
#include "catch.hpp"
#include "GNDStk.hpp"

// fixme We're currently testing write to ostream (specifically ostringsream),
// and operator<< (also to ostringstream). For testing to files (with a given
// file name, or an ofstream in place of an ostringstream), I need to figure
// out how that's supposed to be done within this testing system.



// -----------------------------------------------------------------------------
// Strings: proper empty format::tree/xml/json
// -----------------------------------------------------------------------------

// tree
static const std::string string_empty_tree =
R"***()***";

// xml
static const std::string string_empty_xml =
R"***(<?xml version="1.0"?>
)***";

// json
static const std::string string_empty_json =
R"***(null)***";



// -----------------------------------------------------------------------------
// Strings: gold-standard format::tree/xml/json write()s for a particular
// file we'll read in.
// -----------------------------------------------------------------------------

// fixme I need to review each of these carefully, to be sure they're actually
// correct. :-) At the moment, I got these strings just from doing the write()
// calls and assuming that their output was correct. So, technically, all this
// test tests is that nothing has changed between then and now.

// ------------------------
// tree
// ------------------------

static const std::string string_real_tree =
R"***(xml:
   version: 1.0
   encoding: UTF-8
   covarianceSuite:
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
                     body: 0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012
)***";



// ------------------------
// xml
// ------------------------

static const std::string string_real_xml =
R"***(<?xml version="1.0" encoding="UTF-8"?>
<covarianceSuite projectile="n" target="Tm170" evaluation="ENDF/B-8.0" format="1.9">
   <styles>
      <evaluated label="eval" date="2011-10-01" library="ENDF/B" version="8.0.1">
         <temperature value="0.0" unit="K" />
         <projectileEnergyDomain min="1e-05" max="30000000.0" unit="eV" />
      </evaluated>
   </styles>
   <externalFiles>
      <externalFile label="reactions" path="n-069_Tm_170.xml" />
   </externalFiles>
   <parameterCovariances>
      <parameterCovariance label="resolved resonances">
         <rowData href="$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']" />
         <parameterCovarianceMatrix label="eval" type="absolute">
            <parameters>
               <parameterLink label="resonanceParameters" href="$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']/resonanceParameters/table" nParameters="78" />
            </parameters>
            <array shape="78,78" compression="diagonal">
               <values>0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012</values>
            </array>
         </parameterCovarianceMatrix>
      </parameterCovariance>
   </parameterCovariances>
</covarianceSuite>
)***";



// ------------------------
// json
// ------------------------

// fixme
// For now, ignore the weird-looking "000000000000" nonsense.
// Json I/O is a work-in-progress.

static const std::string string_real_json =
R"***({
   "000000000000covarianceSuite": {
      "000000000001attributes": {
         "000000000002projectile": "n",
         "000000000003target": "Tm170",
         "000000000004evaluation": "ENDF/B-8.0",
         "000000000005format": "1.9"
      },
      "000000000006styles": {
         "000000000007evaluated": {
            "000000000008attributes": {
               "000000000009label": "eval",
               "000000000010date": "2011-10-01",
               "000000000011library": "ENDF/B",
               "000000000012version": "8.0.1"
            },
            "000000000013temperature": {
               "000000000014attributes": {
                  "000000000015value": "0.0",
                  "000000000016unit": "K"
               }
            },
            "000000000017projectileEnergyDomain": {
               "000000000018attributes": {
                  "000000000019min": "1e-05",
                  "000000000020max": "30000000.0",
                  "000000000021unit": "eV"
               }
            }
         }
      },
      "000000000022externalFiles": {
         "000000000023externalFile": {
            "000000000024attributes": {
               "000000000025label": "reactions",
               "000000000026path": "n-069_Tm_170.xml"
            }
         }
      },
      "000000000027parameterCovariances": {
         "000000000028parameterCovariance": {
            "000000000029attributes": {
               "000000000030label": "resolved resonances"
            },
            "000000000031rowData": {
               "000000000032attributes": {
                  "000000000033href": "$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']"
               }
            },
            "000000000034parameterCovarianceMatrix": {
               "000000000035attributes": {
                  "000000000036label": "eval",
                  "000000000037type": "absolute"
               },
               "000000000038parameters": {
                  "000000000039parameterLink": {
                     "000000000040attributes": {
                        "000000000041label": "resonanceParameters",
                        "000000000042href": "$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']/resonanceParameters/table",
                        "000000000043nParameters": "78"
                     }
                  }
               },
               "000000000044array": {
                  "000000000045attributes": {
                     "000000000046shape": "78,78",
                     "000000000047compression": "diagonal"
                  },
                  "000000000048values": {
                     "000000000049attributes": {
                        "000000000050body": "0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012"
                     }
                  }
               }
            }
         }
      }
   }
})***";



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

// fixme As elsewhere, we don't yet have anything of substance for HDF5.

SCENARIO("Testing GNDStk tree write() and operator<<") {
   GNDStk::Tree<> tree;

   // ------------------------
   // Empty tree
   // ------------------------

   GIVEN("An empty GNDStk::tree object") {
      // For now I'll just write to an output stream, as I'm not sure how our
      // testing system is supposed to work when our intention is to actually
      // write *files*.

      // format::tree
      WHEN("We write() or << the empty tree in format::tree format") {
         {
            // write()
            std::ostringstream oss;
            tree.write(oss, GNDStk::format::tree);
            REQUIRE(oss.str() == string_empty_tree);
         } {
            // write(), using format::null (which defaults to tree)
            std::ostringstream oss;
            tree.write(oss, GNDStk::format::null);
            REQUIRE(oss.str() == string_empty_tree);
         } {
            // <<
            std::ostringstream oss;
            oss << tree;
            REQUIRE(oss.str() == string_empty_tree);
         }
      }

      // format::xml
      WHEN("We write() the empty tree in format::xml format") {
         std::ostringstream oss;
         tree.write(oss, GNDStk::format::xml);
         REQUIRE(oss.str() == string_empty_xml);
      }

      // format::json
      WHEN("We write() the empty tree in format::json format") {
         std::ostringstream oss;
         tree.write(oss, GNDStk::format::json);
         REQUIRE(oss.str() == string_empty_json);
      }
   }

   // ------------------------
   // Real tree, from one of
   // our sample GNDS files
   // ------------------------

   GIVEN("A real GNDStk::tree, read from a file") {
      tree.read("n-069_Tm_170-covar.xml");
      REQUIRE(!tree.empty());

      // format::tree
      WHEN("We write() or << the tree in format::tree format") {
         {
            // write()
            std::ostringstream oss;
            tree.write(oss, GNDStk::format::tree);
            REQUIRE(oss.str() == string_real_tree);
         } {
            // write(), using format::null (which defaults to tree)
            std::ostringstream oss;
            tree.write(oss, GNDStk::format::null);
            REQUIRE(oss.str() == string_real_tree);
         } {
            // <<
            std::ostringstream oss;
            oss << tree;
            REQUIRE(oss.str() == string_real_tree);
         }
      }

      // format::xml
      WHEN("We write() the tree in format::xml format") {
         std::ostringstream oss;
         tree.write(oss, GNDStk::format::xml);
         REQUIRE(oss.str() == string_real_xml);
      }

      // format::json
      WHEN("We write() the tree in format::json format") {
         std::ostringstream oss;
         tree.write(oss, GNDStk::format::json);
         REQUIRE(oss.str() == string_real_json);
      }
   }
}
