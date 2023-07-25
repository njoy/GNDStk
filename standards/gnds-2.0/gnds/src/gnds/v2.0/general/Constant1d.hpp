
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_CONSTANT1D
#define GNDS_V2_0_GENERAL_CONSTANT1D

#include "gnds/v2.0/general/Axes.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Constant1d
// -----------------------------------------------------------------------------

class Constant1d :
   public Component<general::Constant1d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Constant1d"; }
   static auto NODENAME() { return "constant1d"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("label") |
         double{}
            / Meta<>("value") |
         double{}
            / Meta<>("domainMin") |
         double{}
            / Meta<>("domainMax") |

         // children
         --Child<general::Axes>
            ("axes")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "value",
         "domainMin",
         "domainMax",
         "axes"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "value",
         "domain_min",
         "domain_max",
         "axes"
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
      label{this};
   Field<double>
      value{this};
   Field<double>
      domainMin{this};
   Field<double>
      domainMax{this};

   // children
   Field<general::Axes>
      axes{this};

   // shortcuts
   #define GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   GNDSTK_SHORTCUT(axes(),axis);
   GNDSTK_SHORTCUT(axes(),grid);
   #undef GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->value, \
      this->domainMin, \
      this->domainMax, \
      this->axes \
   )

   // default
   Constant1d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Constant1d(
      const wrapper<std::optional<std::string>>
         &label,
      const wrapper<double>
         &value = {},
      const wrapper<double>
         &domainMin = {},
      const wrapper<double>
         &domainMax = {},
      const wrapper<general::Axes>
         &axes = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      value(this,value),
      domainMin(this,domainMin),
      domainMax(this,domainMax),
      axes(this,axes)
   {
      Component::finish();
   }

   // from node
   explicit Constant1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Constant1d(const Constant1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      value(this,other.value),
      domainMin(this,other.domainMin),
      domainMax(this,other.domainMax),
      axes(this,other.axes)
   {
      Component::finish(other);
   }

   // move
   Constant1d(Constant1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      value(this,std::move(other.value)),
      domainMin(this,std::move(other.domainMin)),
      domainMax(this,std::move(other.domainMax)),
      axes(this,std::move(other.axes))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Constant1d &operator=(const Constant1d &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         value = other.value;
         domainMin = other.domainMin;
         domainMax = other.domainMax;
         axes = other.axes;
      }
      return *this;
   }

   // move
   Constant1d &operator=(Constant1d &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         value = std::move(other.value);
         domainMin = std::move(other.domainMin);
         domainMax = std::move(other.domainMax);
         axes = std::move(other.axes);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Constant1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Constant1d

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
