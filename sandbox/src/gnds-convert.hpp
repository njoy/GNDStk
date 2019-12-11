
/*
Summary of helpers for xml...

   template<class NODE>
      bool convert(const pugi::xml_node &from, NODE &to)

   template<class TYPE>
      bool convert(const gnds::xml &from, TYPE &to)

Summary of helpers for json...

   template<class NODE>
      bool convert(const nlohmann::json::const_iterator &from, NODE &to)

   template<class TYPE>
      bool convert(const gnds::json &from, TYPE &to)

Above, gnds::xml and gnds::json are our wrappers around pugi::xml_document
and nlohmann::json, respectively. NODE is one of our own node types - either
gnds::node, or possibly gnds::knoop::node if we keep our optional knoop-based
tree. TYPE is one of our tree types: gnds::tree or gnds::knoop.
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

      // We'll store these as metadata for the current element, as they aren't
      // really child elements in the usual XML sense. Markup-wise, I'll use the
      // beginning XML markup as the key, and append, to the value, the ending
      // XML markup.
      // fixme Perhaps we really don't want to append the ending XML markup;
      // this could probably cause problems when interpreting the data.

      // comment
      if (xsub.type() == pugi::node_comment) {
         static const std::string prefix = "<!--";
         static const std::string suffix = "-->";
         node.push(prefix, xsub.value()+suffix);
         continue;
      }

      // CDATA
      if (xsub.type() == pugi::node_cdata) {
         // the docs speak of using text(); let's ensure that the following
         // two give the same result...
         assert(xsub.value() == xsub.text().get());

         static const std::string prefix = "![CDATA[";
         static const std::string suffix = "]]";
         node.push(prefix, xsub.value()+suffix);
         continue;
      }

      // PCDATA
      // This isn't an XML tag (e.g. with "![PCDATA["), like CDATA is, but I'll
      // mark it as such in the output format, to reflect the pugi XML reader's
      // identification of this as being the type.
      if (xsub.type() == pugi::node_pcdata) {
         // comment as with CDATA code above
         assert(xsub.value() == xsub.text().get());

         static const std::string prefix = "![PCDATA[";
         static const std::string suffix = "]]";
         node.push(prefix, xsub.value()+suffix);
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
// Where TYPE == tree | knoop
template<class TYPE>
bool convert(const gnds::xml &xdoc, TYPE &tree)
{
   // prepare output
   tree.clear();

   // visit the xml document's nodes
   int count = 0;
   for (const pugi::xml_node &xnode : xdoc.doc.children()) {
      // gnds::node or gnds::knoop::node
      using NODE = typename std::remove_reference<decltype(*tree.root)>::type;

      if (count == 0) {
         // expect the following, given that we called load_file()
         // with pugi::parse_declaration |d in its second argument
         assert(xnode.name() == std::string("xml"));

         tree.root = std::make_unique<NODE>();
         tree.root->name() = "xml"; // indicates that we came from an xml

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
      if (!sub->is_object()) {
         node.push(sub.key(), sub->get<std::string>());
      } else {
         debug("new node");
         node.push(new NODE);
         if (!convert(sub,*node.children().back()))
            return false;
      }
   }

   // done
   return true;
}



// convert(json ==> TYPE)
// Where TYPE == tree | knoop
template<class TYPE>
bool convert(const gnds::json &jdoc, TYPE &tree)
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
   return true;
}

} // namespace detail



// -----------------------------------------------------------------------------
// convert: (xml|json) to (tree|knoop)
// I.e., convert an object from one of our xml or json documents (wrappers
// around pugi::xml_document and nlohmann::json), to an object of our tree
// or knope-based tree structure.
// -----------------------------------------------------------------------------

// xml to tree
inline bool convert(const gnds::xml &xdoc, gnds::tree &tree)
{ return detail::convert(xdoc,tree); }

// xml to knoop tree
inline bool convert(const gnds::xml &xdoc, gnds::knoop &tree)
{ return detail::convert(xdoc,tree); }

// json to tree
inline bool convert(const gnds::json &jdoc, gnds::tree &tree)
{ return detail::convert(jdoc,tree); }

// json to knoop tree
inline bool convert(const gnds::json &jdoc, gnds::knoop &tree)
{ return detail::convert(jdoc,tree); }



// -----------------------------------------------------------------------------
// Helpers for:
// convert: tree to (xml|json)
// -----------------------------------------------------------------------------

namespace detail {

// node to xml
// fixme write this



// node to json
inline // <== obviously not always :-p
bool convert(const gnds::node &node, nlohmann::json &j)
{
   // name
   // The effect of the following is to enter a key of this name into the json.
   // Generally, this is triggered automatically in the body of one and/or the
   // other of the upcoming metadata and children loops. However, consider
   // a node that has no metadata or children; then, we need this. An example
   // is <RutherfordScattering/> in some of our GNDS XML files, as it contains
   // neither metadata nor children.
   j[node.name()];

   // metadata
   for (auto &meta : node.metadata())
      j[node.name()][meta.first] = meta.second;

   // children
   for (auto &child : node.children())
      if (child && !convert(*child,j[node.name()]))
         return false;

   return true;
}

} // namespace detail



// -----------------------------------------------------------------------------
// convert: tree to (xml|json)
// -----------------------------------------------------------------------------

// tree to xml
inline bool convert(const tree &from, xml &to)
{
   (void)from;
   (void)to;

   // prepare output
   to.clear();

   // convert
   // fixme write this

   // done 
   return true;
}



// tree to json
inline bool convert(const tree &from, json &to)
{
   // prepare output
   to.clear();

   // convert
   if (from.root) {
      const gnds::node &node = *from.root;
      assert(node.name() == "xml"); // fixme maybe not???
      assert(node.children().size() == 1);  // e.g. reactionSuite
      assert(node.children()[0] != nullptr);
      return detail::convert(*node.children()[0],to.doc);
   }

   // done
   return true;
}



// -----------------------------------------------------------------------------
// Finish constructors that depend on certain definitions being available.
// Note that these both go through a tree, and could be made more efficient
// if they were written more directly (which, however, would require more code).
// We'll revisit this issue if efficiency, either in time or in space, becomes
// more of an issue than it currently is.
// -----------------------------------------------------------------------------

// xml(json)
inline xml::xml(const gnds::json &j)
{
   // process: xml(tree(json))
   tree t;
   convert(j,t);
   convert(t,*this);
}

// json(xml)
inline json::json(const xml &x)
{
   // process: json(tree(xml))
   tree t;
   convert(x,t);
   convert(t,*this);
}
