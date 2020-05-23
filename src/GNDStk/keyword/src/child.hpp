
// -----------------------------------------------------------------------------
// keyword_t::child()
// -----------------------------------------------------------------------------

// child[<[void[,FIND]]>](name[,top])
template<
   class RESULT = void,
   find  FIND = find::one
>
static child_t<
   typename detail::isVoid<RESULT>::type,
   FIND, detail::failure_t
> child(
   const std::string &name,
   const bool top = false
) {
   return child_t<void,FIND,detail::failure_t>{name,top};
}


// child<RESULT[,FIND[,CONVERTER]]>(name[,top[,converter]])
template<
   class RESULT,
   find  FIND = find::one,
   class CONVERTER = detail::convert_t
>
static child_t<
   typename detail::isNotVoid<RESULT>::type,
   FIND, CONVERTER
> child(
   const std::string &name,
   const bool top = false,
   const CONVERTER &converter = CONVERTER{}
) {
   return child_t<RESULT,FIND,CONVERTER>{name,top,converter};
}


// child<RESULT[,FIND[,CONVERTER]]>(name,converter[,top])
template<
   class RESULT,
   find  FIND = find::one,
   class CONVERTER = detail::convert_t
>
static child_t<
   typename detail::isNotVoid<RESULT>::type,
   FIND, CONVERTER
> child(
   const std::string &name,
   const CONVERTER &converter,
   const bool top = false
) {
   return child_t<RESULT,FIND,CONVERTER>{name,top,converter};
}
