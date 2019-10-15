
//#include "knoop.hpp"
#include "json.hpp"
#include "pugixml.hpp"

#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>



// -----------------------------------------------------------------------------
// misc / helpers
// -----------------------------------------------------------------------------

// printvar
#define printvar(var) std::cout << #var ": [" << var << "]" << std::endl



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

// endsin: helper
// C++20 will have an ends_with(); I'll just do it directly for now
inline bool endsin(const std::string &str, const std::string &end)
{
   return str.size() >= end.size() && &str[str.size()-end.size()] == end;
}

} // namespace gnds



// -----------------------------------------------------------------------------
// gnds::generic
// -----------------------------------------------------------------------------

namespace gnds {

// forward
   class xml;
   class json;
   class generic;
   bool convert(const xml  &from, generic &to);
   bool convert(const json &from, generic &to);

class generic {
public:
   class node;
   using metadata_t = std::vector<std::pair<std::string,std::string>>;
   using children_t = std::vector<node *>;

   // ------------------------
   // node - begin
   // ------------------------

   class node {
   public:
      // data
      std::string name;
      metadata_t metadata;
      children_t children;

      // dtor
     ~node()
      {
         for (auto &cptr : children) {
            delete cptr;
            cptr = nullptr;
            debug("delete node");
         }
      }

      // leaf
      // true iff this is a leaf node
      bool leaf() const
      {
         return children.size() == 0;
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
      debug("delete ROOT");
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
// gnds::xml
// Wraps pugi::xml_document
// -----------------------------------------------------------------------------

namespace gnds {

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
   bool read(const std::string &filename)
   {
      return read(filename.c_str());
   }

   // write
   std::ostream &write(std::ostream &) const;

}; // class xml

} // namespace gnds



// -----------------------------------------------------------------------------
// gnds::json
// Wraps nlohmann::json
// -----------------------------------------------------------------------------

namespace gnds {

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
   bool read(const std::string &filename)
   {
      return read(filename.c_str());
   }

   // write
   std::ostream &write(std::ostream &) const;

}; // class json

} // namespace gnds



// -----------------------------------------------------------------------------
// read xml
// read json
// -----------------------------------------------------------------------------

namespace gnds {

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
      std::cout << "Error loading file: " << filename << std::endl;
      std::cout << "Parse error: " << load.description() << std::endl;
      std::cout << "Character offset: " << load.offset << std::endl;
      return false;
   }

   // success
   return true;
}



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

} // namespace gnds



// -----------------------------------------------------------------------------
// write generic::node
// write generic
// write xml
// write json
// -----------------------------------------------------------------------------

namespace gnds {

// generic::node
void generic::node::write(std::ostream &os, const int indentlevel) const
{
   // indentation strings
   const std::string icurr(indent* indentlevel   ,' ');
   const std::string inext(indent*(indentlevel+1),' ');

   // name
   os << icurr << name << ":" << std::endl;

   // metadata
   for (const auto &meta : metadata)
      os << inext << meta.first << ": " << meta.second << std::endl;

   // children
   for (const auto &cptr : children)
      if (cptr)
         cptr->write(os,indentlevel+1);
}

// generic
std::ostream &generic::write(std::ostream &os) const
{
   if (root)
      root->write(os,0);
   return os;
}



// xml
std::ostream &xml::write(std::ostream &os) const
{
   doc.save(os, std::string(indent,' ').c_str());
   return os;
}

// json
std::ostream &json::write(std::ostream &os) const
{
   os << std::setw(indent) << doc << std::endl;
   return os;
}

} // namespace gnds



// -----------------------------------------------------------------------------
// convert: xml to generic
// -----------------------------------------------------------------------------

namespace gnds {

// helper: pugi::xml_node to generic::node
bool convert(const pugi::xml_node &from, generic::node &to)
{
   // name
   to.name = from.name();

   // metadata
   for (const pugi::xml_attribute &meta : from.attributes())
      to.metadata.push_back(std::make_pair(meta.name(), meta.value()));

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
      // XML markup. This may give us a fighting chance to correctly read/parse
      // a gnds::generic object.

      // comment
      if (sub.type() == pugi::node_comment) {
         static const std::string prefix = "<!--";
         static const std::string suffix = "-->";
         to.metadata.push_back(std::make_pair(prefix, sub.value()+suffix));
         continue;
      }

      // CDATA
      if (sub.type() == pugi::node_cdata) {
         // docs talk about using text(); let's ensure that the following
         // two give the same result...
         assert(sub.value() == sub.text().get());

         static const std::string prefix = "![CDATA[";
         static const std::string suffix = "]]";
         to.metadata.push_back(std::make_pair(prefix, sub.value()+suffix));
         continue;
      }

      // PCDATA
      // This isn't an XML tag (e.g. with "![PCDATA["), like CDATA is, but I'll
      // mark it as such in our generic format, to reflect the pugi XML reader's
      // identification of this as being the type.
      if (sub.type() == pugi::node_pcdata) {
         assert(sub.value() == sub.text().get());

         static const std::string prefix = "![PCDATA[";
         static const std::string suffix = "]]";
         to.metadata.push_back(std::make_pair(prefix, sub.value()+suffix));
         continue;
      }

      // ------------------------
      // Regular element
      // ------------------------

      assert(sub.type() == pugi::node_element);
      debug("new node");
      to.children.push_back(new generic::node);
      if (!convert(sub,*to.children.back()))
         return false;
   }

