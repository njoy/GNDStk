
// -----------------------------------------------------------------------------
// Node.add()
// For child nodes
// -----------------------------------------------------------------------------

// Terminology: as for the Node.add()s for metadata.
//
// Remark. Some of the Child add()s accept a general ALLOW Child (either
// Allow::one or Allow::many) along with just *one* value. The Allow::many
// is permissible here - even with just one value - because we could certainly
// intend to add multiple values one-by-one.
//
// Naturally, we'll also have add() functions that accept only an Allow::many
// Child, and receive containers of values.



// -----------------------------------------------------------------------------
// 0-argument
// 1-argument:
//    string
//    plain
//    Defaulted
// Guaranteed to add something
// Returns: reference to the added Node
// -----------------------------------------------------------------------------

// 0-argument
// 1-argument: string (the name)
Node &add(const std::string &name = emptyNodeName)
{
   children.push_back(std::make_unique<Node>());
   Node &newChild = *children.back();
   newChild.name = name;
   newChild.parentNode = this;
   return newChild;
}

// 1-argument: plain
template<
   class T,
   class = std::enable_if_t<std::is_constructible_v<Node,T>>,
   class = std::enable_if_t<!detail::isOptional<T>>
>
Node &add(
   const T &val // <== via SFINAE, T != optional
) {
   return add() = Node(val);
}

// 1-argument: optional
// Not available, because adding it couldn't be certain

// 1-argument: Defaulted
template<
   class T,
   class = std::enable_if_t<std::is_constructible_v<Node,T>>
>
Node &add(const Defaulted<T> &def)
{
   return add(def.value());
}



// -----------------------------------------------------------------------------
// Child<void>, *
// Guaranteed to add something
// Returns: reference to the added Node
// -----------------------------------------------------------------------------

// Similar in principle to its Meta counterpart. Bounces to one of the above
// add() functions, and, like those, doesn't allow std::optional.

// Child<void>, plain
// Child<void>, Defaulted
template<
   class T = Node, Allow ALLOW, class FILTER,
   class = std::enable_if_t<std::is_constructible_v<Node,T>>,
   class = std::enable_if_t<!detail::isOptional<T>>
>
Node &add(
   const Child<void,ALLOW,void,FILTER> &kwd,
   const T &val = T{} // <== via SFINAE, T != optional
) {
   Node &n = add(val);
   n.name = kwd.name;
   return n;
}



// -----------------------------------------------------------------------------
// Child<plain>, *
// Guaranteed to add something
// Returns: reference to the added Node
// -----------------------------------------------------------------------------

// Child<plain>, plain
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class T = TYPE,
   class = std::enable_if_t<!detail::isOptional<T>>,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
Node &add(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const T &val = T{} // <== via SFINAE, T != optional
) {
   try {
      // Special case. The following is a mechanism by which someone can have
      // add() *not* actually add a new child node to the current node, but
      // instead have it assume that the converter will modify the current node
      // in some fashion (perhaps by adding a child node itself; but, really,
      // any modification would be possible). This case can be seen as basically
      // the complement of how the query system returns *this when given the
      // special::self string, instead of interpreting the string as the name
      // of a child node that it should find and return. It turns out that
      // this "identity function," in a manner of speaking, will be useful for
      // achieving some things that would otherwise be more awkward to achieve.
      if (kwd.name == special::self) {
         assert(false); // todo NEED TO TEST WRITING!!!
         kwd.converter(TYPE(val),*this);
         return *this;
      }

      // new node
      Node &n = add(kwd.name);

      // name
      if constexpr (detail::isVariant<TYPE>::value) {
         std::istringstream names(kwd.name);
         const std::size_t index = TYPE(val).index();
         for (std::size_t i = 0; i <= index; ++i)
            names >> n.name;
         // todo Have a warning or error if we can't properly extract
         // the index()-th name. This might mean someone didn't formulate
         // the name properly when dealing with a variant.
      }

      // convert value into node
      kwd.converter(TYPE(val),n);

      return n;
   } catch (...) {
      log::member("Node.add(" + detail::keyname(kwd) + ",value)");
      throw;
   }
}

// Child<plain>, optional
// Not available, because adding it couldn't be certain

// Child<plain>, Defaulted
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class T,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
Node &add(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const Defaulted<T> &def
) {
   return add(kwd, def.value());
}



