
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

   // default
   // move
   Tree() { }
   Tree(Tree &&) = default;

   // xml, json
   explicit Tree(const xml  &xdoc) { convert(xdoc,*this); }
   explicit Tree(const json &jdoc) { convert(jdoc,*this); }

   // file, stream
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

   // copy
   Tree(const Tree &t)
   {
      convert(t,*this);
   }

   // templated "copy"
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

   // copy
   Tree &operator=(const Tree &t)
   {
      convert(t,*this);
      return *this;
   }

   // templated "copy"
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

// A couple of these are templated because we'd prefer not to say inline,
// and this is a header-only library. (Not that "inline" really means it.)

// warning_tree_io_name
template<class unused>
void warning_tree_io_name(
   const std::string &op,
   const std::string &file,
   const std::string &format,
   const std::string &name
) {
   warning(
      "Tree " + op + " called with "
      "format::" + format + " and "
      "filename \"" + file + "\",\n"
      "but the filename extension does not appear to be one for " +
       name + "."
   );
}

// warning_tree_io_data
template<class unused>
void warning_tree_io_data(
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

// format_tree_read
inline const std::string format_tree_read =
   "Format format::tree is not allowed in tree.read(). "
   "Our \"tree\" format\nis intended only for debug writing; "
   "it is not a first-class file format."
;

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
      error(detail::format_tree_read);
      return false;
   }

   // ------------------------
   // format::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   if (form == format::xml  && has_extension(file) && !endsin_xml (file))
      detail::warning_tree_io_name<char>("read", file, "xml",  "XML" );
   if (form == format::json && has_extension(file) && !endsin_json(file))
      detail::warning_tree_io_name<char>("read", file, "json", "Json");
   if (form == format::hdf5 && has_extension(file) && !endsin_hdf5(file))
      detail::warning_tree_io_name<char>("read", file, "hdf5", "HDF5");

   // ------------------------
   // Open and read
   // ------------------------

   std::ifstream ifs(file);
   if (!ifs)
      error("Could not open input file \"" + std::string(file) + "\"");

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
   // clear
   // Comment as in read(char *). Note that we need the clear() here, too,
   // because this function might be called directly, not via read(char *).
   clear();

   // ------------------------
   // format::tree
   // Not allowed in read
   // ------------------------

   // non-const; slightly simplifies some later logic
   format form = _form;

   if (form == format::tree) {
      error(detail::format_tree_read);
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
      else if (form != format::xml)
         detail::warning_tree_io_data<char>(
            form, "'<'", "XML");
   } else if (is.peek() == 137) {
      // looks like hdf5
      if (form == format::null)
         form = format::hdf5;
      else if (form != format::hdf5)
         detail::warning_tree_io_data<char>(
            form, "char 137", "HDF5");
   } else {
      // looks like json (via process of elimination)
      if (form == format::null)
         form = format::json;
      else if (form != format::json)
         detail::warning_tree_io_data<char>(
            form, "neither '<' nor char 137", "Json");
   }

   // The above logic is such that form cannot henceforth be format::tree,
   // which would have triggered a return, or format::null, which would have
   // become one of {xml,json,hdf5} somewhere in the above conditional.

   // ------------------------
   // Read and convert
   // ------------------------

   // Obey form, independent of whatever might or might not have been warned
   // about above. Note that if the original form parameter was format::null,
   // then form would have been modified, above, to the likely correct format,
   // based on the peek() calls.
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
   } else if (form == format::hdf5) {
      error("HDF5 read() is not implemented yet");
   } else {
      // we may or may not want slippery-slope stuff like this
      internal("Unrecognized form = " + std::to_string(int(form)) + " "
               "in tree.read()");
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
bool Tree<MCON,CCON>::write(
   const char * const file,
   const format _form
) const {

   // ------------------------
   // format::null
   // Decide from file name
   // ------------------------

   format form = _form;
   if (form == format::null) {
      if (endsin_xml (file))
         form = format::xml;
      else if (endsin_json(file))
         form = format::json;
      else if (endsin_hdf5(file))
         form = format::hdf5;
      else
         form = format::tree;
   }

   // ------------------------
   // format::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   if (form == format::xml  && has_extension(file) && !endsin_xml (file))
      detail::warning_tree_io_name<char>("write", file, "xml",  "XML" );
   if (form == format::json && has_extension(file) && !endsin_json(file))
      detail::warning_tree_io_name<char>("write", file, "json", "Json");
   if (form == format::hdf5 && has_extension(file) && !endsin_hdf5(file))
      detail::warning_tree_io_name<char>("write", file, "hdf5", "HDF5");

   // ------------------------
   // Open and write
   // ------------------------

   std::ofstream ofs(file);
   if (!ofs)
      error("Could not open output file \"" + std::string(file) + "\"");

   // Call write(ostream), below, to do the remaining work.
   return !write(ofs,form).fail();
}



// write(ostream, format)
template<
   template<class...> class MCON,
   template<class...> class CCON
>
std::ostream &Tree<MCON,CCON>::write(
   std::ostream &os,
   const format form
) const {

   // Discussion.
   //
   // This function might have been called through the filename write(); OR,
   // might have been called directly by a user, or possibly called through
   // the << stream output operator.
   //
   // In the former case, a filename was given, and thus the earlier function
   // had the opportunity to examine the filename and, if applicable, make a
   // smart decision - based on the filename extension - of what output format
   // the user would like. That decision would have been forwarded to here.
   //
   // In the latter cases, only an ostream is involved, and there's neither
   // a filename whose extension can be examined, nor an existing file (that
   // we care about, at least - we're doing *output*) whose first character
   // we can peek() in order to guess at the file type. We therefore have our
   // else { } catchall, below, write the tree in our basic tree-output form,
   // whether format::null or format::tree arrived as the format. An argument
   // could be made that write(ostream,format) should require that a format
   // be given, considering that we don't, here, have a file or filename to
   // examine. On the other hand, we like having format be optional, to make
   // our various tree I/O functions be as consistent with one another as
   // possible. Note, also, that if the user calls operator<<, then there's
   // no opportunity to explicitly provide a format.

   if (form == format::xml) {
      // write via a temporary xml object...
      gnds::xml(*this).write(os);
   } else if (form == format::json) {
      // write via a temporary json object...
      gnds::json(*this).write(os);
   } else if (form == format::hdf5) {
      // write via a temporary hdf5 object...
      error("HDF5 write() is not implemented yet");
   } else {
      // default, or our internal tree format
      if (root) root->write(os,0);
   }

   if (!os)
      error("Could not write to output stream");
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
