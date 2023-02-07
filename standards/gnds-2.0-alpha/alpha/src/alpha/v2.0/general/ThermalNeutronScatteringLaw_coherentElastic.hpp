
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_THERMALNEUTRONSCATTERINGLAW_COHERENTELASTIC
#define ALPHA_V2_0_GENERAL_THERMALNEUTRONSCATTERINGLAW_COHERENTELASTIC

#include "alpha/v2.0/general/S_table.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ThermalNeutronScatteringLaw_coherentElastic
// -----------------------------------------------------------------------------

class ThermalNeutronScatteringLaw_coherentElastic :
   public Component<general::ThermalNeutronScatteringLaw_coherentElastic>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ThermalNeutronScatteringLaw_coherentElastic"; }
   static auto FIELD() { return "thermalNeutronScatteringLaw_coherentElastic"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("pid") |
         std::string{}
            / Meta<>("productFrame") |

         // children
         --Child<general::S_table>
            ("S_table")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<std::string> pid{this};
   Field<std::string> productFrame{this};

   // children
   Field<general::S_table>
      S_table{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->pid, \
      this->productFrame, \
      this->S_table \
   )

   // default
   ThermalNeutronScatteringLaw_coherentElastic() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ThermalNeutronScatteringLaw_coherentElastic(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &pid = {},
      const wrapper<std::string>
         &productFrame = {},
      const wrapper<general::S_table>
         &S_table = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      pid(this,pid),
      productFrame(this,productFrame),
      S_table(this,S_table)
   {
      Component::finish();
   }

   // from node
   explicit ThermalNeutronScatteringLaw_coherentElastic(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ThermalNeutronScatteringLaw_coherentElastic(const ThermalNeutronScatteringLaw_coherentElastic &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      pid(this,other.pid),
      productFrame(this,other.productFrame),
      S_table(this,other.S_table)
   {
      Component::finish(other);
   }

   // move
   ThermalNeutronScatteringLaw_coherentElastic(ThermalNeutronScatteringLaw_coherentElastic &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      pid(this,std::move(other.pid)),
      productFrame(this,std::move(other.productFrame)),
      S_table(this,std::move(other.S_table))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ThermalNeutronScatteringLaw_coherentElastic &operator=(const ThermalNeutronScatteringLaw_coherentElastic &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         pid = other.pid;
         productFrame = other.productFrame;
         S_table = other.S_table;
      }
      return *this;
   }

   // move
   ThermalNeutronScatteringLaw_coherentElastic &operator=(ThermalNeutronScatteringLaw_coherentElastic &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         pid = std::move(other.pid);
         productFrame = std::move(other.productFrame);
         S_table = std::move(other.S_table);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ThermalNeutronScatteringLaw_coherentElastic/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ThermalNeutronScatteringLaw_coherentElastic

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
