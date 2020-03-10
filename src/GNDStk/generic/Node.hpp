class Node {

  std::string name_;
  std::map< std::string, std::string > metadata_;
  std::vector< Node > children_;
  std::string body_;

public:
  #include "GNDStk/generic/Node/src/insertChild.hpp"
  #include "GNDStk/generic/Node/src/ctor.hpp"
  #include "GNDStk/generic/Node/src/metadata.hpp"
  #include "GNDStk/generic/Node/src/children.hpp"

  const std::string& name() const { return name_; }
  const std::string& body() const { return body_; }

  auto operator[]( std::string key ){
    return this->children( key );
  }

  auto operator()( std::string key ){
    return this->metadata( key );
  }
};
