
// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

// This class does *not* have a default constructor, because a value for the
// default must always be given. (Observe that the two instances of the word
// default, in the above sentence, mean entirely different things.)

// ------------------------
// constructors:
// general
// ------------------------

// default value
explicit Defaulted(const T &def) :
   def(def)
{ }

// default value, T
Defaulted(const T &def, const T &val) :
   def(def),
   opt(val)
{ }

// default value, std::optional<T>
Defaulted(const T &def, const std::optional<T> &opt) :
   def(def),
   opt(opt)
{ }

// ------------------------
// constructors:
// the usual suspects
// ------------------------

// copy, move
Defaulted(const Defaulted &other) = default;
Defaulted(Defaulted &&other) = default;

// template "copy"
template<
   class U = T,
   class = std::enable_if_t<std::is_constructible_v<T,U>>
>
Defaulted(const Defaulted<U> &other) :
   def(T(other.get_default())),
   opt(other.get_optional())
{ }
