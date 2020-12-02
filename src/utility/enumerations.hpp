#ifndef NJOY_UTILITY_ENUMERATIONS
#define NJOY_UTILITY_ENUMERATIONS

// system includes

// other includes
#include "Log.hpp"

namespace njoy {
namespace utility {

template < typename Enumeration >
struct EnumerationMap {};

/**
 *  @brief Return whether or not a string is a symbol for an enumeration
 *
 *  @param[in] value    the enumeration value
 *
 *  @return true/false
 */
template < typename Enumeration,
           typename = typename std::enable_if< std::is_enum< Enumeration >::value >::type >
bool isSymbol( const std::string& symbol ) {

  return EnumerationMap< Enumeration >::symbols.find( symbol )
           != EnumerationMap< Enumeration >::symbols.end();
}

/**
 *  @brief Return a string symbol of the enumeration value
 *
 *  @param[in] value    the enumeration value
 *
 *  @return A string symbol representing the enumeration value
 */
template < typename Enumeration,
           typename = typename std::enable_if< std::is_enum< Enumeration >::value >::type >
const std::string& toString( const Enumeration& value ) {

  auto found = EnumerationMap< Enumeration >::values.find( value );
  if ( found == EnumerationMap< Enumeration >::values.end() ) {

    Log::error( "An enumeration value for {} has no registered symbol",
                typeid( Enumeration ).name() );
    throw std::exception();
  }
  return found->second;
}

/**
 *  @brief Return an enumeration value based on a string symbol
 *
 *  @param[in] symbol    the enumeration symbol
 *
 *  @return An enumeration value derived from the string symbol
 */
template < typename Enumeration,
           typename = typename std::enable_if< std::is_enum< Enumeration >::value >::type >
const Enumeration& fromString( const std::string& symbol ) {

  auto found = EnumerationMap< Enumeration >::symbols.find( symbol );
  if ( found == EnumerationMap< Enumeration >::symbols.end() ) {

    Log::error( "An enumeration symbol for {} has no registered value: \'{}\'",
                typeid( Enumeration ).name(), symbol );
    throw std::exception();
  }
  return found->second;
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
template < typename Enumeration,
           typename = typename std::enable_if< std::is_enum< Enumeration >::value >::type >
std::istream &operator>>( std::istream& in, Enumeration& value ) {

  auto position = in.tellg();
  std::string symbol;
  in >> symbol;
  if ( in.fail() ) {

    in.clear();
    in.seekg( position );
    in.setstate( std::ios::failbit );
  }
  else {

    try {

      value = fromString< Enumeration >( symbol );
    }
    catch ( std::exception& ) {

      in.seekg( position );
      in.setstate( std::ios::failbit );
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
template < typename Enumeration,
           typename = typename std::enable_if< std::is_enum< Enumeration >::value >::type >
std::ostream& operator<<( std::ostream& out, const Enumeration& value ) {

  return out << toString( value );
}

} // utility namespace
} // njoy namespace

#endif
