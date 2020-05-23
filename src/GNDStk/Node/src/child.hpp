
// -----------------------------------------------------------------------------
// Node::child(child_t<*>)
//
// FIND == find::one
// The child_t encodes the notion that we're only supposed to find one child
// node of this name. (Independent of the fact that many child nodes of the
// same name are allowed in, e.g., XML.) In these cases the child() functions
// return single values.
//
// FIND == find::all
// The child_t encodes the notion that any number of child nodes of this name
// can occur. In these cases the child() functions return containers of values.
//
// Non-const versions aren't needed for most, as they return by value.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Node::child(child_t<void,one>)
// -----------------------------------------------------------------------------

// const
template<class METADATA, class CHILDREN>
const Node &child(
   const child_t<void,find::one,detail::failure_t,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return one(kwd.name,found);
}

// non-const
template<class METADATA, class CHILDREN>
Node &child(
   const child_t<void,find::one,detail::failure_t,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) {
   return one(kwd.name,found);
}



// -----------------------------------------------------------------------------
// Node::child(child_t<void,all>)
// -----------------------------------------------------------------------------

// const
template<
   template<class...> class CONTAINER = std::vector,
   class METADATA, class CHILDREN
>
CONTAINER<Node,std::allocator<Node>> child(
   const child_t<void,find::all,detail::failure_t,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return all<CONTAINER>(kwd.name,found);
}



// -----------------------------------------------------------------------------
// Node::child(child_t<*,one>)
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
      // call one(string), with the child_t's key
      const Node &value = one(kwd.name,found);
      // convert value, if any, to the appropriate result type
      RESULT type{};
      if (found)
         kwd.converter(value,type);
      return type;
   } catch (const std::exception &) {
      log::context("Node::child(child_t<type,find::one>(\"{}\"))", kwd.name);
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



// -----------------------------------------------------------------------------
// Node::child(child_t<*,all>)
// -----------------------------------------------------------------------------

// RESULT
template<
   template<class...> class CONTAINER = std::vector,
   class RESULT,
   class CONVERTER, class METADATA, class CHILDREN
>
CONTAINER<RESULT,std::allocator<RESULT>> child(
   const child_t<RESULT,find::all,CONVERTER,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   CONTAINER<RESULT,std::allocator<RESULT>> container;
   found = false;

   try {
      // search
      for (auto &value : children)
         if (value->name == kwd.name) {
            found = true;
            // convert value to the appropriate result type
            RESULT type{};
            kwd.converter(*value,type);
            container.push_back(type);
         }
      return container;
   } catch (const std::exception &) {
      log::context("Node::child(child_t<type,find::all>(\"{}\"))", kwd.name);
      throw;
   }
}

// variant
// With caller-specified result type
template<
   class RESULT,
   template<class...> class CONTAINER = std::vector,
   class CONVERTER, class METADATA, class CHILDREN, class... Ts
>
CONTAINER<
   typename detail::oneof<RESULT,Ts...>::type,
   std::allocator<typename detail::oneof<RESULT,Ts...>::type>
> child(
   const child_t<std::variant<Ts...>,find::all,CONVERTER,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   return child<CONTAINER>(
      child_t<RESULT,find::all,CONVERTER,METADATA,CHILDREN>(kwd.name),
      found
   );
}
