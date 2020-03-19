
// -----------------------------------------------------------------------------
// Node::child(string)
//
// Searches the Node's children for a child of the given name. If found,
// returns the child node in question. Else, returns an empty Node.
// -----------------------------------------------------------------------------

const Node &child(
   const std::string &key,
   bool &found = detail::default_bool // as for meta(string)
) const {
   // search
   for (auto &c : children)
      if (c != nullptr and c->name == key)
         return found = true, *c;

   // not found
   found = false;
   static const Node empty;

   // comment as in meta(string)
   if (&found == &detail::default_bool)
      error(
         "Node child() called with key \"" + key + "\", "
         "but this key wasn't\nfound in the node's children."
      );

   // done
   return empty;
}



// -----------------------------------------------------------------------------
// Node::child(child_t<*>)
//
// Two cases of child_t<*>:
//    RESULT    General case
//    variant   With caller-specified result type
// -----------------------------------------------------------------------------

// fixme Need to split multiple to true/false for both of these...

// ------------------------
// child(child_t<RESULT>)
// ------------------------

template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN
>
auto &child(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd
) const {
   return *(const TypedNode<const Node, RESULT> *)(&child(kwd.name));
}


// ------------------------
// child(child_t<variant>)
// ------------------------

// Caller must specify the result type (not the same as return type
// of the function, which is a TypedNode with the given result type)
template<
   class RESULT, bool MULTIPLE, class METADATA, class CHILDREN, class... Ts
>
auto &child(
   const child_t<std::variant<Ts...>,MULTIPLE,METADATA,CHILDREN> &kwd
) const {
   return *(const TypedNode<const Node, RESULT> *)(&child(kwd.name));
}
