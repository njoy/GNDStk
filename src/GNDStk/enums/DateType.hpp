#ifndef NJOY_GNDSTK_DATETYPE
#define NJOY_GNDSTK_DATETYPE

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class for interpolation qualifier values
   */
  enum class DateType {

    accepted = 1,
    available,
    copyrighted,
    collected,
    created,
    issued,
    submitted,
    updated,
    valid,
    withdrawn
  };

  /**
   *  @brief Return whether or not a string is a valid parity
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isDateType( const std::string& string ) {

    return isSymbol< DateType >( string );
  }

  /**
   *  @brief Template specialisation to convert DateType to/from strings
   */
  template <>
  class Map< GNDStk::enums::DateType > {
  public:

    static inline const std::map< GNDStk::enums::DateType,
                                  const std::string > values{

      { GNDStk::enums::DateType::accepted, "accepted" },
      { GNDStk::enums::DateType::available, "available" },
      { GNDStk::enums::DateType::copyrighted, "copyrighted" },
      { GNDStk::enums::DateType::collected, "collected" },
      { GNDStk::enums::DateType::created, "created" },
      { GNDStk::enums::DateType::issued, "issued" },
      { GNDStk::enums::DateType::submitted, "submitted" },
      { GNDStk::enums::DateType::updated, "updated" },
      { GNDStk::enums::DateType::valid, "valid" },
      { GNDStk::enums::DateType::withdrawn, "withdrawn" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::DateType > symbols{

      { "accepted", GNDStk::enums::DateType::accepted },
      { "available", GNDStk::enums::DateType::available },
      { "copyrighted", GNDStk::enums::DateType::copyrighted },
      { "collected", GNDStk::enums::DateType::collected },
      { "created", GNDStk::enums::DateType::created },
      { "issued", GNDStk::enums::DateType::issued },
      { "submitted", GNDStk::enums::DateType::submitted },
      { "updated", GNDStk::enums::DateType::updated },
      { "valid", GNDStk::enums::DateType::valid },
      { "withdrawn", GNDStk::enums::DateType::withdrawn }
    };
  };

} // namespace enums

#endif
