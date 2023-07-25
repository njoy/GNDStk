
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_SELFSCATTERINGKERNEL
#define GNDS_V2_0_GENERAL_SELFSCATTERINGKERNEL

#include "gnds/v2.0/general/Gridded3d.hpp"
#include "gnds/v2.0/general/SCTApproximation.hpp"
#include "gnds/v2.0/general/FreeGasApproximation.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class SelfScatteringKernel
// -----------------------------------------------------------------------------

class SelfScatteringKernel :
   public Component<general::SelfScatteringKernel>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "SelfScatteringKernel"; }
   static auto NODENAME() { return "selfScatteringKernel"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<bool>{}
            / Meta<>("symmetric") |

         // children
         --Child<std::optional<general::Gridded3d>>
            ("gridded3d") |
         --Child<std::optional<general::SCTApproximation>>
            ("SCTApproximation") |
         --Child<std::optional<general::FreeGasApproximation>>
            ("freeGasApproximation")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "symmetric",
         "gridded3d",
         "SCTApproximation",
         "freeGasApproximation"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "symmetric",
         "gridded3d",
         "sctapproximation",
         "free_gas_approximation"
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
   Field<std::optional<bool>>
      symmetric{this};

   // children
   Field<std::optional<general::Gridded3d>>
      gridded3d{this};
   Field<std::optional<general::SCTApproximation>>
      SCTApproximation{this};
   Field<std::optional<general::FreeGasApproximation>>
      freeGasApproximation{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->symmetric, \
      this->gridded3d, \
      this->SCTApproximation, \
      this->freeGasApproximation \
   )

   // default
   SelfScatteringKernel() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit SelfScatteringKernel(
      const wrapper<std::optional<bool>>
         &symmetric,
      const wrapper<std::optional<general::Gridded3d>>
         &gridded3d = {},
      const wrapper<std::optional<general::SCTApproximation>>
         &SCTApproximation = {},
      const wrapper<std::optional<general::FreeGasApproximation>>
         &freeGasApproximation = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      symmetric(this,symmetric),
      gridded3d(this,gridded3d),
      SCTApproximation(this,SCTApproximation),
      freeGasApproximation(this,freeGasApproximation)
   {
      Component::finish();
   }

   // from node
   explicit SelfScatteringKernel(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   SelfScatteringKernel(const SelfScatteringKernel &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      symmetric(this,other.symmetric),
      gridded3d(this,other.gridded3d),
      SCTApproximation(this,other.SCTApproximation),
      freeGasApproximation(this,other.freeGasApproximation)
   {
      Component::finish(other);
   }

   // move
   SelfScatteringKernel(SelfScatteringKernel &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      symmetric(this,std::move(other.symmetric)),
      gridded3d(this,std::move(other.gridded3d)),
      SCTApproximation(this,std::move(other.SCTApproximation)),
      freeGasApproximation(this,std::move(other.freeGasApproximation))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   SelfScatteringKernel &operator=(const SelfScatteringKernel &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         symmetric = other.symmetric;
         gridded3d = other.gridded3d;
         SCTApproximation = other.SCTApproximation;
         freeGasApproximation = other.freeGasApproximation;
      }
      return *this;
   }

   // move
   SelfScatteringKernel &operator=(SelfScatteringKernel &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         symmetric = std::move(other.symmetric);
         gridded3d = std::move(other.gridded3d);
         SCTApproximation = std::move(other.SCTApproximation);
         freeGasApproximation = std::move(other.freeGasApproximation);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/SelfScatteringKernel/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class SelfScatteringKernel

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
