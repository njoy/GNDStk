
// -----------------------------------------------------------------------------
// wrapper
// This doesn't really need to be defined within class Component, but it's used
// only in that context, so it might as well be.
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
