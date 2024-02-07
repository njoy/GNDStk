
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_CONVERSION
#define GNDS_V2_0_GENERAL_CONVERSION

#include "GNDS/v2.0/key.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Conversion
// -----------------------------------------------------------------------------

class Conversion :
   public Component<general::Conversion>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Conversion"; }
   static auto NODENAME() { return "conversion"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("flags") |
         std::string{}
            / Meta<>("href")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "flags",
         "href"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "flags",
         "href"
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
      flags{this};
   Field<std::string>
      href{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->flags, \
      this->href \
   )

   // default
   Conversion() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Conversion(
      const wrapper<std::string>
         &flags,
      const wrapper<std::string>
         &href = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      flags(this,flags),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit Conversion(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Conversion(const Conversion &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      flags(this,other.flags),
      href(this,other.href)
   {
      Component::finish(other);
   }

   // move
   Conversion(Conversion &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      flags(this,std::move(other.flags)),
      href(this,std::move(other.href))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Conversion &operator=(const Conversion &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         flags = other.flags;
         href = other.href;
      }
      return *this;
   }

   // move
   Conversion &operator=(Conversion &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         flags = std::move(other.flags);
         href = std::move(other.href);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/Conversion/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Conversion

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif