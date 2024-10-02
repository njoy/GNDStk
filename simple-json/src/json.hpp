
#ifndef JSON_GUARD
#define JSON_GUARD

#ifndef JSON_INTEGRAL
#define JSON_INTEGRAL int
#endif

#ifndef JSON_FLOATING
#define JSON_FLOATING double
#endif


// -----------------------------------------------------------------------------
// Includes: C++
// -----------------------------------------------------------------------------

#include <cassert>
#include <charconv>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>


// -----------------------------------------------------------------------------
// Classes, types, variables, and flags
// Only classes for which we'll need forward declarations appear here.
// -----------------------------------------------------------------------------

namespace json {

class string;
using key = string;
class value;
using pair = std::pair<key,value>;

// as_literal
// See the read() functions in various classes. These allow for specification
// of which standard JSON types should be read as literals. (A flag indicating
// our literal class is excluded here; it isn't meaningful for these purposes.)
// These are given as ints (not, say, as enumerators) because the expected use
// is in bitwise operations.
namespace as_literal {
   static inline const int
      // JSON standard types
      null    = 0b00000001,
      boolean = 0b00000010,
      number  = 0b00000100,
      string  = 0b00001000,
      array   = 0b00010000,
      object  = 0b00100000,
      // none/all of the above
      none    = 0b00000000,
      all     = 0b00111111;
} // namespace as_literal

// Inline variables
inline int  indent   = 3;
inline bool notes    = true;
inline bool warnings = true;
inline bool errors   = true;
inline bool colors   = true;

// ------------------------
// Shorthand for certain
// std:: constructs
// ------------------------

using usize = std::size_t;

template<bool B, class T = void>
   using require = std::enable_if_t<B,T>;

template<class T, class U>
   inline constexpr bool same = std::is_same_v<T,U>;
template<class T, class U>
   inline constexpr bool assignable = std::is_assignable_v<T,U>;
template<class From, class To>
   inline constexpr bool convertible = std::is_convertible_v<From,To>;
template<class T, class... Args>
   inline constexpr bool constructible = std::is_constructible_v<T,Args...>;
template<class T>
   inline constexpr bool arithmetic = std::is_arithmetic_v<T>;
template<class T>
   inline constexpr bool integral = std::is_integral_v<std::decay_t<T>>;
template<class T>
   inline constexpr bool floating = std::is_floating_point_v<std::decay_t<T>>;


// -----------------------------------------------------------------------------
// Includes: JSON
// -----------------------------------------------------------------------------

// Errors, warnings, notes.
#include "json-diagnostic.hpp"

// Detail constructs that are needed prior to the class definitions below.
#include "json-detail-pre.hpp"

// Class definitions.
#include "json-null.hpp"
#include "json-boolean.hpp"
#include "json-number.hpp"
#include "json-string.hpp"
#include "json-array.hpp"
#include "json-object.hpp"
#include "json-literal.hpp"
#include "json-value.hpp"

// For std::to_chars() and std::from_chars(), if applicable.
#ifdef JSON_CHARS
#include "json-chars.hpp"
#endif

// Detail constructs that require knowledge of the class definitions above.
#include "json-detail-post.hpp"

// Definitions of read() and write() for null, boolean, number, string, array,
// object, literal, and value. Some of these use post-class details included
// just above; that's why they're here. Others don't use such constructs, but
// we placed them here, with the ones that do, for organizational purposes.
#include "json-read.hpp"
#include "json-write.hpp"

// Definitions of object's operator[] and its has() function. Given here,
// not in-class, because they need class value's definition to be complete.
#include "json-object-def.hpp"


// -----------------------------------------------------------------------------
// operator>>
// operator<<
// These make use of the (more-flexible) read() and write() function templates
// in the relevant classes.
// -----------------------------------------------------------------------------

#define JSON_IO(type) \
   inline std::istream &operator>>(std::istream &is, type &j) \
      { j.read<JSON_INTEGRAL,JSON_FLOATING>(is); return is; } \
   inline std::ostream &operator<<(std::ostream &os, const type &j) \
      { j.write(os); return os; }

   JSON_IO(null)
   JSON_IO(boolean)
   JSON_IO(number)
   JSON_IO(string)
   JSON_IO(array)
   JSON_IO(object)
   JSON_IO(literal)
   JSON_IO(value)

#undef JSON_IO

} // namespace json
#endif
