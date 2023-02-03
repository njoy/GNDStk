
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace python = pybind11;

// v2.0 interface
namespace python_v2_0 {

// top declarations
namespace python_top {
   void wrapFissionFragmentData(python::module &);
   void wrapPoPs(python::module &);
   void wrapReactionSuite(python::module &);
   void wrapCovarianceSuite(python::module &);
} // namespace python_top

// top wrapper
void wrapTop(python::module &module)
{
   // create the top submodule
   python::module submodule = module.def_submodule(
      "top",
      "alpha v2.0 top"
   );

   // wrap top components
   python_top::wrapFissionFragmentData(submodule);
   python_top::wrapPoPs(submodule);
   python_top::wrapReactionSuite(submodule);
   python_top::wrapCovarianceSuite(submodule);
};

} // namespace python_v2_0
