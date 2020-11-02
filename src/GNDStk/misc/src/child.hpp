
namespace child {

// -----------------------------------------------------------------------------
// Allowable top-level nodes, per LLNL-TR-774621-DRAFT
// -----------------------------------------------------------------------------

// Note: the trues mean "allowed as a top-level node"
inline const child_t<void,allow::one>
   reactionSuite      ("reactionSuite",       true),
   covarianceSuite    ("covarianceSuite",     true),
   PoPs               ("PoPs",                true),
   thermalScattering  ("thermalScattering",   true),
   fissionFragmentData("fissionFragmentData", true);



// -----------------------------------------------------------------------------
// Keywords
// Of type child_t
// -----------------------------------------------------------------------------

// ------------------------
// one + many pair
// constructs
// ------------------------

GNDSTK_MAKE_CHILD(void, averageEnergies, allow::one);
GNDSTK_MAKE_CHILD(void, averageEnergy,   allow::many);

GNDSTK_MAKE_CHILD(void, axes, allow::one);
GNDSTK_MAKE_CHILD(void, axis, allow::many);

GNDSTK_MAKE_CHILD(void, baryons, allow::one);
GNDSTK_MAKE_CHILD(void, baryon,  allow::many);

GNDSTK_MAKE_CHILD(void, channels, allow::one);
GNDSTK_MAKE_CHILD(void, channel,  allow::many);

GNDSTK_MAKE_CHILD(void, chemicalElements, allow::one);
GNDSTK_MAKE_CHILD(void, chemicalElement,  allow::many);

GNDSTK_MAKE_CHILD(void, configurations, allow::one);
GNDSTK_MAKE_CHILD(void, configuration,  allow::many);

GNDSTK_MAKE_CHILD(void, decayModes, allow::one);
GNDSTK_MAKE_CHILD(void, decayMode,  allow::many);

GNDSTK_MAKE_CHILD(void, durations, allow::one);
GNDSTK_MAKE_CHILD(void, duration,  allow::many);

GNDSTK_MAKE_CHILD(void, externalFiles, allow::one);
GNDSTK_MAKE_CHILD(void, externalFile,  allow::many);

GNDSTK_MAKE_CHILD(void, fissionComponents, allow::one);
GNDSTK_MAKE_CHILD(void, fissionComponent,  allow::many);

GNDSTK_MAKE_CHILD(void, isotopes, allow::one);
GNDSTK_MAKE_CHILD(void, isotope,  allow::many);

GNDSTK_MAKE_CHILD(void, Js, allow::one);
GNDSTK_MAKE_CHILD(void, J,  allow::many);

GNDSTK_MAKE_CHILD(void, leptons, allow::one);
GNDSTK_MAKE_CHILD(void, lepton,  allow::many);

GNDSTK_MAKE_CHILD(void, nuclides, allow::one);
GNDSTK_MAKE_CHILD(void, nuclide,  allow::many);

GNDSTK_MAKE_CHILD(void, productions, allow::one);
GNDSTK_MAKE_CHILD(void, production,  allow::many);

GNDSTK_MAKE_CHILD(void, products, allow::one);
GNDSTK_MAKE_CHILD(void, product,  allow::many);

GNDSTK_MAKE_CHILD(void, reactions, allow::one);
GNDSTK_MAKE_CHILD(void, reaction,  allow::many);

GNDSTK_MAKE_CHILD(void, resonanceReactions, allow::one);
GNDSTK_MAKE_CHILD(void, resonanceReaction,  allow::many);

GNDSTK_MAKE_CHILD(void, scatteringAtoms, allow::one);
GNDSTK_MAKE_CHILD(void, scatteringAtom,  allow::many);

GNDSTK_MAKE_CHILD(void, spectra, allow::one);
GNDSTK_MAKE_CHILD(void, spectrum, allow::many);

GNDSTK_MAKE_CHILD(void, spinGroups, allow::one);
GNDSTK_MAKE_CHILD(void, spinGroup,  allow::many);

GNDSTK_MAKE_CHILD(void, widths, allow::one);
GNDSTK_MAKE_CHILD(void, width,  allow::many);

GNDSTK_MAKE_CHILD(void, sums, allow::one);
GNDSTK_MAKE_CHILD(void, sum,  allow::many);

GNDSTK_MAKE_CHILD(void, Ls, allow::one);
GNDSTK_MAKE_CHILD(void, L,  allow::many);

GNDSTK_MAKE_CHILD(void, summands, allow::one);
GNDSTK_MAKE_CHILD(void, summand,  allow::many);


// ------------------------
// Others, not paired
// as above
// ------------------------

// fixme
// Do more sorting/categorization
// Some may actually be singular/plural pairs

// allow::many cases
GNDSTK_MAKE_CHILD(void, add, allow::many);
GNDSTK_MAKE_CHILD(void, averageParameterCovariance, allow::many);
GNDSTK_MAKE_CHILD(void, column, allow::many);
GNDSTK_MAKE_CHILD(void, conversion, allow::many);
GNDSTK_MAKE_CHILD(void, covariance, allow::many);
GNDSTK_MAKE_CHILD(void, covarianceMatrix, allow::many);
GNDSTK_MAKE_CHILD(void, crossSectionSum, allow::many);
GNDSTK_MAKE_CHILD(void, decay, allow::many);
GNDSTK_MAKE_CHILD(void, discrete, allow::many);
GNDSTK_MAKE_CHILD(void, grid, allow::many);
GNDSTK_MAKE_CHILD(void, Legendre, allow::many);
GNDSTK_MAKE_CHILD(void, metaStable, allow::many);
GNDSTK_MAKE_CHILD(void, multiplicitySum, allow::many);
GNDSTK_MAKE_CHILD(void, parameterLink, allow::many);
GNDSTK_MAKE_CHILD(void, regions1d, allow::many);
GNDSTK_MAKE_CHILD(void, section, allow::many);
GNDSTK_MAKE_CHILD(void, shell, allow::many);
GNDSTK_MAKE_CHILD(void, weighted, allow::many);
GNDSTK_MAKE_CHILD(void, XYs1d, allow::many);
GNDSTK_MAKE_CHILD(void, XYs2d, allow::many);

// allow::one cases
GNDSTK_MAKE_CHILD(void, aliases, allow::one);
GNDSTK_MAKE_CHILD(void, angular, allow::one);
GNDSTK_MAKE_CHILD(void, angularEnergy, allow::one);
GNDSTK_MAKE_CHILD(void, angularTwoBody, allow::one);
GNDSTK_MAKE_CHILD(void, applicationData, allow::one);
GNDSTK_MAKE_CHILD(void, array, allow::one);
GNDSTK_MAKE_CHILD(void, atomic, allow::one);
GNDSTK_MAKE_CHILD(void, averageProductEnergy, allow::one);
GNDSTK_MAKE_CHILD(void, background, allow::one);
GNDSTK_MAKE_CHILD(void, bindingEnergy, allow::one);
GNDSTK_MAKE_CHILD(void, branching1d, allow::one);
GNDSTK_MAKE_CHILD(void, branching3d, allow::one);
GNDSTK_MAKE_CHILD(void, BreitWigner, allow::one);
GNDSTK_MAKE_CHILD(void, characteristicCrossSection, allow::one);
GNDSTK_MAKE_CHILD(void, charge, allow::one);
GNDSTK_MAKE_CHILD(void, coherentElastic, allow::one);
GNDSTK_MAKE_CHILD(void, coherentPhotonScattering, allow::one);
GNDSTK_MAKE_CHILD(void, columnData, allow::one);
GNDSTK_MAKE_CHILD(void, columnHeaders, allow::one);
GNDSTK_MAKE_CHILD(void, constant1d, allow::one);
GNDSTK_MAKE_CHILD(void, continuum, allow::one);
GNDSTK_MAKE_CHILD(void, CoulombPlusNuclearElastic, allow::one);
GNDSTK_MAKE_CHILD(void, covarianceSections, allow::one);
GNDSTK_MAKE_CHILD(void, crossSection, allow::one);
GNDSTK_MAKE_CHILD(void, crossSectionReconstructed, allow::one);
GNDSTK_MAKE_CHILD(void, crossSections, allow::one);
GNDSTK_MAKE_CHILD(void, cutoffEnergy, allow::one);
GNDSTK_MAKE_CHILD(void, data, allow::one);
GNDSTK_MAKE_CHILD(void, DebyeWaller, allow::one);
GNDSTK_MAKE_CHILD(void, decayData, allow::one);
GNDSTK_MAKE_CHILD(void, decayPath, allow::one);
GNDSTK_MAKE_CHILD(void, delayedBetaEnergy, allow::one);
GNDSTK_MAKE_CHILD(void, delayedGammaEnergy, allow::one);
GNDSTK_MAKE_CHILD(void, delayedNeutronKE, allow::one);
GNDSTK_MAKE_CHILD(void, discreteGamma, allow::one);
GNDSTK_MAKE_CHILD(void, distribution, allow::one);
GNDSTK_MAKE_CHILD(void, documentation, allow::one);
GNDSTK_MAKE_CHILD(void, documentations, allow::one);
GNDSTK_MAKE_CHILD(void, doubleDifferentialCrossSection, allow::one);
GNDSTK_MAKE_CHILD(void, e_critical, allow::one);
GNDSTK_MAKE_CHILD(void, EFH, allow::one);
GNDSTK_MAKE_CHILD(void, EFL, allow::one);
GNDSTK_MAKE_CHILD(void, e_max, allow::one);
GNDSTK_MAKE_CHILD(void, ENDFconversionFlags, allow::one);
GNDSTK_MAKE_CHILD(void, energy, allow::one);
GNDSTK_MAKE_CHILD(void, energyAngular, allow::one);
GNDSTK_MAKE_CHILD(void, evaluated, allow::one);
GNDSTK_MAKE_CHILD(void, evaporation, allow::one);
GNDSTK_MAKE_CHILD(void, f, allow::one);
GNDSTK_MAKE_CHILD(void, fastRegion, allow::one);
GNDSTK_MAKE_CHILD(void, fissionEnergyReleased, allow::one);
GNDSTK_MAKE_CHILD(void, fraction, allow::one);
GNDSTK_MAKE_CHILD(void, freeAtomCrossSection, allow::one);
GNDSTK_MAKE_CHILD(void, g, allow::one);
GNDSTK_MAKE_CHILD(void, gaugeBoson, allow::one);
GNDSTK_MAKE_CHILD(void, gaugeBosons, allow::one);
GNDSTK_MAKE_CHILD(void, generalEvaporation, allow::one);
GNDSTK_MAKE_CHILD(void, gridded2d, allow::one);
GNDSTK_MAKE_CHILD(void, gridded3d, allow::one);
GNDSTK_MAKE_CHILD(void, halflife, allow::one);
GNDSTK_MAKE_CHILD(void, hardSphereRadius, allow::one);
GNDSTK_MAKE_CHILD(void, imaginaryAnomalousFactor, allow::one);
GNDSTK_MAKE_CHILD(void, imaginaryInterferenceTerm, allow::one);
GNDSTK_MAKE_CHILD(void, incoherentElastic, allow::one);
GNDSTK_MAKE_CHILD(void, incoherentInelastic, allow::one);
GNDSTK_MAKE_CHILD(void, incoherentPhotonScattering, allow::one);
GNDSTK_MAKE_CHILD(void, incompleteReactions, allow::one);
GNDSTK_MAKE_CHILD(void, institution, allow::one);
GNDSTK_MAKE_CHILD(void, integer, allow::one);
GNDSTK_MAKE_CHILD(void, intensity, allow::one);
GNDSTK_MAKE_CHILD(void, internalConversionCoefficients, allow::one);
GNDSTK_MAKE_CHILD(void, internalPairFormationCoefficient, allow::one);
GNDSTK_MAKE_CHILD(void, isotropic2d, allow::one);
GNDSTK_MAKE_CHILD(void, KalbachMann, allow::one);
GNDSTK_MAKE_CHILD(void, levelSpacing, allow::one);
GNDSTK_MAKE_CHILD(void, link, allow::one);
GNDSTK_MAKE_CHILD(void, listOfCovariances, allow::one);
GNDSTK_MAKE_CHILD(void, MadlandNix, allow::one);
GNDSTK_MAKE_CHILD(void, mass, allow::one);
GNDSTK_MAKE_CHILD(void, mixed, allow::one);
GNDSTK_MAKE_CHILD(void, multiplicities, allow::one);
GNDSTK_MAKE_CHILD(void, multiplicity, allow::one);
GNDSTK_MAKE_CHILD(void, NBodyPhaseSpace, allow::one);
GNDSTK_MAKE_CHILD(void, neutrinoEnergy, allow::one);
GNDSTK_MAKE_CHILD(void, nonNeutrinoEnergy, allow::one);
GNDSTK_MAKE_CHILD(void, nuclearAmplitudeExpansion, allow::one);
GNDSTK_MAKE_CHILD(void, nuclearPlusInterference, allow::one);
GNDSTK_MAKE_CHILD(void, nuclearTerm, allow::one);
GNDSTK_MAKE_CHILD(void, nucleus, allow::one);
GNDSTK_MAKE_CHILD(void, orphanProducts, allow::one);
GNDSTK_MAKE_CHILD(void, outputChannel, allow::one);
GNDSTK_MAKE_CHILD(void, parameterCovariance, allow::one);
GNDSTK_MAKE_CHILD(void, parameterCovarianceMatrix, allow::one);
GNDSTK_MAKE_CHILD(void, parameterCovariances, allow::one);
GNDSTK_MAKE_CHILD(void, parameters, allow::one);
GNDSTK_MAKE_CHILD(void, parity, allow::one);
GNDSTK_MAKE_CHILD(void, photonEmissionProbabilities, allow::one);
GNDSTK_MAKE_CHILD(void, pids, allow::one);
GNDSTK_MAKE_CHILD(void, polynomial1d, allow::one);
GNDSTK_MAKE_CHILD(void, positronEmissionIntensity, allow::one);
GNDSTK_MAKE_CHILD(void, primaryGamma, allow::one);
GNDSTK_MAKE_CHILD(void, probability, allow::one);
GNDSTK_MAKE_CHILD(void, productYield, allow::one);
GNDSTK_MAKE_CHILD(void, productYields, allow::one);
GNDSTK_MAKE_CHILD(void, projectileEnergyDomain, allow::one);
GNDSTK_MAKE_CHILD(void, promptGammaEnergy, allow::one);
GNDSTK_MAKE_CHILD(void, promptNeutronKE, allow::one);
GNDSTK_MAKE_CHILD(void, promptProductKE, allow::one);
GNDSTK_MAKE_CHILD(void, Q, allow::one);
GNDSTK_MAKE_CHILD(void, r, allow::one);
GNDSTK_MAKE_CHILD(void, realAnomalousFactor, allow::one);
GNDSTK_MAKE_CHILD(void, realInterferenceTerm, allow::one);
GNDSTK_MAKE_CHILD(void, recoil, allow::one);
GNDSTK_MAKE_CHILD(void, reference, allow::one);
GNDSTK_MAKE_CHILD(void, regions2d, allow::one);
GNDSTK_MAKE_CHILD(void, resolved, allow::one);
GNDSTK_MAKE_CHILD(void, resolvedRegion, allow::one);
GNDSTK_MAKE_CHILD(void, resonanceParameters, allow::one);
GNDSTK_MAKE_CHILD(void, resonances, allow::one);
GNDSTK_MAKE_CHILD(void, resonancesWithBackground, allow::one);
GNDSTK_MAKE_CHILD(void, RMatrix, allow::one);
GNDSTK_MAKE_CHILD(void, rowData, allow::one);
GNDSTK_MAKE_CHILD(void, RutherfordScattering, allow::one);
GNDSTK_MAKE_CHILD(void, S_alpha_beta, allow::one);
GNDSTK_MAKE_CHILD(void, scatteringFactor, allow::one);
GNDSTK_MAKE_CHILD(void, scatteringRadius, allow::one);
GNDSTK_MAKE_CHILD(void, shortRangeSelfScalingVariance, allow::one);
GNDSTK_MAKE_CHILD(void, simpleMaxwellianFission, allow::one);
GNDSTK_MAKE_CHILD(void, spin, allow::one);
GNDSTK_MAKE_CHILD(void, S_table, allow::one);
GNDSTK_MAKE_CHILD(void, standard, allow::one);
GNDSTK_MAKE_CHILD(void, string, allow::one);
GNDSTK_MAKE_CHILD(void, styles, allow::one);
GNDSTK_MAKE_CHILD(void, table, allow::one);
GNDSTK_MAKE_CHILD(void, tabulatedWidths, allow::one);
GNDSTK_MAKE_CHILD(void, T_effective, allow::one);
GNDSTK_MAKE_CHILD(void, temperature, allow::one);
GNDSTK_MAKE_CHILD(void, theta, allow::one);
GNDSTK_MAKE_CHILD(void, time, allow::one);
GNDSTK_MAKE_CHILD(void, T_M, allow::one);
GNDSTK_MAKE_CHILD(void, totalEnergy, allow::one);
GNDSTK_MAKE_CHILD(void, U, allow::one);
GNDSTK_MAKE_CHILD(void, uncertainty, allow::one);
GNDSTK_MAKE_CHILD(void, uncorrelated, allow::one);
GNDSTK_MAKE_CHILD(void, unresolved, allow::one);
GNDSTK_MAKE_CHILD(void, unresolvedRegion, allow::one);
GNDSTK_MAKE_CHILD(void, unspecified, allow::one);
GNDSTK_MAKE_CHILD(void, weightedFunctionals, allow::one);
GNDSTK_MAKE_CHILD(void, xml, allow::one);
GNDSTK_MAKE_CHILD(void, XYs3d, allow::one);
GNDSTK_MAKE_CHILD(void, yields, allow::one);



// -----------------------------------------------------------------------------
// Some special cases
// -----------------------------------------------------------------------------

// Double
// Not called double, for obvious reasons.
inline const child_t<void,allow::one> Double("double");

// cdata, comment
// These are where XML <![CDATA[...]]> or <!-- ... --> (comment) material
// resides. It's reasonable to extract such content into std::strings. We
// then store these as nodes of those respective names, each with one metadatum
// having a key of "text" and a value containing the original content.
inline const child_t<std::string,allow::one,detail::text_metadatum_to_string>
   cdata("cdata");
inline const child_t<std::string,allow::many,detail::text_metadatum_to_string>
   comment("comment");

// pcdata
// These are where XML material appearing in constructs like this:
//    <values>1.2 3.4 5.6 7.8 9.0</values>
// resides. In that case, our internal tree structure would have a node named
// "values", which would have a child node named pcdata, which would have a
// metadatum with a key of "text" and a value containing the original content:
// the "1.2 ..." in the above example. Our examination of many GNDS files shows
// that some pcdata nodes contain integers, while others contain doubles. We
// therefore define pcdata as a child_t with <void>, so that we can access it
// in its original form and thus dig further down to its "text" metadatum, at
// which point we can decide elsewhere what's appropriate for that. (Read into
// a vector of ints? Into vector of doubles? Into something else?)
inline const child_t<void,allow::one>
   pcdata("pcdata");



// -----------------------------------------------------------------------------
// values
// -----------------------------------------------------------------------------

// convert_pcdata_text
// This object, via its type, provides conversions between certain C++ container
// types, and nodes such as <values> that contain plain character data (pcdata)
// content. We provide it for user convenience if someone wishes to extract data
// from <values> nodes using their own constructs (which could make use of this
// object) rather than the values object we provide below.
inline const detail::convert_pcdata_text_t convert_pcdata_text;

// values
template<class T = double>
inline const child_t<
   typename detail::values_type<T>::type,
   allow::one,
   typename detail::values_type<T>::converter
> values("values");

} // namespace child
