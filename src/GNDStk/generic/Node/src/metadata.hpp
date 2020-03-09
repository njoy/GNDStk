void metadata( std::string key, std::string value ){
  this->metadata_.insert_or_assign( key, value );
}

const std::string& metadata( std::string key ) const{
  return this->metadata_.at( key );
}
