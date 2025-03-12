
private:

   static inline helpMap help = {};

public:

   // Custom 1-argument print() function.
   // In order to be called by Component::print(), this function must be public,
   // and must have the exact signature shown here, including the constness of
   // the function itself.
   std::ostream &print(std::ostream &os) const
   {
      os << "*** Custom Library print(), line 1\n";
      os << "*** Custom Library print(), line 2\n";
      os << "*** Custom Library print(), line 3";

      return os;
   }
