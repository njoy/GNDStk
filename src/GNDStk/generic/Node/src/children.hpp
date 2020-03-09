auto children() const{
  return this->children_;
}

auto children( const std::string& name ) const {

  return this->children_
    | ranges::view::filter( 
      [&]( auto&& child ){ return name == child.name(); } )
    | ranges::view::all;
}
