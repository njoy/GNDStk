
// for internal use
namespace detail {
   inline std::istringstream issNone;
   inline const std::string reset = "\033[0m"; // colors/decorations off
   inline constexpr int defer = 2;
}

// error (declaration; called somewhere in the below #include)
template<int print = detail::defer>
void error(
   const std::string &message,
   std::istream &is = detail::issNone
);

#include "json-diagnostic-detail.hpp"

// exception
struct exception : public std::runtime_error
{
   using runtime_error::runtime_error;
};


// -----------------------------------------------------------------------------
// note, warning, error
// -----------------------------------------------------------------------------

// ------------------------
// note
// Returns std::string
// ------------------------

template<int print = detail::defer>
std::string note(
   const std::string &message,
   std::istream &is = detail::issNone
) {
   static const std::string blue = detail::color(40,160,250);
   return detail::diagnostic(
      is,
      colors ? blue : "",
     "note",
      message,
      colors ? detail::reset : "",
      print == detail::defer ? notes : bool(print)
   );
}

// ------------------------
// warning
// Returns std::string
// ------------------------

template<int print = detail::defer>
std::string warning(
   const std::string &message,
   std::istream &is = detail::issNone
) {
   static const std::string yellow = detail::color(220,220,40);
   return detail::diagnostic(
      is,
      colors ? yellow : "",
     "warning",
      message,
      colors ? detail::reset : "",
      print == detail::defer ? warnings : bool(print)
   );
}

// ------------------------
// error
// Throws
// ------------------------

template<int print>
void error(
   const std::string &message,
   std::istream &is // = detail::issNone; see earlier declaration
) {
   static const std::string red = detail::color(200,40,80);
   const std::string err = detail::diagnostic(
      is,
      colors ? red : "",
     "error",
      message,
      colors ? detail::reset : "",
      print == detail::defer ? errors : bool(print)
   );
   throw exception(err);
}
