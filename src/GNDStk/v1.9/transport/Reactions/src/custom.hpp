const transport::Reaction& reaction( const std::string& label ) const {

  auto getLabel = [] ( const auto& variant )
                     { return variant.get().label().value(); };

  auto iter std::find_if( this->content.reaction.begin(), this->content.reaction.end(),
                          [&] ( const transport::Reaction& element )
                              { return element.label() == label; } );

  if ( iter != this->children_.end() ) {

    log::error( "No cross section style \"{}\" can be found", style );
    throw std::exception();
  }

  return *iter;
}
