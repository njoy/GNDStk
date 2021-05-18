
#ifndef NJOY_GNDSTK_ENCODING
#define NJOY_GNDSTK_ENCODING

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class giving acceptable encoding values
   *
   *  See GNDS v1.9 specifications section 3.5.3
   */
  enum class Encoding {

    ascii = 1,
    utf8 = 2
  };

  /**
   *  @brief Return whether or not a string is a valid encoding
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isEncoding( const std::string& string ) {

    return isSymbol< Encoding >( string );
  }

  /**
   *  @brief Template specialisation to convert Encoding to/from strings
   */
  template <>
  class Map< GNDStk::enums::Encoding > {
  public:

    static inline const std::map< GNDStk::enums::Encoding,
                                  const std::string > values{

      { GNDStk::enums::Encoding::ascii, "ascii" },
      { GNDStk::enums::Encoding::utf8, "utf8" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::Encoding > symbols{

      { "ascii", GNDStk::enums::Encoding::ascii },
      { "utf8", GNDStk::enums::Encoding::utf8 }
    };
  };

} // namespace enums

#endif
