
#ifndef NJOY_GNDSTK_FRAME
#define NJOY_GNDSTK_FRAME

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class for reference frame values
   */
  enum class Frame {

    lab = 1,
    centerOfMass = 2
  };

  /**
   *  @brief Return whether or not a string is a valid frame
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isFrame( const std::string& string ) {

    return isSymbol< Frame >( string );
  }

  /**
   *  @brief Template specialisation to convert Frame to/from strings
   */
  template <>
  class Map< GNDStk::enums::Frame > {
  public:

    static inline const std::map< GNDStk::enums::Frame,
                                  const std::string > values{

      { GNDStk::enums::Frame::lab, "lab" },
      { GNDStk::enums::Frame::centerOfMass, "centerOfMass" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::Frame > symbols{

      { "lab", GNDStk::enums::Frame::lab },
      { "centerOfMass", GNDStk::enums::Frame::centerOfMass }
    };
  };

} // namespace enums

#endif
