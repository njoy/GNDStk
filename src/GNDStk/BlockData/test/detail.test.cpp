
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;
inline std::string bar = "bar";

// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing various BlockData-related detail:: constructs") {

   // ------------------------
   // scalarize
   // ------------------------

   GIVEN("Some variants of vectors") {
      using vc = std::variant<
         std::vector<char>
      >;
      using vci = std::variant<
         std::vector<char>,
         std::vector<int>
      >;
      using vcid = std::variant<
         std::vector<char>,
         std::vector<int>,
         std::vector<double>
      >;

      // Double parenthesis are needed for the CHECK macro,
      // because of the commas...
      THEN("detail::scalarize() works correctly") {
         CHECK((
            std::is_same_v<
               decltype(detail::scalarize(vc{})),
               std::variant<char>
            >
         ));
         CHECK((
            std::is_same_v<
               decltype(detail::scalarize(vci{})),
               std::variant<char,int>
            >
         ));
         CHECK((
            std::is_same_v<
               decltype(detail::scalarize(vcid{})),
               std::variant<char,int,double>
            >
         ));
      }
   } // GIVEN


   // ------------------------
   // element2element
   // ------------------------

   GIVEN("Testing detail::element2element") {
      WHEN("We use element2element(from int, to string)") {
         const int from = 123;
         std::string to;
         detail::element2element(from,to);
         CHECK(to == "123");
      }

      WHEN("We use element2element(from double, to string)") {
         const double from = 4.56;
         std::string to;
         detail::element2element(from,to);
         CHECK(to == "4.56");
      }

      WHEN("We use element2element(from string, to int)") {
         const std::string from = "987";
         int to;
         detail::element2element(from,to);
         CHECK(to == 987);
      }

      WHEN("We use element2element(from string, to double)") {
         const std::string from = "6.54";
         double to;
         detail::element2element(from,to);
         CHECK(Approx(to) == 6.54);
      }

      WHEN("We use element2element(from int, to double)") {
         const int from = 345;
         double to;
         detail::element2element(from,to);
         CHECK(to == double(345));
      }

      WHEN("We use element2element(from double, to int)") {
         const double from = 6.78;
         int to;
         detail::element2element(from,to);
         CHECK(to == 6);
      }
   }


   // ------------------------
   // getBounds
   // ------------------------

   GIVEN("Testing detail::getBounds") {

      // ------------------------
      // Various vector<int>s
      // ------------------------

      WHEN("We try vector<int>s of varying sizes") {

         THEN("Bounds are correct when size == 0") {
            std::vector<int> v = {};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 0);
            CHECK(bounds.second == 0);
         }

         THEN("Bounds are correct when size == 1, with a 0") {
            std::vector<int> v = {0};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 1);
            CHECK(bounds.second == 1);
         }

         THEN("Bounds are correct when size == 2, all 0") {
            std::vector<int> v = {0, 0};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 2);
            CHECK(bounds.second == 2);
         }

         THEN("Bounds are correct when size == 3, all non-0") {
            std::vector<int> v = {2, 3, 5};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 0);
            CHECK(bounds.second == 3);
         }

         THEN("Bounds are correct when there are trailing 0s") {
            std::vector<int> v = {2, 3, 5, 0, 0, 0};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 0);
            CHECK(bounds.second == 3);
         }

         THEN("Bounds are correct when there are leading 0s") {
            std::vector<int> v = {0, 0, 2, 3, 5};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 2);
            CHECK(bounds.second == 5);
         }

         THEN("Bounds are correct when there are leading and trailing 0s") {
            std::vector<int> v = {0, 0, 2, 3, 5, 0, 0, 0};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 2);
            CHECK(bounds.second == 5);
         }

      } // WHEN


      // ------------------------
      // Various vector<double>s
      // ------------------------

      WHEN("We try vector<double>s of varying sizes") {

         THEN("Bounds are correct when size == 0") {
            std::vector<double> v = {};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 0);
            CHECK(bounds.second == 0);
         }

         THEN("Bounds are correct when size == 1, with a 0") {
            std::vector<double> v = {0};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 1);
            CHECK(bounds.second == 1);
         }

         THEN("Bounds are correct when size == 3, all 0") {
            std::vector<double> v = {0, 0, 0};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 3);
            CHECK(bounds.second == 3);
         }

         THEN("Bounds are correct when size == 3, all non-0") {
            std::vector<double> v = {1.2, 3.4, 5.6};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 0);
            CHECK(bounds.second == 3);
         }

         THEN("Bounds are correct when there are trailing 0s") {
            std::vector<double> v = {1.2, 3.4, 5.6, 0, 0};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 0);
            CHECK(bounds.second == 3);
         }

         THEN("Bounds are correct when there are leading 0s") {
            std::vector<double> v = {0, 0, 0, 1.2, 3.4, 5.6};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 3);
            CHECK(bounds.second == 6);
         }

         THEN("Bounds are correct when there are leading and trailing 0s") {
            std::vector<double> v = {0, 0, 0, 1.2, 3.4, 5.6, 0, 0};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 3);
            CHECK(bounds.second == 6);
         }

      }


      // ------------------------
      // Various vector<string>s
      // ------------------------

      WHEN("We try vector<string>s of varying sizes") {

         THEN("Bounds are correct when size == 0") {
            std::vector<std::string> v = {};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 0);
            CHECK(bounds.second == 0);
         }

         THEN("Bounds are correct when size == 1, with a \"\"") {
            std::vector<std::string> v = {""};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 1);
            CHECK(bounds.second == 1);
         }

         THEN("Bounds are correct when size == 2, all \"\"") {
            std::vector<std::string> v = {"", ""};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 2);
            CHECK(bounds.second == 2);
         }

         THEN("Bounds are correct when size == 2, all non-\"\"") {
            std::vector<std::string> v = {"abc", "def"};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 0);
            CHECK(bounds.second == 2);
         }

         THEN("Bounds are correct when there are trailing \"\"s") {
            std::vector<std::string> v = {"abc", "def", "", "", ""};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 0);
            CHECK(bounds.second == 2);
         }

         THEN("Bounds are correct when there are leading \"\"s") {
            std::vector<std::string> v = {"", "", "abc", "def"};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 2);
            CHECK(bounds.second == 4);
         }

         THEN("Bounds are correct when there are leading and trailing \"\"s") {
            std::vector<std::string> v = {"", "", "abc", "def", "", "", ""};
            const auto bounds = detail::getBounds(v);
            CHECK(bounds.first  == 2);
            CHECK(bounds.second == 4);
         }

      } // WHEN
   } // GIVEN

} // SCENARIO
