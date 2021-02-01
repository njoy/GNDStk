
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

} // namespace detail
