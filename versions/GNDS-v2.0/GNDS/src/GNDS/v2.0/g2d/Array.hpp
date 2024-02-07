
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_G2D_ARRAY
#define GNDS_V2_0_G2D_ARRAY

#include "GNDS/v2.0/general/Values.hpp"

namespace GNDS {
namespace v2_0 {
namespace g2d {

// -----------------------------------------------------------------------------
// g2d::
// class Array
// -----------------------------------------------------------------------------

class Array :
   public Component<g2d::Array>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "g2d"; }
   static auto CLASS() { return "Array"; }
   static auto NODENAME() { return "array"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("shape") |
         std::optional<std::string>{}
            / Meta<>("compression") |
         std::optional<std::string>{}
            / Meta<>("symmetry") |

         // children
         --Child<general::Values>
            ("values")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "shape",
         "compression",
         "symmetry",
         "values"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "shape",
         "compression",
         "symmetry",
         "values"
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
      shape{this};
   Field<std::optional<std::string>>
      compression{this};
   Field<std::optional<std::string>>
      symmetry{this};

   // children
   Field<general::Values>
      values{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->shape, \
      this->compression, \
      this->symmetry, \
      this->values \
   )

   // default
   Array() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Array(
      const wrapper<std::string>
         &shape,
      const wrapper<std::optional<std::string>>
         &compression = {},
      const wrapper<std::optional<std::string>>
         &symmetry = {},
      const wrapper<general::Values>
         &values = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      shape(this,shape),
      compression(this,compression),
      symmetry(this,symmetry),
      values(this,values)
   {
      Component::finish();
   }

   // from node
   explicit Array(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Array(const Array &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      shape(this,other.shape),
      compression(this,other.compression),
      symmetry(this,other.symmetry),
      values(this,other.values)
   {
      Component::finish(other);
   }

   // move
   Array(Array &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      shape(this,std::move(other.shape)),
      compression(this,std::move(other.compression)),
      symmetry(this,std::move(other.symmetry)),
      values(this,std::move(other.values))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Array &operator=(const Array &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         shape = other.shape;
         compression = other.compression;
         symmetry = other.symmetry;
         values = other.values;
      }
      return *this;
   }

   // move
   Array &operator=(Array &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         shape = std::move(other.shape);
         compression = std::move(other.compression);
         symmetry = std::move(other.symmetry);
         values = std::move(other.values);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/g2d/Array/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Array

} // namespace g2d
} // namespace v2_0
} // namespace GNDS

#endif
