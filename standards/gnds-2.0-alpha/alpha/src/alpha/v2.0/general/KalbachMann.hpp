
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_KALBACHMANN
#define ALPHA_V2_0_GENERAL_KALBACHMANN

#include "alpha/v2.0/general/F.hpp"
#include "alpha/v2.0/general/R.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class KalbachMann
// -----------------------------------------------------------------------------

class KalbachMann :
   public Component<general::KalbachMann>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "KalbachMann"; }
   static auto FIELD() { return "KalbachMann"; }

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
            / Meta<>("productFrame") |

         // children
         --Child<std::optional<general::F>>
            ("f") |
         --Child<std::optional<general::R>>
            ("r")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "productFrame",
         "f",
         "r"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "product_frame",
         "f",
         "r"
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
   Field<std::string>
      productFrame{this};

   // children
   Field<std::optional<general::F>>
      f{this};
   Field<std::optional<general::R>>
      r{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->productFrame, \
      this->f, \
      this->r \
   )

   // default
   KalbachMann() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit KalbachMann(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &productFrame = {},
      const wrapper<std::optional<general::F>>
         &f = {},
      const wrapper<std::optional<general::R>>
         &r = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      productFrame(this,productFrame),
      f(this,f),
      r(this,r)
   {
      Component::finish();
   }

   // from node
   explicit KalbachMann(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   KalbachMann(const KalbachMann &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      productFrame(this,other.productFrame),
      f(this,other.f),
      r(this,other.r)
   {
      Component::finish(other);
   }

   // move
   KalbachMann(KalbachMann &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      productFrame(this,std::move(other.productFrame)),
      f(this,std::move(other.f)),
      r(this,std::move(other.r))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   KalbachMann &operator=(const KalbachMann &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         productFrame = other.productFrame;
         f = other.f;
         r = other.r;
      }
      return *this;
   }

   // move
   KalbachMann &operator=(KalbachMann &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         productFrame = std::move(other.productFrame);
         f = std::move(other.f);
         r = std::move(other.r);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/KalbachMann/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class KalbachMann

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
