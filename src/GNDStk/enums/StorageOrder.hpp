
#ifndef NJOY_GNDSTK_ENUMS_STORAGEORDER
#define NJOY_GNDSTK_ENUMS_STORAGEORDER

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
   inline bool isStorageOrder(const std::string &string)
   {
      return isSymbol<StorageOrder>(string);
   }

   /**
    *  @brief Template specialisation to convert StorageOrder to/from strings
    */
   template<>
   struct Map<StorageOrder>
   {
      static inline const std::map<StorageOrder,std::string> values {
         { StorageOrder::rowMajor, "rowMajor" },
         { StorageOrder::columnMajor, "columnMajor" }
      };

      static inline const std::map<std::string,StorageOrder> symbols {
         { "rowMajor", StorageOrder::rowMajor },
         { "columnMajor", StorageOrder::columnMajor }
      };
   };

} // namespace enums

#endif
