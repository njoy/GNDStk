
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_DATE
#define TEST_V2_0_DOCUMENTATION_DATE

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class Date
// -----------------------------------------------------------------------------

class Date :
   public Component<documentation::Date>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "Date"; }
   static auto NODENAME() { return "date"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         enums::DateType{}
            / Meta<>("dateType") |
         std::string{}
            / Meta<>("value")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "dateType",
         "value"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "date_type",
         "value"
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
   Field<enums::DateType>
      dateType{this};
   Field<std::string>
      value{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->dateType, \
      this->value \
   )

   // default
   Date() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Date(
      const wrapper<enums::DateType>
         &dateType,
      const wrapper<std::string>
         &value = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      dateType(this,dateType),
      value(this,value)
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
      dateType(this,other.dateType),
      value(this,other.value)
   {
      Component::finish(other);
   }

   // move
   Date(Date &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      dateType(this,std::move(other.dateType)),
      value(this,std::move(other.value))
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
         dateType = other.dateType;
         value = other.value;
      }
      return *this;
   }

   // move
   Date &operator=(Date &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         dateType = std::move(other.dateType);
         value = std::move(other.value);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/Date/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Date

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif
