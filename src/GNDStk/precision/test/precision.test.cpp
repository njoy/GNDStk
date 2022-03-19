
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;
#include "precision.test.hpp"

// -----------------------------------------------------------------------------
// Description
// -----------------------------------------------------------------------------

/*
Flags for setting precision in various ways:

For metadata only:
GNDStk::metadata::
   inline Precision<PrecisionContext::metadata, double     > doubles;
   inline Precision<PrecisionContext::metadata, float      > floats;
   inline Precision<PrecisionContext::metadata, long double> longdoubles;
   inline Precision<PrecisionContext::metadata, void       > reals;

For data only:
GNDStk::data::
   inline Precision<PrecisionContext::data, double     > doubles;
   inline Precision<PrecisionContext::data, float      > floats;
   inline Precision<PrecisionContext::data, long double> longdoubles;
   inline Precision<PrecisionContext::data, void       > reals;

For both (metadata and data):
GNDStk::
   inline Precision<PrecisionContext::general, double     > doubles;
   inline Precision<PrecisionContext::general, float      > floats;
   inline Precision<PrecisionContext::general, long double> longdoubles;
   inline Precision<PrecisionContext::general, void       > reals;
*/


// Input string for a couple of our scenarios
// The numbers are (approximately, of course) the square roots
// of 2, 3, 5, 6, 7, and 8. That doesn't really matter; they're
// just numbers, for our purposes here.
const std::string input_numbers_metadata =
R"***(
<numbers
   adouble = "1.41421356237309504880168872420969807856967187537694"
   afloat  = "1.73205080756887729352744634150587236694280525381038"
   aquad   = "2.23606797749978969640917366873127623544061835961152"
   bdouble = "2.44948974278317809819728407470589139196594748065667"
   bfloat  = "2.64575131106459059050161575363926042571025918308245"
   bquad   = "2.82842712474619009760337744841939615713934375075389"
>
</numbers>
)***";



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

// ------------------------
// Some expected results
// ------------------------

const std::string xml_metadata_individual =
R"***(<?xml version="1.0"?>
<numbers adouble="1.414214" afloat="1.7321" aquad="2.23606798" bdouble="2.44949" bfloat="2.6458" bquad="2.82842712" />)***";

const std::string xml_metadata_real =
R"***(<?xml version="1.0"?>
<numbers adouble="1.41" afloat="1.73" aquad="2.24" bdouble="2.45" bfloat="2.65" bquad="2.83" />)***";

const std::string xml_gndstk_individual =
R"***(<?xml version="1.0"?>
<numbers adouble="1.4142136" afloat="1.73205" aquad="2.236067977" bdouble="2.4494897" bfloat="2.64575" bquad="2.828427125" />)***";

const std::string xml_gndstk_real =
R"***(<?xml version="1.0"?>
<numbers adouble="1.414" afloat="1.732" aquad="2.236" bdouble="2.449" bfloat="2.646" bquad="2.828" />)***";


// ------------------------
// SCENARIO
// ------------------------

