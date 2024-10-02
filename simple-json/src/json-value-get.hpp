
// -----------------------------------------------------------------------------
// value::get<T>
// -----------------------------------------------------------------------------

// const
template<
   class T,
   class = require<allowed<T,variant> || allowed<T,number::variant>>
>
const T &get() const
{
   if constexpr (allowed<T,variant>)
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
