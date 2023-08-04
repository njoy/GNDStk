
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

// project GNDS
namespace python_GNDS {

   // version v2.0: namespace wrapper declarations
   namespace python_v2_0 {
      void wrapG2d(py::module &);
      void wrapG3d(py::module &);
      void wrapGeneral(py::module &);
      void wrapReduced(py::module &);
      void wrapTop(py::module &);
   } // namespace python_v2_0

   // version v2.0: wrapper
   void wrapV2_0(py::module &module)
   {
      // v2.0
      py::module submodule = module.def_submodule(
         "v2_0",
         "GNDS v2.0"
      );

      // v2.0 namespaces
      python_v2_0::wrapG2d(submodule);
      python_v2_0::wrapG3d(submodule);
      python_v2_0::wrapGeneral(submodule);
      python_v2_0::wrapReduced(submodule);
      python_v2_0::wrapTop(submodule);
   }

} // namespace GNDS_version
