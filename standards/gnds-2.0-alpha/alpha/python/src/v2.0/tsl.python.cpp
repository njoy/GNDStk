
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace python = pybind11;

// v2.0 interface
namespace python_v2_0 {

// tsl declarations
namespace python_tsl {
   void wrapThermalNeutronScatteringLaw(python::module &);
   void wrapUnorthodox(python::module &);
   void wrapUnorthodoxes(python::module &);
   void wrapThermalNeutronScatteringLaw1d(python::module &);
   void wrapS_table(python::module &);
   void wrapThermalNeutronScatteringLaw_coherentElastic(python::module &);
   void wrapBoundAtomCrossSection(python::module &);
   void wrapDebyeWallerIntegral(python::module &);
   void wrapThermalNeutronScatteringLaw_incoherentElastic(python::module &);
   void wrapE_critical(python::module &);
   void wrapE_max(python::module &);
   void wrapSCTApproximation(python::module &);
   void wrapFreeGasApproximation(python::module &);
   void wrapSelfScatteringKernel(python::module &);
   void wrapT_effective(python::module &);
   void wrapScatteringAtom(python::module &);
   void wrapScatteringAtoms(python::module &);
   void wrapThermalNeutronScatteringLaw_incoherentInelastic(python::module &);
} // namespace python_tsl

// tsl wrapper
void wrapTsl(python::module &module)
{
   // create the tsl submodule
   python::module submodule = module.def_submodule(
      "tsl",
      "alpha v2.0 tsl"
   );

   // wrap tsl components
   python_tsl::wrapThermalNeutronScatteringLaw(submodule);
   python_tsl::wrapUnorthodox(submodule);
   python_tsl::wrapUnorthodoxes(submodule);
   python_tsl::wrapThermalNeutronScatteringLaw1d(submodule);
   python_tsl::wrapS_table(submodule);
   python_tsl::wrapThermalNeutronScatteringLaw_coherentElastic(submodule);
   python_tsl::wrapBoundAtomCrossSection(submodule);
   python_tsl::wrapDebyeWallerIntegral(submodule);
   python_tsl::wrapThermalNeutronScatteringLaw_incoherentElastic(submodule);
   python_tsl::wrapE_critical(submodule);
   python_tsl::wrapE_max(submodule);
   python_tsl::wrapSCTApproximation(submodule);
   python_tsl::wrapFreeGasApproximation(submodule);
   python_tsl::wrapSelfScatteringKernel(submodule);
   python_tsl::wrapT_effective(submodule);
   python_tsl::wrapScatteringAtom(submodule);
   python_tsl::wrapScatteringAtoms(submodule);
   python_tsl::wrapThermalNeutronScatteringLaw_incoherentInelastic(submodule);
};

} // namespace python_v2_0
