
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;

// I'm arguably overdoing it in this file, testing so many different
// permutations of essentially the same underlying capability. We do
// however have lots of query functions - which are called by these -
// and they take lots of different permutations of similar constructs.

SCENARIO("Testing GNDStk Node has*() functions") {
   Tree<> tree("n-008_O_016.xml");

   // We'll use a mixture of const and non-const nodes in the tests,
   // just to change things up. All has* functions are const.
   Node<> &n = tree.top();
   CHECK(n.name == "reactionSuite");
   const Node<> &c = tree.top();
   CHECK(c.name == "reactionSuite");

   GIVEN("A GNDS node") {

      // ------------------------
      // has_meta
      // ------------------------

      WHEN("has_meta(*) is called") {
         THEN("has_meta(*) succeeds where meta(*) would succeed") {
            // meta(string)
            CHECK(n.has_meta("projectile"));
            CHECK(c.has_meta("projectileFrame"));
            CHECK(n.has_meta(".*Frame")); // regex
            // meta(Meta<void>)
            CHECK(n.has_meta(Meta<>("projectile")));
            CHECK(c.has_meta(Meta<>("projectileFrame")));
            CHECK(n.has_meta(Meta<>(".*Frame")));
            // meta(Meta<non-void>)
            CHECK(n.has_meta(Meta<char>("projectile")));
            CHECK(c.has_meta(Meta<std::string>("projectileFrame")));
            CHECK(n.has_meta(Meta<std::string>(".*Frame")));
         }

         THEN("has_meta(*) fails where meta(*) would fail") {
            // meta(string)
            CHECK(!n.has_meta("projectile ")); // extra space at end
            CHECK(!c.has_meta(".*foobar"));
            CHECK(!n.has_meta(""));
            // meta(Meta<void>)
            CHECK(!n.has_meta(Meta<>("projectile ")));
            CHECK(!c.has_meta(Meta<>(".*foobar")));
            CHECK(!n.has_meta(Meta<>("")));
            // meta(Meta<non-void>)
            CHECK(!n.has_meta(Meta<int>("projectile ")));
            CHECK(!c.has_meta(Meta<float>(".*foobar")));
            CHECK(!n.has_meta(Meta<double>("")));
         }
      }

      // ------------------------
      // has_one
      // ------------------------

      WHEN("has_one(*) is called") {
         THEN("has_one(*) succeeds where one(*) would succeed") {
            // some filters
            auto filter1 = [](const node &n)
               { return n.meta("version") == "1.0"; };
            auto filter2 = [](const node &n)
               { return n.meta("format") == "0.1"; };

            // with filter
            CHECK(n.has_one("PoPs",filter1));
            CHECK(c.has_one("PoPs",filter2));

            // without filter
            CHECK(n.has_one("styles"));
            CHECK(c.has_one("externalFiles"));

            // one(""), i.e. with the empty string, has a special meaning:
            // return the current node - which always succeeds. (The filter,
            // if any, isn't even invoked in that case!) Users don't normally
            // need to call one() this way; the behavior exists to support
            // certain features in more-advanced query functions. For our
            // present purposes, however, we should, and do, check the case.
            auto bad_filter = [](const node &n)
               { assert(false); return false; }; // <== won't be invoked
            CHECK(n.has_one(""));
            CHECK(c.has_one("",bad_filter)); // still succeeds
         }

         THEN("has_one(*) fails where one(*) would fail") {
            // some filters
            auto filter1 = [](const node &n)
               { return n.meta("version") == "1.0"; };
            auto filter2 = [](const node &n)
               { return n.meta("format") == "0.2"; }; // oops, 0.2

            // with filter
            CHECK(!n.has_one("foo",filter1)); // "foo" fails; filter !relevant
            CHECK(!c.has_one("PoPs",filter2)); // filter2 fails

            // without filter
            CHECK(!n.has_one("Foo"));
            CHECK(!c.has_one("Bar"));
         }
      }

      // ------------------------
      // has_many
      // ------------------------

      // Remark: has_many(...) simply means that many(...) comes back with
      // found == true, i.e., the thing being looked for was found. It does
      // NOT mean something like "has many - i.e. *has more than one*. For
      // the purposes of testing, then, we can use the same material we did
      // for has_one() above...

      WHEN("has_many(*) is called") {
         THEN("has_many(*) succeeds where many(*) would succeed") {
            // some filters
            auto filter1 = [](const node &n)
               { return n.meta("version") == "1.0"; };
            auto filter2 = [](const node &n)
               { return n.meta("format") == "0.1"; };

            // with filter
            CHECK(n.has_many("PoPs",filter1));
            CHECK(c.has_many("PoPs",filter2));

            // without filter
            CHECK(n.has_many("styles"));
            CHECK(c.has_many("externalFiles"));

            auto bad_filter = [](const node &n)
               { assert(false); return false; }; // <== won't be invoked
            CHECK(n.has_many(""));
            CHECK(c.has_many("",bad_filter));
         }

         THEN("has_many(*) fails where many(*) would fail") {
            // some filters
            auto filter1 = [](const node &n)
               { return n.meta("version") == "1.0"; };
            auto filter2 = [](const node &n)
               { return n.meta("format") == "0.2"; };

            // with filter
            CHECK(!n.has_many("foo",filter1));
            CHECK(!c.has_many("PoPs",filter2));

            // without filter
            CHECK(!n.has_many("Foo"));
            CHECK(!c.has_many("Bar"));
         }
      }

      // ------------------------
      // has_child
      // ------------------------

      // We'll need calls for these cases:
      //    child(Child<void,one>) [const]
      //    child(Child<void,many>)
      //    child(Child<TYPE,one>)
      //    child(Child<TYPE,many>)

      WHEN("has_child(*) is called") {

         // we'll change these up, using operators,
         // to test various child() calls
         const Child<void> PoPs("PoPs");
         const Child<void> styles("styles");
         const Child<void> externalFiles("externalFiles");
         const Child<void> foo("foo");
         const Child<void> Foo("Foo");
         const Child<void> Bar("Bar");
         const Child<void> empty("");

         // made-up node-to-string converter, just for the sake of trying
         // it out; GNDStk actually has one already, by virtue of the fact
         // that node has stream output
         auto conv = [](const node &n, std::string &str)
            { str = "We have here a node named " + n.name; };
         const std::string s = ""; // for TYPE{}/Child

         THEN("has_child(*) succeeds where child(*) would succeed") {
            // some filters
            auto filter1 = [](const node &n)
               { return n.meta("version") == "1.0"; };
            auto filter2 = [](const node &n)
               { return n.meta("format") == "0.1"; };

            // with filter
            CHECK(n.has_child(  --PoPs + filter1));
            CHECK(n.has_child(  ++PoPs + filter1));
            CHECK(n.has_child(s/--PoPs/conv + filter1));
            CHECK(n.has_child(s/++PoPs + filter1));

            CHECK(c.has_child(  --PoPs + filter2));
            CHECK(c.has_child(  ++PoPs + filter2));
            CHECK(c.has_child(s/--PoPs + filter2));
            CHECK(c.has_child(s/++PoPs/conv + filter2));

            // without filter
            CHECK(n.has_child(  --styles));
            CHECK(n.has_child(  ++styles));
            CHECK(n.has_child(s/--styles));
            CHECK(n.has_child(s/++styles/conv));

            CHECK(c.has_child(  --externalFiles));
            CHECK(c.has_child(  ++externalFiles));
            CHECK(c.has_child(s/--externalFiles/conv));
            CHECK(c.has_child(s/++externalFiles));

            auto bad_filter = [](const node &n)
               { assert(false); return false; }; // <== won't be invoked

            CHECK(n.has_child(  --empty));
            CHECK(n.has_child(  ++empty));
            CHECK(n.has_child(s/--empty/conv));
            CHECK(n.has_child(s/++empty));

            CHECK(c.has_child(  --empty + bad_filter));
            CHECK(c.has_child(  ++empty + bad_filter));
            CHECK(c.has_child(s/--empty + bad_filter));
            CHECK(c.has_child(s/++empty/conv + bad_filter));
         }

         THEN("has_child(*) fails where child(*) would fail") {
            // some filters
            auto filter1 = [](const node &n)
               { return n.meta("version") == "1.0"; };
            auto filter2 = [](const node &n)
               { return n.meta("format") == "0.2"; };

            // with filter
            CHECK(!n.has_child(  --foo + filter1));
            CHECK(!n.has_child(  ++foo + filter1));
            CHECK(!n.has_child(s/--foo/conv + filter1));
            CHECK(!n.has_child(s/++foo + filter1));

            CHECK(!c.has_child(  --PoPs + filter2));
            CHECK(!c.has_child(  ++PoPs + filter2));
            CHECK(!c.has_child(s/--PoPs + filter2));
            CHECK(!c.has_child(s/++PoPs/conv + filter2));

            // without filter
            CHECK(!n.has_child(  --Foo));
            CHECK(!n.has_child(  ++Foo));
            CHECK(!n.has_child(s/--Foo));
            CHECK(!n.has_child(s/++Foo/conv));

            CHECK(!c.has_child(  --Bar));
            CHECK(!c.has_child(  ++Bar));
            CHECK(!c.has_child(s/--Bar/conv));
            CHECK(!c.has_child(s/++Bar));
         }
      }

      // ------------------------
      // has(Meta)
      // For operator()(Meta)
      // Similar to has_meta
      // for Meta
      // ------------------------

      WHEN("has(Meta) is called") {
         THEN("has(Meta) succeeds where (Meta) would succeed") {
            // (Meta<void>)
            CHECK(n.has(Meta<>("projectile")));
            CHECK(c.has(Meta<>("projectileFrame")));
            CHECK(n.has(Meta<>(".*Frame")));
            // (Meta<non-void>)
            CHECK(n.has(Meta<char>("projectile")));
            CHECK(c.has(Meta<std::string>("projectileFrame")));
            CHECK(n.has(Meta<std::string>(".*Frame")));
         }

         THEN("has(Meta) fails where (Meta) would fail") {
            // (Meta<void>)
            CHECK(!n.has(Meta<>("projectile ")));
            CHECK(!c.has(Meta<>(".*foobar")));
            CHECK(!n.has(Meta<>("")));
            // (Meta<non-void>)
            CHECK(!n.has(Meta<int>("projectile ")));
            CHECK(!c.has(Meta<float>(".*foobar")));
            CHECK(!n.has(Meta<double>("")));
         }
      }

      // ------------------------
      // has(Child)
      // For operator()(Child)
      // Similar to has_child
      // for Child, but also
      // allows label stuff
      // ------------------------

      WHEN("has(Child) is called") {

         const Child<void> PoPs("PoPs");
         const Child<void> styles("styles");
         const Child<void> externalFiles("externalFiles");
         const Child<void> foo("foo");
         const Child<void> Foo("Foo");
         const Child<void> Bar("Bar");
         const Child<void> empty("");

         auto conv = [](const node &n, std::string &str)
            { str = "We have here a node named " + n.name; };
         std::string s = "";

         THEN("has(Child) succeeds where (Child) would succeed") {
            // some filters
            auto filter1 = [](const node &n)
               { return n.meta("version") == "1.0"; };
            auto filter2 = [](const node &n)
               { return n.meta("format") == "0.1"; };

            // with filter
            CHECK(n.has(  --PoPs + filter1));
            CHECK(n.has(  ++PoPs + filter1));
            CHECK(n.has(s/--PoPs/conv + filter1));
            CHECK(n.has(s/++PoPs + filter1));

            CHECK(c.has(  --PoPs + filter2));
            CHECK(c.has(  ++PoPs + filter2));
            CHECK(c.has(s/--PoPs + filter2));
            CHECK(c.has(s/++PoPs/conv + filter2));

            // without filter
            CHECK(n.has(  --styles));
            CHECK(n.has(  ++styles));
            CHECK(n.has(s/--styles));
            CHECK(n.has(s/++styles/conv));

            CHECK(c.has(  --externalFiles));
            CHECK(c.has(  ++externalFiles));
            CHECK(c.has(s/--externalFiles/conv));
            CHECK(c.has(s/++externalFiles));

            auto bad_filter = [](const node &n)
               { assert(false); return false; }; // <== won't be invoked

            CHECK(n.has(  --empty));
            CHECK(n.has(  ++empty));
            CHECK(n.has(s/--empty/conv));
            CHECK(n.has(s/++empty));

            CHECK(c.has(  --empty + bad_filter));
            CHECK(c.has(  ++empty + bad_filter));
            CHECK(c.has(s/--empty + bad_filter));
            CHECK(c.has(s/++empty/conv + bad_filter));
         }

         THEN("has(Child) fails where (Child) would fail") {
            // some filters
            auto filter1 = [](const node &n)
               { return n.meta("version") == "1.0"; };
            auto filter2 = [](const node &n)
               { return n.meta("format") == "0.2"; };

            // with filter
            CHECK(!n.has(  --foo + filter1));
            CHECK(!n.has(  ++foo + filter1));
            CHECK(!n.has(s/--foo/conv + filter1));
            CHECK(!n.has(s/++foo + filter1));

            CHECK(!c.has(  --PoPs + filter2));
            CHECK(!c.has(  ++PoPs + filter2));
            CHECK(!c.has(s/--PoPs + filter2));
            CHECK(!c.has(s/++PoPs/conv + filter2));

            // without filter
            CHECK(!n.has(  --Foo));
            CHECK(!n.has(  ++Foo));
            CHECK(!n.has(s/--Foo));
            CHECK(!n.has(s/++Foo/conv));

            CHECK(!c.has(  --Bar));
            CHECK(!c.has(  ++Bar));
            CHECK(!c.has(s/--Bar/conv));
            CHECK(!c.has(s/++Bar));
         }
      }

      const Child<> styles("styles");
      const Child<> evaluated("evaluated");
      const Child<> externalFiles("externalFiles");
      const Child<> externalFile("externalFile");
      const std::string s = "";

      WHEN("has(Child,string) is called") {
         CHECK( n(styles).has(  --evaluated,"eval"));
         CHECK( n(styles).has(  ++evaluated,"eval"));
         CHECK( n(styles).has(s/--evaluated,"eval"));
         CHECK( n(styles).has(s/++evaluated,"eval"));
         CHECK( c(styles).has(  --evaluated,"eval"));
         CHECK( c(styles).has(  ++evaluated,"eval"));
         CHECK( c(styles).has(s/--evaluated,"eval"));
         CHECK( c(styles).has(s/++evaluated,"eval"));
         CHECK(!n(styles).has(  --evaluated,"foo"));
         CHECK(!n(styles).has(  ++evaluated,"foo"));
         CHECK(!n(styles).has(s/--evaluated,"foo"));
         CHECK(!n(styles).has(s/++evaluated,"foo"));
         CHECK(!c(styles).has(  --evaluated,"bar"));
         CHECK(!c(styles).has(  ++evaluated,"bar"));
         CHECK(!c(styles).has(s/--evaluated,"bar"));
         CHECK(!c(styles).has(s/++evaluated,"bar"));
      }

      WHEN("has(Child,regex) is called") {
         CHECK( n(externalFiles).has(  --externalFile,std::regex("cov.*")));
         CHECK( n(externalFiles).has(  ++externalFile,std::regex("cov.*")));
         CHECK( n(externalFiles).has(s/--externalFile,std::regex("cov.*")));
         CHECK( n(externalFiles).has(s/++externalFile,std::regex("cov.*")));
         CHECK( c(externalFiles).has(  --externalFile,std::regex("covar.*")));
         CHECK( c(externalFiles).has(  ++externalFile,std::regex("covar.*")));
         CHECK( c(externalFiles).has(s/--externalFile,std::regex("covar.*")));
         CHECK( c(externalFiles).has(s/++externalFile,std::regex("covar.*")));
         CHECK(!n(externalFiles).has(  --externalFile,std::regex(".*foo")));
         CHECK(!n(externalFiles).has(  ++externalFile,std::regex(".*foo")));
         CHECK(!n(externalFiles).has(s/--externalFile,std::regex(".*foo")));
         CHECK(!n(externalFiles).has(s/++externalFile,std::regex(".*foo")));
         CHECK(!c(externalFiles).has(  --externalFile,std::regex("bar.*")));
         CHECK(!c(externalFiles).has(  ++externalFile,std::regex("bar.*")));
         CHECK(!c(externalFiles).has(s/--externalFile,std::regex("bar.*")));
         CHECK(!c(externalFiles).has(s/++externalFile,std::regex("bar.*")));
      }

      // ------------------------
      // has(...)
      // For operator()(...),
      // i.e. our most general
      // call operator
      // ------------------------

      // Given that the fundamentals, as tested above, work correctly,
      // we'll just check a few of these. The underlying operator() just
      // keeps "peeling off" the initial parameters, digging down through
      // the tree until it gets to the end, at which point most of the
      // action occurs.

      WHEN("has(multi-argument) is called") {
         // for some basic (meaning <void> typed) Meta and Child objects
         const Meta<> foo("bar");

         // works where it should
         CHECK(n.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                     Double,value));
         CHECK(c.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                     Double,unit));
         CHECK(n.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                     Double,"eval",value));
         CHECK(c.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                     Double,"eval",unit));
         CHECK(n.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                     Double,std::regex(".*"),value));
         CHECK(c.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                     Double,std::regex(".*"),unit));

         // fails where it should
         CHECK(!n.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                      Double,foo));
         CHECK(!c.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                      Double,foo));
         CHECK(!n.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                      Double,"bad label",value));
         CHECK(!c.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                      Double,"another bad label",unit));
         CHECK(!n.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                      Double,std::regex("foo.*"),value));
         CHECK(!c.has(PoPs,gaugeBosons,--gaugeBoson,mass,
                      Double,std::regex(".*bar"),unit));
      }
   }
}
