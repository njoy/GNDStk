
// -----------------------------------------------------------------------------
// Node::child(string)
//
// Searches the node's children for a child of the given name. If found,
// returns the child node in question. Else, returns an empty node.
// -----------------------------------------------------------------------------

// Important note: These return only the *first* instance, if any, of the
// child node in question. I may reformulate them, or provide different
// functions to find all instances. But see the child(child_t) formulations
// below (in contrast to these child(string) formulations).

// const
const Node &child(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   debug(detail::nc07);

   // ""
   if (key == "")
      return found = true, *this;

   // search
   for (auto &c : children)
      if (c != nullptr and c->name == key)
         return found = true, *c;

   // not found
   found = false;
   static Node empty;
   empty.clear();

   // comment as in meta(string)
   if (&found == &detail::default_bool)
      error(
         "Node child() called with key \"" + key + "\", "
         "but this key wasn't\nfound in the node's children."
      );

   // done
   return empty;
}


// non-const
Node &child(
   const std::string &key,
   bool &found = detail::default_bool
) {
   debug(detail::nc08);
   return const_cast<Node &>(std::as_const(*this).child(key,found));
}



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
// Non-const versions aren't needed for these, because the const versions
// return by value.
// -----------------------------------------------------------------------------

// ------------------------
// find::one
// ------------------------

// child(child_t<RESULT>)
template<class RESULT, class METADATA, class CHILDREN>
RESULT child(
   const child_t<RESULT,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   debug(detail::nc09);

   // call child(string) above, with the child_t's key
   const Node &n = child(kwd.name,found);

   // convert value, if any, to the appropriate result type
   RESULT type{};
   if (found)
      node2type(n,type);
   return type;
}


// child(child_t<void>)
template<class METADATA, class CHILDREN>
Node child(
   const child_t<void,find::one,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   debug(detail::nc10);
   return child(kwd.name,found).copy();
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
   debug(detail::nc11);
   return child(child_t<RESULT,find::one,METADATA,CHILDREN>(kwd.name),found);
}



// ------------------------
// find::all
// ------------------------

// child(child_t<RESULT>)
template<
   template<class ...> class CONTAINER = std::vector,
   class RESULT, class METADATA, class CHILDREN
>
CONTAINER<RESULT,std::allocator<RESULT>> child(
   const child_t<RESULT,find::all,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   debug(detail::nc12);

   // container
   CONTAINER<RESULT,std::allocator<RESULT>> container;

   // search
   for (auto &c : children)
      if (c != nullptr and c->name == kwd.name) {
         RESULT type{};
         node2type(*c,type);
         container.push_back(type);
      }
   found = container.size() > 0;

   // For now, I'm commenting out the following. We may or may not wish to
   // produce an error if no child of the given name was found. If no such
   // child was found, after all, then (in addition to the "found" flag being
   // set to reflect this), the returned container will have size 0, meaning
   // precisely that no such children were found. That's a perfectly valid
   // state of affairs. On the other hand, I like to make similar functions
   // have roughly similar behavior, to the extent that doing so doesn't seem
   // forced. The meta() lookup functions produce *errors* if something isn't
   // found at all. It would make perfect sense to do the same here, with the
   // child() function, even if a size == 0 returned container communicates
   // the same information.
   /*
   if (!found && &found == &detail::default_bool) {
      error(
         "Node child() called with key \"" + kwd.name + "\", "
         "but this key wasn't\nfound in the node's children."
      );
   */

   return container;
}


// child(child_t<void>)
template<
   template<class ...> class CONTAINER = std::vector,
   class METADATA, class CHILDREN
>
CONTAINER<Node,std::allocator<Node>> child(
   const child_t<void,find::all,METADATA,CHILDREN> &kwd,
   bool &found = detail::default_bool
) const {
   debug(detail::nc13);

   CONTAINER<Node,std::allocator<Node>> container;

   for (auto &c : children)
      if (c != nullptr and c->name == kwd.name)
         container.push_back(c->copy());

   found = container.size() > 0;
   return container;
}


// child(child_t<variant>)
// With caller-specified result type
template<
   class RESULT,
   template<class ...> class CONTAINER = std::vector,
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
   debug(detail::nc14);
   return child(child_t<RESULT,find::all,METADATA,CHILDREN>(kwd.name),found);
}