SCENARIO("Precision code in the convert()s between stream and real, "
         "for reading and writing metadata from/to Nodes")
{
   // Context/action:
   //    metadata, read
   //    metadata, write

   Node node;
   node << input_numbers_metadata;

   WHEN("We set metadata:: precision "
         "for real types individually") {
      metadata::doubles << std::setprecision(7);
      metadata::floats  << std::setprecision(5);
      metadata::quads   << std::setprecision(9);
      THEN("The metadata print as expected") {
         std::ostringstream oss;
         oss << XML(Node(precision::Numbers(node)));
         CHECK(oss.str() == xml_metadata_individual);
      }
   }

   WHEN("We set metadata:: precision "
         "for real types in general") {
      metadata::reals << std::setprecision(3);
      THEN("The metadata print as expected") {
         std::ostringstream oss;
         oss << XML(Node(precision::Numbers(node)));
         CHECK(oss.str() == xml_metadata_real);
      }
   }

   WHEN("We set GNDStk:: (metadata+data) precision "
         "for real types individually") {
      njoy::GNDStk::doubles << std::setprecision(8);
      njoy::GNDStk::floats  << std::setprecision(6);
      njoy::GNDStk::quads   << std::setprecision(10);
      THEN("The metadata print as expected") {
         std::ostringstream oss;
         oss << XML(Node(precision::Numbers(node)));
         CHECK(oss.str() == xml_gndstk_individual);
      }
   }

   WHEN("We set GNDStk:: (metadata+data) "
         "precision for real types in general") {
      njoy::GNDStk::reals << std::setprecision(4);
      THEN("The metadata print as expected") {
         std::ostringstream oss;
         oss << XML(Node(precision::Numbers(node)));
         CHECK(oss.str() == xml_gndstk_real);
      }
   }
} // SCENARIO



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Precision code in BlockData::get(), "
         "for reworking a data vector to have a different data type")
{
   // Context/action:
   //    data, read
   //    data, write
   // These actually happen in detail::element2element()

   using namespace precision::key::child;
   using quad = long double;

   const std::vector<std::string> svec = {{
      "1.41421356237309504880168872420969807856967187537695",
      "2.71828182845904523536028747135266249775724709369995",
      "3.14159265358979323846264338327950288419716939937510"
   }};

   // A default-constructed Numbers object.
   precision::Numbers num;

   // ------------------------
   // strings to floats
   // ------------------------

   WHEN("We rework a vector<string> into a vector<float>") {
      // Give it data, in the form of a vector<string>.
      num.reals() = svec;

      THEN("We get the expected result") {
         // Rework the vector<string> into a vector<float>.
         // Doing so uses Precision<PrecisionContext::data,float>{}.read(str)
         // in order to read from strings into floats. This is less interesting
         // than the opposite (writing strings *from* floats), which will use
         // settings like what we might give to std::setprecision(). But we do
         // want to test that this particular read-from-string gets correct
         // floating-point numbers.
         const precision::Reals &r = *num.reals();
         r.get<std::vector<float>>();
         CHECK(Approx(r.get<float>(0)) == 1.414213562373095049);
         CHECK(Approx(r.get<float>(1)) == 2.718281828459045235);
         CHECK(Approx(r.get<float>(2)) == 3.141592653589793238);
      }
   }

   // ------------------------
   // strings to doubles
   // ------------------------

   WHEN("We rework a vector<string> into a vector<double>") {
      num.reals() = svec;
      THEN("We get the expected result") {
         const precision::Reals &r = *num.reals();
         r.get<std::vector<double>>();
         CHECK(Approx(r.get<double>(0)) == 1.414213562373095049);
         CHECK(Approx(r.get<double>(1)) == 2.718281828459045235);
         CHECK(Approx(r.get<double>(2)) == 3.141592653589793238);
      }
   }

   // ------------------------
   // strings to quads
   // ------------------------

   WHEN("We rework a vector<string> into a vector<long double>") {
      num.reals() = svec;
      THEN("We get the expected result") {
         const precision::Reals &r = *num.reals();
         r.get<std::vector<long double>>();
         CHECK(Approx(r.get<quad>(0)) == 1.414213562373095049);
         CHECK(Approx(r.get<quad>(1)) == 2.718281828459045235);
         CHECK(Approx(r.get<quad>(2)) == 3.141592653589793238);
      }
   }

   // ------------------------
   // floats to strings
   // ------------------------

   WHEN("We rework a vector<float> into a vector<string>") {
      const std::vector<float> fvec = {{
         static_cast<float>(std::sqrt(double(2))),
         static_cast<float>(std::sqrt(double(3))),
         static_cast<float>(std::sqrt(double(5)))
      }};

      using precision::key::child::reals;

      THEN("data::floats precision has the intended effect") {
         num.reals() = fvec;
         data::floats << std::setprecision(4);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "1.414 1.732 2.236");
      }

      THEN("data::reals precision has the intended effect") {
         num.reals() = fvec;
         data::reals << std::setprecision(5);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "1.4142 1.7321 2.2361");
      }

      THEN("GNDStk::floats precision has the intended effect") {
         num.reals() = fvec;
         njoy::GNDStk::floats << std::setprecision(6);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "1.41421 1.73205 2.23607");
      }

      THEN("GNDStk::reals precision has the intended effect") {
         num.reals() = fvec;
         njoy::GNDStk::reals << std::setprecision(7);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "1.414214 1.732051 2.236068");
      }
   } // WHEN

   // ------------------------
   // doubles to strings
   // ------------------------

   WHEN("We rework a vector<double> into a vector<string>") {
      const std::vector<double> dvec = {{
         std::sqrt(double(7)),
         std::sqrt(double(11)),
         std::sqrt(double(13))
      }};

      using precision::key::child::reals;

      THEN("data::doubles precision has the intended effect") {
         num.reals() = dvec;
         data::doubles << std::setprecision(4);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "2.646 3.317 3.606");
      }

      THEN("data::reals precision has the intended effect") {
         num.reals() = dvec;
         data::reals << std::setprecision(5);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "2.6458 3.3166 3.6056");
      }

      THEN("GNDStk::doubles precision has the intended effect") {
         num.reals() = dvec;
         njoy::GNDStk::doubles << std::setprecision(6);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "2.64575 3.31662 3.60555");
      }

      THEN("GNDStk::reals precision has the intended effect") {
         num.reals() = dvec;
         njoy::GNDStk::reals << std::setprecision(7);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "2.645751 3.316625 3.605551");
      }
   } // WHEN

   // ------------------------
   // quads to strings
   // ------------------------

   WHEN("We rework a vector<long double> into a vector<string>") {
      const std::vector<quad> qvec = {{
         std::sqrt(quad(17)),
         std::sqrt(quad(19)),
         std::sqrt(quad(23))
      }};

      using precision::key::child::reals;

      THEN("data::longdoubles precision has the intended effect") {
         num.reals() = qvec;
         data::longdoubles << std::setprecision(4);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "4.123 4.359 4.796");
      }

      THEN("data::reals precision has the intended effect") {
         num.reals() = qvec;
         data::reals << std::setprecision(5);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "4.1231 4.3589 4.7958");
      }

      THEN("GNDStk::longdoubles precision has the intended effect") {
         num.reals() = qvec;
         njoy::GNDStk::longdoubles << std::setprecision(6);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "4.12311 4.3589 4.79583");
      }

      THEN("GNDStk::reals precision has the intended effect") {
         num.reals() = qvec;
         njoy::GNDStk::reals << std::setprecision(7);
         num.reals()->get<std::vector<std::string>>();
         CHECK((Node(num))(reals).pcdata() == "4.123106 4.358899 4.795832");
      }
   } // WHEN
} // SCENARIO



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Precision code in BlockData::get(), "
         "for converting from a raw string to a vector of data")
{
   // Context/action:
   //    data, read

   const std::string string =
      "1.41421356237309504880168872420969807856967187537695 "
      "2.71828182845904523536028747135266249775724709369995 "
      "3.14159265358979323846264338327950288419716939937510";
   using quad = long double;
   precision::Reals r;

   // ------------------------
   // raw string to floats
   // ------------------------

   WHEN("We convert a raw \"block data\" string to a vector<float>") {
      // Initialize the raw string
      r = string;

      THEN("We get the expected result") {
         // This uses Precision<PrecisionContext::data,float>{}.read(string).
         // It's a read (to produce floats from string values), not a write,
         // so isn't interesting precision-wise, but it needs testing.
         r.get<std::vector<float>>();
         CHECK(Approx(r.get<float>(0)) == 1.414213562373095049);
         CHECK(Approx(r.get<float>(1)) == 2.718281828459045235);
         CHECK(Approx(r.get<float>(2)) == 3.141592653589793238);
      }
   }

   // ------------------------
   // raw string to doubles
   // ------------------------

   WHEN("We convert a raw \"block data\" string to a vector<double>") {
      r = string;
      THEN("We get the expected result") {
         r.get<std::vector<double>>();
         CHECK(Approx(r.get<double>(0)) == 1.414213562373095049);
         CHECK(Approx(r.get<double>(1)) == 2.718281828459045235);
         CHECK(Approx(r.get<double>(2)) == 3.141592653589793238);
      }
   }

   // ------------------------
   // raw string to long doubles
   // ------------------------

   WHEN("We convert a raw \"block data\" string to a vector<long double>") {
      r = string;
      THEN("We get the expected result") {
         r.get<std::vector<quad>>();
         CHECK(Approx(r.get<quad>(0)) == 1.414213562373095049);
         CHECK(Approx(r.get<quad>(1)) == 2.718281828459045235);
         CHECK(Approx(r.get<quad>(2)) == 3.141592653589793238);
      }
   }
} // SCENARIO



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Precision code in BlockData::toNode(), "
         "for writing... <name>VALUES THAT ARE TO GO HERE</name>")
{
   // Context/action:
   //    data, write

   using namespace precision::key::child;
   using quad = long double;

   const std::vector<std::string> svec = {{
      "1.41421356237309504880168872420969807856967187537695",
      "2.71828182845904523536028747135266249775724709369995",
      "3.14159265358979323846264338327950288419716939937510"
   }};

   precision::Reals r;

   // ------------------------
   // floats
   // ------------------------

   WHEN("We print floats>") {
      const std::vector<float> fvec = {{
         static_cast<float>(std::sqrt(double(2))),
         static_cast<float>(std::sqrt(double(3))),
         static_cast<float>(std::sqrt(double(5)))
      }};

      THEN("data::floats precision has the intended effect") {
         r = fvec;
         data::floats << std::setprecision(4);
         CHECK((Node(r)).pcdata() == "1.414 1.732 2.236");
      }

      THEN("data::reals precision has the intended effect") {
         r = fvec;
         data::reals << std::setprecision(5);
         CHECK((Node(r)).pcdata() == "1.4142 1.7321 2.2361");
      }

      THEN("GNDStk::floats precision has the intended effect") {
         r = fvec;
         njoy::GNDStk::floats << std::setprecision(6);
         CHECK((Node(r)).pcdata() == "1.41421 1.73205 2.23607");
      }

      THEN("GNDStk::reals precision has the intended effect") {
         r = fvec;
         njoy::GNDStk::reals << std::setprecision(7);
         CHECK((Node(r)).pcdata() == "1.414214 1.732051 2.236068");
      }
   } // WHEN

   // ------------------------
   // doubles
   // ------------------------

   WHEN("We print doubles") {
      const std::vector<double> dvec = {{
         std::sqrt(double(7)),
         std::sqrt(double(11)),
         std::sqrt(double(13))
      }};

      THEN("data::doubles precision has the intended effect") {
         r = dvec;
         data::doubles << std::setprecision(4);
         CHECK((Node(r)).pcdata() == "2.646 3.317 3.606");
      }

      THEN("data::reals precision has the intended effect") {
         r = dvec;
         data::reals << std::setprecision(5);
         CHECK((Node(r)).pcdata() == "2.6458 3.3166 3.6056");
      }

      THEN("GNDStk::doubles precision has the intended effect") {
         r = dvec;
         njoy::GNDStk::doubles << std::setprecision(6);
         CHECK((Node(r)).pcdata() == "2.64575 3.31662 3.60555");
      }

      THEN("GNDStk::reals precision has the intended effect") {
         r = dvec;
         njoy::GNDStk::reals << std::setprecision(7);
         CHECK((Node(r)).pcdata() == "2.645751 3.316625 3.605551");
      }
   } // WHEN

   // ------------------------
   // quads
   // ------------------------

   WHEN("We print long doubles") {
      const std::vector<quad> qvec = {{
         std::sqrt(quad(17)),
         std::sqrt(quad(19)),
         std::sqrt(quad(23))
      }};

      THEN("data::longdoubles precision has the intended effect") {
         r = qvec;
         data::longdoubles << std::setprecision(4);
         CHECK((Node(r)).pcdata() == "4.123 4.359 4.796");
      }

      THEN("data::reals precision has the intended effect") {
         r = qvec;
         data::reals << std::setprecision(5);
         CHECK((Node(r)).pcdata() == "4.1231 4.3589 4.7958");
      }

      THEN("GNDStk::longdoubles precision has the intended effect") {
         r = qvec;
         njoy::GNDStk::longdoubles << std::setprecision(6);
         CHECK((Node(r)).pcdata() == "4.12311 4.3589 4.79583");
      }

      THEN("GNDStk::reals precision has the intended effect") {
         r = qvec;
         njoy::GNDStk::reals << std::setprecision(7);
         CHECK((Node(r)).pcdata() == "4.123106 4.358899 4.795832");
      }
   } // WHEN
} // SCENARIO



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

