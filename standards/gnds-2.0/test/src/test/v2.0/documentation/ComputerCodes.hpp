
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_COMPUTERCODES
#define TEST_V2_0_DOCUMENTATION_COMPUTERCODES

#include "test/v2.0/documentation/ComputerCode.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class ComputerCodes
// -----------------------------------------------------------------------------

class ComputerCodes :
   public Component<documentation::ComputerCodes>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "ComputerCodes"; }
   static auto NODENAME() { return "computerCodes"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<documentation::ComputerCode>
            ("computerCode")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "computerCode"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "computer_code"
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
   Field<std::vector<documentation::ComputerCode>>
      computerCode{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->computerCode \
   )

   // default
   ComputerCodes() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ComputerCodes(
      const wrapper<std::vector<documentation::ComputerCode>>
         &computerCode
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      computerCode(this,computerCode)
   {
      Component::finish();
   }

   // from node
   explicit ComputerCodes(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ComputerCodes(const ComputerCodes &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      computerCode(this,other.computerCode)
   {
      Component::finish(other);
   }

   // move
   ComputerCodes(ComputerCodes &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      computerCode(this,std::move(other.computerCode))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ComputerCodes &operator=(const ComputerCodes &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         computerCode = other.computerCode;
      }
      return *this;
   }

   // move
   ComputerCodes &operator=(ComputerCodes &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         computerCode = std::move(other.computerCode);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/ComputerCodes/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ComputerCodes

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif
