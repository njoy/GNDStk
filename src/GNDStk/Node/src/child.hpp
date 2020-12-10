
// -----------------------------------------------------------------------------
// Node.child(child_t<*>)
//
// ALLOW == allow::one
// The child_t encodes the notion that we're only supposed to have one child
// node of this name. (Independent of the fact that many child nodes of the
// same name are allowed in, e.g., XML.) In these cases the child() functions
// return single values.
//
// ALLOW == allow::many
// The child_t encodes the notion that any number of child nodes of this name
// can occur. In these cases the child() functions return containers of values.
//
// Non-const versions aren't needed for most, as they return by value.
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// child(child_t<void,one|many,...>[,found])
// -----------------------------------------------------------------------------

// one, const
template<class FILTER>
const Node &child(
   const child_t<void,allow::one,void,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return one(kwd.name, kwd.filter, found);
}

// one, non-const
template<class FILTER>
Node &child(
   const child_t<void,allow::one,void,FILTER> &kwd,
   bool &found = detail::default_bool
) {
   return one(kwd.name, kwd.filter, found);
}

// many, const
template<
   template<class...> class CONTAINER = std::vector,
   class FILTER
>
CONTAINER<Node> child(
   const child_t<void,allow::many,void,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return many<CONTAINER>(kwd.name, kwd.filter, found);
}


// -----------------------------------------------------------------------------
// child(child_t<TYPE,one,...>[,found])
// -----------------------------------------------------------------------------

// TYPE
template<class TYPE, class CONVERTER, class FILTER>
TYPE child(
   const child_t<TYPE,allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // call one(string), with the child_t's key
      const Node &value = one(kwd.name, kwd.filter, found);
      // convert value, if any, to the appropriate type
      TYPE type{};
      if (found)
         kwd.converter(value,type);
      return type;
   } catch (...) {
      log::member("Node.child(child_t<type,allow::one>(\"{}\"))", kwd.name);
      throw;
   }
}

// variant
// With caller-specified type
template<class TYPE, class... Ts, class CONVERTER, class FILTER>
typename detail::oneof<TYPE,std::variant<Ts...>>::type child(
   const child_t<std::variant<Ts...>,allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return child(TYPE{}/kwd, found);
}


// -----------------------------------------------------------------------------
// child(child_t<TYPE,many>[,found])
// -----------------------------------------------------------------------------

// TYPE
template<
   template<class...> class CONTAINER = std::vector,
   class TYPE, class CONVERTER, class FILTER
>
CONTAINER<TYPE> child(
   const child_t<TYPE,allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   // container
   CONTAINER<TYPE> container;
   found = false;

   try {
      // ""
      // meaning: return a container with the converted-to-TYPE current node
      if (kwd.name == "") {
         TYPE type{};
         kwd.converter(*this,type);
         container.push_back(type);
         found = true;
      } else {
         // search in the current node's children
         for (auto &c : children) {
            if (std::regex_match(c->name, std::regex(kwd.name)) &&
                kwd.filter(*c)
            ) {
               // convert c to the appropriate type
               TYPE type{};
               kwd.converter(*c,type);
               container.push_back(type);
               found = true;
            }
         }
      }
   } catch (...) {
      log::member("Node.child(child_t<type,allow::many>(\"{}\"))", kwd.name);
      throw;
   }

   // done
   return container;
}

// variant
// With caller-specified type
template<
   class TYPE,
   template<class...> class CONTAINER = std::vector,
   class... Ts, class CONVERTER, class FILTER
>
CONTAINER<typename detail::oneof<TYPE,std::variant<Ts...>>::type> child(
   const child_t<std::variant<Ts...>,allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return child<CONTAINER>(TYPE{}/kwd, found);
}
