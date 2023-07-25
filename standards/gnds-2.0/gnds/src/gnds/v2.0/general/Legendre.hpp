
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_LEGENDRE
#define GNDS_V2_0_GENERAL_LEGENDRE

#include "gnds/v2.0/general/Values.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Legendre
// -----------------------------------------------------------------------------

class Legendre :
   public Component<general::Legendre>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Legendre"; }
   static auto NODENAME() { return "Legendre"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         double{}
            / Meta<>("outerDomainValue") |

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
         "outerDomainValue",
         "values"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "outer_domain_value",
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
   Field<double>
      outerDomainValue{this};

   // children
   Field<general::Values>
      values{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->outerDomainValue, \
      this->values \
   )

   // default
   Legendre() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Legendre(
      const wrapper<double>
         &outerDomainValue,
      const wrapper<general::Values>
         &values = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      outerDomainValue(this,outerDomainValue),
      values(this,values)
   {
      Component::finish();
   }

   // from node
   explicit Legendre(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Legendre(const Legendre &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      outerDomainValue(this,other.outerDomainValue),
      values(this,other.values)
   {
      Component::finish(other);
   }

   // move
   Legendre(Legendre &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      outerDomainValue(this,std::move(other.outerDomainValue)),
      values(this,std::move(other.values))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Legendre &operator=(const Legendre &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         outerDomainValue = other.outerDomainValue;
         values = other.values;
      }
      return *this;
   }

   // move
   Legendre &operator=(Legendre &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         outerDomainValue = std::move(other.outerDomainValue);
         values = std::move(other.values);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Legendre/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Legendre

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
