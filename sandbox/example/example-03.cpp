
#include "gnds.hpp"

// helper: compare
void compare(const gnds::knoop &k, const gnds::tree &t)
{
   std::ostringstream strt;
   std::ostringstream strk;
   t.write(strt);
   k.write(strk);
   assert(strt.str() == strk.str());
}



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main(const int argc, const char * const * const argv)
{

   // ------------------------
   // One-file example
   // ------------------------

   assert(argc == 2);

   gnds::xml x(argv[1]);
   gnds::tree g(x);

   std::cout << std::endl;

   printvar(g.meta("version"));
   printvar(g.meta("encoding"));
   printvar(g.child("reactionSuite").meta("projectile"));
   printvar(g.child("reactionSuite").meta("target"));

   std::cout << std::endl;



   // ------------------------
   // Access/print elements,
   // as strings
   // ------------------------

   printvar(
      g.child("reactionSuite")
       .child("styles")
       .child("evaluated")
       .child("temperature")
       .meta ("value")
   );

   printvar(
      g.child("reactionSuite")
       .child("styles")
       .child("evaluated")
       .child("temperature")
       .meta ("unit")
   );

   printvar(
      g.child("reactionSuite")
       .child("PoPs")
       .child("chemicalElements")
       .child("chemicalElement")
       .child("isotopes")
       .child("isotope")
       .child("nuclides")
       .child("nuclide")
       .child("mass")
       .child("double")
       .meta ("value")
   );

   std::cout << std::endl;



   // ------------------------
   // Access/print elements,
   // strongly-typed
   // ------------------------

   using namespace gnds::child;
   using namespace gnds::meta;

   printvar(
      g.child(reactionSuite)
       .child(styles)
       .child(evaluated)
       .child(temperature)
       .meta ("value")
   );

   printvar(
      g.child(reactionSuite)
       .child(styles)
       .child(evaluated)
       .child(temperature)
       .meta ("unit")
   );

   printvar(g.meta(version));
   printvar(g.meta(encoding));

   // For meta_t<variant>, we must write .meta<something>
   printvar(
      g.child(reactionSuite)
       .child(PoPs)
       .child(chemicalElements)
       .child(chemicalElement)
       .child(isotopes)
       .child(isotope)
       .child(nuclides)
       .child(nuclide)
       .child(mass)
       .child(Double)
       .meta<double>(value)
   );

   // This:
   //    <RutherfordScattering/>
   // shows up in a-002_He_004.xml (the example I've been working with).
   // After reading into our tree structure, it presents as a child
   // node with no further children. In GNDS, its existence apparently
   // indicates a trait of the data. We should figure out a way to represent
   // the meaning in an elegant way; the following simple access syntax
   // does *not* accomplish this goal.
   assert(
      g.child(reactionSuite)
       .child(reactions)
       .child(reaction)
       .child(doubleDifferentialCrossSection)
       .child(CoulombPlusNuclearElastic)
       .child(RutherfordScattering)
       .leaf()
      ==
      true
   );

   // For meta pcdata. I should come up with a shorthand; we arguably know,
   // at the "values" level, that an array is approaching.
   for (
      auto elem :
      g.child(reactionSuite)
       .child(reactions)
       .child(reaction)
       .child(doubleDifferentialCrossSection)
       .child(CoulombPlusNuclearElastic)
       .child(nuclearPlusInterference)
       .child(crossSection)
       .child(XYs1d)
       .child(values)
       .meta (pcdata)
   )
      printvar(elem);



   // ------------------------
   // operator() shorthand
   // ------------------------

   printvar(
      g(reactionSuite)
       (styles)
       (evaluated)
       (temperature)
       .meta ("value") // .meta() or .child() still needed for quoted "..."
   );

   printvar(
      g(reactionSuite)
       (styles)
       (evaluated)
       (temperature)
       .meta ("unit") // ditto
   );

   printvar(
      g(reactionSuite)
       (PoPs)
       (chemicalElements)
       (chemicalElement)
       (isotopes)
       (isotope)
       (nuclides)
       (nuclide)
       (mass)
       (Double)
       .meta<double>(value) // here, <double> because of the variant
   );

   assert(
      g(reactionSuite)
       (reactions)
       (reaction)
       (doubleDifferentialCrossSection)
       (CoulombPlusNuclearElastic)
       (RutherfordScattering)
       .leaf()
      ==
      true
   );

   for (
      auto elem :
      g(reactionSuite)
       (reactions)
       (reaction)
       (doubleDifferentialCrossSection)
       (CoulombPlusNuclearElastic)
       (nuclearPlusInterference)
       (crossSection)
       (XYs1d)
       (values)
       (pcdata)
   )
      printvar(elem);



   // ------------------------
   // Shorthand getting
   // shorter :-p
   // ------------------------

   (void)(*g.root);
   (void)(*g.root)(reactionSuite);
   (void)(*g.root)(reactionSuite,styles);
   (void)(*g.root)(reactionSuite,styles,evaluated);
   (void)(*g.root)(reactionSuite,styles,evaluated,temperature);
   (void)(*g.root)(reactionSuite,styles,evaluated,temperature).meta("unit");

   printvar((*g.root)(reactionSuite,styles,evaluated,temperature).meta("unit"));
   printvar(g(reactionSuite,styles,evaluated,temperature).meta("unit"));
   printvar(g(reactionSuite,styles,evaluated,temperature,unit));

   printvar(
      g(reactionSuite, styles, evaluated, temperature)
       .meta("unit")
   );

   printvar(
      g(reactionSuite, PoPs, chemicalElements, chemicalElement,
        isotopes, isotope, nuclides, nuclide, mass, Double)
       .meta<double>(value) // <double> because of the variant
   );

   // comment as before; come up with a shorthand
   assert(
      g(reactionSuite, reactions, reaction, doubleDifferentialCrossSection,
        CoulombPlusNuclearElastic, RutherfordScattering)
       .leaf()
      ==
      true
   );

   // comment as before; have a way to avoid ,pcdata) at the end
   for (
      auto elem :
      g(reactionSuite, reactions, reaction, doubleDifferentialCrossSection,
        CoulombPlusNuclearElastic, nuclearPlusInterference, crossSection,
        XYs1d, values, pcdata)
   )
      printvar(elem);



// old stuff...
// martin, start splitting out files and creating real tests...

   /*
   printvar(g["xml"]["version"]);
   g(reactionSuite,projectile);
   g(reactionSuite,target);
   g(reactionSuite,styles,evaluated,label);
   */

   /*
   // xml
   gnds::xml x(argv[1]);
   {
      std::ostringstream strk;
      std::ostringstream strg;
      gnds::knoop(x).write(strk); // xml  ==> knoop ==> write
      gnds::tree (x).write(strg); // xml  ==> tree  ==> write
      assert(strk.str() == strg.str()); // results should be the same
   }
   */

   /*
   // json
   gnds::json j(argv[1]);
   {
      std::ostringstream strk;
      std::ostringstream strg;
      gnds::knoop(j).write(strk); // json ==> knoop ==> write
      gnds::tree (j).write(strg); // json ==> tree  ==> write
      assert(strk.str() == strg.str()); // results should be the same
   }
   */

   /*
   // ------------------------
   // Stress test
   // ------------------------

   // for timing...
   const int ntiming = 10;

   // command-line arguments...
   for (int i = 1;  i < argc;  ++i) {
      // file
      const std::string filename = argv[i];

      // skip if above some arbitrary size
      if (gnds::filesize(filename) > 100000000) {
         std::cout
            << "Skipping file \"" << filename << "\" (too long)"
            <<  std::endl;
         continue;
      }

      // xml?
      if (gnds::endsin(filename,".xml")) {
         std::cout
            << i << ". Loading XML file \"" << filename
            << "\"\n   converting multiple times" << std::flush;
         gnds::xml x(filename);
         // convert to our knoop and tree types...
         for (int count = ntiming;  count-- ; ) {
            std::cout << '.' << std::flush;
            gnds::knoop k(x);
            gnds::tree  g(x);
            compare(k,g);
         }
         std::cout << std::endl;

      // json?
      } else if (gnds::endsin(filename,".json")) {
         std::cout
            << i << ". Loading Json file \"" << filename
            << "\"\n   converting multiple times" << std::flush;
         gnds::json j(filename);
         // convert to our knoop and tree types...
         for (int count = ntiming;  count-- ; ) {
            std::cout << '.' << std::flush;
            gnds::knoop k(j);
            gnds::tree  g(j);
            compare(k,g);
         }
         std::cout << std::endl;

      // unknown type
      } else {
         std::cout
            << "Skipping file \"" << filename << "\" (unknown type)"
            <<  std::endl;
      }
   }
   */
}
