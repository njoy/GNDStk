
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

      CHECK( tree(sversion   ) == "1.0"   );
      CHECK( tree(dversion   ) ==  1.0    );
      CHECK( tree(sencoding  ) == "UTF-8" );
      CHECK( tree(sprojectile) == "n"     );
      CHECK( tree(cprojectile) == 'n'     );
      CHECK( tree(vtarget    ) == "O16"   );
      CHECK( tree(sevaluation) == "ENDF/B-8.0" );
      CHECK( tree(sformat    ) == "1.9"   );
      CHECK( tree(dformat    ) ==  1.9    );
      CHECK( tree(sframe     ) == "lab"   );

      // found
      found = false; CHECK( (tree(dversion,found),  found) );
      found = true;  CHECK( (tree(foo,     found), !found) );


      // ------------------------
      // operator()(child_t)
      // ------------------------

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


      // ------------------------
      // operator()(child_t, meta_t)
      // ------------------------

      CHECK( tree( reactionSuite, projectile      ) == "n"          );
      CHECK( tree( reactionSuite, target          ) == "O16"        );
      CHECK( tree( reactionSuite, evaluation      ) == "ENDF/B-8.0" );
      CHECK( tree( reactionSuite, meta::format    ) ==  1.9         );
      CHECK( tree( reactionSuite, projectileFrame ) == "lab"        );

      // found
      found = false;
      CHECK((tree(reactionSuite,projectile,found) == "n" && found));
      found = true;
      CHECK((tree(reactionSuite,foo,found), !found));


      // ------------------------
      // operator()(child_t, child_t)
      // ------------------------

      CHECK( tree( reactionSuite, styles ).metadata.size() == 0);
      CHECK( tree( reactionSuite, styles ).children.size() == 1);
      CHECK( tree( reactionSuite, PoPs   ).metadata.size() == 3);
      CHECK( tree( reactionSuite, PoPs   ).children.size() == 3);

      // found
      found = false;
      CHECK((tree(reactionSuite,styles,found), found));
      found = true;
      CHECK((tree(reactionSuite,bar,found), !found));


      // ------------------------
      // operator()(child_t, ...)
      // ------------------------

      // dvalue = double version of "value" metadatum
      CHECK(tree(reactionSuite,styles,evaluated,temperature,dvalue) == 0.0);
      CHECK(tree(reactionSuite,styles,evaluated,temperature,unit  ) == "K");

      // GNDStk::child::reaction has FIND == find::all, so the following
      // gives us back a container (std::vector by default).
      found = false;
      auto vec = tree(reactionSuite,reactions,reaction,found);
      CHECK(found);
      CHECK(vec.size() == 60);

      // At present, need to split and use child() (...) in
      // order to <direct-specify> an output container type
      found = false;
      auto dq = tree(reactionSuite,reactions).child<std::deque>(reaction,found);
      CHECK(found);
      CHECK(dq.size() == 60);

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
      CHECK(
         tree
          (reactionSuite, reactions, reaction)[0]
          (crossSection,XYs1d)[0] // fixme Double-check find::all for XYs1d
          (axes,axis).size() == 2
      );
   }
}
