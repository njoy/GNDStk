#ifndef NJOY_GNDSTK_HASHALGORITHM
#define NJOY_GNDSTK_HASHALGORITHM

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class for hash algorithm values
   */
  enum class HashAlgorithm {

    md5 = 1,
    sha1 = 2
  };

  /**
   *  @brief Return whether or not a string is a valid hash algorithm value
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isHashAlgorithm( const std::string& string ) {

    return isSymbol< HashAlgorithm >( string );
  }

  /**
   *  @brief Template specialisation to convert HashAlgorithm to/from strings
   */
  template <>
  class Map< GNDStk::enums::HashAlgorithm > {
  public:

    static inline const std::map< GNDStk::enums::HashAlgorithm,
                                  const std::string > values{

      { GNDStk::enums::HashAlgorithm::md5, "md5" },
      { GNDStk::enums::HashAlgorithm::sha1, "sha1" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::HashAlgorithm > symbols{

      { "md5", GNDStk::enums::HashAlgorithm::md5 },
      { "sha1", GNDStk::enums::HashAlgorithm::sha1 }
    };
  };

} // namespace enums

#endif
