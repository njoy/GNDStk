
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

// v2.0 interface
namespace python_v2_0 {

// reduced declarations
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

// wrapper for reduced
void wrapReduced(py::module &module)
{
   // create the reduced submodule
   py::module submodule = module.def_submodule(
      "reduced",
      "GNDS v2.0 reduced"
   );

   // wrap reduced components
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