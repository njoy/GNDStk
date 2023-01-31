
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_GRID
#define ALPHA_V2_0_COMMON_GRID

#include "alpha/v2.0/common/Link.hpp"
#include "alpha/v2.0/common/Values.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Grid
// -----------------------------------------------------------------------------

class Grid :
   public Component<common::Grid>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Grid"; }
   static auto FIELD() { return "grid"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         int{}
            / Meta<>("index") |
         std::string{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("unit") |
         std::string{}
            / Meta<>("style") |
         std::optional<std::string>{}
            / Meta<>("interpolation") |

         // children
         --Child<std::optional<common::Link>>("link") |
         --Child<std::optional<common::Values>>("values")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<int> index{this};
   Field<std::string> label{this};
   Field<std::string> unit{this};
   Field<std::string> style{this};
   Field<std::optional<std::string>> interpolation{this};

   // children
   Field<std::optional<common::Link>> link{this};
   Field<std::optional<common::Values>> values{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->index, \
      this->label, \
      this->unit, \
      this->style, \
      this->interpolation, \
      this->link, \
      this->values)

   // default
   Grid() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Grid(
      const wrapper<int> &index,
      const wrapper<std::string> &label = {},
      const wrapper<std::string> &unit = {},
      const wrapper<std::string> &style = {},
      const wrapper<std::optional<std::string>> &interpolation = {},
      const wrapper<std::optional<common::Link>> &link = {},
      const wrapper<std::optional<common::Values>> &values = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      index(this,index),
      label(this,label),
      unit(this,unit),
      style(this,style),
      interpolation(this,interpolation),
      link(this,link),
      values(this,values)
   {
      Component::finish();
   }

   // from node
   explicit Grid(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Grid(const Grid &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      index(this,other.index),
      label(this,other.label),
      unit(this,other.unit),
      style(this,other.style),
      interpolation(this,other.interpolation),
      link(this,other.link),
      values(this,other.values)
   {
      Component::finish(other);
   }

   // move
   Grid(Grid &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      index(this,std::move(other.index)),
      label(this,std::move(other.label)),
      unit(this,std::move(other.unit)),
      style(this,std::move(other.style)),
      interpolation(this,std::move(other.interpolation)),
      link(this,std::move(other.link)),
      values(this,std::move(other.values))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Grid &operator=(const Grid &) = default;
   Grid &operator=(Grid &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/Grid/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Grid

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
