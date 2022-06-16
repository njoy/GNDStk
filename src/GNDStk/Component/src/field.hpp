
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

   // These accept DERIVED*, not DERIVED&, so that we can write "this",
   // not "*this", where Field objects are constructed.

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
   // Same as operator()()
   operator const T &() const { return operator()(); }
   operator T &() { return operator()(); }

   // If T == vector: (index/label/Lookup)
   // Return reference to vector element (which is of type T::value_type,
   // because T in this context is a vector).
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVector_t<TEE>>
   decltype(auto) operator()(const KEY &key) const
      { return parent.getter(value, key); }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVector_t<TEE>>
   decltype(auto) operator()(const KEY &key)
      { return parent.getter(value, key); }

   // ------------------------
   // Setters
   // ------------------------

   // (T)
   // Replace existing value with other value.
   DERIVED &operator()(const T &other)
   {
      value = other;
      return parent;
   }

   // If T == Defaulted: (std::optional)
   // Replace existing Defaulted's value with the given optional value.
   template<class TEE = T, class = detail::isDefaulted_t<TEE>>
   DERIVED &operator()(const std::optional<typename TEE::value_type> &opt)
   {
      value = opt;
      return parent;
   }

   // If T == vector: (scalar)
   // Add (via push_back) to this->value, which in this context is a vector.
   template<class TEE = T, class = detail::isVector_t<TEE>>
   DERIVED &operator()(const typename TEE::value_type &obj)
   {
      parent.setter(value, obj);
      return parent;
   }

   // if T == vector: (index/label/Lookup, value)
   // Find the vector's element that has the given index, label, or Lookup,
   // and replace it with the given replacement value.
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class TEE = T, class = detail::isVector_t<TEE>>
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

template<class T, class PART>
class FieldPart<Field<T>,PART> {
   Field<T> &field;

public:

   // ------------------------
   // Constructors
   // ------------------------

   // Because [Field<T> &field] would be wrong
   FieldPart(const FieldPart &) = delete;
   FieldPart(FieldPart &&) = delete;

   explicit FieldPart(Field<T> &field) :
      field(field)
   { }

   FieldPart(Field<T> &field, const FieldPart &other) :
      field(field)
   { }

   // ------------------------
   // Getters:
   // For T == variant
   // ptr()
   // ------------------------

   template<class TEE = T, class = detail::isVariant_t<TEE>>
   const PART *ptr() const
   {
      return field.parent.template getter<PART>(field());
   }

   template<class TEE = T, class = detail::isVariant_t<TEE>>
   PART *ptr()
   {
      return field.parent.template getter<PART>(field());
   }

   // ------------------------
   // Getters:
   // For T == variant
   // operator()()
   // ------------------------

   template<class TEE = T, class = detail::isVariant_t<TEE>>
   const PART *operator()() const
   {
      return ptr();
   }

   template<class TEE = T, class = detail::isVariant_t<TEE>>
   PART *operator()()
   {
      return ptr();
   }

   // ------------------------
   // Getters:
   // For T == variant
   // Conversion to PART
   // Same as operator()()
   // ------------------------

   template<class TEE = T, class = detail::isVariant_t<TEE>>
   operator const PART *() const
   {
      return operator()();
   }

   template<class TEE = T, class = detail::isVariant_t<TEE>>
   operator PART *()
   {
      return operator()();
   }

   // ------------------------
   // Getters:
   // For T == vector
   // ptr(index/label/Lookup)
   // Get vector element
   // ------------------------

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVector_t<TEE>>
   decltype(auto) ptr(const KEY &key) const
   {
      return field.parent.template getter<PART>(field(), key);
   }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVector_t<TEE>>
   decltype(auto) ptr(const KEY &key)
   {
      return field.parent.template getter<PART>(field(), key);
   }

   // ------------------------
   // Getters:
   // For T == vector
   // operator()(index/label/Lookup)
   // Get vector element
   // ------------------------

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVector_t<TEE>>
   decltype(auto) operator()(const KEY &key) const
   {
      return ptr(key);
   }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = detail::isVector_t<TEE>>
   decltype(auto) operator()(const KEY &key)
   {
      return ptr(key);
   }

   // ------------------------
   // Setters
   // ------------------------

   // If T == variant: (value)
   template<class TEE = T, class = detail::isVariant_t<TEE>>
   DERIVED &operator()(const std::optional<PART> &obj)
   {
      if (obj) field(obj.value());
      return field.parent;
   }

   // If T == vector: (index/label/Lookup, value)
   // Replace vector element.
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class TEE = T, class = detail::isVector_t<TEE>>
   DERIVED &operator()(const KEY &key, const std::optional<PART> &obj)
   {
      if (obj) field(key,obj.value());
      return field.parent;
   }

   // ------------------------
   // Assignment
   // ------------------------

   // Intentional: don't assign [referenced] field; doing so would be wrong
   FieldPart &operator=(const FieldPart &other) { return *this; }
   FieldPart &operator=(FieldPart &&other) { return *this; }
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
