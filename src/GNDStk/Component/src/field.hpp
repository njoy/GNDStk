
template<class, class>
class FieldPart {
   // nothing; see the partial specialization later in this file
};

// -----------------------------------------------------------------------------
// Field
// -----------------------------------------------------------------------------

template<class T>
class Field {
   using PARENT = DERIVED;
   friend PARENT;

   template<class, class>
   friend class FieldPart;

   PARENT &parent;
   T value;

public:

   // ------------------------
   // Constructors
   // ------------------------

   // because [PARENT &parent] would be wrong
   Field(const Field &) = delete;
   Field(Field &&) = delete;

   // These accept PARENT*, not PARENT&, so that we can write "this",
   // not "*this", where Field objects are constructed.

   explicit Field(PARENT *const parent, const T &value = T{}) :
      parent(*parent),
      value(value)
   { }

   Field(PARENT *const parent, const Field &other) :
      parent(*parent),
      value(other.value)
   { }

   // if T == Defaulted
   template<
      class TEE = T,
      class = std::enable_if_t<detail::isDefaulted<TEE>::value>>
   Field(
      PARENT *const parent,
      const typename TEE::value_type &def,
      const std::optional<typename TEE::value_type> &value = {}
   ) :
      parent(*parent),
      value(def,value)
   { }

   // ------------------------
   // Getters
   // ------------------------

   // ()
   const T &operator()() const { return value; }
   T &operator()() { return value; }

   // conversion to T
   // same as operator()()
   operator const T &() const { return operator()(); }
   operator T &() { return operator()(); }

   // if T == vector: (index/label/Lookup)
   // get vector element
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = std::enable_if_t<detail::isVector<TEE>::value>>
   decltype(auto) operator()(const KEY &key) const
      { return parent.getter(value, key); }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = std::enable_if_t<detail::isVector<TEE>::value>>
   decltype(auto) operator()(const KEY &key)
      { return parent.getter(value, key); }

   // ------------------------
   // Setters
   // ------------------------

   // (T)
   PARENT &operator()(const T &other)
   {
      value = other;
      return parent;
   }

   // if T == Defaulted: (std::optional)
   template<
      class TEE = T,
      class = std::enable_if_t<detail::isDefaulted<TEE>::value>>
   PARENT &operator()(const std::optional<typename TEE::value_type> &opt)
   {
      value = opt;
      return parent;
   }

   // if T == vector: (scalar)
   // vector push_back
   template<
      class TEE = T,
      class = std::enable_if_t<detail::isVector<TEE>::value>>
   PARENT &operator()(const typename TEE::value_type &obj)
   {
      parent.setter(value, obj);
      return parent;
   }

   // if T == vector: (index/label/Lookup, value)
   // replace vector element
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class TEE = T, class = std::enable_if_t<detail::isVector<TEE>::value>>
   PARENT &operator()(const KEY &key, const typename TEE::value_type &obj)
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
   using FIELD = Field<T>;
   FIELD &field;

public:

   // ------------------------
   // Constructors
   // ------------------------

   // because [FIELD &field] would be wrong
   FieldPart(const FieldPart &) = delete;
   FieldPart(FieldPart &&) = delete;

   explicit FieldPart(FIELD &field) :
      field(field)
   { }

   FieldPart(FIELD &field, const FieldPart &other) :
      field(field)
   { }

   // ------------------------
   // Getters:
   // For T == variant
   // ptr()
   // ------------------------

   template<
      class TEE = T,
      class = std::enable_if_t<detail::isVariant<TEE>::value>>
   const PART *ptr() const
   {
      return field.parent.template getter<PART>(field());
   }

   template<
      class TEE = T,
      class = std::enable_if_t<detail::isVariant<TEE>::value>>
   PART *ptr()
   {
      return field.parent.template getter<PART>(field());
   }

   // ------------------------
   // Getters:
   // For T == variant
   // operator()()
   // ------------------------

   template<
      class TEE = T,
      class = std::enable_if_t<detail::isVariant<TEE>::value>>
   const PART *operator()() const
   {
      return ptr();
   }

   template<
      class TEE = T,
      class = std::enable_if_t<detail::isVariant<TEE>::value>>
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

   template<
      class TEE = T,
      class = std::enable_if_t<detail::isVariant<TEE>::value>>
   operator const PART *() const
   {
      return operator()();
   }

   template<
      class TEE = T,
      class = std::enable_if_t<detail::isVariant<TEE>::value>>
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
      class TEE = T, class = std::enable_if_t<detail::isVector<TEE>::value>>
   decltype(auto) ptr(const KEY &key) const
   {
      return field.parent.template getter<PART>(field(), key);
   }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = std::enable_if_t<detail::isVector<TEE>::value>>
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
      class TEE = T, class = std::enable_if_t<detail::isVector<TEE>::value>>
   decltype(auto) operator()(const KEY &key) const
   {
      return ptr(key);
   }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = std::enable_if_t<detail::isVector<TEE>::value>>
   decltype(auto) operator()(const KEY &key)
   {
      return ptr(key);
   }

   // ------------------------
   // Setters
   // ------------------------

   // if T == variant: (value)
   template<
      class TEE = T,
      class = std::enable_if_t<detail::isVariant<TEE>::value>>
   DERIVED &operator()(const std::optional<PART> &obj)
   {
      if (obj) field(obj.value());
      return field.parent;
   }

   // if T == vector: (index/label/Lookup, value)
   // replace vector element
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class TEE = T, class = std::enable_if_t<detail::isVector<TEE>::value>>
   DERIVED &operator()(const KEY &key, const std::optional<PART> &obj)
   {
      if (obj) field(key,obj.value());
      return field.parent;
   }

   // ------------------------
   // Assignment
   // ------------------------

   // intentional: don't assign [referenced] field; doing so would be wrong
   FieldPart &operator=(const FieldPart &other) { return *this; }
   FieldPart &operator=(FieldPart &&other) { return *this; }
}; // class FieldPart


// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// ------------------------
// wrapper
// ------------------------

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

// ------------------------
// fieldAddress
// ------------------------

private:

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
