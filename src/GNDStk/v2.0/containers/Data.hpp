
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_CONTAINERS_DATA
#define NJOY_GNDSTK_V2_0_CONTAINERS_DATA

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Data
// -----------------------------------------------------------------------------

namespace containers {

class Data : public Component<Data,true> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Data"; }
   static auto GNDSName() { return "data"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         Defaulted<UTF8Text>{"whiteSpace"}
            / Meta<>("sep")
      ;
   }

public:

   using Component::construct;
   using BodyText::operator=;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const UTF8Text sep = "whiteSpace";
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      Defaulted<UTF8Text> sep{"whiteSpace"};
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // sep
   const Defaulted<UTF8Text> &sep() const
      { return content.sep; }
   Defaulted<UTF8Text> &sep()
      { return content.sep; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // sep(value)
   Data &sep(const Defaulted<UTF8Text> &obj)
      { content.sep = obj; return *this; }
   Data &sep(const std::optional<UTF8Text> &obj)
      { content.sep = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Data() :
      Component{
         BodyText{},
         content.sep
      }
   {
      Component::finish();
   }

   // copy
   Data(const Data &other) :
      Component{
         other,
         content.sep
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Data(Data &&other) :
      Component{
         other,
         content.sep
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Data(const Node &node) :
      Component{
         BodyText{},
         content.sep
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Data(
      const std::optional<UTF8Text> &sep
   ) :
      Component{
         BodyText{},
         content.sep
      },
      content{
         Defaulted<UTF8Text>(defaults.sep,sep)
      }
   {
      Component::finish();
   }

   // from vector
   template<class T, class = std::enable_if_t<body::template supported<T>>>
   Data(const std::vector<T> &vector) :
      Component{
         BodyText{},
         content.sep
      }
   {
      Component::finish(vector);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Data &operator=(const Data &) = default;

   // move
   Data &operator=(Data &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/containers/Data/src/custom.hpp"

}; // class Data

} // namespace containers
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
