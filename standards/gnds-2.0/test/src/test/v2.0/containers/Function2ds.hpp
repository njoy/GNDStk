
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_FUNCTION2DS
#define TEST_V2_0_CONTAINERS_FUNCTION2DS

#include "test/v2.0/containers/XYs2d.hpp"
#include "test/v2.0/containers/Gridded2d.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Function2ds
// -----------------------------------------------------------------------------

class Function2ds :
   public Component<containers::Function2ds>
{
   friend class Component;

   using _t = std::variant<
      containers::XYs2d,
      containers::Gridded2d
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Function2ds"; }
   static auto FIELD() { return "function2ds"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         _t{}
            / ++(Child<>("XYs2d") || Child<>("gridded2d"))
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children - variant
   Field<std::vector<_t>> _XYs2dgridded2d{this};
   FieldPart<decltype(_XYs2dgridded2d),containers::XYs2d> XYs2d{_XYs2dgridded2d};
   FieldPart<decltype(_XYs2dgridded2d),containers::Gridded2d> gridded2d{_XYs2dgridded2d};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->_XYs2dgridded2d)

   // default
   Function2ds() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Function2ds(
      const wrapper<std::vector<_t>> &_XYs2dgridded2d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      _XYs2dgridded2d(this,_XYs2dgridded2d)
   {
      Component::finish();
   }

   // from node
   explicit Function2ds(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Function2ds(const Function2ds &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      _XYs2dgridded2d(this,other._XYs2dgridded2d)
   {
      Component::finish(other);
   }

   // move
   Function2ds(Function2ds &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      _XYs2dgridded2d(this,std::move(other._XYs2dgridded2d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Function2ds &operator=(const Function2ds &) = default;
   Function2ds &operator=(Function2ds &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Function2ds/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Function2ds

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
