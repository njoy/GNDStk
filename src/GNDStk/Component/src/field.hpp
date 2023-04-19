
template<class, class>
class FieldPart {
   // Nothing; see the partial specialization later in this file
};


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

   // If T == Defaulted
   // parent, default value, current value (GNDStk::Optional)
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   Field(
      DERIVED *const parent,
      const typename TEE::value_type &def,
      const GNDStk::Optional<typename TEE::value_type> &value // no = {}
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
   // With no arguments.
   // ------------------------

   // Relates to std::optional/GNDStk::Optional, not to the question of what
   // metadata or metadata values the present Field might contain. (See the
   // other has() functions for that.) Returns true iff either T is optional
   // but has a value, or isn't optional (so that it necessarily has a value).
   bool has() const
   {
      if constexpr (detail::isOptional<T>)
         return wrappedValue.has_value();
      return true;
   }

   // ------------------------
   // has
   // With one argument.
   // ------------------------

   // Forwards to [operator()(const KEY &key) const], below, essentially to
   // provide an alternative form of a "has" query. Instead of, for example,
   //    H.isotope(has(mass_number(2)))
   // to inquire about whether element H's vector of isotopes has an isotope
   // with a mass number of 2, we can instead write:
   //    H.isotope.has(mass_number(2))
   // to make exactly the same query. (The example assumes that H is of a
   // class - say, Element - that contains a vector of isotopes, and that
   // the Isotope class contains an integer metadatum called mass_number.)
   // Note: the SFINAE is such that this function is enabled iff a call to
   // operator()(key) of the present class would be valid, and return bool.
   template<
      class KEY,
      // todo Could perhaps be shorter if we used a trailing return type?
      class = std::enable_if_t<std::is_same_v<
         decltype(std::declval<Field>()(GNDStk::has(std::declval<KEY>()))),
         bool
      >>
   >
   bool has(const KEY &key) const
   {
      return (*this)(GNDStk::has(key));
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
   // With no arguments.
   // ------------------------

   // ()
   // Get exactly the Field-wrapped value, whatever it is (including optional)
   const T &operator()() const { return wrappedValue; } // const
   T &operator()() { return wrappedValue; } // non-const

   // ------------------------
   // operator()
   // With one argument.
   // ------------------------

   /*
   zzz
   Regarding isSearchKey and such, I suspect that we should deal with
   the issue mentioned in comp-detail-get.hh, regarding the interpretation
   of an integral type: as an index, or for a lookup by "index" metadatum.
   My strong thought right now is that it should strictly be the former,
   as the latter would almost certainly have an unexpected meaning. (Yeah,
   I originally wrote the latter, before coming up with the much better
   concept and syntax of my Lookup objects. Speaking of which, I should
   very soon do the todo at the beginning of look.hh. That will help here
   and elsewhere.) In the present file, with Field and probably FieldPart,
   I suspect that (#) just shouldn't fly. Maybe just allow:
      [#] // normal vector index
      [key(value)] // lookup by metadatum
      (key(value)) // lookup by metadatum <== maybe or maybe not
   If we change things around as just suggested, we'll have to look very
   carefully at our use in this file of various SFINAE constructs, such
   as isSearchKey and isLookup. Also do a careful accounting of what
   operator()s we have in this file. Some quick grepping suggest 16 cases.
   Some involve GNDStk::Optional, which I'm increasingly convinced should
   simply be removed. GNDStk is complex already, and can do without it.
   That, at least, would also give us a slight break in dealing with the
   () and [] operators, though getting rid of GNDStk::Optional is really
   its own issue, and probably should be done for its own reasons.
   */

   // If T == [optional] vector
   // (index/label/Lookup), including Lookup<exists> (via the "has" function)
   template<
      class KEY, class = detail::isLookup_t<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   decltype(auto) operator()(const KEY &key) const // const
   {
      return parent.getter(wrappedValue,key);
   }

   template<
      class KEY, class = detail::isLookup_t<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   decltype(auto) operator()(const KEY &key) // non-const
   {
      return parent.getter(wrappedValue,key);
   }

   // If T == [optional] vector
   // [index/label/Lookup]
   template<
      class KEY, class = detail::isLookup_t<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   decltype(auto) operator[](const KEY &key) const // const
   {
      return (*this)(key);
   }

   template<
      class KEY, class = detail::isLookup_t<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   decltype(auto) operator[](const KEY &key) // non-const
   {
      return (*this)(key);
   }

   // ------------------------
   // size()
   // ------------------------

   // If T == [optional] vector
   template<class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   std::size_t size() const
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
   // Setters: general
   // ------------------------

   // replace(T)
   // Replace the existing value with another value.
   // Provides a "builder pattern" for DERIVED.
   DERIVED &replace(const T &value)
   {
      return wrappedValue = value, parent;
   }

   // operator()(T)
   // Same as replace(T)
   // Note that no ambiguity should arise with Field<vector>'s operator() that
   // accepts an index, a label, or a Lookup object, because the parameter here
   // is also a T (and thus is a vector if we're in a Field<vector>).
   DERIVED &operator()(const T &value)
   {
      return replace(value);
   }

   // operator=(T)
   // Returns the left-hand side, as one would expect. For assignment, a builder
   // pattern (returning DERIVED) would just be goofy.
   Field &operator=(const T &value)
   {
      return replace(value), *this;
   }

   // ------------------------
   // Setters: for Defaulted
   // Remarks as above
   // ------------------------

   // If T == Defaulted
   // replace(optional)
   // Replace the Defaulted's existing value with the given optional value.
   // Provides a "builder pattern" for DERIVED.
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   DERIVED &replace(const std::optional<typename TEE::value_type> &opt)
   {
      return wrappedValue = opt, parent;
   }
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   DERIVED &replace(const GNDStk::Optional<typename TEE::value_type> &opt)
   {
      return wrappedValue = opt, parent;
   }

   // operator()(optional)
   // Same as replace(optional)
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   DERIVED &operator()(const std::optional<typename TEE::value_type> &opt)
   {
      return replace(opt);
   }
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   DERIVED &operator()(const GNDStk::Optional<typename TEE::value_type> &opt)
   {
      return replace(opt);
   }

   // operator=(optional)
   // As above, except returns *this, as expected for assignment.
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   Field &operator=(const std::optional<typename TEE::value_type> &opt)
   {
      return replace(opt), *this;
   }
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   Field &operator=(const GNDStk::Optional<typename TEE::value_type> &opt)
   {
      return replace(opt), *this;
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

   // Here, we actually don't want an operator() that forwards to add(), like
   // the operator()s that forwarded to replace() in earlier setters. Imagine
   // that this Field wrapped, say, a vector<int>. If someone used the above
   // add() function and wrote field.add(123), the meaning is clearly that 123
   // is to be added (think push_back()) to the vector<int>. But if we provided
   // an operator() that forwarded to add(), and someone used it to write
   // field(123), they *might* want 123 added to the vector - OR, they might
   // intend to retrieve vector[123]. In the *getter* functions defined
   // earlier, note that we do indeed allow both operator() and operator[] for
   // retrieving vector elements (by index, label, or Lookup object). I suppose
   // we could allow only the operator[] form for getting, and then be able to
   // have an operator() setter here, with the same meaning as add(). However,
   // we believe that the getter's use of the operator() in question provides
   // for the better and more-expected meaning.

   // ------------------------
   // Setters: for vector or
   // optional vector, replace
   // an element
   // ------------------------

   // The following may not see too much use. They mostly have the same effect
   // as indexing into the vector and then doing an assignment. The difference
   // is that these functions endow the operation with a "builder pattern" that
   // returns DERIVED, and in that respect mimic replace(T) and operator()(T)
   // as defined earlier. Indexing+assignment, in contrast, returns a reference
   // to the assignment's left-hand side as one would expect from assignment.

   // For [optional] vector
   // replace(index/label/Lookup, element)
   // Find the vector's element that has the given index, label, or Lookup,
   // and replace it with the given replacement element.
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   DERIVED &replace(
      const KEY &key,
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &element
   ) {
      return (*this)(key) = element, parent;
   }

   // For [optional] vector
   // operator()(index/label/Lookup, element)
   // Same as replace(index/label/Lookup, element)
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   DERIVED &operator()(
      const KEY &key,
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &element
   ) {
      return replace(key,element);
   }
}; // class Field


// -----------------------------------------------------------------------------
// FieldPart
// As with class Field, this is intentionally defined within class Component.
// -----------------------------------------------------------------------------

template<class WHOLE, class PART>
class FieldPart<Field<WHOLE>,PART> {
   Field<WHOLE> &whole;

   static_assert(
      detail::isVariant_v<WHOLE> || detail::isVectorVariant<WHOLE>::value,
     "FieldPart<Field<WHOLE>,PART>: "
     "WHOLE must be variant or vector<variant>"
   );

public:

   // ------------------------
   // Constructors
   // ------------------------

   // Because [Field<WHOLE> &whole] would be wrong
   FieldPart(const FieldPart &) = delete; // no copy
   FieldPart(FieldPart &&) = delete; // no move

   explicit FieldPart(Field<WHOLE> &whole) :
      whole(whole)
   { }

   // ------------------------
   // Getters:
   // If WHOLE == variant
   // ------------------------

   // ptr()
   // Get as PART *
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const PART *ptr() const
   {
      return whole.parent.template getter<PART>(whole());
   }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART *ptr()
   {
      return whole.parent.template getter<PART>(whole());
   }

   // ref()
   // Get as PART &
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const PART &ref() const
   {
      const PART *const p = ptr();
      if (p) return *p;
      log::error(
        "Cannot get reference; variant contains a different alternative");
      log::member("FieldPart::ref()");
      throw std::exception{};
   }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART &ref()
   {
      return const_cast<PART &>(std::as_const(*this).template ref());
   }

   // opt()
   // Makes a std::optional. So, we must return by value,
   // and then only the const version is needed.
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const std::optional<PART> opt() const
   {
      const PART *const p = ptr();
      return p ? std::optional<PART>{*p} : std::optional<PART>{};
   }

   // Opt()
   // As above, except makes a GNDStk::Optional.
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const GNDStk::Optional<PART> Opt() const
   {
      const PART *const p = ptr();
      return p ? GNDStk::Optional<PART>{*p} : GNDStk::Optional<PART>{};
   }

   // operator()
   // Get as PART &
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const PART &operator()() const
   {
      try {
         return ref();
      } catch (...) {
         log::member("FieldPart::operator()");
         throw;
      }
   }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART &operator()()
   {
      return const_cast<PART &>(std::as_const(*this)());
   }

   // ------------------------
   // Conversions
   // If WHOLE == variant
   // ------------------------

   // To PART *
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator const PART *() const { return ptr(); }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator PART *() { return ptr(); }

   // To PART &
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator const PART &() const
   {
      try {
         return ref();
      } catch (...) {
         log::member("FieldPart:: conversion to variant alternative");
         throw;
      }
   }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator PART &()
   {
      return const_cast<PART &>(std::as_const(*this).operator const PART &());
   }

   // To std::optional<PART>
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator std::optional<PART>() const { return opt(); }

   // To GNDStk::Optional<PART>
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator GNDStk::Optional<PART>() const { return Opt(); }

   // ------------------------
   // has
   // Similar to Field's
   // ------------------------

   /*
   // todo I'm not sure that this would have a clear meaning for FieldPart.
   // For Field, it means whether or not a value exists - either it's not
   // optional, or is optional but has a value. Here, that meaning could be
   // confused with the concept of whether or not the variant contains the
   // "PART" represented by this FieldPart. Think about this.

   // has()
   bool has() const
   {
      if constexpr (detail::isOptional<WHOLE>)
         return wrappedValue.has_value();
      else
         return true;
   }
   */

   // has(key)
   template<
      class KEY,
      class = std::enable_if_t<std::is_same_v<
         decltype(std::declval<FieldPart>()(GNDStk::has(std::declval<KEY>()))),
         bool
      >>
   >
   bool has(const KEY &key) const
   {
      return (*this)(GNDStk::has(key));
   }

   // ------------------------
   // Getters:
   // If WHOLE == vector
   // ------------------------

   // ptr(index/label/Lookup)
   // Get as PART *
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   const PART *ptr(const KEY &key) const
   {
      return whole.parent.template getter<PART>(whole(),key);
   }

   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   PART *ptr(const KEY &key)
   {
      return whole.parent.template getter<PART>(whole(),key);
   }

   // ref(index/label/Lookup)
   // Get as PART &
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   const PART &ref(const KEY &key) const
   {
      const PART *const p = ptr(key);
      if (p) return *p;
      log::error(
        "Cannot get reference; variant contains a different alternative");
      log::member("FieldPart::ref(key)");
      throw std::exception{};
   }

   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   PART &ref(const KEY &key)
   {
      return const_cast<PART &>(std::as_const(*this).template ref(key));
   }

   // opt(index/label/Lookup)
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   const std::optional<PART> opt(const KEY &key) const
   {
      const PART *const p = ptr(key);
      return p ? std::optional<PART>{*p} : std::optional<PART>{};
   }

   // Opt(index/label/Lookup)
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   const GNDStk::Optional<PART> Opt(const KEY &key) const
   {
      const PART *const p = ptr(key);
      return p ? GNDStk::Optional<PART>{*p} : GNDStk::Optional<PART>{};
   }

   // (index/label/Lookup), including Lookup<exists> (via the "has" function)
   template<
      class KEY, class = detail::isLookup_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   decltype(auto) operator()(const KEY &key) const
   {
      if constexpr (detail::isLookupBoolReturn_v<KEY>) {
         // a bool
         return whole(key);
      } else {
         // a reference
         try {
            return ref(key);
         } catch (...) {
            log::member("FieldPart::operator()(key)");
            throw;
         }
      }
   }

   template<
      class KEY, class = detail::isLookup_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   decltype(auto) operator()(const KEY &key)
   {
      if constexpr (detail::isLookupBoolReturn_v<KEY>) {
         // a bool
         return whole(key);
      } else {
         // a reference
         return const_cast<PART &>(std::as_const(*this)(key));
      }
   }

   // [index/label/Lookup]
   template<
      class KEY, class = detail::isLookup_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   decltype(auto) operator[](const KEY &key) const
      { return (*this)(key); }

   template<
      class KEY, class = detail::isLookup_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   decltype(auto) operator[](const KEY &key)
      { return (*this)(key); }

   // If T == vector
   // size()
   template<
      class T = WHOLE, class = detail::isVector_t<T>>
   std::size_t size() const
   {
      return whole.size();
   }

   // ------------------------
   // Setters
   // Using std::optional
   // ------------------------

   // If WHOLE == variant
   // replace(value)
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   DERIVED &replace(const std::optional<PART> &opt)
   {
      if (opt) whole.replace(opt.value());
      return whole.parent;
   }

   // operator()(value)
   template<class T = WHOLE, std::enable_if_t<detail::isVariant_v<T>, int> = 0>
   DERIVED &operator()(const std::optional<PART> &opt)
   {
      return replace(opt);
   }

   // operator=(value)
   template<class T = WHOLE, std::enable_if_t<detail::isVariant_v<T>, int> = 0>
   FieldPart &operator=(const std::optional<PART> &opt)
   {
      return replace(opt), *this;
   }

   // If WHOLE == vector
   // add(value)
   template<class T = WHOLE, class = detail::isVector_t<T>>
   FieldPart &add(const std::optional<PART> &opt)
   {
      if (opt) whole.add(opt.value());
      return *this;
   }

   // operator+=(value)
   template<class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &operator+=(const std::optional<PART> &opt)
   {
      return add(opt);
   }

   // If WHOLE == vector
   // replace(index/label/Lookup, element)
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &replace(const KEY &key, const std::optional<PART> &opt)
   {
      if (opt) whole(key,opt.value());
      return whole.parent;
   }

   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &operator()(const KEY &key, const std::optional<PART> &opt)
   {
      return replace(key,opt);
   }

   // ------------------------
   // Setters
   // Using GNDStk::Optional
   // ------------------------

   // If WHOLE == variant
   // replace(value)
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   DERIVED &replace(const GNDStk::Optional<PART> &opt)
   {
      if (opt) whole.replace(opt.value());
      return whole.parent;
   }

   // operator()(value)
   template<class T = WHOLE, std::enable_if_t<detail::isVariant_v<T>, int> = 0>
   DERIVED &operator()(const GNDStk::Optional<PART> &opt)
   {
      return replace(opt);
   }

   // operator=(value)
   template<class T = WHOLE, std::enable_if_t<detail::isVariant_v<T>, int> = 0>
   FieldPart &operator=(const GNDStk::Optional<PART> &opt)
   {
      return replace(opt), *this;
   }

   // If WHOLE == vector
   // add(value)
   template<class T = WHOLE, class = detail::isVector_t<T>>
   FieldPart &add(const GNDStk::Optional<PART> &opt)
   {
      if (opt) whole.add(opt.value());
      return *this;
   }

   // operator+=(value)
   template<class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &operator+=(const GNDStk::Optional<PART> &opt)
   {
      return add(opt);
   }

   // If WHOLE == vector
   // replace(index/label/Lookup, element)
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &replace(const KEY &key, const GNDStk::Optional<PART> &opt)
   {
      if (opt) whole(key,opt.value());
      return whole.parent;
   }

   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &operator()(const KEY &key, const GNDStk::Optional<PART> &opt)
   {
      return replace(key,opt);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // Intentional: don't assign [referenced] whole; doing so would be wrong
   FieldPart &operator=(const FieldPart &) { return *this; }
   FieldPart &operator=(FieldPart &&) { return *this; }
}; // class FieldPart


// -----------------------------------------------------------------------------
// wrapper
// This doesn't really need to be defined within class Component, but it's used
// only in that context, so might as well be.
// -----------------------------------------------------------------------------

// This class is used in the context of parameters in certain constructors
// of Component-derived classes that we create with the GNDStk Code Generator.
// It helps to regularize and simplify the process of providing default values
// to those parameters, and in doing so, it gives the constructors in question
// a more streamlined, less bulky look and feel. We could do without it, but
// we like the improved appearance it facilitates. Note: wrapper is formulated
// in such a way that it shouldn't cause any issues with the py::init<...> and
// py::arg(...) material in our pybind11-based Python binding code. If it ever
// proves to cause any trouble in that respect, we'll reconsider using it.

template<class T>
struct wrapper {
   T value;

   // wrapper(from)
   template<
      class FROM = T,
      class = std::enable_if_t<
         std::is_constructible_v<T,FROM> || std::is_convertible_v<FROM,T>
      >
   >
   wrapper(const FROM &v = FROM{}) :
      value(T(v))
   { }

   // If T == vector
   // wrapper(initializer_list)
   template<
      class TEE = T,
      class = std::enable_if_t<detail::isVector<TEE>::value>>
   wrapper(const std::initializer_list<typename TEE::value_type> &v) :
      value(v)
   { }

   // If T == optional
   // wrapper(optional::value_type)
   template<class TEE = T, class = std::enable_if_t<detail::isOptional<TEE>>>
   wrapper(const typename TEE::value_type &v) :
      value(v)
   { }

   // If T == optional
   // wrapper(nullopt_t)
   template<class TEE = T, class = std::enable_if_t<detail::isOptional<TEE>>>
   wrapper(const std::nullopt_t &v) :
      value(v)
   { }

   // Conversions
   operator const T &() const { return value; }
   operator T &() { return value; }
}; // class wrapper


// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

private:

// ------------------------
// fieldAddress
// ------------------------

template<class T>
void *fieldAddress(T &value)
{
   return &value;
}

template<class T>
void *fieldAddress(Field<T> &field)
{
   return &field();
}

// ------------------------
// stripField
// ------------------------

template<class T>
struct stripField {
   using type = T;
};

template<class T>
struct stripField<Field<T>> {
   using type = T;
};

public:
