
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_COLUMNDATA
#define ALPHA_V2_0_GENERAL_COLUMNDATA

#include "alpha/v2.0/general/Slices.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ColumnData
// -----------------------------------------------------------------------------

class ColumnData :
   public Component<general::ColumnData>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ColumnData"; }
   static auto FIELD() { return "columnData"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("ENDF_MFMT") |
         std::string{}
            / Meta<>("href") |

         // children
         --Child<std::optional<general::Slices>>
            ("slices")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "ENDF_MFMT",
         "href",
         "slices"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "endf_mfmt",
         "href",
         "slices"
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
   Field<std::optional<std::string>>
      ENDF_MFMT{this};
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
      this->href, \
      this->slices \
   )

   // default
   ColumnData() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ColumnData(
      const wrapper<std::optional<std::string>>
         &ENDF_MFMT,
      const wrapper<std::string>
         &href = {},
      const wrapper<std::optional<general::Slices>>
         &slices = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      ENDF_MFMT(this,ENDF_MFMT),
      href(this,href),
      slices(this,slices)
   {
      Component::finish();
   }

   // from node
   explicit ColumnData(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ColumnData(const ColumnData &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      ENDF_MFMT(this,other.ENDF_MFMT),
      href(this,other.href),
      slices(this,other.slices)
   {
      Component::finish(other);
   }

   // move
   ColumnData(ColumnData &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      ENDF_MFMT(this,std::move(other.ENDF_MFMT)),
      href(this,std::move(other.href)),
      slices(this,std::move(other.slices))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ColumnData &operator=(const ColumnData &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         ENDF_MFMT = other.ENDF_MFMT;
         href = other.href;
         slices = other.slices;
      }
      return *this;
   }

   // move
   ColumnData &operator=(ColumnData &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         ENDF_MFMT = std::move(other.ENDF_MFMT);
         href = std::move(other.href);
         slices = std::move(other.slices);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ColumnData/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ColumnData

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
