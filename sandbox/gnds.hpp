
#pragma once

#include "json.hpp"
#include "knoop.hpp"
#include "pugixml.hpp"

#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

#include "keyword.hpp"

// macro: printvar
#define printvar(var) std::cout << #var ": [" << var << "]" << std::endl



// -----------------------------------------------------------------------------
// misc / helpers
// -----------------------------------------------------------------------------

namespace gnds {

// indent
inline int indent = 3;


// debug
inline bool debug = false;

inline void debugmsg(const std::string &str)
{
   if (debug)
      std::cout << "debug: " << str << std::endl;
}


// filesize(char *)
inline std::ifstream::pos_type filesize(const char * const name)
{
   std::ifstream ifs(name, std::ifstream::ate | std::ifstream::binary);
   return ifs.tellg();
}

// filesize(string)
inline std::ifstream::pos_type filesize(const std::string &name)
{
   return filesize(name.c_str());
}


// endsin
// C++20 will have an ends_with(); I'll just do it directly for now
inline bool endsin(const std::string &str, const std::string &end)
{
   return str.size() >= end.size() && &str[str.size()-end.size()] == end;
}

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

   // standard ctor/assignment
   json() = default;
   json(const json &) = default;
   json(json &&) = default;
   json &operator=(const json &) = default;
   json &operator=(json &&) = default;

   // ctor(filename)
   json(const char * const filename) { read(filename); }
   json(const std::string &filename) { read(filename); }

   // read(filename)
   bool read(const char * const filename);
   bool read(const std::string &filename) { return read(filename.c_str()); }

   // write
   std::ostream &write(std::ostream &) const;

}; // class json



// ostream << gnds::json
inline std::ostream &operator<<(std::ostream &os, const json &obj)
{
   return obj.write(os);
}

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

   // standard ctor/assignment
   // The copy constructor and assignment are commented-out because
   // pugi::xml_document's respective elements are inaccessible.
   xml() = default;
   // xml(const xml &) = default;
   xml(xml &&) = default;
   // xml &operator=(const xml &) = default;
   xml &operator=(xml &&) = default;

   // ctor(filename)
   xml(const char * const filename) { read(filename); }
   xml(const std::string &filename) { read(filename); }

   // read(filename)
   bool read(const char * const filename);
   bool read(const std::string &filename) { return read(filename.c_str()); }

   // write
   std::ostream &write(std::ostream &) const;

}; // class xml



// ostream << gnds::xml
inline std::ostream &operator<<(std::ostream &os, const xml &obj)
{
   return obj.write(os);
}

} // namespace gnds



// -----------------------------------------------------------------------------
// gnds::knoop
// Internal representation, using knoop
// -----------------------------------------------------------------------------

namespace gnds {

// forward declarations
class knoop;
bool convert(const xml  &from, knoop &to);
bool convert(const json &from, knoop &to);


// gnds::knoop
class knoop {
public:

   // defined later
   class node;

   // data
   std::unique_ptr<node> root;

   // ctor: default
   knoop() { }

   // ctor: xml | json
   knoop(const xml  &x) { convert(x,*this); }
   knoop(const json &j) { convert(j,*this); }

   // clear
   void clear()
   {
      root = nullptr;
   }

   // write
   std::ostream &write(std::ostream &) const;

}; // class knoop



// ostream << gnds::knoop
inline std::ostream &operator<<(std::ostream &os, const knoop &obj)
{
   return obj.write(os);
}

} // namespace gnds



// -----------------------------------------------------------------------------
// gnds::knoop::node
// Helper for gnds::knoop
// -----------------------------------------------------------------------------

