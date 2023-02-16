
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_G3D_ARRAY
#define ALPHA_V2_0_G3D_ARRAY

#include "alpha/v2.0/g3d/Starts.hpp"
#include "alpha/v2.0/g3d/Lengths.hpp"
#include "alpha/v2.0/general/Values.hpp"

namespace alpha {
namespace v2_0 {
namespace g3d {

// -----------------------------------------------------------------------------
// g3d::
// class Array
// -----------------------------------------------------------------------------

class Array :
   public Component<g3d::Array>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "g3d"; }
   static auto CLASS() { return "Array"; }
   static auto FIELD() { return "array"; }

   // Core Interface multi-query to transfer information to/from Nodes
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
         --Child<std::optional<g3d::Starts>>
            ("values") | "starts" |
         --Child<std::optional<g3d::Lengths>>
            ("values") | "lengths" |
         --Child<general::Values>
            ("values") + [](auto &node) { return node.metadata.size() == 0; }
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
         "starts",
         "lengths",
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
         "starts",
         "lengths",
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
   Field<std::optional<g3d::Starts>>
      starts{this};
   Field<std::optional<g3d::Lengths>>
      lengths{this};
   Field<general::Values>
      values{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->shape, \
      this->compression, \
      this->symmetry, \
      this->starts, \
      this->lengths, \
      this->values \
   )

   // default
   Array() :
      GNDSTK_COMPONENT(BlockData{})
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
      const wrapper<std::optional<g3d::Starts>>
         &starts = {},
      const wrapper<std::optional<g3d::Lengths>>
         &lengths = {},
      const wrapper<general::Values>
         &values = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      shape(this,shape),
      compression(this,compression),
      symmetry(this,symmetry),
      starts(this,starts),
      lengths(this,lengths),
      values(this,values)
   {
      Component::finish();
   }

   // from node
   explicit Array(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Array(const Array &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      shape(this,other.shape),
      compression(this,other.compression),
      symmetry(this,other.symmetry),
      starts(this,other.starts),
      lengths(this,other.lengths),
      values(this,other.values)
   {
      Component::finish(other);
   }

   // move
   Array(Array &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      shape(this,std::move(other.shape)),
      compression(this,std::move(other.compression)),
      symmetry(this,std::move(other.symmetry)),
      starts(this,std::move(other.starts)),
      lengths(this,std::move(other.lengths)),
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
         starts = other.starts;
         lengths = other.lengths;
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
         starts = std::move(other.starts);
         lengths = std::move(other.lengths);
         values = std::move(other.values);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/g3d/Array/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Array

} // namespace g3d
} // namespace v2_0
} // namespace alpha

#endif
