
#ifndef NJOY_GNDSTK_ENUMS_ENUMERATION
#define NJOY_GNDSTK_ENUMS_ENUMERATION

namespace enums {

/**
 *  @brief Forward declaration of the templated enumeration Map used to convert
 *         enumeration values to/from string
 */
template < typename Enumeration >
class Map {};

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

  return Map< Enumeration >::symbols.find( symbol )
           != Map< Enumeration >::symbols.end();
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

  auto found = Map< Enumeration >::values.find( value );
  if ( found == Map< Enumeration >::values.end() ) {

    log::error( "An enumeration value for {} has no registered symbol",
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

  auto found = Map< Enumeration >::symbols.find( symbol );
  if ( found == Map< Enumeration >::symbols.end() ) {

    log::error( "An enumeration symbol for {} has no registered value: \"{}\"",
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

} // namespace enums

#endif
