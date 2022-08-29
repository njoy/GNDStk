
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace python = pybind11;

// v2.0 interface
namespace python_v2_0 {

// fissionFragmentData declarations
namespace python_fissionFragmentData {
   void wrapRate(python::module &);
   void wrapDelayedNeutron(python::module &);
   void wrapDelayedNeutrons(python::module &);
   void wrapFissionFragmentData(python::module &);
} // namespace python_fissionFragmentData

// fissionFragmentData wrapper
void wrapFissionFragmentData(python::module &module)
{
   // create the fissionFragmentData submodule
   python::module submodule = module.def_submodule(
      "fissionFragmentData",
      "try v2.0 fissionFragmentData"
   );

   // wrap fissionFragmentData components
   python_fissionFragmentData::wrapRate(submodule);
   python_fissionFragmentData::wrapDelayedNeutron(submodule);
   python_fissionFragmentData::wrapDelayedNeutrons(submodule);
   python_fissionFragmentData::wrapFissionFragmentData(submodule);
};

} // namespace python_v2_0
