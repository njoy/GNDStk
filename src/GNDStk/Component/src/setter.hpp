
// (vector<variant>, key, from, name)
template<
   class KEY,
   class T,
   class... Ts,
   class = typename std::enable_if<
      detail::is_oneof<T,std::variant<Ts...>>::value &&
     !detail::isVariant<T>::value // else is_oneof<the variant> passes
   >::type
>
void setter(
   std::vector<std::variant<Ts...>> &vector,
   const KEY &key,
   const std::optional<T> &opt,
   const std::string &name
) {
   detail::setter(
      vector, key, opt,
      DERIVED::namespaceName(), DERIVED::className(), name
   );
}
