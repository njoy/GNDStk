
/*
Summary of helpers for xml...

   template<class NODE>
      bool convert(const pugi::xml_node &from, NODE &to)

   template<class TYPE>
      bool convert(const xml &from, TYPE &to)

Summary of helpers for json...

   template<class NODE>
      bool convert(const nlohmann::json::const_iterator &from, NODE &to)

   template<class TYPE>
      bool convert(const json &from, TYPE &to)

Above, xml and json are our wrappers around pugi::xml_document and
nlohmann::json, respectively. NODE is one of our own node types - either
node, or possibly knoop::node if we keep our optional knoop-based tree.
TYPE is one of our tree types: tree or knoop::tree.
*/



// -----------------------------------------------------------------------------
// Helpers for xml-related convert()s
// -----------------------------------------------------------------------------

namespace detail {

// convert(pugi::xml_node ==> NODE)
// Where NODE == node | knoop::node
template<class NODE>
bool convert(const pugi::xml_node &xnode, NODE &node)
{
   // name
   node.name() = xnode.name();

   // metadata
   for (const pugi::xml_attribute &meta : xnode.attributes())
      node.push(meta.name(), meta.value());

   // children (sub-nodes)
   for (const pugi::xml_node &xsub : xnode.children()) {

      // ------------------------
      // Not handled right now
      // ------------------------

      // I don't think that the following should ever appear in this context...
      if (xsub.type() == pugi::node_document)
         assert(false);
      if (xsub.type() == pugi::node_declaration)
         assert(false);

      // For now I won't handle these; let's ensure that we don't see them...
      if (xsub.type() == pugi::node_null)
         assert(false);
      if (xsub.type() == pugi::node_pi)
         assert(false);
      if (xsub.type() == pugi::node_doctype)
         assert(false);

      // ------------------------
      // Comment, CDATA, PCDATA
      // ------------------------

      // We'll store these as metadata for the current node;
      // they aren't really children in the usual XML sense.

      // comment
      // Use "comment"
      if (xsub.type() == pugi::node_comment) {
         node.push("comment", xsub.value());
         continue;
      }

      // CDATA
      // Use "text"
      if (xsub.type() == pugi::node_cdata) {
         assert(xsub.value() == xsub.text().get());
         node.push("text", xsub.value());
         continue;
      }

      // PCDATA
      // use "body"
      if (xsub.type() == pugi::node_pcdata) {
         assert(xsub.value() == xsub.text().get());
         node.push("body", xsub.value());
         continue;
      }

      // ------------------------
      // Regular element
      // ------------------------

      assert(xsub.type() == pugi::node_element);
      debug("new node");
      node.push(new NODE);
      if (!convert(xsub,*node.children().back()))
         return false;
   }

   // done
   return true;
}



// convert(xml ==> TYPE)
// Where TYPE == tree | knoop::tree
template<class TYPE>
bool convert(const xml &xdoc, TYPE &tree)
{
   // prepare output
   tree.clear();

   // visit the xml document's nodes
   int count = 0;
   for (const pugi::xml_node &xnode : xdoc.doc.children()) {
      // node or knoop::node
      using NODE = typename std::remove_reference<decltype(*tree.root)>::type;

      if (count == 0) {
         // expect the following, given that we called load_file()
         // with pugi::parse_declaration |d in its second argument
         assert(xnode.name() == std::string("xml"));

         tree.root = std::make_unique<NODE>();
         tree.root->name() = "xml"; // indicates that we came from a xml

         // base document "attributes", e.g. version and encoding
         for (const pugi::xml_attribute &meta : xnode.attributes())
            tree.root->push(meta.name(), meta.value());
      }

      if (count == 1) {
         // visit the document's outer node, and its descendants
         debug("new node");
         tree.root->push(new NODE);
         if (!detail::convert(xnode,*tree.root->children().back()))
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



// -----------------------------------------------------------------------------
// Helpers for json-related convert()s
// -----------------------------------------------------------------------------

namespace detail {

// convert(nlohmann::json::const_iterator ==> NODE)
// Where NODE == node | knoop::node
template<class NODE>
bool convert(const nlohmann::json::const_iterator &jiter, NODE &node)
{
   assert(jiter->is_object());

   // name
   node.name() = jiter.key();

   // elements
   const nlohmann::json &value = jiter.value();
   for (auto sub = value.begin();  sub != value.end();  ++sub) {
      if (sub->is_null()) {
         // The current node has a child node with neither metadata
         // nor its own children. This would come about, for example,
         // if the .json file was created, earlier, based on an .xml
         // file with a construct like <RutherfordScattering/>, i.e.
         // with /> to end the element immediately.
         node.push(new NODE);
         node.children().back()->name() = sub.key();
      } else if (sub->is_object()) {
         // The current node has a child node *other* than as above.
         debug("new node");
         node.push(new NODE);
         if (!convert(sub,*node.children().back()))
            return false;
      } else {
         // The current node has this as a key/value metadata pair...
         node.push(sub.key(), sub->get<std::string>());
      }
   }

   // done
   return true;
}



// convert(json ==> TYPE)
// Where TYPE == tree | knoop::tree
template<class TYPE>
bool convert(const json &jdoc, TYPE &tree)
{
   // prepare output
   tree.clear();

   // initialize base document
   using NODE = typename std::remove_reference<decltype(*tree.root)>::type;
   tree.root = std::make_unique<NODE>();
   tree.root->name() = "json"; // indicates that we came from a json

   // visit the document's outer node, and its descendants
   for (auto elem = jdoc.doc.begin();  elem != jdoc.doc.end();  ++elem) {
      debug("new node");
      tree.root->push(new NODE);
      if (!detail::convert(elem,*tree.root->children().back()))
         return false;
   }

   // done
   tree.normalize();
   return true;
}

} // namespace detail



// -----------------------------------------------------------------------------
// convert: (xml|json) to (tree|knoop::tree)
// I.e., convert from one of our xml or json objects (wrappers
// around pugi::xml_document and nlohmann::json), to an object of our tree
// or knoop-based tree structure.
// -----------------------------------------------------------------------------

// xml to tree
inline bool convert(const xml &xdoc, tree &tree)
{ return detail::convert(xdoc,tree); }

// xml to knoop tree
inline bool convert(const xml &xdoc, knoop::tree &tree)
{ return detail::convert(xdoc,tree); }

// json to tree
inline bool convert(const json &jdoc, tree &tree)
{ return detail::convert(jdoc,tree); }

// json to knoop tree
inline bool convert(const json &jdoc, knoop::tree &tree)
{ return detail::convert(jdoc,tree); }



// -----------------------------------------------------------------------------
// Helpers for:
// convert: tree to (xml|json)
// -----------------------------------------------------------------------------

namespace detail {

// Helper: prefix
inline std::string prefix(const unsigned long n)
{
   std::ostringstream oss;
   oss << std::setfill('0') << std::setw(12) << n;
   return oss.str();/// + " ";
}



// node to xml
// fixme write this



// node to json
inline bool convert(
   const node &node, nlohmann::json &j,
   unsigned long &count
) {
   // name
   // The effect of j[nodename] is to enter a key of this name into the json
   // object. Generally, this is triggered automatically in the body of one
   // and/or the other of the upcoming metadata and children loops. However,
   // consider a node that has no metadata or children; then, we need this.
   // An example is <RutherfordScattering/> in some of our GNDS XML files,
   // as it contains neither metadata nor children.
   const std::string nodename = prefix(count++) + node.name();
   j[nodename];

   // metadata
   if (node.metadata().size() > 0) {
      // ...because we only want the count ++ side effect if size() > 0
      const std::string attrname = prefix(count++) + "attributes";
      // visit
      for (auto &meta : node.metadata())
         j[nodename][attrname][prefix(count++) + meta.first] =
            meta.second;
   }

   // children
   for (auto &child : node.children())
      if (child && !convert(*child, j[nodename], count))
         return false;

   // done
   return true;
}

} // namespace detail



// -----------------------------------------------------------------------------
// convert: tree to (xml|json)
// -----------------------------------------------------------------------------

// tree to xml
inline bool convert(const tree &tree, xml &xdoc)
{
   (void)tree;
   (void)xdoc;

   // prepare output
   xdoc.clear();

   // convert
   // fixme write this
   assert(false);

   // done 
   return true;
}



// tree to json
inline bool convert(const tree &tree, json &jdoc)
{
   // prepare output
   jdoc.clear();

   // convert
   if (tree.root) {
      const gnds::node &node = *tree.root;
      assert(node.children().size() == 1);  // e.g. reactionSuite
      assert(node.children()[0] != nullptr);
      unsigned long count = 0;
      return detail::convert(*node.children()[0], jdoc.doc, count);
   }

   // done
   return true;
}



// -----------------------------------------------------------------------------
// convert:
//    json to xml
//    xml to json
// Note that these both go through a tree, and could be made more efficient
// if they were written more directly (which, however, would require more code).
// We'll revisit this issue if efficiency, either in time or in space, becomes
// more of an issue than it currently is.
// -----------------------------------------------------------------------------

// convert(json,xml)
inline bool convert(const json &jdoc, xml &xdoc)
{
   gnds::tree tree;
   return
      convert(jdoc,tree) &&
      convert(tree,xdoc);
}

// convert(xml,json)
inline bool convert(const xml &xdoc, json &jdoc)
{
   gnds::tree tree;
   return
      convert(xdoc,tree) &&
      convert(tree,jdoc);
}



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

/*
fixme Probably delete this block; stuff will probably change anyway

namespace detail {
   // pugi/nlohmann nodes to our nodes (either regular or knoop)
   template<class NODE>
   bool convert(const pugi::xml_node                 &xnode, NODE &node);
   template<class NODE>
   bool convert(const nlohmann::json::const_iterator &jiter, NODE &node);

   // our xml/json to our trees (either regular or knoop)
   template<class TYPE> bool convert(const xml  &xdoc, TYPE &tree);
   template<class TYPE> bool convert(const json &jdoc, TYPE &tree);

   // our regular node to nlohmann object
   inline bool convert(const node &node, nlohmann::json &j);
}

inline bool convert(const tree &tree, xml  &xdoc);
inline bool convert(const tree &tree, json &jdoc);
inline bool convert(const xml  &xdoc, tree &tree);
inline bool convert(const xml  &xdoc, json &jdoc);
inline bool convert(const json &jdoc, tree &tree);
inline bool convert(const json &jdoc, xml  &xdoc);

inline bool convert(const xml  &xdoc, knoop::tree &tree);
inline bool convert(const json &jdoc, knoop::tree &tree);
*/