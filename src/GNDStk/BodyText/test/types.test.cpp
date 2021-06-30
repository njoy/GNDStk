
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;

// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("BodyText data types") {
   GIVEN("std::vector<T> for certain specific Ts") {

      // vector type
      using vv = BodyText<true>::VariantOfVectors;
      CHECK(std::variant_size_v<vv> == 15);
      vv vectors;

      // scalar type

      using vs = BodyText<true>::VariantOfScalars;
      CHECK(std::variant_size_v<vv> == 15);
      vs scalars;

      {
         vectors = std::vector<std::string>(10,"a");
         scalars = std::get<std::vector<std::string>>(vectors)[0];
         CHECK(std::get<std::string>(scalars) == "a");
      } {
         vectors = std::vector<char>(10,'b');
         scalars = std::get<std::vector<char>>(vectors)[0];
         CHECK(std::get<char>(scalars) == 'b');
      } {
         vectors = std::vector<signed char>(10,-100);
         scalars = std::get<std::vector<signed char>>(vectors)[0];
         CHECK(std::get<signed char>(scalars) == -100);
      } {
         vectors = std::vector<short>(10,-200);
         scalars = std::get<std::vector<short>>(vectors)[0];
         CHECK(std::get<short>(scalars) == -200);
      } {
         vectors = std::vector<int>(10,-300);
         scalars = std::get<std::vector<int>>(vectors)[0];
         CHECK(std::get<int>(scalars) == -300);
      } {
         vectors = std::vector<long>(10,-400);
         scalars = std::get<std::vector<long>>(vectors)[0];
         CHECK(std::get<long>(scalars) == -400);
      } {
         vectors = std::vector<long long>(10,-500);
         scalars = std::get<std::vector<long long>>(vectors)[0];
         CHECK(std::get<long long>(scalars) == -500);
      } {
         vectors = std::vector<unsigned char>(10,100);
         scalars = std::get<std::vector<unsigned char>>(vectors)[0];
         CHECK(std::get<unsigned char>(scalars) == 100);
      } {
         vectors = std::vector<unsigned short>(10,200);
         scalars = std::get<std::vector<unsigned short>>(vectors)[0];
         CHECK(std::get<unsigned short>(scalars) == 200);
      } {
         vectors = std::vector<unsigned int>(10,300);
         scalars = std::get<std::vector<unsigned int>>(vectors)[0];
         CHECK(std::get<unsigned int>(scalars) == 300);
      } {
         vectors = std::vector<unsigned long>(10,400);
         scalars = std::get<std::vector<unsigned long>>(vectors)[0];
         CHECK(std::get<unsigned long>(scalars) == 400);
      } {
         vectors = std::vector<unsigned long long>(10,500);
         scalars = std::get<std::vector<unsigned long long>>(vectors)[0];
         CHECK(std::get<unsigned long long>(scalars) == 500);
      } {
         vectors = std::vector<float>(10,-1.2f);
         scalars = std::get<std::vector<float>>(vectors)[0];
         CHECK(std::get<float>(scalars) == -1.2f);
      } {
         vectors = std::vector<double>(10,3.4);
         scalars = std::get<std::vector<double>>(vectors)[0];
         CHECK(std::get<double>(scalars) == 3.4);
      } {
         vectors = std::vector<long double>(10,-5.6);
         scalars = std::get<std::vector<long double>>(vectors)[0];
         CHECK(std::get<long double>(scalars) == -5.6);
      }

   } // GIVEN
} // SCENARIO
