
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef PROTO_V1_9_CONTAINERS_VALUES
#define PROTO_V1_9_CONTAINERS_VALUES

#include "proto/v1.9/key.hpp"

namespace proto {
namespace v1_9 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Values
// -----------------------------------------------------------------------------

class Values :
   public Component<containers::Values,true>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Values"; }
   static auto NODENAME() { return "values"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         Defaulted<std::string>{"double"}
            / Meta<>("valueType") |
         Defaulted<int>{0}
            / Meta<>("start") |
         std::optional<int>{}
            / Meta<>("length")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "valueType",
         "start",
         "length"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "value_type",
         "start",
         "length"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;
   using BlockData::operator=;

   // defaults
   static inline const struct Defaults {
      static inline const std::string valueType = "double";
      static inline const int start = 0;
   } defaults;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   mutable Field<Defaulted<std::string>>
      valueType{this,defaults.valueType};
   mutable Field<Defaulted<int>>
      start{this,defaults.start};
   mutable Field<std::optional<int>>
      length{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->valueType, \
      this->start, \
      this->length \
   )

   // default
   Values() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   // optional replaces Defaulted; this class knows the default(s)
   explicit Values(
      const wrapper<std::optional<std::string>>
         &valueType,
      const wrapper<std::optional<int>>
         &start = {},
      const wrapper<std::optional<int>>
         &length = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      valueType(this,defaults.valueType,valueType),
      start(this,defaults.start,start),
      length(this,length)
   {
      Component::finish();
   }

   // from node
   explicit Values(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   explicit Values(const std::vector<T> &vector) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(vector);
   }

   // copy
   Values(const Values &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      valueType(this,other.valueType),
      start(this,other.start),
      length(this,other.length)
   {
      Component::finish(other);
   }

   // move
   Values(Values &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      valueType(this,std::move(other.valueType)),
      start(this,std::move(other.start)),
      length(this,std::move(other.length))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Values &operator=(const Values &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         valueType = other.valueType;
         start = other.start;
         length = other.length;
      }
      return *this;
   }

   // move
   Values &operator=(Values &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         valueType = std::move(other.valueType);
         start = std::move(other.start);
         length = std::move(other.length);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "proto/v1.9/containers/Values/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Values

} // namespace containers
} // namespace v1_9
} // namespace proto

#endif
