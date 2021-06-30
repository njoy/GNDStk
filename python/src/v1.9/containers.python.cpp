
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace python = pybind11;

// v1.9 interface
namespace v1_9 {

// containers declarations
namespace containers {
   void wrapAxis(python::module &);
   void wrapLink(python::module &);
   void wrapValues(python::module &);
   void wrapGrid(python::module &);
   void wrapAxes(python::module &);
   void wrapXYs1d(python::module &);
   void wrapRegions1d(python::module &);
} // namespace containers

// containers wrapper
void wrapContainers(python::module &module)
{
   // create the containers submodule
   python::module submodule = module.def_submodule(
      "containers",
      "GNDS v1.9 containers"
   );

   // wrap containers components
   containers::wrapAxis(submodule);
   containers::wrapLink(submodule);
   containers::wrapValues(submodule);
   containers::wrapGrid(submodule);
   containers::wrapAxes(submodule);
   containers::wrapXYs1d(submodule);
   containers::wrapRegions1d(submodule);
};

} // namespace v1_9
