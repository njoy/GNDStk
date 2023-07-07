
// -----------------------------------------------------------------------------
// Component::has
// Note that some of these are usable in constexpr ifs.
// -----------------------------------------------------------------------------

// constexpr, static
// Extractor works; Lookup<get,unvalued>
// The extractor succeeds. DERIVED has a metadatum of that name.
// No value is given. We're checking for the presence of the metadatum.
template<
   class EXTRACTOR,
   class THIS = DERIVED,
   class = decltype(std::declval<EXTRACTOR>()(THIS{}))>
static constexpr bool
has(const Lookup<LookupMode::get,EXTRACTOR> &)
{
   return true;
}

// non-constexpr, non-static
// Extractor works; Lookup<get,valued>
// The extractor succeeds. DERIVED has a metadatum of that name.
// But does the value match?
template<
   class EXTRACTOR, class TYPE, class CONVERTER,
   class THIS = DERIVED,
   class = decltype(std::declval<EXTRACTOR>()(THIS{}))>
bool
has(const Lookup<LookupMode::get,EXTRACTOR,TYPE,CONVERTER> &look) const
{
   return look.extractor(derived()) == look.value;
}

// constexpr, static
// Extractor fails; Lookup<get,*>
// The extractor fails. DERIVED does not have a metadatum of that name.
// Any value to check against is meaningless here. If DERIVED doesn't
// even have, say, .foo, then we can't check if its .foo equals the
// one in the given Lookup object.
template<
   class EXTRACTOR, class TYPE, class CONVERTER,
   LookupMode GET,
   class = std::enable_if_t<GET == LookupMode::get>>
static constexpr bool
has(const Lookup<GET,EXTRACTOR,TYPE,CONVERTER> &)
{
   return false;
}
