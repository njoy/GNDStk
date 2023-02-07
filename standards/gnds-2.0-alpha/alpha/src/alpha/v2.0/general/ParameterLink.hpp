
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_PARAMETERLINK
#define ALPHA_V2_0_GENERAL_PARAMETERLINK

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ParameterLink
// -----------------------------------------------------------------------------

class ParameterLink :
   public Component<general::ParameterLink>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ParameterLink"; }
   static auto FIELD() { return "parameterLink"; }

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
            / Meta<>("href") |
         std::optional<int>{}
            / Meta<>("nParameters") |
         std::optional<int>{}
            / Meta<>("matrixStartIndex")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<std::string> href{this};
   Field<std::optional<int>> nParameters{this};
   Field<std::optional<int>> matrixStartIndex{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->href, \
      this->nParameters, \
      this->matrixStartIndex \
   )

   // default
   ParameterLink() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ParameterLink(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &href = {},
      const wrapper<std::optional<int>>
         &nParameters = {},
      const wrapper<std::optional<int>>
         &matrixStartIndex = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      href(this,href),
      nParameters(this,nParameters),
      matrixStartIndex(this,matrixStartIndex)
   {
      Component::finish();
   }

   // from node
   explicit ParameterLink(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ParameterLink(const ParameterLink &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      href(this,other.href),
      nParameters(this,other.nParameters),
      matrixStartIndex(this,other.matrixStartIndex)
   {
      Component::finish(other);
   }

   // move
   ParameterLink(ParameterLink &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      href(this,std::move(other.href)),
      nParameters(this,std::move(other.nParameters)),
      matrixStartIndex(this,std::move(other.matrixStartIndex))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ParameterLink &operator=(const ParameterLink &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         href = other.href;
         nParameters = other.nParameters;
         matrixStartIndex = other.matrixStartIndex;
      }
      return *this;
   }

   // move
   ParameterLink &operator=(ParameterLink &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         href = std::move(other.href);
         nParameters = std::move(other.nParameters);
         matrixStartIndex = std::move(other.matrixStartIndex);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ParameterLink/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ParameterLink

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
