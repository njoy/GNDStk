class Node: protected knoop::Node< double, int, std::string >{

  using Base = knoop::Node< double, int, std::string >;
  using meta_t = std::map< std::string, const std::string >;

  meta_t metadata_;

public:

  #include "GNDStk/generic/Node/src/ctor.hpp"

  using Base::put;
  using Base::operator[];

  const std::string& 
  metadata( std::string key ) const{
    return this->metadata_.at( key );
  }
  void metadata( std::string key, std::string value ){
    this->metadata_.emplace( key, value );
  }

};
