
// -----------------------------------------------------------------------------
// value::get<T>
// -----------------------------------------------------------------------------

// const
template<
   class T,
   class = std::enable_if_t<
      detail::invar<T,value::variant> || detail::invar<T,number::variant>
   >
>
const T &get() const
{
   if constexpr (detail::invar<T,value::variant>)
      return std::get<T>(*this);
   else
      return get<number>().get<T>();
}

// non-const
template<class T>
auto get() -> decltype(const_cast<T &>(std::as_const(*this).template get<T>()))
{
   return const_cast<T &>(std::as_const(*this).template get<T>());
}
