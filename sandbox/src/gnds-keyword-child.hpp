
// macros, for keyword building
#define make_child_default(name,allow_multiple) \
   inline const child_t<node> name(#name,allow_multiple)
#define make_child(type,name,allow_multiple) \
   inline const child_t<type> name(#name,allow_multiple)



// -----------------------------------------------------------------------------
// child_t
// -----------------------------------------------------------------------------

// fixme Have T be used in some good way
template<class T>
class child_t {
public:
   const std::string name;
   const bool allow_multiple;
   explicit child_t(const std::string &n, const bool a) :
      name(n), allow_multiple(a)
   { }
};



// -----------------------------------------------------------------------------
// keywords
// These use our macro.
// fixme Eventually, many (or most (or all)) need a solid type, not <node>.
// -----------------------------------------------------------------------------

namespace child {

// ------------------------
// Singular+plural pair
// constructs
// ------------------------

make_child_default(averageEnergies, false);
make_child_default(averageEnergy,   true);

make_child_default(axes, false);
make_child_default(axis, true);

make_child_default(baryons, false);
make_child_default(baryon,  true);

make_child_default(channels, false);
make_child_default(channel,  true);

make_child_default(chemicalElements, false);
make_child_default(chemicalElement,  true);

make_child_default(configurations, false);
make_child_default(configuration,  true);

make_child_default(decayModes, false);
make_child_default(decayMode,  true);

make_child_default(durations, false);
make_child_default(duration,  true);

make_child_default(externalFiles, false);
make_child_default(externalFile,  true);

make_child_default(fissionComponents, false);
make_child_default(fissionComponent,  true);

make_child_default(isotopes, false);
make_child_default(isotope,  true);

make_child_default(Js, false);
make_child_default(J,  true);

make_child_default(leptons, false);
make_child_default(lepton,  true);

make_child_default(nuclides, false);
make_child_default(nuclide,  true);

make_child_default(productions, false);
make_child_default(production,  true);

make_child_default(products, false);
make_child_default(product,  true);

make_child_default(reactions, false);
make_child_default(reaction,  true);

make_child_default(resonanceReactions, false);
make_child_default(resonanceReaction,  true);

make_child_default(scatteringAtoms, false);
make_child_default(scatteringAtom,  true);

make_child_default(spectra, false);
make_child_default(spectrum, true);

make_child_default(spinGroups, false);
make_child_default(spinGroup,  true);

make_child_default(widths, false);
make_child_default(width,  true);

make_child_default(sums, false);
make_child_default(sum,  true);

make_child_default(Ls, false);
make_child_default(L,  true);

make_child_default(summands, false);
make_child_default(summand,  true);



// ------------------------
// Plain old keywords
// ------------------------

// fixme do more sorting/categorization
// fixme some may actually be singular/plural pairs as above

// multiple == true
make_child_default(add, true);
make_child_default(averageParameterCovariance, true);
make_child_default(column, true);
make_child_default(conversion, true);
make_child_default(covariance, true);
make_child_default(covarianceMatrix, true);
make_child_default(crossSectionSum, true);
make_child_default(decay, true);
make_child_default(discrete, true);
make_child_default(grid, true);
make_child_default(Legendre, true);
make_child_default(metaStable, true);
make_child_default(multiplicitySum, true);
make_child_default(parameterLink, true);
make_child_default(regions1d, true);
make_child_default(section, true);
make_child_default(shell, true);
make_child_default(values, true);
make_child_default(weighted, true);
make_child_default(XYs1d, true);
make_child_default(XYs2d, true);

// multiple == false
make_child_default(aliases, false);
make_child_default(angular, false);
make_child_default(angularEnergy, false);
make_child_default(angularTwoBody, false);
make_child_default(applicationData, false);
make_child_default(array, false);
make_child_default(atomic, false);
make_child_default(averageProductEnergy, false);
make_child_default(background, false);
make_child_default(bindingEnergy, false);
make_child_default(branching1d, false);
make_child_default(branching3d, false);
make_child_default(BreitWigner, false);
make_child_default(characteristicCrossSection, false);
make_child_default(charge, false);
make_child_default(coherentElastic, false);
make_child_default(coherentPhotonScattering, false);
make_child_default(columnData, false);
make_child_default(columnHeaders, false);
make_child_default(constant1d, false);
make_child_default(continuum, false);
make_child_default(CoulombPlusNuclearElastic, false);
make_child_default(covarianceSections, false);
make_child_default(covarianceSuite, false);
make_child_default(crossSection, false);
make_child_default(crossSectionReconstructed, false);
make_child_default(crossSections, false);
make_child_default(cutoffEnergy, false);
make_child_default(data, false);
make_child_default(DebyeWaller, false);
make_child_default(decayData, false);
make_child_default(decayPath, false);
make_child_default(delayedBetaEnergy, false);
make_child_default(delayedGammaEnergy, false);
make_child_default(delayedNeutronKE, false);
make_child_default(discreteGamma, false);
make_child_default(distribution, false);
make_child_default(documentation, false);
make_child_default(documentations, false);
make_child_default(doubleDifferentialCrossSection, false);
make_child_default(e_critical, false);
make_child_default(EFH, false);
make_child_default(EFL, false);
make_child_default(e_max, false);
make_child_default(ENDFconversionFlags, false);
make_child_default(energy, false);
make_child_default(energyAngular, false);
make_child_default(evaluated, false);
make_child_default(evaporation, false);
make_child_default(f, false);
make_child_default(fastRegion, false);
make_child_default(fissionEnergyReleased, false);
make_child_default(fissionFragmentData, false);
make_child_default(fraction, false);
make_child_default(freeAtomCrossSection, false);
make_child_default(g, false);
make_child_default(gaugeBoson, false);
make_child_default(gaugeBosons, false);
make_child_default(generalEvaporation, false);
make_child_default(gridded2d, false);
make_child_default(gridded3d, false);
make_child_default(halflife, false);
make_child_default(hardSphereRadius, false);
make_child_default(imaginaryAnomalousFactor, false);
make_child_default(imaginaryInterferenceTerm, false);
make_child_default(incoherentElastic, false);
make_child_default(incoherentInelastic, false);
make_child_default(incoherentPhotonScattering, false);
make_child_default(incompleteReactions, false);
make_child_default(institution, false);
make_child_default(integer, false);
make_child_default(intensity, false);
make_child_default(internalConversionCoefficients, false);
make_child_default(internalPairFormationCoefficient, false);
make_child_default(isotropic2d, false);
make_child_default(KalbachMann, false);
make_child_default(levelSpacing, false);
make_child_default(link, false);
make_child_default(listOfCovariances, false);
make_child_default(MadlandNix, false);
make_child_default(mass, false);
make_child_default(mixed, false);
make_child_default(multiplicities, false);
make_child_default(multiplicity, false);
make_child_default(NBodyPhaseSpace, false);
make_child_default(neutrinoEnergy, false);
make_child_default(nonNeutrinoEnergy, false);
make_child_default(nuclearAmplitudeExpansion, false);
make_child_default(nuclearPlusInterference, false);
make_child_default(nuclearTerm, false);
make_child_default(nucleus, false);
make_child_default(orphanProducts, false);
make_child_default(outputChannel, false);
make_child_default(parameterCovariance, false);
make_child_default(parameterCovarianceMatrix, false);
make_child_default(parameterCovariances, false);
make_child_default(parameters, false);
make_child_default(parity, false);
make_child_default(photonEmissionProbabilities, false);
make_child_default(pids, false);
make_child_default(polynomial1d, false);
make_child_default(PoPs, false);
make_child_default(positronEmissionIntensity, false);
make_child_default(primaryGamma, false);
make_child_default(probability, false);
make_child_default(productYield, false);
make_child_default(productYields, false);
make_child_default(projectileEnergyDomain, false);
make_child_default(promptGammaEnergy, false);
make_child_default(promptNeutronKE, false);
make_child_default(promptProductKE, false);
make_child_default(Q, false);
make_child_default(r, false);
make_child_default(reactionSuite, false);
make_child_default(realAnomalousFactor, false);
make_child_default(realInterferenceTerm, false);
make_child_default(recoil, false);
make_child_default(reference, false);
make_child_default(regions2d, false);
make_child_default(resolved, false);
make_child_default(resolvedRegion, false);
make_child_default(resonanceParameters, false);
make_child_default(resonances, false);
make_child_default(resonancesWithBackground, false);
make_child_default(RMatrix, false);
make_child_default(rowData, false);
make_child_default(RutherfordScattering, false);
make_child_default(S_alpha_beta, false);
make_child_default(scatteringFactor, false);
make_child_default(scatteringRadius, false);
make_child_default(shortRangeSelfScalingVariance, false);
make_child_default(simpleMaxwellianFission, false);
make_child_default(spin, false);
make_child_default(S_table, false);
make_child_default(standard, false);
make_child_default(string, false);
make_child_default(styles, false);
make_child_default(table, false);
make_child_default(tabulatedWidths, false);
make_child_default(T_effective, false);
make_child_default(temperature, false);
make_child_default(thermalScattering, false);
make_child_default(theta, false);
make_child_default(time, false);
make_child_default(T_M, false);
make_child_default(totalEnergy, false);
make_child_default(U, false);
make_child_default(uncertainty, false);
make_child_default(uncorrelated, false);
make_child_default(unresolved, false);
make_child_default(unresolvedRegion, false);
make_child_default(unspecified, false);
make_child_default(weightedFunctionals, false);
make_child_default(xml, false);
make_child_default(XYs3d, false);
make_child_default(yields, false);

} // namespace child



// -----------------------------------------------------------------------------
// keywords
// Special cases, not doable with our macro.
// -----------------------------------------------------------------------------

namespace child {

// Double
// Not double, for obvious reasons.
inline const child_t<node> Double("double", false);

} // namespace child
