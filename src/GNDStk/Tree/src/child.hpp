
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

// child(child_t<RESULT>) const
template<class RESULT, class METADATA, class CHILDREN>
RESULT child(
   const child_t<RESULT,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      const nodeType &n = one(kwd.name,found);
      RESULT type{};
      if (found)
         node2type(n,type);
      return type;
   } catch (const std::exception &) {
      log::context("Tree::child(child_t<type,find::one>(\"{}\"))", kwd.name);
      throw;
   }
}

// child(child_t<void>) const
template<class METADATA, class CHILDREN>
const nodeType &child(
   const child_t<void,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return one(kwd.name,found);
}

// child(child_t<void>) non-const
template<class METADATA, class CHILDREN>
nodeType &child(
   const child_t<void,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) {
   return one(kwd.name,found);
}

// child(child_t<variant>) const
// With caller-specified result type
template<class RESULT, class METADATA, class CHILDREN, class... Ts>
typename detail::oneof<RESULT,Ts...>::type child(
   const child_t<std::variant<Ts...>,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return child(child_t<RESULT,find::one,METADATA,CHILDREN>(kwd.name),found);
}
