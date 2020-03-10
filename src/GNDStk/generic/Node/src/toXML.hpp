void toXML( pugi::xml_node& node ) const{

  for( auto&[ name, value] : this->metadata_ ){
    node.append_attribute( name.c_str() ).set_value( value.c_str() );
  }
  for( const auto& child : this->children_ ){
    auto childNode = node.append_child( child.name().c_str() );
    child.toXML( childNode );
  }
  // node.append_child( pugi::node_pcdata ).set_value( this->body_.c_str() );
  node.text().set( this->body_.c_str() );
}
