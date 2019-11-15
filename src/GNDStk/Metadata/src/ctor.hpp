Metadata() = default;
Metadata( Metadata& ) = default;
Metadata( const Metadata& ) = default;
Metadata( Metadata&& ) = default;

Metadata( MapType& map )
try:
  map_( checkKeys( map ) ){

  } catch( std::exception& ){
    Log::info( "Trouble constructing Metadata given default map." );
    throw;
  }
