
// -----------------------------------------------------------------------------
// Assignment operators
// -----------------------------------------------------------------------------

// ------------------------
// Assignment:
// general
// ------------------------

// = T
Defaulted &operator=(const T &val)
{
   this->opt = val;
   return *this;
}

// = optional<T>
Defaulted &operator=(const std::optional<T> &opt)
{
   this->opt = opt;
   return *this;
}

// ------------------------
// Assignment:
// the usual suspects
// ------------------------

// copy, move
Defaulted &operator=(const Defaulted &other) = default;
Defaulted &operator=(Defaulted &&other) = default;

// template "copy"
template<
   class U = T,
   class = std::enable_if_t<std::is_constructible_v<T,U>>
>
Defaulted &operator=(const Defaulted<U> &other)
{
   def = T(other.get_default());
   opt = other.get_optional();
   return *this;
}
