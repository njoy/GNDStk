
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace GNDStk;
using namespace GNDStk::meta;
using namespace GNDStk::child;



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
inline void node2type(const NODE &node, xml_t &out)
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
inline void node2type(const NODE &node, reactionSuite_t &out)
{
   out.projectile = node.meta(projectile);
   out.target     = node.meta(target);
   out.evaluation = node.meta(evaluation);
   out.format     = node.meta(meta::format);
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

      /*
      // non: a non-const tree
      Tree<> non = tree;
      */

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

      REQUIRE( tree(sversion   ) == "1.0"   );
      REQUIRE( tree(dversion   ) ==  1.0    );
      REQUIRE( tree(sencoding  ) == "UTF-8" );
      REQUIRE( tree(sprojectile) == "n"     );
      REQUIRE( tree(cprojectile) == 'n'     );
      REQUIRE( tree(vtarget    ) == "O16"   );
      REQUIRE( tree(sevaluation) == "ENDF/B-8.0" );
      REQUIRE( tree(sformat    ) == "1.9"   );
      REQUIRE( tree(dformat    ) ==  1.9    );
      REQUIRE( tree(sframe     ) == "lab"   );

      // found
      found = false; REQUIRE( (tree(dversion,found),  found) );
      found = true;  REQUIRE( (tree(foo,     found), !found) );


      // ------------------------
      // operator()(child_t)
      // ------------------------

      auto x = tree(::xml);
      REQUIRE(x.version == 1.0);
      REQUIRE(x.encoding == "UTF-8");

      auto r = tree(::rsuite);
      REQUIRE(r.projectile == "n");
      REQUIRE(r.target     == "O16");
      REQUIRE(r.evaluation == "ENDF/B-8.0");
      REQUIRE(r.format     ==  1.9);
      REQUIRE(r.frame      == "lab");

      // found
      found = false; REQUIRE( (tree(::rsuite,found), found) );
      found = true;  REQUIRE( (tree(bar,found), !found) );


      // ------------------------
      // operator()(child_t, meta_t)
      // ------------------------

      REQUIRE( tree( reactionSuite, projectile      ) == "n"          );
      REQUIRE( tree( reactionSuite, target          ) == "O16"        );
      REQUIRE( tree( reactionSuite, evaluation      ) == "ENDF/B-8.0" );
      REQUIRE( tree( reactionSuite, meta::format    ) ==  1.9         );
      REQUIRE( tree( reactionSuite, projectileFrame ) == "lab"        );

      // found
      found = false;
      REQUIRE((tree(reactionSuite,projectile,found) == "n", found));
      found = true;
      REQUIRE((tree(reactionSuite,foo,found), !found));


      // ------------------------
      // operator()(child_t, child_t)
      // ------------------------

      REQUIRE( tree( reactionSuite, styles ).metadata.size() == 0);
      REQUIRE( tree( reactionSuite, styles ).children.size() == 1);
      REQUIRE( tree( reactionSuite, PoPs   ).metadata.size() == 3);
      REQUIRE( tree( reactionSuite, PoPs   ).children.size() == 3);

      // found
      found = false;
      REQUIRE((tree(reactionSuite,styles,found), found));
      found = true;
      REQUIRE((tree(reactionSuite,bar,found), !found));


      // ------------------------
      // operator()(child_t, ...)
      // ------------------------

      // dvalue = double version of "value" metadatum
      REQUIRE(tree(reactionSuite,styles,evaluated,temperature,dvalue) == 0.0);
      REQUIRE(tree(reactionSuite,styles,evaluated,temperature,unit  ) == "K");

      // GNDStk::child::reaction has MULTIPLE == true, so the following
      // gives us back a container (std::vector by default).
      found = false;
      auto vec = tree(reactionSuite,reactions,reaction,found);
      REQUIRE(found);
      REQUIRE(vec.size() == 60);

      // At present, need to split and use child() (...) in
      // order to <direct-specify> an output container type
      found = false;
      auto dq = tree(reactionSuite,reactions).child<std::deque>(reaction,found);
      REQUIRE(found);
      REQUIRE(dq.size() == 60);

      /*
      Relevant section of the .xml:
      ...
      <reactions>
        <reaction label="n + O16" ENDF_MT="2">
          <crossSection>
            <XYs1d label="eval">
              <axes>
                <axis index="1" label="energy_in" unit="eV"/>
                <axis index="0" label="crossSection" unit="b"/>
              </axes>
      */
      REQUIRE(
         tree
          (reactionSuite, reactions, reaction)[0]
          (crossSection,XYs1d)[0] // fixme Double-check multiple==true for XYs1d
          (axes,axis).size() == 2
      );
   }
}
