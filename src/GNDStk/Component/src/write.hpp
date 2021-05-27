
// -----------------------------------------------------------------------------
// Component::write()
// -----------------------------------------------------------------------------

std::ostream &write(std::ostream &os, const int level = 0) const
{
   try {
      // Indent, write header, newline
      detail::indentString(
         os, level,
         detail::colorize_component(
            detail::fullName(DERIVED::namespaceName(), DERIVED::className())
         ) + " " +
         detail::colorize_brace("{") +
        (comments
            ? " " +
              detail::colorize_comment(
                 std::string("// GNDS: ") + DERIVED::GNDSName()
              )
            : ""
         ) + "\n"
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
         // particular Component<...> type will print with consistent spacing.
         // We prefer this behavior, and it's also slightly simpler to write.
         std::size_t maxlen = 0;
         if (GNDStk::align)
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
                     ) && (os << '\n') // no if()s in fold expressions :-/
                  ),
                  ...
               );
            },
            tup
         );
      }

      // Derived class write()s, if any.
      // Note that neither, either, or both can be provided.
      // To be recognized here, signatures must be exactly what we expect.
      if constexpr (detail::hasWriteOneArg<DERIVED>::has) {
         // DERIVED::write() doesn't take an indentation level; we handle here
         std::ostringstream tmp;
         static_cast<const DERIVED *>(this)->write(tmp);
         if (tmp.str().size() != 0)
            os << indentTo(level+1);
         for (char c : tmp.str())
            os << c << (c == '\n' ? indentTo(level+1) : "");
         if (tmp.str().size())
            os << std::endl;
      }
      if constexpr (detail::hasWriteTwoArg<DERIVED>::has) {
         // DERIVED::write() takes an indentation level
         std::ostringstream tmp;
         static_cast<const DERIVED *>(this)->write(tmp,level+1);
         os << tmp.str();
         if (tmp.str().size())
            os << std::endl;
      }

      // BodyText, if any
      this->BodyText<hasBodyText>::write(os,level+1);

      // Indent, write footer, NO newline
      detail::indentString(
         os, level,
         detail::colorize_brace("}")
          + (comments
              ? " " +
                detail::colorize_comment(
                   std::string("// ") +
                   detail::fullName(
                      DERIVED::namespaceName(),
                      DERIVED::className()
                   )
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
