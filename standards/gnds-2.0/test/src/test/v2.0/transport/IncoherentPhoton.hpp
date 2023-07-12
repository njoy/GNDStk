
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_INCOHERENTPHOTON
#define TEST_V2_0_TRANSPORT_INCOHERENTPHOTON

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class IncoherentPhoton
// -----------------------------------------------------------------------------

class IncoherentPhoton :
   public Component<transport::IncoherentPhoton>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "IncoherentPhoton"; }
   static auto NODENAME() { return "incoherentPhoton"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{}
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment"
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

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment \
   )

   // default
   IncoherentPhoton() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from node
   explicit IncoherentPhoton(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   IncoherentPhoton(const IncoherentPhoton &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment)
   {
      Component::finish(other);
   }

   // move
   IncoherentPhoton(IncoherentPhoton &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   IncoherentPhoton &operator=(const IncoherentPhoton &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
      }
      return *this;
   }

   // move
   IncoherentPhoton &operator=(IncoherentPhoton &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/IncoherentPhoton/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class IncoherentPhoton

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
