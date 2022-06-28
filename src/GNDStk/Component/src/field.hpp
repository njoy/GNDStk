
template<class, class>
class FieldPart {
   // Nothing; see the partial specialization later in this file
};

// -----------------------------------------------------------------------------
// Field
// -----------------------------------------------------------------------------

template<class T>
class Field {
   friend DERIVED;

   template<class, class>
   friend class FieldPart;

   DERIVED &parent;
   T value;

public:

   // ------------------------
   // Constructors
   // ------------------------

   // Because data member [DERIVED &parent] would be wrong
   Field(const Field &) = delete;
   Field(Field &&) = delete;

   // The following accept DERIVED*, not DERIVED&, so that we can write "this",
   // not "*this", where Field objects are constructed. It's just a bit shorter.

   explicit Field(DERIVED *const parent, const T &value = T{}) :
      parent(*parent),
      value(value)
   { }

   Field(DERIVED *const parent, const Field &other) :
      parent(*parent),
      value(other.value)
   { }

   // If T == Defaulted
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   Field(
      DERIVED *const parent, const typename TEE::value_type &def,
      const std::optional<typename TEE::value_type> &value = {}
   ) :
      parent(*parent),
      value(def,value)
   { }

   // ------------------------
   // Getters
   // ------------------------

   // ()
   // Return reference to value (which is of type T)
   const T &operator()() const { return value; }
   T &operator()() { return value; }

   // Conversion to T
   // Same as ()
   operator const T &() const { return (*this)(); }
   operator T &() { return (*this)(); }

   // (index/label/Lookup)
   // If T == vector
   // Return reference to vector element (which is of type T::value_type,
   // because T in this context is a vector).
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVector_t<TEE>
   >
   decltype(auto) operator()(const KEY &key) const
      { return parent.getter(value, key); }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVector_t<TEE>
   >
   decltype(auto) operator()(const KEY &key)
      { return parent.getter(value, key); }

   // ------------------------
   // Setters
   // ------------------------

   // (T)
   // Replace existing value with another value.
   DERIVED &operator()(const T &other)
   {
      value = other;
      return parent;
   }

   // (std::optional)
   // If T == Defaulted
   // Replace existing Defaulted's value with the given optional value.
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   DERIVED &operator()(const std::optional<typename TEE::value_type> &opt)
   {
      value = opt;
      return parent;
   }

   // (scalar)
   // If T == vector
   // Add (via push_back) to this->value, which in this context is a vector.
   template<class TEE = T, class = detail::isVector_t<TEE>>
   DERIVED &operator()(const typename TEE::value_type &obj)
   {
      parent.setter(value, obj);
      return parent;
   }

   // (index/label/Lookup, value)
   // if T == vector
   // Find the vector's element that has the given index, label, or Lookup,
   // and replace it with the given replacement value.
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class TEE = T, class = detail::isVector_t<TEE>
   >
   DERIVED &operator()(const KEY &key, const typename TEE::value_type &obj)
   {
      (*this)(key) = obj;
      return parent;
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
   Field<WHOLE> &field; /// maybe call this "whole"?

   static_assert(
      detail::isVariant<WHOLE>::value || detail::isVectorVariant<WHOLE>::value,
     "FieldPart<Field<WHOLE>,PART>: "
     "WHOLE must be std::variant or std::vector<std::variant>"
   );

public:

   // ------------------------
   // Constructors
   // ------------------------

   // Because [Field<WHOLE> &field] would be wrong
   FieldPart(const FieldPart &) = delete;
   FieldPart(FieldPart &&) = delete;

   explicit FieldPart(Field<WHOLE> &field) :
      field(field)
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
      return field.parent.template getter<PART>(field());
   }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART *ptr()
   {
      return field.parent.template getter<PART>(field());
   }

   // ref()
   // Get as PART &
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const PART &ref() const
   {
      const PART *const p = ptr();
      if (p) return *p;
      log::error(
        "Cannot get reference; variant contains a different alternative.");
      throw std::exception{};
   }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART &ref()
   {
      return const_cast<PART &>(std::as_const(*this).template ref());
   }

