Node( std::string name ):
  name_( name )
{ }

Node( const pugi::xml_node& node ):
  name_( node.name() )
{
  for( auto& attribute : node.attributes() ){
    this->metadata( attribute.name(), attribute.value() );
  }
  for( auto& child : node.children() ){
    this->insertChild( Node( child ) );
  }
  this->body_ = node.text().as_string();
}
