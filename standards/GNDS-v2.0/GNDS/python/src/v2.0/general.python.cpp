
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

// v2.0 interface
namespace python_v2_0 {

// general declarations
namespace python_general {
   void wrapAuthor(py::module &);
   void wrapAuthors(py::module &);
   void wrapDate(py::module &);
   void wrapDates(py::module &);
   void wrapTitle(py::module &);
   void wrapBody(py::module &);
   void wrapEndfCompatible(py::module &);
   void wrapDocumentation(py::module &);
   void wrapTemperature(py::module &);
   void wrapProjectileEnergyDomain(py::module &);
   void wrapEvaluated(py::module &);
   void wrapCrossSectionReconstructed(py::module &);
   void wrapStyles(py::module &);
   void wrapAlias(py::module &);
   void wrapMetaStable(py::module &);
   void wrapAliases(py::module &);
   void wrapValues(py::module &);
   void wrapArray(py::module &);
   void wrapCovariance(py::module &);
   void wrapStandard(py::module &);
   void wrapListOfCovariances(py::module &);
   void wrapAxis(py::module &);
   void wrapLink(py::module &);
   void wrapGrid(py::module &);
   void wrapAxes(py::module &);
   void wrapUncertainty(py::module &);
   void wrapDouble(py::module &);
   void wrapMass(py::module &);
   void wrapFraction(py::module &);
   void wrapSpin(py::module &);
   void wrapInteger(py::module &);
   void wrapParity(py::module &);
   void wrapCharge(py::module &);
   void wrapString(py::module &);
   void wrapHalflife(py::module &);
   void wrapProbability(py::module &);
   void wrapConstant1d(py::module &);
   void wrapXYs1d(py::module &);
   void wrapLegendre(py::module &);
   void wrapRegions1d(py::module &);
   void wrapPolynomial1d(py::module &);
   void wrapReference(py::module &);
   void wrapBranching1d(py::module &);
   void wrapBranching3d(py::module &);
   void wrapUnspecified(py::module &);
   void wrapMultiplicity(py::module &);
   void wrapThermalNeutronScatteringLaw(py::module &);
   void wrapIsotropic2d(py::module &);
   void wrapFunction1ds(py::module &);
   void wrapXYs2d(py::module &);
   void wrapAngular(py::module &);
   void wrapNBodyPhaseSpace(py::module &);
   void wrapPrimaryGamma(py::module &);
   void wrapDiscreteGamma(py::module &);
   void wrapU(py::module &);
   void wrapTheta(py::module &);
   void wrapG(py::module &);
   void wrapGeneralEvaporation(py::module &);
   void wrapEvaporation(py::module &);
   void wrapWeighted(py::module &);
   void wrapWeightedFunctionals(py::module &);
   void wrapSimpleMaxwellianFission(py::module &);
   void wrapEFL(py::module &);
   void wrapEFH(py::module &);
   void wrapT_M(py::module &);
   void wrapMadlandNix(py::module &);
   void wrapEnergy(py::module &);
   void wrapUncorrelated(py::module &);
   void wrapFunction2ds(py::module &);
   void wrapRegions2d(py::module &);
   void wrapRecoil(py::module &);
   void wrapAngularTwoBody(py::module &);
   void wrapXYs3d(py::module &);
   void wrapEnergyAngular(py::module &);
   void wrapF(py::module &);
   void wrapR(py::module &);
   void wrapKalbachMann(py::module &);
   void wrapAngularEnergy(py::module &);
   void wrapRutherfordScattering(py::module &);
   void wrapNuclearTerm(py::module &);
   void wrapRealInterferenceTerm(py::module &);
   void wrapImaginaryInterferenceTerm(py::module &);
   void wrapNuclearAmplitudeExpansion(py::module &);
   void wrapNuclearPlusInterference(py::module &);
   void wrapCoulombPlusNuclearElastic(py::module &);
   void wrapFormFactor(py::module &);
   void wrapRealAnomalousFactor(py::module &);
   void wrapImaginaryAnomalousFactor(py::module &);
   void wrapCoherentPhotonScattering(py::module &);
   void wrapScatteringFactor(py::module &);
   void wrapIncoherentPhotonScattering(py::module &);
   void wrapDistribution(py::module &);
   void wrapQ(py::module &);
   void wrapAverageProductEnergy(py::module &);
   void wrapProduct(py::module &);
   void wrapProducts(py::module &);
   void wrapDecay(py::module &);
   void wrapDecayPath(py::module &);
   void wrapShell(py::module &);
   void wrapPhotonEmissionProbabilities(py::module &);
   void wrapIntensity(py::module &);
   void wrapInternalConversionCoefficients(py::module &);
   void wrapPositronEmissionIntensity(py::module &);
   void wrapDiscrete(py::module &);
   void wrapContinuum(py::module &);
   void wrapSpectrum(py::module &);
   void wrapSpectra(py::module &);
   void wrapDecayMode(py::module &);
   void wrapDecayModes(py::module &);
   void wrapAverageEnergy(py::module &);
   void wrapAverageEnergies(py::module &);
   void wrapDecayData(py::module &);
   void wrapBaryon(py::module &);
   void wrapBaryons(py::module &);
   void wrapBindingEnergy(py::module &);
   void wrapConfiguration(py::module &);
   void wrapConfigurations(py::module &);
   void wrapAtomic(py::module &);
   void wrapNucleus(py::module &);
   void wrapTime(py::module &);
   void wrapYields(py::module &);
   void wrapIncidentEnergy(py::module &);
   void wrapIncidentEnergies(py::module &);
   void wrapElapsedTime(py::module &);
   void wrapElapsedTimes(py::module &);
   void wrapProductYield(py::module &);
   void wrapProductYields(py::module &);
   void wrapRate(py::module &);
   void wrapDelayedNeutron(py::module &);
   void wrapDelayedNeutrons(py::module &);
   void wrapPromptProductKE(py::module &);
   void wrapPromptNeutronKE(py::module &);
   void wrapDelayedNeutronKE(py::module &);
   void wrapPromptGammaEnergy(py::module &);
   void wrapDelayedGammaEnergy(py::module &);
   void wrapDelayedBetaEnergy(py::module &);
   void wrapNeutrinoEnergy(py::module &);
   void wrapNonNeutrinoEnergy(py::module &);
   void wrapTotalEnergy(py::module &);
   void wrapFissionEnergyRelease(py::module &);
   void wrapFissionEnergyReleases(py::module &);
   void wrapNuclide(py::module &);
   void wrapNuclides(py::module &);
   void wrapIsotope(py::module &);
   void wrapIsotopes(py::module &);
   void wrapChemicalElement(py::module &);
   void wrapChemicalElements(py::module &);
   void wrapUnorthodox(py::module &);
   void wrapUnorthodoxes(py::module &);
   void wrapGaugeBoson(py::module &);
   void wrapGaugeBosons(py::module &);
   void wrapLepton(py::module &);
   void wrapLeptons(py::module &);
   void wrapScatteringRadius(py::module &);
   void wrapColumn(py::module &);
   void wrapColumnHeaders(py::module &);
   void wrapData(py::module &);
   void wrapTable(py::module &);
   void wrapResonanceParameters(py::module &);
   void wrapBreitWigner(py::module &);
   void wrapHardSphereRadius(py::module &);
   void wrapResonanceReaction(py::module &);
   void wrapResonanceReactions(py::module &);
   void wrapChannel(py::module &);
   void wrapChannels(py::module &);
   void wrapSpinGroup(py::module &);
   void wrapSpinGroups(py::module &);
   void wrapRMatrix(py::module &);
   void wrapResolved(py::module &);
   void wrapLevelSpacing(py::module &);
   void wrapWidth(py::module &);
   void wrapWidths(py::module &);
   void wrapJ(py::module &);
   void wrapJs(py::module &);
   void wrapL(py::module &);
   void wrapLs(py::module &);
   void wrapTabulatedWidths(py::module &);
   void wrapUnresolved(py::module &);
   void wrapResonances(py::module &);
   void wrapResolvedRegion(py::module &);
   void wrapFastRegion(py::module &);
   void wrapUnresolvedRegion(py::module &);
   void wrapBackground(py::module &);
   void wrapResonancesWithBackground(py::module &);
   void wrapThermalNeutronScatteringLaw1d(py::module &);
   void wrapCrossSection(py::module &);
   void wrapOutputChannel(py::module &);
   void wrapGridded2d(py::module &);
   void wrapS_table(py::module &);
   void wrapThermalNeutronScatteringLaw_coherentElastic(py::module &);
   void wrapBoundAtomCrossSection(py::module &);
   void wrapDebyeWallerIntegral(py::module &);
   void wrapThermalNeutronScatteringLaw_incoherentElastic(py::module &);
   void wrapE_critical(py::module &);
   void wrapE_max(py::module &);
   void wrapGridded3d(py::module &);
   void wrapSCTApproximation(py::module &);
   void wrapFreeGasApproximation(py::module &);
   void wrapSelfScatteringKernel(py::module &);
   void wrapT_effective(py::module &);
   void wrapScatteringAtom(py::module &);
   void wrapScatteringAtoms(py::module &);
   void wrapThermalNeutronScatteringLaw_incoherentInelastic(py::module &);
   void wrapDoubleDifferentialCrossSection(py::module &);
   void wrapReaction(py::module &);
   void wrapReactions(py::module &);
   void wrapConversion(py::module &);
   void wrapENDFconversionFlags(py::module &);
   void wrapInstitution(py::module &);
   void wrapApplicationData(py::module &);
   void wrapExternalFile(py::module &);
   void wrapExternalFiles(py::module &);
   void wrapAdd(py::module &);
   void wrapSummands(py::module &);
   void wrapCrossSectionSum(py::module &);
   void wrapCrossSectionSums(py::module &);
   void wrapMultiplicitySum(py::module &);
   void wrapMultiplicitySums(py::module &);
   void wrapSums(py::module &);
   void wrapProduction(py::module &);
   void wrapProductions(py::module &);
   void wrapFissionComponent(py::module &);
   void wrapFissionComponents(py::module &);
   void wrapOrphanProduct(py::module &);
   void wrapOrphanProducts(py::module &);
   void wrapIncompleteReactions(py::module &);
   void wrapSlice(py::module &);
   void wrapSlices(py::module &);
   void wrapRowData(py::module &);
   void wrapColumnData(py::module &);
   void wrapCovarianceMatrix(py::module &);
   void wrapSummand(py::module &);
   void wrapSum(py::module &);
   void wrapShortRangeSelfScalingVariance(py::module &);
   void wrapMixed(py::module &);
   void wrapCovarianceSection(py::module &);
   void wrapCovarianceSections(py::module &);
   void wrapParameterLink(py::module &);
   void wrapParameters(py::module &);
   void wrapParameterCovarianceMatrix(py::module &);
   void wrapParameterCovariance(py::module &);
   void wrapAverageParameterCovariance(py::module &);
   void wrapParameterCovariances(py::module &);
} // namespace python_general

// wrapper for general
void wrapGeneral(py::module &module)
{
   // create the general submodule
   py::module submodule = module.def_submodule(
      "general",
      "GNDS v2.0 general"
   );

   // wrap general components
   python_general::wrapAuthor(submodule);
   python_general::wrapAuthors(submodule);
   python_general::wrapDate(submodule);
   python_general::wrapDates(submodule);
   python_general::wrapTitle(submodule);
   python_general::wrapBody(submodule);
   python_general::wrapEndfCompatible(submodule);
   python_general::wrapDocumentation(submodule);
   python_general::wrapTemperature(submodule);
   python_general::wrapProjectileEnergyDomain(submodule);
   python_general::wrapEvaluated(submodule);
   python_general::wrapCrossSectionReconstructed(submodule);
   python_general::wrapStyles(submodule);
   python_general::wrapAlias(submodule);
   python_general::wrapMetaStable(submodule);
   python_general::wrapAliases(submodule);
   python_general::wrapValues(submodule);
   python_general::wrapArray(submodule);
   python_general::wrapCovariance(submodule);
   python_general::wrapStandard(submodule);
   python_general::wrapListOfCovariances(submodule);
   python_general::wrapAxis(submodule);
   python_general::wrapLink(submodule);
   python_general::wrapGrid(submodule);
   python_general::wrapAxes(submodule);
   python_general::wrapUncertainty(submodule);
   python_general::wrapDouble(submodule);
   python_general::wrapMass(submodule);
   python_general::wrapFraction(submodule);
   python_general::wrapSpin(submodule);
   python_general::wrapInteger(submodule);
   python_general::wrapParity(submodule);
   python_general::wrapCharge(submodule);
   python_general::wrapString(submodule);
   python_general::wrapHalflife(submodule);
   python_general::wrapProbability(submodule);
   python_general::wrapConstant1d(submodule);
   python_general::wrapXYs1d(submodule);
   python_general::wrapLegendre(submodule);
   python_general::wrapRegions1d(submodule);
   python_general::wrapPolynomial1d(submodule);
   python_general::wrapReference(submodule);
   python_general::wrapBranching1d(submodule);
   python_general::wrapBranching3d(submodule);
   python_general::wrapUnspecified(submodule);
   python_general::wrapMultiplicity(submodule);
   python_general::wrapThermalNeutronScatteringLaw(submodule);
   python_general::wrapIsotropic2d(submodule);
   python_general::wrapFunction1ds(submodule);
   python_general::wrapXYs2d(submodule);
   python_general::wrapAngular(submodule);
   python_general::wrapNBodyPhaseSpace(submodule);
   python_general::wrapPrimaryGamma(submodule);
   python_general::wrapDiscreteGamma(submodule);
   python_general::wrapU(submodule);
   python_general::wrapTheta(submodule);
   python_general::wrapG(submodule);
   python_general::wrapGeneralEvaporation(submodule);
   python_general::wrapEvaporation(submodule);
   python_general::wrapWeighted(submodule);
   python_general::wrapWeightedFunctionals(submodule);
   python_general::wrapSimpleMaxwellianFission(submodule);
   python_general::wrapEFL(submodule);
   python_general::wrapEFH(submodule);
   python_general::wrapT_M(submodule);
   python_general::wrapMadlandNix(submodule);
   python_general::wrapEnergy(submodule);
   python_general::wrapUncorrelated(submodule);
   python_general::wrapFunction2ds(submodule);
   python_general::wrapRegions2d(submodule);
   python_general::wrapRecoil(submodule);
   python_general::wrapAngularTwoBody(submodule);
   python_general::wrapXYs3d(submodule);
   python_general::wrapEnergyAngular(submodule);
   python_general::wrapF(submodule);
   python_general::wrapR(submodule);
   python_general::wrapKalbachMann(submodule);
   python_general::wrapAngularEnergy(submodule);
   python_general::wrapRutherfordScattering(submodule);
   python_general::wrapNuclearTerm(submodule);
   python_general::wrapRealInterferenceTerm(submodule);
   python_general::wrapImaginaryInterferenceTerm(submodule);
   python_general::wrapNuclearAmplitudeExpansion(submodule);
   python_general::wrapNuclearPlusInterference(submodule);
   python_general::wrapCoulombPlusNuclearElastic(submodule);
   python_general::wrapFormFactor(submodule);
   python_general::wrapRealAnomalousFactor(submodule);
   python_general::wrapImaginaryAnomalousFactor(submodule);
   python_general::wrapCoherentPhotonScattering(submodule);
   python_general::wrapScatteringFactor(submodule);
   python_general::wrapIncoherentPhotonScattering(submodule);
   python_general::wrapDistribution(submodule);
   python_general::wrapQ(submodule);
   python_general::wrapAverageProductEnergy(submodule);
   python_general::wrapProduct(submodule);
   python_general::wrapProducts(submodule);
   python_general::wrapDecay(submodule);
   python_general::wrapDecayPath(submodule);
   python_general::wrapShell(submodule);
   python_general::wrapPhotonEmissionProbabilities(submodule);
   python_general::wrapIntensity(submodule);
   python_general::wrapInternalConversionCoefficients(submodule);
   python_general::wrapPositronEmissionIntensity(submodule);
   python_general::wrapDiscrete(submodule);
   python_general::wrapContinuum(submodule);
   python_general::wrapSpectrum(submodule);
   python_general::wrapSpectra(submodule);
   python_general::wrapDecayMode(submodule);
   python_general::wrapDecayModes(submodule);
   python_general::wrapAverageEnergy(submodule);
   python_general::wrapAverageEnergies(submodule);
   python_general::wrapDecayData(submodule);
   python_general::wrapBaryon(submodule);
   python_general::wrapBaryons(submodule);
   python_general::wrapBindingEnergy(submodule);
   python_general::wrapConfiguration(submodule);
   python_general::wrapConfigurations(submodule);
   python_general::wrapAtomic(submodule);
   python_general::wrapNucleus(submodule);
   python_general::wrapTime(submodule);
   python_general::wrapYields(submodule);
   python_general::wrapIncidentEnergy(submodule);
   python_general::wrapIncidentEnergies(submodule);
   python_general::wrapElapsedTime(submodule);
   python_general::wrapElapsedTimes(submodule);
   python_general::wrapProductYield(submodule);
   python_general::wrapProductYields(submodule);
   python_general::wrapRate(submodule);
   python_general::wrapDelayedNeutron(submodule);
   python_general::wrapDelayedNeutrons(submodule);
   python_general::wrapPromptProductKE(submodule);
   python_general::wrapPromptNeutronKE(submodule);
   python_general::wrapDelayedNeutronKE(submodule);
   python_general::wrapPromptGammaEnergy(submodule);
   python_general::wrapDelayedGammaEnergy(submodule);
   python_general::wrapDelayedBetaEnergy(submodule);
   python_general::wrapNeutrinoEnergy(submodule);
   python_general::wrapNonNeutrinoEnergy(submodule);
   python_general::wrapTotalEnergy(submodule);
   python_general::wrapFissionEnergyRelease(submodule);
   python_general::wrapFissionEnergyReleases(submodule);
   python_general::wrapNuclide(submodule);
   python_general::wrapNuclides(submodule);
   python_general::wrapIsotope(submodule);
   python_general::wrapIsotopes(submodule);
   python_general::wrapChemicalElement(submodule);
   python_general::wrapChemicalElements(submodule);
   python_general::wrapUnorthodox(submodule);
   python_general::wrapUnorthodoxes(submodule);
   python_general::wrapGaugeBoson(submodule);
   python_general::wrapGaugeBosons(submodule);
   python_general::wrapLepton(submodule);
   python_general::wrapLeptons(submodule);
   python_general::wrapScatteringRadius(submodule);
   python_general::wrapColumn(submodule);
   python_general::wrapColumnHeaders(submodule);
   python_general::wrapData(submodule);
   python_general::wrapTable(submodule);
   python_general::wrapResonanceParameters(submodule);
   python_general::wrapBreitWigner(submodule);
   python_general::wrapHardSphereRadius(submodule);
   python_general::wrapResonanceReaction(submodule);
   python_general::wrapResonanceReactions(submodule);
   python_general::wrapChannel(submodule);
   python_general::wrapChannels(submodule);
   python_general::wrapSpinGroup(submodule);
   python_general::wrapSpinGroups(submodule);
   python_general::wrapRMatrix(submodule);
   python_general::wrapResolved(submodule);
   python_general::wrapLevelSpacing(submodule);
   python_general::wrapWidth(submodule);
   python_general::wrapWidths(submodule);
   python_general::wrapJ(submodule);
   python_general::wrapJs(submodule);
   python_general::wrapL(submodule);
   python_general::wrapLs(submodule);
   python_general::wrapTabulatedWidths(submodule);
   python_general::wrapUnresolved(submodule);
   python_general::wrapResonances(submodule);
   python_general::wrapResolvedRegion(submodule);
   python_general::wrapFastRegion(submodule);
   python_general::wrapUnresolvedRegion(submodule);
   python_general::wrapBackground(submodule);
   python_general::wrapResonancesWithBackground(submodule);
   python_general::wrapThermalNeutronScatteringLaw1d(submodule);
   python_general::wrapCrossSection(submodule);
   python_general::wrapOutputChannel(submodule);
   python_general::wrapGridded2d(submodule);
   python_general::wrapS_table(submodule);
   python_general::wrapThermalNeutronScatteringLaw_coherentElastic(submodule);
   python_general::wrapBoundAtomCrossSection(submodule);
   python_general::wrapDebyeWallerIntegral(submodule);
   python_general::wrapThermalNeutronScatteringLaw_incoherentElastic(submodule);
   python_general::wrapE_critical(submodule);
   python_general::wrapE_max(submodule);
   python_general::wrapGridded3d(submodule);
   python_general::wrapSCTApproximation(submodule);
   python_general::wrapFreeGasApproximation(submodule);
   python_general::wrapSelfScatteringKernel(submodule);
   python_general::wrapT_effective(submodule);
   python_general::wrapScatteringAtom(submodule);
   python_general::wrapScatteringAtoms(submodule);
   python_general::wrapThermalNeutronScatteringLaw_incoherentInelastic(submodule);
   python_general::wrapDoubleDifferentialCrossSection(submodule);
   python_general::wrapReaction(submodule);
   python_general::wrapReactions(submodule);
   python_general::wrapConversion(submodule);
   python_general::wrapENDFconversionFlags(submodule);
   python_general::wrapInstitution(submodule);
   python_general::wrapApplicationData(submodule);
   python_general::wrapExternalFile(submodule);
   python_general::wrapExternalFiles(submodule);
   python_general::wrapAdd(submodule);
   python_general::wrapSummands(submodule);
   python_general::wrapCrossSectionSum(submodule);
   python_general::wrapCrossSectionSums(submodule);
   python_general::wrapMultiplicitySum(submodule);
   python_general::wrapMultiplicitySums(submodule);
   python_general::wrapSums(submodule);
   python_general::wrapProduction(submodule);
   python_general::wrapProductions(submodule);
   python_general::wrapFissionComponent(submodule);
   python_general::wrapFissionComponents(submodule);
   python_general::wrapOrphanProduct(submodule);
   python_general::wrapOrphanProducts(submodule);
   python_general::wrapIncompleteReactions(submodule);
   python_general::wrapSlice(submodule);
   python_general::wrapSlices(submodule);
   python_general::wrapRowData(submodule);
   python_general::wrapColumnData(submodule);
   python_general::wrapCovarianceMatrix(submodule);
   python_general::wrapSummand(submodule);
   python_general::wrapSum(submodule);
   python_general::wrapShortRangeSelfScalingVariance(submodule);
   python_general::wrapMixed(submodule);
   python_general::wrapCovarianceSection(submodule);
   python_general::wrapCovarianceSections(submodule);
   python_general::wrapParameterLink(submodule);
   python_general::wrapParameters(submodule);
   python_general::wrapParameterCovarianceMatrix(submodule);
   python_general::wrapParameterCovariance(submodule);
   python_general::wrapAverageParameterCovariance(submodule);
   python_general::wrapParameterCovariances(submodule);
};

} // namespace python_v2_0