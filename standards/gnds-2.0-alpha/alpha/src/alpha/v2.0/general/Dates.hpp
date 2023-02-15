
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_DATES
#define ALPHA_V2_0_GENERAL_DATES

#include "alpha/v2.0/general/Date.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Dates
// -----------------------------------------------------------------------------

class Dates :
   public Component<general::Dates>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Dates"; }
   static auto FIELD() { return "dates"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Date>
            ("date")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "date"
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
   Field<std::vector<general::Date>>
      date{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->date \
   )

   // default
   Dates() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Dates(
      const wrapper<std::vector<general::Date>>
         &date
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      date(this,date)
   {
      Component::finish();
   }

   // from node
   explicit Dates(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Dates(const Dates &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      date(this,other.date)
   {
      Component::finish(other);
   }

   // move
   Dates(Dates &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      date(this,std::move(other.date))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Dates &operator=(const Dates &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         date = other.date;
      }
      return *this;
   }

   // move
   Dates &operator=(Dates &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         date = std::move(other.date);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Dates/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Dates

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
