auto emplace(const std::string& key, const std::string& value){ 
  if( not AllowedKeys.empty() ){
    auto found = ranges::find( AllowedKeys, key );

    if( found == AllowedKeys.end() ){
      Log::error( "Tried to insert invalid key: {}", key );
      throw std::out_of_range( "Key not among allowed values" );
    }
  }
  return map_.emplace( key, value ); 
}
