
// -----------------------------------------------------------------------------
// add
// +=
// -----------------------------------------------------------------------------

// add
template<
   class FROM, class D = DERIVED,
   class = std::enable_if_t<
      detail::MatchesExact <FROM,decltype(D::Keys().tup)>::count == 1 ||
      detail::MatchesViable<FROM,decltype(D::Keys().tup)>::count == 1
   >
>
DERIVED &add(const FROM &elem)
{
   // match exact? (else viable, per SFINAE requirement)
   using TUP = decltype(Keys().tup);
   const bool exact = detail::MatchesExact<FROM,TUP>::count == 1;

   // scan until match
   std::apply(
      [this,&elem,exact](const auto &... mc)
      {
         size_t n = 0; bool found = false;
         ((found || (found = detail::added(*this,elem,mc,exact,n++))), ...);
      },
      Keys().tup
   );

   // done
   return derived();
}

// +=
template<class FROM>
auto operator+=(const FROM &elem) -> decltype(add(elem))
{
   return add(elem);
}


// -----------------------------------------------------------------------------
// operator[]
// -----------------------------------------------------------------------------

// const
template<
   class EXTRACTOR, class TYPE, class CONVERTER,
   class = std::enable_if_t<!detail::is_void_v<TYPE>>,
   class D = DERIVED, class TUP = decltype(D::Keys().tup),
   class LOOK = Lookup<LookupMode::get,EXTRACTOR,TYPE,CONVERTER>,
   class = std::enable_if_t<detail::bracket<Component,LOOK,TUP>::count == 1>
>
decltype(auto)
operator[](const Lookup<LookupMode::get,EXTRACTOR,TYPE,CONVERTER> &look) const
{
   return detail::bracket<Component,LOOK,TUP>::value(*this,look);
}

// non-const
template<
   class EXTRACTOR, class TYPE, class CONVERTER,
   class = std::enable_if_t<!detail::is_void_v<TYPE>>,
   class D = DERIVED, class TUP = decltype(D::Keys().tup),
   class LOOK = Lookup<LookupMode::get,EXTRACTOR,TYPE,CONVERTER>,
   class = std::enable_if_t<detail::bracket<Component,LOOK,TUP>::count == 1>
>
decltype(auto)
operator[](const Lookup<LookupMode::get,EXTRACTOR,TYPE,CONVERTER> &look)
{
   using RETURN = typename detail::bracket<Component,LOOK,TUP>::type;
   return const_cast<RETURN &>(std::as_const(*this)[look]);
}
