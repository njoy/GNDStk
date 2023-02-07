
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_ROWDATA
#define ALPHA_V2_0_GENERAL_ROWDATA

#include "alpha/v2.0/general/Slices.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class RowData
// -----------------------------------------------------------------------------

class RowData :
   public Component<general::RowData>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "RowData"; }
   static auto FIELD() { return "rowData"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("ENDF_MFMT") |
         std::optional<int>{}
            / Meta<>("dimension") |
         std::string{}
            / Meta<>("href") |

         // children
         --Child<std::optional<general::Slices>>
            ("slices")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<std::string>>
      ENDF_MFMT{this};
   Field<std::optional<int>>
      dimension{this};
   Field<std::string>
      href{this};

   // children
   Field<std::optional<general::Slices>>
      slices{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->ENDF_MFMT, \
      this->dimension, \
      this->href, \
      this->slices \
   )

   // default
   RowData() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit RowData(
      const wrapper<std::optional<std::string>>
         &ENDF_MFMT,
      const wrapper<std::optional<int>>
         &dimension = {},
      const wrapper<std::string>
         &href = {},
      const wrapper<std::optional<general::Slices>>
         &slices = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      ENDF_MFMT(this,ENDF_MFMT),
      dimension(this,dimension),
      href(this,href),
      slices(this,slices)
   {
      Component::finish();
   }

   // from node
   explicit RowData(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   RowData(const RowData &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      ENDF_MFMT(this,other.ENDF_MFMT),
      dimension(this,other.dimension),
      href(this,other.href),
      slices(this,other.slices)
   {
      Component::finish(other);
   }

   // move
   RowData(RowData &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      ENDF_MFMT(this,std::move(other.ENDF_MFMT)),
      dimension(this,std::move(other.dimension)),
      href(this,std::move(other.href)),
      slices(this,std::move(other.slices))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   RowData &operator=(const RowData &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         ENDF_MFMT = other.ENDF_MFMT;
         dimension = other.dimension;
         href = other.href;
         slices = other.slices;
      }
      return *this;
   }

   // move
   RowData &operator=(RowData &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         ENDF_MFMT = std::move(other.ENDF_MFMT);
         dimension = std::move(other.dimension);
         href = std::move(other.href);
         slices = std::move(other.slices);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/RowData/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class RowData

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
