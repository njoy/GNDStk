
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
// child(child_t<void,one/many,...>[,found])
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

// ------------------------
// TYPE
// ------------------------

template<class TYPE, class CONVERTER, class FILTER>
TYPE child(
   const child_t<TYPE,allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // call one(string), with the child_t's key
      const Node &value = one(kwd.name, kwd.filter, found);
      // convert value, if any, to an object of the appropriate type
      TYPE type{};
      if (found)
         kwd.converter(value,type);
      return type;
   } catch (...) {
      log::member("Node.child(" + detail::keyname(kwd) + " with allow::one)");
      throw;
   }
}


// ------------------------
// optional<TYPE>
// ------------------------

template<class TYPE, class CONVERTER, class FILTER>
std::optional<TYPE> child(
   const child_t<std::optional<TYPE>,allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // Comments as in the meta() analog of this child() function
      bool f;
      const TYPE obj = child(TYPE{}/kwd,f);
      found = true;
      return f ? std::optional<TYPE>(obj) : std::nullopt;
   } catch (...) {
      log::member("Node.child(" + detail::keyname(kwd) + " with allow::one)");
      throw;
   }
}


// ------------------------
// variant
// ------------------------

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

// ------------------------
// TYPE
// ------------------------

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
               // convert *c to an object of the appropriate type
               TYPE type{};
               kwd.converter(*c,type);
               container.push_back(type);
               found = true;
            }
         }
      }
   } catch (...) {
      log::member("Node.child(" + detail::keyname(kwd) + " with allow::many)");
      throw;
   }

   // done
   return container;
}


// ------------------------
// optional<TYPE>
// ------------------------

// fixme Be sure this is the meaning we want...
//
// With an allow::many child_t, as we have here, it's permissible (without
// an exception being thrown) to extract any number of values - including
// zero - into the container. In some sense, then, the allow::many means
// it's *optional* to have any matching values at all. So the question is:
// how should we handle child_t<std::optional<TYPE>,allow::many>, with two
// different "optional" aspects being involved? We'll do this:
//
//    A container<TYPE>, *not* a container<optional<TYPE>>, is produced,
//    even though it's a child_t<optional<TYPE>>. (If we had a container
//    of optionals, then when, and from where, would any nullopt values
//    arise? We're filling the container with what we do find, in which
//    case there'd be no real meaning associated any nullopt values.)
//
//    Consistent with the behavior of std::optional elsewhere in GNDStk's
//    queries, we'll *always* return from here with found == true. That's
//    already the case with allow::many if container.size() > 0 on output,
//    but now we'll unconditionally return found == true, even for 0 size.
//
// We may change this, if doing something else proves to make more sense,
// or to be more useful. It's possible, for example, that for the sake of
// consistency we should always return objects that involve precisely the
// type that's given in the child_t, even in cases like this in which such
// a modification seems to be sensible from a practical standpoint.

template<
   template<class...> class CONTAINER = std::vector,
   class TYPE, class CONVERTER, class FILTER
>
CONTAINER<TYPE> child(
   const child_t<std::optional<TYPE>,allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // The behavior described above makes this easy as well.
      // That wasn't our intention, but we don't mind too much.
      return found = true, child(TYPE{}/kwd);
   } catch (...) {
      log::member("Node.child(" + detail::keyname(kwd) + " with allow::many)");
      throw;
   }
}


// ------------------------
// variant
// ------------------------

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
