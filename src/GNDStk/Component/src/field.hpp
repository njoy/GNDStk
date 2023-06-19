
// -----------------------------------------------------------------------------
// Field
// Note that this class is defined inside of class Component. We do this because
// it uses type Component itself (the particular Component<...> that it's in) as
// well as type DERIVED (the class that derives from this Component via CRTP).
// -----------------------------------------------------------------------------

template<class T>
class Field {

   // friends
   friend DERIVED;

   template<class, class>
   friend class FieldPart;

   // data
   DERIVED &parent;
   T wrappedValue;

public:

   // ------------------------
   // Constructors
   // ------------------------

   // Summary
   // Field(parent)
   // Field(parent, T value)
   // Field(parent, Field other)
   // Field(parent, default value, optional value) // If T == Defaulted

   // No copy or move construction; parent would be wrong
   Field(const Field &) = delete;
   Field(Field &&) = delete;

   // The following accept DERIVED*, not DERIVED&, so that we can write "this",
   // not "*this", where Field objects are constructed. It's just a bit shorter.

   // parent
   // This could be rolled into the (parent, value) constructor below, but,
   // if we split it out, the compiler seems to be better able to optimize
   // the construction of parent objects.
   explicit Field(DERIVED *const parent) :
      parent(*parent),
      wrappedValue(T{}) // default
   { }

   // parent, value
   Field(DERIVED *const parent, const T &value) :
      parent(*parent),
      wrappedValue(value) // from value
   { }

   // parent, other Field
   Field(DERIVED *const parent, const Field &other) :
      parent(*parent),
      wrappedValue(other.wrappedValue) // from other
   { }

   // If T == Defaulted
   // parent, default value, current value (std::optional)
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   Field(
      DERIVED *const parent,
      const typename TEE::value_type &def,
      const std::optional<typename TEE::value_type> &value = {}
   ) :
      parent(*parent),
      wrappedValue(def,value)
   { }

   // ------------------------
   // Assignment: copy, move
   // Some other assignments
   // are defined elsewhere
   // ------------------------

   // copy
   Field &operator=(const Field &other)
   {
      wrappedValue = other.wrappedValue;
      return *this;
   }

   // move
   Field &operator=(Field &&other)
   {
      wrappedValue = std::move(other.wrappedValue);
      return *this;
   }

   // ------------------------
   // has
   // ------------------------

   // With no arguments.
   // Relates to std::optional, not to the question of what metadata or metadata
   // values the present Field might contain. (See the other has() functions for
   // that.) Returns true iff either T is optional but has a value, or isn't
   // optional (so that it necessarily has a value).
   bool has() const
   {
      if constexpr (detail::isOptional<T>)
         return wrappedValue.has_value();
      return true;
   }

   // With one argument.
   // Forwards to operator[](const KEY &key) const, below, essentially to
   // provide an alternative form of a "has" query. Instead of, for example,
   //    H.isotope[has(mass_number(2))]
   // to inquire about whether element H's vector of isotopes has an isotope
   // with a mass number of 2, we can instead write:
   //    H.isotope.has(mass_number(2))
   // to make exactly the same query. (The example assumes that H is of a
   // class - say, Element - that contains a vector of isotopes, and that
   // the Isotope class contains an integer metadatum called mass_number.)
   // Note: the SFINAE is such that this function is enabled iff a call to
   // operator[](Lookup) of the present class would be valid, and return bool.
   template<class KEY>
   auto has(const KEY &look) const -> std::enable_if_t<
      std::is_same_v<decltype((*this)[GNDStk::has(look)]),bool>, bool
   > {
      return (*this)[GNDStk::has(look)];
   }

   // ------------------------
   // value()
   // Drill into any optional
   // ------------------------

   // Note: the parentheses in "return (wrappedValue)" are necessary
   // here, so that the decltype(auto) return types produce references!

   // const
   decltype(auto) value() const
   {
      if constexpr (detail::isOptional<T>)
         return wrappedValue.value();
      else
         return (wrappedValue);
   }

   // non-const
   decltype(auto) value()
   {
      if constexpr (detail::isOptional<T>)
         return wrappedValue.value();
      else
         return (wrappedValue);
   }

   // ------------------------
   // operator()
   // ------------------------

   // ()
   // Get exactly the Field-wrapped value, whatever it is (including optional)
   const T &operator()() const { return wrappedValue; } // const
   T &operator()() { return wrappedValue; } // non-const

   // ------------------------
   // operator[](Lookup)
   // ------------------------

   // If T == [optional] vector

   // [Lookup], including Lookup<exists>
// zzz actually the following REQUIRE (don't just include) Lookup<exists>
   template<
      class EXTRACTOR, class TYPE, class CONVERTER,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   bool
   operator[](const Lookup<LookupMode::exists,EXTRACTOR> &look) const // const
   {
      return parent.getter(wrappedValue,look);
   }

