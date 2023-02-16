
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_MULTIGROUP3D
#define TEST_V2_0_TRANSPORT_MULTIGROUP3D

#include "test/v2.0/containers/Gridded3d.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class MultiGroup3d
// -----------------------------------------------------------------------------

class MultiGroup3d :
   public Component<transport::MultiGroup3d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "MultiGroup3d"; }
   static auto NODENAME() { return "scatteringMatrix"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("productFrame") |

         // children
         --Child<containers::Gridded3d>
            ("gridded3d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "productFrame",
         "gridded3d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "product_frame",
         "gridded3d"
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
   Field<XMLName>
      label{this};
   Field<XMLName>
      productFrame{this};

   // children
   Field<containers::Gridded3d>
      gridded3d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->productFrame, \
      this->gridded3d \
   )

   // default
   MultiGroup3d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit MultiGroup3d(
      const wrapper<XMLName>
         &label,
      const wrapper<XMLName>
         &productFrame = {},
      const wrapper<containers::Gridded3d>
         &gridded3d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      productFrame(this,productFrame),
      gridded3d(this,gridded3d)
   {
      Component::finish();
   }

   // from node
   explicit MultiGroup3d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   MultiGroup3d(const MultiGroup3d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      productFrame(this,other.productFrame),
      gridded3d(this,other.gridded3d)
   {
      Component::finish(other);
   }

   // move
   MultiGroup3d(MultiGroup3d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      productFrame(this,std::move(other.productFrame)),
      gridded3d(this,std::move(other.gridded3d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   MultiGroup3d &operator=(const MultiGroup3d &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         productFrame = other.productFrame;
         gridded3d = other.gridded3d;
      }
      return *this;
   }

   // move
   MultiGroup3d &operator=(MultiGroup3d &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         productFrame = std::move(other.productFrame);
         gridded3d = std::move(other.gridded3d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/MultiGroup3d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class MultiGroup3d

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
