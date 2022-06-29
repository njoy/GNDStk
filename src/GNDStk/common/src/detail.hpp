
namespace detail {

// -----------------------------------------------------------------------------
// convert_pcdata_text_t
// -----------------------------------------------------------------------------

class convert_pcdata_text_t {
public:

   // Node to container
   template<class CONTAINER>
   void operator()(const Node &node, CONTAINER &container) const
   {
      try {
         // Context:
         // We're inside of a <pcdata> node that's inside of a <values> node
         // that looked something like this (in XML):
         //    <values>0.0 1.0 2.0 3.0 4.0</values>
         // In GNDStk, the <pcdata> node has a metadatum with the key "text".
         // The metadatum's string value is the content: "0.0 1.0 ..." in
         // our example. Goal here: extract that content into the container.
         container.clear();
         for (auto &m : node.metadata)
            if (m.first == "text") {
               convert(m.second, container);
               return;
            }
         log::error(
           "Could not find metadatum key \"text\" in the current Node (\"{}\")",
            node.name
         );
         throw std::exception{};
      } catch (...) {
         log::function("convert_pcdata_text_t(Node,container)");
         throw;
      }
   }

   // container to Node
   template<class CONTAINER>
   void operator()(const CONTAINER &container, Node &node) const
   {
      try {
         node.clear();
         node.name = "pcdata";
         std::string &destination = node.add("text","").second;
         convert(container, destination);
      } catch (...) {
         log::function("convert_pcdata_text_t(container,Node)");
         throw;
      }
   }
};


// -----------------------------------------------------------------------------
// numeric_type
// -----------------------------------------------------------------------------

// default
// create vector
template<class T>
class numeric_type {
public:
   using type = std::vector<T>;
};

// keep deque
template<class T, class Alloc>
class numeric_type<std::deque<T,Alloc>> {
public:
   using type = std::deque<T,Alloc>;
};

// keep list
template<class T, class Alloc>
class numeric_type<std::list<T,Alloc>> {
public:
   using type = std::list<T,Alloc>;
};

// keep vector
template<class T, class Alloc>
class numeric_type<std::vector<T,Alloc>> {
public:
   using type = std::vector<T,Alloc>;
};

} // namespace detail
