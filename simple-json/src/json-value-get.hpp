
// -----------------------------------------------------------------------------
// value::get<T>
// -----------------------------------------------------------------------------

// const
template<
   class T,
   class = std::enable_if_t<
      std::is_same_v<T,std::string> ||
      detail::invar<T,variant> ||
      detail::invar<T,number::variant>
   >
>
const T &get() const
{
   if constexpr (std::is_same_v<T,std::string>)
      return get<string>();
   else if constexpr (detail::invar<T,variant>)
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
