
// (field, key, name), const
template<class FIELD, class KEY> // KEY: for index or label
const auto &getter(
   const FIELD &field,
   const KEY &key,
   const std::string &name
) const {
   return detail::getter(
      field, key,
      DERIVED::namespaceName(), DERIVED::className(), name
   );
}

// (field, key, name), non-const
template<class FIELD, class KEY>
auto &getter(
   FIELD &field,
   const KEY &key,
   const std::string &name
) {
   return detail::getter(
      field, key,
      DERIVED::namespaceName(), DERIVED::className(), name
   );
}

// <RETURN>(variant, name), const
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

// <RETURN>(vector<variant>, key, name) const
template<class RETURN, class KEY, class... Ts>
auto getter(
   const std::vector<std::variant<Ts...>> &var,
   const KEY &key,
   const std::string &name
) const {
   return detail::getter<RETURN>(
      var, key,
      DERIVED::namespaceName(), DERIVED::className(), name
   );
}
