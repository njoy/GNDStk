Node( ) = default;
Node( Node& ) = default;
Node( const Node& ) = default;
Node( Node&& ) = default;

Node( typename Sterile_t::Meta_t::Map_t& dMap )
try:
  Sterile_t( dMap ),
  children_( )
{ }
catch( ... ){
  Log::info( "Trouble creating Node with default map." );
  throw;
}

template< typename... Ts >
Node( Ts&&... ts ):
  Sterile_t(),
  children_( std::vector< Child_t >{ std::forward< Ts >( ts ) }... )
{ }

