
#include "GNDS/v2.0.hpp"
using namespace GNDS;
using namespace v2_0;

int main(const int argc, const char *const *const argv)
{
   // For prettyprinting:
   colors = true; // Use color markup.
   shades = true; // Colorize array values based on relative intensity.
   indent = 3;    // Indent by this number of spaces.
   printMode = PrintMode::python;
   elements = 10;

   for (int i = 1; i < argc; ++i) {
      // Assume here that it's a <reactionSuite>. Note that where an XML node
      // is named foo (lower-case 'f'), its *class* in the generated code will
      // be named Foo (upper-case 'F'). Fields - data members in the class -
      // will have lower-case names again. So, for this ReactionSuite r (from
      // the XML <reactionSuite> node, we'll have, for example, r.reactions,
      // of class Reactions, for the XML node <reactions>. Technically we use
      // a Field<Reactions>, where Field is a wrapper class that the generated
      // code uses for a number of purposes. (That's why we write r.reactions(),
      // with those () parenthesis, below, instead of r.reactions. This is
      // something to talk about.)
      top::ReactionSuite r;

      // Read from the given file. Note that we SHOULD NOT try to *construct*
      // like this above:
      //    top::ReactionSuite r(argv[i]);
      // because this doesn't actually mean, "read from that file," but means
      // something else (both for ReactionSuite, and in general for generated
      // classes). In particular, it tries to initialize the class fields by
      // using the parameters. ReactionSuite's first field (aside from the
      // boilerplate "comment" field we always add, and which doesn't play
      // a role in the constructors) happens to be the metadatum "projectile".
      // So, writing top::ReactionSuite r(argv[i]) would inadvertently create
      // an otherwise blank ReactionSuite but with metadatum projectile equal
      // to whatever name is in argv[i]. We don't want that here, because the
      // argv entries are intended to be file names in this example code!
      r.read(argv[i]);

      // Prettyprint the entire ReactionSuite.
      r.print();

      // Prettyprint just the <reactions> portion.
      r.reactions().print(); // <== ask me about the () business
   }
}
