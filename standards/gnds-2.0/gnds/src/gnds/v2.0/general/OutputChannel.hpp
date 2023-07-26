
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_OUTPUTCHANNEL
#define GNDS_V2_0_GENERAL_OUTPUTCHANNEL

#include "gnds/v2.0/general/Q.hpp"
#include "gnds/v2.0/general/Products.hpp"
#include "gnds/v2.0/top/FissionFragmentData.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class OutputChannel
// -----------------------------------------------------------------------------

class OutputChannel :
   public Component<general::OutputChannel>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
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
         --Child<std::optional<general::Products>>
            ("products") |
         --Child<std::optional<top::FissionFragmentData>>
            ("fissionFragmentData")
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
         "products",
         "fissionFragmentData"
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
         "products",
         "fission_fragment_data"
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
   Field<std::optional<general::Products>>
      products{this};
   Field<std::optional<top::FissionFragmentData>>
      fissionFragmentData{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(Q(),Double);
   NJOY_GNDSTK_SHORTCUT(Q(),constant1d);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->genre, \
      this->process, \
      this->Q, \
      this->products, \
      this->fissionFragmentData \
   )

   // default
   OutputChannel() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
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
      const wrapper<std::optional<general::Products>>
         &products = {},
      const wrapper<std::optional<top::FissionFragmentData>>
         &fissionFragmentData = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      genre(this,genre),
      process(this,process),
      Q(this,Q),
      products(this,products),
      fissionFragmentData(this,fissionFragmentData)
   {
      Component::finish();
   }

   // from node
   explicit OutputChannel(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   OutputChannel(const OutputChannel &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      genre(this,other.genre),
      process(this,other.process),
      Q(this,other.Q),
      products(this,other.products),
      fissionFragmentData(this,other.fissionFragmentData)
   {
      Component::finish(other);
   }

   // move
   OutputChannel(OutputChannel &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      genre(this,std::move(other.genre)),
      process(this,std::move(other.process)),
      Q(this,std::move(other.Q)),
      products(this,std::move(other.products)),
      fissionFragmentData(this,std::move(other.fissionFragmentData))
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
         fissionFragmentData = other.fissionFragmentData;
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
         fissionFragmentData = std::move(other.fissionFragmentData);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/OutputChannel/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class OutputChannel

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
