
#ifndef NJOY_GNDSTK_STORAGEORDER
#define NJOY_GNDSTK_STORAGEORDER

namespace enums {

  /**
   *  @class
   *  @brief Enumeration class giving acceptable storage order values
   *
   *  See GNDS v1.9 specifications section 3.5.3
   */
  enum class StorageOrder {

    rowMajor = 1,
    columnMajor = 2
  };

  /**
   *  @brief Return whether or not a string is a valid storage order
   *
   *  @param[in] string    the string to be verified
   *
   *  @return true/false
   */
  inline bool isStorageOrder( const std::string& string ) {

    return isSymbol< StorageOrder >( string );
  }

  /**
   *  @brief Template specialisation to convert StorageOrder to/from strings
   */
  template <>
  class Map< GNDStk::enums::StorageOrder > {
  public:

    static inline const std::map< GNDStk::enums::StorageOrder,
                                  const std::string > values{

      { GNDStk::enums::StorageOrder::rowMajor, "rowMajor" },
      { GNDStk::enums::StorageOrder::columnMajor, "columnMajor" }
    };

    static inline const std::map< const std::string,
                                  GNDStk::enums::StorageOrder > symbols{

      { "rowMajor", GNDStk::enums::StorageOrder::rowMajor },
      { "columnMajor", GNDStk::enums::StorageOrder::columnMajor }
    };
  };

} // namespace enums

#endif
