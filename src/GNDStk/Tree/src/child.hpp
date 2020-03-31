
// Reminder: Tree::nodeType is Node<METADATA_CONTAINER,CHILDREN_CONTAINER>

// -----------------------------------------------------------------------------
// Tree::child(string)
// -----------------------------------------------------------------------------

// const
const nodeType &child(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // if tree is empty, but a "found" flag wasn't sent
   if (empty() and &found == &detail::default_bool) {
      // fixme need a real error
      assert(false);
   }
   return decl().name == key ? (found = true, decl()) : decl().child(key,found);
}


// non-const
nodeType &child(
   const std::string &key,
   bool &found = detail::default_bool
) {
   return const_cast<nodeType &>(std::as_const(*this).child(key,found));
}



// -----------------------------------------------------------------------------
// Tree::child(child_t<*>)
// -----------------------------------------------------------------------------

// ------------------------
// MULTIPLE == false
// Because true wouldn't
// make sense for trees;
// one declaration + one
// top-level GNDS node
// ------------------------

// child(child_t<RESULT>)
template<class RESULT, class METADATA, class CHILDREN>
RESULT child(
   const child_t<RESULT,false,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   const nodeType &n = child(kwd.name,found);
   RESULT type{};
   if (found)
      node2type(n,type);
   return type;
}


// child(child_t<void>)
template<class METADATA, class CHILDREN>
nodeType child(
   const child_t<void,false,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return child(kwd.name,found).copy();
}


// child(child_t<variant>)
// With caller-specified result type
template<class RESULT, class METADATA, class CHILDREN, class... Ts>
typename std::enable_if<
   detail::is_oneof<RESULT,Ts...>::value,
   RESULT
>::type child(
   const child_t<std::variant<Ts...>,false,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return child(child_t<RESULT,false,METADATA,CHILDREN>(kwd.name),found);
}
