
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_ELAPSEDTIMES
#define ALPHA_V2_0_COMMON_ELAPSEDTIMES

#include "alpha/v2.0/common/ElapsedTime.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class ElapsedTimes
// -----------------------------------------------------------------------------

class ElapsedTimes :
   public Component<common::ElapsedTimes>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "ElapsedTimes"; }
   static auto FIELD() { return "elapsedTimes"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<common::ElapsedTime>
            ("elapsedTime")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<common::ElapsedTime>>
      elapsedTime{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->elapsedTime)

   // default
   ElapsedTimes() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ElapsedTimes(
      const wrapper<std::vector<common::ElapsedTime>>
         &elapsedTime
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      elapsedTime(this,elapsedTime)
   {
      Component::finish();
   }

   // from node
   explicit ElapsedTimes(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ElapsedTimes(const ElapsedTimes &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      elapsedTime(this,other.elapsedTime)
   {
      Component::finish(other);
   }

   // move
   ElapsedTimes(ElapsedTimes &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      elapsedTime(this,std::move(other.elapsedTime))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ElapsedTimes &operator=(const ElapsedTimes &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         elapsedTime = other.elapsedTime;
      }
      return *this;
   }

   // move
   ElapsedTimes &operator=(ElapsedTimes &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         elapsedTime = std::move(other.elapsedTime);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/ElapsedTimes/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ElapsedTimes

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
