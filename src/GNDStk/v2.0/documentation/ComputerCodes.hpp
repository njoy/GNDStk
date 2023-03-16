
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_DOCUMENTATION_COMPUTERCODES
#define NJOY_GNDSTK_V2_0_DOCUMENTATION_COMPUTERCODES

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/documentation/ComputerCode.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// documentation::
// class ComputerCodes
// -----------------------------------------------------------------------------

namespace documentation {

class ComputerCodes : public Component<ComputerCodes> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "documentation"; }
   static auto className() { return "ComputerCodes"; }
   static auto GNDSName() { return "computerCodes"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         documentation::ComputerCode{}
            / ++Child<>("computerCode")
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
      // children
      std::vector<documentation::ComputerCode> computerCode;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // computerCode
   const std::vector<documentation::ComputerCode> &computerCode() const
      { return content.computerCode; }
   std::vector<documentation::ComputerCode> &computerCode()
      { return content.computerCode; }

   // computerCode(index)
   const documentation::ComputerCode &computerCode(const std::size_t index) const
      { return getter(computerCode(), index, "computerCode"); }
   documentation::ComputerCode &computerCode(const std::size_t index)
      { return getter(computerCode(), index, "computerCode"); }

   // computerCode(label)
   const documentation::ComputerCode &computerCode(const std::string &label) const
      { return getter(computerCode(), label, "computerCode"); }
   documentation::ComputerCode &computerCode(const std::string &label)
      { return getter(computerCode(), label, "computerCode"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // computerCode(value)
   ComputerCodes &computerCode(const std::vector<documentation::ComputerCode> &obj)
      { computerCode() = obj; return *this; }

   // computerCode(index,value)
   ComputerCodes &computerCode(
      const std::size_t index,
      const documentation::ComputerCode &obj
   ) {
      computerCode(index) = obj; return *this;
   }

   // computerCode(label,value)
   ComputerCodes &computerCode(
      const std::string &label,
      const documentation::ComputerCode &obj
   ) {
      computerCode(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   ComputerCodes() :
      Component{
         BodyText{},
         content.computerCode
      }
   {
      Component::finish();
   }

   // copy
   ComputerCodes(const ComputerCodes &other) :
      Component{
         other,
         content.computerCode
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   ComputerCodes(ComputerCodes &&other) :
      Component{
         other,
         content.computerCode
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   ComputerCodes(const Node &node) :
      Component{
         BodyText{},
         content.computerCode
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit ComputerCodes(
      const std::vector<documentation::ComputerCode> &computerCode
   ) :
      Component{
         BodyText{},
         content.computerCode
      },
      content{
         computerCode
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   ComputerCodes &operator=(const ComputerCodes &) = default;

   // move
   ComputerCodes &operator=(ComputerCodes &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/documentation/ComputerCodes/src/custom.hpp"

}; // class ComputerCodes

} // namespace documentation
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
