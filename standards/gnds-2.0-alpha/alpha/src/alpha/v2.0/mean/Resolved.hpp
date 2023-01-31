
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_RESOLVED
#define ALPHA_V2_0_MEAN_RESOLVED

#include "alpha/v2.0/mean/BreitWigner.hpp"
#include "alpha/v2.0/mean/RMatrix.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class Resolved
// -----------------------------------------------------------------------------

class Resolved :
   public Component<mean::Resolved>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "Resolved"; }
   static auto FIELD() { return "resolved"; }

   // Core Interface multi-query to transfer information to/from Nodes
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
         --Child<std::optional<mean::BreitWigner>>("BreitWigner") |
         --Child<std::optional<mean::RMatrix>>("RMatrix")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<double> domainMin{this};
   Field<double> domainMax{this};
   Field<std::string> domainUnit{this};

   // children
   Field<std::optional<mean::BreitWigner>> BreitWigner{this};
   Field<std::optional<mean::RMatrix>> RMatrix{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->domainMin, \
      this->domainMax, \
      this->domainUnit, \
      this->BreitWigner, \
      this->RMatrix)

   // default
   Resolved() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Resolved(
      const wrapper<double> &domainMin,
      const wrapper<double> &domainMax = {},
      const wrapper<std::string> &domainUnit = {},
      const wrapper<std::optional<mean::BreitWigner>> &BreitWigner = {},
      const wrapper<std::optional<mean::RMatrix>> &RMatrix = {}
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

   Resolved &operator=(const Resolved &) = default;
   Resolved &operator=(Resolved &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/Resolved/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Resolved

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
