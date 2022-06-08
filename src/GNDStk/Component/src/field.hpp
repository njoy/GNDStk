
// -----------------------------------------------------------------------------
// Field
// -----------------------------------------------------------------------------

template<class PARENT, class T>
class Field {
   PARENT &parent;
   T value;
   std::string name;

   friend PARENT;

public:

   // ------------------------
   // constructors
   // ------------------------

   explicit Field(
      PARENT *const parent,
      const T &value = T(), const std::string &name = ""
   ) :
      parent(*parent),
      value(value),
      name(name)
   { }

   Field(PARENT *const parent, const Field &field) :
      parent(*parent),
      value(field.value),
      name(field.name)
   { }

   template<class VALUE = T, class = detail::isDefaulted<VALUE>>
   Field(
      PARENT *const parent,
      const typename VALUE::value_type &def,
      const std::optional<typename VALUE::value_type> &opt,
      const std::string &name
   ) :
      parent(*parent),
      value(def,opt),
      name(name)
   { }

   // ------------------------
   // getters
   // ------------------------

   // ()
   const T &operator()() const { return value; }
   T &operator()() { return value; }

   // for vector: (index/label/Lookup)
   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class VALUE = T, class = detail::isVector<VALUE>
   >
   decltype(auto) operator()(const KEY &key) const
      { return parent.getter(value, key, name); }

   template<
      class KEY, class = detail::isSearchKey<KEY>,
      class VALUE = T, class = detail::isVector<VALUE>
   >
   decltype(auto) operator()(const KEY &key)
      { return parent.getter(value, key, name); }

   // ------------------------
   // setters
   // ------------------------

   // (T)
   PARENT &operator()(const T &other)
   {
      value = other;
      return parent;
   }

   // for Defaulted: (std::optional)
   template<class VALUE = T, class = detail::isDefaulted<VALUE>>
   PARENT &operator()(const std::optional<typename VALUE::value_type> &opt)
   {
      value = opt;
      return parent;
   }

   // for vector: (scalar)
   // vector push_back
   template<class VALUE = T, class = detail::isVector<VALUE>>
   PARENT &operator()(const typename VALUE::value_type &obj)
   {
      parent.setter(value, obj);
      return parent;
   }

   // for vector: (index/label/Lookup, value)
   // replace vector entry
   template<
      class KEY, class = detail::isSearchKeyRefReturn<KEY>,
      class VALUE = T, class = detail::isVector<VALUE>
   >
   PARENT &operator()(const KEY &key, const typename VALUE::value_type &obj)
   {
      (*this)(key) = obj;
      return parent;
   }

   // ------------------------
   // miscellaneous
   // ------------------------

   // assignment
   Field &operator=(const Field &other)
   {
      value = other.value;
      return *this;
   }

   // conversion to T
   operator const T &() const { return value; }
   operator T &() { return value; }
};


// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

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

template<class T>
struct stripField {
   using type = T;
};

template<class PARENT, class T>
struct stripField<Field<PARENT,T>> {
   using type = T;
};
