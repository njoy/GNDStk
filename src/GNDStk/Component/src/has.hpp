
// Note that some of these are usable in constexpr ifs.

// constexpr, static
// The extractor succeeds. DERIVED has a metadatum of that name.
// No value is given. We're checking for the presence of the metadatum.
template<
   class EXTRACTOR, class THIS = DERIVED,
   class = decltype(std::declval<EXTRACTOR>()(THIS{}))>
static constexpr bool
has(const Lookup<LookupMode::get,EXTRACTOR,void,void> &)
{
   return true;
}

// constexpr, static
// The extractor fails. DERIVED does not have a metadatum of that name.
// Any value to check against is meaningless here. If DERIVED doesn't
// even have, say, .foo, then we can't check if its .foo equals the
// one in the given Lookup.
template<
   class EXTRACTOR, class TYPE, class CONVERTER, LookupMode GET,
   class = std::enable_if_t<GET == LookupMode::get>>
static constexpr bool
has(const Lookup<GET,EXTRACTOR,TYPE,CONVERTER> &)
{
   return false;
}

// non-constexpr, non-static
// The extractor succeeds. DERIVED has a metadatum of that name.
// But does the value match?
template<
   class EXTRACTOR, class TYPE, class CONVERTER, class THIS = DERIVED,
   class = decltype(std::declval<EXTRACTOR>()(THIS{}))>
bool
has(const Lookup<LookupMode::get,EXTRACTOR,TYPE,CONVERTER> &from) const
{
   return from.extractor(derived()) == from.value;
}
