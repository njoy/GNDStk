
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;

// helper
template<detail::PrecisionContext CONTEXT, class REAL>
void reset(detail::Precision<CONTEXT,REAL> &p)
{
   p << std::defaultfloat << std::right << std::setw(0) << std::setprecision(6);
}

// SCENARIO
SCENARIO("Testing precision detail:: functionality") {

   using quad = long double;

   // ------------------------
   // FYI
   // ------------------------

   // Values for PrecisionContext
   (void)detail::PrecisionContext::metadata;
   (void)detail::PrecisionContext::data;
   (void)detail::PrecisionContext::general;

   // Values for PrecisionType
   (void)detail::PrecisionType::stream;
   (void)detail::PrecisionType::fixed;
   (void)detail::PrecisionType::scientific;
   (void)detail::PrecisionType::shortest;

   // Stub classes that function as stream manipulators
   { detail::Fixed      foo; (void)foo; }
   { detail::Scientific foo; (void)foo; }
   { detail::Shortest   foo; (void)foo; }


   // ------------------------
   // Precision<*,*>
   // ------------------------

   GIVEN("Precision< metadata|data, float|double|quad >") {
      // Cases, FYI
      /*
      { detail::Precision<detail::PrecisionContext::metadata,float > p; };
      { detail::Precision<detail::PrecisionContext::metadata,double> p; };
      { detail::Precision<detail::PrecisionContext::metadata,quad  > p; };
      { detail::Precision<detail::PrecisionContext::data,    float > p; };
      { detail::Precision<detail::PrecisionContext::data,    double> p; };
      { detail::Precision<detail::PrecisionContext::data,    quad  > p; };
      */

      WHEN("We try Precision<metadata,double>") {
         detail::Precision<detail::PrecisionContext::metadata,double> p;
         reset(p);

         THEN("Various manipulators work as expected") {
            CHECK(p.write(1.234) == "1.234");

            p << std::setw(10);
            CHECK(p.write(5.678) == "     5.678");

            // as elsewhere in C++, setw() isn't "persistent", so...
            p << std::setw(10) << std::left;
            CHECK(p.write(8.642) == "8.642     ");

            p << std::scientific;
            CHECK(p.write(3.14) == "3.140000e+00");

            // read
            CHECK(p.read("1.234") == 1.234);
            CHECK(p.read("     5.678") == 5.678);
            CHECK(p.read("8.642     ") == 8.642);
            CHECK(p.read("3.140000e+00") == 3.14);
         }

         // These won't have any effect until we enable the code that depends
         // on later-model compilers, but let's be sure they compile...
         THEN("We can << and >> detail::Fixed|Scientific|Shortest") {
            p << detail::Fixed{} << detail::Scientific{} << detail::Shortest{};
            p >> detail::Fixed{} >> detail::Scientific{} >> detail::Shortest{};
         } // THEN
      } // WHEN

      WHEN("We send manipulators to Precision<metadata>") {
         THEN("They don't interfere with Precision<data>'s behavior") {
            detail::Precision<detail::PrecisionContext::metadata,double> m;
            detail::Precision<detail::PrecisionContext::data,    double> d;
            reset(m);
            reset(d);

            CHECK(d.write(1.234) == "1.234"); // data

            m << std::setw(10);               // metadata
            CHECK(d.write(5.678) == "5.678"); // data

            m << std::setw(10) << std::left;  // metadata
            CHECK(d.write(8.642) == "8.642"); // data

            m << std::scientific;             // metadata
            CHECK(d.write(3.14) == "3.14");   // data
         } // THEN
      } // WHEN
   } // GIVEN


   // ------------------------
   // Precision<*,void>
   // ------------------------

   GIVEN("Precision< metadata|data, void >") {
      // Cases, FYI
      /*
      { detail::Precision<detail::PrecisionContext::metadata,void  > p; };
      { detail::Precision<detail::PrecisionContext::data,    void  > p; };
      */

      // Use <data> for the test...
      detail::Precision<detail::PrecisionContext::data,void  > v;
      detail::Precision<detail::PrecisionContext::data,float > f;
      detail::Precision<detail::PrecisionContext::data,double> d;
      detail::Precision<detail::PrecisionContext::data,quad  > q;
      reset(v);
      reset(f);
      reset(d);
      reset(q);

      THEN("The <void> makes it work for all floating-point types") {
         CHECK(f.write(1.234) == "1.234"); // float
         CHECK(d.write(1.234) == "1.234"); // double
         CHECK(q.write(1.234) == "1.234"); // quad

         v << std::setw(10);                    // void
         CHECK(f.write(5.678) == "     5.678"); // float
         CHECK(d.write(5.678) == "     5.678"); // double
         CHECK(q.write(5.678) == "     5.678"); // quad

         v << std::setw(10) << std::left;       // void
         CHECK(f.write(8.642) == "8.642     "); // float
         CHECK(d.write(8.642) == "8.642     "); // double
         CHECK(q.write(8.642) == "8.642     "); // double

         v << std::scientific;                   // void
         CHECK(f.write(3.14) == "3.140000e+00"); // float
         CHECK(d.write(3.14) == "3.140000e+00"); // double
         CHECK(q.write(3.14) == "3.140000e+00"); // quad
      } // THEN
   } // GIVEN


   // ------------------------
   // Precision<general,*>
   // ------------------------

   GIVEN("Precision< general, float|double|quad >") {
      // Cases, FYI
      /*
      { detail::Precision<detail::PrecisionContext::general, float > p; };
      { detail::Precision<detail::PrecisionContext::general, double> p; };
      { detail::Precision<detail::PrecisionContext::general, quad  > p; };
      */

      // Use <double> for the test...
      detail::Precision<detail::PrecisionContext::general, double> g;
      detail::Precision<detail::PrecisionContext::metadata,double> m;
      detail::Precision<detail::PrecisionContext::data,    double> d;
      reset(g);
      reset(m);
      reset(d);

      THEN("The <general> makes it work for both metadata and data") {
         CHECK(m.write(1.234) == "1.234");
         CHECK(d.write(1.234) == "1.234");

         g << std::setw(10);                    // general
         CHECK(m.write(5.678) == "     5.678"); // metadata
         CHECK(d.write(5.678) == "     5.678"); // data

         g << std::setw(10) << std::left;       // general
         CHECK(m.write(8.642) == "8.642     "); // metadata
         CHECK(d.write(8.642) == "8.642     "); // data

         g << std::scientific;                   // general
         CHECK(m.write(3.14) == "3.140000e+00"); // metadata
         CHECK(d.write(3.14) == "3.140000e+00"); // data
      } // THEN
   } // GIVEN


   // ------------------------
   // Precision<general,void>
   // ------------------------

   GIVEN("Precision< general, void >") {
      // Cases, FYI
      /*
      { detail::Precision<detail::PrecisionContext::general, void  > p; };
      */

      detail::Precision<detail::PrecisionContext::general, void  > all;
      detail::Precision<detail::PrecisionContext::metadata,float > mf;
      detail::Precision<detail::PrecisionContext::metadata,double> md;
      detail::Precision<detail::PrecisionContext::metadata,quad  > mq;
      detail::Precision<detail::PrecisionContext::data,    float > df;
      detail::Precision<detail::PrecisionContext::data,    double> dd;
      detail::Precision<detail::PrecisionContext::data,    quad  > dq;
      reset(all);
      reset(mf);
      reset(md);
      reset(mq);
      reset(df);
      reset(dd);
      reset(dq);

      THEN(
         "The <general,void> makes it work for metadata, data, "
         "and all floating-point types"
      ) {
         CHECK(mf.write(1.234) == "1.234");
         CHECK(md.write(1.234) == "1.234");
         CHECK(mq.write(1.234) == "1.234");
         CHECK(df.write(1.234) == "1.234");
         CHECK(dd.write(1.234) == "1.234");
         CHECK(dq.write(1.234) == "1.234");

         all << std::setw(10);                   // all
         CHECK(mf.write(5.678) == "     5.678"); // metadata, float
         CHECK(md.write(5.678) == "     5.678"); // metadata, double
         CHECK(mq.write(5.678) == "     5.678"); // metadata, quad
         CHECK(df.write(5.678) == "     5.678"); // data, float
         CHECK(dd.write(5.678) == "     5.678"); // data, double
         CHECK(dq.write(5.678) == "     5.678"); // data, quad

         all << std::setw(10) << std::left;      // all
         CHECK(mf.write(8.642) == "8.642     "); // metadata, float
         CHECK(md.write(8.642) == "8.642     "); // metadata, double
         CHECK(mq.write(8.642) == "8.642     "); // metadata, quad
         CHECK(df.write(8.642) == "8.642     "); // data, float
         CHECK(dd.write(8.642) == "8.642     "); // data, double
         CHECK(dq.write(8.642) == "8.642     "); // data, quad

         all << std::scientific;                  // all
         CHECK(mf.write(3.14) == "3.140000e+00"); // metadata, float
         CHECK(md.write(3.14) == "3.140000e+00"); // metadata, double
         CHECK(mq.write(3.14) == "3.140000e+00"); // metadata, quad
         CHECK(df.write(3.14) == "3.140000e+00"); // data, float
         CHECK(dd.write(3.14) == "3.140000e+00"); // data, double
         CHECK(dq.write(3.14) == "3.140000e+00"); // data, quad
      } // THEN
   } // GIVEN
} // SCENARIO