// ------------------------
// Some expected results
// ------------------------

const std::string printed_metadata_individual =
R"***(precision::Numbers {
   adouble : 1.414214
   afloat  : 1.7321
   aquad   : 2.23606798
   bdouble : 2.44949
   bfloat  : 2.6458
   bquad   : 2.82842712
   doubles : // optional; has no value
   floats  : // optional; has no value
   quads   : // optional; has no value
   reals   : // optional; has no value
} // precision::Numbers
)***";

const std::string printed_metadata_real =
R"***(precision::Numbers {
   adouble : 1.41
   afloat  : 1.73
   aquad   : 2.24
   bdouble : 2.45
   bfloat  : 2.65
   bquad   : 2.83
   doubles : // optional; has no value
   floats  : // optional; has no value
   quads   : // optional; has no value
   reals   : // optional; has no value
} // precision::Numbers
)***";

const std::string printed_gndstk_individual =
R"***(precision::Numbers {
   adouble : 1.4142136
   afloat  : 1.73205
   aquad   : 2.236067977
   bdouble : 2.4494897
   bfloat  : 2.64575
   bquad   : 2.828427125
   doubles : // optional; has no value
   floats  : // optional; has no value
   quads   : // optional; has no value
   reals   : // optional; has no value
} // precision::Numbers
)***";

const std::string printed_gndstk_real =
R"***(precision::Numbers {
   adouble : 1.414
   afloat  : 1.732
   aquad   : 2.236
   bdouble : 2.449
   bfloat  : 2.646
   bquad   : 2.828
   doubles : // optional; has no value
   floats  : // optional; has no value
   quads   : // optional; has no value
   reals   : // optional; has no value
} // precision::Numbers
)***";


// ------------------------
// SCENARIO
// ------------------------

SCENARIO("Precision code in Component::write(), "
         "for writing a metadatum with write()'s prettyprinter")
{
   // Context/action:
   //    metadata, write

   Node node;
   node << input_numbers_metadata;

   WHEN("We set metadata:: precision "
         "for real types individually") {
      metadata::doubles << std::setprecision(7);
      metadata::floats  << std::setprecision(5);
      metadata::quads   << std::setprecision(9);
      THEN("The metadata print as expected") {
         std::ostringstream oss;
         oss << precision::Numbers(node) << std::endl;
         CHECK(oss.str() == printed_metadata_individual);
      }
   }

   WHEN("We set metadata:: precision "
         "for real types in general") {
      metadata::reals << std::setprecision(3);
      THEN("The metadata print as expected") {
         std::ostringstream oss;
         oss << precision::Numbers(node) << std::endl;
         CHECK(oss.str() == printed_metadata_real);
      }
   }

   WHEN("We set GNDStk:: (metadata+data) precision "
         "for real types individually") {
      njoy::GNDStk::doubles << std::setprecision(8);
      njoy::GNDStk::floats  << std::setprecision(6);
      njoy::GNDStk::quads   << std::setprecision(10);
      THEN("The metadata print as expected") {
         std::ostringstream oss;
         oss << precision::Numbers(node) << std::endl;
         CHECK(oss.str() == printed_gndstk_individual);
      }
   }

   WHEN("We set GNDStk:: (metadata+data) "
         "precision for real types in general") {
      njoy::GNDStk::reals << std::setprecision(4);
      THEN("The metadata print as expected") {
         std::ostringstream oss;
         oss << precision::Numbers(node) << std::endl;
         CHECK(oss.str() == printed_gndstk_real);
      }
   }
} // SCENARIO



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

