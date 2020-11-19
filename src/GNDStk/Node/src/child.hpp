
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

// Terminology in the code below:
//
//    FILT filt
//       Filter that's sent as a parameter
//
//    FILTER
//       Filter that's part of the child_t
//
// Be careful not to confuse the two!


// -----------------------------------------------------------------------------
// child(child_t<void,one|many,...>, filter parameter [,found])
// -----------------------------------------------------------------------------

// one, const
template<class FILTER, class FILT>
const Node &child(
   const child_t<void,allow::one,void,FILTER> &kwd,
   const FILT &filt,
   bool &found = detail::default_bool
) const {
   auto filter = [kwd,filt](const Node &n) { return kwd.filter(n) && filt(n); };
   return one(kwd.name, filter, found);
}

// one, non-const
template<class FILTER, class FILT>
Node &child(
   const child_t<void,allow::one,void,FILTER> &kwd,
   const FILT &filt,
   bool &found = detail::default_bool
) {
   auto filter = [kwd,filt](const Node &n) { return kwd.filter(n) && filt(n); };
   return one(kwd.name, filter, found);
}

// many, const
template<
   template<class...> class CONTAINER = std::vector,
   class FILTER, class FILT
>
CONTAINER<Node> child(
   const child_t<void,allow::many,void,FILTER> &kwd,
   const FILT &filt,
   bool &found = detail::default_bool
) const {
   auto filter = [kwd,filt](const Node &n) { return kwd.filter(n) && filt(n); };
   return many<CONTAINER>(kwd.name, filter, found);
}



// -----------------------------------------------------------------------------
// child(child_t<TYPE,one,...>, filter parameter [,found])
// -----------------------------------------------------------------------------

// TYPE
template<class TYPE, class CONVERTER, class FILTER, class FILT>
TYPE child(
   const child_t<TYPE,allow::one,CONVERTER,FILTER> &kwd,
   const FILT &filt,
   bool &found = detail::default_bool
) const {
   try {
      // call one(string), with the child_t's key
      auto filter = [kwd,filt](const Node &n)
         { return kwd.filter(n) && filt(n); };
      const Node &value = one(kwd.name, filter, found);
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
template<class TYPE, class... Ts, class CONVERTER, class FILTER, class FILT>
typename detail::oneof<TYPE,Ts...>::type child(
   const child_t<std::variant<Ts...>,allow::one,CONVERTER,FILTER> &kwd,
   const FILT &filt,
   bool &found = detail::default_bool
) const {
   return child(TYPE{}/kwd, filt, found);
}



// -----------------------------------------------------------------------------
// child(child_t<TYPE,many>,filter[,found])
// -----------------------------------------------------------------------------

// TYPE
template<
   template<class...> class CONTAINER = std::vector,
   class TYPE, class CONVERTER, class FILTER, class FILT
>
CONTAINER<TYPE> child(
   const child_t<TYPE,allow::many,CONVERTER,FILTER> &kwd,
   const FILT &filt,
   bool &found = detail::default_bool
) const {
   // container
   CONTAINER<TYPE> container;
   found = false;

   try {
      // ""
      // meaning: return a container with the converted-to-TYPE current node
      if (kwd.name == "") {
         // filter parameter is ignored in this case
         TYPE type{};
         kwd.converter(*this,type);
         container.push_back(type);
         found = true;
      } else {
         // search in the current node's children
         auto filter = [kwd,filt](const Node &n)
            { return kwd.filter(n) && filt(n); };
         for (auto &c : children) {
            if (std::regex_match(c->name, std::regex(kwd.name)) && filter(*c)) {
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
   class... Ts, class CONVERTER, class FILTER, class FILT
>
CONTAINER<typename detail::oneof<TYPE,Ts...>::type> child(
   const child_t<std::variant<Ts...>,allow::many,CONVERTER,FILTER> &kwd,
   const FILT &filt,
   bool &found = detail::default_bool
) const {
   return child<CONTAINER>(TYPE{}/kwd, filt, found);
}



// -----------------------------------------------------------------------------
// All of the above except with no filt[er] parameters.
// But: the child_t parameters can still have their own filters.
// -----------------------------------------------------------------------------

// ------------------------
// child_t<void>
// ------------------------

// one, const
template<class FILTER>
const Node &child(
   const child_t<void,allow::one,void,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return child(kwd, detail::noFilter{}, found);
}

// one, non-const
template<class FILTER>
Node &child(
   const child_t<void,allow::one,void,FILTER> &kwd,
   bool &found = detail::default_bool
) {
   return child(kwd, detail::noFilter{}, found);
}

// many, const
template<template<class...> class CONTAINER = std::vector, class FILTER>
CONTAINER<Node> child(
   const child_t<void,allow::many,void,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return child<CONTAINER>(kwd, detail::noFilter{}, found);
}


// ------------------------
// child_t<TYPE>
// ------------------------

template<class TYPE, class CONVERTER, class FILTER>
TYPE child(
   const child_t<TYPE,allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return child(kwd, detail::noFilter{}, found);
}

template<class TYPE, class... Ts, class CONVERTER, class FILTER>
typename detail::oneof<TYPE,Ts...>::type child(
   const child_t<std::variant<Ts...>,allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return child<TYPE>(kwd, detail::noFilter{}, found);
}

template<
   template<class...> class CONTAINER = std::vector,
   class TYPE, class CONVERTER, class FILTER
>
CONTAINER<TYPE> child(
   const child_t<TYPE,allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return child<CONTAINER>(kwd, detail::noFilter{}, found);
}

template<
   class TYPE,
   template<class...> class CONTAINER = std::vector,
   class... Ts, class CONVERTER, class FILTER
>
CONTAINER<typename detail::oneof<TYPE,Ts...>::type> child(
   const child_t<std::variant<Ts...>,allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return child<TYPE,CONTAINER>(kwd, detail::noFilter{}, found);
}
