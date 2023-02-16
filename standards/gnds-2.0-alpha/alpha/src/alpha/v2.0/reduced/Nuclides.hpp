
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_REDUCED_NUCLIDES
#define ALPHA_V2_0_REDUCED_NUCLIDES

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace reduced {

// -----------------------------------------------------------------------------
// reduced::
// class Nuclides
// -----------------------------------------------------------------------------

class Nuclides :
   public Component<reduced::Nuclides>,
   public DataNode<std::vector<std::string>,false>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "reduced"; }
   static auto CLASS() { return "Nuclides"; }
   static auto FIELD() { return "nuclides"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("href") |

         // data
         --Child<DataNode>(special::self) / DataConverter{}
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "href",
         "strings"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "href",
         "strings"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;
   using DataNode::operator=;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<std::string>>
      href{this};

   // data
   std::vector<std::string> &strings = *this;

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->href, \
      static_cast<DataNode &>(*this) \
   )

   // default
   Nuclides() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Nuclides(
      const wrapper<std::optional<std::string>>
         &href
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit Nuclides(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector<std::string>
   explicit Nuclides(const std::vector<std::string> &vector) :
      GNDSTK_COMPONENT(BlockData{}),
      DataNode(vector)
   {
      Component::finish(vector);
   }

   // copy
   Nuclides(const Nuclides &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      DataNode(other),
      comment(this,other.comment),
      href(this,other.href)
   {
      Component::finish(other);
   }

   // move
   Nuclides(Nuclides &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      DataNode(std::move(other)),
      comment(this,std::move(other.comment)),
      href(this,std::move(other.href))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Nuclides &operator=(const Nuclides &other)
   {
      if (this != &other) {
         Component::operator=(other);
         DataNode::operator=(other);
         comment = other.comment;
         href = other.href;
      }
      return *this;
   }

   // move
   Nuclides &operator=(Nuclides &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         DataNode::operator=(std::move(other));
         comment = std::move(other.comment);
         href = std::move(other.href);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/reduced/Nuclides/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Nuclides

} // namespace reduced
} // namespace v2_0
} // namespace alpha

#endif
