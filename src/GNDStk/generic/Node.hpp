class Node {

  std::string name_;
  std::map< std::string, std::string > metadata_;
  std::vector< std::unique_ptr< Node > > v;

public:
  #include "GNDStk/generic/Node/src/ctor.hpp"

  const std::string& name(){ return name_; }

};
