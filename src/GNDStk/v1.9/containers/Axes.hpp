
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V1_9_CONTAINERS_AXES
#define NJOY_GNDSTK_V1_9_CONTAINERS_AXES

// core interface
#include "GNDStk.hpp"

// v1.9 dependencies
#include "GNDStk/v1.9/containers/Axis.hpp"
#include "GNDStk/v1.9/containers/Grid.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Axes
// -----------------------------------------------------------------------------

namespace containers {

class Axes : public Component<Axes> {

   using VARIANT = std::variant<
      containers::Axis,
      containers::Grid
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Axes"; }
   static auto GNDSName() { return "axes"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<UTF8Text>{}
            / Meta<>("href") |
         // children
         VARIANT{}
            / ++Child<>("axis grid")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<UTF8Text> href;

      // children
      std::vector<VARIANT> choice;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // href
   const auto &href() const
    { return content.href; }
   auto &href()
    { return content.href; }

   // choice
   const auto &choice() const
    { return content.choice; }
   auto &choice()
    { return content.choice; }

   // choice(index)
   const auto &choice(const std::size_t index) const
    { return getter(choice(), index, "choice"); }
   auto &choice(const std::size_t index)
    { return getter(choice(), index, "choice"); }

   // choice(label)
   const auto &choice(const std::string &label) const
    { return getter(choice(), label, "choice"); }
   auto &choice(const std::string &label)
    { return getter(choice(), label, "choice"); }

   // axis(index)
   auto axis(const std::size_t index) const
    { return getter<containers::Axis>(choice(), index, "axis"); }
   auto axis(const std::size_t index)
    { return getter<containers::Axis>(choice(), index, "axis"); }

   // axis(label)
   auto axis(const std::string &label) const
    { return getter<containers::Axis>(choice(), label, "axis"); }
   auto axis(const std::string &label)
    { return getter<containers::Axis>(choice(), label, "axis"); }

   // grid(index)
   auto grid(const std::size_t index) const
    { return getter<containers::Grid>(choice(), index, "grid"); }
   auto grid(const std::size_t index)
    { return getter<containers::Grid>(choice(), index, "grid"); }

   // grid(label)
   auto grid(const std::string &label) const
    { return getter<containers::Grid>(choice(), label, "grid"); }
   auto grid(const std::string &label)
    { return getter<containers::Grid>(choice(), label, "grid"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // href(value)
   auto &href(const std::optional<UTF8Text> &obj)
    { href() = obj; return *this; }

   // choice(value)
   auto &choice(const std::vector<VARIANT> &obj)
    { choice() = obj; return *this; }

   // choice(index,value)
   auto &choice(
      const std::size_t index,
      const VARIANT &obj
   ) {
      choice(index) = obj; return *this;
   }

   // choice(label,value)
   auto &choice(
      const std::string &label,
      const VARIANT &obj
   ) {
      choice(label) = obj; return *this;
   }

   // axis(index,value)
   auto &axis(
      const std::size_t index,
      const std::optional<containers::Axis> &obj
   ) {
      if (obj) choice(index,obj.value());
      return *this;
   }

   // axis(label,value)
   auto &axis(
      const std::string &label,
      const std::optional<containers::Axis> &obj
   ) {
      if (obj) choice(label,obj.value());
      return *this;
   }

   // grid(index,value)
   auto &grid(
      const std::size_t index,
      const std::optional<containers::Grid> &obj
   ) {
      if (obj) choice(index,obj.value());
      return *this;
   }

   // grid(label,value)
   auto &grid(
      const std::string &label,
      const std::optional<containers::Grid> &obj
   ) {
      if (obj) choice(label,obj.value());
      return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Axes() :
      Component{
         BodyText{},
         content.href,
         content.choice
      }
   {
      Component::finish();
   }

   // copy
   Axes(const Axes &other) :
      Component{
         other,
         content.href,
         content.choice
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Axes(Axes &&other) :
      Component{
         other,
         content.href,
         content.choice
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Axes(const Node &node) :
      Component{
         BodyText{},
         content.href,
         content.choice
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Axes(
      const std::optional<UTF8Text> &href,
      const std::vector<VARIANT> &choice
   ) :
      Component{
         BodyText{},
         content.href,
         content.choice
      },
      content{
         href,
         choice
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Axes &operator=(const Axes &) = default;

   // move
   Axes &operator=(Axes &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Axes/src/custom.hpp"

}; // class Axes

} // namespace containers

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
