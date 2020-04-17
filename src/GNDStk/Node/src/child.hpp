
// -----------------------------------------------------------------------------
// Node::child(child_t<*>)
//
// Cases:
//
//    RESULT    General case
//    variant   With caller-specified result type
//
// Each of those is split into two further cases, depending on the FIND
// template parameter in the child_t:
//
//    FIND == find::one
//       The child_t encodes the notion that we're only supposed to find
//       one child node of this name. (Independent of the fact that many
//       child nodes of the same name are allowed in, e.g., XML.) In these
//       cases, the child() functions below return single values.
//
//    FIND == find::all
//       The child_t encodes the notion that any number of child nodes of
//       this name can occur. In these cases, the child() functions below
//       return containers of values.
//
// Non-const versions aren't needed for most of these.
// -----------------------------------------------------------------------------

// ------------------------
// find::one
// ------------------------

// child(child_t<RESULT>) const
template<class RESULT, class METADATA, class CHILDREN>
RESULT child(
   const child_t<RESULT,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   // call one(string), with the child_t's key
   const Node &n = one(kwd.name,found);

   // convert value, if any, to the appropriate result type
   RESULT type{};
   if (found)
      node2type(n,type);
   return type;
}


// child(child_t<void>) const
template<class METADATA, class CHILDREN>
const Node &child(
   const child_t<void,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return one(kwd.name,found);
}


// child(child_t<void>) non-const
template<class METADATA, class CHILDREN>
Node &child(
   const child_t<void,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) {
   return one(kwd.name,found);
}


// child(child_t<variant>) const
// With caller-specified result type
template<class RESULT, class METADATA, class CHILDREN, class... Ts>
typename std::enable_if<
   detail::is_oneof<RESULT,Ts...>::value,
   RESULT
>::type child(
   const child_t<std::variant<Ts...>,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return child(child_t<RESULT,find::one,METADATA,CHILDREN>(kwd.name),found);
}



// ------------------------
// find::all
// ------------------------

// child(child_t<RESULT>) const
template<
   template<class...> class CONTAINER = std::vector,
   class RESULT, class METADATA, class CHILDREN
>
CONTAINER<RESULT,std::allocator<RESULT>> child(
   const child_t<RESULT,find::all,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   // container
   CONTAINER<RESULT,std::allocator<RESULT>> container;

   // search
   for (auto &c : children)
      if (c != nullptr and c->name == kwd.name) {
         RESULT type{};
         node2type(*c,type);
         container.push_back(type);
      }

   // done
   found = container.size() > 0;
   return container;
}


// child(child_t<void>) const
template<
   template<class...> class CONTAINER = std::vector,
   class METADATA, class CHILDREN
>
CONTAINER<Node,std::allocator<Node>> child(
   const child_t<void,find::all,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return all<CONTAINER>(kwd.name,found);
}


// child(child_t<variant>) const
// With caller-specified result type
template<
   class RESULT,
   template<class...> class CONTAINER = std::vector,
   class METADATA, class CHILDREN, class... Ts
>
CONTAINER<
   typename std::enable_if<
      detail::is_oneof<RESULT,Ts...>::value,
      RESULT
   >::type ,
   std::allocator<
      typename std::enable_if<
         detail::is_oneof<RESULT,Ts...>::value,
         RESULT
      >::type
   >
> child(
   const child_t<std::variant<Ts...>,find::all,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return child<CONTAINER>(
      child_t<RESULT,find::all,METADATA,CHILDREN>(kwd.name),
      found
   );
}
