
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

// project GNDS
// version v2.0
namespace python_GNDS {
namespace python_v2_0 {

   // namespace reduced: class wrapper declarations
   namespace python_reduced {
      void wrapDouble(py::module &);
      void wrapPolynomial1d(py::module &);
      void wrapFunction1ds(py::module &);
      void wrapCrossSection(py::module &);
      void wrapDistribution(py::module &);
      void wrapProduct(py::module &);
      void wrapProducts(py::module &);
      void wrapOutputChannel(py::module &);
      void wrapNuclides(py::module &);
   } // namespace python_reduced

   // namespace reduced: wrapper
   void wrapReduced(py::module &module)
   {
      // reduced
      py::module submodule = module.def_submodule(
         "reduced",
         "GNDS v2.0 reduced"
      );

      // reduced classes
      python_reduced::wrapDouble(submodule);
      python_reduced::wrapPolynomial1d(submodule);
      python_reduced::wrapFunction1ds(submodule);
      python_reduced::wrapCrossSection(submodule);
      python_reduced::wrapDistribution(submodule);
      python_reduced::wrapProduct(submodule);
      python_reduced::wrapProducts(submodule);
      python_reduced::wrapOutputChannel(submodule);
      python_reduced::wrapNuclides(submodule);
   };

} // namespace python_v2_0
} // namespace python_GNDS
