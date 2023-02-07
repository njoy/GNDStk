
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_TOTALENERGY
#define ALPHA_V2_0_GENERAL_TOTALENERGY

#include "alpha/v2.0/general/Polynomial1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class TotalEnergy
// -----------------------------------------------------------------------------

class TotalEnergy :
   public Component<general::TotalEnergy>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "TotalEnergy"; }
   static auto FIELD() { return "totalEnergy"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Polynomial1d>
            ("polynomial1d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<general::Polynomial1d>
      polynomial1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->polynomial1d \
   )

   // default
   TotalEnergy() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit TotalEnergy(
      const wrapper<general::Polynomial1d>
         &polynomial1d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      polynomial1d(this,polynomial1d)
   {
      Component::finish();
   }

   // from node
   explicit TotalEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   TotalEnergy(const TotalEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      polynomial1d(this,other.polynomial1d)
   {
      Component::finish(other);
   }

   // move
   TotalEnergy(TotalEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      polynomial1d(this,std::move(other.polynomial1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   TotalEnergy &operator=(const TotalEnergy &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         polynomial1d = other.polynomial1d;
      }
      return *this;
   }

   // move
   TotalEnergy &operator=(TotalEnergy &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         polynomial1d = std::move(other.polynomial1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/TotalEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class TotalEnergy

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
