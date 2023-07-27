
#ifndef NJOY_GNDSTK_ENUMS
#define NJOY_GNDSTK_ENUMS

namespace enums {

// map2string
template<class T>
using map2string = std::map<T,std::string>;

// reverseMap
template<class KEY, class VALUE>
std::map<VALUE,KEY> reverseMap(const std::map<KEY,VALUE> &in)
{
   std::map<VALUE,KEY> out;
   for (const auto &pair : in)
      out.insert(std::make_pair(pair.second,pair.first));
   return out;
}

/**
 *  @brief Forward declaration of the templated enumeration Map used to convert
 *         enumeration values to/from string
 */
template<class ENUM>
struct Map { };

/**
 *  @brief Return whether or not a string is a symbol for an enumeration
 *
 *  @param[in] value    the enumeration value
 *
 *  @return true/false
 */
template<class ENUM, class = std::enable_if_t<std::is_enum_v<ENUM>>>
bool isSymbol(const std::string &symbol)
{
   return Map<ENUM>::symbols.find(symbol) != Map<ENUM>::symbols.end();
}

/**
 *  @brief Return a string symbol of the enumeration value
 *
 *  @param[in] value    the enumeration value
 *
 *  @return A string symbol representing the enumeration value
 */
template<class ENUM, class = std::enable_if_t<std::is_enum_v<ENUM>>>
const std::string &toString(const ENUM &value)
{
   const auto found = Map<ENUM>::values.find(value);
   if (found != Map<ENUM>::values.end())
      return found->second;
   log::error("An enumeration value for {} has no registered symbol",
              typeid(ENUM).name());
   throw std::exception();
}

/**
 *  @brief Return an enumeration value based on a string symbol
 *
 *  @param[in] symbol    the enumeration symbol
 *
 *  @return An enumeration value derived from the string symbol
 */
template<class ENUM, class = std::enable_if_t<std::is_enum_v<ENUM>>>
const ENUM &fromString(const std::string &symbol)
{
   const auto found = Map<ENUM>::symbols.find(symbol);
   if (found != Map<ENUM>::symbols.end())
      return found->second;
   log::error("An enumeration symbol for {} has no registered value: \"{}\"",
              typeid(ENUM).name(), symbol);
   throw std::exception();
}

/**
 *  @brief operator>> for enumerations
 *
 *  @param[in] in       the input stream
 *  @param[in] value    the enumeration value
 *
 *  @return the input stream (position is unchanged and failbit is set if no
 *          enumeration value could be read)
 */
template<class ENUM, class = std::enable_if_t<std::is_enum_v<ENUM>>>
std::istream &operator>>(std::istream &in, ENUM &value)
{
   const auto position = in.tellg();
   std::string symbol;

   in >> symbol;
   if (in.fail()) {
      in.clear();
      in.seekg(position);
      in.setstate(std::ios::failbit);
   } else {
      try {
         value = fromString<ENUM>(symbol);
      } catch (...) {
         in.seekg(position);
         in.setstate(std::ios::failbit);
      }
   }
   return in;
}

/**
 *  @brief operator<< for enumerations
 *
 *  @param[in] in       the input stream
 *  @param[in] value    the enumeration value
 *
 *  @return the output stream
 */
template<class ENUM, class = std::enable_if_t<std::is_enum_v<ENUM>>>
std::ostream &operator<<(std::ostream &out, const ENUM &value)
{
   return out << toString(value);
}

} // namespace enums

#endif
