
// -----------------------------------------------------------------------------
// Component::write()
// -----------------------------------------------------------------------------

std::ostream &write(std::ostream &os, const int level = 0) const
{
   try {
      // Indent, write header, newline
      detail::indentString(
         os, level,
         detail::colorize_component(DERIVED::className()) + " "
          + detail::colorize_brace("{")
          + (comments
              ? " " +
                detail::colorize_comment(
                   std::string("// GNDS: ") + DERIVED::GNDSField()
                )
              : ""
            )
          + "\n"
      );

      if constexpr (
         std::is_same<decltype(DERIVED::keys()),std::tuple<>>::value
      ) {
         // Consistency check
         assert(0 == links.size());
      } else {
         // Make tuple (of individual keys) from DERIVED::keys()
         const auto tup = toKeywordTup(DERIVED::keys()).tup;

         // Consistency check
         assert(std::tuple_size<decltype(tup)>::value == links.size());

         // Compute maximum length of key names, if aligning. Note that we
         // could - but don't - take into account that keys associated with
         // optional or Defaulted values *might* not in fact show up in the
         // final printed text. In such cases, and if values of those types
         // happen to have longer names, then the printing that does appear
         // might use more spacing than it really needs to. By choosing not
         // to factor this in, on a case-by-case basis, all objects of this
         // particular Component<DERIVED> type print with consistent spacing.
         // We prefer this behavior, and it's also slightly simpler to write.
         std::size_t maxlen = 0;
         if (njoy::GNDStk::align)
            std::apply(
               [&maxlen](const auto &... key) {
                  ((maxlen=std::max(maxlen,detail::getName(key).size())), ...);
               },
               tup
            );

         // Apply links:
         // derived-class data ==> print
         std::apply(
            [this,&os,&level,maxlen](const auto &... key) {
               std::size_t n = 0;
               (
                  (
                     // indent, write internal value, newline
                     detail::writeComponentPart(
                        os,
                        level+1,
                      *(typename
                        detail::remove_cvref<decltype(Node{}(key))>::type *)
                        links[n++],
                        detail::getName(key),
                        maxlen
                     ) && (os << '\n') // no "if" in fold expression :-/
                  ),
                  ...
               );
            },
            tup
         );
      }

      // Indent, write footer, NO newline
      detail::indentString(
         os, level,
         detail::colorize_brace("}")
          + (comments
              ? " " +
                detail::colorize_comment(
                   std::string("// ") + DERIVED::className()
                )
              : ""
            )
      );

      return os;

   } catch (...) {
      log::member("Component.write()");
      throw;
   }
}
