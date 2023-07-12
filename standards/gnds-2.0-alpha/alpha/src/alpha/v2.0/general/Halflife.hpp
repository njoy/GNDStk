
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_HALFLIFE
#define ALPHA_V2_0_GENERAL_HALFLIFE

#include "alpha/v2.0/general/String.hpp"
#include "alpha/v2.0/general/Double.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Halflife
// -----------------------------------------------------------------------------

class Halflife :
   public Component<general::Halflife>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Halflife"; }
   static auto NODENAME() { return "halflife"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::String>>
            ("string") |
         --Child<std::optional<general::Double>>
            ("double")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "string",
         "Double"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "string",
         "double"
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
   Field<std::optional<general::String>>
      string{this};
   Field<std::optional<general::Double>>
      Double{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->string, \
      this->Double \
   )

   // default
   Halflife() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Halflife(
      const wrapper<std::optional<general::String>>
         &string,
      const wrapper<std::optional<general::Double>>
         &Double = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      string(this,string),
      Double(this,Double)
   {
      Component::finish();
   }

   // from node
   explicit Halflife(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Halflife(const Halflife &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      string(this,other.string),
      Double(this,other.Double)
   {
      Component::finish(other);
   }

   // move
   Halflife(Halflife &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      string(this,std::move(other.string)),
      Double(this,std::move(other.Double))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Halflife &operator=(const Halflife &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         string = other.string;
         Double = other.Double;
      }
      return *this;
   }

   // move
   Halflife &operator=(Halflife &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         string = std::move(other.string);
         Double = std::move(other.Double);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Halflife/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Halflife

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
