
namespace child {

// -----------------------------------------------------------------------------
// Allowable top-level nodes, per LLNL-TR-774621-DRAFT
// -----------------------------------------------------------------------------

// Note: the ~ (tilde) makes them allowed as top-level nodes
inline const auto
   PoPs                = ~child_t<void,allow::one>("PoPs");
inline const auto
   reactionSuite       = ~child_t<void,allow::one>("reactionSuite");
inline const auto
   covarianceSuite     = ~child_t<void,allow::one>("covarianceSuite");
inline const auto
   thermalScattering   = ~child_t<void,allow::one>("thermalScattering");
inline const auto
   fissionFragmentData = ~child_t<void,allow::one>("fissionFragmentData");



// -----------------------------------------------------------------------------
// Keywords
// Of type child_t
// -----------------------------------------------------------------------------

// ------------------------
// one + many pair
// constructs
// ------------------------

GNDSTK_MAKE_CHILD(void, averageEnergies, one);
GNDSTK_MAKE_CHILD(void, averageEnergy,   many);

GNDSTK_MAKE_CHILD(void, axes, one);
GNDSTK_MAKE_CHILD(void, axis, many);

GNDSTK_MAKE_CHILD(void, baryons, one);
GNDSTK_MAKE_CHILD(void, baryon,  many);

GNDSTK_MAKE_CHILD(void, channels, one);
GNDSTK_MAKE_CHILD(void, channel,  many);

GNDSTK_MAKE_CHILD(void, chemicalElements, one);
GNDSTK_MAKE_CHILD(void, chemicalElement,  many);

GNDSTK_MAKE_CHILD(void, configurations, one);
GNDSTK_MAKE_CHILD(void, configuration,  many);

GNDSTK_MAKE_CHILD(void, decayModes, one);
GNDSTK_MAKE_CHILD(void, decayMode,  many);

GNDSTK_MAKE_CHILD(void, durations, one);
GNDSTK_MAKE_CHILD(void, duration,  many);

GNDSTK_MAKE_CHILD(void, externalFiles, one);
GNDSTK_MAKE_CHILD(void, externalFile,  many);

GNDSTK_MAKE_CHILD(void, fissionComponents, one);
GNDSTK_MAKE_CHILD(void, fissionComponent,  many);

GNDSTK_MAKE_CHILD(void, gaugeBosons, one);
GNDSTK_MAKE_CHILD(void, gaugeBoson, many);

GNDSTK_MAKE_CHILD(void, isotopes, one);
GNDSTK_MAKE_CHILD(void, isotope,  many);

GNDSTK_MAKE_CHILD(void, Js, one);
GNDSTK_MAKE_CHILD(void, J,  many);

GNDSTK_MAKE_CHILD(void, leptons, one);
GNDSTK_MAKE_CHILD(void, lepton,  many);

GNDSTK_MAKE_CHILD(void, nuclides, one);
GNDSTK_MAKE_CHILD(void, nuclide,  many);

GNDSTK_MAKE_CHILD(void, productions, one);
// The GNDS manual says:
//    production: [optional, must appear one time]
// but we think that that's wrong. It actually does appear more than once
// in some parent nodes in some GNDS files. We think the manual makes the
// same mistake at least two more times - with <conversion> and <weighted>.
// Both sometimes appear multiple times under a single parent in some GNDS
// files, but the manual says "must appear one time" for both. (The manual
// says "must appear at least one time" elsewhere, for things that can
// appear multiple times under a single parent.)
GNDSTK_MAKE_CHILD(void, production,  many);

GNDSTK_MAKE_CHILD(void, products, one);
GNDSTK_MAKE_CHILD(void, product,  many);

GNDSTK_MAKE_CHILD(void, productYields, one);
GNDSTK_MAKE_CHILD(void, productYield, many);

GNDSTK_MAKE_CHILD(void, reactions, one);
GNDSTK_MAKE_CHILD(void, reaction,  many);

GNDSTK_MAKE_CHILD(void, resonanceReactions, one);
GNDSTK_MAKE_CHILD(void, resonanceReaction,  many);

GNDSTK_MAKE_CHILD(void, scatteringAtoms, one);
GNDSTK_MAKE_CHILD(void, scatteringAtom,  many);

GNDSTK_MAKE_CHILD(void, spectra, one);
GNDSTK_MAKE_CHILD(void, spectrum, many);

GNDSTK_MAKE_CHILD(void, spinGroups, one);
GNDSTK_MAKE_CHILD(void, spinGroup,  many);

GNDSTK_MAKE_CHILD(void, widths, one);
GNDSTK_MAKE_CHILD(void, width,  many);

GNDSTK_MAKE_CHILD(void, sums, one);
GNDSTK_MAKE_CHILD(void, sum,  many);

GNDSTK_MAKE_CHILD(void, Ls, one);
GNDSTK_MAKE_CHILD(void, L,  many);

GNDSTK_MAKE_CHILD(void, summands, one);
GNDSTK_MAKE_CHILD(void, summand,  many);


// ------------------------
// Others, not paired
// as above
// ------------------------

// fixme
// Do more sorting/categorization
// Some may actually be singular/plural pairs

// allow::one cases
GNDSTK_MAKE_CHILD(void, aliases, one);
GNDSTK_MAKE_CHILD(void, angular, one);
GNDSTK_MAKE_CHILD(void, angularEnergy, one);
GNDSTK_MAKE_CHILD(void, angularTwoBody, one);
GNDSTK_MAKE_CHILD(void, applicationData, one);
GNDSTK_MAKE_CHILD(void, array, one);
GNDSTK_MAKE_CHILD(void, atomic, one);
GNDSTK_MAKE_CHILD(void, averageProductEnergy, one);
GNDSTK_MAKE_CHILD(void, background, one);
GNDSTK_MAKE_CHILD(void, bindingEnergy, one);
GNDSTK_MAKE_CHILD(void, branching1d, one);
GNDSTK_MAKE_CHILD(void, branching3d, one);
GNDSTK_MAKE_CHILD(void, BreitWigner, one);
GNDSTK_MAKE_CHILD(void, characteristicCrossSection, one);
GNDSTK_MAKE_CHILD(void, charge, one);
GNDSTK_MAKE_CHILD(void, coherentElastic, one);
GNDSTK_MAKE_CHILD(void, coherentPhotonScattering, one);
GNDSTK_MAKE_CHILD(void, columnData, one);
GNDSTK_MAKE_CHILD(void, columnHeaders, one);
GNDSTK_MAKE_CHILD(void, constant1d, one);
GNDSTK_MAKE_CHILD(void, continuum, one);
GNDSTK_MAKE_CHILD(void, CoulombPlusNuclearElastic, one);
GNDSTK_MAKE_CHILD(void, covarianceSections, one);
GNDSTK_MAKE_CHILD(void, crossSection, one);
GNDSTK_MAKE_CHILD(void, crossSections, one);
GNDSTK_MAKE_CHILD(void, cutoffEnergy, one);
GNDSTK_MAKE_CHILD(void, data, one);
GNDSTK_MAKE_CHILD(void, DebyeWaller, one);
GNDSTK_MAKE_CHILD(void, decayData, one);
GNDSTK_MAKE_CHILD(void, decayPath, one);
GNDSTK_MAKE_CHILD(void, delayedBetaEnergy, one);
GNDSTK_MAKE_CHILD(void, delayedGammaEnergy, one);
GNDSTK_MAKE_CHILD(void, delayedNeutronKE, one);
GNDSTK_MAKE_CHILD(void, discreteGamma, one);
GNDSTK_MAKE_CHILD(void, distribution, one);
GNDSTK_MAKE_CHILD(void, documentation, one);
GNDSTK_MAKE_CHILD(void, documentations, one);
GNDSTK_MAKE_CHILD(void, doubleDifferentialCrossSection, one);
GNDSTK_MAKE_CHILD(void, e_critical, one);
GNDSTK_MAKE_CHILD(void, EFH, one);
GNDSTK_MAKE_CHILD(void, EFL, one);
GNDSTK_MAKE_CHILD(void, e_max, one);
GNDSTK_MAKE_CHILD(void, ENDFconversionFlags, one);
GNDSTK_MAKE_CHILD(void, energy, one);
GNDSTK_MAKE_CHILD(void, energyAngular, one);
GNDSTK_MAKE_CHILD(void, evaporation, one);
GNDSTK_MAKE_CHILD(void, f, one);
GNDSTK_MAKE_CHILD(void, fastRegion, one);
GNDSTK_MAKE_CHILD(void, fissionEnergyReleased, one);
GNDSTK_MAKE_CHILD(void, freeAtomCrossSection, one);
GNDSTK_MAKE_CHILD(void, g, one);
GNDSTK_MAKE_CHILD(void, generalEvaporation, one);
GNDSTK_MAKE_CHILD(void, gridded2d, one);
GNDSTK_MAKE_CHILD(void, gridded3d, one);
GNDSTK_MAKE_CHILD(void, halflife, one);
GNDSTK_MAKE_CHILD(void, hardSphereRadius, one);
GNDSTK_MAKE_CHILD(void, imaginaryAnomalousFactor, one);
GNDSTK_MAKE_CHILD(void, imaginaryInterferenceTerm, one);
GNDSTK_MAKE_CHILD(void, incoherentElastic, one);
GNDSTK_MAKE_CHILD(void, incoherentInelastic, one);
GNDSTK_MAKE_CHILD(void, incoherentPhotonScattering, one);
GNDSTK_MAKE_CHILD(void, incompleteReactions, one);
GNDSTK_MAKE_CHILD(void, institution, one);
GNDSTK_MAKE_CHILD(void, intensity, one);
GNDSTK_MAKE_CHILD(void, internalConversionCoefficients, one);
GNDSTK_MAKE_CHILD(void, internalPairFormationCoefficient, one);
GNDSTK_MAKE_CHILD(void, isotropic2d, one);
GNDSTK_MAKE_CHILD(void, KalbachMann, one);
GNDSTK_MAKE_CHILD(void, levelSpacing, one);
GNDSTK_MAKE_CHILD(void, link, one);
GNDSTK_MAKE_CHILD(void, listOfCovariances, one);
GNDSTK_MAKE_CHILD(void, MadlandNix, one);
GNDSTK_MAKE_CHILD(void, mass, one);
GNDSTK_MAKE_CHILD(void, mixed, one);
GNDSTK_MAKE_CHILD(void, multiplicities, one);
GNDSTK_MAKE_CHILD(void, multiplicity, one);
GNDSTK_MAKE_CHILD(void, NBodyPhaseSpace, one);
GNDSTK_MAKE_CHILD(void, neutrinoEnergy, one);
GNDSTK_MAKE_CHILD(void, nonNeutrinoEnergy, one);
GNDSTK_MAKE_CHILD(void, nuclearAmplitudeExpansion, one);
GNDSTK_MAKE_CHILD(void, nuclearPlusInterference, one);
GNDSTK_MAKE_CHILD(void, nuclearTerm, one);
GNDSTK_MAKE_CHILD(void, nucleus, one);
GNDSTK_MAKE_CHILD(void, orphanProducts, one);
GNDSTK_MAKE_CHILD(void, outputChannel, one);
GNDSTK_MAKE_CHILD(void, parameterCovariances, one);
GNDSTK_MAKE_CHILD(void, parameters, one);
GNDSTK_MAKE_CHILD(void, parity, one);
GNDSTK_MAKE_CHILD(void, photonEmissionProbabilities, one);
GNDSTK_MAKE_CHILD(void, pids, one);
GNDSTK_MAKE_CHILD(void, polynomial1d, one);
GNDSTK_MAKE_CHILD(void, positronEmissionIntensity, one);
GNDSTK_MAKE_CHILD(void, primaryGamma, one);
GNDSTK_MAKE_CHILD(void, probability, one);
GNDSTK_MAKE_CHILD(void, projectileEnergyDomain, one);
GNDSTK_MAKE_CHILD(void, promptGammaEnergy, one);
GNDSTK_MAKE_CHILD(void, promptNeutronKE, one);
GNDSTK_MAKE_CHILD(void, promptProductKE, one);
GNDSTK_MAKE_CHILD(void, Q, one);
GNDSTK_MAKE_CHILD(void, r, one);
GNDSTK_MAKE_CHILD(void, realAnomalousFactor, one);
GNDSTK_MAKE_CHILD(void, realInterferenceTerm, one);
GNDSTK_MAKE_CHILD(void, recoil, one);
GNDSTK_MAKE_CHILD(void, reference, one);
GNDSTK_MAKE_CHILD(void, regions2d, one);
GNDSTK_MAKE_CHILD(void, resolved, one);
GNDSTK_MAKE_CHILD(void, resolvedRegion, one);
GNDSTK_MAKE_CHILD(void, resonanceParameters, one);
GNDSTK_MAKE_CHILD(void, resonances, one);
GNDSTK_MAKE_CHILD(void, resonancesWithBackground, one);
GNDSTK_MAKE_CHILD(void, RMatrix, one);
GNDSTK_MAKE_CHILD(void, rowData, one);
GNDSTK_MAKE_CHILD(void, RutherfordScattering, one);
GNDSTK_MAKE_CHILD(void, S_alpha_beta, one);
GNDSTK_MAKE_CHILD(void, scatteringFactor, one);
GNDSTK_MAKE_CHILD(void, scatteringRadius, one);
GNDSTK_MAKE_CHILD(void, simpleMaxwellianFission, one);
GNDSTK_MAKE_CHILD(void, spin, one);
GNDSTK_MAKE_CHILD(void, S_table, one);
GNDSTK_MAKE_CHILD(void, standard, one);
GNDSTK_MAKE_CHILD(void, string, one);
GNDSTK_MAKE_CHILD(void, styles, one);
GNDSTK_MAKE_CHILD(void, table, one);
GNDSTK_MAKE_CHILD(void, tabulatedWidths, one);
GNDSTK_MAKE_CHILD(void, T_effective, one);
GNDSTK_MAKE_CHILD(void, temperature, one);
GNDSTK_MAKE_CHILD(void, theta, one);
GNDSTK_MAKE_CHILD(void, time, one);
GNDSTK_MAKE_CHILD(void, T_M, one);
GNDSTK_MAKE_CHILD(void, totalEnergy, one);
GNDSTK_MAKE_CHILD(void, U, one);
GNDSTK_MAKE_CHILD(void, uncertainty, one);
GNDSTK_MAKE_CHILD(void, uncorrelated, one);
GNDSTK_MAKE_CHILD(void, unresolved, one);
GNDSTK_MAKE_CHILD(void, unresolvedRegion, one);
GNDSTK_MAKE_CHILD(void, unspecified, one);
GNDSTK_MAKE_CHILD(void, weightedFunctionals, one);
GNDSTK_MAKE_CHILD(void, xml, one);
GNDSTK_MAKE_CHILD(void, yields, one);

// allow::many cases
GNDSTK_MAKE_CHILD(void, add, many);
GNDSTK_MAKE_CHILD(void, averageParameterCovariance, many);
GNDSTK_MAKE_CHILD(void, column, many);
GNDSTK_MAKE_CHILD(void, conversion, many);
GNDSTK_MAKE_CHILD(void, covariance, many);
GNDSTK_MAKE_CHILD(void, covarianceMatrix, many);
GNDSTK_MAKE_CHILD(void, crossSectionReconstructed, many);
GNDSTK_MAKE_CHILD(void, crossSectionSum, many);
GNDSTK_MAKE_CHILD(void, decay, many);
GNDSTK_MAKE_CHILD(void, discrete, many);
GNDSTK_MAKE_CHILD(void, evaluated, many);
GNDSTK_MAKE_CHILD(void, fraction, many);
GNDSTK_MAKE_CHILD(void, grid, many);
GNDSTK_MAKE_CHILD(void, integer, many);
GNDSTK_MAKE_CHILD(void, Legendre, many);
GNDSTK_MAKE_CHILD(void, metaStable, many);
GNDSTK_MAKE_CHILD(void, multiplicitySum, many);
GNDSTK_MAKE_CHILD(void, parameterCovariance, many);
GNDSTK_MAKE_CHILD(void, parameterCovarianceMatrix, many);
GNDSTK_MAKE_CHILD(void, parameterLink, many);
GNDSTK_MAKE_CHILD(void, regions1d, many);
GNDSTK_MAKE_CHILD(void, section, many);
GNDSTK_MAKE_CHILD(void, shell, many);
GNDSTK_MAKE_CHILD(void, shortRangeSelfScalingVariance, many);
GNDSTK_MAKE_CHILD(void, values, many);
GNDSTK_MAKE_CHILD(void, weighted, many);
GNDSTK_MAKE_CHILD(void, XYs1d, many);
GNDSTK_MAKE_CHILD(void, XYs2d, many);
GNDSTK_MAKE_CHILD(void, XYs3d, many);



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
// These are where data appearing in constructs like this:
//    <values>1.2 3.4 5.6 7.8 9.0</values>
// reside. In that case, our internal tree structure would have a node named
// "values", which would have a child node named "pcdata", which would have a
// metadatum with a key of "text" and a value containing the original content:
// the "1.2 ..." in the above example. Our examination of many GNDS files shows
// that some pcdata nodes contain integers, while others contain doubles. We
// therefore define pcdata as a child_t with <void>, so that we can access it
// in its original form and thus dig further down to its "text" metadatum, at
// which point we can decide elsewhere what's appropriate for that. (Read into
// a vector of ints? A vector of doubles? Something else?)
inline const child_t<void,allow::one>
   pcdata("pcdata");

} // namespace child
