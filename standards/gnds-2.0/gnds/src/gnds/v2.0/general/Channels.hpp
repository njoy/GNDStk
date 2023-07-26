
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_CHANNELS
#define GNDS_V2_0_GENERAL_CHANNELS

#include "gnds/v2.0/general/Channel.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Channels
// -----------------------------------------------------------------------------

class Channels :
   public Component<general::Channels>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Channels"; }
   static auto NODENAME() { return "channels"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Channel>
            ("channel")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "channel"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "channel"
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
   Field<std::vector<general::Channel>>
      channel{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->channel \
   )

   // default
   Channels() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Channels(
      const wrapper<std::vector<general::Channel>>
         &channel
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      channel(this,channel)
   {
      Component::finish();
   }

   // from node
   explicit Channels(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Channels(const Channels &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      channel(this,other.channel)
   {
      Component::finish(other);
   }

   // move
   Channels(Channels &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      channel(this,std::move(other.channel))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Channels &operator=(const Channels &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         channel = other.channel;
      }
      return *this;
   }

   // move
   Channels &operator=(Channels &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         channel = std::move(other.channel);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Channels/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Channels

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
