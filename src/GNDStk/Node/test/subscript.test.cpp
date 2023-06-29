
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

#include "GNDStk/test/keys.hpp"
using namespace basic;


// -----------------------------------------------------------------------------
// Custom types
// -----------------------------------------------------------------------------

// Really? major and minor are #defined in some system header??
#undef major
#undef minor


// ------------------------
// version_t
// used with Meta
// ------------------------

struct version_t {
   int major = -1;
   int minor = -1;
   int patch = -1;
   version_t() { }
   version_t(const int a, const int b, const int c) :
      major(a), minor(b), patch(c)
   { }
};

// FYI reminder for readers: for conversion from/to metadata value strings,
// GNDStk's series of defaults for its convert() "free functions" eventually
// make it to the C++ I/O operators, if nothing else is provided. (Naturally,
// istringstream and ostringstream are involved, between the metadata value
// strings and the istream and ostream as below.) Programmers, and/or end
// users of GNDStk, may find it more convenient to write stream I/O as we
// do here - especially given that you may want those for your custom classes
// anyway. (But we don't just use those directly, in place of our convert(),
// because it's entirely possible that stream I/O writes or reads something
// in a different form from what the GNDStk metadata value needs. Especially
// if you've gotten a class with existing stream I/O from this or that random
// library with which you may be interfacing.)

// operator>>
// Reached by convert(const string &, your type &) if all else fails
inline std::istream &operator>>(std::istream &s, version_t &obj)
{
   char ch; // '.'
   return s >> obj.major >> ch >> obj.minor >> ch >> obj.patch;
}

// operator<<
// Reached by convert(const your type &, string &) if all else fails
inline std::ostream &operator<<(std::ostream &s, const version_t &obj)
{
   return s << obj.major << '.' << obj.minor << '.' << obj.patch;
}


// ------------------------
// temp_t
// used with Child
// ------------------------

struct temp_t {
   double value;
   std::string unit;
   temp_t() { }
   temp_t(const double value, const std::string &unit) :
      value(value), unit(unit)
   { }
};

namespace njoy {
namespace GNDStk {

inline void convert(const Node &n, temp_t &t)
{
   t.value = n(double{}/basic::value);
   t.unit  = n(basic::unit);
}

inline void convert(const temp_t &t, Node &n)
{
   assert(n.empty());
   n.name = "temperature";
   n.add(double{}/basic::value, t.value);
   n.add(basic::unit, t.unit);
}

}
}


// ------------------------
// axis_t
// used with Child
// ------------------------

struct axis_t {
   int index;
   std::string label;
   std::string unit;

   axis_t() { }

   axis_t(
      const int index,
      const std::string &label,
      const std::string &unit
   ) :
      index(index),
      label(label),
      unit(unit)
   { }
};

// operator==
// we use this in some of the tests
inline bool operator==(const axis_t &a, const axis_t &b)
{
   return
        a.index == b.index
     && a.label == b.label
     && a.unit  == b.unit;
}

// operator==
inline bool operator!=(const axis_t &a, const axis_t &b)
{
   return !(a == b);
}

