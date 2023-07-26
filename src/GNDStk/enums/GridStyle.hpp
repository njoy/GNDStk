
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
   struct Map<GridStyle>
   {
      static inline const std::map<GridStyle,std::string> values {
         { GridStyle::none, "none" },
         { GridStyle::link, "link" },
         { GridStyle::points, "points" },
         { GridStyle::boundaries, "boundaries" },
         { GridStyle::parameters, "parameters" }
      };

      static inline const std::map<std::string,GridStyle> symbols {
         { "none", GridStyle::none },
         { "link", GridStyle::link },
         { "points", GridStyle::points },
         { "boundaries", GridStyle::boundaries },
         { "parameters", GridStyle::parameters }
      };
   };

} // namespace enums

#endif
