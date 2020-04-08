
// -----------------------------------------------------------------------------
// Tree::child(child_t<*>)
// Reminder: Tree::nodeType is Node<METADATA_CONTAINER,CHILDREN_CONTAINER>
// -----------------------------------------------------------------------------

// ------------------------
// find::one
// ------------------------

// Note: We have the find::one case only, because find::all wouldn't make sense
// for trees, which have at most one declaration node and one top-level GNDS
// node. We did in fact provide a Tree::all(string) function - for plain string
// lookup - but, with properly formulated keywords, there's just no need here.


// child(child_t<RESULT>)
template<class RESULT, class METADATA, class CHILDREN>
RESULT child(
   const child_t<RESULT,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   debug(detail::tc27);
   const nodeType &n = one(kwd.name,found);
   RESULT type{};
   if (found)
      node2type(n,type);
   return type;
}


// child(child_t<void>)
template<class METADATA, class CHILDREN>
nodeType child(
   const child_t<void,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   debug(detail::tc28);
   return one(kwd.name,found).copy();
}


// child(child_t<variant>)
// With caller-specified result type
template<class RESULT, class METADATA, class CHILDREN, class... Ts>
typename std::enable_if<
   detail::is_oneof<RESULT,Ts...>::value,
   RESULT
>::type child(
   const child_t<std::variant<Ts...>,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   debug(detail::tc29);
   return child(child_t<RESULT,find::one,METADATA,CHILDREN>(kwd.name),found);
}
