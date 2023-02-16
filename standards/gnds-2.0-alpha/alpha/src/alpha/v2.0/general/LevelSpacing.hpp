
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_LEVELSPACING
#define ALPHA_V2_0_GENERAL_LEVELSPACING

#include "alpha/v2.0/general/XYs1d.hpp"
#include "alpha/v2.0/general/Constant1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class LevelSpacing
// -----------------------------------------------------------------------------

class LevelSpacing :
   public Component<general::LevelSpacing>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "LevelSpacing"; }
   static auto FIELD() { return "levelSpacing"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::XYs1d>>
            ("XYs1d") |
         --Child<std::optional<general::Constant1d>>
            ("constant1d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "XYs1d",
         "constant1d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "xys1d",
         "constant1d"
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
   Field<std::optional<general::XYs1d>>
      XYs1d{this};
   Field<std::optional<general::Constant1d>>
      constant1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->XYs1d, \
      this->constant1d \
   )

   // default
   LevelSpacing() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit LevelSpacing(
      const wrapper<std::optional<general::XYs1d>>
         &XYs1d,
      const wrapper<std::optional<general::Constant1d>>
         &constant1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d),
      constant1d(this,constant1d)
   {
      Component::finish();
   }

   // from node
   explicit LevelSpacing(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   LevelSpacing(const LevelSpacing &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs1d(this,other.XYs1d),
      constant1d(this,other.constant1d)
   {
      Component::finish(other);
   }

   // move
   LevelSpacing(LevelSpacing &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs1d(this,std::move(other.XYs1d)),
      constant1d(this,std::move(other.constant1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   LevelSpacing &operator=(const LevelSpacing &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         XYs1d = other.XYs1d;
         constant1d = other.constant1d;
      }
      return *this;
   }

   // move
   LevelSpacing &operator=(LevelSpacing &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         XYs1d = std::move(other.XYs1d);
         constant1d = std::move(other.constant1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/LevelSpacing/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class LevelSpacing

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
