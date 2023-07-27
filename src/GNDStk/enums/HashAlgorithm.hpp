
#ifndef NJOY_GNDSTK_ENUMS_HASHALGORITHM
#define NJOY_GNDSTK_ENUMS_HASHALGORITHM

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
   inline bool isHashAlgorithm(const std::string &string)
   {
      return isSymbol<HashAlgorithm>(string);
   }

   /**
    *  @brief Template specialisation to convert HashAlgorithm to/from strings
    */
   template<>
   struct Map<HashAlgorithm> {
      static inline const map2string<HashAlgorithm> values {
         { HashAlgorithm::md5, "md5" },
         { HashAlgorithm::sha1, "sha1" }
      };
      static inline const auto symbols = reverseMap(values);
   };

} // namespace enums

#endif
