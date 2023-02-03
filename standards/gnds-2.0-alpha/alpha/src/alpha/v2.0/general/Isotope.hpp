
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_ISOTOPE
#define ALPHA_V2_0_GENERAL_ISOTOPE

#include "alpha/v2.0/general/Nuclides.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Isotope
// -----------------------------------------------------------------------------

class Isotope :
   public Component<general::Isotope>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Isotope"; }
   static auto FIELD() { return "isotope"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("symbol") |
         int{}
            / Meta<>("A") |

         // children
         --Child<general::Nuclides>
            ("nuclides")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> symbol{this};
   Field<int> A{this};

   // children
   Field<general::Nuclides>
      nuclides{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->symbol, \
      this->A, \
      this->nuclides)

   // default
   Isotope() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Isotope(
      const wrapper<std::string>
         &symbol,
      const wrapper<int>
         &A = {},
      const wrapper<general::Nuclides>
         &nuclides = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      symbol(this,symbol),
      A(this,A),
      nuclides(this,nuclides)
   {
      Component::finish();
   }

   // from node
   explicit Isotope(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Isotope(const Isotope &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      symbol(this,other.symbol),
      A(this,other.A),
      nuclides(this,other.nuclides)
   {
      Component::finish(other);
   }

   // move
   Isotope(Isotope &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      symbol(this,std::move(other.symbol)),
      A(this,std::move(other.A)),
      nuclides(this,std::move(other.nuclides))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Isotope &operator=(const Isotope &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         symbol = other.symbol;
         A = other.A;
         nuclides = other.nuclides;
      }
      return *this;
   }

   // move
   Isotope &operator=(Isotope &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         symbol = std::move(other.symbol);
         A = std::move(other.A);
         nuclides = std::move(other.nuclides);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Isotope/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Isotope

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
