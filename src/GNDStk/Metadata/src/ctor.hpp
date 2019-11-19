Metadata() = default;
Metadata( Metadata& ) = default;
Metadata( const Metadata& ) = default;
Metadata( Metadata&& ) = default;

Metadata( Map_t& map )
try:
  map_( checkKeys( map ) ){
  } catch( std::exception& ){
    Log::info( "Trouble constructing Metadata given default map." );
    throw;
  }

Metadata( Map_t&& map )
try:
  map_( checkKeys( map ) ){
  } catch( std::exception& ){
    Log::info( "Trouble constructing Metadata given default map." );
    throw;
  }

Metadata( 
  std::initializer_list< std::pair< const std::string, ValueType > >&& map )
try:
  Metadata( Map_t{ map } ){
  } catch( std::exception& ){
    Log::info( "Trouble constructing Metadata given initializer list." );
    throw;
  }
