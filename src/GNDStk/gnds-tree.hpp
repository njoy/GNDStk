
// -----------------------------------------------------------------------------
// Tree (templated)
// tree = Tree<>
// -----------------------------------------------------------------------------

template<
   template<class...> class MCON, // metadata container
   template<class...> class CCON  // children container
>
class Tree {
public:

   // ------------------------
   // Data
   // ------------------------

   // root
   std::shared_ptr<Node<MCON,CCON>> root;


   // ------------------------
   // Miscellaneous functions
   // ------------------------

   // clear
   void clear()
   {
      // smart pointer, so the rest of the tree is deleted as well
      root = nullptr;
   }

   // empty
   bool empty() const
   {
      return root == nullptr;
   }

   // normalize
   void normalize()
   {
      if (root)
         root->normalize();
   }


   // ------------------------
   // Constructors
   // ------------------------

   // ctor: default
   Tree() { }

   // ctor: xml, json
   explicit Tree(const xml  &xdoc) { convert(xdoc,*this); }
   explicit Tree(const json &jdoc) { convert(jdoc,*this); }

   // ctor: file, stream
   explicit Tree(
      const char * const file,
      const format form = format::null
   ) {
      read(file,form);
   }

   explicit Tree(
      const std::string &file,
      const format form = format::null
   ) {
      read(file,form);
   }

   explicit Tree(
      std::istream &is,
      const format form = format::null
   ) {
      read(is,form);
   }

   // copy ctor
   Tree(const Tree &t)
   {
      convert(t,*this);
   }

   // templated "copy ctor"
   template<
      template<class...> class MCONTO,
      template<class...> class CCONTO
   >
   explicit Tree(const Tree<MCONTO,CCONTO> &t)
   {
      convert(t,*this);
   }


   // ------------------------
   // Assignment
   // ------------------------

   // copy assignment
   Tree &operator=(const Tree &t)
   {
      convert(t,*this);
      return *this;
   }

   // templated "copy assignment"
   template<
      template<class...> class MCONTO,
      template<class...> class CCONTO
   >
   Tree &operator=(const Tree<MCONTO,CCONTO> &t)
   {
      convert(t,*this);
      return *this;
   }


   // ------------------------
   // read
   // ------------------------

   // char *
   bool read(
      const char * const file,
      const format form = format::null
   );

   // string
   bool read(
      const std::string &file,
      const format form = format::null
   ) {
      return read(file.c_str(),form);
   }

   // istream
   std::istream &read(
      std::istream &,
      const format form = format::null
   );


   // ------------------------
   // write
   // ------------------------

   // char *
   bool write(
      const char * const file,
      const format form = format::null
   ) const;

   // string
   bool write(
      const std::string &file,
      const format form = format::null
   ) const {
      return write(file.c_str(),form);
   }

   // ostream
   std::ostream &write(
      std::ostream &,
      const format form = format::null
   ) const;


   // ------------------------
   // shorthand data access:
   // meta, child, operator()
   // ------------------------

   // meta
   decltype(auto) meta(const std::string &) const;
   template<class T>
   decltype(auto) meta(const meta_t<T> &) const;

   // child
   decltype(auto) child(const std::string &) const;
   template<class T, class META, class CHILD>
   decltype(auto) child(const child_t<T,META,CHILD> &) const;

   // operator()
   template<class T>
   decltype(auto) operator()(const meta_t<T> &) const;
   template<class T, class META, class CHILD>
   decltype(auto) operator()(const child_t<T,META,CHILD> &) const;
   template<class T, class META, class CHILD, class... Ts>
   decltype(auto) operator()(const child_t<T,META,CHILD> &, Ts &&...) const;

}; // class Tree



// -----------------------------------------------------------------------------
// helpers
// -----------------------------------------------------------------------------

namespace detail {

// warning_tree_io_name
inline void warning_tree_io_name(
   const std::string &op,
   const std::string &file,
   const std::string &format,
   const std::string &name
) {
   warning(
      "Tree " + op + " called with "
      "format::" + format + " and "
      "filename \"" + file + "\",\n"
      "but the filename extension doesn't appear to be one for " +
       name + "."
   );
}

// warning_tree_io_data
inline void warning_tree_io_data(
   const format f,
   const std::string &ch,
   const std::string &name
) {
   const std::string form =
      f == format::xml  ? "xml"
    : f == format::json ? "json"
    : f == format::hdf5 ? "hdf5"
    : "?";

   warning(
      "Tree read called with "
      "format::" + form + ",\n"
      "but the file begins with " + ch + ", which suggests " +
       name + "."
   );
}

} // namespace detail



// -----------------------------------------------------------------------------
// read
// -----------------------------------------------------------------------------

