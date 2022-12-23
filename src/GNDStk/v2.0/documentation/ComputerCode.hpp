
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_DOCUMENTATION_COMPUTERCODE
#define NJOY_GNDSTK_V2_0_DOCUMENTATION_COMPUTERCODE

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/documentation/CodeRepo.hpp"
#include "GNDStk/v2.0/documentation/InputDecks.hpp"
#include "GNDStk/v2.0/documentation/OutputDecks.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// documentation::
// class ComputerCode
// -----------------------------------------------------------------------------

namespace documentation {

class ComputerCode : public Component<ComputerCode> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "documentation"; }
   static auto className() { return "ComputerCode"; }
   static auto GNDSName() { return "computerCode"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         UTF8Text{}
            / Meta<>("name") |
         XMLName{}
            / Meta<>("version") |
         // children
         std::optional<documentation::CodeRepo>{}
            / --Child<>("codeRepo") |
         std::optional<documentation::InputDecks>{}
            / --Child<>("inputDecks") |
         std::optional<documentation::OutputDecks>{}
            / --Child<>("outputDecks")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      UTF8Text name;
      XMLName version;
      // children
      std::optional<documentation::CodeRepo> codeRepo;
      std::optional<documentation::InputDecks> inputDecks;
      std::optional<documentation::OutputDecks> outputDecks;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // name
   const UTF8Text &name() const
      { return content.name; }
   UTF8Text &name()
      { return content.name; }

   // version
   const XMLName &version() const
      { return content.version; }
   XMLName &version()
      { return content.version; }

   // codeRepo
   const std::optional<documentation::CodeRepo> &codeRepo() const
      { return content.codeRepo; }
   std::optional<documentation::CodeRepo> &codeRepo()
      { return content.codeRepo; }

   // inputDecks
   const std::optional<documentation::InputDecks> &inputDecks() const
      { return content.inputDecks; }
   std::optional<documentation::InputDecks> &inputDecks()
      { return content.inputDecks; }

   // outputDecks
   const std::optional<documentation::OutputDecks> &outputDecks() const
      { return content.outputDecks; }
   std::optional<documentation::OutputDecks> &outputDecks()
      { return content.outputDecks; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // name(value)
   ComputerCode &name(const UTF8Text &obj)
      { name() = obj; return *this; }

   // version(value)
   ComputerCode &version(const XMLName &obj)
      { version() = obj; return *this; }

   // codeRepo(value)
   ComputerCode &codeRepo(const std::optional<documentation::CodeRepo> &obj)
      { codeRepo() = obj; return *this; }

   // inputDecks(value)
   ComputerCode &inputDecks(const std::optional<documentation::InputDecks> &obj)
      { inputDecks() = obj; return *this; }

   // outputDecks(value)
   ComputerCode &outputDecks(const std::optional<documentation::OutputDecks> &obj)
      { outputDecks() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   ComputerCode() :
      Component{
         BodyText{},
         content.name,
         content.version,
         content.codeRepo,
         content.inputDecks,
         content.outputDecks
      }
   {
      Component::finish();
   }

   // copy
   ComputerCode(const ComputerCode &other) :
      Component{
         other,
         content.name,
         content.version,
         content.codeRepo,
         content.inputDecks,
         content.outputDecks
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   ComputerCode(ComputerCode &&other) :
      Component{
         other,
         content.name,
         content.version,
         content.codeRepo,
         content.inputDecks,
         content.outputDecks
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   ComputerCode(const Node &node) :
      Component{
         BodyText{},
         content.name,
         content.version,
         content.codeRepo,
         content.inputDecks,
         content.outputDecks
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit ComputerCode(
      const UTF8Text &name,
      const XMLName &version,
      const std::optional<documentation::CodeRepo> &codeRepo,
      const std::optional<documentation::InputDecks> &inputDecks,
      const std::optional<documentation::OutputDecks> &outputDecks
   ) :
      Component{
         BodyText{},
         content.name,
         content.version,
         content.codeRepo,
         content.inputDecks,
         content.outputDecks
      },
      content{
         name,
         version,
         codeRepo,
         inputDecks,
         outputDecks
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   ComputerCode &operator=(const ComputerCode &) = default;

   // move
   ComputerCode &operator=(ComputerCode &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/documentation/ComputerCode/src/custom.hpp"

}; // class ComputerCode

} // namespace documentation
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
