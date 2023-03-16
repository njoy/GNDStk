
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_DATE
#define CODE_V2_0_GNDS_DATE

#include "code/v2.0/key.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Date
// -----------------------------------------------------------------------------

class Date :
   public Component<gnds::Date>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Date"; }
   static auto NODENAME() { return "date"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("value") |
         enums::DateType{}
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

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "value",
         "date_type"
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
   Field<enums::DateType>
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
      const wrapper<enums::DateType>
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

   #include "code/v2.0/gnds/Date/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Date

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
