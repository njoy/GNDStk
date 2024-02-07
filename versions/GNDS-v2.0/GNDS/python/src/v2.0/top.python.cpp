
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// project GNDS
// version v2.0
namespace python_GNDS {
namespace python_v2_0 {

   // namespace top: class wrapper declarations
   namespace python_top {
      void wrapFissionFragmentData(pybind11::module &);
      void wrapPoPs(pybind11::module &);
      void wrapReactionSuite(pybind11::module &);
      void wrapCovarianceSuite(pybind11::module &);
   } // namespace python_top

   // namespace top: wrapper
   void wrapTop(pybind11::module &module)
   {
      // top
      pybind11::module submodule = module.def_submodule(
         "top",
         "GNDS v2.0 top"
      );

      // top classes
      python_top::wrapFissionFragmentData(submodule);
      python_top::wrapPoPs(submodule);
      python_top::wrapReactionSuite(submodule);
      python_top::wrapCovarianceSuite(submodule);
   }

} // namespace python_v2_0
} // namespace python_GNDS
