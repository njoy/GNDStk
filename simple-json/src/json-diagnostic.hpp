
// for internal use
namespace detail {
   inline std::istringstream iss;
}

// error (declaration; for use in the below #include)
inline void error(const std::string &message, std::istream &is = detail::iss);

#include "json-diagnostic-detail.hpp"

// error (definition)
inline void error(const std::string &message, std::istream &is)
{
   static const std::string red = detail::color(200,40,80);
   detail::diagnostic(is, message, red + "error");
   throw std::exception();
}

// warning
inline void warning(const std::string &message, std::istream &is = detail::iss)
{
   static const std::string yellow = detail::color(220,220,40);
   detail::diagnostic(is, message, yellow + "warning");
}

// note
inline void note(const std::string &message, std::istream &is = detail::iss)
{
   static const std::string blue = detail::color(40,160,250);
   detail::diagnostic(is, message, blue + "note");
}
