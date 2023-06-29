#ifndef NJOY_GNDSTK_PARITY
#define NJOY_GNDSTK_PARITY

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class for particle parity values
   */
  enum class Parity {

    minus = -1,
    plus = +1
  };

  /**
   *  @brief Return whether or not a string is a valid parity
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isParity( const std::string& string ) {

    return isSymbol< Parity >( string );
  }

  /**
   *  @brief Template specialisation to convert Parity to/from strings
   */
  template <>
  class Map< GNDStk::enums::Parity > {
  public:

    static inline const std::map< GNDStk::enums::Parity,
                                  const std::string > values{

      { GNDStk::enums::Parity::minus, "-1" },
      { GNDStk::enums::Parity::plus, "+1" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::Parity > symbols{

      { "-1", GNDStk::enums::Parity::minus },
      { "+1", GNDStk::enums::Parity::plus }
    };
  };

} // namespace enums

#endif
