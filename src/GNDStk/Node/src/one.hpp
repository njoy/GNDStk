
// -----------------------------------------------------------------------------
// Node.one(string,...)
//
// Searches the current node's sub-nodes for one that has the given name, and
// that also passes the given filter requirement. If it's found, the sub-node
// is returned. Else, an empty node is returned.
//
// Call one() you expect exactly one such value. (Some GNDS nodes are expected
// to occur at most once as a sub-node of a given parent, even if the file
// format used, e.g. XML, might allow for more than one same-named sub-node.)
//
// With one(), as opposed to many(), you'll get a direct reference to the one
// found node, not to a container of nodes.
// -----------------------------------------------------------------------------

// ------------------------
// one(key,filter[,found])
// ------------------------

// const
template<class FILTER>
const Node &one(
   const std::string &key,
   const FILTER &filter,
   bool &found = detail::default_bool
) const {
   // ""
   // meaning: return the current node
   if (key == "" || key == special::self) {
      // filter is ignored in this case
      return found = true, *this;
   }

   // search in the current node's children,
   // with these tracked for better diagnostics:
   // nname: #times node name matches key
   // nboth: #times node name matches key AND ALSO the filter condition is met
   const Node *theone = nullptr;
   std::size_t nname = 0, nboth = 0;
   for (auto &c : children)
      if (std::regex_match(c->name, std::regex(key))
          && (nname++, filter(*c)) && nboth++ == 0)
         theone = &(*c);

   // found
   if (nboth) {
      if (nboth > 1)
         log::warning(
            "Node.one(\"{}\") was called, but {} matching nodes were found.\n"
            "Returning the first one that was found. Context: Node \"{}\".",
            key, nboth, name // name == current ("parent") node's name
         );
      return found = true, *theone;
   }

   // not found
   found = false;

   // error iff no "found" flag sent
   if (!detail::sent(found)) {
      if (nname == 0)
         log::error(
            "Node.one(\"{}\"): no Nodes matching the key were found", key);
      else if (nname == 1)
         log::error(
            "Node.one(\"{}\"): a Node matching the key was found,\n"
            "but it didn't pass the filter condition", key);
      else
         log::error(
            "Node.one(\"{}\"): {} Nodes matching the key were found,\n"
            "but none of them passed the filter condition", key, nname);
      throw std::exception{};
   }

   // done
   static Node empty;
   return empty.clear();
}


// non-const
template<class FILTER>
Node &one(
   const std::string &key,
   const FILTER &filter,
   bool &found = detail::default_bool
) {
   return const_cast<Node &>(std::as_const(*this).one(key,filter,found));
}



// ------------------------
// one(key[,found])
// ------------------------

// const
const Node &one(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   return one(key, detail::noFilter{}, found);
}

// non-const
Node &one(
   const std::string &key,
   bool &found = detail::default_bool
) {
   return one(key, detail::noFilter{}, found);
}
