
#ifndef NJOY_GNDSTK_ENUMS_FRAME
#define NJOY_GNDSTK_ENUMS_FRAME

namespace enums {

   /**
    *  @class
    *  @brief Enumeration class for reference frame values
    */
   enum class Frame {
      lab = 1,
      centerOfMass = 2
   };

   /**
    *  @brief Return whether or not a string is a valid frame
    *
    *  @param[in] string    the string to be verified
    *
    *  @return true/false
    */
   inline bool isFrame(const std::string &string)
   {
      return isSymbol<Frame>(string);
   }

   /**
    *  @brief Template specialisation to convert Frame to/from strings
    */
   template<>
   struct Map<Frame>
   {
      static inline const std::map<Frame,std::string> values {
         { Frame::lab, "lab" },
         { Frame::centerOfMass, "centerOfMass" }
      };

      static inline const std::map<std::string,Frame> symbols {
         { "lab", Frame::lab },
         { "centerOfMass", Frame::centerOfMass }
      };
   };

} // namespace enums

#endif