// ------------------------
// Input string for
// this scenario
// ------------------------

const std::string input_numbers_full =
R"***(
<numbers>
   <floats>
      8.4018771715470949058846
      3.94382926819093025672114
      7.83099223758605878691411
      7.98440033476073310466856
      9.11647357936784326088581
      1.97551369293383960283605
   </floats>
   <doubles>
      3.35222755714889036372794
      7.68229594811904055451368
      2.77774710803187783255026
      5.53969955795430557717041
      4.7739705186216023374314
      6.28870924761924391960949
   </doubles>
   <quads>
      3.64784472791843336451911
      5.13400910195615566445487
      9.52229725174712820535972
      9.16195068003700612089407
      6.35711727959900967750359
      7.17296929432683125823361
   </quads>
</numbers>
)***";


// ------------------------
// Some expected results
// ------------------------

const std::string block_data_individual =
R"***(precision::Numbers {
   adouble : // defaulted; is its default (1.414)
   afloat  : // defaulted; is its default (1.732)
   aquad   : // defaulted; is its default (2.236)
   bdouble : // defaulted; is its default (2.449)
   bfloat  : // defaulted; is its default (2.646)
   bquad   : // defaulted; is its default (2.828)
   precision::Doubles {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      3.352228 7.682296 2.777747 5.5397
      4.773971 6.288709
   } // precision::Doubles
   precision::Floats {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      8.4019 3.9438 7.831 7.9844
      9.1165 1.9755
   } // precision::Floats
   precision::Quads {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      3.64784473 5.1340091 9.52229725 9.16195068
      6.35711728 7.17296929
   } // precision::Quads
   reals   : // optional; has no value
} // precision::Numbers
)***";

