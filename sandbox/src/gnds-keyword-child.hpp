
// macro, for keyword building
#define make_child(name,allow_multiple) \
   inline constexpr const child_t name(#name,allow_multiple)



// -----------------------------------------------------------------------------
// child_t
// -----------------------------------------------------------------------------

// Probably have this take <T> after we figure out node types, as with the
// data-structure project I'm working on in parallel
class child_t {
public:
   const char *const name;
   const bool allow_multiple;
   explicit constexpr child_t(const char *const n, const bool a) :
      name(n), allow_multiple(a)
   {
   }
};



// -----------------------------------------------------------------------------
// keywords
// Use our macro.
// -----------------------------------------------------------------------------

namespace child {

// ------------------------
// Singular/plural
// constructs
// ------------------------

make_child(averageEnergy,   true);
make_child(averageEnergies, false);

make_child(axis, true);
make_child(axes, false);

make_child(baryon,  true);
make_child(baryons, false);

make_child(channel,  true);
make_child(channels, false);

make_child(chemicalElement,  true);
make_child(chemicalElements, false);

make_child(configuration,  true);
make_child(configurations, false);

make_child(decayMode,  true);
make_child(decayModes, false);

make_child(duration,  true);
make_child(durations, false);

make_child(externalFile,  true);
make_child(externalFiles, false);

make_child(fissionComponent,  true);
make_child(fissionComponents, false);

make_child(isotope,  true);
make_child(isotopes, false);

make_child(J,  true);
make_child(Js, false);

make_child(lepton,  true);
make_child(leptons, false);

make_child(nuclide,  true);
make_child(nuclides, false);

make_child(production,  true);
make_child(productions, false);

make_child(product,  true);
make_child(products, false);

make_child(reaction,  true);
make_child(reactions, false);

make_child(resonanceReaction,  true);
make_child(resonanceReactions, false);

make_child(scatteringAtom,  true);
make_child(scatteringAtoms, false);

make_child(spectrum, true);
make_child(spectra, false);

make_child(spinGroup,  true);
make_child(spinGroups, false);

make_child(width,  true);
make_child(widths, false);

make_child(sum,  true);
make_child(sums, false);

make_child(L,  true);
make_child(Ls, false);

make_child(summand,  true);
make_child(summands, false);



// ------------------------
// Plain old keywords
// ------------------------

// fixme do more sorting/categorization etc.

// multiple = true
make_child(add, true);
make_child(averageParameterCovariance, true);
make_child(column, true);
make_child(conversion, true);
make_child(covariance, true);
make_child(covarianceMatrix, true);
make_child(crossSectionSum, true);
make_child(decay, true);
make_child(discrete, true);
make_child(grid, true);
make_child(Legendre, true);
make_child(metaStable, true);
make_child(multiplicitySum, true);
make_child(parameterLink, true);
make_child(regions1d, true);
make_child(section, true);
make_child(shell, true);
make_child(values, true);
make_child(weighted, true);
make_child(XYs1d, true);
make_child(XYs2d, true);

// multiple = false
make_child(aliases, false);
make_child(angular, false);
make_child(angularEnergy, false);
make_child(angularTwoBody, false);
make_child(applicationData, false);
make_child(array, false);
make_child(atomic, false);
make_child(averageProductEnergy, false);
make_child(background, false);
make_child(bindingEnergy, false);
make_child(branching1d, false);
make_child(branching3d, false);
make_child(BreitWigner, false);
make_child(characteristicCrossSection, false);
make_child(charge, false);
make_child(coherentElastic, false);
make_child(coherentPhotonScattering, false);
make_child(columnData, false);
make_child(columnHeaders, false);
make_child(constant1d, false);
make_child(continuum, false);
make_child(CoulombPlusNuclearElastic, false);
make_child(covarianceSections, false);
make_child(covarianceSuite, false);
make_child(crossSection, false);
make_child(crossSectionReconstructed, false);
make_child(crossSections, false);
make_child(cutoffEnergy, false);
make_child(data, false);
make_child(DebyeWaller, false);
make_child(decayData, false);
make_child(decayPath, false);
make_child(delayedBetaEnergy, false);
make_child(delayedGammaEnergy, false);
make_child(delayedNeutronKE, false);
make_child(discreteGamma, false);
make_child(distribution, false);
make_child(documentation, false);
make_child(documentations, false);
make_child(doubleDifferentialCrossSection, false);
make_child(e_critical, false);
make_child(EFH, false);
make_child(EFL, false);
make_child(e_max, false);
make_child(ENDFconversionFlags, false);
make_child(energy, false);
make_child(energyAngular, false);
make_child(evaluated, false);
make_child(evaporation, false);
make_child(f, false);
make_child(fastRegion, false);
make_child(fissionEnergyReleased, false);
make_child(fissionFragmentData, false);
make_child(fraction, false);
make_child(freeAtomCrossSection, false);
make_child(g, false);
make_child(gaugeBoson, false);
make_child(gaugeBosons, false);
make_child(generalEvaporation, false);
make_child(gridded2d, false);
make_child(gridded3d, false);
make_child(halflife, false);
make_child(hardSphereRadius, false);
make_child(imaginaryAnomalousFactor, false);
make_child(imaginaryInterferenceTerm, false);
make_child(incoherentElastic, false);
make_child(incoherentInelastic, false);
make_child(incoherentPhotonScattering, false);
make_child(incompleteReactions, false);
make_child(institution, false);
make_child(integer, false);
make_child(intensity, false);
make_child(internalConversionCoefficients, false);
make_child(internalPairFormationCoefficient, false);
make_child(isotropic2d, false);
make_child(KalbachMann, false);
make_child(levelSpacing, false);
make_child(link, false);
make_child(listOfCovariances, false);
make_child(MadlandNix, false);
make_child(mass, false);
make_child(mixed, false);
make_child(multiplicities, false);
make_child(multiplicity, false);
make_child(NBodyPhaseSpace, false);
make_child(neutrinoEnergy, false);
make_child(nonNeutrinoEnergy, false);
make_child(nuclearAmplitudeExpansion, false);
make_child(nuclearPlusInterference, false);
make_child(nuclearTerm, false);
make_child(nucleus, false);
make_child(orphanProducts, false);
make_child(outputChannel, false);
make_child(parameterCovariance, false);
make_child(parameterCovarianceMatrix, false);
make_child(parameterCovariances, false);
make_child(parameters, false);
make_child(parity, false);
make_child(photonEmissionProbabilities, false);
make_child(pids, false);
make_child(polynomial1d, false);
make_child(PoPs, false);
make_child(positronEmissionIntensity, false);
make_child(primaryGamma, false);
make_child(probability, false);
make_child(productYield, false);
make_child(productYields, false);
make_child(projectileEnergyDomain, false);
make_child(promptGammaEnergy, false);
make_child(promptNeutronKE, false);
make_child(promptProductKE, false);
make_child(Q, false);
make_child(r, false);
make_child(reactionSuite, false);
make_child(realAnomalousFactor, false);
make_child(realInterferenceTerm, false);
make_child(recoil, false);
make_child(reference, false);
make_child(regions2d, false);
make_child(resolved, false);
make_child(resolvedRegion, false);
make_child(resonanceParameters, false);
make_child(resonances, false);
make_child(resonancesWithBackground, false);
make_child(RMatrix, false);
make_child(rowData, false);
make_child(RutherfordScattering, false);
make_child(S_alpha_beta, false);
make_child(scatteringFactor, false);
make_child(scatteringRadius, false);
make_child(shortRangeSelfScalingVariance, false);
make_child(simpleMaxwellianFission, false);
make_child(spin, false);
make_child(S_table, false);
make_child(standard, false);
make_child(string, false);
make_child(styles, false);
make_child(table, false);
make_child(tabulatedWidths, false);
make_child(T_effective, false);
make_child(temperature, false);
make_child(thermalScattering, false);
make_child(theta, false);
make_child(time, false);
make_child(T_M, false);
make_child(totalEnergy, false);
make_child(U, false);
make_child(uncertainty, false);
make_child(uncorrelated, false);
make_child(unresolved, false);
make_child(unresolvedRegion, false);
make_child(unspecified, false);
make_child(weightedFunctionals, false);
make_child(xml, false);
make_child(XYs3d, false);
make_child(yields, false);

} // namespace child



// -----------------------------------------------------------------------------
// keywords
// Special cases, not doable with our macro.
// -----------------------------------------------------------------------------

namespace child {

// Double
// Not double, for obvious reasons.
inline constexpr const child_t Double("double", false);

} // namespace child
