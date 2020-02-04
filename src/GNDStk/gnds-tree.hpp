
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

   // data
   std::shared_ptr<Node<MCON,CCON>> root;

   // clear
   void clear()
   {
      // smart pointer, so the rest of the tree is deleted as well
      root = nullptr;
   }

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

   // copy assignment
   Tree &operator=(const Tree &t)
   {
      convert(t,*this);
      return *this;
   }

   // templated "copy ctor"
   template<
      template<class...> class MCONTO,
      template<class...> class CCONTO
   >
   Tree(const Tree<MCONTO,CCONTO> &t)
   {
      convert(t,*this);
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

   // read
   bool read(
      const char * const file,
      const format form = format::null
   );

   bool read(
      const std::string &file,
      const format form = format::null
   ) {
      return read(file.c_str(),form);
   }

   std::istream &read(
      std::istream &,
      const format form = format::null
   );

   // write
   bool write(
      const char * const file,
      const format form = format::null
   ) const;

   bool write(
      const std::string &file,
      const format form = format::null
   ) const {
      return write(file.c_str(),form);
   }

   std::ostream &write(
      std::ostream &,
      const format form = format::null
   ) const;

   // normalize
   void normalize()
   {
      if (root)
         root->normalize();
   }


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
// read
// -----------------------------------------------------------------------------

// read(char *, format)
template<
   template<class...> class MCON,
   template<class...> class CCON
>
inline bool Tree<MCON,CCON>::read(
   const char * const file,
   const format form
) {
   // Clear current contents. Note that this will happen even if something
   // below fails - which is reasonable behavior. Empty tree is a reminder
   // that the attempt to read failed.
   clear();

   // format::tree: not allowed for read() (it's for *output* only)
   if (form == format::tree) {
      // fixme Error here; tree format is intended only for debug writing,
      // it isn't a full, working format.
      return false;
   }

   // format::xml: warn if file name appears to be inconsistent w/XML
   if (form == format::xml) {
      if (!endsin(file,".xml") &&
          !endsin(file,".XML")
      ) {
         // fixme Warning here
      }
   }

   // format::json: warn if file name appears to be inconsistent w/JSON
   if (form == format::json) {
      if (!endsin(file,".jsn") && !endsin(file,".json") &&
          !endsin(file,".JSN") && !endsin(file,".JSON")
      ) {
         // fixme Warning here
      }
   }

   // Open file; error if fails
   std::ifstream ifs(file);
   if (!ifs) {
      // fixme Error here
   }

   // Call read(istream) below
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
   // non-const
   format form = _form;

   // clear; comment as above
   clear();

   // tree format: not allowed for read
   if (form == format::tree) {
      // fixme Error here; tree format is intended only for debug writing,
      // it isn't a full, working format.
      return is;
   }

   // Print a warning if the stipulated form, and the contents
   // of the file, appear to be inconsistent with one another.
   if (is.peek() == '<') {
      if (form == format::null)
         form = format::xml;
      if (form != format::xml) {
         // fixme Warning
      }
   } else {
      if (form == format::null)
         form = format::json;
      if (form != format::json) {
         // fixme Warning
      }
   }

   // guess xml/json, then read and convert
   if (form == format::xml) {
      // assume .xml
      // go through a temporary xml object to create the tree...
      const xml x(is);
      if (!is.fail())
         convert(x, *this);
   } else {
      // because of our own logic above
      assert(form == format::json);

      // assume .json
      // go through a temporary json object to create the tree...
      const json j(is);

      // It would seem that the nlohmann::json stream input operation,
      // which is used by the constructor we just called, sets failbit
      // in instances in which it should just set eofbit. So, for now,
      // we'll comment-out the !is.fail() test... :-/
      // if (!is.fail())
      convert(j, *this);
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
   // format::xml: warn if file name appears to be inconsistent w/XML
   if (form == format::xml) {
      if (!endsin(file,".xml") &&
          !endsin(file,".XML")
      ) {
         // fixme Warning here
      }
   }

   // format::json: warn if file name appears to be inconsistent w/JSON
   if (form == format::json) {
      if (!endsin(file,".jsn") && !endsin(file,".json") &&
          !endsin(file,".JSN") && !endsin(file,".JSON")
      ) {
         // fixme Warning here
      }
   }

   // Open file; error if fails
   std::ofstream ofs(file);
   if (!ofs) {
      // fixme Error here
   }

   // Call write(ostream) below
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
