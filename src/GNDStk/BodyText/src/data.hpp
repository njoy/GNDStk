
// -----------------------------------------------------------------------------
// Variant type
// -----------------------------------------------------------------------------

using variant_t = std::variant<
   // strings
   std::vector<std::string>,

   // integrals
   // Remember that signed char != char in C++
   // As far as I know, we don't need to support plain chars
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
>;


// -----------------------------------------------------------------------------
// Primary data regarding GNDS "body text"
// -----------------------------------------------------------------------------

// Raw string, directly from "plain character data" in a GNDS file.
// Also, we'll allow a caller to set this directly with a setter.
std::string rawstring;

// vector of <several possibilities>.
// Mutable, so that we can defer processing of the raw string into a vector
// until a caller *asks* for the vector, and also so that we can reinterpret
// data as being of a different type, if we really wish to do so.
mutable variant_t variant;
