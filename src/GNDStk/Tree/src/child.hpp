
// -----------------------------------------------------------------------------
// Tree::child(child_t<*>)
// Reminder: Tree::nodeType is Node<METADATA_CONTAINER,CHILDREN_CONTAINER>
// Note: We have the find::one cases only because find::all wouldn't make sense
// for trees, which have at most one declaration node and one top-level GNDS
// node. We did in fact provide a Tree::all(string) function - for plain string
// lookup - but, with properly formulated keywords, there's just no need here.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Tree::child(child_t<void,one>)
// -----------------------------------------------------------------------------

// const
template<class METADATA, class CHILDREN>
const nodeType &child(
   const child_t<void,find::one,detail::failure_t,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return one(kwd.name,found);
}

// non-const
template<class METADATA, class CHILDREN>
nodeType &child(
   const child_t<void,find::one,detail::failure_t,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) {
   return one(kwd.name,found);
}



// -----------------------------------------------------------------------------
// Tree::child(child_t<*,one>)
// -----------------------------------------------------------------------------

// RESULT
template<
   class RESULT,
   class CONVERTER, class METADATA, class CHILDREN
>
RESULT child(
   const child_t<RESULT,find::one,CONVERTER,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      const nodeType &value = one(kwd.name,found);
      RESULT type{};
      if (found)
         kwd.converter(value,type);
      return type;
   } catch (const std::exception &) {
      log::context("Tree::child(child_t<type,find::one>(\"{}\"))", kwd.name);
      throw;
   }
}

// variant
// With caller-specified result type
template<
   class RESULT,
   class CONVERTER, class METADATA, class CHILDREN, class... Ts
>
typename detail::oneof<RESULT,Ts...>::type child(
   const child_t<std::variant<Ts...>,find::one,CONVERTER,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return child(
      child_t<RESULT,find::one,CONVERTER,METADATA,CHILDREN>(kwd.name),
      found
   );
}
