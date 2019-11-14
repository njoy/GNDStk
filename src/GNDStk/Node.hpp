template< typename... Ls >
class Node {
public:
  using child_type = std::variant< Ls... >;
  using ptr_type = valuable::value_ptr< Node >;

private:
  std::string name_;
  Metadata metadata_;
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
