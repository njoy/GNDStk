
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

inline const child_t<xml_t> xml("xml");


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

inline const child_t<reactionSuite_t> rsuite("reactionSuite");


// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk tree operator()") {

   GIVEN("A tree read from n-008_O_016.xml") {
      // tree: a const tree
      const Tree<> tree("n-008_O_016.xml");

      // optional return flag
      bool found;

      // nonsense meta_t and child_t
      const meta_t <void> foo("bar");
      const child_t<void> bar("foo");


      // ------------------------
      // operator()(meta_t)
      // ------------------------

      const meta_t<std::string> sversion   ("version");
      const meta_t<double     > dversion   ("version");
      const meta_t<std::string> sencoding  ("encoding");
      const meta_t<std::string> sprojectile("projectile");
      const meta_t<char       > cprojectile("projectile");
      const meta_t<void       > vtarget    ("target");
      const meta_t<std::string> sevaluation("evaluation");
      const meta_t<std::string> sformat    ("format");
      const meta_t<double     > dformat    ("format");
      const meta_t<std::string> sframe     ("projectileFrame");

      WHEN("We call tree operator() with (child_t,meta_t)") {
         CHECK( tree(::xml,sversion   ) == "1.0"   );
         CHECK( tree(::xml,dversion   ) ==  1.0    );
         CHECK( tree(::xml,sencoding  ) == "UTF-8" );
         CHECK( tree(reactionSuite,sprojectile) == "n"     );
         CHECK( tree(reactionSuite,cprojectile) == 'n'     );
         CHECK( tree(reactionSuite,vtarget    ) == "O16"   );
         CHECK( tree(reactionSuite,sevaluation) == "ENDF/B-8.0" );
         CHECK( tree(reactionSuite,sformat    ) == "1.9"   );
         CHECK( tree(reactionSuite,dformat    ) ==  1.9    );
         CHECK( tree(reactionSuite,sframe     ) == "lab"   );

         // found
         found = false; CHECK( (tree(::xml,dversion,found),  found) );
         found = true;  CHECK( (tree(::xml,foo,     found), !found) );
      }


      // ------------------------
      // operator()(child_t)
      // ------------------------

      WHEN("We call tree operator() with (child_t)") {
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
      // operator()(child_t, meta_t)
      // ------------------------

      WHEN("We call tree operator() with (child_t,meta_t)") {
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
      // operator()(child_t, child_t)
      // ------------------------

      WHEN("We call tree operator() with (child_t,child_t)") {
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
      // operator()(child_t, ...)
      // ------------------------

      WHEN("We call tree operator() with (child_t,...) (various ...s)") {
         // dvalue = double version of "value" metadatum
         CHECK(tree(reactionSuite,styles,evaluated,temperature,dvalue) == 0.0);
         CHECK(tree(reactionSuite,styles,evaluated,temperature,unit  ) == "K");

         // child::reaction has ALLOW == allow::many, so the following
         // gives us back a container (std::vector by default).
         found = false;
         auto vec = tree(reactionSuite,reactions,reaction,found);
         CHECK(found);
         CHECK(vec.size() == 60);

         // At present, need to split and use child() (...) in
         // order to <direct-specify> an output container type
         found = false;
         auto dq =
            tree(reactionSuite,reactions).
            child<std::deque>(reaction,found);
         CHECK(found);
         CHECK(dq.size() == 60);

         CHECK(
            tree
            (reactionSuite, reactions, reaction)[0]
            (crossSection,XYs1d)[0]
            (axes,axis).size() == 2
         );
      }
   }
}
