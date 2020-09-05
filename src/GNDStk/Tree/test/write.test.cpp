
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;



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

static const std::string string_real_json =
R"***({
   "covarianceSuite": {
      "attributes": {
         "evaluation": "ENDF/B-8.0",
         "format": "1.9",
         "projectile": "n",
         "target": "Tm170"
      },
      "externalFiles": {
         "externalFile": {
            "attributes": {
               "label": "reactions",
               "path": "n-069_Tm_170.xml"
            }
         }
      },
      "parameterCovariances": {
         "parameterCovariance": {
            "attributes": {
               "label": "resolved resonances"
            },
            "parameterCovarianceMatrix": {
               "array": {
                  "attributes": {
                     "compression": "diagonal",
                     "shape": "78,78"
                  },
                  "values": {
                     "pcdata": {
                        "attributes": {
                           "text": "0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012"
                        }
                     }
                  }
               },
               "attributes": {
                  "label": "eval",
                  "type": "absolute"
               },
               "parameters": {
                  "parameterLink": {
                     "attributes": {
                        "href": "$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']/resonanceParameters/table",
                        "label": "resonanceParameters",
                        "nParameters": "78"
                     }
                  }
               }
            },
            "rowData": {
               "attributes": {
                  "href": "$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']"
               }
            }
         }
      },
      "styles": {
         "evaluated": {
            "attributes": {
               "date": "2011-10-01",
               "label": "eval",
               "library": "ENDF/B",
               "version": "8.0.1"
            },
            "projectileEnergyDomain": {
               "attributes": {
                  "max": "30000000.0",
                  "min": "1e-05",
                  "unit": "eV"
               }
            },
            "temperature": {
               "attributes": {
                  "unit": "K",
                  "value": "0.0"
               }
            }
         }
      }
   }
})***";



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk tree write() and operator<<") {
   Tree<> tree;

   // ------------------------
   // Empty tree
   // ------------------------

   GIVEN("An empty tree object") {
      // For now I'll just write to an output stream, as I'm not sure how our
      // testing system is supposed to work when our intention is to actually
      // write *files*.

      // format::tree
      WHEN("We write() the empty tree using format::tree") {
         // write()
         {
            std::ostringstream oss;
            tree.write(oss, format::tree);
            CHECK(oss.str() == string_empty_tree);
         } {
            std::ostringstream oss;
            tree.write(oss, "tree");
            CHECK(oss.str() == string_empty_tree);
         }
      }

      WHEN("We write() the empty tree using format::null") {
         // write(), using format::null (which defaults to tree)
         {
            std::ostringstream oss;
            tree.write(oss, format::null);
            CHECK(oss.str() == string_empty_tree);
         } {
            std::ostringstream oss;
            tree.write(oss, "null");
            CHECK(oss.str() == string_empty_tree);
         } {
            std::ostringstream oss;
            tree.write(oss, "");
            CHECK(oss.str() == string_empty_tree);
         }
      }

      WHEN("We stream-output the empty tree") {
         // <<
         std::ostringstream oss;
         oss << tree;
         CHECK(oss.str() == string_empty_tree);
      }

      // format::xml
      WHEN("We write() the empty tree using format::xml") {
         {
            std::ostringstream oss;
            tree.write(oss, format::xml);
            CHECK(oss.str() == string_empty_xml);
         } {
            std::ostringstream oss;
            tree.write(oss, "xml");
            CHECK(oss.str() == string_empty_xml);
         }
      }

      // format::json
      WHEN("We write() the empty tree using format::json") {
         {
            std::ostringstream oss;
            tree.write(oss, format::json);
            CHECK(oss.str() == string_empty_json);
         } {
            std::ostringstream oss;
            tree.write(oss, "json");
            CHECK(oss.str() == string_empty_json);
         }
      }
   }

   // ------------------------
   // Real tree, from one of
   // our sample GNDS files
   // ------------------------

   GIVEN("A real tree, read from a file") {
      tree.read("n-069_Tm_170-covar.xml");
      CHECK(!tree.empty());

      // format::tree
      WHEN("We write() the tree using format::tree") {
         // write()
         {
            std::ostringstream oss;
            tree.write(oss);
            CHECK(oss.str() == string_real_tree);
         } {
            std::ostringstream oss;
            tree.write(oss, format::tree);
            CHECK(oss.str() == string_real_tree);
         } {
            std::ostringstream oss;
            tree.write(oss, "tree");
            CHECK(oss.str() == string_real_tree);
         }
      }

      WHEN("We write() the tree using format::null") {
         // write(), using format::null (which defaults to tree)
         {
            std::ostringstream oss;
            tree.write(oss);
            CHECK(oss.str() == string_real_tree);
         } {
            std::ostringstream oss;
            tree.write(oss, format::null);
            CHECK(oss.str() == string_real_tree);
         } {
            std::ostringstream oss;
            tree.write(oss, "null");
            CHECK(oss.str() == string_real_tree);
         } {
            std::ostringstream oss;
            tree.write(oss, "");
            CHECK(oss.str() == string_real_tree);
         }
      }

      WHEN("We stream-output the tree") {
         // <<
         std::ostringstream oss;
         oss << tree;
         CHECK(oss.str() == string_real_tree);
      }

      // format::xml
      WHEN("We write() the tree using format::xml") {
         {
            std::ostringstream oss;
            tree.write(oss, format::xml);
            CHECK(oss.str() == string_real_xml);
         } {
            std::ostringstream oss;
            tree.write(oss, "xml");
            CHECK(oss.str() == string_real_xml);
         }
      }

      // format::json
      WHEN("We write() the tree using format::json") {
         {
            std::ostringstream oss;
            tree.write(oss, format::json);
            CHECK(oss.str() == string_real_json);
         } {
            std::ostringstream oss;
            tree.write(oss, "json");
            CHECK(oss.str() == string_real_json);
         }
      }
   }
}
