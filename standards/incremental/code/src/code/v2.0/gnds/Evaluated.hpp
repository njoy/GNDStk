
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_EVALUATED
#define CODE_V2_0_GNDS_EVALUATED

#include "code/v2.0/gnds/Documentation.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Evaluated
// -----------------------------------------------------------------------------

class Evaluated :
   public Component<gnds::Evaluated>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Evaluated"; }
   static auto NODENAME() { return "evaluated"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("date") |
         std::string{}
            / Meta<>("library") |
         std::string{}
            / Meta<>("version") |

         // children
         --Child<gnds::Documentation>
            ("documentation")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "date",
         "library",
         "version",
         "documentation"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "date",
         "library",
         "version",
         "documentation"
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
      date{this};
   Field<std::string>
      library{this};
   Field<std::string>
      version{this};

   // children
   Field<gnds::Documentation>
      documentation{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->date, \
      this->library, \
      this->version, \
      this->documentation \
   )

   // default
   Evaluated() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Evaluated(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &date = {},
      const wrapper<std::string>
         &library = {},
      const wrapper<std::string>
         &version = {},
      const wrapper<gnds::Documentation>
         &documentation = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      date(this,date),
      library(this,library),
      version(this,version),
      documentation(this,documentation)
   {
      Component::finish();
   }

   // from node
   explicit Evaluated(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Evaluated(const Evaluated &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      date(this,other.date),
      library(this,other.library),
      version(this,other.version),
      documentation(this,other.documentation)
   {
      Component::finish(other);
   }

   // move
   Evaluated(Evaluated &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      date(this,std::move(other.date)),
      library(this,std::move(other.library)),
      version(this,std::move(other.version)),
      documentation(this,std::move(other.documentation))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Evaluated &operator=(const Evaluated &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         date = other.date;
         library = other.library;
         version = other.version;
         documentation = other.documentation;
      }
      return *this;
   }

   // move
   Evaluated &operator=(Evaluated &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         date = std::move(other.date);
         library = std::move(other.library);
         version = std::move(other.version);
         documentation = std::move(other.documentation);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/Evaluated/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Evaluated

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
