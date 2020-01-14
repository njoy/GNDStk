
/*
Summary of functions in this file:

namespace detail {
   1. prefix(unsigned long)

   2. node2json(gnds::Node, nlohmann::json, unsigned long)
      ...calls (1)
}

3. convert(gnds::Tree, gnds::json)
   ...calls (2)

4. convert(gnds::xml,  gnds::json)

5. convert(gnds::json, gnds::json)
*/



// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

namespace detail {

// prefix
inline std::string prefix(const unsigned long n)
{
   std::ostringstream oss;
   oss << std::setfill('0') << std::setw(12) << n;
   return oss.str();
}



// node2json
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool node2json(
   const gnds::Node<MCON,CCON> &node,
   nlohmann::json &j,
   unsigned long &kwdcount
) {
   // name
   // The effect of j[nodename] is to enter a key of this name into the json
   // object. Generally, this is triggered automatically in the body of one
   // and/or the other of the upcoming metadata and children loops. However,
   // consider a node that has no metadata or children; then, we need this.
   // An example is <RutherfordScattering/> in some of our GNDS XML files,
   // as it contains neither metadata nor children.
   const std::string nodename = prefix(kwdcount++) + node.name;
   j[nodename];

   // metadata
   if (node.metadata.size() > 0) {
      // ...because we only want the kwdcount ++ side effect if size() > 0
      const std::string attrname = prefix(kwdcount++) + "attributes";
      // visit
      for (auto &meta : node.metadata)
         j[nodename][attrname][prefix(kwdcount++) + meta.first] =
            meta.second;
   }

   // children
   for (auto &child : node.children)
      if (child && !node2json(*child, j[nodename], kwdcount))
         return false;

   // done
   return true;
}

} // namespace detail



// -----------------------------------------------------------------------------
// convert
// -----------------------------------------------------------------------------

// Tree ==> json
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool convert(const gnds::Tree<MCON,CCON> &tree, gnds::json &jdoc)
{
   // prepare output
   jdoc.clear();

   // convert
   if (tree.root) {
      const gnds::Node<MCON,CCON> &node = *tree.root;
      unsigned long kwdcount = 0;
      assert(node.children.size() == 1);  // e.g. reactionSuite
      assert(*node.children.begin() != nullptr);
      return detail::node2json(**node.children.begin(), jdoc.doc, kwdcount);
   }

   // done
   return true;
}



// xml ==> json
// Goes through a tree. Could be made more efficient if written more directly.
// We'll revisit this issue if this becomes more of an issue.
inline bool convert(const gnds::xml &xdoc, gnds::json &jdoc)
{
   gnds::tree tree;
   return
      convert(xdoc,tree) &&
      convert(tree,jdoc);
}



// json ==> json
// For completeness
inline bool convert(const gnds::json &from, gnds::json &to)
{
   if (&from != &to) {
      to.clear();

      // We can use nlohmann::json's assignment.
      to.doc = from.doc;
   }
   return true;
}
