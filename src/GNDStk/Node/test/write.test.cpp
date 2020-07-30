
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

static const std::string correct_written_node =
R"***(covarianceSuite:
   projectile: n
   target: Tm170
   evaluation: ENDF/B-8.0
   format: 1.9
   styles:
      evaluated:
         label: eval
         date: 2011-10-01
         library: ENDF/B
         version: 8.0.1
         temperature:
            value: 0.0
            unit: K
         projectileEnergyDomain:
            min: 1e-05
            max: 30000000.0
            unit: eV
   externalFiles:
      externalFile:
         label: reactions
         path: n-069_Tm_170.xml
   parameterCovariances:
      parameterCovariance:
         label: resolved resonances
         rowData:
            href: $reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']
         parameterCovarianceMatrix:
            label: eval
            type: absolute
            parameters:
               parameterLink:
                  label: resonanceParameters
                  href: $reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']/resonanceParameters/table
                  nParameters: 78
            array:
               shape: 78,78
               compression: diagonal
               values:
                  pcdata:
                     text: 0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012
)***";

SCENARIO("Testing GNDStk Node write() and operator<<") {
   GIVEN("A top-level node from a tree object") {
      const Tree<> tree("n-069_Tm_170-covar.xml");
      const Node<> &top = tree.top(); // top-level GNDS node

      WHEN("We call node.write(ostream)") {
         std::ostringstream oss;
         top.write(oss);
         CHECK(oss.str() == correct_written_node);
      }

      WHEN("We call ostream << node") {
         std::ostringstream oss;
         oss << top;
         CHECK(oss.str() == correct_written_node);
      }
   }
}
