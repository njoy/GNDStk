
private:

   static inline helpMap help = {};

public:

   // Custom 2-argument print() function.
   // In order to be called by Component::print(), this function must be public,
   // and must have the exact signature shown here, including both the constness
   // of the second parameter, and of the function itself.
   std::ostream &print(std::ostream &os, const int level) const
   {
      // When Component::print() calls a custom print() that takes indentation
      // level (as opposed to a custom print() that takes only a std::ostream),
      // it assumes that the custom print() takes care of its own indentation.
      // So, prefer this print() over a std::ostream-only print() - for which
      // Component::print() indents as it believes is appropriate - ONLY if you
      // wish to do something nonstandard with indentation.

      // Here, we'll indent as GNDStk does: using GNDStk::indent*level spaces.
      // GNDStk::indentTo() creates an appropriate std::string for that purpose.
      os << indentTo(level) << "*** Custom Element print(), line 1\n";
      os << indentTo(level) << "*** Custom Element print(), line 2\n";
      os << indentTo(level) << "*** Custom Element print(), line 3";

      return os;
   }
