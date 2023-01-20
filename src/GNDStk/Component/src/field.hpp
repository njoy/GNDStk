
template<class, class>
class FieldPart {
   // Nothing; see the partial specialization later in this file
};


// -----------------------------------------------------------------------------
// Field
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

   // Because parent would be wrong
   Field(const Field &) = delete; // no copy
   Field(Field &&) = delete; // no move

   // The following accept DERIVED*, not DERIVED&, so that we can write "this",
   // not "*this", where Field objects are constructed. It's just a bit shorter.

   // parent
   // This could be rolled into the (parent, value) constructor below, but the
   // compiler seems to be better able to optimize the construction of objects
   // with class Field data members if we split it out.
   explicit Field(DERIVED *const parent) :
      parent(*parent),
      wrappedValue(T{})
   { }

   // parent, value
   explicit Field(DERIVED *const parent, const T &v) :
      parent(*parent),
      wrappedValue(v)
   { }

   // parent, other Field object
   Field(DERIVED *const parent, const Field &other) :
      parent(*parent),
      wrappedValue(other.wrappedValue)
   { }

   // parent, default value, current value (std::optional)
   // If T == Defaulted
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   Field(
      DERIVED *const parent, const typename TEE::value_type &def,
      const std::optional<typename TEE::value_type> &v = {}
   ) :
      parent(*parent),
      wrappedValue(def,v)
   { }

   /*
   // parent, default value, current value (GNDStk::Optional)
   // If T == Defaulted
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   Field(
      DERIVED *const parent, const typename TEE::value_type &def,
      const GNDStk::Optional<typename TEE::value_type> &v = {}
   ) :
      parent(*parent),
      wrappedValue(def,v)
   { }
   */

   // ------------------------
   // has
   // ------------------------

   // has()
   // With no arguments.
   // Relates to std::optional/GNDStk::Optional, not to the question of what
   // metadata or metadata values the present Field might contain. (See the
   // below function for that.) Returns true iff T is either *not* optional,
   // or is optional *and* has a value.
   bool has() const
   {
      if constexpr (detail::isOptional<T>)
         return wrappedValue.has_value();
      else
         return true;
   }

   // has()
   // With one argument.
   // Forwards to [operator()(const KEY &key) const], below, essentially to
   // provide an alternative form of a "has" query. Instead of, for example,
   //    H.isotope(has(mass_number(2)))
   // to inquire as to whether element H's vector of isotopes has one with
   // a mass number of 2, one could instead write:
   //    H.isotope.has(mass_number(2))
   // to make exactly the same query. (The example assumes that H is of a
   // class - say, Element - that contains a vector of isotopes, and that
   // the Isotope class contains an integer metadatum called mass_number.)
   // Note: the SFINAE is such that this function is enabled iff a call to
   // operator()(key) of the present class would be valid and return bool.
   template<
      class KEY,
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
   // Get past optional
   // where necessary
   // ------------------------

   // Note: the parentheses in "return (wrappedValue)" are necessary in
   // these, so that the decltype(auto) return types produce references!

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
   // Getters
   // ------------------------

   // ()
   // Get exactly the Field-wrapped value, whatever it is (including optional)
   const T &operator()() const { return wrappedValue; }
   T &operator()() { return wrappedValue; }

   // (index/label/Lookup), including Lookup<true> (via the "has" function)
   // If T == vector
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>
   >
   decltype(auto) operator()(const KEY &key) const
      { return parent.getter(wrappedValue,key); }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>
   >
   decltype(auto) operator()(const KEY &key)
      { return parent.getter(wrappedValue,key); }

   // [index/label/Lookup]
   // If T == vector
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>
   >
   decltype(auto) operator[](const KEY &key) const
      { return (*this)(key); }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>
   >
   decltype(auto) operator[](const KEY &key)
      { return (*this)(key); }

   // size()
   // If T == vector
   template<
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>
   >
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
   operator const T &() const { return (*this)(); }
   operator T &() { return (*this)(); }

   // To vector, if T == optional<vector>
   template<class TEE = T, class = detail::isOptionalVector_t<TEE>>
   operator const typename TEE::value_type &() const
   {
      if (!wrappedValue) {
         log::error(
           "Cannot give valueless optional<vector> a vector value\n"
           "when the object is const");
         log::member("Field:: conversion to vector");
         throw std::exception{};
      }
      return *wrappedValue;
   }

   template<class TEE = T, class = detail::isOptionalVector_t<TEE>>
   operator typename TEE::value_type &()
   {
      return *(
         wrappedValue
          ? wrappedValue
          : wrappedValue = typename TEE::value_type{}
      );
   }

   // ------------------------
   // Setters: general
   // ------------------------

   // replace(T)
   // Replace existing value with another.
   // Provides a "builder pattern" for DERIVED.
   DERIVED &replace(const T &val)
   {
      wrappedValue = val;
      return parent;
   }

   // operator()(T)
   // Provides a "builder pattern" for DERIVED. Note that no ambiguity should
   // arise with Field<vector>'s operator() that accepts an index, a label, or
   // a Lookup object, because the parameter here is also a T (and thus is a
   // vector if we're in a Field<vector>).
   DERIVED &operator()(const T &val)
   {
      return replace(val);
   }

   // operator=(T)
   // Returns the left-hand side, as one would probably expect. For assignment,
   // a builder pattern for DERIVED would just be goofy.
   Field &operator=(const T &val)
   {
      return replace(val), *this;
   }

   // ------------------------
   // Setters: for Defaulted;
   // remarks as above
   // ------------------------

   // replace(optional)
   // Replace existing Defaulted's value with the given value.
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
   // As above.
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
   // As above, except returns Field, as expected for assignment.
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

   // add(element)
   // If T == [optional] vector
   // Add (via push_back()) to this->wrappedValue, which in this context
   // is a vector.
   template<class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   Field &add(
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &elem
   ) {
      Component::setter(wrappedValue, elem);
      return *this;
   }

   // Here, we actually don't want an operator() that forwards to add(), like
   // the operator()s that forwarded to replace() in earlier setters. Imagine
   // that this Field wrapped, say, a vector<int>. If someone used the above
   // add() function and wrote field.add(123), the meaning is clearly that 123
   // is to be added (think push_back()) to the vector<int>. But if we allowed
   // for an operator() that forwards to add(), and someone used it to write
   // field(123), they *might* want 123 added to the vector - or they might
   // be intending to retrieve vector[123]. In the *getter* functions defined
   // earlier, note that we do indeed allow both operator() and operator[] for
   // retrieving vector elements (by index, label, or Lookup object). I suppose
   // we could allow only the operator[] form for getting, and then be able to
   // have an operator() setter here, with the same meaning as add(). However,
   // we believe that the getter's use of the operator() in question provides
   // for the better and more-expected meaning.

   // operator+=(element)
   template<class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   Field &operator+=(
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &elem
   ) {
      return add(elem);
   }

   // ------------------------
   // Setters: for vector or
   // optional vector, replace
   // an element
   // ------------------------

   // The following may not see too much use. They mostly have the same effect
   // as indexing into the vector and then doing an assignment. The difference
   // is that these functions endow the operation with a "builder pattern" for
   // DERIVED, and in that respect are analogous to replace(T) and operator()(T)
   // as defined earlier. Indexing+assignment, in contrast, returns a reference
   // to the assignment's left-hand side (as one would expect from assignment),
   // which is the current Field, not its parent DERIVED.

   // replace(index/label/Lookup, element)
   // Find the vector's element that has the given index, label, or Lookup,
   // and replace it with the given replacement element.
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>
   >
   DERIVED &replace(
      const KEY &key,
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &elem
   ) {
      (*this)(key) = elem;
      return parent;
   }

   // operator()(index/label/Lookup, element)
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>
   >
   DERIVED &operator()(
      const KEY &key,
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &elem
   ) {
      return replace(key,elem);
   }

   // ------------------------
   // Assignment
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
}; // class Field


