Node( ) = default;
Node( Node& ) = default;
Node( const Node& ) = default;
Node( Node&& ) = default;

using Sterile_t::Sterile_t;

Node( typename Sterile_t::Meta_t::Map_t& dMap )
try:
  Sterile_t( dMap ),
  children_( )
{ }
catch( ... ){
  Log::info( "Trouble creating Node with default map." );
  throw;
}
