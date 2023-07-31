
#ifndef NJOY_GNDSTK_ENUMS_DATETYPE
#define NJOY_GNDSTK_ENUMS_DATETYPE

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class for date type values
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
    *  @brief Return whether or not a string is a valid date type
    *
    *  @param[in] string    the string to be verified
    *
    *  @return true/false
    */
   inline bool isDateType(const std::string &string)
   {
      return isSymbol<DateType>(string);
   }

   /**
    *  @brief Template specialisation to convert DateType to/from strings
    */
   template<>
   struct Map<DateType>
   {
      static inline const std::map<DateType,std::string> values {
         { DateType::accepted, "accepted" },
         { DateType::available, "available" },
         { DateType::copyrighted, "copyrighted" },
         { DateType::collected, "collected" },
         { DateType::created, "created" },
         { DateType::issued, "issued" },
         { DateType::submitted, "submitted" },
         { DateType::updated, "updated" },
         { DateType::valid, "valid" },
         { DateType::withdrawn, "withdrawn" }
      };

      static inline const std::map<std::string,DateType> symbols {
         { "accepted", DateType::accepted },
         { "available", DateType::available },
         { "copyrighted", DateType::copyrighted },
         { "collected", DateType::collected },
         { "created", DateType::created },
         { "issued", DateType::issued },
         { "submitted", DateType::submitted },
         { "updated", DateType::updated },
         { "valid", DateType::valid },
         { "withdrawn", DateType::withdrawn }
      };
   };

} // namespace enums

#endif
