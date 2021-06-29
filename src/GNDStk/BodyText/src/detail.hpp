
namespace detail {

// -----------------------------------------------------------------------------
// Miscellaneous
// -----------------------------------------------------------------------------

// scalarize
template<class... Ts>
auto scalarize(const std::variant<Ts...>)
{
   return std::variant<typename Ts::value_type ...>{};
}

// decays, decays_t
// Like std::decay and std::decay_t, but for tuple
template<class T>
struct decays { };
template<class... Ts>
struct decays<std::tuple<Ts...>> {
   using type = std::tuple<typename std::decay<Ts>::type ...>;
};

template<class... Ts>
using decays_t = typename decays<Ts...>::type;


// -----------------------------------------------------------------------------
// has*
// SFINAE constructs for detecting whether or not a class has certain members.
// Adapted from an answer here: https://stackoverflow.com/questions/1005476
// -----------------------------------------------------------------------------

// ------------------------
// Helpers
// ------------------------

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

// ------------------------
// Use these; they deal
// with CV and reference
// qualifiers, and don't
// require ::value
// ------------------------

template<class T>
inline constexpr bool hasLength    = has_length   <std::decay_t<T>>::value;
template<class T>
inline constexpr bool hasStart     = has_start    <std::decay_t<T>>::value;
template<class T>
inline constexpr bool hasValueType = has_valueType<std::decay_t<T>>::value;


// -----------------------------------------------------------------------------
// element2element
// -----------------------------------------------------------------------------

// We don't use to_string() below, so that we can eventually deal with
// precision; to_string() might be insufficient for our needs in that respect.
// todo: see if GNDStk's convert() functions are appropriate for doing all
// possible cases here, or could be extended to be.

// arithmetic ==> string
template<class FROM, class=std::enable_if_t<!std::is_same_v<FROM,std::string>>>
void element2element(const FROM &from, std::string &to)
{
   std::ostringstream oss;
   oss << from; // <== precision would be relevant here
   to = oss.str();
}

// string ==> arithmetic
template<class TO, class=std::enable_if_t<!std::is_same_v<TO,std::string>>>
void element2element(const std::string &from, TO &to)
{
   std::istringstream iss(from);
   iss >> to;
}

// arithmetic ==> arithmetic
template<class FROM, class TO>
void element2element(const FROM &from, TO &to)
{
   to = TO(from);
}


// -----------------------------------------------------------------------------
// getBounds
// -----------------------------------------------------------------------------

template<class T>
auto getBounds(const std::vector<T> &vec)
{
   T zero;
   if constexpr (std::is_same_v<T,std::string>) zero = ""; else zero = T(0);
   std::pair<std::size_t,std::size_t> bnd(0,vec.size());
   while (bnd.first < bnd.second && vec[bnd.first   ] == zero) ++bnd.first;
   while (bnd.first < bnd.second && vec[bnd.second-1] == zero) --bnd.second;
   return bnd;
}

} // namespace detail
