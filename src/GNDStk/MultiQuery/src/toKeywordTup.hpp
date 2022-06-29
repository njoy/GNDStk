
// -----------------------------------------------------------------------------
// toKeywordTup
// -----------------------------------------------------------------------------

// for std::tuple
template<class... Args>
constexpr auto toKeywordTup(const std::tuple<Args...> &tup)
{
   return KeywordTup<Args...>(tup);
}

// for KeywordTup
template<class... Args>
constexpr auto toKeywordTup(const KeywordTup<Args...> &kwds)
{
   return kwds;
}

// for Meta, Child, and pair<Child,string/regex>
// Returns a 1-element KeywordTup made from the object
template<
   class T,
   class = std::enable_if_t<
       detail::IsMetaOrChild<T>::value ||
       detail::IsPairChildStringOrRegex<T>::value
   >
>
constexpr auto toKeywordTup(const T &obj)
{
   return KeywordTup<T>(obj);
}
