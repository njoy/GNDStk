
// -----------------------------------------------------------------------------
// keyword_t.child()
// -----------------------------------------------------------------------------

// fixme Allow these to accept filter


// child[<[void[,ALLOW]]>](name[,top])
template<
   class TYPE = void,
   allow ALLOW = allow::one
>
static child_t<
   typename detail::isVoid<TYPE>::type,
   ALLOW
> child(
   const std::string &name,
   const bool top = false
) {
   return child_t<void,ALLOW>{name,top};
}


// child<TYPE[,ALLOW[,CONVERTER]]>(name[,top[,converter]])
template<
   class TYPE,
   allow ALLOW = allow::one,
   class CONVERTER = detail::convert_t
>
static child_t<
   typename detail::isNotVoid<TYPE>::type,
   ALLOW, CONVERTER
> child(
   const std::string &name,
   const bool top = false,
   const CONVERTER &converter = CONVERTER{}
) {
   return child_t<TYPE,ALLOW,CONVERTER>{name,top,converter};
}


// child<TYPE[,ALLOW[,CONVERTER]]>(name,converter[,top])
template<
   class TYPE,
   allow ALLOW = allow::one,
   class CONVERTER = detail::convert_t
>
static child_t<
   typename detail::isNotVoid<TYPE>::type,
   ALLOW, CONVERTER
> child(
   const std::string &name,
   const CONVERTER &converter,
   const bool top = false
) {
   return child_t<TYPE,ALLOW,CONVERTER>{name,top,converter};
}