namespace gnds {

class knoop::node : public njoy::knoop::Node<
   std::string, // name
   std::vector<std::pair<std::string,std::string>>, // metadata
   std::vector<node *> // children
> {
   using name_t     = std::string;
   using metadata_t = std::vector<std::pair<std::string,std::string>>;
   using children_t = std::vector<node *>;

   // begin(), for brevity later
   decltype(auto) begin()       { return list().begin(); }
   decltype(auto) begin() const { return list().begin(); }

   using base = njoy::knoop::Node<name_t, metadata_t, children_t>;

public:

   // ctor: default
   node() : base(name_t{}, metadata_t{}, children_t{}) { }

   // accessors
   const auto &name    () const { return (    begin())->get<name_t    >(); }
   const auto &metadata() const { return (  ++begin())->get<metadata_t>(); }
   const auto &children() const { return (++++begin())->get<children_t>(); }
   auto &name    () { return (    begin())->get<name_t    >(); }
   auto &metadata() { return (  ++begin())->get<metadata_t>(); }
   auto &children() { return (++++begin())->get<children_t>(); }

   // push
   void push(const std::string &key, const std::string &value)
   {
      metadata().push_back(std::make_pair(key,value));
   }

   void push(node *const value)
   {
      children().push_back(value);
   }

   // leaf?
   bool leaf() const
   {
      return children().size() == 0;
   }

   // write
   void write(std::ostream &, const int indentlevel) const;

   // dtor
  ~node()
   {
      for (auto &cptr : children()) {
         delete cptr;    // <== still have raw pointer in knoop-based class
         cptr = nullptr; // <== to ensure deleted raw pointer can't be used
         debugmsg("delete node - knoop");
      }
   }

}; // class node

} // namespace gnds



// -----------------------------------------------------------------------------
// gnds::generic
// Internal representation, using our own lightweight class
// -----------------------------------------------------------------------------

namespace gnds {

// forward declarations
class generic;
bool convert(const xml  &from, generic &to);
bool convert(const json &from, generic &to);


// gnds::generic
class generic {
public:

   // defined later
   class node;

   // data
   std::unique_ptr<node> root;

   // ctor: default
   generic() { }

   // ctor: xml | json
   generic(const xml  &x) { convert(x,*this); }
   generic(const json &j) { convert(j,*this); }

   // clear
   void clear()
   {
      root = nullptr;
   }

   // write
   std::ostream &write(std::ostream &) const;

   // ------------------------
   // shorthand data access:
   // meta, child, operator()
   // ------------------------

   const std::string &meta(const std::string &key) const;
   template<class T>
   decltype(auto) meta(const gnds::meta<T> &m) const;
   const node &child(const std::string &name) const;
   const node &child(const gnds::child &c) const;
   const node &operator()(const gnds::child &c) const;
   template<class T, class... Ts>
   decltype(auto) operator()(T &&t, Ts &&...ts) const; // should have sfinae

}; // class generic



// ostream << gnds::generic
inline std::ostream &operator<<(std::ostream &os, const generic &obj)
{
   return obj.write(os);
}

} // namespace gnds



// -----------------------------------------------------------------------------
// gnds::generic::node
// Helper for gnds::generic
// -----------------------------------------------------------------------------

namespace gnds {

class generic::node {
public:

   // data
   std::string name_;
   std::vector<std::pair<std::string,std::string>> metadata_;
   std::vector<std::unique_ptr<node>> children_;

   // accessors
   const auto &name    () const { return name_    ; }
   const auto &metadata() const { return metadata_; }
   const auto &children() const { return children_; }
   auto &name    () { return name_    ; }
   auto &metadata() { return metadata_; }
   auto &children() { return children_; }

   // push
   void push(const std::string &key, const std::string &value)
   {
      metadata().push_back(std::make_pair(key,value));
   }

   void push(node *const value)
   {
      children().push_back(std::unique_ptr<node>(value));
   }

   // leaf?
   bool leaf() const
   {
      return children().size() == 0;
   }

   // write
   void write(std::ostream &, const int indentlevel) const;


   // ------------------------
   // meta()
   // ------------------------

