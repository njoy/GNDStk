auto insertChild( Node&& child ){
  return this->children_.push_back( std::move( child ) );
}

auto insertChild( std::string name ){
  return this->children_.emplace_back( name );
}
