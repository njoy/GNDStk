
#include "catch.hpp"
#include "GNDStk.hpp"

/*
The file we'll be examining:

<?xml version="1.0" encoding="UTF-8"?>
<covarianceSuite projectile="n" target="Tm170"
 evaluation="ENDF/B-8.0" format="1.9">
  <styles> ... </styles>
  <externalFiles> ... </externalFiles>
  <parameterCovariances> ... </parameterCovariances>
</covarianceSuite>
*/

SCENARIO("Testing GNDStk tree meta()") {
   using namespace GNDStk;
   using namespace GNDStk::meta;

   GIVEN("A tree read from n-069_Tm_170-covar.xml") {
      // c: a const tree
      const Tree<> c("n-069_Tm_170-covar.xml");
      // t: a non-const tree
      Tree<> t = c;


      // ------------------------
      // meta(string)
      // Dumb string lookup
      // ------------------------

      // Some of the following appear in the declaration node (<?xml ... ),
      // while some appear in the top-level GNDS node (<covarianceSuite ... ).
      // Tree's meta() function automatically looks in the declaration node
      // first, then looks in the top-level node only if the first look failed.

      // const
      REQUIRE(c.meta("version") == "1.0");
      REQUIRE(c.meta("encoding") == "UTF-8");
      REQUIRE(c.meta("projectile") == "n");
      REQUIRE(c.meta("target") == "Tm170");
      REQUIRE(c.meta("evaluation") == "ENDF/B-8.0");
      REQUIRE(c.meta("format") == "1.9");

      // non-const
      REQUIRE(t.meta("version") == "1.0");
      REQUIRE(t.meta("encoding") == "UTF-8");
      REQUIRE(t.meta("projectile") == "n");
      REQUIRE(t.meta("target") == "Tm170");
      REQUIRE(t.meta("evaluation") == "ENDF/B-8.0");
      REQUIRE(t.meta("format") == "1.9");

      // Be sure that all of the above return references, given that both const
      // and non-const meta(string) use decltype(auto) and some other constructs
      // in arguably not-too-common ways. The following won't compile unless
      // references are returned.
      (void)&c.meta("version");
      (void)&c.meta("encoding");
      (void)&c.meta("projectile");
      (void)&c.meta("target");
      (void)&c.meta("evaluation");
      (void)&c.meta("format");
      (void)&t.meta("version");
      (void)&t.meta("encoding");
      (void)&t.meta("projectile");
      (void)&t.meta("target");
      (void)&t.meta("evaluation");
      (void)&t.meta("format");

      // Again doing the lookups as earlier, be sure they always give back
      // a true "found" if we send "found" at all...
      bool found;
      REQUIRE((found=false,c.meta("version",   found)=="1.0"        && found));
      REQUIRE((found=false,c.meta("encoding",  found)=="UTF-8"      && found));
      REQUIRE((found=false,c.meta("projectile",found)=="n"          && found));
      REQUIRE((found=false,c.meta("target",    found)=="Tm170"      && found));
      REQUIRE((found=false,c.meta("evaluation",found)=="ENDF/B-8.0" && found));
      REQUIRE((found=false,c.meta("format",    found)=="1.9"        && found));
      REQUIRE((found=false,t.meta("version",   found)=="1.0"        && found));
      REQUIRE((found=false,t.meta("encoding",  found)=="UTF-8"      && found));
      REQUIRE((found=false,t.meta("projectile",found)=="n"          && found));
      REQUIRE((found=false,t.meta("target",    found)=="Tm170"      && found));
      REQUIRE((found=false,t.meta("evaluation",found)=="ENDF/B-8.0" && found));
      REQUIRE((found=false,t.meta("format",    found)=="1.9"        && found));

      // Now, try to look up something that isn't there, and be sure "found"
      // comes back as false. (If we didn't send it at all, then attempting
      // to look up a nonexistent metadata key would trigger an error).
      // Const version, then non-const...
      REQUIRE((found = true, c.meta("foo", found), found == false));
      REQUIRE((found = true, t.meta("bar", found), found == false));


      // ------------------------
      // meta(meta_t)
      // Smart keyword lookup
      // ------------------------

      // *** version ***
      // extract as double or string
      // appears in declaration node
      const meta_t<std::variant<double,std::string>> version("version");

      // *** encoding ***
      // extract as string
      // appears in declaration node
      const meta_t<std::string> encoding("encoding");

      // *** projectile ***
      // extract as char or string
      // appears in top-level GNDS node
      const meta_t<std::variant<char,std::string>> projectile("projectile");

      // *** target ***
      // extract as string (void ==> string w/meta_t)
      // appears in top-level GNDS node
      const meta_t<void> target("target");

      // *** format ***
      // extract as double
      // appears in top-level GNDS node
      const meta_t<double> format("format");

      // fixme Floating-point comparisons aren't necessarily reliable
      REQUIRE( c.meta <double     > ( version    ) ==  1.0    ); // double
      REQUIRE( c.meta <std::string> ( version    ) == "1.0"   ); // string
      REQUIRE( c.meta               ( encoding   ) == "UTF-8" ); // string
      REQUIRE( c.meta <char       > ( projectile ) == 'n'     ); // char
      REQUIRE( c.meta <std::string> ( projectile ) == "n"     ); // string
      REQUIRE( c.meta               ( target     ) == "Tm170" ); // string
      REQUIRE( c.meta               ( format     ) ==  1.9    ); // double

      // Test found
      REQUIRE((found=false,
               c.meta <double     > ( version    , found) ==  1.0    && found));
      REQUIRE((found=false,
               c.meta <std::string> ( version    , found) == "1.0"   && found));
      REQUIRE((found=false,
               c.meta               ( encoding   , found) == "UTF-8" && found));
      REQUIRE((found=false,
               c.meta <char       > ( projectile , found) == 'n'     && found));
      REQUIRE((found=false,
               c.meta <std::string> ( projectile , found) == "n"     && found));
      REQUIRE((found=false,
               c.meta               ( target     , found) == "Tm170" && found));
      REQUIRE((found=false,
               c.meta               ( format     , found) ==  1.9    && found));

      // Test not-found
      meta_t<int> foo("foo");
      meta_t<std::variant<int,double>> bar("bar");
      REQUIRE((found = true, c.meta        (foo,found), found == false));
      REQUIRE((found = true, c.meta<int   >(bar,found), found == false));
      REQUIRE((found = true, c.meta<double>(bar,found), found == false));


      // ------------------------
      // meta(string) again;
      // test assignment into
      // metadata
      // ------------------------

      // something in the declaration node
      t.meta("version") = "1.2345"; // change version string
      REQUIRE(t.meta("version") == "1.2345"); // verify that it changed

      // something in the top-level GNDS node
      t.meta("projectile") = "abc"; // change projectile string
      REQUIRE(t.meta("projectile") == "abc"); // verify that it changed

      // assignments "work" (don't cause a crash) for nonexistent metadata
      // keys, but give back found == false
      REQUIRE((found = true, t.meta("foo key",found) = "foo value", !found));
      REQUIRE((found = true, t.meta("bar key",found) = "bar value", !found));
   }
}
