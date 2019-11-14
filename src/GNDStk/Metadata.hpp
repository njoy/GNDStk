class Metadata{
private:
  std::map< std::string, std::string > map_;

public:
  auto& at( const std::string& key ) { return map_.at( key ); }
  const auto& at( const std::string& key ) const{ return map_.at( key ); }

  auto emplace(const std::string& key, const std::string& value){ 
    return map_.emplace( key, value ); 
  }

  auto keys() const { return ranges::view::keys( this->map_ ); }
  auto values() const { return ranges::view::values( this->map_ ); }

  auto size() const { return map_.size(); }

};
