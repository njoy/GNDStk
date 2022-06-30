
#include "GNDStk/Support/src/detail.hpp"

// -----------------------------------------------------------------------------
// Miscellaneous support constructs for our various version-specific GNDS
// Standard Interfaces. These could perhaps have gone into utility.hpp
// or elsewhere, but it seemed appropriate that they have their own place.
// -----------------------------------------------------------------------------

using Integer32  = int;
using UInteger32 = unsigned;
using Float64    = double;
using UTF8Text   = std::string;
using XMLName    = std::string;


// -----------------------------------------------------------------------------
// Fraction32
// -----------------------------------------------------------------------------

class Fraction32 {
public:
   int num;
   int den;

   explicit Fraction32(const int n = 0, const int d = 1) :
      num(n), den(d)
   {
      if (den == 0) {
         // Let's just make this a warning; perhaps with experience
         // we'll decide it should be an error.
         log::warning("Fraction32 {}/0 initialized with denominator of 0", num);
         log::ctor("Fraction32");
         // not for warning: throw std::exception{};
      }
      // We could write something to reduce the fraction, e.g. 2/4
      // to 1/2, but that probably isn't important for these.
   }

   int numerator  () const { return num; }
   int denominator() const { return den; }
};

// operator>>
inline std::istream &operator>>(std::istream &is, Fraction32 &obj)
{
   try {
      int num, den;
      is >> num;
      if (is.get() == '/') {
         is >> den;
      } else {
         is.unget();
         den = 1;
      }
      obj = Fraction32(num,den);
   } catch (...) {
      log::function("std::istream >> Fraction32");
      throw;
   }

   return is;
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const Fraction32 &obj)
{
   os << obj.num;
   if (obj.den != 1)
      os << '/' << obj.den;
   return os;
}


// -----------------------------------------------------------------------------
// IntegerTuple
// -----------------------------------------------------------------------------

class IntegerTuple {
public:
   std::vector<int> vec;

   // ------------------------
   // constructors
   // ------------------------

   // fixme
   // The GNDS manual says that "any integer (0-9)" is allowed. If the 0-9
   // part is really correct, then I should probably throw an error, or at
   // least print a warning) if a provided value is outside of that range.

   IntegerTuple()
   { }

   explicit IntegerTuple(const int i)
   {
      vec.push_back(i);
   }

   IntegerTuple(const int i, const int j)
   {
      vec.push_back(i);
      vec.push_back(j);
   }

   IntegerTuple(const int i, const int j, const int k)
   {
      vec.push_back(i);
      vec.push_back(j);
      vec.push_back(k);
   }

   explicit IntegerTuple(const std::vector<int> &vec) :
      vec(vec)
   { }

   template<std::size_t N>
   explicit IntegerTuple(const std::array<int,N> &arr) :
      vec(arr.begin(), arr.end())
   { }

   // ------------------------
   // miscellaneous functions
   // ------------------------

   // size
   auto size() const { return vec.size(); }

   // operator[]
   // we'll use at(), under-the-hood, so that out-of-range ==> exception
   const int &operator[](const std::size_t i) const
      { return vec.at(i); }
   int &operator[](const std::size_t i)
      { return vec.at(i); }

   // push
   int &push(const int n)
   {
      vec.push_back(n);
      return vec.back();
   }

   // clear
   IntegerTuple &clear()
   {
      vec.clear();
      return *this;
   }
};

// operator>>
inline std::istream &operator>>(std::istream &is, IntegerTuple &obj)
{
   obj.clear();
   try {
      int n;
      is >> n;
      obj.push(n);

      while (true) {
         if (is.get() == ',') {
            is >> n;
            obj.push(n);
         } else {
            is.unget();
            break;
         }
      }
   } catch (...) {
      log::function("std::istream >> IntegerTuple");
      throw;
   }

   return is;
}

// operator<<
inline std::ostream &operator<<(std::ostream &os, const IntegerTuple &obj)
{
   std::size_t n = 0;
   while (n < obj.size())
      os << (n ? "," : "") << obj[n];
   return os;
}
