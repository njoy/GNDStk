
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_XYS2D
#define GNDS_V2_0_GENERAL_XYS2D

#include "GNDS/v2.0/general/Axes.hpp"
#include "GNDS/v2.0/general/Function1ds.hpp"
#include "GNDS/v2.0/general/Uncertainty.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class XYs2d
// -----------------------------------------------------------------------------

class XYs2d :
   public Component<general::XYs2d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "XYs2d"; }
   static auto NODENAME() { return "XYs2d"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<int>{}
            / Meta<>("index") |
         std::optional<std::string>{}
            / Meta<>("interpolation") |
         std::optional<std::string>{}
            / Meta<>("interpolationQualifier") |
         std::optional<double>{}
            / Meta<>("outerDomainValue") |

         // children
         --Child<std::optional<general::Axes>>
            ("axes") |
         --Child<general::Function1ds>
            ("function1ds") |
         --Child<std::optional<general::Uncertainty>>
            ("uncertainty")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "index",
         "interpolation",
         "interpolationQualifier",
         "outerDomainValue",
         "axes",
         "function1ds",
         "uncertainty"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "index",
         "interpolation",
         "interpolation_qualifier",
         "outer_domain_value",
         "axes",
         "function1ds",
         "uncertainty"
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
   Field<std::optional<int>>
      index{this};
   Field<std::optional<std::string>>
      interpolation{this};
   Field<std::optional<std::string>>
      interpolationQualifier{this};
   Field<std::optional<double>>
      outerDomainValue{this};

   // children
   Field<std::optional<general::Axes>>
      axes{this};
   Field<general::Function1ds>
      function1ds{this};
   Field<std::optional<general::Uncertainty>>
      uncertainty{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(function1ds(),Legendre);
   NJOY_GNDSTK_SHORTCUT(function1ds(),XYs1d);
   NJOY_GNDSTK_SHORTCUT(function1ds(),regions1d);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->index, \
      this->interpolation, \
      this->interpolationQualifier, \
      this->outerDomainValue, \
      this->axes, \
      this->function1ds, \
      this->uncertainty \
   )

   // default
   XYs2d() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit XYs2d(
      const wrapper<std::optional<int>>
         &index,
      const wrapper<std::optional<std::string>>
         &interpolation = {},
      const wrapper<std::optional<std::string>>
         &interpolationQualifier = {},
      const wrapper<std::optional<double>>
         &outerDomainValue = {},
      const wrapper<std::optional<general::Axes>>
         &axes = {},
      const wrapper<general::Function1ds>
         &function1ds = {},
      const wrapper<std::optional<general::Uncertainty>>
         &uncertainty = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      index(this,index),
      interpolation(this,interpolation),
      interpolationQualifier(this,interpolationQualifier),
      outerDomainValue(this,outerDomainValue),
      axes(this,axes),
      function1ds(this,function1ds),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit XYs2d(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   XYs2d(const XYs2d &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      index(this,other.index),
      interpolation(this,other.interpolation),
      interpolationQualifier(this,other.interpolationQualifier),
      outerDomainValue(this,other.outerDomainValue),
      axes(this,other.axes),
      function1ds(this,other.function1ds),
      uncertainty(this,other.uncertainty)
   {
      Component::finish(other);
   }

   // move
   XYs2d(XYs2d &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      index(this,std::move(other.index)),
      interpolation(this,std::move(other.interpolation)),
      interpolationQualifier(this,std::move(other.interpolationQualifier)),
      outerDomainValue(this,std::move(other.outerDomainValue)),
      axes(this,std::move(other.axes)),
      function1ds(this,std::move(other.function1ds)),
      uncertainty(this,std::move(other.uncertainty))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   XYs2d &operator=(const XYs2d &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         index = other.index;
         interpolation = other.interpolation;
         interpolationQualifier = other.interpolationQualifier;
         outerDomainValue = other.outerDomainValue;
         axes = other.axes;
         function1ds = other.function1ds;
         uncertainty = other.uncertainty;
      }
      return *this;
   }

   // move
   XYs2d &operator=(XYs2d &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         index = std::move(other.index);
         interpolation = std::move(other.interpolation);
         interpolationQualifier = std::move(other.interpolationQualifier);
         outerDomainValue = std::move(other.outerDomainValue);
         axes = std::move(other.axes);
         function1ds = std::move(other.function1ds);
         uncertainty = std::move(other.uncertainty);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/XYs2d/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class XYs2d

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif