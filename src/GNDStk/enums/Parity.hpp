
#ifndef NJOY_GNDSTK_ENUMS_PARITY
#define NJOY_GNDSTK_ENUMS_PARITY

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
   inline bool isParity(const std::string &string)
   {
      return isSymbol<Parity>(string);
   }

   /**
    *  @brief Template specialisation to convert Parity to/from strings
    */
   template<>
   struct Map<Parity> {
      static inline const map2string<Parity> values {
         { Parity::minus, "-1" },
         { Parity::plus, "+1" }
      };
      static inline const auto symbols = reverseMap(values);
   };

} // namespace enums

#endif
