
namespace enums {

// -----------------------------------------------------------------------------
// Re: maps
// -----------------------------------------------------------------------------

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
 *  @brief Forward declaration of the templated enumeration map
 *         used to convert enumeration values to/from strings
 */
template<class ENUM>
struct EnumMap { };


// -----------------------------------------------------------------------------
// getEnum*
// -----------------------------------------------------------------------------

// getEnumClass
template<class T>
struct getEnumClass;

template<template<class> class C, class T>
struct getEnumClass<C<T>>
{
   using type = T;
};

// getEnum
template<class C>
using getEnum = typename getEnumClass<C>::type;


// -----------------------------------------------------------------------------
// isSymbolForEnum
// enum2string
// string2enum
// -----------------------------------------------------------------------------

/**
 *  @brief Return whether or not a string is a symbol for an enumeration
 *
 *  @param[in] value   The enumeration value
 *
 *  @return true/false
 */
template<class ENUM, class = std::enable_if_t<std::is_enum_v<ENUM>>>
bool isSymbolForEnum(const std::string &symbol)
{
   return EnumMap<ENUM>::symbols.find(symbol) != EnumMap<ENUM>::symbols.end();
}

/**
 *  @brief Return a string symbol of the enumeration value
 *
 *  @param[in] value   The enumeration value
 *
 *  @return A string symbol representing the enumeration value
 */
template<class ENUM, class = std::enable_if_t<std::is_enum_v<ENUM>>>
const std::string &enum2string(const ENUM &value)
{
   const auto found = EnumMap<ENUM>::values.find(value);
   if (found != EnumMap<ENUM>::values.end())
      return found->second;
   log::error("An enumeration value for {} has no registered symbol",
              typeid(ENUM).name());
   throw std::exception();
}

/**
 *  @brief Return an enumeration value based on a string symbol
 *
 *  @param[in] symbol   The enumeration symbol
 *
 *  @return An enumeration value derived from the string symbol
 */
template<class ENUM, class = std::enable_if_t<std::is_enum_v<ENUM>>>
const ENUM &string2enum(const std::string &symbol)
{
   const auto found = EnumMap<ENUM>::symbols.find(symbol);
   if (found != EnumMap<ENUM>::symbols.end())
      return found->second;
   log::error("An enumeration symbol for {} has no registered value: \"{}\"",
              typeid(ENUM).name(), symbol);
   throw std::exception();
}


// -----------------------------------------------------------------------------
// operator>>
// operator<<
// -----------------------------------------------------------------------------

/**
 *  @brief operator>> for enumerations
 *
 *  @param[in] is      The input stream
 *  @param[in] value   The enumeration value
 *
 *  @return the input stream (position is unchanged and failbit is set if no
 *          enumeration value could be read)
 */
// Uses string2enum
template<class ENUM, class = std::enable_if_t<std::is_enum_v<ENUM>>>
std::istream &operator>>(std::istream &is, ENUM &value)
{
   const auto position = is.tellg();
   std::string symbol;

   is >> symbol;
   if (is.fail()) {
      is.clear();
      is.seekg(position);
      is.setstate(std::ios::failbit);
   } else {
      try {
         value = string2enum<ENUM>(symbol);
      } catch (...) {
         is.seekg(position);
         is.setstate(std::ios::failbit);
      }
   }
   return is;
}

/**
 *  @brief operator<< for enumerations
 *
 *  @param[in] os      The output stream
 *  @param[in] value   The enumeration value
 *
 *  @return the output stream
 */
// Uses enum2string
template<class ENUM, class = std::enable_if_t<std::is_enum_v<ENUM>>>
std::ostream &operator<<(std::ostream &os, const ENUM &value)
{
   return os << enum2string(value);
}

} // namespace enums

using enums::operator>>;
using enums::operator<<;
