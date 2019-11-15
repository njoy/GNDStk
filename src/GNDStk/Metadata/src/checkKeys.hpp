MapType& checkKeys( MapType& defaultMap ){
  auto keys = ranges::view::keys( defaultMap );
  for( const auto& key : keys ){
    if( ranges::find( AllowedKeys, key ) == AllowedKeys.end() ){
      Log::error( "Invalid key {} given in metadata constructor map", key );
      throw std::out_of_range( "Key not among allowed values" );
    }
  }
  return defaultMap;
}
