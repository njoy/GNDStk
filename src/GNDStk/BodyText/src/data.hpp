
// -----------------------------------------------------------------------------
// Primary data regarding GNDS "body text"
// -----------------------------------------------------------------------------

// Raw string, directly from "plain character data" in a GNDS file;
// or, a caller can set it directly with a setter.
std::string rawstring;

// vector of <several possibilities>
// Mutable, so that we can reinterpret rawstring if necessary
mutable std::variant<
   // strings
   std::vector<std::string>,

   // integrals
   // Remember that signed char != char in C++
   std::vector<signed char>,
   std::vector<short>,
   std::vector<int>,
   std::vector<long>,
   std::vector<long long>,

   // unsigned integrals
   std::vector<unsigned char>,
   std::vector<unsigned short>,
   std::vector<unsigned int>,
   std::vector<unsigned long>,
   std::vector<unsigned long long>,

   // floating-points
   std::vector<float>,
   std::vector<double>,
   std::vector<long double>
> variant;
