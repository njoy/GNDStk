
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_PROCESSED_AVAILABLEENERGY
#define TEST_V2_0_PROCESSED_AVAILABLEENERGY

#include "test/v2.0/containers/XYs1d.hpp"
#include "test/v2.0/containers/Gridded1d.hpp"

namespace test {
namespace v2_0 {
namespace processed {

// -----------------------------------------------------------------------------
// processed::
// class AvailableEnergy
// -----------------------------------------------------------------------------

class AvailableEnergy :
   public Component<processed::AvailableEnergy>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "processed"; }
   static auto CLASS() { return "AvailableEnergy"; }
   static auto FIELD() { return "availableEnergy"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<containers::XYs1d>>("XYs1d") |
         --Child<std::optional<containers::Gridded1d>>("gridded1d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<containers::XYs1d>> XYs1d{this};
   Field<std::optional<containers::Gridded1d>> gridded1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->XYs1d, \
      this->gridded1d)

   // default
   AvailableEnergy() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit AvailableEnergy(
      const wrapper<std::optional<containers::XYs1d>> &XYs1d,
      const wrapper<std::optional<containers::Gridded1d>> &gridded1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      gridded1d(this,gridded1d)
   {
      Component::finish();
   }

   // from node
   explicit AvailableEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   AvailableEnergy(const AvailableEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs1d(this,other.XYs1d),
      gridded1d(this,other.gridded1d)
   {
      Component::finish(other);
   }

   // move
   AvailableEnergy(AvailableEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs1d(this,std::move(other.XYs1d)),
      gridded1d(this,std::move(other.gridded1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   AvailableEnergy &operator=(const AvailableEnergy &) = default;
   AvailableEnergy &operator=(AvailableEnergy &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/processed/AvailableEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class AvailableEnergy

} // namespace processed
} // namespace v2_0
} // namespace test

#endif
