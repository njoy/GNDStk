
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_REACTION
#define ALPHA_V2_0_GENERAL_REACTION

#include "alpha/v2.0/general/CrossSection.hpp"
#include "alpha/v2.0/general/OutputChannel.hpp"
#include "alpha/v2.0/general/DoubleDifferentialCrossSection.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Reaction
// -----------------------------------------------------------------------------

class Reaction :
   public Component<general::Reaction>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Reaction"; }
   static auto FIELD() { return "reaction"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         int{}
            / Meta<>("ENDF_MT") |
         std::optional<std::string>{}
            / Meta<>("fissionGenre") |

         // children
         --Child<general::CrossSection>
            ("crossSection") |
         --Child<general::OutputChannel>
            ("outputChannel") |
         --Child<std::optional<general::DoubleDifferentialCrossSection>>
            ("doubleDifferentialCrossSection")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "ENDF_MT",
         "fissionGenre",
         "crossSection",
         "outputChannel",
         "doubleDifferentialCrossSection"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "endf_mt",
         "fission_genre",
         "cross_section",
         "output_channel",
         "double_differential_cross_section"
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
   Field<std::string>
      label{this};
   Field<int>
      ENDF_MT{this};
   Field<std::optional<std::string>>
      fissionGenre{this};

   // children
   Field<general::CrossSection>
      crossSection{this};
   Field<general::OutputChannel>
      outputChannel{this};
   Field<std::optional<general::DoubleDifferentialCrossSection>>
      doubleDifferentialCrossSection{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->ENDF_MT, \
      this->fissionGenre, \
      this->crossSection, \
      this->outputChannel, \
      this->doubleDifferentialCrossSection \
   )

   // default
   Reaction() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Reaction(
      const wrapper<std::string>
         &label,
      const wrapper<int>
         &ENDF_MT = {},
      const wrapper<std::optional<std::string>>
         &fissionGenre = {},
      const wrapper<general::CrossSection>
         &crossSection = {},
      const wrapper<general::OutputChannel>
         &outputChannel = {},
      const wrapper<std::optional<general::DoubleDifferentialCrossSection>>
         &doubleDifferentialCrossSection = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      ENDF_MT(this,ENDF_MT),
      fissionGenre(this,fissionGenre),
      crossSection(this,crossSection),
      outputChannel(this,outputChannel),
      doubleDifferentialCrossSection(this,doubleDifferentialCrossSection)
   {
      Component::finish();
   }

   // from node
   explicit Reaction(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Reaction(const Reaction &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      ENDF_MT(this,other.ENDF_MT),
      fissionGenre(this,other.fissionGenre),
      crossSection(this,other.crossSection),
      outputChannel(this,other.outputChannel),
      doubleDifferentialCrossSection(this,other.doubleDifferentialCrossSection)
   {
      Component::finish(other);
   }

   // move
   Reaction(Reaction &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      ENDF_MT(this,std::move(other.ENDF_MT)),
      fissionGenre(this,std::move(other.fissionGenre)),
      crossSection(this,std::move(other.crossSection)),
      outputChannel(this,std::move(other.outputChannel)),
      doubleDifferentialCrossSection(this,std::move(other.doubleDifferentialCrossSection))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Reaction &operator=(const Reaction &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         ENDF_MT = other.ENDF_MT;
         fissionGenre = other.fissionGenre;
         crossSection = other.crossSection;
         outputChannel = other.outputChannel;
         doubleDifferentialCrossSection = other.doubleDifferentialCrossSection;
      }
      return *this;
   }

   // move
   Reaction &operator=(Reaction &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         ENDF_MT = std::move(other.ENDF_MT);
         fissionGenre = std::move(other.fissionGenre);
         crossSection = std::move(other.crossSection);
         outputChannel = std::move(other.outputChannel);
         doubleDifferentialCrossSection = std::move(other.doubleDifferentialCrossSection);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Reaction/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Reaction

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
