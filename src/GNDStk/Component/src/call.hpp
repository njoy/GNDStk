
// These essentially provide an alternative to the has() member functions,
// using operator() combined with the has() free functions: obj(has(...)).

template<
   class EXTRACTOR, class THIS = DERIVED,
   class = decltype(std::declval<EXTRACTOR>()(THIS{}))>
constexpr bool operator()(
   const Lookup<LookupMode::exists,EXTRACTOR> &
) const {
   return true;
}

template<
   class EXTRACTOR, class TYPE, class CONVERTER, class THIS = DERIVED,
   class = decltype(std::declval<EXTRACTOR>()(THIS{}))>
bool operator()(
   const Lookup<LookupMode::exists,EXTRACTOR,TYPE,CONVERTER> &from
) const {
   return from.extractor(derived()) == from.value;
}

template<
   class EXTRACTOR, class TYPE, class CONVERTER, LookupMode EXISTS,
   class = std::enable_if_t<EXISTS == LookupMode::exists>>
constexpr bool operator()(
   const Lookup<EXISTS,EXTRACTOR,TYPE,CONVERTER> &
) const {
   return false;
}
