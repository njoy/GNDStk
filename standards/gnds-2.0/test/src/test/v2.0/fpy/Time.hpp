
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_FPY_TIME
#define TEST_V2_0_FPY_TIME

#include "test/v2.0/containers/Double.hpp"
#include "test/v2.0/containers/String.hpp"

namespace test {
namespace v2_0 {
namespace fpy {

// -----------------------------------------------------------------------------
// fpy::
// class Time
// -----------------------------------------------------------------------------

class Time :
   public Component<fpy::Time>
{
   friend class Component;

   using _t = std::variant<
      containers::Double,
      containers::String
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "fpy"; }
   static auto CLASS() { return "Time"; }
   static auto FIELD() { return "time"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         _t{}
            / --(Child<>("Double") || Child<>("string"))
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children - variant
   Field<_t> _Doublestring{this};
   FieldPart<decltype(_Doublestring),containers::Double> Double{_Doublestring};
   FieldPart<decltype(_Doublestring),containers::String> string{_Doublestring};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->_Doublestring)

   // default
   Time() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Time(
      const wrapper<_t> &_Doublestring
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      _Doublestring(this,_Doublestring)
   {
      Component::finish();
   }

   // from node
   explicit Time(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Time(const Time &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      _Doublestring(this,other._Doublestring)
   {
      Component::finish(other);
   }

   // move
   Time(Time &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      _Doublestring(this,std::move(other._Doublestring))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Time &operator=(const Time &) = default;
   Time &operator=(Time &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/fpy/Time/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Time

} // namespace fpy
} // namespace v2_0
} // namespace test

#endif
