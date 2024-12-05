
#ifndef JSON_GUARD
#define JSON_GUARD

#ifndef JSON_INTEGRAL
#define JSON_INTEGRAL int
#endif

#ifndef JSON_FLOATING
#define JSON_FLOATING double
#endif

// Includes: C++
#include <cassert>
#include <cctype>
#include <charconv>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>


// -----------------------------------------------------------------------------
// Some variables, classes, etc.
// -----------------------------------------------------------------------------

namespace json {

// Variables: for JSON content
inline int  indent = 3;
inline bool colors = false;

// Variables: for diagnostics on/off
inline bool notes    = true;
inline bool warnings = true;
inline bool errors   = true;

// Variables: for diagnostics properties
namespace diagnostics {
   inline int  indent = json::indent;
   inline bool colors = true;
}

// Variables: for floating point to_chars
#ifdef JSON_CHARS
   inline constexpr std::chars_format fixed      = std::chars_format::fixed;
   inline constexpr std::chars_format scientific = std::chars_format::scientific;
   inline constexpr std::chars_format general    = std::chars_format::general;
   inline           std::chars_format format     = general;
#endif

// Classes, types
template<bool>
class String;
using key = String<false>;
class value;
using pair = std::pair<key,value>;

// ------------------------
// Shorthand for some
// std:: constructs
// ------------------------

// Alias for the ever-important std::enable_if_t.
template<bool B, class T = void>
   using require = std::enable_if_t<B,T>;

// Aliases for miscellaneous std::is_*_v bools.
template<class T, class U>
   inline constexpr bool same = std::is_same_v<T,U>;
template<class T, class U>
   inline constexpr bool assignable = std::is_assignable_v<T,U>;
template<class From, class To>
   inline constexpr bool convertible = std::is_convertible_v<From,To>;
template<class T, class... Args>
   inline constexpr bool constructible = std::is_constructible_v<T,Args...>;
template<class T>
   inline constexpr bool integral = std::is_integral_v<T>;
template<class T>
   inline constexpr bool floating = std::is_floating_point_v<T>;

// See https://stackoverflow.com/questions/42797279
using std::size_t;


// -----------------------------------------------------------------------------
// Includes: JSON
// -----------------------------------------------------------------------------

// Errors, warnings, notes.
#include "json-diagnostic.hpp"

// Detail constructs that are needed prior to the class definitions below.
class literal;
#include "json-detail-pre.hpp"

// invar
template<class T, class VARIANT>
inline constexpr bool invar = detail::inVariant<T,VARIANT>::count;

// Class definitions.
#include "json-number.hpp"
#include "json-literal.hpp"
#include "json-null.hpp"
#include "json-boolean.hpp"
#include "json-string.hpp"
#include "json-array.hpp"
#include "json-object.hpp"
#include "json-value.hpp"
#include "json-value-make.hpp"
#include "json-chars.hpp"

// Detail constructs that require knowledge of the class definitions above.
#include "json-detail-post.hpp"

// Definitions of read() and print() for null, boolean, number, string, array,
// object, literal, and value. Some of these use post-class details included
// just above; this is why we put them here.
#include "json-read.hpp"
#include "json-print.hpp"

// Definitions of object's operator[] and its has() function. Given here,
// not in-class, because they need class value's definition to be complete.
#include "json-object-def.hpp"


// -----------------------------------------------------------------------------
// Finish stream output. Via read(), they needed literal's definition.
// -----------------------------------------------------------------------------

#undef JSON_IO
#define JSON_IO(type) \
   inline std::istream &operator>>(std::istream &is, type &j) \
      { j.template read<JSON_INTEGRAL,JSON_FLOATING>(is); return is; }

JSON_IO(null)
JSON_IO(boolean)
JSON_IO(number)
JSON_IO(array)
JSON_IO(object)
JSON_IO(literal)
JSON_IO(value)

#undef JSON_IO

template<bool b>
inline std::istream &operator>>(std::istream &is, String<b> &j)
   { j.template read<JSON_INTEGRAL,JSON_FLOATING>(is); return is; }

} // namespace json
#endif
