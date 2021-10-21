
#include "catch.hpp"
#include "GNDStk.hpp"
#include "prototype.hpp"

using namespace njoy::GNDStk::core;
using namespace GNDStk::proto;


// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

inline const std::string &InputXML();

SCENARIO("Component conversion-to-Node") {
   GIVEN("A GNDS Node") {
      Node node;
      node << InputXML();
      WHEN("A ReactionSuite object is constructed from the Node") {
         const ReactionSuite suite(node);
         THEN("Converting it back into a Node gives the expected result") {
            std::ostringstream oss;
            oss << XML(Node(suite));
            CHECK(oss.str() == InputXML());
         } // THEN
      } // WHEN
   } // GIVEN
} // SCENARIO


// -----------------------------------------------------------------------------
// InputXML
// This is based on the content in n-001_H_002.xml, but pared down quite a bit
// in order to reflect what we have in our prototype test classes. This file's
// test ensures that, after the following content is read into our Component-
// derived classes, Component's toNode() function produces the same result.
// -----------------------------------------------------------------------------

inline const std::string &InputXML()
{
   static const std::string ret =
R"***(<?xml version="1.0"?>
<reactionSuite evaluation="ENDF/B-8.0" format="1.9" projectile="n" projectileFrame="lab" target="H2">
  <reactions>
    <reaction ENDF_MT="16" label="2n + H1">
      <crossSection>
        <XYs1d label="eval">
          <axes>
            <axis index="0" label="crossSection" unit="b" />
            <axis index="1" label="energy_in" unit="eV" />
          </axes>
          <values>2 3 5 7 11 13 17 19 23 29 31 37 41</values>
        </XYs1d>
      </crossSection>
    </reaction>
    <reaction ENDF_MT="102" label="H3 + photon">
      <crossSection>
        <regions1d label="eval">
          <XYs1d index="0" interpolation="log-log">
            <values>43 47 53 59 61 67 71 73 79 83 89 97 101 103</values>
          </XYs1d>
          <XYs1d index="1">
            <values>107 109 113 127 131 137 139 149 151 157 163 167 173 179 181</values>
          </XYs1d>
          <axes>
            <axis index="0" label="crossSection" unit="b" />
            <axis index="1" label="energy_in" unit="eV" />
          </axes>
        </regions1d>
      </crossSection>
    </reaction>
    <reaction ENDF_MT="2" label="n + H2">
      <crossSection>
        <XYs1d label="eval">
          <axes>
            <axis index="0" label="crossSection" unit="b" />
            <axis index="1" label="energy_in" unit="eV" />
          </axes>
          <values>191 193 197 199 211 223 227 229 233 239 241 251 257 263 269 271</values>
        </XYs1d>
      </crossSection>
    </reaction>
  </reactions>
</reactionSuite>
)***";

   return ret;
}
