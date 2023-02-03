
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_DECAY
#define ALPHA_V2_0_GENERAL_DECAY

#include "alpha/v2.0/general/Products.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Decay
// -----------------------------------------------------------------------------

class Decay :
   public Component<general::Decay>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Decay"; }
   static auto FIELD() { return "decay"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         int{}
            / Meta<>("index") |
         std::optional<std::string>{}
            / Meta<>("mode") |
         std::optional<bool>{}
            / Meta<>("complete") |

         // children
         --Child<std::optional<general::Products>>
            ("products")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<int> index{this};
   Field<std::optional<std::string>> mode{this};
   Field<std::optional<bool>> complete{this};

   // children
   Field<std::optional<general::Products>>
      products{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->index, \
      this->mode, \
      this->complete, \
      this->products)

   // default
   Decay() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Decay(
      const wrapper<int>
         &index,
      const wrapper<std::optional<std::string>>
         &mode = {},
      const wrapper<std::optional<bool>>
         &complete = {},
      const wrapper<std::optional<general::Products>>
         &products = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      index(this,index),
      mode(this,mode),
      complete(this,complete),
      products(this,products)
   {
      Component::finish();
   }

   // from node
   explicit Decay(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Decay(const Decay &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      index(this,other.index),
      mode(this,other.mode),
      complete(this,other.complete),
      products(this,other.products)
   {
      Component::finish(other);
   }

   // move
   Decay(Decay &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      index(this,std::move(other.index)),
      mode(this,std::move(other.mode)),
      complete(this,std::move(other.complete)),
      products(this,std::move(other.products))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Decay &operator=(const Decay &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         index = other.index;
         mode = other.mode;
         complete = other.complete;
         products = other.products;
      }
      return *this;
   }

   // move
   Decay &operator=(Decay &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         index = std::move(other.index);
         mode = std::move(other.mode);
         complete = std::move(other.complete);
         products = std::move(other.products);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Decay/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Decay

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
