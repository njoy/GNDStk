
// -----------------------------------------------------------------------------
// Assignment operators
// -----------------------------------------------------------------------------

// = std::nullopt_t
Optional &operator=(const std::nullopt_t)
{
   reset();
   return *this;
}

// = T
Optional &operator=(const T &val)
{
   if (ptr)
      *ptr = val;
   else
      ptr = new T(val);
   return *this;
}

// copy
Optional &operator=(const Optional &other)
{
   if (this != &other) {
      if (other.ptr)
         *this = *other.ptr;
      else
         reset();
   }
   return *this;
}

// move
Optional &operator=(Optional &&other)
{
   if (this != &other) {
      delete ptr;
      ptr = other.ptr;
      other.ptr = nullptr;
   }
   return *this;
}

// template "copy"
template<class U = T, class = std::enable_if_t<std::is_constructible_v<T,U>>>
Optional &operator=(const Optional<U> &other)
{
   if (other.ptr)
      *this = T(*other.ptr);
   else
      reset();
   return *this;
}
