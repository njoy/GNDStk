inline Node_t node( const std::string& name ){
  auto gNode = Node_t::makeMap();

  gNode.insert( "name", Node_t{ name } );
  gNode.insert( "metadata", Node_t::makeMap() );

  return gNode;
}
