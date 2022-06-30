
// -----------------------------------------------------------------------------
// Variant<vectors> and variant<scalars> types
// -----------------------------------------------------------------------------

using VariantOfVectors = std::variant<
   // strings
   std::vector<std::string>,

   // chars
   std::vector<char>,

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
>;

// without std::vector<>
using VariantOfScalars = decltype(detail::scalarize(VariantOfVectors{}));
