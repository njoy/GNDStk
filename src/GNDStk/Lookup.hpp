
// -----------------------------------------------------------------------------
// Discussion
// Understanding the Lookup class, and its associated constructs.
// -----------------------------------------------------------------------------

/*
------------------------
Meta class (background)
------------------------

Consider, for a moment, the GNDStk Core Interface's Meta<TYPE,CONVERTER> class
template. It has a general definition, and a specialization:

   * Meta<TYPE,CONVERTER>
   * Meta<void,void>

Both are designed to help users extract metadata from Core Interface nodes. For
example, say that we have a node that represents a chemical element, as in the
following XML construct:

   <element symbol="He" atomic_number="2">
      ...
   </element>

In XML, the values of metadata (a.k.a attributes) are quoted, essentially making
all of them strings. The Core Interface's Node class stores them as strings too.
Keeping metadata in their original string form helps the Node class to preserve
information - think "non-lossy storage" - so that we aren't making premature
assumptions about data types - assumptions that might result in loss of accuracy
or other information.

When extracting metadata for practical use, type matters. In the above example,
if we extract the symbol and the atomic_number, we'll probably want to keep
the former as a string, but convert the latter to an int. To do this, we could
create Meta<> objects like this:

   Meta<void> symbol("symbol"); // is Meta<void,void>
   Meta<int> atomic_number("atomic_number"); // is Meta<int,someDefault>

The first, which is really Meta<TYPE=void,CONVERTER=void>, means that we keep
the symbol in its original form. We already know it's a std::string, and that's
exactly how we want to extract it. CONVERTER is meaningless in this case; we're
not intending to convert from the original form to anything else. (Aside, though
not important for the present discussion: We *could* stipulate TYPE=std::string
explicitly, and then give a CONVERTER as well, if we want to keep the value as
a std::string but still perform some sort of transformation. Example: converting
the original std::string name "He" to the upper-case std::string name "HE".)

The second, which is really Meta<TYPE=int,CONVERTER=someDefault>, means that
we wish to convert the std::string to an int. We could give our own function
to do the conversion, but GNDStk is designed so that an appropriate converter,
if not provided, will be selected automatically for certain basic conversions,
that GNDStk knows about, such as from std::string to int.

In both of the above Meta objects, the quoted values given in the constructor
calls are the names of the metadata we're looking for. (We'll typically give
the Meta<> objects the same names, which generally makes sense; but we don't
need to do so.)

Given a Node n, containing an element as represented in the XML example above,
and armed with the Meta objects just outlined, we could now write:

   std::string sym = n(symbol); // "He"
   int atnum = n(atomic_number); // 2

to extract the Node's metadata in a nice, usable form.

------------------------
Component Interface
------------------------

Let's outline a few aspects of GNDStk's Component Interface. Understanding these
will help motivate the Lookup class described below, and its relationship to the
Meta class described above.

GNDStk's Component class serves as a base class for what we'll appropriately, if
not necessarily cleverly, call "Component-derived classes."

zzz working here

------------------------
Lookup class
------------------------

Think of class Lookup, defined below, as being the Component Interface's analog
to the Core Interface's Meta. And, much as the smarter, higher-level Component
Interface sits on the shoulders of the Core Interface, the smarter, higher-level
Lookup class sits on top of the Meta class. (It derives from Meta, in fact, and
then adds more functionality.)

zzz Outline: code generator, Component base, Field, free has(), Field has().

Lookup, like Meta, has a general definition followed by a specialization:

   * Lookup<MODE,EXTRACTOR,TYPE,CONVERTER>
     Derives from Meta<TYPE,CONVERTER>

   * Lookup<MODE,EXTRACTOR,void,void>
     Derived from Meta<void,void>

zzz working here, documenting
   Relevant: Field has has() too.
   Discuss autogenerator, Component base, and class Field.
   They're all involved here.
*/


// -----------------------------------------------------------------------------
// Lookup<MODE,EXTRACTOR,TYPE,CONVERTER>
// Based on Meta<TYPE,CONVERTER>
// -----------------------------------------------------------------------------

// LookupMode
enum class LookupMode {
   get,
   exists
};

template<
   LookupMode MODE,
   class EXTRACTOR,
   // as with Meta<>...
   class TYPE = void,
   class CONVERTER = detail::default_converter_t<TYPE>
>
struct Lookup : public Meta<TYPE,CONVERTER>
{
   // data
   EXTRACTOR extractor;
   TYPE value;

   // constructor
   Lookup(
      const std::string &name,
      const EXTRACTOR &extractor,
      const TYPE &value,
      const CONVERTER &converter = CONVERTER{}
   ) :
      Meta<TYPE,CONVERTER>(name,converter),
      extractor(extractor),
      value(value)
   { }
};


// -----------------------------------------------------------------------------
// Lookup<MODE,EXTRACTOR,void,void>
// Based on Meta<void,void>
// -----------------------------------------------------------------------------

