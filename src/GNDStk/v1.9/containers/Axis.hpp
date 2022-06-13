
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_CONTAINERS_AXIS
#define GNDSTK_V1_9_CONTAINERS_AXIS

#include "GNDStk/v1.9/key.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {


// -----------------------------------------------------------------------------
// containers::
// class Axis
// -----------------------------------------------------------------------------

namespace containers {

class Axis : public Component<containers::Axis> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Names: this namespace, this class, a field / node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Axis"; }
   static auto FIELD() { return "axis"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<int>{}
            / Meta<>("index") |
         std::optional<std::string>{}
            / Meta<>("label") |
         std::optional<std::string>{}
            / Meta<>("unit")
      ;
   }

public:

   using Component::construct;

   // metadata
   Field<Axis,std::optional<int>> index;
   Field<Axis,std::optional<std::string>> label;
   Field<Axis,std::optional<std::string>> unit;

   // ------------------------
   // Constructors
   // ------------------------

   // default, and from fields
   explicit Axis(
      const std::optional<int> &index = {},
      const std::optional<std::string> &label = {},
      const std::optional<std::string> &unit = {}
   ) :
      Component{
         BlockData{},
         this->index,
         this->label,
         this->unit
      },
      index(this,index,"index"),
      label(this,label,"label"),
      unit(this,unit,"unit")
   {
      Component::finish();
   }

   // from node
   Axis(const Node &node) :
      Component{
         BlockData{},
         this->index,
         this->label,
         this->unit
      },
      index(this,{},"index"),
      label(this,{},"label"),
      unit(this,{},"unit")
   {
      Component::finish(node);
   }

   // copy
   Axis(const Axis &other) :
      Component{
         other.baseBlockData(),
         this->index,
         this->label,
         this->unit
      },
      index(this,other.index),
      label(this,other.label),
      unit(this,other.unit)
   {
      Component::finish(other);
   }

   // move
   Axis(Axis &&other) :
      Component{
         other.baseBlockData(),
         this->index,
         this->label,
         this->unit
      },
      index(this,std::move(other.index)),
      label(this,std::move(other.label)),
      unit(this,std::move(other.unit))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment
   // ------------------------

   Axis &operator=(const Axis &) = default;
   Axis &operator=(Axis &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Axis/src/custom.hpp"

}; // class Axis

} // namespace containers
} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
