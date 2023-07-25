
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_AVERAGEENERGIES
#define GNDS_V2_0_GENERAL_AVERAGEENERGIES

#include "gnds/v2.0/general/AverageEnergy.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class AverageEnergies
// -----------------------------------------------------------------------------

class AverageEnergies :
   public Component<general::AverageEnergies>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "AverageEnergies"; }
   static auto NODENAME() { return "averageEnergies"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::AverageEnergy>
            ("averageEnergy")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "averageEnergy"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "average_energy"
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

   // children
   Field<std::vector<general::AverageEnergy>>
      averageEnergy{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->averageEnergy \
   )

   // default
   AverageEnergies() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit AverageEnergies(
      const wrapper<std::vector<general::AverageEnergy>>
         &averageEnergy
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      averageEnergy(this,averageEnergy)
   {
      Component::finish();
   }

   // from node
   explicit AverageEnergies(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   AverageEnergies(const AverageEnergies &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      averageEnergy(this,other.averageEnergy)
   {
      Component::finish(other);
   }

   // move
   AverageEnergies(AverageEnergies &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      averageEnergy(this,std::move(other.averageEnergy))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   AverageEnergies &operator=(const AverageEnergies &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         averageEnergy = other.averageEnergy;
      }
      return *this;
   }

   // move
   AverageEnergies &operator=(AverageEnergies &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         averageEnergy = std::move(other.averageEnergy);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/AverageEnergies/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class AverageEnergies

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
