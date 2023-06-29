
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

// v2.0 interface
namespace python_v2_0 {

// common declarations
namespace python_common {
   void wrapQ(py::module &);
   void wrapEnergy(py::module &);
   void wrapProduct(py::module &);
   void wrapProducts(py::module &);
   void wrapMass(py::module &);
   void wrapProbability(py::module &);
   void wrapTemperature(py::module &);
   void wrapExternalFile(py::module &);
   void wrapExternalFiles(py::module &);
} // namespace python_common

// wrapper for common
void wrapCommon(py::module &module)
{
   // create the common submodule
   py::module submodule = module.def_submodule(
      "common",
      "test v2.0 common"
   );

   // wrap common components
   python_common::wrapQ(submodule);
   python_common::wrapEnergy(submodule);
   python_common::wrapProduct(submodule);
   python_common::wrapProducts(submodule);
   python_common::wrapMass(submodule);
   python_common::wrapProbability(submodule);
   python_common::wrapTemperature(submodule);
   python_common::wrapExternalFile(submodule);
   python_common::wrapExternalFiles(submodule);
};

} // namespace python_v2_0
