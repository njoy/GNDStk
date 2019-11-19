SterileNode( ) = default;
SterileNode( SterileNode& ) = default;
SterileNode( const SterileNode& ) = default;
SterileNode( SterileNode&& ) = default;

SterileNode( typename Metadata< AllowedKeys >::Map_t& dMap )
try:
  metadata_( dMap )
{ }
catch( ... ){
  Log::info( "Trouble creating Node with default map." );
  throw;
}

SterileNode(
  std::initializer_list< std::pair< const std::string, std::string > >&& map )
try:
  metadata_( map )
{ }
catch( ... ){
  Log::info( "Trouble creating Node with initializer list." );
  throw;
}

