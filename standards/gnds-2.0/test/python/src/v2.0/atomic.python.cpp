
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

// v2.0 interface
namespace python_v2_0 {

// atomic declarations
namespace python_atomic {
   void wrapFormFactor(py::module &);
   void wrapRealAnomalousFactor(py::module &);
   void wrapImaginaryAnomalousFactor(py::module &);
   void wrapCoherentPhotonScattering(py::module &);
   void wrapScatteringFactor(py::module &);
   void wrapIncoherentPhotonScattering(py::module &);
} // namespace python_atomic

// wrapper for atomic
void wrapAtomic(py::module &module)
{
   // create the atomic submodule
   py::module submodule = module.def_submodule(
      "atomic",
      "test v2.0 atomic"
   );

   // wrap atomic components
   python_atomic::wrapFormFactor(submodule);
   python_atomic::wrapRealAnomalousFactor(submodule);
   python_atomic::wrapImaginaryAnomalousFactor(submodule);
   python_atomic::wrapCoherentPhotonScattering(submodule);
   python_atomic::wrapScatteringFactor(submodule);
   python_atomic::wrapIncoherentPhotonScattering(submodule);
};

} // namespace python_v2_0