   // opt()
   // Makes an optional. So, we must return by value,
   // and only the const version is needed.
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const std::optional<PART> opt() const
   {
      const PART *const p = ptr();
      return p ? std::optional<PART>{*p} : std::optional<PART>{};
   }

   // operator()
   // Get as PART &
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const PART &operator()() const { return ref(); }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART &operator()() { return ref(); }

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
   operator const PART &() const { return ref(); }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator PART &() { return ref(); }

   // To optional<PART>
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator std::optional<PART>() const { return opt(); }

   // ------------------------
   // Getters:
   // If WHOLE == vector
   // ptr(index/label/Lookup)
   // Get vector element
   // ------------------------

   // zzz Need to look these over carefully and compare with what we have
   // in comp-detail-getter.hh. Make consistent the use, there, of pointers
   // versus references for return type; then clarify in this file.
   // Also: have log::context for log::error calls in this file.

   // ptr(key)
   // Get as PART *
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   const PART *ptr(const KEY &key) const
   {
      return field.parent.template getter<PART>(field(), key);
   }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   PART *ptr(const KEY &key)
   {
      return field.parent.template getter<PART>(field(), key);
   }

   // ref(key)
   // Get as PART &
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   const PART &ref(const KEY &key) const
   {
      const PART *const p = ptr(key);
      if (p) return *p;
      log::error(
        "Cannot get reference; key not found.");
      throw std::exception{};
   }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   PART &ref(const KEY &key)
   {
      return const_cast<PART &>(std::as_const(*this).template ref(key));
   }

   // opt(key)
   // Makes an optional. So, we must return by value,
   // and only the const version is needed.
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   const std::optional<PART> opt(const KEY &key) const
   {
      const PART *const p = ptr(key);
      return p ? std::optional<PART>{*p} : std::optional<PART>{};
   }

   // operator()(key)
   // Get as PART &
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   const PART &operator()(const KEY &key) const { return ref(key); }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>
   >
   PART &operator()(const KEY &key) { return ref(key); }

#if 0
#if 0
#if 0
   // ------------------------
   // Getters:
   // If WHOLE == vector
   // operator()(index/label/Lookup)
   // Get vector element
   // ------------------------

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   decltype(auto) operator()(const KEY &key) const
   {
      return ptr(key);
   }
   // zzz I think these conflict with the above
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   decltype(auto) operator()(const KEY &key)
   {
      return ptr(key);
   }
#endif
#endif
#endif

   // ------------------------
   // Setters
   // ------------------------

   // (value)
   // If WHOLE == variant
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   DERIVED &operator()(const std::optional<PART> &obj)
   {
      if (obj) field(obj.value());
      return field.parent;
   }

   // (index/label/Lookup, value)
   // If WHOLE == vector
   // Replace vector element.
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &operator()(const KEY &key, const std::optional<PART> &obj)
   {
      if (obj) field(key,obj.value());
      return field.parent;
   }

   // ------------------------
   // Assignment
   // ------------------------

   // Intentional: don't assign [referenced] field; doing so would be wrong
   FieldPart &operator=(const FieldPart &) { return *this; }
   FieldPart &operator=(FieldPart &&) { return *this; }
}; // class FieldPart


// -----------------------------------------------------------------------------
// wrapper
// -----------------------------------------------------------------------------

template<class T>
struct wrapper {
   T value;

   template<
      class FROM = T,
      class = std::enable_if_t<std::is_constructible_v<T,FROM>>>
   wrapper(const FROM &v = FROM{}) :
      value(T(v))
   { }

   // if T == std::optional
   template<class TEE = T, class = std::enable_if_t<detail::isOptional<TEE>>>
   wrapper(const typename TEE::value_type &v) :
      value(v)
   { }

   // if T == std::optional
   template<class TEE = T, class = std::enable_if_t<detail::isOptional<TEE>>>
   wrapper(const std::nullopt_t &v) :
      value(v)
   { }

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
void *fieldAddress(Field<T> &value)
{
   return &value();
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
