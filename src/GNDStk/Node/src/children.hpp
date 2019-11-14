const auto& children() const{ return this->children_; }

auto children( const std::string& name ) const {
  return this->children_
    | ranges::view::filter(
        [&]( auto& child ){ return name == child->name(); } );
}

/* Not sure how to do this one
template< typename T >
auto children() const{

}
 */