namespace njoy {
namespace GNDStk {

// Node ==> axis_t
inline void convert(const Node &n, axis_t &a)
{
   a.index = n(int{}/basic::index);
   a.label = n(      basic::label);
   a.unit  = n(      basic::unit );
}

// axis_t ==> Node
inline void convert(const axis_t &a, Node &n)
{
   assert(n.empty());
   n.name = "axis";

   n.add(int{}/basic::index, a.index);
   n.add(      basic::label, a.label);
   n.add(      basic::unit,  a.unit );
}

}
}



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk Node operator[]") {
   Tree tree("n-008_O_016.xml");

   // const and non-const Node, for testing
   const Node &c = tree;
   Node &n = tree;

   GIVEN("const and non-const Nodes") {

      // ------------------------
      // [Meta<void>]
      // ------------------------

      // For Meta<void>, [] returns the same thing () does: a const
      // or non-const reference to the actual metadata value.

      WHEN("We call [Meta<void>]") {

         // ------------
         // CONST
         // ------------

         THEN("const works as expected") {
            CHECK(c(reactionSuite)[projectile] == "n");
            // returns a reference, so we can take the address
            (void)&c(reactionSuite)[projectile];
         }

         // ------------
         // NON-CONST
         // ------------

         THEN("non-const works as expected") {
            // as above
            CHECK(n(reactionSuite)[projectile] == "n");
            (void)&n(reactionSuite)[projectile];
            // and we can also assign
            n(reactionSuite)[projectile] = "foo";
            CHECK(n(reactionSuite,projectile) == "foo");
            n(reactionSuite)[projectile] = "n";
            CHECK(n(reactionSuite,projectile) == "n");
         }
      }


      // ------------------------
      // [Meta<TYPE>]
      // ------------------------

      WHEN("We call [Meta<TYPE>]") {

         // ------------
         // CONST
         // ------------
         THEN("const works as expected") {
            // v will be a detail::MetaRef<Node,CONST=true,version_t>,
            // where version_t is our custom type defined above
            auto v = c(reactionSuite,styles,--evaluated)
               [Meta<version_t>("version")];

            // for const, assignment isn't available; neither of these compile:
            // v = version_t(8,0,3);
            // v = "8.0.3";

            // v's type, as created by [] and described above, isn't just
            // an rvalue version_t as we'd have gotten from (). Instead, it's
            // something more intelligent. Here, we see that it can convert
            // (in the C++ sense, not in GNDStk's convert() sense) to either
            // a version_t or to a std::string. A return from (), not from []
            // as we had above, wouldn't have been able to do that.
            const version_t v_new = v; // v can become a version_t
            const std::string str = v; // v can become a std::string

            CHECK(v_new.major == 8);
            CHECK(v_new.minor == 0);
            CHECK(v_new.patch == 3);
            CHECK(str == "8.0.3");
         }

         // ------------
         // NON-CONST
         // ------------

         THEN("non-const works as expected") {
            // as for the const case, above, but assignment is now available
            auto v = n(reactionSuite,styles,--evaluated)
               [Meta<version_t>("version")];

            // Assignment is available now, because the above came from our
            // non-const Node. The following illustrates the real point of
            // using the [] operator: to get an lvalue:
            v = version_t(8,0,3);
            v = "8.0.3";

            // as before
            const version_t v_new = v; // v can become a version_t
            const std::string str = v; // v can become a std::string

            CHECK(v_new.major == 8);
            CHECK(v_new.minor == 0);
            CHECK(v_new.patch == 3);
            CHECK(str == "8.0.3");

            // Let's exercise [] obtained from a non-const Node, not so much
            // for the sake of more tests, but to illustrate []'s main purpose
            // as something that's usable (when applied to non-const Nodes
            // anyway) as an lvalue.

            auto &EvaluatedNode = n(reactionSuite,styles,--evaluated);
            const Meta<version_t> myversion("version");

            // Actually writes into the tree...
            EvaluatedNode[myversion] = "123.456.789";
            CHECK(tree(reactionSuite,styles,--evaluated,basic::version)
                  == "123.456.789");
            // can still use as rvalue, and implicitly converts to string...
            std::string foo = EvaluatedNode[myversion];
            CHECK(foo == "123.456.789");

            // Also actually writes into the tree...
            EvaluatedNode[myversion] = version_t(12,34,56);
            CHECK(tree(reactionSuite,styles,--evaluated,basic::version)
                  == "12.34.56");
            // can still use as rvalue, and implicitly converts to version_t...
            version_t bar = EvaluatedNode[myversion];
            CHECK(bar.major == 12);
            CHECK(bar.minor == 34);
            CHECK(bar.patch == 56);
         }
      }


      // ------------------------
      // [Child<void,one>]
      // ------------------------

      // For Child<void,one>, [] returns the same thing () does: a const
      // or non-const reference to the actual child node.

      WHEN("We call [Child<void,one>]") {

         // ------------
         // CONST
         // ------------

         THEN("const works as expected") {
            CHECK(c[reactionSuite].name == "reactionSuite");
            CHECK(c[reactionSuite].metadata.size() == 5);
            CHECK(c[reactionSuite].children.size() == 9);
            // returns a reference, so we can take the address
            (void)&c[reactionSuite];
         }

         // ------------
         // NON-CONST
         // ------------

         THEN("non-const works as expected") {
            // as above, and we can also assign
            CHECK(n[reactionSuite].name == "reactionSuite");
            CHECK(n[reactionSuite].metadata.size() == 5);
            CHECK(n[reactionSuite].children.size() == 9);
            (void)&n[reactionSuite];
            // try assigning name...
            n[reactionSuite].name = "REACTIONSUITE";
            // which of course leads to this sort of thing...
            CHECK(n.one("REACTIONSUITE").name == "REACTIONSUITE");
            n[Child<>("REACTIONSUITE")].name = "reactionSuite";
            // try assigning the Node itself...
            n[reactionSuite] = c[reactionSuite];
         }
      }


      // ------------------------
      // [Child<void,many>]
      // ------------------------

      /*
      Relevant parts of n-008_O_016.xml
      <reactionSuite>
       <reactions>
        <reaction label="n + O16">
         <outputChannel>
          <products>
           <product label="n">
            <distribution>
             <angularTwoBody label="eval">
              <regions2d>
               <axes>
                <axis index="2" label="energy_in"       unit="eV" />
                <axis index="1" label="mu"              unit=""   />
                <axis index="0" label="P(mu|energy_in)" unit=""   />
               </axes>
               ...
      */

      WHEN("We call [Child<void,many>]") {

         // ------------
         // CONST
         // ------------

         THEN("const works as expected") {
            const Node &axes = tree(
               reactionSuite,
               reactions,
               reaction, "n + O16",
               outputChannel,
               products,
               product, "n",
               distribution,
               angularTwoBody, "eval",
               regions2d,
               basic::axes
            );
            CHECK(axes.metadata.size() == 0);
            CHECK(axes.children.size() == 3);

            // auto gives a certain type of object that, under the hood,
            // encapsulates a vector of pointers to [const, in this case]
            // Nodes. The vector of pointers is (intentionally) unavailable
            // outside of the class. The key here is that the axis object
            // will be equipped with some capabilities that users should
            // find to be convenient, such as its own operator[] (not to
            // be confused with the one applied to axes in order to get
            // axis in the first place) that returns references to the
            // in-tree Nodes. We'll see this shortly.
            auto axis = axes[basic::axis]; // basic::axis: Child<void,many>

            // size() is available
            CHECK(axis.size() == 3);

            // We can use [] on axis to get references to the (still in-tree)
            // Nodes; dereferencing from the pointers happens in the []:
            (void)&axis[0];
            (void)&axis[1];
            (void)&axis[2];

            // So, using the above axis[n] constructs allows you to work
            // directly with the in-tree Nodes. Let's illustrate that we
            // indeed reference what we think we do:
            CHECK(&axes(basic::axis,"energy_in") == &axis[0]);
            CHECK(&axes(basic::axis,"mu") == &axis[1]);
            CHECK(&axes(basic::axis,"P(mu|energy_in)") == &axis[2]);

            // Finally, the axis object has a conversion to a straight vector
            // of Nodes - that is, the Nodes are copies of the ones in the
            // original tree.
            std::vector<Node> v = axis;
            CHECK(v.size() == 3);
            CHECK(v[0] == axis[0]);
            CHECK(v[1] == axis[1]);
            CHECK(v[2] == axis[2]);
         }

         // ------------
         // NON-CONST
         // ------------

         // Much like the above const case, but we'll change things
         // up a bit, and we can assign as well (because non-const)
         THEN("non-const works as expected") {
            Node &axes = tree(
               reactionSuite, reactions, reaction, "n + O16",
               outputChannel, products, product, "n",
               distribution, angularTwoBody, "eval",
               regions2d, basic::axes
            );

            // auto gives an object much like the one in the const case...
            auto axis = axes[basic::axis];
            CHECK(axis.size() == 3);

            // It's non-const. Let's back up axis[1], change it, ensure
            // the change "took" in the original tree, then restore.
            auto backup = axis[1];
            axis[1] = Node{"foobar"};
            bool found = false;
            axes.one("foobar",found); // parent axes now has a "foobar" Node
            CHECK(found);
            // restore
            axis[1] = backup;
            // actually, for "mu" even to work here,
            // the restoration had to have worked...
            CHECK(axes(basic::axis,"mu") == axis[1]);

            // So, using the above axis[n] constructs allows you to work
            // directly with the in-tree nodes. Let's illustrate that we
            // indeed reference what we think we do:
            CHECK(&axes(basic::axis,"energy_in") == &axis[0]);
            CHECK(&axes(basic::axis,"mu") == &axis[1]);
            CHECK(&axes(basic::axis,"P(mu|energy_in)") == &axis[2]);

            // Finally, test conversion...
            std::vector<Node> v = axis;
            CHECK(v.size() == 3);
            CHECK(v[0] == axis[0]);
            CHECK(v[1] == axis[1]);
            CHECK(v[2] == axis[2]);
         }
      }


      // ------------------------
      // [Child<TYPE,one>]
      // ------------------------

      WHEN("We call [Child<TYPE,one>]") {

         // ------------
         // CONST
         // ------------

         THEN("const works as expected") {
            // t will be a detail::ChildRef<Node,CONST=true,temp_t>,
            // where temp_t is our custom type defined above
            auto t = c(reactionSuite,styles,--evaluated)
               [Child<temp_t,Allow::one>("temperature")];

            // for const, assignment isn't available; neither of these compile:
            // t = Node{};
            // t = temp_t(0.0, "K");

            // t's type, as created by [] and described above, is, like its
            // metadata counterpart in an earlier test, something that allows
            // for various uses. It is NOT just an rvalue temp_t, as
            // would have been created by () rather than [].
            const temp_t t_new = t; // t can become a temp_t
            const Node mynode = t; // t can become a Node

            CHECK(t_new.value == 0.0);
            CHECK(t_new.unit  == "K");

            CHECK(mynode.metadata.size() == 2);
            CHECK(mynode(basic::value) == "0.0");
            CHECK(mynode(basic::unit ) == "K");
            CHECK(mynode.children.size() == 0);
         }

         // ------------
         // NON-CONST
         // ------------

         THEN("non-const works as expected") {
            // as for the const case, above, but assignment is now available
            auto t = n(reactionSuite,styles,--evaluated)
               [Child<temp_t,Allow::one>("temperature")];

            // assignment is available now:
            t = Node{};
            t = temp_t(0.0, "K");

            // conversion
            const temp_t t_new = t; // t can become a temp_t
            const Node mynode = t; // t can become a Node

            CHECK(t_new.value == 0.0);
            CHECK(t_new.unit  == "K");

            CHECK(mynode.metadata.size() == 2);
            // = "0" in the following line, because t = temp_t(0.0, "K")
            // above just wrote 0 for double 0.0.
            CHECK(mynode(basic::value) == "0");
            CHECK(mynode(basic::unit ) == "K");
            CHECK(mynode.children.size() == 0);

            // Let's exercise [], obtained from a non-const Node, to illustrate
            // how it produces an lvalue.

            // parent Node of <temperature>
            auto &parent = n(reactionSuite,styles,--evaluated);
            // back up <temperature>, so we can restore it
            const auto backup = parent(temperature);

            // Child for our temp_t
            const Child<temp_t> temp("temperature");

            // [] gives lvalue, so this actually writes into the tree...
            parent[temp] = Node{"temperature"};
            CHECK(tree(reactionSuite,styles,--evaluated,temperature)
                  == Node{"temperature"});

            // restore from backup
            parent[temp] = backup;
            CHECK(tree(reactionSuite,styles,--evaluated,temperature)
                  != Node{"temperature"}); // has other than just its name :-)

            // can still use as rvalue, and implicitly converts to Node...
            Node foo = parent[temp];
            CHECK(foo.metadata.size() == 2);
            CHECK(foo.children.size() == 0);

            // this also writes into the tree...
            parent[temp] = temp_t(1.0,"C");
            CHECK(tree(reactionSuite,styles,--evaluated,temperature,
                       double{}/value) == 1);
            CHECK(tree(reactionSuite,styles,--evaluated,temperature,
                       unit) == "C");

            // can still use as rvalue, and implicitly converts to temp_t...
            temp_t bar = parent[temp];
            CHECK(bar.value == 1.0);
            CHECK(bar.unit  == "C");
         }
      }


      // ------------------------
      // [Child<TYPE,many>]
      // ------------------------

      WHEN("We call [Child<TYPE,many>]") {

         // ------------
         // CONST
         // ------------

         THEN("const works as expected") {
            const Node &axes = tree(
               reactionSuite,
               reactions,
               reaction, "n + O16",
               outputChannel,
               products,
               product, "n",
               distribution,
               angularTwoBody, "eval",
               regions2d,
               basic::axes
            );
            CHECK(axes.metadata.size() == 0);
            CHECK(axes.children.size() == 3);

            // auto gives a certain "smart object" that knows about the axis
            // nodes in the tree (not copies), also knows about the type (in
            // this case axis_t{}) that was used for its creation, and provides
            // functionality that takes advantage of all that.
            auto axis = axes[axis_t{}/basic::axis]; // [Child<axis_t,many>]

            // size() is available
            CHECK(axis.size() == 3);

            // At this point, you can say axis[0], axis[1] etc. and get
            // objects of the same type as those illustrated earlier for
            // the [Child<TYPE,one>] cases.

            // axis converts to a std::vector<axis_t>. Also, although
            // it's not really the point of the current test, axis[0]
            // etc. can convert to axis_t.
            std::vector<axis_t> vector_axis = axis;
            CHECK(vector_axis.size() == 3);
            CHECK(vector_axis[0] == axis_t(axis[0]));
            CHECK(vector_axis[1] == axis_t(axis[1]));
            CHECK(vector_axis[2] == axis_t(axis[2]));

            // axis converts to a std::vector<Node>. Also, axis[0] etc.
            // can convert to Node.
            std::vector<Node> vector_node = axis;
            CHECK(vector_node.size() == 3);
            CHECK(vector_node[0] == Node(axis[0]));
            CHECK(vector_node[1] == Node(axis[1]));
            CHECK(vector_node[2] == Node(axis[2]));
         }

         // ------------
         // NON-CONST
         // ------------

         // Much like the above const case
         THEN("non-const works as expected") {
            Node &axes = tree(
               reactionSuite,
               reactions,
               reaction, "n + O16",
               outputChannel,
               products,
               product, "n",
               distribution,
               angularTwoBody, "eval",
               regions2d,
               basic::axes
            );
            CHECK(axes.metadata.size() == 0);
            CHECK(axes.children.size() == 3);

            // auto gives a certain "smart object" that knows about the axis
            // nodes in the tree (not copies), also knows about the type (in
            // this case axis_t{}) that was used for its creation, and provides
            // functionality that takes advantage of all that.
            auto axis = axes[axis_t{}/basic::axis]; // [Child<axis_t,many>]

            // size() is available
            CHECK(axis.size() == 3);

            // Illustrating here that for the non-const case, you can assign.
            // Setting axis[0] to be the same as axis[1] isn't something we'd
            // actually want to do, but it doesn't mess up any further tests...
            CHECK(axis_t(axis[0]) != axis_t(axis[1]));
            CHECK(Node(axis[0]) != Node(axis[1]));
            axis[0] = axis_t(axis[1]); // assign
            CHECK(axis_t(axis[0]) == axis_t(axis[1]));
            CHECK(Node(axis[0]) == Node(axis[1]));

            // axis converts to a std::vector<axis_t>. Also, although
            // it's not really the point of the current test, axis[0]
            // etc. can convert to axis_t.
            std::vector<axis_t> vector_axis = axis;
            CHECK(vector_axis.size() == 3);
            CHECK(vector_axis[0] == axis_t(axis[0]));
            CHECK(vector_axis[1] == axis_t(axis[1]));
            CHECK(vector_axis[2] == axis_t(axis[2]));

            // axis converts to a std::vector<Node>. Also, axis[0] etc.
            // can convert to Node.
            std::vector<Node> vector_node = axis;
            CHECK(vector_node.size() == 3);
            CHECK(vector_node[0] == Node(axis[0]));
            CHECK(vector_node[1] == Node(axis[1]));
            CHECK(vector_node[2] == Node(axis[2]));
         }
      }
   }
}
