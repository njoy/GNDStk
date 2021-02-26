// Outer namespaces that surround everything else.
namespace njoy {
namespace GNDStk {

   // Namespace for basic, generic "GNDS query objects". There are
   // other sets of query objects; don't worry about those for now.
   namespace basic {

      // Query objects specific for GNDS metadata.
      namespace meta {
      }

      // Query objects specific for GNDS child nodes.
      namespace child {
      }

      // Bring in meta:: and child:: above.
      using namespace meta;
      using namespace child;

      // Bring in common:: below.
      using namespace common;
   }

   // Some query objects that we wish to be shared across basic::
   // as well as other query-object namespaces that we don't list here.
   namespace common {
   }

   // Logging capabilities, including, for example, support for errors,
   // warnings, and informational messages.
   namespace log {
   }

   // Our "core" namespace; see discussion.
   namespace core {
      // Bring in GNDStk:: itself, and basic:: above
      using namespace GNDStk;
      using namespace basic;
   }

}
}