// -----------------------------------------------------------------------------
// Child<optional>, *
// -----------------------------------------------------------------------------

// Child<optional>, plain
// Returns: Node &
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class T = TYPE,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
Node &add(
   const Child<std::optional<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const T &val = T{}
) {
   return add(TYPE{}/kwd, val);
}

// Child<optional>, optional
// Returns: bool: was something added?
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class T,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
bool add(
   const Child<std::optional<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const std::optional<T> &opt
) {
   return opt.has_value() ? (add(kwd, opt.value()), true) : false;
}

// Child<optional>, Defaulted
// Returns: bool: was something added?
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class T,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
bool add(
   const Child<std::optional<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const Defaulted<T> &def
) {
   return def.has_value() ? (add(kwd, def.value()), true) : false;
}



// -----------------------------------------------------------------------------
// Child<Defaulted>, *
// -----------------------------------------------------------------------------

// Child<Defaulted>, plain
// Returns: Node &
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class T = TYPE,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
Node &add(
   const Child<Defaulted<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const T &val = T{}
) {
   return add(TYPE{}/kwd, val);
}

// Child<Defaulted>, optional
// Returns: bool: was something added?
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class T,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
bool add(
   const Child<Defaulted<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const std::optional<T> &opt
) {
   return opt.has_value() ? (add(kwd, opt.value()), true) : false;
}

// Child<Defaulted>, Defaulted
// Returns: bool: was something added?
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER,
   class T,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
bool add(
   const Child<Defaulted<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const Defaulted<T> &def
) {
   return def.has_value() ? (add(kwd, def.value()), true) : false;
}



// -----------------------------------------------------------------------------
// Child<*> with Allow::many, and a container
// -----------------------------------------------------------------------------

// This takes a container, and builds on our non-container overloads. The add()
// that it calls, for each container element, can return either Node & or bool,
// depending on what particular types are involved. Those returns will, in any
// event, generally be different for different container elements. Therefore,
// this function doesn't return anything.

// The relatively complicated template specification is designed to handle both
// Child<void> and Child<TYPE>, and T (for the container elements) being a plain
// type, a std::optional<something>, or a Defaulted<something>.

template<
   // re: the Child
   class TYPE, class CONVERTER, class FILTER,

   // re: the container
   template<class...> class CONTAINER = std::vector,
   class T = // <== Node for Child<void>; else TYPE
      std::conditional_t<detail::isVoid<TYPE>,Node,TYPE>,
   class... Args,
   class = std::enable_if_t<detail::isIterable<CONTAINER<T,Args...>>::value>,

   // re: constructible-to that an underlying add() will require:
   // to Node if Child<void>, to TYPE if Child<TYPE>
   class = std::enable_if_t<
      std::is_constructible_v<
         std::conditional_t<detail::isVoid<TYPE>,Node,TYPE>,
         // remove type, if inside optional<> or Defaulted<>
         typename detail::remove_opt_def<T>::type
      >
   >
>
void add(
   const Child<TYPE,Allow::many,CONVERTER,FILTER> &kwd,
   const CONTAINER<T,Args...> &container
) {
   try {
      for (const T &val : container)
         add(--kwd,val); // --kwd: Child w/Allow::one
   } catch (...) {
      log::member("Node.add(" + detail::keyname(kwd) + ",container)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// Child<*> with Allow::many, and an optional container
// -----------------------------------------------------------------------------

// SFINAE as in (non-optional) container case
template<
   class TYPE, class CONVERTER, class FILTER,

   template<class...> class CONTAINER = std::vector,
   class T =
      std::conditional_t<detail::isVoid<TYPE>,Node,TYPE>,
   class... Args,
   class = std::enable_if_t<detail::isIterable<CONTAINER<T,Args...>>::value>,

   class = std::enable_if_t<
      std::is_constructible_v<
         std::conditional_t<detail::isVoid<TYPE>,Node,TYPE>,
         typename detail::remove_opt_def<T>::type
      >
   >
>
void add(
   const Child<std::optional<TYPE>,Allow::many,CONVERTER,FILTER> &kwd,
   const std::optional<CONTAINER<T,Args...>> &opt
) {
   if (opt.has_value())
      add(TYPE{}/kwd, opt.value());
}
