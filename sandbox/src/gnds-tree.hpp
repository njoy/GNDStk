
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

   // ctor: gnds::xml, gnds::json
   tree(const gnds::xml  &xdoc) { convert(xdoc,*this); }
   tree(const gnds::json &jdoc) { convert(jdoc,*this); }

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

   const std::string &meta(const std::string &key) const;

   template<class T>
   decltype(auto) meta(const gnds::meta_t<T> &m) const;

   const node &child(const std::string &name) const;

   template<class T>
   const node &child(const gnds::child_t<T> &c) const;

   template<class T>
   const node &operator()(const gnds::child_t<T> &c) const;

   template<class T, class... Ts>
   decltype(auto) operator()(T &&t, Ts &&...ts) const; // fixme Have SFINAE

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
      // go through a temporary gnds::xml object to create the tree...
      const gnds::xml x(is);
      if (!is.fail())
         convert(x, *this);
   } else {
      // assume .json
      // go through a temporary gnds::json object to create the tree...
      const gnds::json j(is);
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

// helper: detail::strip
void strip(std::string &name)
{
   int n = 0, ch; const int size = name.size();
   while (n < size && (isdigit(ch=name[n]) || isspace(ch)))
      n++;
   if (n)
      name = std::string(&name[n]);
}



// helper: detail::normalize
void normalize(gnds::node &node)
{
   // name
   strip(node.name());

   // Sanity check. If the current node has a child node named "attributes",
   // then that presumably means that the node originally had *that* child
   // node's metadata as its own, before they were embedded down into a
   // child named "attributes" for the purpose of writing, say, to a .json
   // file. And, now, we've presumably read such a file back in, and are
   // trying to restore the present node's original form. So, here, we're
   // looking to see if an "attributes" child exists, and if it does, then
   // this node shouldn't at present have any of its own metadata (until we
   // restore that data from the "attributes" node). And, we'll also ensure
   // that we have at most one "attributes" node; more than that should not
   // have been created in the first place.
   bool attr = false;
   for (auto &child : node.children()) {
      strip(child->name());
      if (child->name() == "attributes") {
///         assert(false);
         assert(attr == false);
         attr = true;
      }
   }

   /*
   bool attr = false;
   for (auto iter = node.children().begin();
        iter != node.children().end();  ++iter) {
      if ((*iter)->name() == "attributes") {
         assert(attr == false);
         attr = true;
      }
   }
   */

   // metadata
   for (auto &meta : node.metadata()) {
      assert(attr == false); // see remark above
      strip(meta.first);
   }

   // children
   for (auto &child : node.children()) {
      if (child->name() == "attributes") {
         // such a child shouldn't have its own
         assert(child->children().size() == 0);

         // hoist the metadata
         for (auto &m : child->metadata()) {
            ///            assert(false);
            ///zzz;
            ///node.metadata().push(m);
            strip(m.first);
            ///std::cout << m.first << std::endl;
            node.push(m.first,m.second);
         }


      } else {
         normalize(*child);
      }
   }

   for (auto iter = node.children().begin();
        iter != node.children().end(); ++iter) {
      if ((*iter)->name() == "attributes") {
         node.children().erase(iter);
         break;
      }
   }
}

} // namespace detail



// normalize
inline void tree::normalize()
{
   if (!root)
      return;
   detail::normalize(*root);
}
