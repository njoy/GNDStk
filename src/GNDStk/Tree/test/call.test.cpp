
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;
using namespace misc;


// -----------------------------------------------------------------------------
// For some keyword tests
// -----------------------------------------------------------------------------

// ------------------------
// xml_t
// ------------------------

class xml_t {
public:
   double version;
   std::string encoding;
};

template<class NODE>
inline void convert(const NODE &node, xml_t &out)
{
   out.version  = std::stod(node.meta(version));
   out.encoding = node.meta(encoding);
}

inline const Child<xml_t> xml("#xml");


// ------------------------
// reactionSuite_t
// ------------------------

class reactionSuite_t {
public:
   std::string projectile;
   std::string target;
   std::string evaluation;
   double      format;
   std::string frame;
};

template<class NODE>
inline void convert(const NODE &node, reactionSuite_t &out)
{
   out.projectile = node.meta(projectile);
   out.target     = node.meta(target);
   out.evaluation = node.meta(evaluation);
   out.format     = node.meta(format);
   out.frame      = node.meta(projectileFrame);
}

inline const Child<reactionSuite_t> rsuite("reactionSuite");


// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk Tree operator()") {

   GIVEN("A Tree read from n-008_O_016.xml") {
      // tree: a const Tree
      const Tree tree("n-008_O_016.xml");

      // optional return flag
      bool found;

      // nonsense Meta and Child
      const Meta <void> foo("bar");
      const Child<void> bar("foo");


      // ------------------------
      // operator()(Meta)
      // ------------------------

      const Meta<std::string> sversion   ("version");
      const Meta<double     > dversion   ("version");
      const Meta<std::string> sencoding  ("encoding");
      const Meta<std::string> sprojectile("projectile");
      const Meta<char       > cprojectile("projectile");
      const Meta<void       > vtarget    ("target");
      const Meta<std::string> sevaluation("evaluation");
      const Meta<std::string> sformat    ("format");
      const Meta<double     > dformat    ("format");
      const Meta<std::string> sframe     ("projectileFrame");

      WHEN("We call Tree operator() with (Child,Meta)") {
         CHECK( (tree(::xml,sversion ) == "1.0"   ) );
         CHECK( (tree(::xml,dversion ) ==  1.0    ) );
         CHECK( (tree(::xml,sencoding) == "UTF-8" ) );

         CHECK( (tree(reactionSuite,sprojectile) == "n"     ) );
         CHECK( (tree(reactionSuite,cprojectile) == 'n'     ) );
         CHECK( (tree(reactionSuite,vtarget    ) == "O16"   ) );
         CHECK( (tree(reactionSuite,sevaluation) == "ENDF/B-8.0" ) );
         CHECK( (tree(reactionSuite,sformat    ) == "1.9"   ) );
         CHECK( (tree(reactionSuite,dformat    ) ==  1.9    ) );
         CHECK( (tree(reactionSuite,sframe     ) == "lab"   ) );

         // found
         found = false; CHECK( (tree(::xml,dversion,found),  found) );
         found = true;  CHECK( (tree(::xml,foo,     found), !found) );
      }


      // ------------------------
      // operator()(Child)
      // ------------------------

      WHEN("We call tree operator() with (Child)") {
         auto x = tree(::xml);
         CHECK(x.version == 1.0);
         CHECK(x.encoding == "UTF-8");

         auto r = tree(::rsuite);
         CHECK(r.projectile == "n");
         CHECK(r.target     == "O16");
         CHECK(r.evaluation == "ENDF/B-8.0");
         CHECK(r.format     ==  1.9);
         CHECK(r.frame      == "lab");

         // found
         found = false; CHECK( (tree(::rsuite,found), found) );
         found = true;  CHECK( (tree(bar,found), !found) );
      }


      // ------------------------
      // operator()(Child, Meta)
      // ------------------------

      WHEN("We call tree operator() with (Child,Meta)") {
         CHECK( tree( reactionSuite, projectile) == "n");
         CHECK( tree( reactionSuite, target) == "O16");
         CHECK( tree( reactionSuite, evaluation) == "ENDF/B-8.0");
         CHECK( tree( reactionSuite, format) ==  1.9);
         CHECK( tree( reactionSuite, projectileFrame) == "lab");

         // found
         found = false;
         CHECK((tree(reactionSuite,projectile,found) == "n" && found));
         found = true;
         CHECK((tree(reactionSuite,foo,found), !found));
      }


      // ------------------------
      // operator()(Child, Child)
      // ------------------------

      WHEN("We call tree operator() with (Child,Child)") {
         CHECK( tree( reactionSuite, styles ).metadata.size() == 0);
         CHECK( tree( reactionSuite, styles ).children.size() == 1);
         CHECK( tree( reactionSuite, PoPs   ).metadata.size() == 3);
         CHECK( tree( reactionSuite, PoPs   ).children.size() == 3);

         // found
         found = false;
         CHECK((tree(reactionSuite,styles,found), found));
         found = true;
         CHECK((tree(reactionSuite,bar,found), !found));
      }


      // ------------------------
      // operator()(Child, ...)
      // ------------------------

      WHEN("We call tree operator() with (Child,...) (various ...s)") {
         // dvalue = double version of "value" metadatum
         CHECK(tree(reactionSuite,styles,--evaluated,temperature,dvalue)
               == 0.0);
         CHECK(tree(reactionSuite,styles,--evaluated,temperature,unit  )
               == "K");

         // child::reaction has ALLOW == Allow::many, so the following
         // gives us back a container (std::vector by default).
         found = false;
         auto vec = tree(reactionSuite,reactions,reaction,found);
         CHECK(found);
         CHECK(vec.size() == 60);

         // At present, need to split and use child() (...) in
         // order to <direct-specify> an output container type
         found = false;
         auto deq =
            tree(reactionSuite,reactions).
            child<std::deque>(reaction,found);
         CHECK(found);
         CHECK(deq.size() == 60);

         CHECK(
            tree
            (reactionSuite, reactions, reaction)[0]
            (crossSection,XYs1d)[0]
            (axes,axis).size() == 2
         );
      } // WHEN
   }
}
