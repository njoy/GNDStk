
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_STANDARD
#define TEST_V2_0_CONTAINERS_STANDARD

#include "test/v2.0/extra/Double.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Standard
// -----------------------------------------------------------------------------

class Standard :
   public Component<containers::Standard>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Standard"; }
   static auto FIELD() { return "standard"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<extra::Double>("double")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<extra::Double> Double{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->Double)

   // default
   Standard() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Standard(
      const wrapper<extra::Double> &Double
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      Double(this,Double)
   {
      Component::finish();
   }

   // from node
   explicit Standard(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Standard(const Standard &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      Double(this,other.Double)
   {
      Component::finish(other);
   }

   // move
   Standard(Standard &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      Double(this,std::move(other.Double))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Standard &operator=(const Standard &) = default;
   Standard &operator=(Standard &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Standard/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Standard

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
