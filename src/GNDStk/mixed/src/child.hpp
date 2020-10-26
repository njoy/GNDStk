
namespace child {

// -----------------------------------------------------------------------------
// Allowable top-level nodes
// As given in LLNL-TR-774621-DRAFT
// -----------------------------------------------------------------------------

// Note: the trues here mean "allowed as a top-level node"
inline const child_t<void,find::one>
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
// one + all pair
// constructs
// ------------------------

GNDSTK_MAKE_CHILD(void, averageEnergies, find::one);
GNDSTK_MAKE_CHILD(void, averageEnergy,   find::all);

GNDSTK_MAKE_CHILD(void, axes, find::one);
GNDSTK_MAKE_CHILD(void, axis, find::all);

GNDSTK_MAKE_CHILD(void, baryons, find::one);
GNDSTK_MAKE_CHILD(void, baryon,  find::all);

GNDSTK_MAKE_CHILD(void, channels, find::one);
GNDSTK_MAKE_CHILD(void, channel,  find::all);

GNDSTK_MAKE_CHILD(void, chemicalElements, find::one);
GNDSTK_MAKE_CHILD(void, chemicalElement,  find::all);

GNDSTK_MAKE_CHILD(void, configurations, find::one);
GNDSTK_MAKE_CHILD(void, configuration,  find::all);

GNDSTK_MAKE_CHILD(void, decayModes, find::one);
GNDSTK_MAKE_CHILD(void, decayMode,  find::all);

GNDSTK_MAKE_CHILD(void, durations, find::one);
GNDSTK_MAKE_CHILD(void, duration,  find::all);

GNDSTK_MAKE_CHILD(void, externalFiles, find::one);
GNDSTK_MAKE_CHILD(void, externalFile,  find::all);

GNDSTK_MAKE_CHILD(void, fissionComponents, find::one);
GNDSTK_MAKE_CHILD(void, fissionComponent,  find::all);

GNDSTK_MAKE_CHILD(void, isotopes, find::one);
GNDSTK_MAKE_CHILD(void, isotope,  find::all);

GNDSTK_MAKE_CHILD(void, Js, find::one);
GNDSTK_MAKE_CHILD(void, J,  find::all);

GNDSTK_MAKE_CHILD(void, leptons, find::one);
GNDSTK_MAKE_CHILD(void, lepton,  find::all);

GNDSTK_MAKE_CHILD(void, nuclides, find::one);
GNDSTK_MAKE_CHILD(void, nuclide,  find::all);

GNDSTK_MAKE_CHILD(void, productions, find::one);
GNDSTK_MAKE_CHILD(void, production,  find::all);

GNDSTK_MAKE_CHILD(void, products, find::one);
GNDSTK_MAKE_CHILD(void, product,  find::all);

GNDSTK_MAKE_CHILD(void, reactions, find::one);
GNDSTK_MAKE_CHILD(void, reaction,  find::all);

GNDSTK_MAKE_CHILD(void, resonanceReactions, find::one);
GNDSTK_MAKE_CHILD(void, resonanceReaction,  find::all);

GNDSTK_MAKE_CHILD(void, scatteringAtoms, find::one);
GNDSTK_MAKE_CHILD(void, scatteringAtom,  find::all);

GNDSTK_MAKE_CHILD(void, spectra, find::one);
GNDSTK_MAKE_CHILD(void, spectrum, find::all);

GNDSTK_MAKE_CHILD(void, spinGroups, find::one);
GNDSTK_MAKE_CHILD(void, spinGroup,  find::all);

GNDSTK_MAKE_CHILD(void, widths, find::one);
GNDSTK_MAKE_CHILD(void, width,  find::all);

GNDSTK_MAKE_CHILD(void, sums, find::one);
GNDSTK_MAKE_CHILD(void, sum,  find::all);

GNDSTK_MAKE_CHILD(void, Ls, find::one);
GNDSTK_MAKE_CHILD(void, L,  find::all);

GNDSTK_MAKE_CHILD(void, summands, find::one);
GNDSTK_MAKE_CHILD(void, summand,  find::all);


// ------------------------
// Plain old keywords
// ------------------------

// fixme
// Do more sorting/categorization
// Some may actually be singular/plural pairs

// find::all cases
GNDSTK_MAKE_CHILD(void, add, find::all);
GNDSTK_MAKE_CHILD(void, averageParameterCovariance, find::all);
GNDSTK_MAKE_CHILD(void, column, find::all);
GNDSTK_MAKE_CHILD(void, conversion, find::all);
GNDSTK_MAKE_CHILD(void, covariance, find::all);
GNDSTK_MAKE_CHILD(void, covarianceMatrix, find::all);
GNDSTK_MAKE_CHILD(void, crossSectionSum, find::all);
GNDSTK_MAKE_CHILD(void, decay, find::all);
GNDSTK_MAKE_CHILD(void, discrete, find::all);
GNDSTK_MAKE_CHILD(void, grid, find::all);
GNDSTK_MAKE_CHILD(void, Legendre, find::all);
GNDSTK_MAKE_CHILD(void, metaStable, find::all);
GNDSTK_MAKE_CHILD(void, multiplicitySum, find::all);
GNDSTK_MAKE_CHILD(void, parameterLink, find::all);
GNDSTK_MAKE_CHILD(void, regions1d, find::all);
GNDSTK_MAKE_CHILD(void, section, find::all);
GNDSTK_MAKE_CHILD(void, shell, find::all);
GNDSTK_MAKE_CHILD(void, weighted, find::all);
GNDSTK_MAKE_CHILD(void, XYs1d, find::all);
GNDSTK_MAKE_CHILD(void, XYs2d, find::all);

// find::one cases
GNDSTK_MAKE_CHILD(void, aliases, find::one);
GNDSTK_MAKE_CHILD(void, angular, find::one);
GNDSTK_MAKE_CHILD(void, angularEnergy, find::one);
GNDSTK_MAKE_CHILD(void, angularTwoBody, find::one);
GNDSTK_MAKE_CHILD(void, applicationData, find::one);
GNDSTK_MAKE_CHILD(void, array, find::one);
GNDSTK_MAKE_CHILD(void, atomic, find::one);
GNDSTK_MAKE_CHILD(void, averageProductEnergy, find::one);
GNDSTK_MAKE_CHILD(void, background, find::one);
GNDSTK_MAKE_CHILD(void, bindingEnergy, find::one);
GNDSTK_MAKE_CHILD(void, branching1d, find::one);
GNDSTK_MAKE_CHILD(void, branching3d, find::one);
GNDSTK_MAKE_CHILD(void, BreitWigner, find::one);
GNDSTK_MAKE_CHILD(void, characteristicCrossSection, find::one);
GNDSTK_MAKE_CHILD(void, charge, find::one);
GNDSTK_MAKE_CHILD(void, coherentElastic, find::one);
GNDSTK_MAKE_CHILD(void, coherentPhotonScattering, find::one);
GNDSTK_MAKE_CHILD(void, columnData, find::one);
GNDSTK_MAKE_CHILD(void, columnHeaders, find::one);
GNDSTK_MAKE_CHILD(void, constant1d, find::one);
GNDSTK_MAKE_CHILD(void, continuum, find::one);
GNDSTK_MAKE_CHILD(void, CoulombPlusNuclearElastic, find::one);
GNDSTK_MAKE_CHILD(void, covarianceSections, find::one);
GNDSTK_MAKE_CHILD(void, crossSection, find::one);
GNDSTK_MAKE_CHILD(void, crossSectionReconstructed, find::one);
GNDSTK_MAKE_CHILD(void, crossSections, find::one);
GNDSTK_MAKE_CHILD(void, cutoffEnergy, find::one);
GNDSTK_MAKE_CHILD(void, data, find::one);
GNDSTK_MAKE_CHILD(void, DebyeWaller, find::one);
GNDSTK_MAKE_CHILD(void, decayData, find::one);
GNDSTK_MAKE_CHILD(void, decayPath, find::one);
GNDSTK_MAKE_CHILD(void, delayedBetaEnergy, find::one);
GNDSTK_MAKE_CHILD(void, delayedGammaEnergy, find::one);
GNDSTK_MAKE_CHILD(void, delayedNeutronKE, find::one);
GNDSTK_MAKE_CHILD(void, discreteGamma, find::one);
GNDSTK_MAKE_CHILD(void, distribution, find::one);
GNDSTK_MAKE_CHILD(void, documentation, find::one);
GNDSTK_MAKE_CHILD(void, documentations, find::one);
GNDSTK_MAKE_CHILD(void, doubleDifferentialCrossSection, find::one);
GNDSTK_MAKE_CHILD(void, e_critical, find::one);
GNDSTK_MAKE_CHILD(void, EFH, find::one);
GNDSTK_MAKE_CHILD(void, EFL, find::one);
GNDSTK_MAKE_CHILD(void, e_max, find::one);
GNDSTK_MAKE_CHILD(void, ENDFconversionFlags, find::one);
GNDSTK_MAKE_CHILD(void, energy, find::one);
GNDSTK_MAKE_CHILD(void, energyAngular, find::one);
GNDSTK_MAKE_CHILD(void, evaluated, find::one);
GNDSTK_MAKE_CHILD(void, evaporation, find::one);
GNDSTK_MAKE_CHILD(void, f, find::one);
GNDSTK_MAKE_CHILD(void, fastRegion, find::one);
GNDSTK_MAKE_CHILD(void, fissionEnergyReleased, find::one);
GNDSTK_MAKE_CHILD(void, fraction, find::one);
GNDSTK_MAKE_CHILD(void, freeAtomCrossSection, find::one);
GNDSTK_MAKE_CHILD(void, g, find::one);
GNDSTK_MAKE_CHILD(void, gaugeBoson, find::one);
GNDSTK_MAKE_CHILD(void, gaugeBosons, find::one);
GNDSTK_MAKE_CHILD(void, generalEvaporation, find::one);
GNDSTK_MAKE_CHILD(void, gridded2d, find::one);
GNDSTK_MAKE_CHILD(void, gridded3d, find::one);
GNDSTK_MAKE_CHILD(void, halflife, find::one);
GNDSTK_MAKE_CHILD(void, hardSphereRadius, find::one);
GNDSTK_MAKE_CHILD(void, imaginaryAnomalousFactor, find::one);
GNDSTK_MAKE_CHILD(void, imaginaryInterferenceTerm, find::one);
GNDSTK_MAKE_CHILD(void, incoherentElastic, find::one);
GNDSTK_MAKE_CHILD(void, incoherentInelastic, find::one);
GNDSTK_MAKE_CHILD(void, incoherentPhotonScattering, find::one);
GNDSTK_MAKE_CHILD(void, incompleteReactions, find::one);
GNDSTK_MAKE_CHILD(void, institution, find::one);
GNDSTK_MAKE_CHILD(void, integer, find::one);
GNDSTK_MAKE_CHILD(void, intensity, find::one);
GNDSTK_MAKE_CHILD(void, internalConversionCoefficients, find::one);
GNDSTK_MAKE_CHILD(void, internalPairFormationCoefficient, find::one);
GNDSTK_MAKE_CHILD(void, isotropic2d, find::one);
GNDSTK_MAKE_CHILD(void, KalbachMann, find::one);
GNDSTK_MAKE_CHILD(void, levelSpacing, find::one);
GNDSTK_MAKE_CHILD(void, link, find::one);
GNDSTK_MAKE_CHILD(void, listOfCovariances, find::one);
GNDSTK_MAKE_CHILD(void, MadlandNix, find::one);
GNDSTK_MAKE_CHILD(void, mass, find::one);
GNDSTK_MAKE_CHILD(void, mixed, find::one);
GNDSTK_MAKE_CHILD(void, multiplicities, find::one);
GNDSTK_MAKE_CHILD(void, multiplicity, find::one);
GNDSTK_MAKE_CHILD(void, NBodyPhaseSpace, find::one);
GNDSTK_MAKE_CHILD(void, neutrinoEnergy, find::one);
GNDSTK_MAKE_CHILD(void, nonNeutrinoEnergy, find::one);
GNDSTK_MAKE_CHILD(void, nuclearAmplitudeExpansion, find::one);
GNDSTK_MAKE_CHILD(void, nuclearPlusInterference, find::one);
GNDSTK_MAKE_CHILD(void, nuclearTerm, find::one);
GNDSTK_MAKE_CHILD(void, nucleus, find::one);
GNDSTK_MAKE_CHILD(void, orphanProducts, find::one);
GNDSTK_MAKE_CHILD(void, outputChannel, find::one);
GNDSTK_MAKE_CHILD(void, parameterCovariance, find::one);
GNDSTK_MAKE_CHILD(void, parameterCovarianceMatrix, find::one);
GNDSTK_MAKE_CHILD(void, parameterCovariances, find::one);
GNDSTK_MAKE_CHILD(void, parameters, find::one);
GNDSTK_MAKE_CHILD(void, parity, find::one);
GNDSTK_MAKE_CHILD(void, photonEmissionProbabilities, find::one);
GNDSTK_MAKE_CHILD(void, pids, find::one);
GNDSTK_MAKE_CHILD(void, polynomial1d, find::one);
GNDSTK_MAKE_CHILD(void, positronEmissionIntensity, find::one);
GNDSTK_MAKE_CHILD(void, primaryGamma, find::one);
GNDSTK_MAKE_CHILD(void, probability, find::one);
GNDSTK_MAKE_CHILD(void, productYield, find::one);
GNDSTK_MAKE_CHILD(void, productYields, find::one);
GNDSTK_MAKE_CHILD(void, projectileEnergyDomain, find::one);
GNDSTK_MAKE_CHILD(void, promptGammaEnergy, find::one);
GNDSTK_MAKE_CHILD(void, promptNeutronKE, find::one);
GNDSTK_MAKE_CHILD(void, promptProductKE, find::one);
GNDSTK_MAKE_CHILD(void, Q, find::one);
GNDSTK_MAKE_CHILD(void, r, find::one);
GNDSTK_MAKE_CHILD(void, realAnomalousFactor, find::one);
GNDSTK_MAKE_CHILD(void, realInterferenceTerm, find::one);
GNDSTK_MAKE_CHILD(void, recoil, find::one);
GNDSTK_MAKE_CHILD(void, reference, find::one);
GNDSTK_MAKE_CHILD(void, regions2d, find::one);
GNDSTK_MAKE_CHILD(void, resolved, find::one);
GNDSTK_MAKE_CHILD(void, resolvedRegion, find::one);
GNDSTK_MAKE_CHILD(void, resonanceParameters, find::one);
GNDSTK_MAKE_CHILD(void, resonances, find::one);
GNDSTK_MAKE_CHILD(void, resonancesWithBackground, find::one);
GNDSTK_MAKE_CHILD(void, RMatrix, find::one);
GNDSTK_MAKE_CHILD(void, rowData, find::one);
GNDSTK_MAKE_CHILD(void, RutherfordScattering, find::one);
GNDSTK_MAKE_CHILD(void, S_alpha_beta, find::one);
GNDSTK_MAKE_CHILD(void, scatteringFactor, find::one);
GNDSTK_MAKE_CHILD(void, scatteringRadius, find::one);
GNDSTK_MAKE_CHILD(void, shortRangeSelfScalingVariance, find::one);
GNDSTK_MAKE_CHILD(void, simpleMaxwellianFission, find::one);
GNDSTK_MAKE_CHILD(void, spin, find::one);
GNDSTK_MAKE_CHILD(void, S_table, find::one);
GNDSTK_MAKE_CHILD(void, standard, find::one);
GNDSTK_MAKE_CHILD(void, string, find::one);
GNDSTK_MAKE_CHILD(void, styles, find::one);
GNDSTK_MAKE_CHILD(void, table, find::one);
GNDSTK_MAKE_CHILD(void, tabulatedWidths, find::one);
GNDSTK_MAKE_CHILD(void, T_effective, find::one);
GNDSTK_MAKE_CHILD(void, temperature, find::one);
GNDSTK_MAKE_CHILD(void, theta, find::one);
GNDSTK_MAKE_CHILD(void, time, find::one);
GNDSTK_MAKE_CHILD(void, T_M, find::one);
GNDSTK_MAKE_CHILD(void, totalEnergy, find::one);
GNDSTK_MAKE_CHILD(void, U, find::one);
GNDSTK_MAKE_CHILD(void, uncertainty, find::one);
GNDSTK_MAKE_CHILD(void, uncorrelated, find::one);
GNDSTK_MAKE_CHILD(void, unresolved, find::one);
GNDSTK_MAKE_CHILD(void, unresolvedRegion, find::one);
GNDSTK_MAKE_CHILD(void, unspecified, find::one);
GNDSTK_MAKE_CHILD(void, weightedFunctionals, find::one);
GNDSTK_MAKE_CHILD(void, xml, find::one);
GNDSTK_MAKE_CHILD(void, XYs3d, find::one);
GNDSTK_MAKE_CHILD(void, yields, find::one);



// -----------------------------------------------------------------------------
// keywords
// Some special cases
// -----------------------------------------------------------------------------

// Double
// Not called double, for obvious reasons.
inline const child_t<void,find::one> Double("double");

// cdata, comment
// These are where XML <![CDATA[...]]> or <!-- ... --> (comment) material
// resides. It's reasonable to extract such content into std::strings. We
// then store these as nodes of those respective names, each with one metadatum
// having a key of "text" and a value containing the original content.
inline const child_t<std::string,find::one,detail::text_metadatum_to_string>
   cdata("cdata");
inline const child_t<std::string,find::all,detail::text_metadatum_to_string>
   comment("comment");

// pcdata
// These are where XML material appearing in constructs like this:
//    <values>1.2 3.4 5.6 7.8 9.0</values>
// resides. In that case, our internal tree structure would have a node named
// values, which would have a child node named pcdata, which would have a
// metadatum with a key of "text" and a value containing the original content:
// the "1.2 ..." in the above example. Our examination of many GNDS files shows
// that some pcdata nodes contain integers, while others contain doubles. We
// therefore define pcdata as a child_t with <void>, so that we can access it
// in its original form and thus dig further down to its "text" metadatum, at
// which point we can decide elsewhere what's appropriate for that. (Read into
// a vector of ints? Into vector of doubles? Into something else?)
inline const child_t<void,find::one>
   pcdata("pcdata");



// -----------------------------------------------------------------------------
// values
// -----------------------------------------------------------------------------

// convert_pcdata_text
// This object, via its type, provides conversions between certain C++ container
// types, and nodes that contain plain character data (pcdata) content.
inline const detail::convert_pcdata_text_t convert_pcdata_text;

// values
template<class T = double>
inline const child_t<
   typename detail::values_type<T>::type,
   find::one,
   detail::convert_pcdata_text_t
> values("values",convert_pcdata_text);

} // namespace child
