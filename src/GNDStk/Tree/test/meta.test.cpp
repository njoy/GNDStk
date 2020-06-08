
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
   using namespace njoy::GNDStk;
   using namespace mixed::meta;

   GIVEN("A tree read from n-069_Tm_170-covar.xml") {
      // c: a const tree
      const Tree<> c("n-069_Tm_170-covar.xml");
      // t: a non-const tree
      Tree<> t = c;


      // ------------------------
      // meta(string)
      // Dumb string lookup
      // ------------------------

      // const
      CHECK(c.decl().meta("version") == "1.0");
      CHECK(c.decl().meta("encoding") == "UTF-8");
      CHECK(c.top() .meta("projectile") == "n");
      CHECK(c.top() .meta("target") == "Tm170");
      CHECK(c.top() .meta("evaluation") == "ENDF/B-8.0");
      CHECK(c.top() .meta("format") == "1.9");

      // non-const
      CHECK(t.decl().meta("version") == "1.0");
      CHECK(t.decl().meta("encoding") == "UTF-8");
      CHECK(t.top() .meta("projectile") == "n");
      CHECK(t.top() .meta("target") == "Tm170");
      CHECK(t.top() .meta("evaluation") == "ENDF/B-8.0");
      CHECK(t.top() .meta("format") == "1.9");

      // Be sure that all of the above return references, given that both const
      // and non-const meta(string) use decltype(auto) and some other constructs
      // in arguably not-too-common ways. The following won't compile unless
      // references are returned.
      (void)&c.decl().meta("version");
      (void)&c.decl().meta("encoding");
      (void)&c.top() .meta("projectile");
      (void)&c.top() .meta("target");
      (void)&c.top() .meta("evaluation");
      (void)&c.top() .meta("format");
      (void)&t.decl().meta("version");
      (void)&t.decl().meta("encoding");
      (void)&t.top() .meta("projectile");
      (void)&t.top() .meta("target");
      (void)&t.top() .meta("evaluation");
      (void)&t.top() .meta("format");

      // Again doing the lookups as earlier, be sure they always give back
      // a true "found" if we send "found" at all...
      bool found;
      CHECK((found=false,c.decl().meta("version",   found)=="1.0"        && found));
      CHECK((found=false,c.decl().meta("encoding",  found)=="UTF-8"      && found));
      CHECK((found=false,c.top() .meta("projectile",found)=="n"          && found));
      CHECK((found=false,c.top() .meta("target",    found)=="Tm170"      && found));
      CHECK((found=false,c.top() .meta("evaluation",found)=="ENDF/B-8.0" && found));
      CHECK((found=false,c.top() .meta("format",    found)=="1.9"        && found));
      CHECK((found=false,t.decl().meta("version",   found)=="1.0"        && found));
      CHECK((found=false,t.decl().meta("encoding",  found)=="UTF-8"      && found));
      CHECK((found=false,t.top() .meta("projectile",found)=="n"          && found));
      CHECK((found=false,t.top() .meta("target",    found)=="Tm170"      && found));
      CHECK((found=false,t.top() .meta("evaluation",found)=="ENDF/B-8.0" && found));
      CHECK((found=false,t.top() .meta("format",    found)=="1.9"        && found));

      // Now, try to look up something that isn't there, and be sure "found"
      // comes back as false. (If we didn't send it at all, then attempting
      // to look up a nonexistent metadata key would trigger an error).
      // Const version, then non-const...
      CHECK((found = true, c.meta("foo", found), found == false));
      CHECK((found = true, t.meta("bar", found), found == false));


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
      // meta<void> cases should trigger [const] reference returns...
      (void)&c.top().meta(target);
      (void)&t.top().meta(target);

      // *** format ***
      // extract as double
      // appears in top-level GNDS node
      const meta_t<double> format("format");

      // fixme Floating-point comparisons aren't necessarily reliable
      CHECK( c.decl().meta <double     > ( version    ) ==  1.0    ); // double
      CHECK( c.decl().meta <std::string> ( version    ) == "1.0"   ); // string
      CHECK( c.decl().meta               ( encoding   ) == "UTF-8" ); // string
      CHECK( c.top() .meta <char       > ( projectile ) == 'n'     ); // char
      CHECK( c.top() .meta <std::string> ( projectile ) == "n"     ); // string
      CHECK( c.top() .meta               ( target     ) == "Tm170" ); // string
      CHECK( c.top() .meta               ( format     ) ==  1.9    ); // double

      // Test found
      CHECK((found=false,
             c.decl().meta <double     > ( version    , found) ==  1.0    && found));
      CHECK((found=false,
             c.decl().meta <std::string> ( version    , found) == "1.0"   && found));
      CHECK((found=false,
             c.decl().meta               ( encoding   , found) == "UTF-8" && found));
      CHECK((found=false,
             c.top() .meta <char       > ( projectile , found) == 'n'     && found));
      CHECK((found=false,
             c.top() .meta <std::string> ( projectile , found) == "n"     && found));
      CHECK((found=false,
             c.top() .meta               ( target     , found) == "Tm170" && found));
      CHECK((found=false,
             c.top() .meta               ( format     , found) ==  1.9    && found));

      // Test not-found
      meta_t<int> foo("foo");
      meta_t<std::variant<int,double>> bar("bar");
      CHECK((found = true, c.meta        (foo,found), found == false));
      CHECK((found = true, c.meta<int   >(bar,found), found == false));
      CHECK((found = true, c.meta<double>(bar,found), found == false));


      // ------------------------
      // meta(string) again;
      // test assignment into
      // metadata
      // ------------------------

      // something in the declaration node
      t.decl().meta("version") = "1.2345"; // change version string
      CHECK(t.decl().meta("version") == "1.2345"); // verify that it changed

      // something in the top-level GNDS node
      t.top().meta("projectile") = "abc"; // change projectile string
      CHECK(t.top() .meta("projectile") == "abc"); // verify that it changed

      // assignments "work" (don't cause a crash) for nonexistent metadata
      // keys, but give back found == false
      CHECK((found = true, t.meta("foo key",found) = "foo value", !found));
      CHECK((found = true, t.meta("bar key",found) = "bar value", !found));
   }
}
