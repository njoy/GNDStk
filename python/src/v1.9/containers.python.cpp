
// THIS FILE WAS AUTO-GENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace python = pybind11;

// v1.9 interface
namespace python_v1_9 {

// containers declarations
namespace python_containers {
   void wrapAxis(python::module &);
   void wrapLink(python::module &);
   void wrapValues(python::module &);
   void wrapGrid(python::module &);
   void wrapAxes(python::module &);
   void wrapXYs1d(python::module &);
   void wrapRegions1d(python::module &);
} // namespace python_containers

// containers wrapper
void wrapContainers(python::module &module)
{
   // create the containers submodule
   python::module submodule = module.def_submodule(
      "containers",
      "GNDS v1.9 containers"
   );

   // wrap containers components
   python_containers::wrapAxis(submodule);
   python_containers::wrapLink(submodule);
   python_containers::wrapValues(submodule);
   python_containers::wrapGrid(submodule);
   python_containers::wrapAxes(submodule);
   python_containers::wrapXYs1d(submodule);
   python_containers::wrapRegions1d(submodule);
};

} // namespace python_v1_9
