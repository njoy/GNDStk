
// -----------------------------------------------------------------------------
// Variant type
// todo: Possibly reduce to int, double, and string, if we're certain users
// will never care about the others. On the other hand: most of the related
// code, e.g. for visiting the variant, won't simplify by doing that.
// -----------------------------------------------------------------------------

public:

using variant_t = std::variant<
   // strings
   std::vector<std::string>,

   // integrals
   // Remember that signed char != char in C++
   // As far as I know, we'll never care about supporting plain chars here
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

// todo Should figure out the following automatically, from the above
using variant_scalar_t = std::variant<
   // strings
   std::string,

   // integrals
   signed char,
   short,
   int,
   long,
   long long,

   // unsigned integrals
   unsigned char,
   unsigned short,
   unsigned int,
   unsigned long,
   unsigned long long,

   // floating-points
   float,
   double,
   long double
>;


// -----------------------------------------------------------------------------
// Primary data regarding GNDS "body text"
// -----------------------------------------------------------------------------

private:

// Raw string, directly from "plain character data" in a GNDS file.
// We'll allow callers to set this directly by using a setter.
std::string rawstring;

// Vector of <several possibilities>.
// Mutable, so that we can defer processing of the raw string into a vector
// until, and unless, a caller *asks* for the vector.
mutable variant_t variant;
