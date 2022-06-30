
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_CONTAINERS_AXIS
#define GNDSTK_V1_9_CONTAINERS_AXIS

// GNDStk Core Interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Axis
// -----------------------------------------------------------------------------

namespace containers {

class Axis : public Component<Axis> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Axis"; }
   static auto GNDSName() { return "axis"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
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

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<int> index;
      std::optional<std::string> label;
      std::optional<std::string> unit;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // index
   const std::optional<int> &index() const
      { return content.index; }
   std::optional<int> &index()
      { return content.index; }

   // label
   const std::optional<std::string> &label() const
      { return content.label; }
   std::optional<std::string> &label()
      { return content.label; }

   // unit
   const std::optional<std::string> &unit() const
      { return content.unit; }
   std::optional<std::string> &unit()
      { return content.unit; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // index(value)
   Axis &index(const std::optional<int> &obj)
      { index() = obj; return *this; }

   // label(value)
   Axis &label(const std::optional<std::string> &obj)
      { label() = obj; return *this; }

   // unit(value)
   Axis &unit(const std::optional<std::string> &obj)
      { unit() = obj; return *this; }

   // ------------------------
   // Constructors
   // ------------------------

   // default, and from fields
   explicit Axis(
      const std::optional<int> &index =
         std::optional<int>{},
      const std::optional<std::string> &label =
         std::optional<std::string>{},
      const std::optional<std::string> &unit =
         std::optional<std::string>{}
   ) :
      Component{
         BlockData{},
         this->index(),
         this->label(),
         this->unit()
      },
      content{
         index,
         label,
         unit
      }
   {
      Component::finish();
   }

   // copy
   Axis(const Axis &other) :
      Component{
         other.baseBlockData(),
         this->index(),
         this->label(),
         this->unit()
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Axis(Axis &&other) :
      Component{
         other.baseBlockData(),
         this->index(),
         this->label(),
         this->unit()
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Axis(const Node &node) :
      Component{
         BlockData{},
         this->index(),
         this->label(),
         this->unit()
      }
   {
      Component::finish(node);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Axis &operator=(const Axis &) = default;

   // move
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
