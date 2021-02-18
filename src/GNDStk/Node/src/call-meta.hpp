
// (Meta) const
template<class TYPE, class CONVERTER>
decltype(auto) operator()(
   const Meta<TYPE,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(kwd,found);
}

// (Meta)
template<class TYPE, class CONVERTER>
decltype(auto) operator()(
   const Meta<TYPE,CONVERTER> &kwd,
   bool &found = detail::default_bool
) {
   return meta(kwd,found);
}
