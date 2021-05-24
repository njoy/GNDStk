
template<class FIELD, class T> // T: for n or label
const auto &getter(
   const FIELD &field,
   const T &value,
   const std::string &name
) const {
   return detail::getter(
      field, value,
      DERIVED::namespaceName(), DERIVED::className(), name
   );
}

template<class FIELD, class T>
auto &getter(
   FIELD &field,
   const T &value,
   const std::string &name
) {
   return detail::getter(
      field, value,
      DERIVED::namespaceName(), DERIVED::className(), name
   );
}

template<class RETURN, class... Ts>
auto getter(
   const std::variant<Ts...> &var,
   const std::string &name
) const {
   return detail::getter<RETURN>(
      var,
      DERIVED::namespaceName(), DERIVED::className(), name
   );
}

template<class RETURN, class T, class... Ts>
auto getter(
   const std::vector<std::variant<Ts...>> &var,
   const T &value,
   const std::string &name
) const {
   return detail::getter<RETURN>(
      var, value,
      DERIVED::namespaceName(), DERIVED::className(), name
   );
}
