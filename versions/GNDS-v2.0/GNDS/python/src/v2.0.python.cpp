
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace python = pybind11;

// project GNDS
namespace python_GNDS {

   // version v2.0: enum wrapper declarations
   namespace python_v2_0 {
   namespace python_enums {
      void wrapBoundaryCondition(python::module &);
      void wrapContributorType(python::module &);
      void wrapDateType(python::module &);
      void wrapDecayType(python::module &);
      void wrapEncoding(python::module &);
      void wrapEnergy(python::module &);
      void wrapFrame(python::module &);
      void wrapGridStyle(python::module &);
      void wrapHashAlgorithm(python::module &);
      void wrapInteraction(python::module &);
      void wrapInterpolation(python::module &);
      void wrapInterpolationQualifier(python::module &);
      void wrapLength(python::module &);
      void wrapParity(python::module &);
      void wrapRelationType(python::module &);
      void wrapStorageOrder(python::module &);
   } // namespace python_enums
   } // namespace python_v2_0

   // version v2.0: namespace wrapper declarations
   namespace python_v2_0 {
      void wrapG2d(python::module &);
      void wrapG3d(python::module &);
      void wrapGeneral(python::module &);
      void wrapReduced(python::module &);
      void wrapTop(python::module &);
   } // namespace python_v2_0

   // version v2.0: wrapper
   void wrapV2_0(python::module &module)
   {
      // v2.0
      python::module submodule = module.def_submodule(
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
