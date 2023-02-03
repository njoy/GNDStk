
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_GENERALEVAPORATION
#define ALPHA_V2_0_GENERAL_GENERALEVAPORATION

#include "alpha/v2.0/general/U.hpp"
#include "alpha/v2.0/general/Theta.hpp"
#include "alpha/v2.0/general/G.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class GeneralEvaporation
// -----------------------------------------------------------------------------

class GeneralEvaporation :
   public Component<general::GeneralEvaporation>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "GeneralEvaporation"; }
   static auto FIELD() { return "generalEvaporation"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::U>
            ("U") |
         --Child<general::Theta>
            ("theta") |
         --Child<general::G>
            ("g")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<general::U>
      U{this};
   Field<general::Theta>
      theta{this};
   Field<general::G>
      g{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->U, \
      this->theta, \
      this->g)

   // default
   GeneralEvaporation() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit GeneralEvaporation(
      const wrapper<general::U>
         &U,
      const wrapper<general::Theta>
         &theta = {},
      const wrapper<general::G>
         &g = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      U(this,U),
      theta(this,theta),
      g(this,g)
   {
      Component::finish();
   }

   // from node
   explicit GeneralEvaporation(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   GeneralEvaporation(const GeneralEvaporation &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      U(this,other.U),
      theta(this,other.theta),
      g(this,other.g)
   {
      Component::finish(other);
   }

   // move
   GeneralEvaporation(GeneralEvaporation &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      U(this,std::move(other.U)),
      theta(this,std::move(other.theta)),
      g(this,std::move(other.g))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   GeneralEvaporation &operator=(const GeneralEvaporation &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         U = other.U;
         theta = other.theta;
         g = other.g;
      }
      return *this;
   }

   // move
   GeneralEvaporation &operator=(GeneralEvaporation &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         U = std::move(other.U);
         theta = std::move(other.theta);
         g = std::move(other.g);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/GeneralEvaporation/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class GeneralEvaporation

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
