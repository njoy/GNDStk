
#ifndef NJOY_GNDSTK_ENUMS_GRIDSTYLE
#define NJOY_GNDSTK_ENUMS_GRIDSTYLE

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class giving acceptable grid style values
    */
   enum class GridStyle {
      none,
      link,
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
   inline bool isGridStyle(const std::string &string)
   {
      return isSymbol<GridStyle>(string);
   }

   /**
    *  @brief Template specialisation to convert GridStyle to/from strings
    */
   template<>
   struct Map<GridStyle> {
      static inline const map2string<GridStyle> values {
         { GridStyle::none, "none" },
         { GridStyle::link, "link" },
         { GridStyle::points, "points" },
         { GridStyle::boundaries, "boundaries" },
         { GridStyle::parameters, "parameters" }
      };
      static inline const auto symbols = reverseMap(values);
   };

} // namespace enums

#endif
