
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_APPLICATIONDATA
#define GNDS_V2_0_GENERAL_APPLICATIONDATA

#include "GNDS/v2.0/general/Institution.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ApplicationData
// -----------------------------------------------------------------------------

class ApplicationData :
   public Component<general::ApplicationData>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ApplicationData"; }
   static auto NODENAME() { return "applicationData"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Institution>
            ("institution")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "institution"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "institution"
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
   Field<general::Institution>
      institution{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(institution(),ENDFconversionFlags);
   NJOY_GNDSTK_SHORTCUT(institution().ENDFconversionFlags(),conversion);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->institution \
   )

   // default
   ApplicationData() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ApplicationData(
      const wrapper<general::Institution>
         &institution
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      institution(this,institution)
   {
      Component::finish();
   }

   // from node
   explicit ApplicationData(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ApplicationData(const ApplicationData &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      institution(this,other.institution)
   {
      Component::finish(other);
   }

   // move
   ApplicationData(ApplicationData &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      institution(this,std::move(other.institution))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ApplicationData &operator=(const ApplicationData &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         institution = other.institution;
      }
      return *this;
   }

   // move
   ApplicationData &operator=(ApplicationData &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         institution = std::move(other.institution);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/ApplicationData/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class ApplicationData

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif