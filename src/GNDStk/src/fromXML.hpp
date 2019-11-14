inline auto fromXML( const pugi::xml_node& xmlNode ) -> Node< std::string >{

  // Log::info( "Creating node from XML named: {}", xmlNode.name() );
  Node< std::string > returnNode{ xmlNode.name() };

  // Log::info( "\tAttributes:" );
  for( const auto& attr : xmlNode.attributes()){
    // Log::info( "\t\tname: {}, value: {}", attr.name(), attr.value() );
    returnNode.metadata( attr.name(), attr.value() );
  }

  for( const auto& child : xmlNode.children() ){
    returnNode.push_back( fromXML( child ) );
  }

  return returnNode;
}