const std::string block_data_real =
R"***(precision::Numbers {
   adouble : // defaulted; is its default (1.414)
   afloat  : // defaulted; is its default (1.732)
   aquad   : // defaulted; is its default (2.236)
   bdouble : // defaulted; is its default (2.449)
   bfloat  : // defaulted; is its default (2.646)
   bquad   : // defaulted; is its default (2.828)
   precision::Doubles {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      3.35 7.68 2.78 5.54
      4.77 6.29
   } // precision::Doubles
   precision::Floats {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      8.4 3.94 7.83 7.98
      9.12 1.98
   } // precision::Floats
   precision::Quads {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      3.65 5.13 9.52 9.16
      6.36 7.17
   } // precision::Quads
   reals   : // optional; has no value
} // precision::Numbers
)***";

const std::string block_gndstk_individual =
R"***(precision::Numbers {
   adouble : // defaulted; is its default (1.4142136)
   afloat  : // defaulted; is its default (1.73205)
   aquad   : // defaulted; is its default (2.236067977)
   bdouble : // defaulted; is its default (2.4494897)
   bfloat  : // defaulted; is its default (2.64575)
   bquad   : // defaulted; is its default (2.828427125)
   precision::Doubles {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      3.3522276 7.6822959 2.7777471 5.5396996
      4.7739705 6.2887092
   } // precision::Doubles
   precision::Floats {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      8.40188 3.94383 7.83099 7.9844
      9.11647 1.97551
   } // precision::Floats
   precision::Quads {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      3.647844728 5.134009102 9.522297252 9.16195068
      6.35711728 7.172969294
   } // precision::Quads
   reals   : // optional; has no value
} // precision::Numbers
)***";

const std::string block_gndstk_real =
R"***(precision::Numbers {
   adouble : // defaulted; is its default (1.414)
   afloat  : // defaulted; is its default (1.732)
   aquad   : // defaulted; is its default (2.236)
   bdouble : // defaulted; is its default (2.449)
   bfloat  : // defaulted; is its default (2.646)
   bquad   : // defaulted; is its default (2.828)
   precision::Doubles {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      3.352 7.682 2.778 5.54
      4.774 6.289
   } // precision::Doubles
   precision::Floats {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      8.402 3.944 7.831 7.984
      9.116 1.976
   } // precision::Floats
   precision::Quads {
      length    : // optional; has no value
      start     : // defaulted; is its default (0)
      valueType : // optional; has no value
      3.648 5.134 9.522 9.162
      6.357 7.173
   } // precision::Quads
   reals   : // optional; has no value
} // precision::Numbers
)***";


// ------------------------
// SCENARIO
// ------------------------

SCENARIO("Precision code in BlockData::write(), "
         "for writing data blocks with Component::write()'s prettyprinter")
{
   // Context/action:
   //    data, write
   // This actually happens in detail::writeComponentPart()

   Node node;
   node << input_numbers_full;
   const precision::Numbers num(node);

   std::cout << num << std::endl;

   WHEN("We set data:: precision "
         "for real types individually") {
      data::doubles << std::setprecision(7);
      data::floats  << std::setprecision(5);
      data::quads   << std::setprecision(9);
      THEN("The data blocks print as expected") {
         std::ostringstream oss;
         oss << num << std::endl;
         CHECK(oss.str() == block_data_individual);
      }
   }

   WHEN("We set data:: precision "
         "for real types in general") {
      data::reals << std::setprecision(3);
      THEN("The data blocks print as expected") {
         std::ostringstream oss;
         oss << num << std::endl;
         CHECK(oss.str() == block_data_real);
      }
   }

   WHEN("We set GNDStk:: (metadata+data) precision "
         "for real types individually") {
      njoy::GNDStk::doubles << std::setprecision(8);
      njoy::GNDStk::floats  << std::setprecision(6);
      njoy::GNDStk::quads   << std::setprecision(10);
      THEN("The data blocks print as expected") {
         std::ostringstream oss;
         oss << num << std::endl;
         CHECK(oss.str() == block_gndstk_individual);
      }
   }

   WHEN("We set GNDStk:: (metadata+data) "
         "precision for real types in general") {
      njoy::GNDStk::reals << std::setprecision(4);
      THEN("The data blocks print as expected") {
         std::ostringstream oss;
         oss << num << std::endl;
         CHECK(oss.str() == block_gndstk_real);
      }
   }
} // SCENARIO
