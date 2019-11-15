const auto& metadata() const{
  return this->metadata_;
}

const auto& metadata( std::string key ) const{
  return this->metadata_.at( key );
}

auto metadata( std::string key, std::string value ){
  return this->metadata_.emplace( key, value );
}
