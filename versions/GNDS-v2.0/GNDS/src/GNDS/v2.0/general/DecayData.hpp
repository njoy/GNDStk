
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_DECAYDATA
#define GNDS_V2_0_GENERAL_DECAYDATA

#include "GNDS/v2.0/general/DecayModes.hpp"
#include "GNDS/v2.0/general/AverageEnergies.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class DecayData
// -----------------------------------------------------------------------------

class DecayData :
   public Component<general::DecayData>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "DecayData"; }
   static auto NODENAME() { return "decayData"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::DecayModes>
            ("decayModes") |
         --Child<std::optional<general::AverageEnergies>>
            ("averageEnergies")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "decayModes",
         "averageEnergies"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "decay_modes",
         "average_energies"
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
   Field<general::DecayModes>
      decayModes{this};
   Field<std::optional<general::AverageEnergies>>
      averageEnergies{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(decayModes(),decayMode);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->decayModes, \
      this->averageEnergies \
   )

   // default
   DecayData() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DecayData(
      const wrapper<general::DecayModes>
         &decayModes,
      const wrapper<std::optional<general::AverageEnergies>>
         &averageEnergies = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      decayModes(this,decayModes),
      averageEnergies(this,averageEnergies)
   {
      Component::finish();
   }

   // from node
   explicit DecayData(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DecayData(const DecayData &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      decayModes(this,other.decayModes),
      averageEnergies(this,other.averageEnergies)
   {
      Component::finish(other);
   }

   // move
   DecayData(DecayData &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      decayModes(this,std::move(other.decayModes)),
      averageEnergies(this,std::move(other.averageEnergies))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   DecayData &operator=(const DecayData &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         decayModes = other.decayModes;
         averageEnergies = other.averageEnergies;
      }
      return *this;
   }

   // move
   DecayData &operator=(DecayData &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         decayModes = std::move(other.decayModes);
         averageEnergies = std::move(other.averageEnergies);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/DecayData/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class DecayData

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
