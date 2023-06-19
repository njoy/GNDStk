
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COVARIANCE_COVARIANCESECTIONS
#define TEST_V2_0_COVARIANCE_COVARIANCESECTIONS

#include "test/v2.0/covariance/CovarianceSection.hpp"

namespace test {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class CovarianceSections
// -----------------------------------------------------------------------------

class CovarianceSections :
   public Component<covariance::CovarianceSections>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "CovarianceSections"; }
   static auto NODENAME() { return "covarianceSections"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<std::optional<covariance::CovarianceSection>>
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
   Field<std::optional<std::vector<covariance::CovarianceSection>>>
      covarianceSection{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->covarianceSection \
   )

   // default
   CovarianceSections() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CovarianceSections(
      const wrapper<std::optional<std::vector<covariance::CovarianceSection>>>
         &covarianceSection
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      covarianceSection(this,covarianceSection)
   {
      Component::finish();
   }

   // from node
   explicit CovarianceSections(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CovarianceSections(const CovarianceSections &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      covarianceSection(this,other.covarianceSection)
   {
      Component::finish(other);
   }

   // move
   CovarianceSections(CovarianceSections &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
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

   #include "test/v2.0/covariance/CovarianceSections/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CovarianceSections

} // namespace covariance
} // namespace v2_0
} // namespace test

#endif
