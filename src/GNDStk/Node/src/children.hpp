const auto& children() const{ return this->children_; }


auto children( unsigned int index ){
  return this->children_
    | ranges::view::filter(
      [&]( auto& child ){ return index == child.index(); } );
}

template< typename T >
auto children() const{
  return this->children_
    | ranges::view::filter(
      []( auto& child ){ return std::get_if< T >( &child ); } )
    | ranges::view::transform(
      []( auto& child ){ return std::get< T >( child ); } );
}
