
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace python = pybind11;

// v2.0 interface
namespace python_v2_0 {

// pops declarations
namespace python_pops {
   void wrapStandard(python::module &);
   void wrapLogNormal(python::module &);
   void wrapInterval(python::module &);
   void wrapConfidenceIntervals(python::module &);
   void wrapPdf(python::module &);
   void wrapUncertainty(python::module &);
   void wrapAlias(python::module &);
   void wrapMetaStable(python::module &);
   void wrapAliases(python::module &);
   void wrapCharge(python::module &);
   void wrapHalflife(python::module &);
   void wrapMass(python::module &);
   void wrapSpin(python::module &);
   void wrapParity(python::module &);
   void wrapProbability(python::module &);
   void wrapShell(python::module &);
   void wrapInternalConversionCoefficients(python::module &);
   void wrapPhotonEmissionProbabilities(python::module &);
   void wrapQ(python::module &);
   void wrapProduct(python::module &);
   void wrapProducts(python::module &);
   void wrapDecay(python::module &);
   void wrapDecayPath(python::module &);
   void wrapContinuum(python::module &);
   void wrapDiscreteEnergy(python::module &);
   void wrapIntensity(python::module &);
   void wrapInternalPairFormationCoefficient(python::module &);
   void wrapPositronEmissionIntensity(python::module &);
   void wrapDiscrete(python::module &);
   void wrapSpectrum(python::module &);
   void wrapSpectra(python::module &);
   void wrapDecayMode(python::module &);
   void wrapDecayModes(python::module &);
   void wrapAverageEnergy(python::module &);
   void wrapAverageEnergies(python::module &);
   void wrapDecayData(python::module &);
   void wrapGaugeBoson(python::module &);
   void wrapGaugeBosons(python::module &);
   void wrapLepton(python::module &);
   void wrapLeptons(python::module &);
   void wrapBaryon(python::module &);
   void wrapBaryons(python::module &);
   void wrapBindingEnergy(python::module &);
   void wrapConfiguration(python::module &);
   void wrapConfigurations(python::module &);
   void wrapAtomic(python::module &);
   void wrapEnergy(python::module &);
   void wrapNucleus(python::module &);
   void wrapNuclide(python::module &);
   void wrapNuclides(python::module &);
   void wrapIsotope(python::module &);
   void wrapIsotopes(python::module &);
   void wrapChemicalElement(python::module &);
   void wrapChemicalElements(python::module &);
   void wrapUnorthodoxes(python::module &);
   void wrapPoPs_database(python::module &);
   void wrapUnorthodox(python::module &);
} // namespace python_pops

// pops wrapper
void wrapPops(python::module &module)
{
   // create the pops submodule
   python::module submodule = module.def_submodule(
      "pops",
      "test v2.0 pops"
   );

   // wrap pops components
   python_pops::wrapStandard(submodule);
   python_pops::wrapLogNormal(submodule);
   python_pops::wrapInterval(submodule);
   python_pops::wrapConfidenceIntervals(submodule);
   python_pops::wrapPdf(submodule);
   python_pops::wrapUncertainty(submodule);
   python_pops::wrapAlias(submodule);
   python_pops::wrapMetaStable(submodule);
   python_pops::wrapAliases(submodule);
   python_pops::wrapCharge(submodule);
   python_pops::wrapHalflife(submodule);
   python_pops::wrapMass(submodule);
   python_pops::wrapSpin(submodule);
   python_pops::wrapParity(submodule);
   python_pops::wrapProbability(submodule);
   python_pops::wrapShell(submodule);
   python_pops::wrapInternalConversionCoefficients(submodule);
   python_pops::wrapPhotonEmissionProbabilities(submodule);
   python_pops::wrapQ(submodule);
   python_pops::wrapProduct(submodule);
   python_pops::wrapProducts(submodule);
   python_pops::wrapDecay(submodule);
   python_pops::wrapDecayPath(submodule);
   python_pops::wrapContinuum(submodule);
   python_pops::wrapDiscreteEnergy(submodule);
   python_pops::wrapIntensity(submodule);
   python_pops::wrapInternalPairFormationCoefficient(submodule);
   python_pops::wrapPositronEmissionIntensity(submodule);
   python_pops::wrapDiscrete(submodule);
   python_pops::wrapSpectrum(submodule);
   python_pops::wrapSpectra(submodule);
   python_pops::wrapDecayMode(submodule);
   python_pops::wrapDecayModes(submodule);
   python_pops::wrapAverageEnergy(submodule);
   python_pops::wrapAverageEnergies(submodule);
   python_pops::wrapDecayData(submodule);
   python_pops::wrapGaugeBoson(submodule);
   python_pops::wrapGaugeBosons(submodule);
   python_pops::wrapLepton(submodule);
   python_pops::wrapLeptons(submodule);
   python_pops::wrapBaryon(submodule);
   python_pops::wrapBaryons(submodule);
   python_pops::wrapBindingEnergy(submodule);
   python_pops::wrapConfiguration(submodule);
   python_pops::wrapConfigurations(submodule);
   python_pops::wrapAtomic(submodule);
   python_pops::wrapEnergy(submodule);
   python_pops::wrapNucleus(submodule);
   python_pops::wrapNuclide(submodule);
   python_pops::wrapNuclides(submodule);
   python_pops::wrapIsotope(submodule);
   python_pops::wrapIsotopes(submodule);
   python_pops::wrapChemicalElement(submodule);
   python_pops::wrapChemicalElements(submodule);
   python_pops::wrapUnorthodoxes(submodule);
   python_pops::wrapPoPs_database(submodule);
   python_pops::wrapUnorthodox(submodule);
};

} // namespace python_v2_0
