
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_COVARIANCESECTIONS
#define GNDS_V2_0_GENERAL_COVARIANCESECTIONS

#include "GNDS/v2.0/general/CovarianceSection.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class CovarianceSections
// -----------------------------------------------------------------------------

class CovarianceSections :
   public Component<general::CovarianceSections>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "CovarianceSections"; }
   static auto NODENAME() { return "covarianceSections"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::CovarianceSection>
            ("covarianceSection")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "covarianceSection"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "covariance_section"
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
   Field<std::vector<general::CovarianceSection>>
      covarianceSection{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->covarianceSection \
   )

   // default
   CovarianceSections() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CovarianceSections(
      const wrapper<std::vector<general::CovarianceSection>>
         &covarianceSection
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      covarianceSection(this,covarianceSection)
   {
      Component::finish();
   }

   // from node
   explicit CovarianceSections(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CovarianceSections(const CovarianceSections &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      covarianceSection(this,other.covarianceSection)
   {
      Component::finish(other);
   }

   // move
   CovarianceSections(CovarianceSections &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      covarianceSection(this,std::move(other.covarianceSection))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   CovarianceSections &operator=(const CovarianceSections &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         covarianceSection = other.covarianceSection;
      }
      return *this;
   }

   // move
   CovarianceSections &operator=(CovarianceSections &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         covarianceSection = std::move(other.covarianceSection);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/CovarianceSections/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class CovarianceSections

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
