
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_FPY_TIME
#define TRY_V2_0_FPY_TIME

#include "try/v2.0/unknownNamespace/Double.hpp"
#include "try/v2.0/unknownNamespace/String.hpp"

namespace try {
namespace v2_0 {
namespace fpy {

// -----------------------------------------------------------------------------
// fpy::
// class Time
// -----------------------------------------------------------------------------

class Time : public Component<fpy::Time> {
   friend class Component;

   using _t = std::variant<
      unknownNamespace::Double,
      unknownNamespace::String
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fpy"; }
   static auto CLASS() { return "Time"; }
   static auto FIELD() { return "time"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         _t{}
            / --(Child<>("Double") || Child<>("string"))
      ;
   }

public:
   using Component::construct;

   // children - variant
   Field<_t> _Doublestring{this};
   FieldPart<decltype(_Doublestring),unknownNamespace::Double> Double{_Doublestring};
   FieldPart<decltype(_Doublestring),unknownNamespace::String> string{_Doublestring};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->_Doublestring)

   // default, and from fields
   explicit Time(
      const wrapper<_t> &_Doublestring = {}
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
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Time(Time &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
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

   #include "try/v2.0/fpy/Time/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Time

} // namespace fpy
} // namespace v2_0
} // namespace try

#endif
