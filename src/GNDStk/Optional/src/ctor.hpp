
// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

// default
Optional()
{ }

// std::nullopt_t
explicit Optional(const std::nullopt_t)
{ }

// T
explicit Optional(const T &val) :
   ptr(new T(val))
{ }

// copy
Optional(const Optional &other) :
   ptr(other.ptr ? new T(*other.ptr) : nullptr)
{ }

// move
Optional(Optional &&other) :
   ptr(other.ptr)
{
   other.ptr = nullptr;
}

// template "copy"
template<class U = T, class = std::enable_if_t<std::is_constructible_v<T,U>>>
Optional(const Optional<U> &other) :
   ptr(other.ptr ? new T(*other.ptr) : nullptr)
{ }

// destructor
~Optional()
{
   reset();
}
