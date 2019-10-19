
#include "json.hpp"
#include "knoop.hpp"
#include "pugixml.hpp"

#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

// macro: printvar
#define printvar(var) std::cout << #var ": [" << var << "]" << std::endl



// -----------------------------------------------------------------------------
// misc / helpers
// -----------------------------------------------------------------------------

namespace gnds {

// indent
inline int indent = 3;


// line
inline void line()
{
   std::cout << std::endl;
}

// debug
inline void debug(const std::string &str)
{
   (void)str;
   //std::cout << "debug: " << str << std::endl;
}


// filesize(char *)
inline std::ifstream::pos_type filesize(const char * const filename)
{
   std::ifstream ifs(filename, std::ifstream::ate | std::ifstream::binary);
   return ifs.tellg();
}

// filesize(string)
inline std::ifstream::pos_type filesize(const std::string &filename)
{
   return filesize(filename.c_str());
}

// endsin
// C++20 will have an ends_with(); I'll just do it directly for now
inline bool endsin(const std::string &str, const std::string &end)
{
   return str.size() >= end.size() && &str[str.size()-end.size()] == end;
}

} // namespace gnds



// -----------------------------------------------------------------------------
// Classes based on external file-format libraries:
// gnds::json
// gnds::xml
// -----------------------------------------------------------------------------

namespace gnds {

// ------------------------
// gnds::json
// Wraps nlohmann::json
// ------------------------

class json {
public:

   // Note: The json object reorders name/value pairs lexicographically, instead
   // of preserving the order in which we add them. The json.hpp file says:
   // 
   //    @note The order name/value pairs are added to the object is *not*
   //    preserved by the library. Therefore, iterating an object may return
   //    name/value pairs in a different order than they were originally stored.
   //    In fact, keys will be traversed in alphabetical order as `std::map`
   //    with `std::less` is used by default. Please note this behavior conforms
   //    to [RFC 7159](http://rfc7159.net/rfc7159), because any order implements
   //    the specified "unordered" nature of JSON objects.
   //
   // OK, but I'd have liked to have a way to preserve the order. This could be
   // hacked in some way, I suppose. We'll see.

   // overall json document
   nlohmann::json doc;

   // ctor: default
   json() { }

   // ctor: char *
   // ctor: string
   json(const char * const filename) { read(filename); }
   json(const std::string &filename) { read(filename); }

   // read(filename)
   bool read(const char * const filename);
   bool read(const std::string &filename) { return read(filename.c_str()); }

   // write
   std::ostream &write(std::ostream &) const;

}; // class json



// ------------------------
// gnds::xml
// Wraps pugi::xml_document
// ------------------------

class xml {
public:
   // overall xml document
   pugi::xml_document doc;

   // ctor: default
   xml() { }

   // ctor: char *
   // ctor: string
   xml(const char * const filename) { read(filename); }
   xml(const std::string &filename) { read(filename); }

   // read(filename)
   bool read(const char * const filename);
   bool read(const std::string &filename) { return read(filename.c_str()); }

   // write
   std::ostream &write(std::ostream &) const;

}; // class xml

} // namespace gnds



// -----------------------------------------------------------------------------
// Internal representation, knoop-based:
// gnds::knoop
// -----------------------------------------------------------------------------

namespace gnds {

// forward declarations
class knoop;
bool convert(const xml  &from, knoop &to);
bool convert(const json &from, knoop &to);

// ------------------------
// gnds::knoop
// ------------------------

class knoop {
public:

   // ------------------------
   // node - begin
   // ------------------------

   class node : public njoy::knoop::Node<
      std::string, // name
      std::vector<std::pair<std::string,std::string>>, // metadata
      std::vector<node *> // children
   > {
      using name_t = std::string;
      using metadata_t = std::vector<std::pair<std::string,std::string>>;
      using children_t = std::vector<node *>;

   public:
      using base = njoy::knoop::Node<name_t, metadata_t, children_t>;

      // ctor: default
      node() : base(name_t{}, metadata_t{}, children_t{}) { }

      // begin(), for brevity
      decltype(auto) begin()       { return list().begin(); }
      decltype(auto) begin() const { return list().begin(); }

      // accessors
      const auto &name    () const { return (    begin())->get<name_t    >(); }
      const auto &metadata() const { return (  ++begin())->get<metadata_t>(); }
      const auto &children() const { return (++++begin())->get<children_t>(); }

      auto &name    () { return (    begin())->get<name_t    >(); }
      auto &metadata() { return (  ++begin())->get<metadata_t>(); }
      auto &children() { return (++++begin())->get<children_t>(); }

      // dtor
     ~node()
      {
         for (auto &cptr : children()) {
            delete cptr;
            cptr = nullptr;
            debug("delete node - knoop");
         }
      }

      // leaf?
      bool leaf() const
      {
         return children().size() == 0;
      }

      // write
      void write(std::ostream &, const int indentlevel) const;

   }; // class node