   // done
   return true;
}



bool convert(const xml &from, generic &to)
{
   // prepare output
   to.clear();

   int count = 0;
   for (const pugi::xml_node &xnode : from.doc.children()) {
      if (count == 0) {
         // expect the following, given that we called load_file()
         // with pugi::parse_declaration |d in its second argument
         assert(xnode.name() == std::string("xml"));

         // in our generic structure, the following at root level
         // indicates that we came from an xml
         debug("new ROOT");
         to.root = new generic::node;
         to.root->name = "xml";

         // base document "attributes": stuff like version and encoding
         for (const pugi::xml_attribute &meta : xnode.attributes())
            to.root->metadata.push_back(
               std::make_pair(meta.name(), meta.value())
            );
      }

      if (count == 1) {
         // visit the document's nodes
         debug("new node");
         to.root->children.push_back(new generic::node);
         if (!convert(xnode,*to.root->children.back()))
            return false;
      }

      // a proper XML document should contain just one outer node; we expect
      // two (but no more) only because we loaded the file with a flag that
      // said to include the enclosing "xml" material as part of the deal
      if (count >= 2)
         assert(false);
      count++;
   }
   assert(count == 2);

   // done
   return true;
}

} // namespace gnds



// -----------------------------------------------------------------------------
// convert: json to generic
// -----------------------------------------------------------------------------

namespace gnds {

// helper: nlohmann::json::const_iterator to generic::node
bool convert(const nlohmann::json::const_iterator &from, generic::node &to)
{
   assert(from->is_object());
   to.name = from.key();

   // visit the node's subnodes
   const nlohmann::json &value = from.value();
   for (auto sub = value.begin(); sub != value.end(); ++sub) {
      if (!sub->is_object()) {
         to.metadata.push_back(
            std::make_pair(
               sub.key(),
               sub->get<std::string>()
            )
         );
      } else {
         debug("new node");
         to.children.push_back(new generic::node);
         if (!convert(sub,*to.children.back()))
            return false;
      }
   }

   // done
   return true;
}



bool convert(const json &from, generic &to)
{
   // prepare output
   to.clear();

   // in our generic structure, the following at root level
   // indicates that we came from a json
   debug("new ROOT");
   to.root = new generic::node;
   to.root->name = "json";

   // visit the document's nodes
   for (auto elem = from.doc.begin();  elem != from.doc.end();  ++elem) {
      debug("new node");
      to.root->children.push_back(new generic::node);
      if (!convert(elem,*to.root->children.back()))
         return false;
   }

   // done
   return true;
}

} // namespace gnds



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main(const int argc, const char * const * const argv)
{
   for (int i = 1;  i < argc;  ++i) {
      // file name
      const std::string filename = argv[i];

      // for now, let's not bother with files above some arbitrary size
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
         // convert to our generic type...
         for (int timing = 0;  timing < 10;  ++timing)
            gnds::generic g(x);

      // json?
      } else if (gnds::endsin(argv[i],".json")) {
         std::cout << "Loading Json file \"" << filename << "\"" << std::endl;
         gnds::json j(filename);
         // convert to our generic type...
         for (int timing = 0;  timing < 10;  ++timing)
            gnds::generic g(j);

      // unknown file type
      } else {
         std::cout
            << "Skipping file \"" << filename << "\" (unknown type)"
            << std::endl;
      }
   }

#if 0
   (void)argc;
   (void)argv;

   gnds::xml  xml ("19.xml" );
   gnds::json json("19.json");

   /*
   // write
   xml .write(std::cout);
   json.write(std::cout);
   */

   {
      gnds::generic g;
      gnds::convert(xml,g);
      g.write(std::cout);
   }

   std::cout << "================================================" << std::endl;

   {
      gnds::generic g;
      gnds::convert(json,g);
      g.write(std::cout);
   }

   std::cout << "================================================" << std::endl;

   gnds::generic(xml ).write(std::cout);
   gnds::generic(json).write(std::cout);

   /*
   // xml
   gnds::xml xml;
   for (int a = 1;  a < argc;  ++a)
      xml.read(argv[a]);

   const std::string filename = "ENDF-VIII.gnds/neutrons/n-009_F_019.xml";
   gnds::xml xml(filename);
   */
#endif

}
