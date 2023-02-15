
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_REDUCED_DOUBLE
#define ALPHA_V2_0_REDUCED_DOUBLE

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace reduced {

// -----------------------------------------------------------------------------
// reduced::
// class Double
// -----------------------------------------------------------------------------

class Double :
   public Component<reduced::Double>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "reduced"; }
   static auto CLASS() { return "Double"; }
   static auto FIELD() { return "double"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         double{}
            / Meta<>("value")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "value"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<double>
      value{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->value \
   )

   // default
   Double() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Double(
      const wrapper<double>
         &value
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      value(this,value)
   {
      Component::finish();
   }

   // from node
   explicit Double(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Double(const Double &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      value(this,other.value)
   {
      Component::finish(other);
   }

   // move
   Double(Double &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      value(this,std::move(other.value))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Double &operator=(const Double &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         value = other.value;
      }
      return *this;
   }

   // move
   Double &operator=(Double &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         value = std::move(other.value);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/reduced/Double/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Double

} // namespace reduced
} // namespace v2_0
} // namespace alpha

#endif
