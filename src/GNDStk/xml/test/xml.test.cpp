#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO( "Test reading of an XML file" ){
  GIVEN( "an xml file" ){

    const std::string file = "resources/n-009_F_019.xml";
    pugi::xml_document document;

    WHEN( "the document has been loaded" ){
      pugi::xml_parse_result load = document.load_file(file.c_str());

      THEN( "its metadata can be checked" ){
        pugi::xml_node rs = document.child("reactionSuite");

        CHECK( rs.attribute("projectile"     ).value() ==
               std::string("n"         ));
        CHECK( rs.attribute("target"         ).value() ==
               std::string("F19"       ));
        CHECK( rs.attribute("evaluation"     ).value() ==
               std::string("ENDF/B-7.1"));
        CHECK( rs.attribute("version"        ).value() ==
               std::string("GND 1.8"   ));
        CHECK( rs.attribute("projectileFrame").value() ==
               std::string("lab"       ));

        const std::vector<std::string> names {
          "styles",
          "documentations",
          "PoPs",
          "resonances",
          "reactions",
          "sums",
          "productions"
        };

        int count = 0;
        for (pugi::xml_node &rschild :
             document.child("reactionSuite").children()) {
          CHECK( rschild.name() == names[count++] );
        } // for
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

