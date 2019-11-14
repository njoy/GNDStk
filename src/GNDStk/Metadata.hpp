class Metadata{
private:
  std::map< std::string, std::string > map_;

public:

  auto emplace(const std::string& key, const std::string& value){ 
    return map_.emplace( key, value ); 
  }

  #include "GNDStk/Metadata/src/at.hpp"
};
