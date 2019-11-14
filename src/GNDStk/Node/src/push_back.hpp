Node& push_back( Node&& arg ){
  this->children_.push_back( std::forward< Node >( arg ) );
  return *this;
}


template< typename T >
Node& push_back( T&& t ){
  this->body_.push_back( std::forward< T >( t ) );
  return *this;
}

template< typename T, typename... Args >
Node& push_back( T&& t, Args&&... args ){
  this->push_back( std::forward< T >( t ) );
  this->push_back( std::forward< Args >( args )... );
  return *this;
}
