
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// project GNDS
namespace python_GNDS {

   // version v2.0: enum wrapper declarations
   namespace python_v2_0 {
   namespace python_enums {
      void wrapBoundaryCondition(pybind11::module &);
      void wrapContributorType(pybind11::module &);
      void wrapDateType(pybind11::module &);
      void wrapDecayType(pybind11::module &);
      void wrapEncoding(pybind11::module &);
      void wrapEnergy(pybind11::module &);
      void wrapFrame(pybind11::module &);
      void wrapGridStyle(pybind11::module &);
      void wrapHashAlgorithm(pybind11::module &);
      void wrapInteraction(pybind11::module &);
      void wrapInterpolation(pybind11::module &);
      void wrapInterpolationQualifier(pybind11::module &);
      void wrapLength(pybind11::module &);
      void wrapParity(pybind11::module &);
      void wrapRelationType(pybind11::module &);
      void wrapStorageOrder(pybind11::module &);
   } // namespace python_enums
   } // namespace python_v2_0

   // version v2.0: namespace wrapper declarations
   namespace python_v2_0 {
      void wrapG2d(pybind11::module &);
      void wrapG3d(pybind11::module &);
      void wrapGeneral(pybind11::module &);
      void wrapReduced(pybind11::module &);
      void wrapTop(pybind11::module &);
   } // namespace python_v2_0

   // version v2.0: wrapper
   void wrapV2_0(pybind11::module &module)
   {
      // v2.0
      pybind11::module submodule = module.def_submodule(
         "v2_0",
         "GNDS v2.0"
      );

      // v2.0 enumerations
      python_v2_0::python_enums::wrapBoundaryCondition(submodule);
      python_v2_0::python_enums::wrapContributorType(submodule);
      python_v2_0::python_enums::wrapDateType(submodule);
      python_v2_0::python_enums::wrapDecayType(submodule);
      python_v2_0::python_enums::wrapEncoding(submodule);
      python_v2_0::python_enums::wrapEnergy(submodule);
      python_v2_0::python_enums::wrapFrame(submodule);
      python_v2_0::python_enums::wrapGridStyle(submodule);
      python_v2_0::python_enums::wrapHashAlgorithm(submodule);
      python_v2_0::python_enums::wrapInteraction(submodule);
      python_v2_0::python_enums::wrapInterpolation(submodule);
      python_v2_0::python_enums::wrapInterpolationQualifier(submodule);
      python_v2_0::python_enums::wrapLength(submodule);
      python_v2_0::python_enums::wrapParity(submodule);
      python_v2_0::python_enums::wrapRelationType(submodule);
      python_v2_0::python_enums::wrapStorageOrder(submodule);

      // v2.0 namespaces
      python_v2_0::wrapG2d(submodule);
      python_v2_0::wrapG3d(submodule);
      python_v2_0::wrapGeneral(submodule);
      python_v2_0::wrapReduced(submodule);
      python_v2_0::wrapTop(submodule);
   }

} // namespace python_GNDS
