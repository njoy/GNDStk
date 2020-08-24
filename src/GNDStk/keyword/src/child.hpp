
// -----------------------------------------------------------------------------
// keyword_t::child()
// -----------------------------------------------------------------------------

// child[<[void[,FIND]]>](name[,top])
template<
   class TYPE = void,
   find  FIND = find::one
>
static child_t<
   typename detail::isVoid<TYPE>::type,
   FIND
> child(
   const std::string &name,
   const bool top = false
) {
   return child_t<void,FIND>{name,top};
}


// child<TYPE[,FIND[,CONVERTER]]>(name[,top[,converter]])
template<
   class TYPE,
   find  FIND = find::one,
   class CONVERTER = detail::convert_t
>
static child_t<
   typename detail::isNotVoid<TYPE>::type,
   FIND, CONVERTER
> child(
   const std::string &name,
   const bool top = false,
   const CONVERTER &converter = CONVERTER{}
) {
   return child_t<TYPE,FIND,CONVERTER>{name,top,converter};
}


// child<TYPE[,FIND[,CONVERTER]]>(name,converter[,top])
template<
   class TYPE,
   find  FIND = find::one,
   class CONVERTER = detail::convert_t
>
static child_t<
   typename detail::isNotVoid<TYPE>::type,
   FIND, CONVERTER
> child(
   const std::string &name,
   const CONVERTER &converter,
   const bool top = false
) {
   return child_t<TYPE,FIND,CONVERTER>{name,top,converter};
}
