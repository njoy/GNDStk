
// -----------------------------------------------------------------------------
// This file contains miscellaneous types and classes that help with our
// high-level GNDS interface.
// -----------------------------------------------------------------------------

// Use fixed-width integral types to align with GNDS specs
using Integer32  = int32_t;
using UInteger32 = uint32_t;

// C++ presently has no fixed-width floating point types;
// this should suffice
using Float64 = double;

// For now; perhaps consider specialty types at some point
using UTF8Text = std::string;
using XMLName  = std::string;
using bodyText = std::string;



// -----------------------------------------------------------------------------
// interpolation_t
// For the GNDS basic data type "interpolation"
// -----------------------------------------------------------------------------

enum class interpolation_t {
   unknown,
   flat,
   charged_particle,
   lin_lin,
   lin_log,
   log_lin,
   log_log
};


// ------------------------
// operator>>
// ------------------------

// Should perhaps just make a std::map for operator>> and operator<<

inline std::istream &operator>>(std::istream &is, interpolation_t &obj)
{
   std::string str;
   is >> str;

   if (str == "flat") 
      obj = interpolation_t::flat;
   else if (str == "charged-particle")
      obj = interpolation_t::charged_particle;
   else if (str == "lin-lin")
      obj = interpolation_t::lin_lin;
   else if (str == "lin-log")
      obj = interpolation_t::lin_log;
   else if (str == "log-lin")
      obj = interpolation_t::log_lin;
   else if (str == "log-log")
      obj = interpolation_t::log_log;
   else {
      obj = interpolation_t::unknown;
      if (!is)
         log::error(
           "Error reading interpolation value from std::istream");
      else
         log::error(
           "Unrecognized value {} for interpolation. Valid values are:\n"
           "flat, charged-particle, lin-lin, lin-log, log-lin, log-log.", str);
      log::function("std::istream >> interpolation_t");
      throw std::exception{};
   }

   return is;
}


// ------------------------
// operator<<
// ------------------------

inline std::ostream &operator<<(std::ostream &os, const interpolation_t &obj)
{
   if (obj == interpolation_t::flat)
      os << "flat";
   else if (obj == interpolation_t::charged_particle)
      os << "charged-particle";
   else if (obj == interpolation_t::lin_lin)
      os << "lin-lin";
   else if (obj == interpolation_t::lin_log)
      os << "lin-log";
   else if (obj == interpolation_t::log_lin)
      os << "log-lin";
   else if (obj == interpolation_t::log_log)
      os << "log-log";
   else {
      if (!os)
         log::error(
           "Error writing interpolation value to std::ostream");
      else
         log::error(
           "Unknown value for interpolation. Valid values are:\n"
           "flat, charged-particle, lin-lin, lin-log, log-lin, log-log.");
      log::function("std::ostream << interpolation_t");
      throw std::exception{};
   }

   return os;
}



// -----------------------------------------------------------------------------
// Fraction32
// -----------------------------------------------------------------------------

class Fraction32 {
public:
   Integer32 num;
   Integer32 den;

   explicit Fraction32(const Integer32 n = 0, const Integer32 d = 1) :
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

   Integer32 numerator  () const { return num; }
   Integer32 denominator() const { return den; }
};


// ------------------------
// operator>>
// ------------------------

inline std::istream &operator>>(std::istream &is, Fraction32 &obj)
{
   try {
      Integer32 num, den;
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


// ------------------------
// operator<<
// ------------------------

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
   std::vector<Integer32> vec;

   // ------------------------
   // constructors
   // ------------------------

   // fixme
   // The GNDS manual says that "any integer (0-9)" is allowed. If the 0-9
   // part is really correct, then I should probably throw an error, or at
   // least print a warning) if a provided value is outside of that range.

   IntegerTuple()
   { }

   explicit IntegerTuple(const Integer32 i)
   {
      vec.push_back(i);
   }

   IntegerTuple(const Integer32 i, const Integer32 j)
   {
      vec.push_back(i);
      vec.push_back(j);
   }

   IntegerTuple(const Integer32 i, const Integer32 j, const Integer32 k)
   {
      vec.push_back(i);
      vec.push_back(j);
      vec.push_back(k);
   }

   explicit IntegerTuple(const std::vector<Integer32> &vec) :
      vec(vec)
   { }

   template<std::size_t N>
   explicit IntegerTuple(const std::array<Integer32,N> &arr) :
      vec(arr.begin(), arr.end())
   { }

   // ------------------------
   // miscellaneous functions
   // ------------------------

   // size
   auto size() const { return vec.size(); }

   // operator[]
   // we'll use at(), under-the-hood, so that out-of-range ==> exception
   const Integer32 &operator[](const std::size_t i) const
      { return vec.at(i); }
   Integer32 &operator[](const std::size_t i)
      { return vec.at(i); }

   // push
   Integer32 &push(const Integer32 n)
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


// ------------------------
// operator>>
// ------------------------

inline std::istream &operator>>(std::istream &is, IntegerTuple &obj)
{
   obj.clear();
   try {
      Integer32 n;
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


// ------------------------
// operator<<
// ------------------------

inline std::ostream &operator<<(std::ostream &os, const IntegerTuple &obj)
{
   std::size_t n = 0;
   while (n < obj.size())
      os << (n ? "," : "") << obj[n];
   return os;
}
