
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_U
#define ALPHA_V2_0_MEAN_U

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class U
// -----------------------------------------------------------------------------

class U :
   public Component<mean::U>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "U"; }
   static auto FIELD() { return "U"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         double{}
            / Meta<>("value") |
         std::string{}
            / Meta<>("unit")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<double> value{this};
   Field<std::string> unit{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->value, \
      this->unit)

   // default
   U() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit U(
      const wrapper<double> &value,
      const wrapper<std::string> &unit = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      value(this,value),
      unit(this,unit)
   {
      Component::finish();
   }

   // from node
   explicit U(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   U(const U &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      value(this,other.value),
      unit(this,other.unit)
   {
      Component::finish(other);
   }

   // move
   U(U &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      value(this,std::move(other.value)),
      unit(this,std::move(other.unit))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   U &operator=(const U &) = default;
   U &operator=(U &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/U/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class U

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
