
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace python = pybind11;

// v1.9 interface
namespace v1_9 {

// transport declarations
namespace transport {
   // void wrapCrossSection(python::module &);
   // void wrapReaction(python::module &);
   // void wrapReactions(python::module &);
   // void wrapReactionSuite(python::module &);
} // namespace transport

// transport wrapper
void wrapTransport(python::module &module)
{
   // create the transport submodule
   python::module submodule = module.def_submodule(
      "transport",
      "GNDS v1.9 transport"
   );

   // wrap transport components
   // transport::wrapCrossSection(submodule);
   // transport::wrapReaction(submodule);
   // transport::wrapReactions(submodule);
   // transport::wrapReactionSuite(submodule);
};

} // namespace v1_9
