Node( std::string name ):
  name_( name ),
  metadata_(),
  children_()
{
}

Node( Node&& ) = default;
Node( Node& ) = default;
Node( const Node& ) = default;
