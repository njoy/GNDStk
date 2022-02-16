
namespace detail {

// -----------------------------------------------------------------------------
// node2json
// -----------------------------------------------------------------------------

template<class NODE>
bool node2json(
   const NODE &node, nlohmann::ordered_json &j,
   const std::string &suffix = ""
) {
   // Original node name, and suffixed name. The latter is for handling child
   // nodes of the same name under the same parent node, and includes a numeric
   // suffix (so, name0, name1, etc.) in that scenario. This is needed for JSON
   // because JSON doesn't support same-named child nodes. In cases where the
   // name was unique to begin with, nameOriginal == nameSuffixed.
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + suffix;

   // Create new ordered_json in j
   nlohmann::ordered_json &json = j[nameSuffixed];

   // ------------------------
   // metadata ==> json
   // ------------------------

   if (suffix != "")
      json["#nodeName"] = nameOriginal;

   for (auto &meta : node.metadata)
      json["#attributes"][meta.first] = meta.second;

   // ------------------------
   // children ==> json
   // ------------------------

   // First, account for what children appear in the current node. If any child
   // name appears multiple times, we must deal with that. For each represented
   // child name, the map gets 0 if the name appears once, 1 if it appears more
   // than once. Later, this 0/1 is used initially to make a boolean choice;
   // then it serves as a counter to generate a 0-indexed numeric suffix that
   // makes the child names unique: name0, name1, etc.
   std::map<std::string,std::size_t> childNames;
   for (auto &c : node.children) {
      auto iter = childNames.find(c->name);
      if (iter == childNames.end())
         childNames.insert({c->name,0}); // once (so far)
      else
         iter->second = 1; // more than once
   }

   // now revisit and process the child nodes
   for (auto &c : node.children) {
      const std::size_t counter = childNames.find(c->name)->second++;
      if (!node2json(*c, json, counter ? std::to_string(counter-1) : ""))
         return false;
   }

   // done
   return true;
}



// -----------------------------------------------------------------------------
// xml2node
// -----------------------------------------------------------------------------

/*
FYI, here's the pugixml code for pugi::xml_node_type:

namespace pugi
{
   // Tree node types
   enum xml_node_type
   {
      node_null,        // Empty (null) node handle
      node_document,    // A document tree's absolute root
      node_element,     // Element tag, i.e. '<node/>'
      node_pcdata,      // Plain character data, i.e. 'foo'
      node_cdata,       // Character data, i.e. '<![CDATA[foo]]>'
      node_comment,     // Comment tag, i.e. '<!-- foo -->'
      node_pi,          // Processing instruction, i.e. '<?name?>'
      node_declaration, // Document declaration, i.e. '<?xml version="1.0"?>'
      node_doctype      // Document type declaration, i.e. '<!DOCTYPE doc>'
   };
}
*/

// Helper: error_xml2node
inline void error_xml2node(const std::string &type)
{
   log::error(
     "Internal error in xml2node(pugi::xml_node, Node):\n"
     "Type pugi::{} found, but not handled, as sub-element.",
      type
   );
   throw std::exception{};
}

// xml2node
// pugi::xml_node ==> Node
template<class NODE>
bool xml2node(const pugi::xml_node &xnode, NODE &node)
{
   static const std::string context =
      "xml2node(pugi::xml_node, Node)";

   // check destination node
   if (!node.empty()) {
      log::error(
         "Internal error in xml2node(pugi::xml_node, Node):\n"
         "Destination Node is supposed to arrive here empty, but didn't."
      );
      throw std::exception{};
   }

   // name
   node.name = xnode.name();

   // metadata
   for (const pugi::xml_attribute &xattr : xnode.attributes())
      node.add(xattr.name(), xattr.value());

   // children (sub-nodes)
   for (const pugi::xml_node &xsub : xnode) {

      // ------------------------
      // not handled right now
      // ------------------------

      // I don't think that the following should ever appear in this context
      if (xsub.type() == pugi::node_document)
         error_xml2node("node_document");
      if (xsub.type() == pugi::node_declaration)
         error_xml2node("node_declaration");

      // For now I won't handle these; let's ensure that we don't see them
      if (xsub.type() == pugi::node_null)
         error_xml2node("node_null");
      if (xsub.type() == pugi::node_pi)
         error_xml2node("node_pi");
      if (xsub.type() == pugi::node_doctype)
         error_xml2node("node_doctype");

      // ------------------------
      // element (typical case)
      // ------------------------

      if (xsub.type() == pugi::node_element) {
         try {
            if (!xml2node(xsub,node.add()))
               return false;
         } catch (...) {
            log::function(context);
            throw;
         }
         continue;
      }

      // ------------------------
      // cdata, pcdata, comment
      // ------------------------

      // We'll store these in a special manner as children of the current node,
      // reflecting how they arrived through pugi xml. Our manner of storing
      // them will allow us to maintain their original ordering if, say, someone
      // reads an XML, makes modest modifications or additions to data here and
      // there, and then writes an XML back out. GNDS has no ordering, so doing
      // this isn't necessary. It is, however, easy to handle, and users may
      // appreciate that GNDStk doesn't toss comments, or mess with the ordering
      // of cdata, pcdata, or comment nodes, either individually or together.
      // Of note, all bets are off if someone converts to JSON and back, because
      // the nlohmann JSON library reorders everything lexicographically.

      if (xsub.type() == pugi::node_cdata) {
         node.add("#cdata").add("#text", xsub.value());
         continue;
      }

      if (xsub.type() == pugi::node_pcdata) {
         node.add("#pcdata").add("#text", xsub.value());
         continue;
      }

      if (xsub.type() == pugi::node_comment) {
         node.add("#comment").add("#text", xsub.value());
         continue;
      }

      // ------------------------
      // well we missed something
      // ------------------------

      log::error(
         "Internal error in xml2node(pugi::xml_node, Node):\n"
         "Encountered a pugi:: node type that we don't know about."
      );
      throw std::exception{};
   }

   // done
   return true;
}



// -----------------------------------------------------------------------------
// json2node
// -----------------------------------------------------------------------------

// nlohmann::ordered_json::const_iterator ==> Node
// Why the iterator rather than the ordered_json object? I found that there
// were some seemingly funny semantics in the nlohmann JSON library. As we
// can see below, we have for example iter->is_object() (so, the -> operator,
// typical for iterators), but also iter.value() (the . operator - on an
// iterator). Similarly, also seen below, with the sub-elements. This is why
// we are, for now, writing our for-loops, here as well as in the functions
// that call this, in the older iterator form rather than the range-based-for
// form. Perhaps there's a way to reformulate all this in a shorter way, but
// this is what we have for now.

// Helper: error_json2node
inline void error_json2node(const std::string &message)
{
   log::error(
     "Internal error in json2node(nlohmann::ordered_json, Node):\n"
     "Message: \"{}\".",
      message
   );
   throw std::exception{};
}

// json2node
template<class NODE>
bool json2node(const nlohmann::ordered_json::const_iterator &iter, NODE &node)
{
   static const std::string context =
      "json2node(nlohmann::ordered_json::const_iterator, Node)";

   // the node sent here should be fresh, ready to receive entries...
   if (!node.empty())
      error_json2node("!node.empty()");

   // non-object cases should have been handled
   // before any caller calls this function...
   if (!iter->is_object())
      error_json2node("!iter->is_object()");

   // any "#attributes" key (a specially-named "child node" that we use in JSON
   // in order to identify attributes) should have been handled in the caller...
   if (iter.key() == "#attributes")
      error_json2node("iter.key() == \"#attributes\"");

   // key,value ==> node name, JSON value to bring in
   node.name = iter.key();
   const nlohmann::ordered_json &json = iter.value();

   // elements
   for (auto elem = json.begin();  elem != json.end();  ++elem) {
      if (elem.key() == "#nodeName") {
         // #nodeName? ...extract as current node's true name
         node.name = elem->get<std::string>();
      } else if (elem.key() == "#attributes") {
         // #attributes? ...extract as current node's metadata
         const auto &jsub = elem.value();
         for (auto attr = jsub.begin();  attr != jsub.end();  ++attr)
            node.add(attr.key(), attr->get<std::string>());
      } else if (elem->is_string()) {
         // string? ...extract as metadata key/value pair
         node.add(elem.key(), elem->get<std::string>());
      } else if (elem->is_object()) {
         // {} object? ...extract as normal child node
         try {
            if (!json2node(elem,node.add()))
               return false;
         } catch (...) {
            log::function(context);
            throw;
         }
      } else if (elem->is_null()) {
         // null node? ...extract as normal (albeit empty) child node
         // In GNDS, e.g. XML's <RutherfordScattering/> or <isotropic2d/>
         node.add().name = elem.key();
      } else {
         // no other cases are handled right now
         error_json2node("unhandled JSON value type");
      }
   }

   // done
   return true;
}



// -----------------------------------------------------------------------------
// HDF5-related helper functions
// -----------------------------------------------------------------------------

// scalarAttr
template<class T, class OBJECT>
HighFive::Attribute scalarAttr(
   const std::string &key, const std::string &value,
   OBJECT &hdf
) {
   T scalar;
   convert(value,scalar);
   return hdf.createAttribute(key,scalar);
}

// vectorAttr
template<class T, class OBJECT>
HighFive::Attribute vectorAttr(
   const std::string &key, const std::string &value,
   OBJECT &hdf
) {
   std::vector<T> vector;
   convert(value,vector);
   return hdf.createAttribute(key,vector);
}

// vecDataSet
template<class T, class OBJECT>
HighFive::DataSet vecDataSet(
   const std::string &key, const std::string &value,
   OBJECT &hdf
) {
   std::vector<T> vector;
   convert(value,vector);
   return hdf.createDataSet(key,vector);
}

// vecDataSet, w/ type string
template<class OBJECT>
HighFive::DataSet vecDataSet(
   const std::string &type,
   const std::string &key, const std::string &value,
   OBJECT &hdf
) {
   return
      type == "int"    || type == "ints"    ?
         vecDataSet<int          >(key,value,hdf) :
      type == "uint"   || type == "uints"   ?
         vecDataSet<unsigned     >(key,value,hdf) :
      type == "long"   || type == "longs"   ?
         vecDataSet<long         >(key,value,hdf) :
      type == "ulong"  || type == "ulongs"  ?
         vecDataSet<unsigned long>(key,value,hdf) :
      type == "double" || type == "doubles" ?
         vecDataSet<double       >(key,value,hdf) :
      // "string", "strings", or ""
         vecDataSet<std::string  >(key,value,hdf) ;
}



// -----------------------------------------------------------------------------
// typedHDF5
// -----------------------------------------------------------------------------

template<class NODE, class OBJECT>
void typedHDF5(const NODE &node, OBJECT &hdf)
{
   const std::string &parent = node.name;

   for (auto &meta : node.metadata) {
      const std::string &key = meta.first;
      const std::string &value = meta.second;
      const std::string type = detail::guessType(value);

      // *** #cdata/#text
      // *** #comment/#text
      // ACTION: Write these as-is. That is, do NOT apply our type-guessing code
      // to a comment, or to the contents of a <![CDATA[...]]> block like those
      // that we see in existing XML-format GNDS files. The type guesser would
      // see words, and think "vector of [whitespace-separated] strings," which
      // would be painfully wrong for what are clearly free-form strings.
      if (key == "#text" && (parent == "#cdata" || parent == "#comment")) {
         hdf.createAttribute(key,value); // just a simple string attribute
         continue;
      }

      // *** #pcdata/#text
      // ACTION: Apply our type-guessing code, but write *vectors* only, never
      // scalars. So, <values>10</values> would be interpreted as a vector with
      // one element, NOT as a scalar; while <values>10 20 30</values> would be
      // interpreted as a vector with three elements. What may look like scalars
      // are folded into vectors because we think that reflects what nodes like
      // this are intended to represent. (If something was really just a scalar,
      // then surely it would be placed in the metadata, not in a node such as
      // <values>scalar</values>.)
      if constexpr (std::is_same_v<OBJECT,HighFive::Group>) {
         if (key == "#text" && parent == "#pcdata") {
            vecDataSet(type,key,value,hdf);
            continue;
         }
      }

      // *** key/#text not expected except as already handled
      if (key == "#text") {
         log::warning("Metadatum name \"#text\" not expected here; "
                      "writing anyway");
         log::function("detail::typedHDF5(Node named \"{}\", ...)", parent);
      }

      // *** key/value
      // General case
      // ACTION: Apply our type-guessing code almost fully, except that for
      // a metadatum="that looks like this", interpret "..." as essentially
      // a single descriptive string. So, don't split it up into a vector.
      type == "int"     ? scalarAttr<int          >(key,value,hdf) :
      type == "ints"    ? vectorAttr<int          >(key,value,hdf) :
      type == "uint"    ? scalarAttr<unsigned     >(key,value,hdf) :
      type == "uints"   ? vectorAttr<unsigned     >(key,value,hdf) :
      type == "long"    ? scalarAttr<long         >(key,value,hdf) :
      type == "longs"   ? vectorAttr<long         >(key,value,hdf) :
      type == "ulong"   ? scalarAttr<unsigned long>(key,value,hdf) :
      type == "ulongs"  ? vectorAttr<unsigned long>(key,value,hdf) :
      type == "double"  ? scalarAttr<double       >(key,value,hdf) :
      type == "doubles" ? vectorAttr<double       >(key,value,hdf) :
      /* else........ */  scalarAttr<std::string  >(key,value,hdf) ;
   }
}



// -----------------------------------------------------------------------------
// Meta2HDF5
// -----------------------------------------------------------------------------

// Here, OBJECT hdf is either a HighFive::Group or a HighFive::DataSet
template<class NODE, class OBJECT>
void Meta2HDF5(const NODE &node, OBJECT &hdf, const std::string &suffix)
{
   // #nodeName if appropriate (as with JSON, allows recovery of original name)
   if (suffix != "")
      hdf.createAttribute(std::string("#nodeName"), node.name);

   // Existing attributes
   if (HDF5::typed) {
      // Use our "guess what's in the string" code to try to infer what certain
      // "string" values actually contain (a single int, say, or a vector of
      // doubles). Then, use the inferred types in the HDF5 file.
      typedHDF5(node,hdf);
   } else {
      // Write simple HDF5 where all data (metadata, and the content of "cdata"
      // and "pcdata" nodes) end up being strings. Not even vectors of strings
      // (as from <values>H He Li ...</values>), but single strings.
      for (auto &meta : node.metadata)
         hdf.createAttribute(meta.first, meta.second);
   }
}



// -----------------------------------------------------------------------------
// Node2HDF5
// -----------------------------------------------------------------------------

// Here, OBJECT hdf is either a HighFive::File or a HighFive::Group
template<class NODE, class OBJECT>
bool Node2HDF5(const NODE &node, OBJECT &hdf, const std::string &suffix = "")
{
   // As with JSON; see the comment in node2json()
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + suffix;

   if (
      HDF5::flat &&
      node.children.size() == 1 &&
      node.children[0]->name == "#pcdata" &&
      node.children[0]->metadata.size() == 1 &&
      node.children[0]->metadata[0].first == "#text"
   ) {
      // Create DataSet
      const std::string value = node.children[0]->metadata[0].second;
      const std::string type = detail::guessType(value);
      HighFive::DataSet dataset = vecDataSet(type,nameSuffixed,value,hdf);

      // Handle metadata, then done (there are no children)
      Meta2HDF5(node,dataset,suffix);
      return true;
   }

   // Create Group
   HighFive::Group group = hdf.createGroup(nameSuffixed);

   // Handle metadata
   Meta2HDF5(node,group,suffix);

   // ------------------------
   // children
   // ------------------------

   // Logic as with JSON; see the comment in node2json()
   std::map<std::string,std::size_t> childNames;
   for (auto &c : node.children) {
      auto iter = childNames.find(c->name);
      if (iter == childNames.end())
         childNames.insert({c->name,0}); // once (so far)
      else
         iter->second = 1; // more than once
   }

   // Now revisit and process the child nodes
   for (auto &c : node.children) {
      const std::size_t counter = childNames.find(c->name)->second++;
      if (!Node2HDF5(*c, group, counter ? std::to_string(counter-1) : ""))
         return false;
   }

   // Done
   return true;
}



// -----------------------------------------------------------------------------
// HDF5attr2Node
// For HighFive::Attribute
// -----------------------------------------------------------------------------

// Helper: attrTYPE2node
template<class T, class NODE>
bool attrTYPE2node(const HighFive::Attribute &attr, NODE &node)
{
   if (attr.getDataType() == HighFive::AtomicType<T>{}) {
      const std::string attrName = attr.getName();
      const std::size_t attrSize = attr.getSpace().getElementCount();

      // Scalar case. Includes bool.
      if (attrSize == 1) {
         T scalar;
         attr.read(scalar);
         node.add(attrName,scalar);
         return true;
      }

      // Vector case. EXcludes bool, as HighFive (perhaps HDF5 in general?)
      // doesn't appear to support it in this case. Indeed, the body of the
      // if-constexpr doesn't *compile* with bool. (Hence our if-constexpr.)
      if constexpr (!std::is_same_v<T,bool>) {
         std::vector<T> vector;
         vector.reserve(attrSize);
         attr.read(vector);
         node.add(attrName,vector);
         return true;
      }
   }

   return false;
}

// HDF5attr2Node
template<class NODE>
bool HDF5attr2Node(const HighFive::Attribute &attr, NODE &node)
{
   // HighFive's documentation leaves much to be desired. I used what I found
   // in HighFive/include/highfive/bits/H5DataType_misc.hpp to get an idea of
   // what attribute *types* are allowed. That file also had some handling of
   // C-style fixed-length strings, as with char[length], and std::complex as
   // well. It didn't have long double, which I'd have liked, but that's fine.
   // I won't bother with fixed-length strings or with std::complex right now,
   // but will support the rest.
   if (attrTYPE2node<char              >(attr,node)) return true;
   if (attrTYPE2node<signed char       >(attr,node)) return true;
   if (attrTYPE2node<unsigned char     >(attr,node)) return true;
   if (attrTYPE2node<short             >(attr,node)) return true;
   if (attrTYPE2node<unsigned short    >(attr,node)) return true;
   if (attrTYPE2node<int               >(attr,node)) return true;
   if (attrTYPE2node<unsigned          >(attr,node)) return true;
   if (attrTYPE2node<long              >(attr,node)) return true;
   if (attrTYPE2node<unsigned long     >(attr,node)) return true;
   if (attrTYPE2node<long long         >(attr,node)) return true;
   if (attrTYPE2node<unsigned long long>(attr,node)) return true;
   if (attrTYPE2node<float             >(attr,node)) return true;
   if (attrTYPE2node<double            >(attr,node)) return true;
   if (attrTYPE2node<bool              >(attr,node)) return true;
   if (attrTYPE2node<std::string       >(attr,node)) return true;

   log::error(
     "HDF5 Attribute \"{}\"'s DataType \"{}\" is not handled at this time.",
      attr.getName(), attr.getDataType().string());
   log::function("HDF5attr2Node(HighFive::Attribute, Node)");

   return false;
}



// -----------------------------------------------------------------------------
// HDF5data2node
// For HighFive::DataSet
// -----------------------------------------------------------------------------

// Helper: dataTYPE2node
template<class T, class NODE>
bool dataTYPE2node(const HighFive::DataSet &data, NODE &node)
{
   if (data.getDataType() == HighFive::AtomicType<T>{}) {
      // Comments as in the similar helper function attrTYPE2node()...
      const std::size_t dataSize = data.getElementCount();

      if (dataSize == 1) {
         T scalar;
         data.read(scalar);
         node.add("#pcdata").add("#text",scalar);
         return true;
      }

      if constexpr (!std::is_same_v<T,bool>) {
         std::vector<T> vector;
         vector.reserve(dataSize);
         data.read(vector);
         node.add("#pcdata").add("#text",vector);
         return true;
      }
   }

   return false;
}

// HDF5data2node
template<class NODE>
bool HDF5data2node(
   const HighFive::DataSet &data, const std::string &dataName,
   NODE &node
) {
   // node name
   node.name = dataName;

   // the data set's attributes
   for (auto &attrName : data.listAttributeNames())
      if (!HDF5attr2Node(data.getAttribute(attrName), node))
         return false;

   // the data set's data
   if (dataTYPE2node<char              >(data,node)) return true;
   if (dataTYPE2node<signed char       >(data,node)) return true;
   if (dataTYPE2node<unsigned char     >(data,node)) return true;
   if (dataTYPE2node<short             >(data,node)) return true;
   if (dataTYPE2node<unsigned short    >(data,node)) return true;
   if (dataTYPE2node<int               >(data,node)) return true;
   if (dataTYPE2node<unsigned          >(data,node)) return true;
   if (dataTYPE2node<long              >(data,node)) return true;
   if (dataTYPE2node<unsigned long     >(data,node)) return true;
   if (dataTYPE2node<long long         >(data,node)) return true;
   if (dataTYPE2node<unsigned long long>(data,node)) return true;
   if (dataTYPE2node<float             >(data,node)) return true;
   if (dataTYPE2node<double            >(data,node)) return true;
   if (dataTYPE2node<bool              >(data,node)) return true;
   if (dataTYPE2node<std::string       >(data,node)) return true;

   log::error(
     "HDF5 DataSet \"{}\"'s DataType \"{}\" is not handled at this time.",
      dataName, data.getDataType().string());
   log::function("HDF5data2node(HighFive::DataSet, dataName, Node)");

   return false;
}



// -----------------------------------------------------------------------------
// HDF52Node
// -----------------------------------------------------------------------------

// Helper: error_HDF52Node
inline void error_HDF52Node(const std::string &message)
{
   log::error(
     "Internal error in HDF52Node(HighFive::Group, std::string, Node):\n"
     "Message: \"{}\".",
      message
   );
   throw std::exception{};
}

// HDF52Node
template<class NODE>
bool HDF52Node(
   const HighFive::Group &group, const std::string &groupName,
   NODE &node, const bool requireEmpty = true
) {
   static const std::string context =
      "HDF52Node(HighFive::Group, std::string, Node)";

   // The node sent here should be fresh, ready to receive entries
   if (requireEmpty && !node.empty())
      error_HDF52Node("!node.empty()");

   // ------------------------
   // HDF5 group name
   // ==> node name
   // ------------------------

   // if "/" then we're at the top-level node, which we call "" internally
   if (groupName != "/")
      node.name = groupName;

   // ------------------------
   // HDF5 attributes
   // ==> metadata
   // ------------------------

   // if "/" then attributes were handled, in a special way, by the caller
   if (groupName != "/")
      for (auto &attrName : group.listAttributeNames())
         if (!HDF5attr2Node(group.getAttribute(attrName), node))
            return false;

   // ------------------------
   // HDF5 sub-groups
   // ==> children
   // ------------------------

   for (auto &elemName : group.listObjectNames()) {
      switch (group.getObjectType(elemName)) {

         // File
         // NOT EXPECTED IN THIS CONTEXT
         case HighFive::ObjectType::File :
            error_HDF52Node("ObjectType \"File\" not expected here");
            break;

         // Group
         // ACTION: call the present function recursively
         case HighFive::ObjectType::Group :
            try {
               if (!HDF52Node(group.getGroup(elemName), elemName, node.add()))
                  return false;
            } catch (...) {
               log::function(context);
               throw;
            }
            break;

         // UserDataType
         // NOT HANDLED; perhaps we could provide something in the future
         case HighFive::ObjectType::UserDataType :
            error_HDF52Node("ObjectType \"UserDataType\" not handled");
            break;

         // DataSpace (not to be confused with Dataset)
         // NOT EXPECTED IN THIS CONTEXT
         case HighFive::ObjectType::DataSpace :
            error_HDF52Node("ObjectType \"DataSpace\" not expected here");
            break;

         // Dataset
         // ACTION: handle the DataSet's data
         case HighFive::ObjectType::Dataset :
            try {
               if (!HDF5data2node(
                  group.getDataSet(elemName),
                  elemName,
                  node.add()
               ))
                  return false;
            } catch (...) {
               log::function(context);
               throw;
            }
            break;

         // Attribute
         // NOT EXPECTED IN THIS CONTEXT
         case HighFive::ObjectType::Attribute :
            // group.listObjectNames() (used in the for-loop we're in right
            // now) apparently doesn't include attribute names - which is fine,
            // because we already handled attributes earlier. So, here, we just
            // produce an error if ObjectType::Attribute inexplicably made an
            // appearance here, where we don't expect it.
            error_HDF52Node("ObjectType \"Attribute\" not expected here");
            break;

         // Other
         // NOT HANDLED; we're not sure when this would arise
         case HighFive::ObjectType::Other :
            error_HDF52Node("ObjectType \"Other\" not handled");
            break;

         // default
         // NOT HANDLED; presumably our switch has covered all bases already
         default:
            error_HDF52Node("ObjectType [unknown] not handled");
            break;

      } // switch
   } // for

   // done
   return true;
}



// -----------------------------------------------------------------------------
// node2node
// -----------------------------------------------------------------------------

// Node ==> Node
template<class NODE>
void node2node(const NODE &from, NODE &to)
{
   // clear
   to.clear();

   // name
   to.name = from.name;

   // metadata
   for (auto &m : from.metadata)
      to.add(m.first,m.second);

   // children
   for (auto &c : from.children)
      node2node(*c, to.add());
}



// -----------------------------------------------------------------------------
// node2xml
// -----------------------------------------------------------------------------

// Helper: check_special
template<class NODE>
bool check_special(const NODE &node, const std::string &label)
{
   if (node.children.size() != 0) {
      log::error(
        "Internal error in node2xml(Node, pugi::xml_node):\n"
        "Ill-formed <" + label + "> node; "
        "should have 0 children, but has {}.",
         node.children.size()
      );
      throw std::exception{};
   }

   if (node.metadata.size() != 1) {
      log::error(
        "Internal error in node2xml(Node, pugi::xml_node):\n"
        "Ill-formed <" + label + "> node; "
        "should have 1 metadatum, but has {}.",
         node.metadata.size()
      );
      throw std::exception{};
   }

   if (node.metadata.begin()->first != "#text") {
      log::error(
        "Internal error in node2xml(Node, pugi::xml_node):\n"
        "Ill-formed <" + label + "> node; "
        "should have metadatum key \"#text\", but has key \"{}\".",
         node.metadata.begin()->first
      );
      throw std::exception{};
   }

   return true;
}

// Helper: write_cdata
template<class NODE>
bool write_cdata(const NODE &node, pugi::xml_node &xnode)
{
   if (!check_special(node,"#cdata")) return false;
   xnode.append_child(pugi::node_cdata).set_value(node.meta("#text").data());
   return true;
}

// Helper: write_pcdata
template<class NODE>
bool write_pcdata(const NODE &node, pugi::xml_node &xnode)
{
   if (!check_special(node,"#pcdata")) return false;
   xnode.append_child(pugi::node_pcdata).set_value(node.meta("#text").data());
   return true;
}

// Helper: write_comment
template<class NODE>
bool write_comment(const NODE &node, pugi::xml_node &xnode)
{
   if (!check_special(node,"#comment")) return false;
   xnode.append_child(pugi::node_comment).set_value(node.meta("#text").data());
   return true;
}


// node2xml
template<class NODE>
bool node2xml(const NODE &node, pugi::xml_node &x)
{
   static const std::string context =
      "node2xml(Node, pugi::xml_node)";

   // name
   pugi::xml_node xnode = x.append_child(node.name.data());

   // metadata
   for (auto &meta : node.metadata)
      xnode.append_attribute(meta.first.data()) = meta.second.data();

   // children
   for (auto &child : node.children) {
      try {
         // special element
         if (child->name == "#cdata")
            { if (write_cdata  (*child,xnode)) continue; else return false; }
         if (child->name == "#pcdata")
            { if (write_pcdata (*child,xnode)) continue; else return false; }
         if (child->name == "#comment")
            { if (write_comment(*child,xnode)) continue; else return false; }

         // typical element
         if (!node2xml(*child,xnode))
            return false;
      } catch (...) {
         log::function(context);
         throw;
      }
   }

   // done
   return true;
}

} // namespace detail
