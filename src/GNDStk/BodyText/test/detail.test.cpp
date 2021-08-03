
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;
inline std::string bar = "bar";

// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing various BodyText-related detail:: constructs") {

   // ------------------------
   // scalarize
   // ------------------------

   GIVEN("Testing detail::scalarize") {
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
   } // GIVEN


   // ------------------------
   // decays
   // ------------------------

   GIVEN("Testing detail::decays") {
      using tup1 = std::tuple<>;
      using tup2 = std::tuple<int, volatile double &>;
      using tup3 = std::tuple<const int, float &>;
      using tup4 = std::tuple<int &, long>;
      using tup5 = std::tuple<const int &>;

      CHECK((std::is_same_v<detail::decays_t<tup1>, std::tuple<>>));
      CHECK((std::is_same_v<detail::decays_t<tup2>, std::tuple<int,double>>));
      CHECK((std::is_same_v<detail::decays_t<tup3>, std::tuple<int,float>>));
      CHECK((std::is_same_v<detail::decays_t<tup4>, std::tuple<int,long>>));
      CHECK((std::is_same_v<detail::decays_t<tup5>, std::tuple<int>>));
   } // GIVEN


   // ------------------------
   // hasLength, hasStart,
   // hasValueType
   // ------------------------

   GIVEN("Testing detail::hasLength,hasStart,hasValueType") {
      {
         struct {
            int length;
            const double start = 0;
            const std::string &valueType = bar;
         } foo;
         CHECK((detail::hasLength   <decltype(foo)> == true));
         CHECK((detail::hasStart    <decltype(foo)> == true));
         CHECK((detail::hasValueType<decltype(foo)> == true));
      }

      {
         struct {
            const double start = 0;
            const std::string &valueType = bar;
         } foo;
         CHECK((detail::hasLength   <decltype(foo)> == false));
         CHECK((detail::hasStart    <decltype(foo)> == true));
         CHECK((detail::hasValueType<decltype(foo)> == true));
      }

      {
         struct {
            int length;
            const std::string &valueType = bar;
         } foo;
         CHECK((detail::hasLength   <decltype(foo)> == true));
         CHECK((detail::hasStart    <decltype(foo)> == false));
         CHECK((detail::hasValueType<decltype(foo)> == true));
      }

      {
         struct {
            int length;
            const double start = 0;
         } foo;
         CHECK((detail::hasLength   <decltype(foo)> == true));
         CHECK((detail::hasStart    <decltype(foo)> == true));
         CHECK((detail::hasValueType<decltype(foo)> == false));
      }

      {
         struct {
            int length;
         } foo;
         CHECK((detail::hasLength   <decltype(foo)> == true));
         CHECK((detail::hasStart    <decltype(foo)> == false));
         CHECK((detail::hasValueType<decltype(foo)> == false));
      }

      {
         struct {
            const double start = 0;
         } foo;
         CHECK((detail::hasLength   <decltype(foo)> == false));
         CHECK((detail::hasStart    <decltype(foo)> == true));
         CHECK((detail::hasValueType<decltype(foo)> == false));
      }

      {
         struct {
            const std::string &valueType = bar;
         } foo;
         CHECK((detail::hasLength   <decltype(foo)> == false));
         CHECK((detail::hasStart    <decltype(foo)> == false));
         CHECK((detail::hasValueType<decltype(foo)> == true));
      }

      {
         struct {
         } foo;
         CHECK((detail::hasLength   <decltype(foo)> == false));
         CHECK((detail::hasStart    <decltype(foo)> == false));
         CHECK((detail::hasValueType<decltype(foo)> == false));
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

      // Various vector<int>s
      {
         std::vector<int> v = {};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 0);
         CHECK(bounds.second == 0);
      } {
         std::vector<int> v = {0};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 1);
         CHECK(bounds.second == 1);
      } {
         std::vector<int> v = {0, 0};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 2);
         CHECK(bounds.second == 2);
      } {
         std::vector<int> v = {2, 3, 5};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 0);
         CHECK(bounds.second == 3);
      } {
         std::vector<int> v = {2, 3, 5, 0, 0, 0};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 0);
         CHECK(bounds.second == 3);
      } {
         std::vector<int> v = {0, 0, 2, 3, 5};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 2);
         CHECK(bounds.second == 5);
      } {
         std::vector<int> v = {0, 0, 2, 3, 5, 0, 0, 0};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 2);
         CHECK(bounds.second == 5);
      }

      // Various vector<double>s
      {
         std::vector<double> v = {};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 0);
         CHECK(bounds.second == 0);
      } {
         std::vector<double> v = {0};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 1);
         CHECK(bounds.second == 1);
      } {
         std::vector<double> v = {0, 0, 0};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 3);
         CHECK(bounds.second == 3);
      } {
         std::vector<double> v = {1.2, 3.4, 5.6};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 0);
         CHECK(bounds.second == 3);
      } {
         std::vector<double> v = {1.2, 3.4, 5.6, 0, 0};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 0);
         CHECK(bounds.second == 3);
      } {
         std::vector<double> v = {0, 0, 0, 1.2, 3.4, 5.6};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 3);
         CHECK(bounds.second == 6);
      } {
         std::vector<double> v = {0, 0, 0, 1.2, 3.4, 5.6, 0, 0};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 3);
         CHECK(bounds.second == 6);
      }

      // Various vector<string>s
      {
         std::vector<std::string> v = {};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 0);
         CHECK(bounds.second == 0);
      } {
         std::vector<std::string> v = {""};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 1);
         CHECK(bounds.second == 1);
      } {
         std::vector<std::string> v = {"", ""};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 2);
         CHECK(bounds.second == 2);
      } {
         std::vector<std::string> v = {"abc", "def"};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 0);
         CHECK(bounds.second == 2);
      } {
         std::vector<std::string> v = {"abc", "def", "", "", ""};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 0);
         CHECK(bounds.second == 2);
      } {
         std::vector<std::string> v = {"", "", "abc", "def"};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 2);
         CHECK(bounds.second == 4);
      } {
         std::vector<std::string> v = {"", "", "abc", "def", "", "", ""};
         const auto bounds = detail::getBounds(v);
         CHECK(bounds.first  == 2);
         CHECK(bounds.second == 4);
      }
   }

} // SCENARIO
