
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

class Documentation : public Component<gnds::Documentation> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Documentation"; }
   static auto FIELD() { return "documentation"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
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
      this->authors, \
      this->dates, \
      this->title, \
      this->body, \
      this->endfCompatible)

   // default
   Documentation() :
      GNDSTK_COMPONENT(BlockData{})
   {
      std::cout << "ctor: Documentation: default" << std::endl;
      Component::finish();
   }

   // from fields
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
      std::cout << "ctor: Documentation: fields" << std::endl;
      Component::finish();
   }

   // from node
   explicit Documentation(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      std::cout << "ctor: Documentation: node" << std::endl;
      Component::finish(node);
   }

   // copy
   Documentation(const Documentation &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      std::cout << "ctor: Documentation: copy" << std::endl;
      *this = other;
      Component::finish(other);
   }

   // move
   Documentation(Documentation &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      std::cout << "ctor: Documentation: move" << std::endl;
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Documentation &operator=(const Documentation &other)
   {
      if (this != &other) {
         authors = other.authors;
         dates = other.dates;
         title = other.title;
         body = other.body;
         endfCompatible = other.endfCompatible;
      }
      std::cout << "assign: Documentation: copy" << std::endl;
      return *this;
   }

   // move
   Documentation &operator=(Documentation &&other)
   {
      if (this != &other) {
         authors = std::move(other.authors);
         dates = std::move(other.dates);
         title = std::move(other.title);
         body = std::move(other.body);
         endfCompatible = std::move(other.endfCompatible);
      }
      std::cout << "assign: Documentation: move" << std::endl;
      return *this;
   }

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
