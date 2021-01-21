
// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

// This class does *not* have a default constructor, because a default value
// must always be given. (Observe that the two instances of the word "default"
// in that sentence mean entirely different things.)


// ------------------------
// constructors:
// general
// ------------------------

// default value
explicit defaulted(const T &def) :
   def(def)
{ }

// default value, T
defaulted(const T &def, const T &val) :
   def(def),
   opt(val)
{ }

// default value, std::optional<T>
defaulted(const T &def, const std::optional<T> &opt) :
   def(def),
   opt(opt)
{ }

// default value, std::nullopt_t
// This has the same effect as the constructor that takes (default). We don't
// need both, but, given that the present class is similar in some respects to
// std::optional, we thought that having:
//    constructor(default)
//    constructor(default,nullopt_t)
// would provide an additional similarity, given that std::optional has:
//    constructor()
//    constructor(nullopt_t)
// That is, the present class, as compared with std::optional, just requires
// a stipulated default value as the first argument.
defaulted(const T &def, const std::nullopt_t) :
   def(def)
{ }


// ------------------------
// constructors:
// the usual suspects
// ------------------------

// copy
defaulted(const defaulted &other) :
   def(other.def),
   opt(other.opt)
{ }

// template "copy"
template<
   class U = T, bool writes = WRITES,
   class = typename std::enable_if<
      std::is_convertible<U,T>::value
   >::type
>
defaulted(const defaulted<U,writes> &other) :
   def(T(other.get_default())),
   opt(other.get_optional())
{ }

// move
defaulted(defaulted &&other) :
   def(std::move(other.def)),
   opt(std::move(other.opt))
{ }
