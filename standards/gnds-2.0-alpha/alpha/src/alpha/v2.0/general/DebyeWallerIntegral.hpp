
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_DEBYEWALLERINTEGRAL
#define ALPHA_V2_0_GENERAL_DEBYEWALLERINTEGRAL

#include "alpha/v2.0/general/XYs1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class DebyeWallerIntegral
// -----------------------------------------------------------------------------

class DebyeWallerIntegral :
   public Component<general::DebyeWallerIntegral>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "DebyeWallerIntegral"; }
   static auto FIELD() { return "DebyeWallerIntegral"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::XYs1d>
            ("XYs1d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "XYs1d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "xys1d"
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
   Field<general::XYs1d>
      XYs1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->XYs1d \
   )

   // default
   DebyeWallerIntegral() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DebyeWallerIntegral(
      const wrapper<general::XYs1d>
         &XYs1d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d)
   {
      Component::finish();
   }

   // from node
   explicit DebyeWallerIntegral(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DebyeWallerIntegral(const DebyeWallerIntegral &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs1d(this,other.XYs1d)
   {
      Component::finish(other);
   }

   // move
   DebyeWallerIntegral(DebyeWallerIntegral &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs1d(this,std::move(other.XYs1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   DebyeWallerIntegral &operator=(const DebyeWallerIntegral &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         XYs1d = other.XYs1d;
      }
      return *this;
   }

   // move
   DebyeWallerIntegral &operator=(DebyeWallerIntegral &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         XYs1d = std::move(other.XYs1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/DebyeWallerIntegral/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DebyeWallerIntegral

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
