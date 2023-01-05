
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_DOCUMENTATION
#define CODE_V2_0_GNDS_DOCUMENTATION

#include "code/v2.0/gnds/Authors.hpp"
#include "code/v2.0/gnds/Dates.hpp"
#include "code/v2.0/gnds/Title.hpp"
#include "code/v2.0/gnds/Body.hpp"
#include "code/v2.0/gnds/EndfCompatible.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Documentation
// -----------------------------------------------------------------------------

class Documentation :
   public Component<gnds::Documentation>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Documentation"; }
   static auto FIELD() { return "documentation"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<gnds::Authors>("authors") |
         --Child<gnds::Dates>("dates") |
         --Child<gnds::Title>("title") |
         --Child<gnds::Body>("body") |
         --Child<gnds::EndfCompatible>("endfCompatible")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<gnds::Authors> authors{this};
   Field<gnds::Dates> dates{this};
   Field<gnds::Title> title{this};
   Field<gnds::Body> body{this};
   Field<gnds::EndfCompatible> endfCompatible{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->authors, \
      this->dates, \
      this->title, \
      this->body, \
      this->endfCompatible)

   // default
   Documentation() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Documentation(
      const wrapper<gnds::Authors> &authors,
      const wrapper<gnds::Dates> &dates = {},
      const wrapper<gnds::Title> &title = {},
      const wrapper<gnds::Body> &body = {},
      const wrapper<gnds::EndfCompatible> &endfCompatible = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      authors(this,authors),
      dates(this,dates),
      title(this,title),
      body(this,body),
      endfCompatible(this,endfCompatible)
   {
      Component::finish();
   }

   // from node
   explicit Documentation(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Documentation(const Documentation &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      authors(this,other.authors),
      dates(this,other.dates),
      title(this,other.title),
      body(this,other.body),
      endfCompatible(this,other.endfCompatible)
   {
      Component::finish(other);
   }

   // move
   Documentation(Documentation &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      authors(this,std::move(other.authors)),
      dates(this,std::move(other.dates)),
      title(this,std::move(other.title)),
      body(this,std::move(other.body)),
      endfCompatible(this,std::move(other.endfCompatible))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Documentation &operator=(const Documentation &) = default;
   Documentation &operator=(Documentation &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/Documentation/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Documentation

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
