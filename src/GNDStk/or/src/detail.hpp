
namespace detail {

// -----------------------------------------------------------------------------
// Helper classes:
//    IsMeta
//    IsChild
//    IsMetaOrChild
//    IsStringOrRegex
// for SFINAE.
// -----------------------------------------------------------------------------

// ------------------------
// IsMeta
// ------------------------

// default
template<class T>
class IsMeta {
public:
   static constexpr bool value = false;
};

// Meta
template<class TYPE, class CONVERTER>
class IsMeta<Meta<TYPE,CONVERTER>> {
public:
   static constexpr bool value = true;
};


// ------------------------
// IsChild
// ------------------------

// default
template<class T>
class IsChild {
public:
   static constexpr bool value = false;
};

// Child
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class IsChild<Child<TYPE,ALLOW,CONVERTER,FILTER>> {
public:
   static constexpr bool value = true;
};


// ------------------------
// IsMetaOrChild
// ------------------------

template<class T>
class IsMetaOrChild {
public:
   static constexpr bool value = IsMeta<T>::value || IsChild<T>::value;
};


// ------------------------
// IsStringOrRegex
// ------------------------

// default
template<class T>
class IsStringOrRegex {
public:
   static constexpr bool value = false;
};

// string
template<>
class IsStringOrRegex<std::string> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// char *
template<>
class IsStringOrRegex<char *> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// const char *
template<>
class IsStringOrRegex<const char *> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// char[N]
template<std::size_t N>
class IsStringOrRegex<char[N]> {
public:
   static constexpr bool value = true;
   using type = std::string;
};

// regex
template<>
class IsStringOrRegex<std::regex> {
public:
   static constexpr bool value = true;
   using type = std::regex;
};


// ------------------------
// IsPairChildStringOrRegex
// ------------------------

// default
template<class T>
class IsPairChildStringOrRegex {
public:
   static constexpr bool value = false;
};

// pair
template<class FIRST, class SECOND>
class IsPairChildStringOrRegex<std::pair<FIRST,SECOND>> {
public:
   static constexpr bool value =
      IsChild<FIRST>::value && IsStringOrRegex<SECOND>::value;
};



// -----------------------------------------------------------------------------
// Helper functionality for std::tuple
// -----------------------------------------------------------------------------

// ------------------------
// tupleAllButLast
// ------------------------

// Adapted from: https://stackoverflow.com/questions/51810702

template<class... Args, std::size_t... Is>
constexpr auto tupleAllButLastHelper(
   const std::tuple<Args...> &tup,
   std::index_sequence<Is...>
) {
   return std::tuple(std::get<Is>(tup)...);
}

template<
   class... Args,
   class = std::enable_if_t<(0 < sizeof...(Args))>
>
constexpr auto tupleAllButLast(const std::tuple<Args...> &tup)
{
   return tupleAllButLastHelper(
      tup,
      std::make_index_sequence<sizeof...(Args) - 1>{}
   );
}


// ------------------------
// tupleReplaceLast
// ------------------------

// Given a tuple with at least one element, make a new tuple that's mostly the
// same, except for a different last element, which can be of a different type.

template<
   class... Args, class RHS,
   class = std::enable_if_t<(0 < sizeof...(Args))>
>
constexpr auto tupleReplaceLast(const std::tuple<Args...> &tup, const RHS &rhs)
{
   return std::tuple_cat(tupleAllButLast(tup), std::tuple<RHS>(rhs));
}

} // namespace detail
