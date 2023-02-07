
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_ENDFCONVERSIONFLAGS
#define ALPHA_V2_0_GENERAL_ENDFCONVERSIONFLAGS

#include "alpha/v2.0/general/Conversion.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ENDFconversionFlags
// -----------------------------------------------------------------------------

class ENDFconversionFlags :
   public Component<general::ENDFconversionFlags>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ENDFconversionFlags"; }
   static auto FIELD() { return "ENDFconversionFlags"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("flags") |
         std::optional<std::string>{}
            / Meta<>("href") |

         // children
         ++Child<general::Conversion>
            ("conversion")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<std::string>>
      flags{this};
   Field<std::optional<std::string>>
      href{this};

   // children
   Field<std::vector<general::Conversion>>
      conversion{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->flags, \
      this->href, \
      this->conversion \
   )

   // default
   ENDFconversionFlags() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ENDFconversionFlags(
      const wrapper<std::optional<std::string>>
         &flags,
      const wrapper<std::optional<std::string>>
         &href = {},
      const wrapper<std::vector<general::Conversion>>
         &conversion = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      flags(this,flags),
      href(this,href),
      conversion(this,conversion)
   {
      Component::finish();
   }

   // from node
   explicit ENDFconversionFlags(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ENDFconversionFlags(const ENDFconversionFlags &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      flags(this,other.flags),
      href(this,other.href),
      conversion(this,other.conversion)
   {
      Component::finish(other);
   }

   // move
   ENDFconversionFlags(ENDFconversionFlags &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      flags(this,std::move(other.flags)),
      href(this,std::move(other.href)),
      conversion(this,std::move(other.conversion))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ENDFconversionFlags &operator=(const ENDFconversionFlags &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         flags = other.flags;
         href = other.href;
         conversion = other.conversion;
      }
      return *this;
   }

   // move
   ENDFconversionFlags &operator=(ENDFconversionFlags &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         flags = std::move(other.flags);
         href = std::move(other.href);
         conversion = std::move(other.conversion);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ENDFconversionFlags/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ENDFconversionFlags

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
