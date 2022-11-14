
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

class Evaluated : public Component<gnds::Evaluated> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Evaluated"; }
   static auto FIELD() { return "evaluated"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
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
         --Child<gnds::Documentation>("documentation")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> label{this};
   Field<std::string> date{this};
   Field<std::string> library{this};
   Field<std::string> version{this};

   // children
   Field<gnds::Documentation> documentation{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->date, \
      this->library, \
      this->version, \
      this->documentation)

   // default
   Evaluated() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Evaluated(
      const wrapper<std::string> &label,
      const wrapper<std::string> &date = {},
      const wrapper<std::string> &library = {},
      const wrapper<std::string> &version = {},
      const wrapper<gnds::Documentation> &documentation = {}
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

   Evaluated &operator=(const Evaluated &) = default;
   Evaluated &operator=(Evaluated &&) = default;

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