   // 1. for string
   const std::string &meta(const std::string &key) const
   {
      for (auto &m : metadata())
         if (m.first == key)
            return m.second;
      // eventually do something better than this...
      assert(false);
      static std::string empty = "";
      return empty;
   }

   // 2. for meta<bool>
   bool meta(const gnds::meta<bool> &m) const
   {
      if (m.name == std::string("true" )) return true;
      if (m.name == std::string("false")) return false;
      assert(false);
      return false;
   }

   // 3. for meta<T>
   template<class T>
   T meta(const gnds::meta<T> &m) const
   {
      std::istringstream iss(meta(std::string(m.name)));
      T value;
      iss >> value;
      return value;
   }

   // 4. for meta<variant>
   // Caller must stipulate <T>
   template<class T, class... Vs>
   T meta(const gnds::meta<std::variant<Vs...>> &m) const
   {
      std::istringstream iss(meta(std::string(m.name)));
      T value;
      iss >> value;
      return value;
   }

   // 5. for meta<vector>
   // Return by value isn't ideal, performance-wise,
   // but we'll go with it for now
   template<class T>
   std::vector<T> meta(const gnds::meta<std::vector<T>> &m) const
   {
      std::istringstream iss(meta(std::string(m.name)));
      std::vector<T> value;
      T val;
      while (iss >> val)
         value.push_back(val);
      return value;
   }


   // ------------------------
   // child()
   // ------------------------

   // 6. for string
   const node &child(const std::string &name) const
   {
      for (auto &c : children())
         if (c != nullptr && c->name() == name)
            return *c;
      // eventually do something better than this...
      assert(false);
      static node empty{};
      return empty;
   }

   // 7. for child
   const node &child(const gnds::child &c) const
   {
      return child(std::string(c.name));
   }


   // ------------------------
   // operator()
   // ------------------------

   /*
   zzz

   (n) 1. const std::string &meta(const std::string &key) const;

   (x) 2. bool meta(const gnds::meta<bool> &m) const;
   (x) 3. template<class T>
   (x)    T meta(const gnds::meta<T> &m) const;
   (x) 4. template<class T, class... Vs>
   (x)    T meta(const gnds::meta<std::variant<Vs...>> &m) const;
   (x) 5. template<class T>
   (x)    std::vector<T> meta(const gnds::meta<std::vector<T>> &m) const;

   (n) 6. const node &child(const std::string &name) const;

   (x) 7. const node &child(const gnds::child &c) const;
   */

   // forwards to (2), (3), (4), or (5) above
   template<class T>
   decltype(auto) operator()(const gnds::meta<T> &m) const
   {
      return meta(m);
   }

   // forwards to (7) above
   // return type will actually always be const node &
   decltype(auto) operator()(const gnds::child &c) const
   {
      return child(c);
   }

   // multi-argument
   // should have sfinae to ensure T is meta or child as for above operator()s
   template<class T, class... Ts>
   decltype(auto) operator()(T &&t, Ts &&...ts) const
   {
      return (*this)(t)(std::forward<Ts>(ts)...);
   }

}; // class node

} // namespace gnds



// -----------------------------------------------------------------------------
// Definitions:
//    generic::meta()
//    generic::child()
//    generic::operator()()
// These appear to be somewhat redundant, and they all just defer down to the
// document's top-level child node. Figure out a good way to fold them down.
// Possibly, even have the top-level document type be implicitly convertible
// to its top-level node; then we may not need these at all. Be sure that
// whatever we do, we don't allow screwy usages that cause pages and pages of
// incomprehensible compiler gibberish to spew out.
// -----------------------------------------------------------------------------

// zzz

