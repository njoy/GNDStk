
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_NUCLEARTERM
#define ALPHA_V2_0_GENERAL_NUCLEARTERM

#include "alpha/v2.0/general/Regions2d.hpp"
#include "alpha/v2.0/general/XYs2d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class NuclearTerm
// -----------------------------------------------------------------------------

class NuclearTerm :
   public Component<general::NuclearTerm>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "NuclearTerm"; }
   static auto FIELD() { return "nuclearTerm"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::Regions2d>>
            ("regions2d") |
         --Child<std::optional<general::XYs2d>>
            ("XYs2d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<general::Regions2d>>
      regions2d{this};
   Field<std::optional<general::XYs2d>>
      XYs2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->regions2d, \
      this->XYs2d \
   )

   // default
   NuclearTerm() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit NuclearTerm(
      const wrapper<std::optional<general::Regions2d>>
         &regions2d,
      const wrapper<std::optional<general::XYs2d>>
         &XYs2d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      regions2d(this,regions2d),
      XYs2d(this,XYs2d)
   {
      Component::finish();
   }

   // from node
   explicit NuclearTerm(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   NuclearTerm(const NuclearTerm &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      regions2d(this,other.regions2d),
      XYs2d(this,other.XYs2d)
   {
      Component::finish(other);
   }

   // move
   NuclearTerm(NuclearTerm &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      regions2d(this,std::move(other.regions2d)),
      XYs2d(this,std::move(other.XYs2d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   NuclearTerm &operator=(const NuclearTerm &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         regions2d = other.regions2d;
         XYs2d = other.XYs2d;
      }
      return *this;
   }

   // move
   NuclearTerm &operator=(NuclearTerm &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         regions2d = std::move(other.regions2d);
         XYs2d = std::move(other.XYs2d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/NuclearTerm/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class NuclearTerm

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