   // ------------------------
   // node - end
   // ------------------------

   // data
   node *root = nullptr;

   // ctor: default
   knoop() { }

   // ctor: xml
   // ctor: json
   knoop(const xml  &x) { convert(x,*this); }
   knoop(const json &j) { convert(j,*this); }

   // clear
   void clear()
   {
      delete root;
      root = nullptr;
      debug("delete ROOT - knoop");
   }

   // dtor
  ~knoop()
   {
      clear();
   }

   // write
   std::ostream &write(std::ostream &) const;

}; // class knoop

} // namespace gnds



// -----------------------------------------------------------------------------
// Internal representation, our own lightweight class:
// gnds::generic
// -----------------------------------------------------------------------------

namespace gnds {

// forward declarations
class generic;
bool convert(const xml  &from, generic &to);
bool convert(const json &from, generic &to);

// ------------------------
// gnds::generic
// ------------------------

class generic {
public:

   // ------------------------
   // node - begin
   // ------------------------

   class node {
   public:

      // data
      std::string name_;
      std::vector<std::pair<std::string,std::string>> metadata_;
      std::vector<node *> children_;

      // accessors
      const auto &name    () const { return name_    ; }
      const auto &metadata() const { return metadata_; }
      const auto &children() const { return children_; }

      auto &name    () { return name_    ; }
      auto &metadata() { return metadata_; }
      auto &children() { return children_; }

      // dtor
     ~node()
      {
         for (auto &cptr : children()) {
            delete cptr;
            cptr = nullptr;
            debug("delete node - generic");
         }
      }

      // leaf?
      bool leaf() const
      {
         return children().size() == 0;
      }

      // write
      void write(std::ostream &, const int indentlevel) const;

   }; // class node

   // ------------------------
   // node - end
   // ------------------------

   // data
   node *root = nullptr;

   // ctor: default
   generic() { }

   // ctor: xml
   // ctor: json
   generic(const xml  &x) { convert(x,*this); }
   generic(const json &j) { convert(j,*this); }

   // clear
   void clear()
   {
      delete root;
      root = nullptr;
      debug("delete ROOT - generic");
   }

   // dtor
  ~generic()
   {
      clear();
   }

   // write
   std::ostream &write(std::ostream &) const;

}; // class generic

} // namespace gnds



// -----------------------------------------------------------------------------
// read json
// read xml
// -----------------------------------------------------------------------------

namespace gnds {

// json
bool json::read(const char * const filename)
{
   // load the document
   std::ifstream ifs(filename);
   ifs >> doc;

   // check for errors
   if (ifs.bad())
      return false;

   // success
   return true;
}

// xml
bool xml::read(const char * const filename)
{
   // load the document
   pugi::xml_parse_result load = doc.load_file(
      filename,
      pugi::parse_default |
      pugi::parse_declaration |
      pugi::parse_comments
   );

   // check for errors
   if (load.description() != std::string("No error")) {
      std::cout << "Error loading file: " << filename           << std::endl;
      std::cout << "Parse error       : " << load.description() << std::endl;
      std::cout << "Character offset  : " << load.offset        << std::endl;
      return false;
   }

   // success
   return true;
}

} // namespace gnds



// -----------------------------------------------------------------------------
// write json
// write xml
// -----------------------------------------------------------------------------

namespace gnds {

// json
std::ostream &json::write(std::ostream &os) const
{
   os << std::setw(indent) << doc << std::endl;
   return os;
}

// xml
std::ostream &xml::write(std::ostream &os) const
{
   doc.save(os, std::string(indent,' ').c_str());
   return os;
}

} // namespace gnds



// -----------------------------------------------------------------------------
// write knoop
// write generic
// Those have consistent interfaces, so we can reuse some write() code...
// -----------------------------------------------------------------------------