namespace gnds {

// ------------------------
// generic::meta()
// ------------------------

inline const std::string &generic::meta(const std::string &key) const
{
   assert(root != nullptr);
   return root->meta(key);
}

template<class T>
inline decltype(auto) generic::meta(const gnds::meta<T> &m) const
{
   assert(root != nullptr);
   return root->meta(m);
}

// ------------------------
// generic::child()
// ------------------------

inline const generic::node &generic::child(const std::string &name) const
{
   assert(root != nullptr);
   return root->child(name);
}

inline const generic::node &generic::child(const gnds::child &c) const
{
   assert(root != nullptr);
   return root->child(c);
}

// ------------------------
// generic::operator()()
// ------------------------

inline const generic::node &generic::operator()(const gnds::child &c) const
{
   assert(root != nullptr);
   return root->child(c);
}

template<class T, class... Ts>
inline decltype(auto) generic::operator()(T &&t, Ts &&...ts) const
{
   assert(root != nullptr);
   return (*root)(t)(std::forward<Ts>(ts)...);
}

} // namespace gnds



// -----------------------------------------------------------------------------
// read json
// read xml
// -----------------------------------------------------------------------------

namespace gnds {

// json
inline bool json::read(const char * const filename)
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
inline bool xml::read(const char * const filename)
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
// These just wrap, into a consistent interface, the write capabilities
// that the Json and XML libraries already have.
// -----------------------------------------------------------------------------

namespace gnds {

// json
inline std::ostream &json::write(std::ostream &os) const
{
   os << std::setw(indent) << doc << std::endl;
   return os;
}

// xml
inline std::ostream &xml::write(std::ostream &os) const
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
// For now I won't bother guaranteeing that NODE is one of those two things.
template<class NODE>
std::ostream &write(const NODE &node, std::ostream &os, const int indentlevel)
{
   // indentation
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
inline std::ostream &knoop::write(std::ostream &os) const
{
   return root ? detail::write(*root,os,0) : os;
}

// generic
inline std::ostream &generic::write(std::ostream &os) const
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
         to.push(sub.key(), sub->get<std::string>());
      } else {
         debugmsg("new node");
         to.push(new NODE);
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
   using NODE = typename TYPE::node;
   to.root = std::make_unique<NODE>();
   to.root->name() = "json";

   // visit the document's nodes
   for (auto elem = from.doc.begin();  elem != from.doc.end();  ++elem) {
      debugmsg("new node");
      to.root->push(new NODE);
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
      to.push(meta.name(), meta.value());

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
         to.push(prefix, sub.value()+suffix);
         continue;
      }

      // CDATA
      if (sub.type() == pugi::node_cdata) {
         // docs talk about using text(); let's ensure that the following
         // two give the same result...
         assert(sub.value() == sub.text().get());

         static const std::string prefix = "![CDATA[";
         static const std::string suffix = "]]";
         to.push(prefix, sub.value()+suffix);
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
         to.push(prefix, sub.value()+suffix);
         continue;
      }

      // ------------------------
      // Regular element
      // ------------------------

      assert(sub.type() == pugi::node_element);
      debugmsg("new node");
      to.push(new NODE);
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
      using NODE = typename TYPE::node;

      if (count == 0) {
         // expect the following, given that we called load_file()
         // with pugi::parse_declaration |d in its second argument
         assert(xnode.name() == std::string("xml"));

         // root's name "xml" indicates that we came from a xml
         to.root = std::make_unique<NODE>();
         to.root->name() = "xml";

         // base document "attributes": stuff like version and encoding
         for (const pugi::xml_attribute &meta : xnode.attributes())
            to.root->push(meta.name(), meta.value());
      }

      if (count == 1) {
         // visit the document's nodes
         debugmsg("new node");
         to.root->push(new NODE);
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

inline bool convert(const json &from, knoop   &to)
{ return detail::convert(from,to); }

inline bool convert(const json &from, generic &to)
{ return detail::convert(from,to); }

inline bool convert(const xml  &from, knoop   &to)
{ return detail::convert(from,to); }

inline bool convert(const xml  &from, generic &to)
{ return detail::convert(from,to); }

} // namespace gnds
