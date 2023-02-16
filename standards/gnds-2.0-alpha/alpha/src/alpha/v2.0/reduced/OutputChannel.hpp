
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_REDUCED_OUTPUTCHANNEL
#define ALPHA_V2_0_REDUCED_OUTPUTCHANNEL

#include "alpha/v2.0/general/Q.hpp"
#include "alpha/v2.0/reduced/Products.hpp"

namespace alpha {
namespace v2_0 {
namespace reduced {

// -----------------------------------------------------------------------------
// reduced::
// class OutputChannel
// -----------------------------------------------------------------------------

class OutputChannel :
   public Component<reduced::OutputChannel>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "reduced"; }
   static auto CLASS() { return "OutputChannel"; }
   static auto NODENAME() { return "outputChannel"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("genre") |
         std::optional<std::string>{}
            / Meta<>("process") |

         // children
         --Child<general::Q>
            ("Q") |
         --Child<std::optional<reduced::Products>>
            ("products")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "genre",
         "process",
         "Q",
         "products"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "genre",
         "process",
         "q",
         "products"
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
   Field<std::string>
      genre{this};
   Field<std::optional<std::string>>
      process{this};

   // children
   Field<general::Q>
      Q{this};
   Field<std::optional<reduced::Products>>
      products{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->genre, \
      this->process, \
      this->Q, \
      this->products \
   )

   // default
   OutputChannel() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit OutputChannel(
      const wrapper<std::string>
         &genre,
      const wrapper<std::optional<std::string>>
         &process = {},
      const wrapper<general::Q>
         &Q = {},
      const wrapper<std::optional<reduced::Products>>
         &products = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      genre(this,genre),
      process(this,process),
      Q(this,Q),
      products(this,products)
   {
      Component::finish();
   }

   // from node
   explicit OutputChannel(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   OutputChannel(const OutputChannel &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      genre(this,other.genre),
      process(this,other.process),
      Q(this,other.Q),
      products(this,other.products)
   {
      Component::finish(other);
   }

   // move
   OutputChannel(OutputChannel &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      genre(this,std::move(other.genre)),
      process(this,std::move(other.process)),
      Q(this,std::move(other.Q)),
      products(this,std::move(other.products))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   OutputChannel &operator=(const OutputChannel &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         genre = other.genre;
         process = other.process;
         Q = other.Q;
         products = other.products;
      }
      return *this;
   }

   // move
   OutputChannel &operator=(OutputChannel &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         genre = std::move(other.genre);
         process = std::move(other.process);
         Q = std::move(other.Q);
         products = std::move(other.products);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/reduced/OutputChannel/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class OutputChannel

} // namespace reduced
} // namespace v2_0
} // namespace alpha

#endif
