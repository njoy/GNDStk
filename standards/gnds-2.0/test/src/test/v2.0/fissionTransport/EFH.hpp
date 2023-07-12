
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_FISSIONTRANSPORT_EFH
#define TEST_V2_0_FISSIONTRANSPORT_EFH

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace fissionTransport {

// -----------------------------------------------------------------------------
// fissionTransport::
// class EFH
// -----------------------------------------------------------------------------

class EFH :
   public Component<fissionTransport::EFH>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "fissionTransport"; }
   static auto CLASS() { return "EFH"; }
   static auto NODENAME() { return "EFH"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("unit") |
         Float64{}
            / Meta<>("value")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "unit",
         "value"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "unit",
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
   Field<XMLName>
      unit{this};
   Field<Float64>
      value{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->unit, \
      this->value \
   )

   // default
   EFH() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit EFH(
      const wrapper<XMLName>
         &unit,
      const wrapper<Float64>
         &value = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      unit(this,unit),
      value(this,value)
   {
      Component::finish();
   }

   // from node
   explicit EFH(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   EFH(const EFH &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      unit(this,other.unit),
      value(this,other.value)
   {
      Component::finish(other);
   }

   // move
   EFH(EFH &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      unit(this,std::move(other.unit)),
      value(this,std::move(other.value))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   EFH &operator=(const EFH &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         unit = other.unit;
         value = other.value;
      }
      return *this;
   }

   // move
   EFH &operator=(EFH &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         unit = std::move(other.unit);
         value = std::move(other.value);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/fissionTransport/EFH/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class EFH

} // namespace fissionTransport
} // namespace v2_0
} // namespace test

#endif
