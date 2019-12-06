
/*
Summary of helpers for xml...

   template<class NODE>
      bool convert(const pugi::xml_node                 &from, NODE &to)

   template<class TYPE>
      bool convert(const xml  &from, TYPE &to)

Summary of helpers for json...

   template<class NODE>
      bool convert(const nlohmann::json::const_iterator &from, NODE &to)

   template<class TYPE>
      bool convert(const json &from, TYPE &to)

The above are OCD lined-up to make the pattern clear.
*/



// -----------------------------------------------------------------------------
// Helpers for xml-related convert()s
// -----------------------------------------------------------------------------

namespace detail {

// convert(pugi::xml_node ==> NODE)
// Where NODE == node | knoop::node
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
      debug("new node");
      to.push(new NODE);
      if (!convert(sub,*to.children().back()))
         return false;
   }

   // done
   return true;
}



// convert(xml ==> TYPE)
// Where TYPE == knoop | tree
template<class TYPE>
bool convert(const xml &from, TYPE &to)
{
   // prepare output
   to.clear();

   int count = 0;
   for (const pugi::xml_node &xnode : from.doc.children()) {
      using NODE = typename std::remove_reference<decltype(*to.root)>::type;

      if (count == 0) {
         // expect the following, given that we called load_file()
         // with pugi::parse_declaration |d in its second argument
         assert(xnode.name() == std::string("xml"));

         to.root = std::make_unique<NODE>();
         to.root->name() = "xml"; // indicates that we came from a xml

         // base document "attributes": stuff like version and encoding
         for (const pugi::xml_attribute &meta : xnode.attributes())
            to.root->push(meta.name(), meta.value());
      }

      if (count == 1) {
         // visit the document's nodes
         debug("new node");
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








// -----------------------------------------------------------------------------
// Helpers for json-related convert()s
// -----------------------------------------------------------------------------

namespace detail {

// convert(nlohmann::json::const_iterator ==> NODE)
// Where NODE == node | knoop::node
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
         debug("new node");
         to.push(new NODE);
         if (!convert(sub,*to.children().back()))
            return false;
      }
   }

   // done
   return true;
}



// convert(json ==> TYPE)
// Where TYPE == knoop | tree
template<class TYPE>
bool convert(const json &from, TYPE &to)
{
   // prepare output
   to.clear();

   using NODE = typename std::remove_reference<decltype(*to.root)>::type;
   to.root = std::make_unique<NODE>();
   to.root->name() = "json"; // indicates that we came from a json

   // visit the document's nodes
   for (auto elem = from.doc.begin();  elem != from.doc.end();  ++elem) {
      debug("new node");
      to.root->push(new NODE);
      if (!detail::convert(elem,*to.root->children().back()))
         return false;
   }

   // done
   return true;
}

} // namespace detail



// -----------------------------------------------------------------------------
// convert: (xml|json) to (tree|knoop)
// -----------------------------------------------------------------------------

// xml to tree
inline bool convert(const xml &from, tree &to)
{ return detail::convert(from,to); }

// xml to knoop
inline bool convert(const xml &from, knoop &to)
{ return detail::convert(from,to); }

// json to tree
inline bool convert(const json &from, tree &to)
{ return detail::convert(from,to); }

// json to knoop
inline bool convert(const json &from, knoop &to)
{ return detail::convert(from,to); }



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
   // Generally, the effect of the following is triggered automatically in the
   // body of one and/or the other of the upcoming metadata and children loops.
   // However, consider a node that has no metadata or children; then, we need
   // this. Example: <RutherfordScattering/> in some of our GNDS XML files.
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

   to.clear();
   // fixme write this
   return true;
}



// tree to json
inline bool convert(const tree &from, json &to)
{
   to.clear();

   if (from.root) {
      const gnds::node &node = *from.root;
      assert(node.name() == "xml");
      assert(node.children().size() == 1);  // e.g. reactionSuite
      assert(node.children()[0] != nullptr);
      return detail::convert(*node.children()[0],to.doc);
   }

   return true;
}



// -----------------------------------------------------------------------------
// Finish constructors that depend on definitions being available.
// These both go through a tree, and could be made more efficient.
// -----------------------------------------------------------------------------

// xml(json)
inline xml::xml(const gnds::json &j)
{
   tree t;
   convert(j,t);
   convert(t,*this);
}

// json(xml)
inline json::json(const xml &x)
{
   tree t;
   convert(x,t);
   convert(t,*this);
}
