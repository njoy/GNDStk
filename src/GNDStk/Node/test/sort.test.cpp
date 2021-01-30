
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

static const std::string correct_sorted_written_node =
R"***(covarianceSuite:
   evaluation: ENDF/B-8.0
   format: 1.9
   projectile: n
   target: Tm170
   externalFiles:
      externalFile:
         label: reactions
         path: n-069_Tm_170.xml
   parameterCovariances:
      parameterCovariance:
         label: resolved resonances
         parameterCovarianceMatrix:
            label: eval
            type: absolute
            array:
               compression: diagonal
               shape: 78,78
               values:
                  pcdata:
                     text: 0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012
            parameters:
               parameterLink:
                  href: $reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']/resonanceParameters/table
                  label: resonanceParameters
                  nParameters: 78
         rowData:
            href: $reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']
   styles:
      evaluated:
         date: 2011-10-01
         label: eval
         library: ENDF/B
         version: 8.0.1
         projectileEnergyDomain:
            max: 30000000.0
            min: 1e-05
            unit: eV
         temperature:
            unit: K
            value: 0.0
)***";

SCENARIO("Testing GNDStk Node sort()") {
   GIVEN("A top-level node from a tree object") {
      Tree<> tree("n-069_Tm_170-covar.xml");
      Node<> &top = tree.top(); // top-level GNDS node

      WHEN("We call Node.sort()") {
         std::ostringstream oss;
         top.sort().write(oss);
         THEN("We get properly reordered Node content") {
            CHECK(oss.str() == correct_sorted_written_node);
         }
      }
   }
}
