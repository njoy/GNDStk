template< std::vector< std::string >& AllowedKeys, typename... Ls >
class Node {
public:
  using child_type = std::variant< Ls... >;
  using ptr_type = valuable::value_ptr< Node >;

private:
  std::string name_;
  Metadata< AllowedKeys > metadata_;
  std::vector< ptr_type > children_;
  std::vector< child_type > body_;

public: 
  const auto& name() const { return this->name_; }
  

  #include "GNDStk/Node/src/ctor.hpp"
  #include "GNDStk/Node/src/metadata.hpp"
  #include "GNDStk/Node/src/push_back.hpp"
  #include "GNDStk/Node/src/children.hpp"
  #include "GNDStk/Node/src/body.hpp"

};

inline std::vector< std::string > allKeysValid;
template< typename... Ls >
using AllKeysValidNode = Node< allKeysValid, Ls... >;
