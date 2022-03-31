
// -----------------------------------------------------------------------------
// REMARK
// Regarding "write" vs. "print", and newlines
// -----------------------------------------------------------------------------

/*
Python has print(), and we anticipate having many Python-aware users. First and
foremost, this is why we provide these print() functions.

Elsewhere, we've given Component a set of write() (not print()) functions that
mirror Node's functions of the same name. These first make use of Component's
ability to convert objects of its derived classes to Node, then they call Node's
write() functions. Node's write() functions can do a number of things, such as
writing to XML, or to GNDStk's debug format.

Someone who wishes to print the contents of a Component-derived class may prefer
to see our print() function's "prettyprinting" output. Not XML, not our internal
debug format, not the various other things that the write() functions can do.

The name print(), then, not only aligns with what a Python user might expect,
but also reflects the difference from its - really, Node's - write() functions.
Note, in particular, that write() (called with no argument) behaves as it does
for Node, while print() (called with no argument) does something completely
different: prettyprint to standard output.

Our no-argument print() functions also print a newline at the end - which, when
prettyprinting, a user probably expects.

The write() functions, being arguably more "low level", don't emit that newline,
and shouldn't. Just as C++ doesn't automatically print something basic (an int,
for example, or a floating-point number) with a newline, neither should a well-
mannered system for writing class objects. Whether a newline is really wanted,
or not, depends on context.

If you write std::cout << 1.23 << std::endl, you expect one line, with "1.23",
followed by a newline via std::endl, then the cursor ready at the beginning of
the very next line. Write std::cout << obj << std::endl, where obj is of some
user-defined type whose stream output operator already prints its own newline,
and the cursor will end up *two* lines down, after an intervening blank line.
It may seem convenient for "large" objects to print with their own newline, but
doing so creates inconsistent behavior between them and more-basic object types.
Inconsistencies beget unpredictability.

Moreover, Component-derived classes often contain instances of other Component-
derived classes. An enclosing object should place its own newlines - only where
appropriate, and not where not appropriate - between its constituent parts. If
those parts did their own thing in this respect, they'd stymie the ability of
the enclosing class to do the right thing.
*/


// -----------------------------------------------------------------------------
// print(ostream,level)
// Low-level version, possibly building on other Component-derived objects.
// Doesn't print the trailing newline.
// -----------------------------------------------------------------------------

std::ostream &print(std::ostream &os, const int level) const
{
   try {
      // Indent, header, newline
      detail::indentString(
         os, level,
         detail::colorize_component(
            detail::fullName(DERIVED::NAMESPACE(), DERIVED::CLASS())
         ) + " " +
         detail::colorize_brace("{") + "\n"
      );

      if constexpr (!hasFields) {
         // Consistency check
         assert(0 == links.size());
      } else {
         // Make tuple (of individual keys) from DERIVED::KEYS()
         static const auto tup = makeKeyTuple(DERIVED::KEYS()).tup;

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
         // We prefer this behavior, and its code is also slightly simpler.
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
                     // indent, value, newline
                     detail::printComponentPart(
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

      // Custom derived-class print()s, if any.
      // To be recognized here, derived-class print() functions must be public,
      // and have signatures that are *exactly* as we expect, including their
      // constness.
      if constexpr (detail::hasPrintTwoArg<DERIVED>) {
         // Derived class has:
         //    std::ostream &print(std::ostream &os, const int level) const;
         // and handles indentation level in its own way; we won't here.
         std::ostringstream tmp;
         derived().print(tmp,level+1);
         const std::string &str = tmp.str();

         std::size_t size = str.size();
         if (size) {
            // expect that customizations may have spurious newlines :-/
            if (str[size-1] == '\n') size--;
            for (std::size_t i = 0; i < size; ++i)
               os << str[i];
            std::cout << std::endl;
         }
      } else if constexpr (detail::hasPrintOneArg<DERIVED>) {
         // Derived class has:
         //    std::ostream &print(std::ostream &os) const;
         // and we'll detect newlines and handle indentation automatically.
         std::ostringstream tmp;
         derived().print(tmp);
         const std::string &str = tmp.str();

         std::size_t size = str.size();
         if (size) {
            // remark as above
            if (str[size-1] == '\n') size--;
            if (size)
               os << indentTo(level+1);
            for (std::size_t i = 0; i < size; ++i)
               os << str[i] << (str[i] == '\n' ? indentTo(level+1) : "");
            std::cout << std::endl;
         }
      }

      // BlockData, if any
      if constexpr (hasBlockData)
         BLOCKDATA::print(os,level+1);

      // Indent, footer, NO trailing newline
      detail::indentString(
         os, level,
         detail::colorize_brace("}")
          + (comments
              ? " " +
                detail::colorize_comment(
                   std::string("// ") +
                   detail::fullName(
                      DERIVED::NAMESPACE(),
                      DERIVED::CLASS()
                   )
                )
              : ""
            )
      );

      return os;

   } catch (...) {
      log::member("Component.print()");
      throw;
   }
}


// -----------------------------------------------------------------------------
// print
// print(ostream)
// Print trailing newlines.
// -----------------------------------------------------------------------------

// We'll give these const and non-const versions (one would normally expect only
// const versions of print functions), and with a "builder pattern" that mirrors
// that of the setters that GNDStk's code generator gives its generated classes.
// This way, someone can prettyprint an object while it's being built, builder
// style. Some users may find this to be useful for visualizing what's happening
// as they create an object.

// const
const DERIVED &print(std::ostream &os = std::cout) const
{
   print(os,0) << std::endl;
   return *static_cast<const DERIVED *>(this);
}

// non-const
DERIVED &print(std::ostream &os = std::cout)
{
   print(os,0) << std::endl;
   return *static_cast<DERIVED *>(this);
}
