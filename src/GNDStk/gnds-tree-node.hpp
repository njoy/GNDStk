
// -----------------------------------------------------------------------------
// Node (templated)
// Then node = Node<>
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
class Node {
   // for internal use
   static bool static_found;

   using pair = std::pair<std::string,std::string>;
   using sptr = std::shared_ptr<Node>;

public:

   // Simple node for our tree structure:
   //    name
   //    metadata
   //    children
   std::string name;
   METADATA_CONTAINER<pair,std::allocator<pair>> metadata;
   CHILDREN_CONTAINER<sptr,std::allocator<sptr>> children;

   // normalize
   void normalize();

   // push metadatum
   pair &push(const std::string &key, const std::string &value)
   {
      metadata.push_back(std::make_pair(key,value));
      return metadata.back();
   }

   pair &push(const pair &m)
   {
      metadata.push_back(m);
      return metadata.back();
   }

   template<class T>
   pair &push(const std::string &key, const T &value)
   {
      std::ostringstream oss;
      oss << value;
      return push(key,oss.str());
   }

   template<class T>
   pair &push(const std::pair<std::string,T> &m)
   {
      std::ostringstream oss;
      oss << m.second;
      return push(pair(m.first,oss.str()));
   }

   // push child
   Node &push(const std::string &name = "")
   {
      children.push_back(
         std::make_shared<Node<METADATA_CONTAINER,CHILDREN_CONTAINER>>()
      );
      children.back()->name = name;
      return *children.back();
   }

   // write
   bool write(const std::string &file, const int level = 0) const;
   std::ostream &write(std::ostream &, const int level = 0) const;

   // leaf?
   bool leaf() const
   {
      return children.size() == 0;
   }


   // ------------------------
   // meta()
   // ------------------------

   // for string
   const std::string &meta(
      const std::string &str,
      bool &found = static_found // importantly, a reference; see below
   ) const {
      // search
      for (auto &m : metadata)
         if (m.first == str)
            return found = true, m.second;

      // not found
      found = false;
      static const std::string empty = "";

      // If a "found" flag was NOT sent to this function, we'll emit an error.
      // Otherwise, we'll assume that the caller intends to deal with the issue
      // in its own way, and therefore that we shouldn't produce such an error.
      // Note that the question of whether a "found" flag was sent is determined
      // by looking at its address. This is entirely different from the question
      // of what found's value should be. Its value is set either way.
      if (&found == &static_found) {
         // found references our private default - so, caller didn't send one
         error(
            "Node meta() called with key \"" + str + "\", "
            "but this key wasn't\nfound in the node's metadata."
         );
      }

      // done
      return empty;
   }

   // for meta_t<T>
   // Return by value isn't ideal, if T is something large like a container.
   // Think about options.
   template<class T>
   T meta(
      const meta_t<T> &kwd,
      bool &found = static_found
   ) const {
      const std::string &str = meta(kwd.name,found);
      T value{};
      if (found)
         gnds::read(str,value);
      return value;
   }

   // for meta_t<string>
   // Functionally equivalent to using meta(meta_t<T>) with T = string,
   // but more direct and thus perhaps more efficient.
   std::string meta(
      const meta_t<std::string> &kwd,
      bool &found = static_found
   ) const {
      return meta(kwd.name,found); // direct call to meta(string)
   }

   // for meta_t<void>
   // Let's define the meta_t<void> case to be equivalent to the meta_t<string>
   // case. This makes the behavior of meta_t be more consistent with that of
   // child_t, which uses <void> to stipulate that the child node be returned
   // in its original tree-node form.
   std::string meta(
      const meta_t<void> &kwd,
      bool &found = static_found
   ) const {
      return meta(kwd.name,found); // as above
   }

   // for meta_t<variant>, caller must stipulate <T>.
   // We can't just fold this into meta(meta_t<T>) above and return the variant,
   // because the read() would have no idea what variant variation to read into!
   template<class T, class... Ts>
   T meta(
      const meta_t<std::variant<Ts...>> &kwd,
      bool &found = static_found
   ) const {
      // body is as above, but the function signature is structurally different
      const std::string &str = meta(kwd.name,found);
      T value{}; // T having been direct-specified, not in meta_t<here>
      if (found)
         gnds::read(str,value);
      return value;
   }


   // ------------------------
   // child()
   // ------------------------

   // for string
   const Node &child(
      const std::string &str,
      bool &found = static_found // as for meta(string)
      // fixme Need "found" below, and in operator()
   ) const {
      // search
      for (auto &c : children)
         if (c != nullptr and c->name == str)
            return found = true, *c;

      // not found
      found = false;
      static const Node empty;

      // comment as in meta(string)
      if (&found == &static_found) {
         error(
            "Node child() called with key \"" + str + "\", "
            "but this key wasn't\nfound in the node's children."
         );
      }

      // done
      return empty;
   }

   // for child_t<T>
   template<class T, class META, class CHILD>
   auto child(const child_t<T,META,CHILD> &kwd) const
   {
      return tnode<METADATA_CONTAINER,CHILDREN_CONTAINER,T>(child(kwd.name));
   }

   // for child_t<variant>, caller must stipulate <T>.
   template<class T, class META, class CHILD, class... Ts>
   auto child(const child_t<std::variant<Ts...>,META,CHILD> &kwd) const
   {
      return tnode<METADATA_CONTAINER,CHILDREN_CONTAINER,T>(child(kwd.name));
   }


   // ------------------------
   // operator()
   // ------------------------

   // These provide notationally consistent access to the above meta() and
   // child() functions, except that the std::string parameter versions of
   // those functions are intentionally not supported here, as it would be
   // indeterminate as to whether we'd want the meta or child (std::string)
   // function. This is not a deficiency, but instead reflects the fact that
   // calling these functions with meta_t and child_t parameters - not with
   // std::string parameters - should be preferred. Those encode (via their
   // type) whether we're accessing metadata or children.

