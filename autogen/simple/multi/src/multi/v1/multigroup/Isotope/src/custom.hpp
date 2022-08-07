
private:

   static inline helpMap help = {};

public:

   // If a custom 1-argument print() function *and* a custom 2-argument print()
   // function are both given, and both with the correct signature, then
   // Component::print() will call the 2-argument version, and ignore the other.

   std::ostream &print(std::ostream &os) const
   {
      assert(false); // shouldn't happen, because the below print() is used!
      return os;
   }

   std::ostream &print(std::ostream &os, const int level) const
   {
      os << indentTo(level) << "*** Custom Isotope print(), line 1\n";
      os << indentTo(level) << "*** Custom Isotope print(), line 2\n";
      os << indentTo(level) << "*** Custom Isotope print(), line 3";

      return os;
   }
