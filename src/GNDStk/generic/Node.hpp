class Node: protected knoop::Node< double, int, std::string >{

  using Node_t = knoop::Node< double, int, std::string >;
  using meta_t = std::map< std::string, const std::string >;

  meta_t metadata_;
  std::optional< Node_t::list_type > values_;

public:

  #include "GNDStk/generic/Node/src/ctor.hpp"
  #include "GNDStk/generic/Node/src/metadata.hpp"
  #include "GNDStk/generic/Node/src/values.hpp"

  using Node_t::put;
  using Node_t::operator[];

};
