
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_INTENSITY
#define ALPHA_V2_0_GENERAL_INTENSITY

#include "alpha/v2.0/general/Uncertainty.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Intensity
// -----------------------------------------------------------------------------

class Intensity :
   public Component<general::Intensity>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Intensity"; }
   static auto FIELD() { return "intensity"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         double{}
            / Meta<>("value") |

         // children
         --Child<std::optional<general::Uncertainty>>
            ("uncertainty")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<double>
      value{this};

   // children
   Field<std::optional<general::Uncertainty>>
      uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->value, \
      this->uncertainty)

   // default
   Intensity() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Intensity(
      const wrapper<double>
         &value,
      const wrapper<std::optional<general::Uncertainty>>
         &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      value(this,value),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit Intensity(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Intensity(const Intensity &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      value(this,other.value),
      uncertainty(this,other.uncertainty)
   {
      Component::finish(other);
   }

   // move
   Intensity(Intensity &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      value(this,std::move(other.value)),
      uncertainty(this,std::move(other.uncertainty))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Intensity &operator=(const Intensity &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         value = other.value;
         uncertainty = other.uncertainty;
      }
      return *this;
   }

   // move
   Intensity &operator=(Intensity &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         value = std::move(other.value);
         uncertainty = std::move(other.uncertainty);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Intensity/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Intensity

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
