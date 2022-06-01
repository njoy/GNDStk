
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// JSON literal
// -----------------------------------------------------------------------------

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
               "array": {
                  "#metadata": {
                     "compression": "diagonal",
                     "shape": "78,78"
                  },
                  "values": {
                     "#pcdata": {
                        "#metadata": {
                           "#text": "0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012"
                        }
                     }
                  }
               },
               "#metadata": {
                  "label": "eval",
                  "type": "absolute"
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


// -----------------------------------------------------------------------------
// writeAndReadJSON
// Helper function
// -----------------------------------------------------------------------------

void writeAndReadJSON(
   const Tree &oldTree,
   const bool reduced, const bool typed,
   const std::string &correct,
   const std::string &baseName
) {
   // Set flags
   JSON::reduced = reduced;
   JSON::typed = typed;

   // Compute file names
   const std::string newFile = baseName + ".json";
   const std::string vettedFile = "correct-" + newFile;

   // Write the Tree to a JSON file
   oldTree.write(newFile);

   // Read from the JSON file into a brand-new Tree
   Tree newTree(newFile);

   // Test #1. Ensure that the newly-read Tree prints (in our debug format)
   // in exactly the same way as the original Tree did.
   std::ostringstream oss;
   newTree.sort().top().write(oss,"debug");
   CHECK(oss.str() == correct);

   // Test #2. Ensure that file newFile (written above, from the original Tree)
   // is identical to the vetted JSON file vettedFile.
   std::ifstream ifsWant(vettedFile);
   std::stringstream bufWant;
   bufWant << ifsWant.rdbuf();
   std::cout << "bufWant.str().size() == " << bufWant.str().size() << std::endl;

   std::ifstream ifsHave(newFile);
   std::stringstream bufHave;
   bufHave << ifsHave.rdbuf();
   std::cout << "bufHave.str().size() == " << bufHave.str().size() << std::endl;

   CHECK(bufWant.str() == bufHave.str());
}


// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk JSON, Part I") {
   WHEN("We create a Tree from an XML with various constructs in it") {
      // Read Tree
      Tree tree("various.xml");

      // Write to a string, in our simple debug format
      std::ostringstream oss;
      tree.sort().top().write(oss,"debug");
      const std::string correct = oss.str();

      // Write/read to/from JSON, for each combination of the available flags
      // for doing so: JSON::reduced = false/true (x) JSON::typed = false/true
      writeAndReadJSON(tree, false, false, correct, "raw-string");
      writeAndReadJSON(tree, false, true,  correct, "raw-typed");
      writeAndReadJSON(tree, true,  false, correct, "reduced-string");
      writeAndReadJSON(tree, true,  true,  correct, "reduced-typed");
   }
}


// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk JSON, Part II") {
   JSON::reduced = false;
   JSON::typed   = false;

   // read a JSON
   JSON j("n-069_Tm_170-covar.json");

   // construct a Tree from the JSON
   Tree t(j);

   // the Tree should be non-empty
   CHECK(!t.empty());


   // ------------------------
   // clear
   // ------------------------

   WHEN("We clear() a JSON, and convert() it to a Tree") {
      convert(j.clear(),t);
      THEN("The Tree should have only an empty declaration node") {
         CHECK(t.children.size() == 1);
         CHECK(t.has_decl());
         CHECK(t.decl().name == special::json);
         CHECK(t.decl().metadata.size() == 0);
         CHECK(t.decl().children.size() == 0);
      }
   }


   // ------------------------
   // empty
   // ------------------------

   WHEN("We call empty() on a clear()d JSON") {
      j.clear();
      CHECK(j.empty());
   }


   // ------------------------
   // constructors
   // ------------------------

   // default
   WHEN("We call JSON's default constructor") {
      const JSON j;
      CHECK(j.empty());
   }

   // move
   WHEN("We call JSON's move constructor") {
      const JSON j(JSON{"n-069_Tm_170-covar.json"});
      CHECK(!j.empty());
      // and ensure it moved correctly
      std::ostringstream oss1; oss1 << JSON{"n-069_Tm_170-covar.json"};
      std::ostringstream oss2; oss2 << j;
      CHECK(oss1.str() == oss2.str());
   }

   // copy
   WHEN("We call JSON's copy constructor") {
      const JSON a("n-069_Tm_170-covar.json");
      const JSON j(a);
      CHECK(!j.empty());
      // and ensure it copied correctly
      std::ostringstream oss1; oss1 << a;
      std::ostringstream oss2; oss2 << j;
      CHECK(oss1.str() == oss2.str());
   }

   // from XML
   WHEN("We construct a JSON from an XML") {
      const XML x("n-069_Tm_170-covar.xml");
      const JSON j(x);
      THEN("They should produce equivalent Trees") {
         CHECK(!j.empty());
         CHECK(Tree(x) == Tree(j));
      }
   }

   // from Tree
   WHEN("We construct a JSON from a Tree") {
      const Tree t("n-069_Tm_170-covar.xml");
      const JSON j(t);
      THEN("It should produce an equivalent Tree") {
         CHECK(!j.empty());
         CHECK(t == Tree(j));
      }
   }

   // from file
   WHEN("We construct a JSON from a file") {
      const JSON j("n-069_Tm_170-covar.json");
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!j.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.json");
         std::ostringstream oss2; oss2 << Tree(j);
         CHECK(oss1.str() == oss2.str());
      }
   }

   // from istream
   WHEN("We construct a JSON from an istream") {
      std::ifstream ifs("n-069_Tm_170-covar.json");
      const JSON j(ifs);
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!j.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.json");
         std::ostringstream oss2; oss2 << Tree(j);
         CHECK(oss1.str() == oss2.str());
      }
   }


   // ------------------------
   // assignment
   // ------------------------

   // move
   WHEN("We call JSON's move assignment") {
      JSON j;
      j = JSON{"n-069_Tm_170-covar.json"};
      CHECK(!j.empty());
      // and ensure it moved correctly
      std::ostringstream oss1; oss1 << JSON{"n-069_Tm_170-covar.json"};
      std::ostringstream oss2; oss2 << j;
      CHECK(oss1.str() == oss2.str());
   }

   // copy
   WHEN("We call JSON's copy assignment") {
      const JSON a("n-069_Tm_170-covar.json");
      JSON j;
      j = a;
      CHECK(!j.empty());
      // and ensure it copied correctly
      std::ostringstream oss1; oss1 << a;
      std::ostringstream oss2; oss2 << j;
      CHECK(oss1.str() == oss2.str());
   }


   // ------------------------
   // read
   // ------------------------

   // from istream
   WHEN("We read a JSON from an istream") {
      std::ifstream ifs("n-069_Tm_170-covar.json");
      const JSON j(ifs);
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!j.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.json");
         std::ostringstream oss2; oss2 << Tree(j);
         CHECK(oss1.str() == oss2.str());
      }
   }

   // from file
   WHEN("We read a JSON from a file") {
      const JSON j("n-069_Tm_170-covar.json");
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!j.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.json");
         std::ostringstream oss2; oss2 << Tree(j);
         CHECK(oss1.str() == oss2.str());
      }
   }


   // ------------------------
   // write
   // ------------------------

   // to ostream
   WHEN("We write a JSON to an ostream") {
      const JSON j("n-069_Tm_170-covar.json");
      std::ostringstream oss;
      j.write(oss);
      THEN("We can check that the result is what we expect") {
         CHECK(oss.str() == string_real_json);
      }
   }


   // ------------------------
   // stream I/O
   // ------------------------

   // operator>>
   WHEN("We do istream >> JSON") {
      std::ifstream ifs("n-069_Tm_170-covar.json");
      JSON j;
      ifs >> j;
      THEN("It should give what we expect") {
         // Well, we also end up testing << here, which we test
         // more directly in the next block, below
         std::ostringstream oss;
         oss << j;
         CHECK(oss.str() == string_real_json);
      }
   }

   // operator<<
   WHEN("We do ostream << JSON") {
      const JSON j("n-069_Tm_170-covar.json");
      std::ostringstream oss;
      oss << j;
      THEN("It should give what we expect") {
         CHECK(oss.str() == string_real_json);
      }
   }
}