   // meta_t
   // forwards to meta(meta_t) above
   template<class T>
   decltype(auto) operator()(const meta_t<T> &kwd) const
   {
      return meta(kwd);
   }

   // child_t
   // forwards to child(child_t) above
   template<class T, class META, class CHILD>
   decltype(auto) operator()(const child_t<T,META,CHILD> &kwd) const
   {
      return child(kwd);
   }

   // child_t, ...
   // multi-argument
   template<class T, class META, class CHILD, class... Ts>
   decltype(auto) operator()(
      const child_t<T,META,CHILD> &kwd,
      Ts &&...ts
   ) const {
      return (*this)(kwd)(std::forward<Ts>(ts)...);
   }

}; // class Node

// Node::static_found
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool Node<METADATA_CONTAINER,CHILDREN_CONTAINER>::static_found = false;



// -----------------------------------------------------------------------------
// write
// -----------------------------------------------------------------------------

// write(string)
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
inline bool Node<METADATA_CONTAINER,CHILDREN_CONTAINER>::write(
   const std::string &file,
   const int level
) const {
   // calls write(ostream) below
   std::ofstream ofs(file.c_str());
   return not write(ofs,level).fail();
}


// write(ostream)
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
std::ostream &Node<METADATA_CONTAINER,CHILDREN_CONTAINER>::write(
   std::ostream &os,
   const int level
) const {
   // indentation
   const std::string icurr(indent* level   ,' '); // current indentation #spaces
   const std::string inext(indent*(level+1),' '); // next ...

   // write name
   os << icurr << name << ":" << std::endl;

   // write metadata
   for (const auto &meta : metadata)
      os << inext << meta.first << ": " << meta.second << std::endl;

   // write children
   for (const auto &cptr : children)
      if (cptr)
         cptr->write(os,level+1);

   // done
   return os;
}


// operator<<
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
inline std::ostream &operator<<(
   std::ostream &os,
   const Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &obj
) {
   // calls write(ostream) above
   return obj.write(os);
}



// -----------------------------------------------------------------------------
// normalize
// -----------------------------------------------------------------------------

namespace detail {

// helper: strip
// Strips leading digits and white-space from a string. Modifies
// the original string, and also returns a reference to it.
inline std::string &strip(std::string &name)
{
   int n = 0, ch; const int size = name.size();
   while (n < size and (isdigit(ch=name[n]) or isspace(ch)))
      n++;
   return n ? (name = std::string(&name[n])) : name;
}

} // namespace detail



// normalize
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
void Node<METADATA_CONTAINER,CHILDREN_CONTAINER>::normalize()
{
   // name
   detail::strip(name);

   // children
   auto iter = children.end();
   for (auto c = children.begin();  c != children.end();  ++c)
      if (detail::strip((*c)->name) == "attributes") {
         // Child node's name is "attributes". This presumably means that the
         // current node originally had *that* child node's metadata as its
         // own, before they were placed into an "attributes" child for the
         // purpose of writing, say, to a .json file. Now, apparently, we've
         // just read such a file, and must restore the node's original form.

         // Under the circumstances, this node should not (yet) have its own
         // metadata. They'll be pulled up from the "attributes" child, which
         // itself should have only those metadata (and not further children).
         assert(metadata.size() == 0);  // <== this node has no metadata
         assert((*c)->children.size() == 0); // <== child node has no children

         // And, there should have been at most one such "attributes" child.
         assert(iter == children.end()); // up until now
         iter = c; // now

         // Restore the metadata
         for (auto &m : (*c)->metadata)
            push(m);

      } else if (endsin((*c)->name, "_attr")) {
         assert(false); // for now
         // Child node's name ends in "_attr"
         /*
         fixme
         I'll  need to think about the .json business more, and see what sorts
         of GNDS json files are actually being produced by people other than
         myself, in order to know for certain what I'll need to do in order to
         properly read whatever other people might be writing. In my own json-
         reading code, I use is_object(), from the nlohmann json library, to
         distinguish whether what I'm reading should be entered into the current
         node's children, or go into its metadata. I think this condition
         amounts to whether the value in a json key/value pair is of the {...}
         form (goes to children), or the "..." form (goes to metadata). The
         GNDS manual speaks of the json format *not* having the concept of
         attributes, but perhaps in some sense it does, via the condition I've
         just described.
         */
      } else {
         // Regular child node; recursively normalize
         (*c)->normalize();
      }

   // chuck any "attributes" child
   if (iter != children.end())
      children.erase(iter);

   // metadata, including any additional ones from an "attributes"
   // child as described above
   for (auto &meta : metadata)
      detail::strip(meta.first);
}



// -----------------------------------------------------------------------------
// Summary
// -----------------------------------------------------------------------------

/*
Node::meta()
   const string & meta  ( const string                  &str ) const;
   T              meta  ( const meta_t<T>               &kwd ) const;
   string         meta  ( const meta_t<string>          &kwd ) const;
   string         meta  ( const meta_t<void>            &kwd ) const;
   T              meta  ( const meta_t<variant<Ts...>>  &kwd ) const;

Node::child()
   const Node & child ( const string                  &str ) const;
   tnode<...,T> child ( const child_t<T>              &kwd ) const;
   tnode<...,T> child ( const child_t<variant<Ts...>> &kwd ) const

Node::operator()()
   decltype(auto) operator() ( const meta_t <T> &kwd             ) const;
   decltype(auto) operator() ( const child_t<T> &kwd             ) const;
   decltype(auto) operator() ( const child_t<T> &kwd, Ts &&...ts ) const;
*/
