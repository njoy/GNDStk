
// -----------------------------------------------------------------------------
// Lookup<HAS,EXTRACTOR,TYPE,CONVERTER>
// Based on Meta<TYPE,CONVERTER>
// -----------------------------------------------------------------------------

template<
   bool HAS,
   class EXTRACTOR,
   class TYPE = void,
   class CONVERTER = detail::default_converter_t<TYPE>
>
class Lookup : public Meta<TYPE,CONVERTER> {
public:
   // extractor
   EXTRACTOR extractor;

   // ctor
   Lookup(
      const EXTRACTOR &e,
      const std::string &name,
      const TYPE &value,
      const CONVERTER &converter = CONVERTER{}
   ) :
      Meta<TYPE,CONVERTER>(name,value,converter),
      extractor(e)
   { }
};

// makeLookup
template<
   bool HAS = false,
   class EXTRACTOR,
   class TYPE,
   class CONVERTER = detail::default_converter_t<TYPE>
>
auto makeLookup(
   const EXTRACTOR &extractor,
   const std::string &name,
   const TYPE &value,
   const CONVERTER &converter = CONVERTER{}
) {
   return Lookup<HAS,EXTRACTOR,TYPE,CONVERTER>(extractor,name,value,converter);
}


// -----------------------------------------------------------------------------
// Lookup<HAS,EXTRACTOR,void>
// Based on Meta<>
// -----------------------------------------------------------------------------

template<bool HAS, class EXTRACTOR, class CONVERTER>
class Lookup<HAS,EXTRACTOR,void,CONVERTER> : public Meta<> {
   static_assert(
      std::is_same_v<CONVERTER,void>,
     "Can't create Lookup<HAS,EXTRACTOR,void,CONVERTER> "
      "with non-default CONVERTER"
   );

public:
   // extractor
   EXTRACTOR extractor;

   // ctor
   Lookup(
      const EXTRACTOR &e,
      const std::string &name
   ) :
      Meta<>(name),
      extractor(e)
   { }

   // operator()
   template<class TYPE, class C = detail::default_converter_t<TYPE>>
   auto operator()(const TYPE &value, const C &converter = C{})
   {
      return Lookup<HAS,EXTRACTOR,TYPE,CONVERTER>(extractor,name,value,converter);
   }
};

// makeLookup
template<bool HAS = false, class EXTRACTOR>
auto makeLookup(
   const EXTRACTOR &extractor,
   const std::string &name
) {
   return Lookup<HAS,EXTRACTOR>(extractor,name);
}
