
namespace detail {

// text_metadatum_to_string
// Helper for cdata and comment
class text_metadatum_to_string {
public:
   template<class NODE>
   void operator()(const NODE &node, std::string &to) const
   {
      to = node.meta("text");
   }
};



// -----------------------------------------------------------------------------
// values_type
// -----------------------------------------------------------------------------

// default: make vector
template<class T>
class values_type {
public:
   using type = std::vector<T>;
};

// keep deque
template<class T, class Alloc>
class values_type<std::deque<T,Alloc>> {
public:
   using type = std::deque<T,Alloc>;
};

// keep list
template<class T, class Alloc>
class values_type<std::list<T,Alloc>> {
public:
   using type = std::list<T,Alloc>;
};

// keep vector
template<class T, class Alloc>
class values_type<std::vector<T,Alloc>> {
public:
   using type = std::vector<T,Alloc>;
};



// -----------------------------------------------------------------------------
// get_pcdata_text
// -----------------------------------------------------------------------------

template<class NODE>
const std::string &get_pcdata_text(const NODE &node)
{
   // Context:
   // We're in, say, a <values> node that looked something like this in XML:
   //    <values>0.0 1.0 2.0 3.0 4.0</values>
   // In GNDStk's data structures, this node - <values> - will have a <pcdata>
   // child node, which in turn will have a metadatum with the key "text". The
   // metadatum's value will be the content: the 0.0 1.0 ... as in our example,
   // as a std::string. Our goal here is to extract that content and return it.
   for (auto &c : node.children)
      if (c->name == "pcdata")
         for (auto &m : c->metadata)
            if (m.first == "text")
               return m.second;

   log::error(
      "Internal error in detail::get_pcdata_text().\n"
      "Unable to find child \"pcdata\" metadatum \"text\" entry in the Node,\n"
      "but it's needed for an operation"
   );
   throw std::exception{};

   // unreached, given the above throw, but might silence compiler warnings
   static const std::string empty = "";
   return empty;
}



// -----------------------------------------------------------------------------
// set_pcdata_text
// -----------------------------------------------------------------------------

template<class NODE>
std::string &set_pcdata_text(NODE &node)
{
   // Our own calls to this (detail) function clear the node first, and
   // this function shouldn't be called directly. So let's double-check.
   if (node.metadata.size() != 0) {
      log::error(
         "Internal error in detail::set_pcdata_text().\n"
         "Please contact us"
      );
      throw std::exception{};
   }

   return node.add("pcdata").add("text","").second;
}



// -----------------------------------------------------------------------------
// PcdataTextVContainer
// -----------------------------------------------------------------------------

class convert_pcdata_text_t {
   std::string str;

public:

   // constructor
   explicit convert_pcdata_text_t(const std::string &s = "values") : str(s)
   {
   }

   // node to container
   template<
      template<class...> class METADATA_CONTAINER,
      template<class...> class CHILDREN_CONTAINER,
      template<class...> class CONTAINER, class T, class Alloc
   >
   void operator()(
      const Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node,
      CONTAINER<T,Alloc> &container
   ) const {
      try {
         container.clear();
         convert(get_pcdata_text(node), container);
      } catch (const std::exception &) {
         log::context("convert_pcdata_text_t(node,container)");
         throw;
      }
   }

   // container to node
   template<
      template<class...> class CONTAINER, class T, class Alloc,
      template<class...> class METADATA_CONTAINER,
      template<class...> class CHILDREN_CONTAINER
   >
   void operator()(
      const CONTAINER<T,Alloc> &container,
      Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node
   ) const {
      try {
         node.clear().name = str;
         convert(container, set_pcdata_text(node));
      } catch (const std::exception &) {
         log::context("convert_pcdata_text_t(container,node)");
         throw;
      }
   }
};

} // namespace detail
