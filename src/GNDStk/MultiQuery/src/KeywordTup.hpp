
// -----------------------------------------------------------------------------
// KeywordTup
// -----------------------------------------------------------------------------

// default
template<class... Ks>
class KeywordTup {
public:
   std::tuple<Ks...> tup;

   using last_t =
      // Sans std::decay, const &ness can break detail::IsSomething<> traits.
      // Note: sizeof...(Ks) >= 1 here, because we'll specialize the <> case
      std::decay_t<decltype(std::get<sizeof...(Ks)-1>(tup))>;

   // KeywordTup(KeywordTup, RHS)
   template<
      class... LHS, class RHS,
      // ensure Ks... == LHS... RHS
      class = std::enable_if_t<
         std::is_same_v<
            std::tuple<Ks...>,
            std::tuple<LHS...,RHS>
         >
      >,
      // ensure RHS \in {Meta, Child, pair<Child,string|regex>, string, regex}
      class = std::enable_if_t<
          detail::IsMetaOrChild<RHS>::value ||
          detail::IsPairChildStringOrRegex<RHS>::value
      >
   >
   KeywordTup(const KeywordTup<LHS...> &lhs, const RHS &rhs) :
      tup(std::tuple_cat(lhs.tup, std::tuple<RHS>(rhs)))
   { }

   // KeywordTup(tuple)
   KeywordTup(const std::tuple<Ks...> &tup) :
      tup(tup)
   { }
};


// <>
// intentionally non-constructible
template<>
class KeywordTup<>
{
   KeywordTup() = delete;
   KeywordTup(const KeywordTup &) = delete;
   KeywordTup(KeywordTup &&) = delete;
};


// just Meta
template<class TYPE, class CONVERTER>
class KeywordTup<Meta<TYPE,CONVERTER>> {
   using M = Meta<TYPE,CONVERTER>;
public:
   std::tuple<M> tup;
   explicit KeywordTup(const M &m) : tup(m) { }
};


// just Child
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class KeywordTup<Child<TYPE,ALLOW,CONVERTER,FILTER>> {
   using C = Child<TYPE,ALLOW,CONVERTER,FILTER>;
public:
   std::tuple<C> tup;
   explicit KeywordTup(const C &c) : tup(c) { }
};


// std::pair<Child,string>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class KeywordTup<std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::string>> {
   using CPAIR = std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::string>;
public:
   using last_t = CPAIR;
   std::tuple<CPAIR> tup;
   explicit KeywordTup(const CPAIR &cpair) : tup(cpair) { }
};


// std::pair<Child,regex>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
class KeywordTup<std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::regex>> {
   using CPAIR = std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::regex>;
public:
   using last_t = CPAIR;
   std::tuple<CPAIR> tup;
   explicit KeywordTup(const CPAIR &cpair) : tup(cpair) { }
};
