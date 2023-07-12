
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_RESOLVED
#define ALPHA_V2_0_GENERAL_RESOLVED

#include "alpha/v2.0/general/BreitWigner.hpp"
#include "alpha/v2.0/general/RMatrix.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Resolved
// -----------------------------------------------------------------------------

class Resolved :
   public Component<general::Resolved>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Resolved"; }
   static auto NODENAME() { return "resolved"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         double{}
            / Meta<>("domainMin") |
         double{}
            / Meta<>("domainMax") |
         std::string{}
            / Meta<>("domainUnit") |

         // children
         --Child<std::optional<general::BreitWigner>>
            ("BreitWigner") |
         --Child<std::optional<general::RMatrix>>
            ("RMatrix")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "domainMin",
         "domainMax",
         "domainUnit",
         "BreitWigner",
         "RMatrix"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "domain_min",
         "domain_max",
         "domain_unit",
         "breit_wigner",
         "rmatrix"
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
      domainMin{this};
   Field<double>
      domainMax{this};
   Field<std::string>
      domainUnit{this};

   // children
   Field<std::optional<general::BreitWigner>>
      BreitWigner{this};
   Field<std::optional<general::RMatrix>>
      RMatrix{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->domainMin, \
      this->domainMax, \
      this->domainUnit, \
      this->BreitWigner, \
      this->RMatrix \
   )

   // default
   Resolved() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Resolved(
      const wrapper<double>
         &domainMin,
      const wrapper<double>
         &domainMax = {},
      const wrapper<std::string>
         &domainUnit = {},
      const wrapper<std::optional<general::BreitWigner>>
         &BreitWigner = {},
      const wrapper<std::optional<general::RMatrix>>
         &RMatrix = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      domainMin(this,domainMin),
      domainMax(this,domainMax),
      domainUnit(this,domainUnit),
      BreitWigner(this,BreitWigner),
      RMatrix(this,RMatrix)
   {
      Component::finish();
   }

   // from node
   explicit Resolved(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Resolved(const Resolved &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      domainMin(this,other.domainMin),
      domainMax(this,other.domainMax),
      domainUnit(this,other.domainUnit),
      BreitWigner(this,other.BreitWigner),
      RMatrix(this,other.RMatrix)
   {
      Component::finish(other);
   }

   // move
   Resolved(Resolved &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      domainMin(this,std::move(other.domainMin)),
      domainMax(this,std::move(other.domainMax)),
      domainUnit(this,std::move(other.domainUnit)),
      BreitWigner(this,std::move(other.BreitWigner)),
      RMatrix(this,std::move(other.RMatrix))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Resolved &operator=(const Resolved &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         domainMin = other.domainMin;
         domainMax = other.domainMax;
         domainUnit = other.domainUnit;
         BreitWigner = other.BreitWigner;
         RMatrix = other.RMatrix;
      }
      return *this;
   }

   // move
   Resolved &operator=(Resolved &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         domainMin = std::move(other.domainMin);
         domainMax = std::move(other.domainMax);
         domainUnit = std::move(other.domainUnit);
         BreitWigner = std::move(other.BreitWigner);
         RMatrix = std::move(other.RMatrix);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Resolved/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Resolved

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