namespace gnds {

namespace detail {

// Helper: write(NODE == knoop::node | generic::node)
// For now I won't bother guaranteeing that NODE is valid.
template<class NODE>
std::ostream &write(const NODE &node, std::ostream &os, const int indentlevel)
{
   // indentation strings
   const std::string icurr(indent* indentlevel   ,' ');
   const std::string inext(indent*(indentlevel+1),' ');

   // name
   os << icurr << node.name() << ":" << std::endl;

   // metadata
   for (const auto &meta : node.metadata())
      os << inext << meta.first << ": " << meta.second << std::endl;

   // children
   for (const auto &cptr : node.children())
      if (cptr)
         write(*cptr,os,indentlevel+1);

   return os;
}

} // namespace detail



// knoop
std::ostream &knoop::write(std::ostream &os) const
{
   return root ? detail::write(*root,os,0) : os;
}

// generic
std::ostream &generic::write(std::ostream &os) const
{
   return root ? detail::write(*root,os,0) : os;
}

} // namespace gnds



// -----------------------------------------------------------------------------
// Helpers for various convert() functions
// -----------------------------------------------------------------------------

namespace gnds {
namespace detail {

// Helper: convert(nlohmann::json::const_iterator ==> NODE)
// Where NODE == knoop::node | generic::node
template<class NODE>
bool convert(const nlohmann::json::const_iterator &from, NODE &to)
{
   assert(from->is_object());
   to.name() = from.key();

   // visit the node's subnodes
   const nlohmann::json &value = from.value();
   for (auto sub = value.begin();  sub != value.end();  ++sub) {
      if (!sub->is_object()) {
         to.metadata().push_back(
            std::make_pair(
               sub.key(),
               sub->get<std::string>()
            )
         );
      } else {
         debug("new node");
         to.children().push_back(new NODE);
         if (!convert(sub,*to.children().back()))
            return false;
      }
   }

   // done
   return true;
}



// Helper: convert(json ==> TYPE)
// Where TYPE == knoop | generic
template<class TYPE>
bool convert(const json &from, TYPE &to)
{
   // prepare output
   to.clear();

   // root's name "json" indicates that we came from a json
   debug("new ROOT");
   to.root = new typename TYPE::node;
   to.root->name() = "json";

   // visit the document's nodes
   for (auto elem = from.doc.begin();  elem != from.doc.end();  ++elem) {
      debug("new node");
      to.root->children().push_back(new typename TYPE::node);
      if (!detail::convert(elem,*to.root->children().back()))
         return false;
   }

   // done
   return true;
}



// Helper: convert(pugi::xml_node ==> NODE)
// Where NODE == knoop::node | generic::node
template<class NODE>
bool convert(const pugi::xml_node &from, NODE &to)
{
   // name
   to.name() = from.name();

   // metadata
   for (const pugi::xml_attribute &meta : from.attributes())
      to.metadata().push_back(std::make_pair(meta.name(), meta.value()));

   // children
   for (const pugi::xml_node &sub : from.children()) {

      // ------------------------
      // Not handled, for now...
      // ------------------------

      // I don't think that the following should ever appear in this context...
      if (sub.type() == pugi::node_document)
         assert(false);
      if (sub.type() == pugi::node_declaration)
         assert(false);

      // For now I won't handle these; let's ensure that we don't see them...
      if (sub.type() == pugi::node_null)
         assert(false);
      if (sub.type() == pugi::node_pi)
         assert(false);
      if (sub.type() == pugi::node_doctype)
         assert(false);

      // ------------------------
      // Comment, CDATA, PCDATA
      // ------------------------

      // We'll store these as metadata for the current element, as they aren't
      // really child elements in the usual XMl sense. Markup-wise, I'll use the
      // beginning XML markup as the key, and append, to the value, the ending
      // XML markup.

      // comment
      if (sub.type() == pugi::node_comment) {
         static const std::string prefix = "<!--";
         static const std::string suffix = "-->";
         to.metadata().push_back(std::make_pair(prefix, sub.value()+suffix));
         continue;
      }

      // CDATA
      if (sub.type() == pugi::node_cdata) {
         // docs talk about using text(); let's ensure that the following
         // two give the same result...
         assert(sub.value() == sub.text().get());

         static const std::string prefix = "![CDATA[";
         static const std::string suffix = "]]";
         to.metadata().push_back(std::make_pair(prefix, sub.value()+suffix));
         continue;
      }

      // PCDATA
      // This isn't an XML tag (e.g. with "![PCDATA["), like CDATA is, but I'll
      // mark it as such in the output format, to reflect the pugi XML reader's
      // identification of this as being the type.
      if (sub.type() == pugi::node_pcdata) {
         assert(sub.value() == sub.text().get());

         static const std::string prefix = "![PCDATA[";
         static const std::string suffix = "]]";
         to.metadata().push_back(std::make_pair(prefix, sub.value()+suffix));
         continue;
      }

      // ------------------------
      // Regular element
      // ------------------------

      assert(sub.type() == pugi::node_element);
      debug("new node");
      to.children().push_back(new NODE);
      if (!convert(sub,*to.children().back()))
         return false;
   }

   // done
   return true;
}



// Helper: convert(xml ==> TYPE)
// Where TYPE == knoop | generic
template<class TYPE>
bool convert(const xml &from, TYPE &to)
{
   // prepare output
   to.clear();

   int count = 0;
   for (const pugi::xml_node &xnode : from.doc.children()) {
      if (count == 0) {
         // expect the following, given that we called load_file()
         // with pugi::parse_declaration |d in its second argument
         assert(xnode.name() == std::string("xml"));

         // root's name "xml" indicates that we came from a xml
         debug("new ROOT");
         to.root = new typename TYPE::node;
         to.root->name() = "xml";

         // base document "attributes": stuff like version and encoding
         for (const pugi::xml_attribute &meta : xnode.attributes())
            to.root->metadata().push_back(
               std::make_pair(meta.name(), meta.value())
            );
      }

      if (count == 1) {
         // visit the document's nodes
         debug("new node");
         to.root->children().push_back(new typename TYPE::node);
         if (!detail::convert(xnode,*to.root->children().back()))
            return false;
      }

      // a proper XML document should contain just one outer node; we expect
      // two (but no more) only because we loaded the file with a flag that
      // said to include the <?xml ... ?> material as part of the deal
      if (count >= 2)
         assert(false);
      count++;
   }
   assert(count == 2);

   // done
   return true;
}

} // namespace detail
} // namespace gnds



// -----------------------------------------------------------------------------
// convert: (json|xml) to (knoop|generic)
// -----------------------------------------------------------------------------

namespace gnds {

bool convert(const json &from, knoop   &to) { return detail::convert(from,to); }
bool convert(const json &from, generic &to) { return detail::convert(from,to); }
bool convert(const xml  &from, knoop   &to) { return detail::convert(from,to); }
bool convert(const xml  &from, generic &to) { return detail::convert(from,to); }

} // namespace gnds



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

// helper: compare
void compare(const gnds::knoop &k, const gnds::generic &g)
{
   std::ostringstream strk;
   std::ostringstream strg;
   k.write(strk);
   g.write(strg);
   assert(strk.str() == strg.str());
}

// main
int main(const int argc, const char * const * const argv)
{
   /*
   // xml
   gnds::xml x("19.xml" );
   {
      std::ostringstream strk;
      std::ostringstream strg;
      gnds::knoop  (x).write(strk); // xml  ==> knoop   ==> write
      gnds::generic(x).write(strg); // xml  ==> generic ==> write
      assert(strk.str() == strg.str()); // results should be the same
   }

   // json
   gnds::json j("19.json");
   {
      std::ostringstream strk;
      std::ostringstream strg;
      gnds::knoop  (j).write(strk); // json ==> knoop   ==> write
      gnds::generic(j).write(strg); // json ==> generic ==> write
      assert(strk.str() == strg.str()); // results should be the same
   }
   */

   // ------------------------
   // Stress test
   // ------------------------

   // for timing...
   const int ntiming = 10;

   // command-line arguments...
   for (int i = 1;  i < argc;  ++i) {
      // file
      const std::string filename = argv[i];

      // skip if above some arbitrary size
      if (gnds::filesize(filename) > 100000000) {
         std::cout
            << "Skipping file \"" << filename << "\" (too long)"
            << std::endl;
         continue;
      }

      // xml?
      if (gnds::endsin(argv[i],".xml")) {
         std::cout << "Loading XML file \"" << filename << "\"" << std::endl;
         gnds::xml x(filename);
         // convert to our knoop and generic types...
         for (int count = ntiming;  count-- ; ) {
            gnds::knoop   k(x);
            gnds::generic g(x);
            compare(k,g);
         }

      // json?
      } else if (gnds::endsin(argv[i],".json")) {
         std::cout << "Loading Json file \"" << filename << "\"" << std::endl;
         gnds::json j(filename);
         // convert to our knoop and generic types...
         for (int count = ntiming;  count-- ; ) {
            gnds::knoop   k(j);
            gnds::generic g(j);
            compare(k,g);
         }

      // unknown type
      } else {
         std::cout
            << "Skipping file \"" << filename << "\" (unknown type)"
            << std::endl;
      }
   }
}