// -----------------------------------------------------------------------------
// FieldPart
// -----------------------------------------------------------------------------

template<class WHOLE, class PART>
class FieldPart<Field<WHOLE>,PART> {
   Field<WHOLE> &whole;

   static_assert(
      detail::isVariant<WHOLE>::value || detail::isVectorVariant<WHOLE>::value,
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
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   const PART *ptr(const KEY &key) const
   {
      return whole.parent.template getter<PART>(whole(),key);
   }

   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   PART *ptr(const KEY &key)
   {
      return whole.parent.template getter<PART>(whole(),key);
   }

   // ref(index/label/Lookup)
   // Get as PART &
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
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
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   PART &ref(const KEY &key)
   {
      return const_cast<PART &>(std::as_const(*this).template ref(key));
   }

   // opt(index/label/Lookup)
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   const std::optional<PART> opt(const KEY &key) const
   {
      const PART *const p = ptr(key);
      return p ? std::optional<PART>{*p} : std::optional<PART>{};
   }

   // Opt(index/label/Lookup)
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   const GNDStk::Optional<PART> Opt(const KEY &key) const
   {
      const PART *const p = ptr(key);
      return p ? GNDStk::Optional<PART>{*p} : GNDStk::Optional<PART>{};
   }

   // (index/label/Lookup), including Lookup<true> (via the "has" function)
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   decltype(auto) operator()(const KEY &key) const
   {
      if constexpr (detail::isLookupBoolReturn<KEY>) {
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
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   decltype(auto) operator()(const KEY &key)
   {
      if constexpr (detail::isLookupBoolReturn<KEY>) {
         // a bool
         return whole(key);
      } else {
         // a reference
         return const_cast<PART &>(std::as_const(*this)(key));
      }
   }

   // [index/label/Lookup]
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   decltype(auto) operator[](const KEY &key) const
      { return (*this)(key); }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   decltype(auto) operator[](const KEY &key)
      { return (*this)(key); }

   // size()
   // If T == vector
   template<
      class T = WHOLE, class = detail::isVector_t<T>
   >
   std::size_t size() const
   {
      return whole.size();
   }

   // ------------------------
   // Setters
   // Using std::optional
   // ------------------------

   // replace(value)
   // If WHOLE == variant
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

   // add(value)
   // If WHOLE == vector
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

   // replace(index/label/Lookup, element)
   // If WHOLE == vector
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &replace(const KEY &key, const std::optional<PART> &opt)
   {
      if (opt) whole(key,opt.value());
      return whole.parent;
   }

   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &operator()(const KEY &key, const std::optional<PART> &opt)
   {
      return replace(key,opt);
   }

   // ------------------------
   // Setters
   // Using GNDStk::Optional
   // ------------------------

   // replace(value)
   // If WHOLE == variant
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

   // add(value)
   // If WHOLE == vector
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

   // replace(index/label/Lookup, element)
   // If WHOLE == vector
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &replace(const KEY &key, const GNDStk::Optional<PART> &opt)
   {
      if (opt) whole(key,opt.value());
      return whole.parent;
   }

   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
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
// -----------------------------------------------------------------------------

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

   // wrapper(initializer_list)
   // If T == vector
   template<
      class TEE = T,
      class = std::enable_if_t<detail::isVector<TEE>::value>
   >
   wrapper(const std::initializer_list<typename TEE::value_type> &v) :
      value(v)
   { }

   // wrapper(optional::value_type)
   // If T == std::optional or GNDStk::Optional
   template<class TEE = T, class = std::enable_if_t<detail::isOptional<TEE>>>
   wrapper(const typename TEE::value_type &v) :
      value(v)
   { }

   // wrapper(nullopt_t)
   // If T == std::optional or GNDStk::Optional
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
