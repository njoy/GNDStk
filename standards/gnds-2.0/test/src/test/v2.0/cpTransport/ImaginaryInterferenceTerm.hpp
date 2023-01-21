
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CPTRANSPORT_IMAGINARYINTERFERENCETERM
#define TEST_V2_0_CPTRANSPORT_IMAGINARYINTERFERENCETERM

#include "test/v2.0/containers/XYs2d.hpp"
#include "test/v2.0/containers/Regions2d.hpp"

namespace test {
namespace v2_0 {
namespace cpTransport {

// -----------------------------------------------------------------------------
// cpTransport::
// class ImaginaryInterferenceTerm
// -----------------------------------------------------------------------------

class ImaginaryInterferenceTerm :
   public Component<cpTransport::ImaginaryInterferenceTerm>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "cpTransport"; }
   static auto CLASS() { return "ImaginaryInterferenceTerm"; }
   static auto FIELD() { return "imaginaryInterferenceTerm"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<containers::XYs2d>>("XYs2d") |
         --Child<std::optional<containers::Regions2d>>("regions2d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<containers::XYs2d>> XYs2d{this};
   Field<std::optional<containers::Regions2d>> regions2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->XYs2d, \
      this->regions2d)

   // default
   ImaginaryInterferenceTerm() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ImaginaryInterferenceTerm(
      const wrapper<std::optional<containers::XYs2d>> &XYs2d,
      const wrapper<std::optional<containers::Regions2d>> &regions2d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs2d(this,XYs2d),
      regions2d(this,regions2d)
   {
      Component::finish();
   }

   // from node
   explicit ImaginaryInterferenceTerm(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ImaginaryInterferenceTerm(const ImaginaryInterferenceTerm &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs2d(this,other.XYs2d),
      regions2d(this,other.regions2d)
   {
      Component::finish(other);
   }

   // move
   ImaginaryInterferenceTerm(ImaginaryInterferenceTerm &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs2d(this,std::move(other.XYs2d)),
      regions2d(this,std::move(other.regions2d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ImaginaryInterferenceTerm &operator=(const ImaginaryInterferenceTerm &) = default;
   ImaginaryInterferenceTerm &operator=(ImaginaryInterferenceTerm &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/cpTransport/ImaginaryInterferenceTerm/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ImaginaryInterferenceTerm

} // namespace cpTransport
} // namespace v2_0
} // namespace test

#endif
