
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

// v2.0 interface
namespace python_v2_0 {

// g3d declarations
namespace python_g3d {
   void wrapStarts(py::module &);
   void wrapLengths(py::module &);
   void wrapArray(py::module &);
} // namespace python_g3d

// wrapper for g3d
void wrapG3d(py::module &module)
{
   // create the g3d submodule
   py::module submodule = module.def_submodule(
      "g3d",
      "GNDS v2.0 g3d"
   );

   // wrap g3d components
   python_g3d::wrapStarts(submodule);
   python_g3d::wrapLengths(submodule);
   python_g3d::wrapArray(submodule);
};

} // namespace python_v2_0