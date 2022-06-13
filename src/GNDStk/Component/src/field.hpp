
template<class, class>
class FieldPart {
   // nothing; see the partial specialization later in this file
};

// -----------------------------------------------------------------------------
// Field
// -----------------------------------------------------------------------------

template<class PARENT, class T>
class Field {
   PARENT &parent;
   T value;
   const std::string name;

   friend PARENT;

   template<class, class>
   friend class FieldPart;

public:

   // ------------------------
   // Constructors
   // ------------------------

   // because [PARENT &parent] would be wrong
   Field(const Field &) = delete;
   Field(Field &&) = delete;

   // These accept PARENT*, not PARENT&, so that we can write "this",
   // not "*this", where Field objects are constructed.

   explicit Field(
      PARENT *const parent,
      const T &value = T{}, const std::string &name = ""
   ) :
      parent(*parent),
      value(value),
      name(name)
   { }

   Field(
      PARENT *const parent, const Field &other
   ) :
      parent(*parent),
      value(other.value),
      name(other.name)
   { }

   // if T == Defaulted
   template<
      class TEE = T,
      class = std::enable_if_t<detail::isDefaulted<TEE>::value>>
   Field(
      PARENT *const parent,
      const typename TEE::value_type &def,
      const std::optional<typename TEE::value_type> &value = {},
      const std::string &name = ""
   ) :
      parent(*parent),
      value(def,value),
      name(name)
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
      { return parent.getter(value, key, name); }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = std::enable_if_t<detail::isVector<TEE>::value>>
   decltype(auto) operator()(const KEY &key)
      { return parent.getter(value, key, name); }

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
};


// -----------------------------------------------------------------------------
// FieldPart
// -----------------------------------------------------------------------------

template<class PARENT, class T, class PART>
class FieldPart<Field<PARENT,T>,PART> {
   using FIELD = Field<PARENT,T>;

   FIELD &field;
   const std::string name;

public:

   // ------------------------
   // Constructors
   // ------------------------

   // because [FIELD &field] would be wrong
   FieldPart(const FieldPart &) = delete;
   FieldPart(FieldPart &&) = delete;

   explicit FieldPart(FIELD &field, const std::string &name = "") :
      field(field),
      name(name)
   { }

   FieldPart(FIELD &field, const FieldPart &other) :
      field(field),
      name(other.name)
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
      return field.parent.template getter<PART>(field(), name);
   }

   template<
      class TEE = T,
      class = std::enable_if_t<detail::isVariant<TEE>::value>>
   PART *ptr()
   {
      return field.parent.template getter<PART>(field(), name);
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
      return field.parent.template getter<PART>(field(), key, name);
   }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class TEE = T, class = std::enable_if_t<detail::isVector<TEE>::value>>
   decltype(auto) ptr(const KEY &key)
   {
      return field.parent.template getter<PART>(field(), key, name);
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
   PARENT &operator()(const std::optional<PART> &obj)
   {
      if (obj) field(obj.value());
      return field.parent;
   }

   // if T == vector: (index/label/Lookup, value)
   // replace vector element
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class TEE = T, class = std::enable_if_t<detail::isVector<TEE>::value>>
   PARENT &operator()(const KEY &key, const std::optional<PART> &obj)
   {
      if (obj) field(key,obj.value());
      return field.parent;
   }

   // ------------------------
   // Assignment
   // ------------------------

   // intentional: don't assign field (wrong) or name (unnecessary)
   FieldPart &operator=(const FieldPart &other) { return *this; }
   FieldPart &operator=(FieldPart &&other) { return *this; }
};


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

template<class PARENT, class T>
void *fieldAddress(Field<PARENT,T> &value)
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

template<class PARENT, class T>
struct stripField<Field<PARENT,T>> {
   using type = T;
};
