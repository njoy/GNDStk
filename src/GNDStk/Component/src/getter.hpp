
// The getter() functions of class Component get some names from the derived
// class (those are used when printing diagnostics, if applicable), and then
// call getter() functions in the detail:: namespace to do most of the work.
//
// The motivation for having the following at all is to simplify the retrieval,
// in the derived-class getters, of certain information in the content{} struct
// of the derived class object. For simple data, e.g. an int or a std::string
// in the derived class' content struct, a derived-class getter will simply
// do a "return content.something", because nothing more complicated is needed.
// So, the below functions involve circumstances where something more involved
// needs to be done. See the various remarks below for more information.


// -----------------------------------------------------------------------------
// (field, key, name)
// FIELD in this context is either a vector or an optional<vector>, and KEY
// is either an integral index or a string label. (If FIELD were just a plain
// data type, not an [optional] vector, then there would be no reason to bother
// with a getter() function for it; we'd just return content.field in the
// derived class, instead of calling getter() to do something more complicated.
// And, besides, the fact that we're looking up by index or label suggests that
// we're dealing with a vector, not something simple like an int or a string.)
// -----------------------------------------------------------------------------

// const
template<class FIELD, class KEY> // KEY: for index or label
const auto &getter(
   const FIELD &field,
   const KEY &key,
   const std::string &fieldName
) const {
   return detail::getter(
      field, key,
      DERIVED::namespaceName(), DERIVED::className(), fieldName
   );
}

// non-const
template<class FIELD, class KEY>
auto &getter(
   FIELD &field,
   const KEY &key,
   const std::string &fieldName
) {
   return detail::getter(
      field, key,
      DERIVED::namespaceName(), DERIVED::className(), fieldName
   );
}


// -----------------------------------------------------------------------------
// <RETURN>(variant, name)
// These, in contrast to the getter()s above, don't involve a vector or an
// optional vector, or an index or a label. We bother having these only because
// of the (admittedly small, in this case) extra complexity of checking that
// the variant holds the requested alternative, and of producing diagnostics
// if it doesn't.
// -----------------------------------------------------------------------------

// const
template<class RETURN, class... Ts>
const RETURN *getter(
   const std::variant<Ts...> &var,
   const std::string &fieldName
) const {
   return detail::getter<RETURN>(
      var,
      DERIVED::namespaceName(), DERIVED::className(), fieldName
   );
}

// non-const
template<class RETURN, class... Ts>
RETURN *getter(
   std::variant<Ts...> &var,
   const std::string &fieldName
) {
   return const_cast<RETURN *>(
      std::as_const(*this).template
      getter<RETURN>(std::as_const(var), fieldName)
   );
}


// -----------------------------------------------------------------------------
// <RETURN>(vector<variant>, key, name)
// The motivation for these essentially amounts to the combined motivations
// for the above two sets of getter() functions.
// -----------------------------------------------------------------------------

// const
template<class RETURN, class KEY, class... Ts>
const RETURN *getter(
   const std::vector<std::variant<Ts...>> &var,
   const KEY &key,
   const std::string &fieldName
) const {
   return detail::getter<RETURN>(
      var, key,
      DERIVED::namespaceName(), DERIVED::className(), fieldName
   );
}

// non-const
template<class RETURN, class KEY, class... Ts>
RETURN *getter(
   std::vector<std::variant<Ts...>> &var,
   const KEY &key,
   const std::string &fieldName
) const {
   return const_cast<RETURN *>(
      std::as_const(*this).template
      getter<RETURN>(std::as_const(var), key, fieldName)
   );
}
