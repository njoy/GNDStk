
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
const Node &child(
   const child_t<void,find::one> &kwd,
   bool &found = detail::default_bool
) const {
   return one(kwd.name,found);
}

// non-const
Node &child(
   const child_t<void,find::one> &kwd,
   bool &found = detail::default_bool
) {
   return one(kwd.name,found);
}



// -----------------------------------------------------------------------------
// Node::child(child_t<void,all>)
// -----------------------------------------------------------------------------

// const
template<template<class...> class CONTAINER = std::vector>
CONTAINER<Node> child(
   const child_t<void,find::all> &kwd,
   bool &found = detail::default_bool
) const {
   return all<CONTAINER>(kwd.name,found);
}



// -----------------------------------------------------------------------------
// Node::child(child_t<*,one>)
// -----------------------------------------------------------------------------

// RESULT
template<class RESULT, class CONVERTER>
RESULT child(
   const child_t<RESULT,find::one,CONVERTER> &kwd,
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
template<class RESULT, class... Ts, class CONVERTER>
typename detail::oneof<RESULT,Ts...>::type child(
   const child_t<std::variant<Ts...>,find::one,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   return child(
      child_t<RESULT,find::one,CONVERTER>(kwd.name),
      found
   );
}



// -----------------------------------------------------------------------------
// Node::child(child_t<*,all>)
// -----------------------------------------------------------------------------

// RESULT
template<
   template<class...> class CONTAINER = std::vector,
   class RESULT, class CONVERTER
>
CONTAINER<RESULT> child(
   const child_t<RESULT,find::all,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   CONTAINER<RESULT> container;
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
   class... Ts, class CONVERTER
>
CONTAINER<typename detail::oneof<RESULT,Ts...>::type> child(
   const child_t<std::variant<Ts...>,find::all,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   return child<CONTAINER>(
      child_t<RESULT,find::all,CONVERTER>(kwd.name),
      found
   );
}
