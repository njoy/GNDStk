
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;



// -----------------------------------------------------------------------------
// Strings: proper empty FileType::debug/xml/json
// -----------------------------------------------------------------------------

// tree
static const std::string string_empty_tree =
R"***(/:)***";

// xml
static const std::string string_empty_xml =
R"***(<?xml version="1.0"?>)***";

// json
static const std::string string_empty_json =
R"***({})***";



// -----------------------------------------------------------------------------
// Strings: gold-standard FileType::debug/xml/json write()s for a particular
// file we'll read in.
// -----------------------------------------------------------------------------

// ------------------------
// tree
// ------------------------

static const std::string string_real_tree =
R"***(/:
   #xml:
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
                     #data:
                        #text: 0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012)***";



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
</covarianceSuite>)***";



// ------------------------
// json
// ------------------------

#ifndef GNDSTK_DISABLE_JSON
static const std::string string_real_json =
R"***({
   "covarianceSuite": {
      "#metadata": {
         "evaluation": "ENDF/B-8.0",
         "format": "1.9",
         "projectile": "n",
         "target": "Tm170"
      },
      "externalFiles": {
         "externalFile": {
            "#metadata": {
               "label": "reactions",
               "path": "n-069_Tm_170.xml"
            }
         }
      },
      "parameterCovariances": {
         "parameterCovariance": {
            "#metadata": {
               "label": "resolved resonances"
            },
            "parameterCovarianceMatrix": {
               "#metadata": {
                  "label": "eval",
                  "type": "absolute"
               },
               "array": {
                  "#metadata": {
                     "compression": "diagonal",
                     "shape": "78,78"
                  },
                  "values": {
                     "#data": {
                        "#metadata": {
                           "#text": "0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012"
                        }
                     }
                  }
               },
               "parameters": {
                  "parameterLink": {
                     "#metadata": {
                        "href": "$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']/resonanceParameters/table",
                        "label": "resonanceParameters",
                        "nParameters": "78"
                     }
                  }
               }
            },
            "rowData": {
               "#metadata": {
                  "href": "$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']"
               }
            }
         }
      },
      "styles": {
         "evaluated": {
            "#metadata": {
               "date": "2011-10-01",
               "label": "eval",
               "library": "ENDF/B",
               "version": "8.0.1"
            },
            "projectileEnergyDomain": {
               "#metadata": {
                  "max": "30000000.0",
                  "min": "1e-05",
                  "unit": "eV"
               }
            },
            "temperature": {
               "#metadata": {
                  "unit": "K",
                  "value": "0.0"
               }
            }
         }
      }
   }
})***";
#endif



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk tree write() and operator<<") {
   Tree tree;

   // ------------------------
   // Empty tree
   // ------------------------

   GIVEN("An empty tree object") {
      // For now I'll just write to an output stream, as I'm not sure how our
      // testing system is supposed to work when our intention is to actually
      // write *files*.

      // FileType::debug
      WHEN("We write() the empty tree using FileType::debug") {
         // write()
         THEN("We get an empty string (case: FileType::debug)") {
            std::ostringstream oss;
            tree.write(oss, FileType::debug);
            CHECK(oss.str() == string_empty_tree);
         }
         THEN("We get an empty string (case: \"debug\")") {
            std::ostringstream oss;
            tree.write(oss, "debug");
            CHECK(oss.str() == string_empty_tree);
         }
      }

      WHEN("We write() the empty tree using FileType::guess") {
         // write(), using FileType::guess
         THEN("We get an empty string (case: FileType::guess)") {
            std::ostringstream oss;
            tree.write(oss, FileType::guess);
            CHECK(oss.str() == string_empty_tree);
         }
         THEN("We get an empty string (case: \"guess\")") {
            std::ostringstream oss;
            tree.write(oss, "guess");
            CHECK(oss.str() == string_empty_tree);
         }
         THEN("We get an empty string (case: \"\")") {
            std::ostringstream oss;
            tree.write(oss, "");
            CHECK(oss.str() == string_empty_tree);
         }
      }

      WHEN("We stream-output the empty tree") {
         // <<
         THEN("We get an empty string") {
            std::ostringstream oss;
            oss << tree;
            CHECK(oss.str() == string_empty_tree);
         }
      }

      // FileType::xml
      WHEN("We write() the empty tree using FileType::xml") {
         THEN("We get XML boilerplate only (case: FileType::xml)") {
            std::ostringstream oss;
            tree.write(oss, FileType::xml);
            CHECK(oss.str() == string_empty_xml);
         }
         THEN("We get XML boilerplate only (case: \"xml\"))") {
            std::ostringstream oss;
            tree.write(oss, "xml");
            CHECK(oss.str() == string_empty_xml);
         }
      }

      // FileType::json
#ifndef GNDSTK_DISABLE_JSON
      WHEN("We write() the empty tree using FileType::json") {
         THEN("We get JSON \"(null)\" only (case: FileType::json)") {
            std::ostringstream oss;
            tree.write(oss, FileType::json);
            CHECK(oss.str() == string_empty_json);
         }
         THEN("We get JSON \"(null)\" only (case: \"json\")") {
            std::ostringstream oss;
            tree.write(oss, "json");
            CHECK(oss.str() == string_empty_json);
         }
      }
#endif
   }

   // ------------------------
   // Real tree, from one of
   // our sample GNDS files
   // ------------------------

   GIVEN("A real tree, read from a file") {
      tree.read("n-069_Tm_170-covar.xml");
      CHECK(!tree.empty());

      // FileType::debug
      WHEN("We write() the tree using FileType::debug") {
         // write()
         THEN("We get the correct debug-format content") {
            std::ostringstream oss;
            tree.write(oss);
            CHECK(oss.str() == string_real_tree);
         }
         THEN("We get the correct debug-format content (case: FileType::debug)") {
            std::ostringstream oss;
            tree.write(oss, FileType::debug);
            CHECK(oss.str() == string_real_tree);
         }
         THEN("We get the correct debug-format content (case: \"debug\")") {
            std::ostringstream oss;
            tree.write(oss, "debug");
            CHECK(oss.str() == string_real_tree);
         }
      }

      WHEN("We write() the tree using FileType::guess") {
         // write(), using FileType::guess
         THEN("We get the correct debug-format content") {
            std::ostringstream oss;
            tree.write(oss);
            CHECK(oss.str() == string_real_tree);
         }
         THEN("We get the correct debug-format content (case: FileType::guess)") {
            std::ostringstream oss;
            tree.write(oss, FileType::guess);
            CHECK(oss.str() == string_real_tree);
         }
         THEN("We get the correct debug-format content (case: \"guess\")") {
            std::ostringstream oss;
            tree.write(oss, "guess");
            CHECK(oss.str() == string_real_tree);
         }
         THEN("We get the correct debug-format content (case: \"\")") {
            std::ostringstream oss;
            tree.write(oss, "");
            CHECK(oss.str() == string_real_tree);
         }
      }

      WHEN("We stream-output the tree") {
         // <<
         std::ostringstream oss;
         THEN("We get the correct debug-format content") {
            oss << tree;
            CHECK(oss.str() == string_real_tree);
         }
      }

      // FileType::xml
      WHEN("We write() the tree using FileType::xml") {
         THEN("We get the correct XML content (case: FileType::xml)") {
            std::ostringstream oss;
            tree.write(oss, FileType::xml);
            CHECK(oss.str() == string_real_xml);
         }
         THEN("We get the correct XML content (case: \"xml\")") {
            std::ostringstream oss;
            tree.write(oss, "xml");
            CHECK(oss.str() == string_real_xml);
         }
      }

      // FileType::json
#ifndef GNDSTK_DISABLE_JSON
      WHEN("We write() the tree using FileType::json") {
         THEN("We get the correct JSON content (case: FileType::json)") {
            std::ostringstream oss;
            JSON::reduced = false;
            JSON::typed   = false;
            tree.sort().write(oss, FileType::json);
            CHECK(oss.str() == string_real_json);
         }
         THEN("We get the correct JSON content (case: \"json\")") {
            std::ostringstream oss;
            JSON::reduced = false;
            JSON::typed   = false;
            tree.sort().write(oss, "json");
            CHECK(oss.str() == string_real_json);
         }
      }
#endif
   }
}
