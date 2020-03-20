
#include "GNDStk/Node/src/detail.hpp"

// This is returned by some of Node's child() functions
template<class NODE, class T>
class TypedNode;



// -----------------------------------------------------------------------------
// Node (templated)
// node = Node<>
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER, // container type for metadata
   template<class...> class CHILDREN_CONTAINER  // container type for children
>
class Node {
   using metaPair = std::pair<std::string,std::string>;
   using childPtr = std::unique_ptr<Node>;

public:

   // ------------------------
   // Data
   // ------------------------

   // Simple node for our tree structure:
   //    name
   //    metadata (container of string pairs)
   //    children (container of pointers to other Node<>s)
   std::string name;
   METADATA_CONTAINER<metaPair,std::allocator<metaPair>> metadata;
   CHILDREN_CONTAINER<childPtr,std::allocator<childPtr>> children;

   // ------------------------
   // Simple functions
   // ------------------------

   // clear()
   Node &clear()
   {
      name = "";
      metadata.clear();
      children.clear();
      return *this;
   }

   // is this node empty?
   bool empty() const
   {
      return name == "" && metadata.size() == 0 && children.size() == 0;
   }

   // is this a leaf node?
   bool leaf() const
   {
      return children.size() == 0;
   }

   // copy
   Node copy() const
   {
      Node ret;
      detail::node2Node(*this,ret);
      return ret;
   }

   // normalize
   Node &normalize();

   // ------------------------
   // General functions
   // ------------------------

   // ctor: default
   Node() { }

   // ctor: move, DELETED copy
   Node(Node &&) = default;
   Node(const Node &) = delete;

   // assignment: move, DELETED copy
   Node &operator=(Node &&) = default;
   Node &operator=(const Node &) = delete;

   #include "GNDStk/Node/src/add.hpp"
   #include "GNDStk/Node/src/write.hpp"
   #include "GNDStk/Node/src/meta.hpp"
   #include "GNDStk/Node/src/child.hpp"
   #include "GNDStk/Node/src/call.hpp"

}; // class Node



// -----------------------------------------------------------------------------
// operator<<
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
inline std::ostream &operator<<(
   std::ostream &os,
   const Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &obj
) {
   return obj.write(os);
}



// -----------------------------------------------------------------------------
// normalize
// -----------------------------------------------------------------------------

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &
Node<METADATA_CONTAINER,CHILDREN_CONTAINER>::normalize()
{
   // name
   detail::strip(name);

   // children
   auto iter = children.end();
   for (auto c = children.begin();  c != children.end();  ++c)
      if (detail::strip((*c)->name) == "attributes") {
         // Child node's name is "attributes". This presumably means that the
         // current node originally had *that* child node's metadata as its
         // own, before they were placed into an "attributes" child for the
         // purpose of writing, say, to a .json file. Now, apparently, we've
         // just read such a file, and must restore the node's original form.

         // Under the circumstances, this node should not (yet) have its own
         // metadata. They'll be pulled up from the "attributes" child, which
         // itself should have only those metadata (and not further children).
         assert(metadata.size() == 0);  // <== this node has no metadata
         assert((*c)->children.size() == 0); // <== child node has no children

         // And, there should have been at most one such "attributes" child.
         assert(iter == children.end()); // up until now
         iter = c; // now

         // Restore the metadata
         for (auto &m : (*c)->metadata)
            add(m);

      } else if (endsin((*c)->name, "_attr")) {
         assert(false); // for now
         // Child node's name ends in "_attr"
         /*
         fixme
         I'll  need to think about the .json business more, and see what sorts
         of GNDS json files are actually being produced by people other than
         myself, in order to know for certain what I'll need to do in order to
         properly read whatever other people might be writing. In my own json-
         reading code, I use is_object(), from the nlohmann json library, to
         distinguish whether what I'm reading should be entered into the current
         node's children, or go into its metadata. I think this condition
         amounts to whether the value in a json key/value pair is of the {...}
         form (goes to children), or the "..." form (goes to metadata). The
         GNDS manual speaks of the json format *not* having the concept of
         attributes, but perhaps in some sense it does, via the condition I've
         just described.
         */
      } else {
         // Regular child node; recursively normalize
         (*c)->normalize();
      }

   // chuck any "attributes" child
   if (iter != children.end())
      children.erase(iter);

   // metadata, including any additional ones from an "attributes"
   // child as described above
   for (auto &meta : metadata)
      detail::strip(meta.first);

   // done
   return *this;
}
