
// -----------------------------------------------------------------------------
// tree
// -----------------------------------------------------------------------------

class tree {
public:

   // data
   std::unique_ptr<node> root;

   // clear
   void clear()
   {
      // smart pointer, so the rest of the tree is deleted as well
      root = nullptr;
   }

   // ctor: default
   tree() { }

   // ctor: xml, json
   tree(const xml  &xdoc) { convert(xdoc,*this); }
   tree(const json &jdoc) { convert(jdoc,*this); }

   // ctor: file, stream
   tree(const char * const file) { read(file); }
   tree(const std::string &file) { read(file); }
   tree(std::istream &is) { read(is); }

   // read
   bool read(const char * const file);
   bool read(const std::string &file) { return read(file.c_str()); }
   std::istream &read(std::istream &);

   // write
   bool write(const char * const file) const;
   bool write(const std::string &file) const { return write(file.c_str()); }
   std::ostream &write(std::ostream &) const;

   // normalize
   void normalize();


   // ------------------------
   // shorthand data access:
   // meta, child, operator()
   // ------------------------

   decltype(auto) meta(const std::string &str) const;

   template<class T>
   decltype(auto) meta(const meta_t<T> &keyword) const;

   decltype(auto) child(const std::string &str) const;

   template<class T>
   decltype(auto) child(const child_t<T> &keyword) const;

   template<class T>
   decltype(auto) operator()(const meta_t<T> &keyword) const;

   template<class T>
   decltype(auto) operator()(const child_t<T> &keyword) const;

   template<class T, class... Ts>
   decltype(auto) operator()(const meta_t <T> &keyword, Ts &&...ts) const;
   template<class T, class... Ts>
   decltype(auto) operator()(const child_t<T> &keyword, Ts &&...ts) const;

}; // class tree



// -----------------------------------------------------------------------------
// read
// -----------------------------------------------------------------------------

// read(char *)
inline bool tree::read(const char * const file)
{
   // Note that this function makes use of the read(istream) function directly
   // below. That function peeks at the first character to decide whether it's
   // an xml or a json file. Alternatively, because we have the file *name* in
   // the present function, we could guess the file type by looking at any file
   // extension it has. However, I'll predict that the below function's decision
   // will get the right answer, if the right answer exists.

   // calls read(istream) below
   std::ifstream ifs(file);
   return !read(ifs).fail();
}


// read(istream)
inline std::istream &tree::read(std::istream &is)
{
   // Chuck current contents. Note that this will happen even
   // if the below read fails, which is a reasonable behavior.
   // Empty tree == reminder that the attempt to read failed!
   clear();

   // guess xml/json, then read and convert
   if (is.peek() == '<') {
      // assume .xml
      // go through a temporary xml object to create the tree...
      const xml x(is);
      if (!is.fail())
         convert(x, *this);
   } else {
      // assume .json
      // go through a temporary json object to create the tree...
      const json j(is);
      // It would seem that the nlohmann::json stream input operation,
      // which is used by the constructor we just called, sets failbit
      // in instances in which it should just set eofbit!! So, we'll
      // comment-out the !is.fail() test... :-/
      // if (!is.fail())
      convert(j, *this);
   }

   // done
   return is;
}


// operator>>
inline std::istream &operator>>(std::istream &is, tree &obj)
{
   // calls read(istream) above
   return obj.read(is);
}



// -----------------------------------------------------------------------------
// write
// -----------------------------------------------------------------------------

// write(char *)
inline bool tree::write(const char * const file) const
{
   // calls write(ostream) below
   std::ofstream ofs(file);
   return !write(ofs).fail();
}


// write(ostream)
inline std::ostream &tree::write(std::ostream &os) const
{
   return root ? detail::write(*root,os,0) : os;
}


// operator<<
inline std::ostream &operator<<(std::ostream &os, const tree &obj)
{
   // calls write(ostream) above
   return obj.write(os);
}



// -----------------------------------------------------------------------------
// normalize
// -----------------------------------------------------------------------------

namespace detail {

// helper: strip
inline std::string &strip(std::string &name)
{
   int n = 0, ch; const int size = name.size();
   while (n < size && (isdigit(ch=name[n]) || isspace(ch)))
      n++;
   return n ? (name = std::string(&name[n])) : name;
}

// helper: normalize
template<class NODE>
void normalize(NODE &node)
{
   // name
   strip(node.name());

   // children
   auto iter = node.children().end();
   for (auto c = node.children().begin();  c != node.children().end();  ++c)
      if (strip((*c)->name()) == "attributes") {
         // Child node's name is "attributes"; this presumably means that the
         // current node originally had *that* child node's metadata as its
         // own, before they were placed into an "attributes" child for the
         // purpose of writing, say, to a .json file. Now, apparently, we've
         // just read such a file, and must restore the node's original form.

         // Under the circumstances, this node shouldn't (yet) have its own
         // metadata. They'll be pulled up from the "attributes" child, which
         // itself should have only those metadata (and not further children).
         assert(node.metadata().size() == 0);  // this node
         assert((*c)->children().size() == 0); // child's children

         // And, there should have been at most one such "attributes" child.
         assert(iter == node.children().end()); // up until now
         iter = c; // now

         // Restore the metadata
         for (auto &m : (*c)->metadata())
            node.push(m.first,m.second);

      } else if (endsin((*c)->name(), "_attr")) {
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
         normalize(**c);
      }

   // chuck any "attributes" child
   if (iter != node.children().end())
      node.children().erase(iter);

   // metadata (including any new ones from an "attributes" child as above)
   for (auto &meta : node.metadata())
      strip(meta.first);
}

} // namespace detail



// normalize
inline void tree::normalize()
{
   if (root)
      detail::normalize(*root);
}