const auto& children() const{ return this->children_; }


auto children( unsigned int index ){
  return this->children_
    | ranges::view::filter(
      [&]( auto& child ){ return index == child.index(); } )
    | ranges::view::all;
}
