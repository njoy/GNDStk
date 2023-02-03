
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_REDUCED_POLYNOMIAL1D
#define ALPHA_V2_0_REDUCED_POLYNOMIAL1D

#include "alpha/v2.0/general/Axes.hpp"
#include "alpha/v2.0/general/Values.hpp"

namespace alpha {
namespace v2_0 {
namespace reduced {

// -----------------------------------------------------------------------------
// reduced::
// class Polynomial1d
// -----------------------------------------------------------------------------

class Polynomial1d :
   public Component<reduced::Polynomial1d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "reduced"; }
   static auto CLASS() { return "Polynomial1d"; }
   static auto FIELD() { return "polynomial1d"; }

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

         // children
         --Child<general::Axes>
            ("axes") |
         --Child<general::Values>
            ("values")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<double> domainMin{this};
   Field<double> domainMax{this};

   // children
   Field<general::Axes>
      axes{this};
   Field<general::Values>
      values{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->domainMin, \
      this->domainMax, \
      this->axes, \
      this->values)

   // default
   Polynomial1d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Polynomial1d(
      const wrapper<double>
         &domainMin,
      const wrapper<double>
         &domainMax = {},
      const wrapper<general::Axes>
         &axes = {},
      const wrapper<general::Values>
         &values = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      domainMin(this,domainMin),
      domainMax(this,domainMax),
      axes(this,axes),
      values(this,values)
   {
      Component::finish();
   }

   // from node
   explicit Polynomial1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Polynomial1d(const Polynomial1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      domainMin(this,other.domainMin),
      domainMax(this,other.domainMax),
      axes(this,other.axes),
      values(this,other.values)
   {
      Component::finish(other);
   }

   // move
   Polynomial1d(Polynomial1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      domainMin(this,std::move(other.domainMin)),
      domainMax(this,std::move(other.domainMax)),
      axes(this,std::move(other.axes)),
      values(this,std::move(other.values))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Polynomial1d &operator=(const Polynomial1d &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         domainMin = other.domainMin;
         domainMax = other.domainMax;
         axes = other.axes;
         values = other.values;
      }
      return *this;
   }

   // move
   Polynomial1d &operator=(Polynomial1d &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         domainMin = std::move(other.domainMin);
         domainMax = std::move(other.domainMax);
         axes = std::move(other.axes);
         values = std::move(other.values);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/reduced/Polynomial1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Polynomial1d

} // namespace reduced
} // namespace v2_0
} // namespace alpha

#endif