// read(char *, format)
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool Tree<MCON,CCON>::read(
   const char * const file,
   const format form
) {
   // ------------------------
   // Clear current contents
   // ------------------------

   // Note that this happens even if something below fails. This is reasonable
   // behavior; an empty tree is a reminder that the read attempt failed.
   clear();

   // ------------------------
   // format::tree
   // Not allowed in read
   // ------------------------

   // Error; this format isn't allowed for read() (only for write())
   if (form == format::tree) {
      // fixme Error here; tree format is intended only for debug *writing*,
      // not for reading. It's not intended to be a full, working format.
      return false;
   }

   // ------------------------
   // format::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   if (form == format::xml  && has_extension(file) && !endsin_xml (file))
      detail::warning_tree_io_name("read", file, "xml",  "XML" );
   if (form == format::json && has_extension(file) && !endsin_json(file))
      detail::warning_tree_io_name("read", file, "json", "Json");
   if (form == format::hdf5 && has_extension(file) && !endsin_hdf5(file))
      detail::warning_tree_io_name("read", file, "hdf5", "HDF5");

   // ------------------------
   // Open and read
   // ------------------------

   std::ifstream ifs(file);
   if (!ifs) {
      // fixme Error here
   }

   // Call read(istream), below, to do the remaining work. Note that although
   // the filename isn't available any longer in that function, the function
   // can, and does, do additional checking (complimentary to what we already
   // did above), based on looking at the content we'll be attempting to read.
   return !read(ifs,form).fail();
}



// read(istream, format)
template<
   template<class...> class MCON,
   template<class...> class CCON
>
std::istream &Tree<MCON,CCON>::read(
   std::istream &is,
   const format _form
) {
   // non-const; slightly simplifies logic
   format form = _form;

   // clear; comment as in read(char *)
   clear();

   // ------------------------
   // format::tree
   // Not allowed in read
   // ------------------------

   if (form == format::tree) {
      // fixme Error here; tree format is intended only for debug writing,
      // it isn't a full, working format.
      // Oh...perhaps we should set is' bad and/or fail
      return is;
   }

   // ------------------------
   // format::xml,json,hdf5
   // Check: consistent
   // initial content?
   // ------------------------

   if (is.peek() == '<') {
      // looks like xml
      if (form == format::null)
         form = format::xml;
      if (form != format::xml)
         detail::warning_tree_io_data(form, "'<'", "XML");
   } else if (is.peek() == 137) {
      // looks like hdf5
      if (form == format::null)
         form = format::hdf5;
      if (form != format::hdf5)
         detail::warning_tree_io_data(form, "char 137", "HDF5");
   } else {
      // looks like json (via process of elimination)
      if (form == format::null)
         form = format::json;
      if (form != format::json)
         detail::warning_tree_io_data(form, "neither '<' nor char 137", "Json");
   }

   // Read and convert
   // Obey form, independent of what might or might not have been warned
   // about above. Note that if the original form parameter was format::null,
   // then form would have been modified, above, to the probable correct
   // format, based on the peek() code above.
   if (form == format::xml) {
      // assume .xml
      // go through a temporary xml object to create the tree...
      const xml tmp(is);
      if (!is.fail())
         convert(tmp, *this);
   } else if (form == format::json) {
      // assume .json
      // go through a temporary json object to create the tree...
      const json tmp(is);

      // It would seem that the nlohmann::json stream input operation,
      // which is used by the constructor we just called, sets failbit
      // in instances in which it should just set eofbit. So, for now,
      // we'll comment-out the !is.fail() test... :-/
      // if (!is.fail())
      convert(tmp, *this);
   } else {
      assert(form == format::hdf5);
      // fixme Duh, need to write something non-stupid here
      assert(false);
   }

   // done
   return is;
}



// operator>>
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline std::istream &operator>>(
   std::istream &is,
   Tree<MCON,CCON> &obj
) {
   // Call read(istream) above
   return obj.read(is);
}



// -----------------------------------------------------------------------------
// write
// -----------------------------------------------------------------------------

// write(char *, format)
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline bool Tree<MCON,CCON>::write(
   const char * const file,
   const format form
) const {

   // ------------------------
   // format::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   if (form == format::xml  && has_extension(file) && !endsin_xml (file))
      detail::warning_tree_io_name("write", file, "xml",  "XML" );
   if (form == format::json && has_extension(file) && !endsin_json(file))
      detail::warning_tree_io_name("write", file, "json", "Json");
   if (form == format::hdf5 && has_extension(file) && !endsin_hdf5(file))
      detail::warning_tree_io_name("write", file, "hdf5", "HDF5");

   // ------------------------
   // Open and write
   // ------------------------

   std::ofstream ofs(file);
   if (!ofs) {
      // fixme Error here
   }
   return !write(ofs,form).fail();
}



// write(ostream, format)
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline std::ostream &Tree<MCON,CCON>::write(
   std::ostream &os,
   const format form
) const {

   // format::xml?
   if (form == format::xml) {
      // write via a temporary xml object...
      gnds::xml(*this).write(os);
      return os;
   }

   // format::json?
   if (form == format::json) {
      // write via a temporary json object...
      gnds::json(*this).write(os);
      return os;
   }

   // else
   if (root) root->write(os,0);
   return os;
}



// operator<<
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline std::ostream &operator<<(
   std::ostream &os,
   const Tree<MCON,CCON> &obj
) {
   // Call write(ostream) above
   return obj.write(os);
}
