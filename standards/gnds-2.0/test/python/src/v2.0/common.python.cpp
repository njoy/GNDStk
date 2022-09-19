
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace python = pybind11;

// v2.0 interface
namespace python_v2_0 {

// common declarations
namespace python_common {
   void wrapQ(python::module &);
   void wrapEnergy(python::module &);
   void wrapProduct(python::module &);
   void wrapProducts(python::module &);
   void wrapMass(python::module &);
   void wrapProbability(python::module &);
   void wrapTemperature(python::module &);
   void wrapExternalFile(python::module &);
   void wrapExternalFiles(python::module &);
} // namespace python_common

// common wrapper
void wrapCommon(python::module &module)
{
   // create the common submodule
   python::module submodule = module.def_submodule(
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
