
// -----------------------------------------------------------------------------
// Component::write(), for "prettyprinting"
// -----------------------------------------------------------------------------

std::ostream &write(std::ostream &os, const int level) const
{
   try {
      // Indent, write header, newline
      detail::indentString(
         os, level,
         detail::colorize_component(
            detail::fullName(DERIVED::namespaceName(), DERIVED::className())
         ) + " " +
         detail::colorize_brace("{") +
         /*
         // fixme We may not actually want this. It's arguably largely clutter,
         // and besides, someone may have used GNDStk's code generator to make
         // a different library - for which "GNDS" verbiage may be confusing.
         (comments
            ? " " +
              detail::colorize_comment(
                 std::string("// GNDS: ") + DERIVED::GNDSName()
              )
            : ""
         ) +
         */
         "\n"
      );

      if constexpr (!hasFields) {
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
                      *(std::decay_t<decltype(Node{}(key))> *)links[n++],
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
      if constexpr (detail::hasWriteOneArg<DERIVED>) {
         // DERIVED::write() doesn't take an indentation level; we handle here
         std::ostringstream tmp;
         derived().write(tmp,0);
         if (tmp.str().size() != 0)
            os << indentTo(level+1);
         for (char c : tmp.str())
            os << c << (c == '\n' ? indentTo(level+1) : "");
         if (tmp.str().size())
            os << std::endl;
      }
      if constexpr (detail::hasWriteTwoArg<DERIVED>) {
         // DERIVED::write() takes an indentation level
         std::ostringstream tmp;
         derived().write(tmp,level+1);
         os << tmp.str();
         if (tmp.str().size())
            os << std::endl;
      }

      // BlockData, if any
      if constexpr (hasBlockData)
         body::write(os,level+1);

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



// -----------------------------------------------------------------------------
// Component::write()
// Via Node, and using Node's available write() functions.
// So, autogenerated classes can directly use .write(...).
// -----------------------------------------------------------------------------

// write(ostream, FileType)
std::ostream &write(
   std::ostream &os = std::cout,
   const FileType format = FileType::null,
   const bool decl = false
) const {
   return Node(*this).write(os, format, decl);
}

// write(file name, FileType)
bool write(
   const std::string &filename,
   FileType format = FileType::null,
   const bool decl = false
) const {
   return Node(*this).write(filename, format, decl);
}

// write(ostream, string)
std::ostream &write(
   std::ostream &os,
   const std::string &format,
   const bool decl = false
) const {
   return Node(*this).write(os, format, decl);
}

// write(file name, string)
bool write(
   const std::string &filename,
   const std::string &format,
   const bool decl = false
) const {
   return Node(*this).write(filename, format, decl);
}



// -----------------------------------------------------------------------------
// print
// Simple version of the prettyprinting write(), for user ease and familiarity.
// -----------------------------------------------------------------------------

/*
REMARK
A long remark about a short function. :-)

Python has print(), and we anticipate having many Python-aware users. This,
first and foremost, is the reason for this function's existence.

Also, importantly, we've provided a series of write() functions, above, that
mirror Node's various write()s. The Component class is designed to imbue its
derived classes with a wealth of functionality, and, in this vein, we're taking
advantage of Component's ability to convert objects of those derived classes
to Node (an ability that Component also gives us!) and to thereby make Node's
write()s available to them.

Node's write()s can do a number of things, including, for example, writing to
XML, and also writing to an internal debug format we have in GNDStk. Given the
above write()s - which, again, are intentionally designed (and this includes
their default arguments) to mirror Node's - a call to .write() in fact ends up
going to GNDStk's Debug format.

A user, however, printing a Component-derived class, would probably much prefer
our prettyprinting capability! Not our internal debug format. So, instead of
changing up these write() functions - making them, in effect, be inconsistent
with Node's write() functions - we'll instead give users a "simple prettyprint
to C++ standard output" call by doing exactly what we're doing here: providing
a print(), like Python does, and with a name that's different from "write" so
that no conflict exists.

Note that our print() does something small but important: it prints a newline
at the end, which in this context a user will expect.

Wait a minute, doesn't the main prettyprint write() already do a newline? No,
in fact, it doesn't, and as some readers may realize, it shouldn't. Just as C++
doesn't automatically end something it prints (an integer, say, or a floating-
point number) with a newline, neither should a well-mannered system for printing
class objects. Whether a newline is appropriate, or not, depends on context.

If you write std::cout << 1.23 << std::endl, you expect one line, with "1.23",
followed by a newline via std::endl, then the cursor ready at the beginning of
the very next line. Write std::cout << obj << std::endl, where obj is of some
user-defined type with a stream output operator that prints its own newline (but
shouldn't!), and now the cursor, after printing, will be *two* lines down, after
an intervening blank line. Which raises a question: why the different behavior?

It may seem convenient for "large" things to print with a newline automatically,
but doing so creates inconsistent behavior between different types of printed
objects, and inconsistencies beget unpredictability.

Moreover, Component-derived classes often contain instances of other Component-
derived classes. In the above write(), an enclosing object will place its own
newlines - only where appropriate, and NOT where not appropriate - between its
constituent parts. If those parts did their own thing in this respect, they'd
stymie the ability of the enclosing class to do the right thing.

Just for fun, we'll give print() both const and non-const versions (one would
normally expect only a const version), and with a "builder pattern" that mirrors
that of the setters that GNDStk's code generator gives its generated classes.
This way, someone could actually prettyprint an object *while* it's being built,
builder style. Perhaps some users would find this to be useful for visualizing
what's happening as they create their objects.
*/

const DERIVED &print(const int level = 0) const
{
   write(std::cout,level) << std::endl;
   return *static_cast<const DERIVED *>(this);
}

DERIVED &print(const int level = 0)
{
   write(std::cout,level) << std::endl;
   return *static_cast<DERIVED *>(this);
}
