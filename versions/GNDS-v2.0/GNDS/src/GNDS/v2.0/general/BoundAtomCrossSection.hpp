
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_BOUNDATOMCROSSSECTION
#define GNDS_V2_0_GENERAL_BOUNDATOMCROSSSECTION

#include "GNDS/v2.0/key.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class BoundAtomCrossSection
// -----------------------------------------------------------------------------

class BoundAtomCrossSection :
   public Component<general::BoundAtomCrossSection>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "BoundAtomCrossSection"; }
   static auto NODENAME() { return "boundAtomCrossSection"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "value",
         "unit"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "value",
         "unit"
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
   Field<std::string>
      unit{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->value, \
      this->unit \
   )

   // default
   BoundAtomCrossSection() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit BoundAtomCrossSection(
      const wrapper<double>
         &value,
      const wrapper<std::string>
         &unit = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      value(this,value),
      unit(this,unit)
   {
      Component::finish();
   }

   // from node
   explicit BoundAtomCrossSection(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   BoundAtomCrossSection(const BoundAtomCrossSection &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      value(this,other.value),
      unit(this,other.unit)
   {
      Component::finish(other);
   }

   // move
   BoundAtomCrossSection(BoundAtomCrossSection &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      value(this,std::move(other.value)),
      unit(this,std::move(other.unit))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   BoundAtomCrossSection &operator=(const BoundAtomCrossSection &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         value = other.value;
         unit = other.unit;
      }
      return *this;
   }

   // move
   BoundAtomCrossSection &operator=(BoundAtomCrossSection &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         value = std::move(other.value);
         unit = std::move(other.unit);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/BoundAtomCrossSection/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class BoundAtomCrossSection

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif