
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_LISTOFCOVARIANCES
#define ALPHA_V2_0_GENERAL_LISTOFCOVARIANCES

#include "alpha/v2.0/general/Covariance.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ListOfCovariances
// -----------------------------------------------------------------------------

class ListOfCovariances :
   public Component<general::ListOfCovariances>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ListOfCovariances"; }
   static auto NODENAME() { return "listOfCovariances"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Covariance>
            ("covariance")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "covariance"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "covariance"
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

   // children
   Field<std::vector<general::Covariance>>
      covariance{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->covariance \
   )

   // default
   ListOfCovariances() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ListOfCovariances(
      const wrapper<std::vector<general::Covariance>>
         &covariance
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      covariance(this,covariance)
   {
      Component::finish();
   }

   // from node
   explicit ListOfCovariances(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ListOfCovariances(const ListOfCovariances &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      covariance(this,other.covariance)
   {
      Component::finish(other);
   }

   // move
   ListOfCovariances(ListOfCovariances &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      covariance(this,std::move(other.covariance))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ListOfCovariances &operator=(const ListOfCovariances &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         covariance = other.covariance;
      }
      return *this;
   }

   // move
   ListOfCovariances &operator=(ListOfCovariances &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         covariance = std::move(other.covariance);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ListOfCovariances/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ListOfCovariances

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
