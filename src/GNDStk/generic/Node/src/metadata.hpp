const std::string& metadata( std::string key ) const{
  return this->metadata_.at( key );
}

void metadata( std::string key, std::string value ){
  this->metadata_.emplace( key, value );
}
