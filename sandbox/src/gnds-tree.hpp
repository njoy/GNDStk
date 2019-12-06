
// -----------------------------------------------------------------------------
// tree
// -----------------------------------------------------------------------------

// convert: forward
class tree;
bool convert(const xml  &from, tree &to);
bool convert(const json &from, tree &to);


// tree
class tree {
public:

   // data
   std::unique_ptr<node> root;

   // clear
   void clear()
   {
      // smart pointer, so the rest of the tree is deleted too
      root = nullptr;
   }

   // ctor: default
   tree() { }

   // ctor: xml, json
   tree(const xml  &x) { convert(x,*this); }
   tree(const json &j) { convert(j,*this); }

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

   // ------------------------
   // shorthand data access:
   // meta, child, operator()
   // ------------------------

   const std::string &meta(const std::string &key) const;
   template<class T>
   decltype(auto) meta(const gnds::meta_t<T> &m) const;
   const node &child(const std::string &name) const;
   const node &child(const gnds::child_t &c) const;
   const node &operator()(const gnds::child_t &c) const;
   template<class T, class... Ts>
   decltype(auto) operator()(T &&t, Ts &&...ts) const; // should have sfinae

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
   // extension it has. However, I'll be so bold as to predict that the below
   // function's decision will get the right answer, if the right answer exists.

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
      // we go through an xml object to create the tree...
      xml x(is);
      if (is)
         convert(x, *this);
   } else {
      // assume .json
      // we go through a json object to create the tree...
      json j(is);
      if (is)
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
