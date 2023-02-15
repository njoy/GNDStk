
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_DATE
#define ALPHA_V2_0_GENERAL_DATE

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Date
// -----------------------------------------------------------------------------

class Date :
   public Component<general::Date>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Date"; }
   static auto FIELD() { return "date"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("value") |
         std::string{}
            / Meta<>("dateType")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "value",
         "dateType"
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
      value{this};
   Field<std::string>
      dateType{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->value, \
      this->dateType \
   )

   // default
   Date() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Date(
      const wrapper<std::string>
         &value,
      const wrapper<std::string>
         &dateType = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      value(this,value),
      dateType(this,dateType)
   {
      Component::finish();
   }

   // from node
   explicit Date(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Date(const Date &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      value(this,other.value),
      dateType(this,other.dateType)
   {
      Component::finish(other);
   }

   // move
   Date(Date &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      value(this,std::move(other.value)),
      dateType(this,std::move(other.dateType))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Date &operator=(const Date &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         value = other.value;
         dateType = other.dateType;
      }
      return *this;
   }

   // move
   Date &operator=(Date &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         value = std::move(other.value);
         dateType = std::move(other.dateType);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Date/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Date

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