   template<
      class EXTRACTOR, class TYPE, class CONVERTER,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   bool
   operator[](const Lookup<LookupMode::exists,EXTRACTOR> &look) // non-const
   {
      return parent.getter(wrappedValue,look);
   }

   // zzz working here

   // [Lookup], including Lookup<exists>
   template<
      LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>,
      class = std::enable_if_t<
         detail::has_field<typename TEE::value_type,EXTRACTOR>::value
      >
   >
   decltype(auto)
   operator[](const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &look) const // const
   {
      return parent.getter(wrappedValue,look);
   }

   template<
      LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>,
      class = std::enable_if_t<
         detail::has_field<typename TEE::value_type,EXTRACTOR>::value
      >
   >
   decltype(auto)
   operator[](const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &look) // non-const
   {
      return parent.getter(wrappedValue,look);
   }

   // ------------------------
   // operator[](size_t)
   // ------------------------

   // If T == [optional] vector

   template<class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   decltype(auto) operator[](const size_t index) const // const
   {
      if constexpr (detail::isOptional<T>)
         return (*wrappedValue)[index];
      else
         return wrappedValue[index];
   }

   template<class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   decltype(auto) operator[](const size_t index) // non-const
   {
      if constexpr (detail::isOptional<T>)
         return (*wrappedValue)[index];
      else
         return wrappedValue[index];
   }

   // ------------------------
   // size()
   // ------------------------

   // If T == [optional] vector
   template<class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   size_t size() const
   {
      if constexpr (detail::isOptional<T>)
         return wrappedValue.has_value() ? wrappedValue->size() : 0;
      else
         return wrappedValue.size();
   }

   // ------------------------
   // Conversions
   // ------------------------

   // To T
   // Same as ()
   operator const T &() const { return wrappedValue; }
   operator T &() { return wrappedValue; }

   // If T == optional<vector>
   // To vector
   // Note that the return type, TEE::value_type, is the type of the vector
   // optionally contained in the optional - NOT the vector's element type.

   // Discussion. We're providing the following functions essentially because
   // they may "smooth out" the interface for users. Imagine that we're dealing
   // with an optional<vector>. If the optional contains a value, which in these
   // circumstances means a vector, then these "conversion to vector" functions
   // just, well, return the contained vector. End of story. However, what if
   // the optional doesn't contain a value? Well, one could reasonably consider
   // that "no vector" is equivalent, for many purposes at least, to "have a
   // vector but with size 0." Following this line of reasoning, we've designed
   // this "conversion to vector" to do the following. If the optional has a
   // value, return the value. If not, then place a 0-length vector into the
   // optional, then return the value. In short, "return the contained vector,
   // having first created an empty vector if need be." There is, however, a
   // caveat. As is expected of conversion operators that return references,
   // we have a version for const *this, and a version for non-const *this.
   // In the former case - the const case - we can return the contained vector
   // only if it already exists. We *can't* do the "first create an empty vector
   // first, if necessary" business, because, well, the object is const. You'll
   // see below, then, that if the object is const and the optional contains
   // no value, we throw an error. In all other cases, either there's already
   // a vector to return, or (in the non-const case) one can be created first.

   template<class TEE = T, class = detail::isOptionalVector_t<TEE>>
   operator const typename TEE::value_type &() const // const
   {
      if (wrappedValue.has_value())
         return *wrappedValue;

      log::error(
         "Cannot give a *const* valueless optional<vector> a vector value");
      log::member("Field:: conversion to vector");
      throw std::exception{};
   }

   template<class TEE = T, class = detail::isOptionalVector_t<TEE>>
   operator typename TEE::value_type &() // non-const
   {
      return wrappedValue
         ? *(wrappedValue)
         : *(wrappedValue = typename TEE::value_type{});
   }

   // ------------------------
   // operator=
   // ------------------------

   // operator=(T)
   Field &operator=(const T &value)
   {
      return wrappedValue = value, *this;
   }

   // If T == Defaulted
   // operator=(optional)
   // As above, except returns *this, as expected for assignment.
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   Field &operator=(const std::optional<typename TEE::value_type> &opt)
   {
      return wrappedValue = opt, *this;
   }

   // ------------------------
   // Setters: add to vector
   // ------------------------

   // If T == [optional] vector
   // add(element)
   // Add (via push_back()) to wrappedValue.
   template<class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   Field &add(
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &element
   ) {
      return Component::setter(wrappedValue,element), *this;
   }

   // operator+=(element)
   // Same as add(element)
   template<class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   Field &operator+=(
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &element
   ) {
      return add(element);
   }
}; // class Field
