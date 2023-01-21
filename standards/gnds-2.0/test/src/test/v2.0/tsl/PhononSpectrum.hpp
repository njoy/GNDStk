
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TSL_PHONONSPECTRUM
#define TEST_V2_0_TSL_PHONONSPECTRUM

#include "test/v2.0/containers/XYs1d.hpp"

namespace test {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class PhononSpectrum
// -----------------------------------------------------------------------------

class PhononSpectrum :
   public Component<tsl::PhononSpectrum>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "PhononSpectrum"; }
   static auto FIELD() { return "phononSpectrum"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<containers::XYs1d>("XYs1d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<containers::XYs1d> XYs1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->XYs1d)

   // default
   PhononSpectrum() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit PhononSpectrum(
      const wrapper<containers::XYs1d> &XYs1d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d)
   {
      Component::finish();
   }

   // from node
   explicit PhononSpectrum(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   PhononSpectrum(const PhononSpectrum &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs1d(this,other.XYs1d)
   {
      Component::finish(other);
   }

   // move
   PhononSpectrum(PhononSpectrum &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs1d(this,std::move(other.XYs1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   PhononSpectrum &operator=(const PhononSpectrum &) = default;
   PhononSpectrum &operator=(PhononSpectrum &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/tsl/PhononSpectrum/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class PhononSpectrum

} // namespace tsl
} // namespace v2_0
} // namespace test

#endif
