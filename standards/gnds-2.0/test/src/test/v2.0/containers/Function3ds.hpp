
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_FUNCTION3DS
#define TEST_V2_0_CONTAINERS_FUNCTION3DS

#include "test/v2.0/containers/XYs3d.hpp"
#include "test/v2.0/containers/Gridded3d.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Function3ds
// -----------------------------------------------------------------------------

class Function3ds :
   public Component<containers::Function3ds>
{
   friend class Component;

   using _t = std::variant<
      containers::XYs3d,
      containers::Gridded3d
   >;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Function3ds"; }
   static auto FIELD() { return "function3ds"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         _t{}
            / ++(Child<>("XYs3d") || Child<>("gridded3d"))
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children - variant
   Field<std::vector<_t>> _XYs3dgridded3d{this};
   FieldPart<decltype(_XYs3dgridded3d),containers::XYs3d> XYs3d{_XYs3dgridded3d};
   FieldPart<decltype(_XYs3dgridded3d),containers::Gridded3d> gridded3d{_XYs3dgridded3d};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->_XYs3dgridded3d)

   // default
   Function3ds() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Function3ds(
      const wrapper<std::vector<_t>> &_XYs3dgridded3d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      _XYs3dgridded3d(this,_XYs3dgridded3d)
   {
      Component::finish();
   }

   // from node
   explicit Function3ds(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Function3ds(const Function3ds &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      _XYs3dgridded3d(this,other._XYs3dgridded3d)
   {
      Component::finish(other);
   }

   // move
   Function3ds(Function3ds &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      _XYs3dgridded3d(this,std::move(other._XYs3dgridded3d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Function3ds &operator=(const Function3ds &) = default;
   Function3ds &operator=(Function3ds &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Function3ds/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Function3ds

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
