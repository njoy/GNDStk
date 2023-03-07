
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
to see our print() function's "prettyprinting" output. Not XML, certainly not
our internal debug format, and not other formats our Node's write()s support.

The name print(), then, not only aligns with what Python users might expect, but
also reflects a difference from Node's write() functions. In particular, write()
behaves as it does for Node, while print() does something completely different:
it prettyprints to standard output.

Our print() functions also print a newline at the end - which a user probably
expects to see when prettyprinting.

The write() functions, being arguably more "low level", don't emit that newline,
and shouldn't. Just as C++ doesn't automatically print something basic (an int,
for example, or a floating-point number) with a newline, neither should a well-
mannered system for writing class objects. Whether a newline is really wanted,
or not wanted, depends on context.

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

// Helper
template<class KEY>
const std::string getName(const KEY &key, const std::size_t n) const
{
   return detail::getName(key) == special::comment
      ? special::comment
      : printMode == PrintMode::cpp
      ? derived(). FIELDNAMES()[n]
      : derived().PYTHONNAMES()[n];
}


// -----------------------------------------------------------------------------
// print(ostream,level)
// Low-level version, possibly building on other Component-derived objects.
// Doesn't print a trailing newline.
// -----------------------------------------------------------------------------

std::ostream &print(
   std::ostream &os, const int level,
   const std::string &label = "",
   const std::string &labelColor = color::component
) const {
   // Name of the class is as follows, in case we want to use it for anything...
   // const std::string type = detail::fullName(Namespace(), Class());

   try {
      // Consistency check
      // todo Eventually remove this, or make it a proper error,
      // as it really shouldn't happen at all.
      assert(std::tuple_size_v<decltype(Keys().tup)> == links.size());

      // ------------------------
      // Indent, header, newline
      // ------------------------

      detail::indentString(
         os,
         level,
         detail::colorize(label == "" ? "{" : label+" {", labelColor)
      );
      os << std::endl;

      // ------------------------
      // For alignment
      // ------------------------

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

      if (GNDStk::align) {
         std::apply(
            [this,&maxlen](const auto &... key)
            {
               using namespace detail;
               std::size_t n = 0;
               ((
                  n++,
                  maxlen = std::max(
                     maxlen,
                     pprintAlign{}(key,links[n-1])
                        ? this->getName(key,n-1).size()
                        : 0
                  )
               ), ... );
            },
            Keys().tup
         );
      }

      // ------------------------
      // Apply links
      // ------------------------

      // derived-class fields ==> print
      std::apply(
         [this,&os,&level,maxlen](const auto &... key)
         {
            using namespace detail;
            std::size_t n = 0;
            (((
               n++, // not in any [n-1] below, lest undefined evaluation order
               // indent, value, newline
               printComponentPart(
                  // os
                  os,
                  // level
                  level+1,
                  // maxlen
                  pprintAlign{}(key,links[n-1])
                     ? maxlen
                     : 0,
                  // label
                  this->getName(key,n-1),
                  // value
                  *(
                     typename queryResult<std::decay_t<decltype(key)>>::type
                  *)links[n-1]
               )
               ) && (os << std::endl) // no if()s in fold expressions :-/
            ), ... );
         },
         Keys().tup
      );

      // ------------------------
      // Customizations, if any
      // ------------------------

      // Custom derived-class print()s.
      // To be recognized here, derived-class print() functions must be public,
      // and have signatures that are *exactly* as we expect, including their
      // constness.
      if constexpr (detail::hasPrintTwoArg<DERIVED>) {
         // Derived class has:
         //    std::ostream &print(std::ostream &os, const int level) const;
         // and handles the indentation level in its own way; we won't here.
         std::ostringstream tmp;
         derived().print(tmp,level+1);
         const std::string &str = tmp.str();

         std::size_t size = str.size();
         if (size) {
            // expect that customizations may have spurious newlines :-/
            if (str[size-1] == '\n') size--;
            for (std::size_t i = 0; i < size; ++i)
               os << str[i];
            os << std::endl;
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
            os << std::endl;
         }
      }

      // ------------------------
      // BlockData, if any
      // ------------------------

      if constexpr (hasBlockData)
         BLOCKDATA::print(os,level+1);

      // ------------------------
      // Indent, footer,
      // NO trailing newline
      // ------------------------

      using namespace detail;
      indentString(
         os, level,
         comments && label != ""
            ? colorize("} " + colorize_comment(label), labelColor)
            : colorize("}", labelColor)
      );

   } catch (...) {
      log::member("Component.print() for {}", label);
      throw;
   }

   return os;
}


// -----------------------------------------------------------------------------
// print()
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


// -----------------------------------------------------------------------------
// Component::xml()
// Component::json()
// Component::hdf5()
// Component::debug()
// Print trailing newlines.
//
// Shortcuts: like write(), but (1) in the given format, (2) to std::cout
// by default, and (3) with a trailing newline, print()-style. In view of
// points (2) and (3), these resemble print() more than write(), so I put
// them here, not in the file that defines the write() functions.
// -----------------------------------------------------------------------------

// ------------------------
// ostream, decl
// ------------------------

// xml
std::ostream &xml(std::ostream &os = std::cout, const bool decl = false) const
{
   return write(os,"xml",decl) << std::endl, os;
}

// json
std::ostream &json(std::ostream &os = std::cout, const bool decl = false) const
{
   return write(os,"json",decl) << std::endl, os;
}

// hdf5
std::ostream &hdf5(std::ostream &os = std::cout, const bool decl = false) const
{
   return write(os,"hdf5",decl) << std::endl, os;
}

// debug
std::ostream &debug(std::ostream &os = std::cout, const bool decl = false) const
{
   return write(os,"debug",decl) << std::endl, os;
}

// ------------------------
// decl, ostream
// ------------------------

// xml
std::ostream &xml(const bool decl, std::ostream &os = std::cout) const
{
   return xml(os,decl);
}

// json
std::ostream &json(const bool decl, std::ostream &os = std::cout) const
{
   return json(os,decl);
}

// hdf5
std::ostream &hdf5(const bool decl, std::ostream &os = std::cout) const
{
   return hdf5(os,decl);
}

// debug
std::ostream &debug(const bool decl, std::ostream &os = std::cout) const
{
   return debug(os,decl);
}
