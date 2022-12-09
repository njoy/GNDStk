
namespace detail {

// -----------------------------------------------------------------------------
// Helper classes for SFINAE
// -----------------------------------------------------------------------------

// ------------------------
// IsMeta
// ------------------------

// default
template<class T>
struct IsMeta {
   static constexpr bool value = false;
};

// Meta
template<class TYPE, class CONVERTER>
struct IsMeta<Meta<TYPE,CONVERTER>> {
   static constexpr bool value = true;
};


// ------------------------
// IsChild
// ------------------------

// default
template<class T>
struct IsChild {
   static constexpr bool value = false;
};

// Child
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
struct IsChild<Child<TYPE,ALLOW,CONVERTER,FILTER>> {
   static constexpr bool value = true;
};


// ------------------------
// IsMetaOrChild
// ------------------------

template<class T>
struct IsMetaOrChild {
   static constexpr bool value = IsMeta<T>::value || IsChild<T>::value;
};


// ------------------------
// IsStringOrRegex
// ------------------------

// default
template<class T>
struct IsStringOrRegex {
   static constexpr bool value = false;
};

// string
template<>
struct IsStringOrRegex<std::string> {
   static constexpr bool value = true;
   using type = std::string;
};

// char *
template<>
struct IsStringOrRegex<char *> {
   static constexpr bool value = true;
   using type = std::string;
};

// const char *
template<>
struct IsStringOrRegex<const char *> {
   static constexpr bool value = true;
   using type = std::string;
};

// char[N]
template<std::size_t N>
struct IsStringOrRegex<char[N]> {
   static constexpr bool value = true;
   using type = std::string;
};

// regex
template<>
struct IsStringOrRegex<std::regex> {
   static constexpr bool value = true;
   using type = std::regex;
};


// ------------------------
// IsPairChildStringOrRegex
// ------------------------

// default
template<class T>
struct IsPairChildStringOrRegex {
   static constexpr bool value = false;
};

// pair
template<class FIRST, class SECOND>
struct IsPairChildStringOrRegex<std::pair<FIRST,SECOND>> {
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
