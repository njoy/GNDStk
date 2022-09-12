
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_EXFORDATASET
#define TEST_V2_0_DOCUMENTATION_EXFORDATASET

#include "test/v2.0/documentation/CovarianceScript.hpp"
#include "test/v2.0/documentation/CorrectionScript.hpp"
#include "test/v2.0/documentation/Note.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class ExforDataSet
// -----------------------------------------------------------------------------

class ExforDataSet : public Component<documentation::ExforDataSet> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "ExforDataSet"; }
   static auto FIELD() { return "exforDataSet"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("subentry") |
         std::string{}
            / Meta<>("retrievalDate") |
         // children
         std::optional<documentation::CovarianceScript>{}
            / --Child<>("covarianceScript") |
         std::optional<documentation::CorrectionScript>{}
            / --Child<>("correctionScript") |
         std::optional<documentation::Note>{}
            / --Child<>("note")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> subentry{this};
   Field<std::string> retrievalDate{this};

   // children
   Field<std::optional<documentation::CovarianceScript>> covarianceScript{this};
   Field<std::optional<documentation::CorrectionScript>> correctionScript{this};
   Field<std::optional<documentation::Note>> note{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->subentry, \
      this->retrievalDate, \
      this->covarianceScript, \
      this->correctionScript, \
      this->note)

   // default, and from fields
   explicit ExforDataSet(
      const wrapper<XMLName> &subentry = {},
      const wrapper<std::string> &retrievalDate = {},
      const wrapper<std::optional<documentation::CovarianceScript>> &covarianceScript = {},
      const wrapper<std::optional<documentation::CorrectionScript>> &correctionScript = {},
      const wrapper<std::optional<documentation::Note>> &note = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      subentry(this,subentry),
      retrievalDate(this,retrievalDate),
      covarianceScript(this,covarianceScript),
      correctionScript(this,correctionScript),
      note(this,note)
   {
      Component::finish();
   }

   // from node
   explicit ExforDataSet(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ExforDataSet(const ExforDataSet &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   ExforDataSet(ExforDataSet &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ExforDataSet &operator=(const ExforDataSet &) = default;
   ExforDataSet &operator=(ExforDataSet &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/ExforDataSet/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ExforDataSet

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif