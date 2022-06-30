
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
   T value;

public:

   // ------------------------
   // Constructors
   // ------------------------

   // Because data member [DERIVED &parent] would be wrong
   Field(const Field &) = delete; // no copy
   Field(Field &&) = delete; // no move

   // The following accept DERIVED*, not DERIVED&, so that we can write "this",
   // not "*this", where Field objects are constructed. It's just a bit shorter.

   // parent, value
   explicit Field(DERIVED *const parent, const T &v = T{}) :
      parent(*parent),
      value(v)
   { }

   // parent, other Field object
   Field(DERIVED *const parent, const Field &other) :
      parent(*parent),
      value(other.value)
   { }

   // parent, default value, value
   // If T == Defaulted
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   Field(
      DERIVED *const parent, const typename TEE::value_type &def,
      const std::optional<typename TEE::value_type> &v = {}
   ) :
      parent(*parent),
      value(def,v)
   { }

   // ------------------------
   // Getters
   // ------------------------

   // ()
   const T &operator()() const { return value; }
   T &operator()() { return value; }

   // (index/label/Lookup), including Lookup<false> (via "has" function)
   // If T == vector
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>
   >
   decltype(auto) operator()(const KEY &key) const
      { return parent.getter(value,key); }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>
   >
   decltype(auto) operator()(const KEY &key)
      { return parent.getter(value,key); }

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
      if (!value) {
         log::error(
           "Cannot give valueless optional<vector> a vector value\n"
           "when the object is const");
         log::member("Field:: conversion to vector");
         throw std::exception{};
      }
      return *value;
   }

   template<class TEE = T, class = detail::isOptionalVector_t<TEE>>
   operator typename TEE::value_type &()
   {
      return *(value ? value : value = typename TEE::value_type{});
   }

   // ------------------------
   // Setters
   // ------------------------

   // (T)
   // Replace existing value with another value.
   DERIVED &operator()(const T &val)
   {
      value = val;
      return parent;
   }

   DERIVED &replace(const T &val)
   {
      return (*this)(val);
   }

   // (optional)
   // If T == Defaulted
   // Replace existing Defaulted's value with the given optional value.
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   DERIVED &operator()(const std::optional<typename TEE::value_type> &opt)
   {
      value = opt;
      return parent;
   }

   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   DERIVED &replace(const std::optional<typename TEE::value_type> &opt)
   {
      return (*this)(opt);
   }

   // (scalar)
   // If T == [optional] vector
   // Add (via push_back) to this->value, which in this context is a vector.
   template<class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   DERIVED &operator()(
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &obj
   ) {
      parent.setter(value, obj);
      return parent;
   }

   template<class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>>
   DERIVED &add(
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &obj
   ) {
      return (*this)(obj);
   }

   // (index/label/Lookup, value)
   // If T == [optional] vector
   // Find the vector's element that has the given index, label, or Lookup,
   // and replace it with the given replacement value.
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>
   >
   DERIVED &operator()(
      const KEY &key,
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &obj
   ) {
      (*this)(key) = obj;
      return parent;
   }

   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class TEE = T, class = detail::isVectorOrOptionalVector_t<TEE>
   >
   DERIVED &replace(
      const KEY &key,
      const typename detail::isVectorOrOptionalVector<TEE>::value_type &obj
   ) {
      return (*this)(key,obj);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Field &operator=(const Field &other)
   {
      value = other.value;
      return *this;
   }

   // move
   Field &operator=(Field &&other)
   {
      value = std::move(other.value);
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
   // Makes an optional. So, we must return by value,
   // and then only the const version is needed.
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const std::optional<PART> opt() const
   {
      const PART *const p = ptr();
      return p ? std::optional<PART>{*p} : std::optional<PART>{};
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

   // To optional<PART>
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator std::optional<PART>() const { return opt(); }

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

   // (index/label/Lookup), including Lookup<false> (via "has" function)
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

   // ------------------------
   // Setters
   // ------------------------

   // (value)
   // If WHOLE == variant
   // Replace existing value with another value.
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   DERIVED &operator()(const std::optional<PART> &opt)
   {
      if (opt) whole(opt.value());
      return whole.parent;
   }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   DERIVED &replace(const std::optional<PART> &opt)
   {
      return (*this)(opt);
   }

   // (index/label/Lookup, value)
   // If WHOLE == vector
   // Find the vector's element that has the given index, label, or Lookup,
   // and replace it with the given replacement value.
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &operator()(const KEY &key, const std::optional<PART> &opt)
   {
      if (opt) whole(key,opt.value());
      return whole.parent;
   }

   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &replace(const KEY &key, const std::optional<PART> &opt)
   {
      return (*this)(key,opt);
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

   // Constructor
   template<
      class FROM = T,
      class = std::enable_if_t<std::is_constructible_v<T,FROM>>>
   wrapper(const FROM &v = FROM{}) :
      value(T(v))
   { }

   // If T == optional
   template<class TEE = T, class = std::enable_if_t<detail::isOptional<TEE>>>
   wrapper(const typename TEE::value_type &v) :
      value(v)
   { }

   // If T == optional
   template<class TEE = T, class = std::enable_if_t<detail::isOptional<TEE>>>
   wrapper(const std::nullopt_t &v) :
      value(v)
   { }

   // Conversions
   operator const T &() const { return value; }
   operator T &() { return value; }
};


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
