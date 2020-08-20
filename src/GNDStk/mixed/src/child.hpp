
// -----------------------------------------------------------------------------
// Allowable top-level nodes
// As given in LLNL-TR-774621-DRAFT
// -----------------------------------------------------------------------------

namespace child {

// Note: the true values here mean "allowed as a top-level node"
inline const child_t<void,find::one>
   reactionSuite      ("reactionSuite",       true),
   covarianceSuite    ("covarianceSuite",     true),
   PoPs               ("PoPs",                true),
   thermalScattering  ("thermalScattering",   true),
   fissionFragmentData("fissionFragmentData", true);

} // namespace child



// -----------------------------------------------------------------------------
// Keywords
// Of type child_t
// -----------------------------------------------------------------------------

namespace child {

// ------------------------
// one + all pair
// constructs
// ------------------------

GNDSTK_MAKE_CHILD_DEFAULT(averageEnergies, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(averageEnergy,   find::all);

GNDSTK_MAKE_CHILD_DEFAULT(axes, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(axis, find::all);

GNDSTK_MAKE_CHILD_DEFAULT(baryons, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(baryon,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(channels, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(channel,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(chemicalElements, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(chemicalElement,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(configurations, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(configuration,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(decayModes, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(decayMode,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(durations, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(duration,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(externalFiles, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(externalFile,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(fissionComponents, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(fissionComponent,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(isotopes, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(isotope,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(Js, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(J,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(leptons, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(lepton,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(nuclides, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(nuclide,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(productions, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(production,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(products, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(product,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(reactions, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(reaction,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(resonanceReactions, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(resonanceReaction,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(scatteringAtoms, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(scatteringAtom,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(spectra, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(spectrum, find::all);

GNDSTK_MAKE_CHILD_DEFAULT(spinGroups, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(spinGroup,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(widths, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(width,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(sums, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(sum,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(Ls, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(L,  find::all);

GNDSTK_MAKE_CHILD_DEFAULT(summands, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(summand,  find::all);


// ------------------------
// Plain old keywords
// ------------------------

// fixme
// Do more sorting/categorization
// Some may actually be singular/plural pairs

// find::all cases
GNDSTK_MAKE_CHILD_DEFAULT(add, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(averageParameterCovariance, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(column, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(conversion, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(covariance, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(covarianceMatrix, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(crossSectionSum, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(decay, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(discrete, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(grid, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(Legendre, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(metaStable, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(multiplicitySum, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(parameterLink, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(regions1d, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(section, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(shell, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(values, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(weighted, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(XYs1d, find::all);
GNDSTK_MAKE_CHILD_DEFAULT(XYs2d, find::all);

// find::one cases
GNDSTK_MAKE_CHILD_DEFAULT(aliases, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(angular, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(angularEnergy, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(angularTwoBody, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(applicationData, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(array, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(atomic, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(averageProductEnergy, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(background, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(bindingEnergy, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(branching1d, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(branching3d, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(BreitWigner, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(characteristicCrossSection, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(charge, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(coherentElastic, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(coherentPhotonScattering, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(columnData, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(columnHeaders, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(constant1d, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(continuum, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(CoulombPlusNuclearElastic, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(covarianceSections, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(crossSection, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(crossSectionReconstructed, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(crossSections, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(cutoffEnergy, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(data, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(DebyeWaller, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(decayData, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(decayPath, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(delayedBetaEnergy, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(delayedGammaEnergy, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(delayedNeutronKE, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(discreteGamma, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(distribution, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(documentation, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(documentations, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(doubleDifferentialCrossSection, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(e_critical, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(EFH, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(EFL, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(e_max, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(ENDFconversionFlags, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(energy, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(energyAngular, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(evaluated, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(evaporation, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(f, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(fastRegion, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(fissionEnergyReleased, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(fraction, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(freeAtomCrossSection, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(g, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(gaugeBoson, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(gaugeBosons, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(generalEvaporation, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(gridded2d, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(gridded3d, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(halflife, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(hardSphereRadius, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(imaginaryAnomalousFactor, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(imaginaryInterferenceTerm, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(incoherentElastic, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(incoherentInelastic, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(incoherentPhotonScattering, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(incompleteReactions, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(institution, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(integer, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(intensity, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(internalConversionCoefficients, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(internalPairFormationCoefficient, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(isotropic2d, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(KalbachMann, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(levelSpacing, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(link, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(listOfCovariances, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(MadlandNix, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(mass, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(mixed, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(multiplicities, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(multiplicity, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(NBodyPhaseSpace, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(neutrinoEnergy, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(nonNeutrinoEnergy, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(nuclearAmplitudeExpansion, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(nuclearPlusInterference, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(nuclearTerm, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(nucleus, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(orphanProducts, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(outputChannel, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(parameterCovariance, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(parameterCovarianceMatrix, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(parameterCovariances, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(parameters, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(parity, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(photonEmissionProbabilities, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(pids, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(polynomial1d, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(positronEmissionIntensity, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(primaryGamma, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(probability, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(productYield, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(productYields, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(projectileEnergyDomain, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(promptGammaEnergy, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(promptNeutronKE, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(promptProductKE, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(Q, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(r, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(realAnomalousFactor, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(realInterferenceTerm, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(recoil, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(reference, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(regions2d, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(resolved, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(resolvedRegion, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(resonanceParameters, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(resonances, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(resonancesWithBackground, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(RMatrix, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(rowData, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(RutherfordScattering, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(S_alpha_beta, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(scatteringFactor, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(scatteringRadius, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(shortRangeSelfScalingVariance, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(simpleMaxwellianFission, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(spin, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(S_table, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(standard, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(string, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(styles, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(table, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(tabulatedWidths, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(T_effective, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(temperature, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(theta, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(time, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(T_M, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(totalEnergy, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(U, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(uncertainty, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(uncorrelated, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(unresolved, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(unresolvedRegion, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(unspecified, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(weightedFunctionals, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(xml, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(XYs3d, find::one);
GNDSTK_MAKE_CHILD_DEFAULT(yields, find::one);

} // namespace child



// -----------------------------------------------------------------------------
// keywords
// Special cases
// -----------------------------------------------------------------------------

// Helper for cdata and comment
namespace detail {
   class text_metadatum_to_string {
   public:
      template<class NODE>
      void operator()(const NODE &node, std::string &to) const
      {
         to = node.meta("text");
      }
   };
}

namespace child {

// cdata, comment
// These are where XML <![CDATA[...]]> or <!-- ... --> (comment) material ends
// up. It's reasonable to extract such material as a std::string. We're storing
// these "cdata" and "comment" nodes as nodes of those respective names, each
// with one metadatum having a key of "text" and a value containing the "..."
// from <![CDATA[...]]> or <!--...-->.
inline const child_t<std::string,find::one,detail::text_metadatum_to_string>
   cdata("cdata");
inline const child_t<std::string,find::all,detail::text_metadatum_to_string>
   comment("comment");

// pcdata
// These are where XML material appearing in constructs like this:
//    <values>1.2 3.4 5.6 7.8 9.0</values>
// ends up. In that case, in our internal tree structure, we'd have a node named
// "values", inside it a child node named "pcdata", and then in the pcdata child
// node we'd have a metadatum with a key of "text" and a value with the original
// content: "1.2 ...". Examination of a large library of GNDS files shows that
// some pcdata nodes contain integers, while others contain doubles. We provide
// the following, a child_t<void,...>, so that users can get to the pcdata node
// in its plain node form and decide for themselves what to do about the "text"
// metadatum.
inline const child_t<void,find::one>
   pcdata("pcdata");

// Double
// Not called double, for obvious reasons.
inline const child_t<void,find::one> Double("double");

} // namespace child
