
namespace detail {

// -----------------------------------------------------------------------------
// remove_cvref
// remove_cvrefs
// -----------------------------------------------------------------------------

// C++20 will have this
template<class T>
class remove_cvref {
public:
   using type = std::remove_cv_t<std::remove_reference_t<T>>;
};

// With -s, for tuple
template<class T>
class remove_cvrefs {
};

template<class... Ts>
class remove_cvrefs<std::tuple<Ts...>> {
public:
   using type = std::tuple<typename remove_cvref<Ts>::type ...>;
};


// -----------------------------------------------------------------------------
// has_*
// SFINAE constructs for detecting whether or not a class has certain members.
// Adapted from an answer here: https://stackoverflow.com/questions/1005476
// -----------------------------------------------------------------------------

// has_length
template<class T, class = int>
struct has_length : std::false_type { };
template<class T>
struct has_length<T,decltype((void)T::length,0)> : std::true_type { };

// has_start
template<class T, class = int>
struct has_start : std::false_type { };
template<class T>
struct has_start<T,decltype((void)T::start,0)> : std::true_type { };

// has_valueType
template<class T, class = int>
struct has_valueType : std::false_type { };
template<class T>
struct has_valueType<T,decltype((void)T::valueType,0)> : std::true_type { };


// -----------------------------------------------------------------------------
// element2element
// -----------------------------------------------------------------------------

// We don't use to_string() below, so that we can eventually deal with
// precision; to_string() might be insufficient for our needs in that respect.

// todo: see if GNDStk's convert() functions are appropriate for doing all
// possible cases here, or could be extended to be.

// arithmetic ==> string
template<class FROM>
inline void element2element(const FROM &from, std::string &to)
{
   std::ostringstream oss;
   oss << from; // <== precision would be relevant here
   to = oss.str();
}

// string ==> arithmetic
template<class TO>
inline void element2element(const std::string &from, TO &to)
{
   std::istringstream iss(from);
   iss >> to;
}

// arithmetic ==> arithmetic
template<class FROM, class TO>
inline void element2element(const FROM &from, TO &to)
{
   to = TO(from);
}

// string ==> string
inline void element2element(const std::string &from, std::string &to)
{
   // The call context is such than "from" and "to" should never actually
   // be of the same type. This overload is needed only for disambiguation.
   assert(false);
   to = from;
}

} // namespace detail
