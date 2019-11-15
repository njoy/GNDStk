Node( ) = default;
Node( Node& ) = default;
Node( const Node& ) = default;
Node( Node&& ) = default;

Node( typename Metadata< AllowedKeys >::MapType& dMap )
try:
  metadata_( dMap ),
  children_( )
{ }
catch( ... ){
  Log::info( "Trouble creating Node with default map." );
  throw;
}

template< typename... Ts >
Node( Ts&&... ts ):
  metadata_(),
  children_( std::vector< Child_t >{ std::forward< Ts >( ts ) }... )
{ }

