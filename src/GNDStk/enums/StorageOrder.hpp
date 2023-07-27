
#ifndef NJOY_GNDSTK_ENUMS_STORAGEORDER
#define NJOY_GNDSTK_ENUMS_STORAGEORDER

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class giving acceptable storage order values
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
   inline bool isStorageOrder(const std::string &string)
   {
      return isSymbol<StorageOrder>(string);
   }

   /**
    *  @brief Template specialisation to convert StorageOrder to/from strings
    */
   template<>
   struct Map<StorageOrder> {
      static inline const map2string<StorageOrder> values {
         { StorageOrder::rowMajor, "rowMajor" },
         { StorageOrder::columnMajor, "columnMajor" }
      };
      static inline const auto symbols = reverseMap(values);
   };

} // namespace enums

#endif
