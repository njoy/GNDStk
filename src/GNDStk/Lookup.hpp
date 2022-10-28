
/*
todo
The contents of this file could really use some documentation.
Let's do this when other priorities allow.
*/

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
   static inline constexpr bool Has = HAS;
   static inline constexpr bool Void = false;

   // extractor
   EXTRACTOR extractor;

   // constructor
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
   return Lookup<HAS,EXTRACTOR,TYPE,CONVERTER>(
      extractor, name, value, converter);
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
   static inline constexpr bool Has = HAS;
   static inline constexpr bool Void = true;

   // extractor
   EXTRACTOR extractor;

   // constructor
   Lookup(
      const EXTRACTOR &e,
      const std::string &name
   ) :
      Meta<>(name),
      extractor(e)
   { }

   // operator()
   template<class TYPE, class C = detail::default_converter_t<TYPE>>
   auto operator()(const TYPE &value, const C &converter = C{}) const
   {
      return Lookup<HAS,EXTRACTOR,TYPE,C>(
         extractor, name, value, converter);
   }

   // operator() for char*; needed in order to force std::string
   template<class C = detail::default_converter_t<std::string>>
   auto operator()(const char *const value, const C &converter = C{}) const
   {
      return Lookup<HAS,EXTRACTOR,std::string,C>(
         extractor, name, value, converter);
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


// -----------------------------------------------------------------------------
// has
// -----------------------------------------------------------------------------

// For TYPE != void
template<
   class EXTRACTOR, class TYPE, class CONVERTER,
   class = std::enable_if_t<!std::is_same_v<TYPE,void>>
>
auto has(const Lookup<false,EXTRACTOR,TYPE,CONVERTER> &look)
{
   return Lookup<true,EXTRACTOR,TYPE,CONVERTER>(
      look.extractor,
      look.name,
      look.placeholder,
      look.converter
   );
}

// For TYPE == void
template<class EXTRACTOR>
auto has(const Lookup<false,EXTRACTOR,void,void> &look)
{
   return Lookup<true,EXTRACTOR,void,void>(
      look.extractor,
      look.name
   );
}
