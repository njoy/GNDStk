
// (meta_t) const
template<class TYPE, class CONVERTER>
decltype(auto) operator()(
   const meta_t<TYPE,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(kwd,found);
}

// (meta_t)
template<class TYPE, class CONVERTER>
decltype(auto) operator()(
   const meta_t<TYPE,CONVERTER> &kwd,
   bool &found = detail::default_bool
) {
   return meta(kwd,found);
}
