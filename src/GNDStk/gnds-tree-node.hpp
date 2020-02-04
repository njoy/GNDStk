
// -----------------------------------------------------------------------------
// Node (templated)
// Then node = Node<>
// -----------------------------------------------------------------------------

template<
   template<class...> class MCON,
   template<class...> class CCON
>
class Node {
   using pair = std::pair<std::string,std::string>;
   using sptr = std::shared_ptr<Node>;

public:

   // Simple node for our tree structure:
   //    name
   //    metadata
   //    children
   std::string name;
   MCON<pair,std::allocator<pair>> metadata;
   CCON<sptr,std::allocator<sptr>> children;

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

   // push child
   Node &push()
   {
      children.push_back(std::make_shared<Node<MCON,CCON>>());
      return *children.back();
   }

   // write
   bool write(const char * const file, const int level = 0) const;
   bool write(const std::string &file, const int level = 0) const
   {
      return write(file.c_str(),level);
   }
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
   const std::string &meta(const std::string &str) const
   {
      for (auto &m : metadata)
         if (m.first == str)
            return m.second;
      // fixme: eventually, do something better than this...
      assert(false);
      static std::string empty = "";
      return empty;
   }

   // for meta_t<T>
   // Return by value isn't ideal, if T is something large like a container.
   // Think about options.
   template<class T>
   T meta(const meta_t<T> &kwd) const
   {
      const std::string &str = meta(kwd.name);
      T value;
      gnds::read(str,value);
      return value;
   }

   // for meta_t<string>
   // The above is functionally equivalent, as we have a read(string,string)
   // that just copies the string (and we want that read() anyway, for possible
   // use by the variant case below). But let's do this directly, for clarity's
   // sake, even if after optimization the above probably wouldn't be worse...
   std::string meta(const meta_t<std::string> &kwd) const
   {
      return meta(kwd.name); // raw (not meta_t<>'d) string case, earlier
   }

   // for meta_t<void>
   // What the hey, let's define the meta_t<void> case to be equivalent to the
   // meta_t<string> case. This makes meta_t's behavior more consistent with
   // that of child_t, which uses <void> to stipulate that the child node be
   // returned in its original form in the tree.
   std::string meta(const meta_t<void> &kwd) const
   {
      return meta(kwd.name); // as above
   }

   // for meta_t<variant>, caller must stipulate <T>.
   // We don't just fold this into meta(meta_t<T>) above and return the variant,
   // because the read() would have no idea what variant variation to read into!
   template<class T, class... Ts>
   T meta(const meta_t<std::variant<Ts...>> &kwd) const
   {
      // body is as above, but function signature is structurally different
      const std::string &str = meta(kwd.name);
      T value;
      gnds::read(str,value);
      return value;
   }


   // ------------------------
   // child()
   // ------------------------

   // for string
   const Node &child(const std::string &str) const
   {
      for (auto &c : children)
         if (c != nullptr && c->name == str)
            return *c;
      // fixme: eventually, do something better than this...
      assert(false);
      static Node empty;
      return empty;
   }

   // for child_t<T>
   template<class T, class META, class CHILD>
   auto child(const child_t<T,META,CHILD> &kwd) const
   {
      return tnode<MCON,CCON,T>(child(kwd.name));
   }

   // for child_t<variant>, caller must stipulate <T>.
   template<class T, class META, class CHILD, class... Ts>
   auto child(const child_t<std::variant<Ts...>,META,CHILD> &kwd) const
   {
      return tnode<MCON,CCON,T>(child(kwd.name));
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



// -----------------------------------------------------------------------------
// write
// -----------------------------------------------------------------------------

// write(char *)
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline bool Node<MCON,CCON>::write(
   const char * const file,
   const int level
) const {
   // calls write(ostream) below
   std::ofstream ofs(file);
   return !write(ofs,level).fail();
}


// write(ostream)
template<
   template<class...> class MCON,
   template<class...> class CCON
>
std::ostream &Node<MCON,CCON>::write(
   std::ostream &os,
   const int level
) const {
   // indentation
   const std::string icurr(indent* level   ,' ');
   const std::string inext(indent*(level+1),' ');

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
   template<class...> class MCON,
   template<class...> class CCON
>
inline std::ostream &operator<<(std::ostream &os, const Node<MCON,CCON> &obj)
{
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
   while (n < size && (isdigit(ch=name[n]) || isspace(ch)))
      n++;
   return n ? (name = std::string(&name[n])) : name;
}

} // namespace detail



// normalize
template<
   template<class...> class MCON,
   template<class...> class CCON
>
void Node<MCON,CCON>::normalize()
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