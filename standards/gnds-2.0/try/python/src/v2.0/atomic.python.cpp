
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace python = pybind11;

// v2.0 interface
namespace python_v2_0 {

// atomic declarations
namespace python_atomic {
   void wrapFormFactor(python::module &);
   void wrapRealAnomalousFactor(python::module &);
   void wrapImaginaryAnomalousFactor(python::module &);
   void wrapCoherentPhotonScattering(python::module &);
   void wrapScatteringFactor(python::module &);
   void wrapIncoherentPhotonScattering(python::module &);
} // namespace python_atomic

// atomic wrapper
void wrapAtomic(python::module &module)
{
   // create the atomic submodule
   python::module submodule = module.def_submodule(
      "atomic",
      "try v2.0 atomic"
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