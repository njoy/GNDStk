template< const std::vector< std::string >& AllowedKeys, 
          typename ValueType=std::string >
class Metadata{
public:
  using Map_t = std::map< std::string, ValueType >;

private:
 
  Map_t map_;

  #include "GNDStk/Metadata/src/checkKeys.hpp"

public:
  #include "GNDStk/Metadata/src/ctor.hpp"
  #include "GNDStk/Metadata/src/emplace.hpp"

  auto& at( const std::string& key ) { return map_.at( key ); }
  const auto& at( const std::string& key ) const{ return map_.at( key ); }


  auto keys() const { return ranges::view::keys( this->map_ ); }
  auto values() const { return ranges::view::values( this->map_ ); }

  auto size() const { return map_.size(); }

};
