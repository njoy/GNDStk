
// -----------------------------------------------------------------------------
// Node.child(Child<*>)
//
// ALLOW == Allow::one
// The Child encodes the notion that we're only supposed to have one child
// node of this name. (Independent of the fact that many child nodes of the
// same name are allowed in, e.g., XML.) In these cases the child() functions
// return single values.
//
// ALLOW == Allow::many
// The Child encodes the notion that any number of child nodes of this name
// can occur. In these cases the child() functions return containers of values.
//
// Non-const versions aren't needed for most, as they return by value.
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// child(Child<void,one/many,...>[,found])
// -----------------------------------------------------------------------------

// one, const
template<class FILTER>
const Node &child(
   const Child<void,Allow::one,void,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return one(kwd.name, kwd.filter, found);
}

// one, non-const
template<class FILTER>
Node &child(
   const Child<void,Allow::one,void,FILTER> &kwd,
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
   const Child<void,Allow::many,void,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return many<CONTAINER>(kwd.name, kwd.filter, found);
}


// -----------------------------------------------------------------------------
// child(Child<TYPE,one,...>[,found])
// -----------------------------------------------------------------------------

// ------------------------
// TYPE
// ------------------------

template<class TYPE, class CONVERTER, class FILTER>
TYPE child(
   const Child<TYPE,Allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // call one(string), with the Child's key
      const Node &value = one(kwd.name, kwd.filter, found);
      // convert value, if any, to an object of the appropriate type
      TYPE obj = kwd.object;
      if (found)
         kwd.converter(value,obj);
      return obj;
   } catch (...) {
      log::member("Node.child(" + detail::keyname(kwd) + " with Allow::one)");
      throw;
   }
}


// ------------------------
// optional<TYPE>
// ------------------------

template<class TYPE, class CONVERTER, class FILTER>
std::optional<TYPE> child(
   const Child<std::optional<TYPE>,Allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // Comments as in the meta() analog of this child() function
      bool f;
      const TYPE obj = child((kwd.object ? kwd.object.value() : TYPE{})/kwd, f);
      found = true;
      return f ? std::optional<TYPE>(obj) : std::nullopt;
   } catch (...) {
      log::member("Node.child(" + detail::keyname(kwd) + " with Allow::one)");
      throw;
   }
}


// ------------------------
// Defaulted<TYPE>
// ------------------------

template<class TYPE, class CONVERTER, class FILTER>
Defaulted<TYPE> child(
   const Child<Defaulted<TYPE>,Allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      bool f;
      const TYPE obj = child(kwd.object.value()/kwd, f);
      found = true;
      return f
         ? Defaulted<TYPE>(kwd.object.get_default(),obj)
         : Defaulted<TYPE>(kwd.object.get_default());
   } catch (...) {
      log::member("Node.child(" + detail::keyname(kwd) + " with Allow::one)");
      throw;
   }
}


// ------------------------
// variant
// ------------------------

// With caller-specified type
template<class TYPE, class... Ts, class CONVERTER, class FILTER>
typename detail::oneof<TYPE,std::variant<Ts...>>::type child(
   const Child<std::variant<Ts...>,Allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   const auto ptr = std::get_if<TYPE>(&kwd.object);
   return child((ptr ? *ptr : TYPE{})/kwd, found);
}


// -----------------------------------------------------------------------------
// child(Child<TYPE,many>[,found])
// -----------------------------------------------------------------------------

// ------------------------
// TYPE
// ------------------------

template<
   template<class...> class CONTAINER = std::vector,
   class TYPE, class CONVERTER, class FILTER
>
CONTAINER<TYPE> child(
   const Child<TYPE,Allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   // container
   CONTAINER<TYPE> container;
   found = false;

   try {
      // ""
      // meaning: return a container with the converted-to-TYPE current Node
      if (kwd.name == "") {
         TYPE obj = kwd.object;
         kwd.converter(*this,obj);
         container.push_back(obj);
         found = true;
      } else {
         // search in the current Node's children
         for (auto &c : children) {
            if (std::regex_match(c->name, std::regex(kwd.name))
                && kwd.filter(*c)
            ) {
               // convert *c to an object of the appropriate type
               TYPE obj = kwd.object;
               kwd.converter(*c,obj);
               container.push_back(obj);
               found = true;
            }
         }
      }
   } catch (...) {
      log::member("Node.child(" + detail::keyname(kwd) + " with Allow::many)");
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
// With an Allow::many Child, as we have here, it's permissible (without
// an exception being thrown) to extract any number of values - including
// zero - into the container. In some sense, then, the Allow::many means
// it's *optional* to have any matching values at all. So the question is:
// how should we handle Child<std::optional<TYPE>,Allow::many>, with two
// different "optional" aspects being involved? We'll do this:
//
//    A container<TYPE>, *not* a container<optional<TYPE>>, is produced,
//    even though it's a Child<optional<TYPE>>. (If we had a container
//    of optionals, then when, and from where, would any nullopt values
//    arise? We're filling the container with what we do find, in which
//    case there'd be no real meaning associated with any nullopt values.)
//
//    Consistent with the behavior of std::optional elsewhere in GNDStk's
//    queries, we'll *always* return from here with found == true. That's
//    already the case with Allow::many if container.size() > 0 on output,
//    but now we'll unconditionally return found == true, even for 0 size.
//
// We may change this, if doing something else proves to make more sense,
// or to be more useful. It's possible, for example, that for the sake of
// consistency we should always return objects that involve precisely the
// type that's given in the Child, even in cases like this in which such
// a modification seems to be sensible from a practical standpoint.

template<
   template<class...> class CONTAINER = std::vector,
   class TYPE, class CONVERTER, class FILTER
>
CONTAINER<TYPE> child(
   const Child<std::optional<TYPE>,Allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // The behavior described above makes this easy as well.
      // That wasn't our intention, but we don't mind too much.
      return
         found = true,
         child((kwd.object ? kwd.object.value() : TYPE{})/kwd);
   } catch (...) {
      log::member("Node.child(" + detail::keyname(kwd) + " with Allow::many)");
      throw;
   }
}


// ------------------------
// Defaulted<TYPE>
// ------------------------

// Comments similar to those for the optional case above
template<
   template<class...> class CONTAINER = std::vector,
   class TYPE, class CONVERTER, class FILTER
>
CONTAINER<TYPE> child(
   const Child<Defaulted<TYPE>,Allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      return found = true, child(kwd.object.value()/kwd);
   } catch (...) {
      log::member("Node.child(" + detail::keyname(kwd) + " with Allow::many)");
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
   const Child<std::variant<Ts...>,Allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   const auto ptr = std::get_if<TYPE>(&kwd.object);
   return child<CONTAINER>((ptr ? *ptr : TYPE{})/kwd, found);
}
