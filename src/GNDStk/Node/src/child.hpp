
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
// Non-const versions aren't needed for most of these, as they return by value.
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// child(Child<void,one/many,...>[,found])
// -----------------------------------------------------------------------------

// one, const
template<class FILTER>
const Node &
child(
   const Child<void,Allow::one,void,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return one(kwd.name, kwd.filter, found);
}

// one, non-const
template<class FILTER>
Node &
child(
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
CONTAINER<Node>
child(
   const Child<void,Allow::many,void,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   return many<CONTAINER>(kwd.name, kwd.filter, found);
}



// -----------------------------------------------------------------------------
// child(Child<TYPE,one,...>[,found])
// -----------------------------------------------------------------------------

// ------------------------
// variant_find_one
// helper
// ------------------------

private:

template<std::size_t n, std::size_t size, class KWD, class... Ts>
void variant_find_one(
   const KWD &kwd,
   const std::vector<std::string> &names,
   bool &found,
   std::variant<Ts...> &var,
   // variant alternative# that may have already been found...
   std::size_t selectedAlternative
) const {
   if constexpr (n < size) {
      bool f = false; // local "found"
      const Node &node = one(names[n], kwd.filter, f);

      if (f) { // if one() found anything for the <n> alternative
         if (found) // if already global "found", then warning...
         {
            // The situation here is as follows. In the present context, we're
            // supposed to find exactly one matching child node (of *this) over
            // all variant alternatives ("outer" loop in this function's caller)
            // and all child nodes ("inner" loop, done within the above one()
            // call). One match, that is, in a sort of two-loop/two-dimensional
            // sense. The one() call above will have triggered a warning if more
            // than one child node matched with the current variant alternative.
            // Right now, we have a situation in which a match was already found
            // somewhere, somehow, in a previous variant alternative. It could
            // be a match of the same child node or a different one. Either way,
            // it's a match of some child node, in an earlier alternative. (Not
            // *just* a match of an earlier child in the current alternative,
            // without anything yet from an earlier alternative - "if (found)"
            // won't quite yet be true in that scenario, but one() would have
            // just emitted a warning.)

            // warning
            log::warning(
               "A node for <{}> \"{}\" from Child<variant<...>>'s name,\n"
               "   \"{}\"\n"
               "was already found. "
               "Now, a node for <{}> \"{}\" has also been found.\n"
               + std::string(
                  names[n] == names[selectedAlternative]
                  ? "No wonder; those keys are duplicates in the name!\n"
                  : ""
               ) +
               "Keeping the position <{}> \"{}\" variant alternative.",
               selectedAlternative, names[selectedAlternative], // already
               kwd.name,
               n, names[n], // new one
               selectedAlternative, names[selectedAlternative]  // keeping
            );

            // context
            log::member(
               "Node.child(" + detail::keyname(kwd) + " with Allow::one)"
            );
         } else { // not already global "found"...
            // convert the Node to an object of the n-th variant alternative
            std::variant_alternative_t<n,std::variant<Ts...>> alt;
            kwd.converter(node,alt);
            var = alt;
            selectedAlternative = n;
            found = true;
         }
      }

      // Proceed to the next alternative in the variant.
      // Do this even if a match was already found, above,
      // so that we can warn if there are multiple matches.
      variant_find_one<n+1,size>(kwd, names, found, var, selectedAlternative);

   } else {
      // done with recursion
      if (!found && !detail::sent(found)) {
         log::error(
            "No nodes matching any tokens in the Child<variant<...>> object's\n"
            "name were found (or passed the filter condition, "
            "if one was given)."
         );
         throw std::exception{};
      }
   }
}

public:


// ------------------------
// TYPE
// ------------------------

template<class TYPE, class CONVERTER, class FILTER>
TYPE
child(
   const Child<TYPE,Allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      TYPE obj = kwd.object;

      if constexpr (detail::isVariant<TYPE>::value) {
         // ------------------------
         // variant obj
         // ------------------------

         const auto names = detail::name_split(kwd);
         found = false;
         variant_find_one<0,std::variant_size_v<TYPE>>(kwd,names,found,obj,0);

      } else {
         // ------------------------
         // non-variant obj
         // ------------------------

         // call one(string), with the Child's key
         const Node &node = one(kwd.name, kwd.filter, found);
         // convert the node, if found, to an object of the appropriate type
         if (found)
            kwd.converter(node,obj);
      }

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
std::optional<TYPE>
child(
   const Child<std::optional<TYPE>,Allow::one,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // Comments as in the meta() analog of this child() function
      bool f;
      const TYPE obj =
         child((kwd.object.has_value() ? kwd.object.value() : TYPE{})/kwd, f);
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
Defaulted<TYPE>
child(
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
std::enable_if_t<
   detail::isAlternativeOrTheVariant<TYPE,std::variant<Ts...>>,
   TYPE
> child(
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
// variant_find_many
// helper
// ------------------------

private:

template<
   std::size_t n, std::size_t size,
   template<class...> class CONTAINER,
   class KWD, class... Ts
>
bool variant_find_many(
   const Node &c, // child node from loop in caller
   CONTAINER<std::variant<Ts...>> &container,
   const KWD &kwd,
   const std::vector<std::string> &names,
   bool &found,
   std::size_t selectedAlternative
) const {
   if constexpr (n < size) {
      if (std::regex_match(c.name,std::regex(names[n])) && kwd.filter(c)) {
         if (found)
         {
            // This function (variant_find_many()) is for building a container
            // of std::variant objects from each matching child of the caller's
            // *this node. Given that we're building a container, it's normal
            // and expected that multiple matches may occur. Bear in mind, then,
            // that the following message does not (and should not) warn about
            // multiple matching child nodes. Rather, the warning relates to the
            // situation of the current child node (c) matching against multiple
            // different alternatives in the std::variant. This shouldn't happen
            // if the names[n] (the whitespace-separated names we obtained from
            // kwd.name) are distinct. However: (1) a user could make a mistake
            // in that regard; and (2) as elsewhere, we do a regex match, which
            // could concievably lead to multiple matches if the regexes aren't
            // formulated in a manner that prevents - as they should - multiple
            // matches. (We don't anticipate heavy use of actual, non-trivial
            // regexes, but should certainly warn of problems nonetheless.)

            log::warning(
               "Node \"{}\" matched with <{}> \"{}\" from "
               "Child<variant<...>>'s name,\n"
               "   {}\n"
               "but also matches with the <{}> \"{}\" alternative.\n"
               + std::string(
                  names[n] == names[selectedAlternative]
                  ? "No wonder; those keys are duplicates in the name!\n"
                  : ""
               ) +
               "Keeping the position <{}> \"{}\" variant alternative.\n",
               c.name, // current node's name
               selectedAlternative, names[selectedAlternative], // already
               kwd.name,
               n, names[n], // new one
               selectedAlternative, names[selectedAlternative]  // keeping
            );

            // context
            log::member(
               "Node.child(" + detail::keyname(kwd) + " with Allow::many)"
            );
         } else {
            // not (found)
            // convert the Node to an object of the n-th variant alternative
            std::variant_alternative_t<n,std::variant<Ts...>> alt;
            kwd.converter(c,alt);
            container.push_back(alt);
            selectedAlternative = n;
            found = true;
         }
      } // if regex_match + filter

      // Proceed to the next alternative in the variant
      return variant_find_many<n+1,size>
         (c, container, kwd, names, found, selectedAlternative);
   } // if constexpr (n < size)

   return found;
}

public:


// ------------------------
// TYPE
// ------------------------

template<
   template<class...> class CONTAINER = std::vector,
   class TYPE, class CONVERTER, class FILTER
>
CONTAINER<TYPE>
child(
   const Child<TYPE,Allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   // container
   CONTAINER<TYPE> container;
   found = false;

   try {

      if constexpr (detail::isVariant<TYPE>::value) {
         // ------------------------
         // variant obj
         // ------------------------

         const auto names = detail::name_split(kwd);
         for (auto &c : children) {
            bool f = false; // per-child "found", over variant alternatives
            if (variant_find_many<0,std::variant_size_v<TYPE>>
                (*c, container, kwd, names, f, 0))
               found = true;
         }

      } else {
         // ------------------------
         // non-variant obj
         // ------------------------

         // ""
         // meaning: return a container with the converted-to-TYPE current Node
         if (kwd.name == "") {
            TYPE obj = kwd.object;
            kwd.converter(*this,obj);
            container.push_back(obj);
            found = true;
         } else {
            // search in the current Node's children
            for (auto &c : children)
               if (std::regex_match(c->name, std::regex(kwd.name)) &&
                   kwd.filter(*c)
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

// With an Allow::many Child, as we have here, it's permissible (without an
// exception being thrown) to extract any number of values - including none -
// into the container. In some sense, then, Allow::many means it's optional
// to have *any* matching values. So the question is: how should we handle
// Child<std::optional<TYPE>,Allow::many>, given that two different "optional"
// concepts are involved?
//
// Creating a container<std::optional<TYPE>> wouldn't really make sense.
// With a container of optionals, when, and from where, would any nullopt
// values arise? We're filling the container with what we do find, in which
// case there's no real meaning associated with any nullopt values.
//
// We could dispense with "optional" altogether, and return container<TYPE>,
// with length 0 (i.e. no elements in the container) if no values are found.
// That's arguably a resonable behavior, but is the same behavior we'd have
// if the Child didn't have a std::optional type in the first place.
//
// So, let's give the optional encoding (as in Child<std::optional<TYPE>>)
// some meaning, in the following way. We'll return an optional container,
// with no value (so that optional.has_value() == false) in the event that
// the container would have no elements. Else, optional.has_value() will be
// true, with a container that has >= 1 element.
//
// Consistent with the behavior of std::optional elsewhere in GNDStk, we'll
// always return from here with found == true. That's already the case with
// Allow::many if container.size() > 0 on output, but now we unconditionally
// return found == true, even for "0 size", which, as we'd said, now means
// that there's no value in the optional.

template<
   template<class...> class CONTAINER = std::vector,
   class TYPE, class CONVERTER, class FILTER
>
std::optional<CONTAINER<TYPE>>
child(
   const Child<std::optional<TYPE>,Allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      bool f;
      const auto container =
         child((kwd.object.has_value() ? kwd.object.value() : TYPE{})/kwd, f);
      found = true;
      return f ? std::optional<CONTAINER<TYPE>>(container) : std::nullopt;
   } catch (...) {
      log::member("Node.child(" + detail::keyname(kwd) + " with Allow::many)");
      throw;
   }
}


// ------------------------
// Defaulted<TYPE>
// ------------------------

// Similar to the optional case. We'll return a Defaulted<CONTAINER<TYPE>>,
// with the default value being a container of one value - the value from
// the original Defaulted<TYPE> in the Child object.
template<
   template<class...> class CONTAINER = std::vector,
   class TYPE, class CONVERTER, class FILTER
>
Defaulted<CONTAINER<TYPE>>
child(
   const Child<Defaulted<TYPE>,Allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      bool f;
      const auto container = child(kwd.object.value()/kwd, f);
      found = true;
      return f
         ? Defaulted<CONTAINER<TYPE>>(
              CONTAINER<TYPE>(1, kwd.object.get_default()), container)
         : Defaulted<CONTAINER<TYPE>>(
              CONTAINER<TYPE>(1, kwd.object.get_default()));
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
CONTAINER<
   std::enable_if_t<
      detail::isAlternativeOrTheVariant<TYPE,std::variant<Ts...>>,
      TYPE
   >
> child(
   const Child<std::variant<Ts...>,Allow::many,CONVERTER,FILTER> &kwd,
   bool &found = detail::default_bool
) const {
   const auto ptr = std::get_if<TYPE>(&kwd.object);
   return child<CONTAINER>((ptr ? *ptr : TYPE{})/kwd, found);
}