/*
We'll define the following with a class CONVERTER, but then require via a static
assertion that CONVERTER be void. This way, if a user tries to create an object
of this type:

   Lookup<*,*,void,non-void>,

which really isn't meaningful, then they'll probably get a comprehensible error
message during compilation.

If we instead wrote this Lookup partial specialization as:

   Lookup<MODE,EXTRACTOR,void,void>

then the compiler would attempt to use the general class Lookup, defined above,
and would emit what might be seen as somewhat confusing errors. One such error
would likely be a static assertion failure in class Meta, which someone may or
may not realize is a base class of Lookup. Another error would probably relate
to type void being unusable, or incomplete, while attempting to instantiate
class Lookup, as defined above, for TYPE == void.

It's actually unlikely that somebody would try to create a

   Lookup<*,*,void,non-void>,

or for that matter any other Lookup variation, directly. Doing so is generally
awkward. EXTRACTOR will, for example, typically be the type of some lambda. By
using auto and makeLookup(), however, EXTRACTOR, and other template types, are
determined automatically. (Analogy: think of how the C++'s standard library's
std::make_pair() function will determine pair<>'s template types automatically.
That's convenient, and moreover, the types involved in the present context are
likely to be more complicated than what most people use with std::pair.)

So, yes, we'll typically use a makeLookup() function to create Lookup objects,
and then the problematic <...void,non-void> business won't happen anyway. Even
so, we'd still like useful diagnostics to be emitted in the event that someone
creates a Lookup object directly, not just in the simpler makeLookup() manner.
*/

template<LookupMode MODE, class EXTRACTOR, class CONVERTER>
struct Lookup<MODE,EXTRACTOR,void,CONVERTER> : public Meta<void,void>
{
   static_assert(
      // CONVERTER should be void too; give this requirement a good diagnostic
      detail::is_void_v<CONVERTER>,
     "Can't create Lookup<MODE,EXTRACTOR,void,CONVERTER> unless CONVERTER "
     "is also void (or its default)"
   );

   // data
   EXTRACTOR extractor;

   // constructor
   Lookup(
      const std::string &name,
      const EXTRACTOR &extractor
   ) :
      Meta<void,void>(name),
      extractor(extractor)
   { }

   // ------------------------
   // operator()
   // ------------------------

   // The idea: we can apply operator() to *this generic Lookup:
   //    Lookup<MODE,EXTRACTOR,void,void>
   // to create a typed, specific-valued Lookup:
   //    Lookup<MODE,EXTRACTOR,TYPE,CONVERTER>
   template<class TYPE, class C = detail::default_converter_t<TYPE>>
   auto operator()(const TYPE &value, const C &converter = C{}) const
   {
      return Lookup<MODE,EXTRACTOR,TYPE,C>(name, extractor, value, converter);
   }

   // As above
   // We give the char* case explicitly in order to force std::string
   template<class C = detail::default_converter_t<std::string>>
   auto operator()(const char *const value, const C &converter = C{}) const
   {
      using TYPE = std::string;
      return Lookup<MODE,EXTRACTOR,TYPE,C>(name, extractor, value, converter);
   }
};


// -----------------------------------------------------------------------------
// makeLookup
// -----------------------------------------------------------------------------

// For TYPE != void
template<
   LookupMode MODE = LookupMode::get,
   class EXTRACTOR,
   class TYPE,
   class CONVERTER = detail::default_converter_t<TYPE>
>
auto makeLookup(
   const std::string &name,
   const EXTRACTOR &extractor,
   const TYPE &value,
   const CONVERTER &converter = CONVERTER{}
) {
   return Lookup<MODE,EXTRACTOR,TYPE,CONVERTER>(
      name,
      extractor,
      value,
      converter
   );
}

// For TYPE == void
// This, not the above, is probably the makeLookup() to prefer. Once created
// with this function, a Lookup can have its operator() called, with specific
// values (and a converter if necessary) in order to create, as needed, Lookup
// objects with specific values.
template<
   LookupMode MODE = LookupMode::get,
   class EXTRACTOR
>
auto makeLookup(
   const std::string &name,
   const EXTRACTOR &extractor
) {
   return Lookup<MODE,EXTRACTOR,void,void>(
      name,
      extractor
   );
}


// -----------------------------------------------------------------------------
// has
// 1-argument
// -----------------------------------------------------------------------------

// For TYPE != void
template<
   class EXTRACTOR, class TYPE, class CONVERTER,
   class = std::enable_if_t<!detail::is_void_v<TYPE>>
>
auto has(const Lookup<LookupMode::get,EXTRACTOR,TYPE,CONVERTER> &from)
{
   return Lookup<LookupMode::exists,EXTRACTOR,TYPE,CONVERTER>(
      from.name,
      from.extractor,
      from.value,
      from.converter
   );
}

// For TYPE == void
template<class EXTRACTOR>
auto has(const Lookup<LookupMode::get,EXTRACTOR,void,void> &from)
{
   return Lookup<LookupMode::exists,EXTRACTOR,void,void>(
      from.name,
      from.extractor
   );
}


// -----------------------------------------------------------------------------
// has
// 0-argument
// constexpr
// Useful in some of our constexpr ifs
// -----------------------------------------------------------------------------

template<
   class Class,
   class EXTRACTOR,
   class = decltype(std::declval<EXTRACTOR>()(Class{}))
>
constexpr bool has(const int)
{
   return true;
}

template<
   class Class,
   class EXTRACTOR
>
constexpr bool has(const double)
{
   return false;
}
