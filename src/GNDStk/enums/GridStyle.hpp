
#ifndef NJOY_GNDSTK_GRIDSTYLE
#define NJOY_GNDSTK_GRIDSTYLE

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class giving acceptable grid style values
   */
  enum class GridStyle {

    none,
    points,
    boundaries,
    parameters
  };

  /**
   *  @brief Return whether or not a string is a valid grid style
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isGridStyle( const std::string& string ) {

    return isSymbol< GridStyle >( string );
  }

  /**
   *  @brief Template specialisation to convert GridStyle to/from strings
   */
  template <>
  class Map< GNDStk::enums::GridStyle > {
  public:

    static inline const std::map< GNDStk::enums::GridStyle,
                                  const std::string > values{

      { GNDStk::enums::GridStyle::none,       "none" },
      { GNDStk::enums::GridStyle::points,     "points" },
      { GNDStk::enums::GridStyle::boundaries, "boundaries" },
      { GNDStk::enums::GridStyle::parameters, "parameters" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::GridStyle > symbols{

      { "none",  GNDStk::enums::GridStyle::none },
      { "points", GNDStk::enums::GridStyle::points },
      { "boundaries", GNDStk::enums::GridStyle::boundaries },
      { "parameters", GNDStk::enums::GridStyle::parameters }
    };
  };

} // namespace enums

#endif
