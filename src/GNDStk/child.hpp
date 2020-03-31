
// -----------------------------------------------------------------------------
// child_t
// -----------------------------------------------------------------------------

/*
// ------------------------
// Description
// ------------------------

RESULT

   The type to which GNDStk should convert a Node<> that's extracted from
   a Tree<> with the child_t object in question. If RESULT is void, then
   GNDStk uses Node<*> (the child node, in its original form in the tree),
   where * is whatever template parameters are in play with the particular
   Tree<> being queried. The fact that there's no fixed Node<> type is why
   we use void for this meaning.

MULTIPLE

   A boolean that indicates whether or not the particular child node can
   appear multiple times in whatever context it's found in. For example,
   an XML-format GNDS might have:

      <axes>
         <axis> ... </axis>
         <axis> ... </axis>
         <axis> ... </axis>
         ...
      </axes>

   In other words: there are (or can be) *multiple* <axis> nodes within
   a particular enclosing context (here, <axes>). MULTIPLE is a template
   parameter because it affects the type that's pulled from the Tree when
   a child_t object is used for a query. For example,

      tree(...,axes,axis)

   gives back a container of axis objects, not a single axis object, due
   to our child_t axis keyword having a true MULTIPLE. (Note: axes has
   a false MULTIPLE, because it isn't *axes*, but *axis*, that's allowed
   to have multiple values.)

METADATA

   fixme: not entirely implemented yet.

   This is metadata<M1,M2,...> for some meta_t types M1, M2, .... These
   meta_t types indicate what types of metadata this child_t is allowed
   to have. This information will be used in a SFINAE context to ensure
   that a particular drill-down into the Tree is well-structured.

   Defaults to metadata<>, which means that we're allowing this child_t
   to have any type of children.

   At the moment, we're building all our keywords this way. The goal is
   to eventually outfit these with proper specifications of what metadata
   are allowed, if such specifications are well-defined in GNDS.

CHILDREN

   fixme: not entirely implemented yet.

   This is children<C1,C2,...> for some child_t types C1, C2, ....
   Similar to METADATA, but defines what children this child_t can have.

*/

template<class RESULT, bool MULTIPLE, class METADATA, class CHILDREN>
class child_t {
public:
   // data
   const std::string name;
   const bool canBeTopLevel;

   // ctor
   explicit child_t(const std::string &n, const bool top = false) :
      name(n), canBeTopLevel(top)
   { }
};

// operator-
template<class RESULT, bool MULTIPLE, class METADATA, class CHILDREN>
inline child_t<void,MULTIPLE,METADATA,CHILDREN> operator-(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &kwd
) {
   return child_t<void,MULTIPLE,METADATA,CHILDREN>(kwd.name,kwd.canBeTopLevel);
}



// -----------------------------------------------------------------------------
// Macros
// For child_t building
// -----------------------------------------------------------------------------

// void (unspecified) result type (so, Node<>)
#define GNDSTK_MAKE_CHILD_DEFAULT(name,multiple) \
   inline const child_t<void,multiple> name(#name)

// user-defined result type
#define GNDSTK_MAKE_CHILD(result,name,multiple) \
   inline const child_t<result,multiple> name(#name)

// Note: we won't #undef these later, as one often would with macros,
// because they're both perfectly viable for users to invoke.



// -----------------------------------------------------------------------------
// Keywords for allowable top-level nodes
// -----------------------------------------------------------------------------

namespace child {

// Remember:
// false in <> means it's NOT "multiple" as described above (none of these are)
// true  in () means it's allowed as a top-level node (all of these are)

inline const child_t<void,false>
   reactionSuite      ("reactionSuite",       true),
   covarianceSuite    ("covarianceSuite",     true),
   PoPs               ("PoPs",                true),
   thermalScattering  ("thermalScattering",   true),
   fissionFragmentData("fissionFragmentData", true);
// fixme Not sure about fissionFragmentData

} // namespace child



// -----------------------------------------------------------------------------
// Keywords
// Of type child_t<*>
//
// fixme Eventually, many (or most (or all)) deserve a solid type,
// not child_t's default.
// -----------------------------------------------------------------------------

namespace child {

// ------------------------
// Single + multiple pair
// constructs
// ------------------------

GNDSTK_MAKE_CHILD_DEFAULT(averageEnergies, false);
GNDSTK_MAKE_CHILD_DEFAULT(averageEnergy,   true);

GNDSTK_MAKE_CHILD_DEFAULT(axes, false);
GNDSTK_MAKE_CHILD_DEFAULT(axis, true);

GNDSTK_MAKE_CHILD_DEFAULT(baryons, false);
GNDSTK_MAKE_CHILD_DEFAULT(baryon,  true);

GNDSTK_MAKE_CHILD_DEFAULT(channels, false);
GNDSTK_MAKE_CHILD_DEFAULT(channel,  true);

GNDSTK_MAKE_CHILD_DEFAULT(chemicalElements, false);
GNDSTK_MAKE_CHILD_DEFAULT(chemicalElement,  true);

GNDSTK_MAKE_CHILD_DEFAULT(configurations, false);
GNDSTK_MAKE_CHILD_DEFAULT(configuration,  true);

GNDSTK_MAKE_CHILD_DEFAULT(decayModes, false);
GNDSTK_MAKE_CHILD_DEFAULT(decayMode,  true);

GNDSTK_MAKE_CHILD_DEFAULT(durations, false);
GNDSTK_MAKE_CHILD_DEFAULT(duration,  true);

GNDSTK_MAKE_CHILD_DEFAULT(externalFiles, false);
GNDSTK_MAKE_CHILD_DEFAULT(externalFile,  true);

GNDSTK_MAKE_CHILD_DEFAULT(fissionComponents, false);
GNDSTK_MAKE_CHILD_DEFAULT(fissionComponent,  true);

GNDSTK_MAKE_CHILD_DEFAULT(isotopes, false);
GNDSTK_MAKE_CHILD_DEFAULT(isotope,  true);

GNDSTK_MAKE_CHILD_DEFAULT(Js, false);
GNDSTK_MAKE_CHILD_DEFAULT(J,  true);

GNDSTK_MAKE_CHILD_DEFAULT(leptons, false);
GNDSTK_MAKE_CHILD_DEFAULT(lepton,  true);

GNDSTK_MAKE_CHILD_DEFAULT(nuclides, false);
GNDSTK_MAKE_CHILD_DEFAULT(nuclide,  true);

GNDSTK_MAKE_CHILD_DEFAULT(productions, false);
GNDSTK_MAKE_CHILD_DEFAULT(production,  true);

GNDSTK_MAKE_CHILD_DEFAULT(products, false);
GNDSTK_MAKE_CHILD_DEFAULT(product,  true);

GNDSTK_MAKE_CHILD_DEFAULT(reactions, false);
GNDSTK_MAKE_CHILD_DEFAULT(reaction,  true);

GNDSTK_MAKE_CHILD_DEFAULT(resonanceReactions, false);
GNDSTK_MAKE_CHILD_DEFAULT(resonanceReaction,  true);

GNDSTK_MAKE_CHILD_DEFAULT(scatteringAtoms, false);
GNDSTK_MAKE_CHILD_DEFAULT(scatteringAtom,  true);

GNDSTK_MAKE_CHILD_DEFAULT(spectra, false);
GNDSTK_MAKE_CHILD_DEFAULT(spectrum, true);

GNDSTK_MAKE_CHILD_DEFAULT(spinGroups, false);
GNDSTK_MAKE_CHILD_DEFAULT(spinGroup,  true);

GNDSTK_MAKE_CHILD_DEFAULT(widths, false);
GNDSTK_MAKE_CHILD_DEFAULT(width,  true);

GNDSTK_MAKE_CHILD_DEFAULT(sums, false);
GNDSTK_MAKE_CHILD_DEFAULT(sum,  true);

GNDSTK_MAKE_CHILD_DEFAULT(Ls, false);
GNDSTK_MAKE_CHILD_DEFAULT(L,  true);

GNDSTK_MAKE_CHILD_DEFAULT(summands, false);
GNDSTK_MAKE_CHILD_DEFAULT(summand,  true);



// ------------------------
// Plain old keywords
// ------------------------

// fixme
// Do more sorting/categorization
// Some may actually be singular/plural pairs as above

// multiple == true
GNDSTK_MAKE_CHILD_DEFAULT(add, true);
GNDSTK_MAKE_CHILD_DEFAULT(averageParameterCovariance, true);
GNDSTK_MAKE_CHILD_DEFAULT(column, true);
GNDSTK_MAKE_CHILD_DEFAULT(conversion, true);
GNDSTK_MAKE_CHILD_DEFAULT(covariance, true);
GNDSTK_MAKE_CHILD_DEFAULT(covarianceMatrix, true);
GNDSTK_MAKE_CHILD_DEFAULT(crossSectionSum, true);
GNDSTK_MAKE_CHILD_DEFAULT(decay, true);
GNDSTK_MAKE_CHILD_DEFAULT(discrete, true);
GNDSTK_MAKE_CHILD_DEFAULT(grid, true);
GNDSTK_MAKE_CHILD_DEFAULT(Legendre, true);
GNDSTK_MAKE_CHILD_DEFAULT(metaStable, true);
GNDSTK_MAKE_CHILD_DEFAULT(multiplicitySum, true);
GNDSTK_MAKE_CHILD_DEFAULT(parameterLink, true);
GNDSTK_MAKE_CHILD_DEFAULT(regions1d, true);
GNDSTK_MAKE_CHILD_DEFAULT(section, true);
GNDSTK_MAKE_CHILD_DEFAULT(shell, true);
GNDSTK_MAKE_CHILD_DEFAULT(values, true);
GNDSTK_MAKE_CHILD_DEFAULT(weighted, true);
GNDSTK_MAKE_CHILD_DEFAULT(XYs1d, true);
GNDSTK_MAKE_CHILD_DEFAULT(XYs2d, true);

// multiple == false
GNDSTK_MAKE_CHILD_DEFAULT(aliases, false);
GNDSTK_MAKE_CHILD_DEFAULT(angular, false);
GNDSTK_MAKE_CHILD_DEFAULT(angularEnergy, false);
GNDSTK_MAKE_CHILD_DEFAULT(angularTwoBody, false);
GNDSTK_MAKE_CHILD_DEFAULT(applicationData, false);
GNDSTK_MAKE_CHILD_DEFAULT(array, false);
GNDSTK_MAKE_CHILD_DEFAULT(atomic, false);
GNDSTK_MAKE_CHILD_DEFAULT(averageProductEnergy, false);
GNDSTK_MAKE_CHILD_DEFAULT(background, false);
GNDSTK_MAKE_CHILD_DEFAULT(bindingEnergy, false);
GNDSTK_MAKE_CHILD_DEFAULT(branching1d, false);
GNDSTK_MAKE_CHILD_DEFAULT(branching3d, false);
GNDSTK_MAKE_CHILD_DEFAULT(BreitWigner, false);
GNDSTK_MAKE_CHILD_DEFAULT(characteristicCrossSection, false);
GNDSTK_MAKE_CHILD_DEFAULT(charge, false);
GNDSTK_MAKE_CHILD_DEFAULT(coherentElastic, false);
GNDSTK_MAKE_CHILD_DEFAULT(coherentPhotonScattering, false);
GNDSTK_MAKE_CHILD_DEFAULT(columnData, false);
GNDSTK_MAKE_CHILD_DEFAULT(columnHeaders, false);
GNDSTK_MAKE_CHILD_DEFAULT(constant1d, false);
GNDSTK_MAKE_CHILD_DEFAULT(continuum, false);
GNDSTK_MAKE_CHILD_DEFAULT(CoulombPlusNuclearElastic, false);
GNDSTK_MAKE_CHILD_DEFAULT(covarianceSections, false);
GNDSTK_MAKE_CHILD_DEFAULT(crossSection, false);
GNDSTK_MAKE_CHILD_DEFAULT(crossSectionReconstructed, false);
GNDSTK_MAKE_CHILD_DEFAULT(crossSections, false);
GNDSTK_MAKE_CHILD_DEFAULT(cutoffEnergy, false);
GNDSTK_MAKE_CHILD_DEFAULT(data, false);
GNDSTK_MAKE_CHILD_DEFAULT(DebyeWaller, false);
GNDSTK_MAKE_CHILD_DEFAULT(decayData, false);
GNDSTK_MAKE_CHILD_DEFAULT(decayPath, false);
GNDSTK_MAKE_CHILD_DEFAULT(delayedBetaEnergy, false);
GNDSTK_MAKE_CHILD_DEFAULT(delayedGammaEnergy, false);
GNDSTK_MAKE_CHILD_DEFAULT(delayedNeutronKE, false);
GNDSTK_MAKE_CHILD_DEFAULT(discreteGamma, false);
GNDSTK_MAKE_CHILD_DEFAULT(distribution, false);
GNDSTK_MAKE_CHILD_DEFAULT(documentation, false);
GNDSTK_MAKE_CHILD_DEFAULT(documentations, false);
GNDSTK_MAKE_CHILD_DEFAULT(doubleDifferentialCrossSection, false);
GNDSTK_MAKE_CHILD_DEFAULT(e_critical, false);
GNDSTK_MAKE_CHILD_DEFAULT(EFH, false);
GNDSTK_MAKE_CHILD_DEFAULT(EFL, false);
GNDSTK_MAKE_CHILD_DEFAULT(e_max, false);
GNDSTK_MAKE_CHILD_DEFAULT(ENDFconversionFlags, false);
GNDSTK_MAKE_CHILD_DEFAULT(energy, false);
GNDSTK_MAKE_CHILD_DEFAULT(energyAngular, false);
GNDSTK_MAKE_CHILD_DEFAULT(evaluated, false);
GNDSTK_MAKE_CHILD_DEFAULT(evaporation, false);
GNDSTK_MAKE_CHILD_DEFAULT(f, false);
GNDSTK_MAKE_CHILD_DEFAULT(fastRegion, false);
GNDSTK_MAKE_CHILD_DEFAULT(fissionEnergyReleased, false);
GNDSTK_MAKE_CHILD_DEFAULT(fraction, false);
GNDSTK_MAKE_CHILD_DEFAULT(freeAtomCrossSection, false);
GNDSTK_MAKE_CHILD_DEFAULT(g, false);
GNDSTK_MAKE_CHILD_DEFAULT(gaugeBoson, false);
GNDSTK_MAKE_CHILD_DEFAULT(gaugeBosons, false);
GNDSTK_MAKE_CHILD_DEFAULT(generalEvaporation, false);
GNDSTK_MAKE_CHILD_DEFAULT(gridded2d, false);
GNDSTK_MAKE_CHILD_DEFAULT(gridded3d, false);
GNDSTK_MAKE_CHILD_DEFAULT(halflife, false);
GNDSTK_MAKE_CHILD_DEFAULT(hardSphereRadius, false);
GNDSTK_MAKE_CHILD_DEFAULT(imaginaryAnomalousFactor, false);
GNDSTK_MAKE_CHILD_DEFAULT(imaginaryInterferenceTerm, false);
GNDSTK_MAKE_CHILD_DEFAULT(incoherentElastic, false);
GNDSTK_MAKE_CHILD_DEFAULT(incoherentInelastic, false);
GNDSTK_MAKE_CHILD_DEFAULT(incoherentPhotonScattering, false);
GNDSTK_MAKE_CHILD_DEFAULT(incompleteReactions, false);
GNDSTK_MAKE_CHILD_DEFAULT(institution, false);
GNDSTK_MAKE_CHILD_DEFAULT(integer, false);
GNDSTK_MAKE_CHILD_DEFAULT(intensity, false);
GNDSTK_MAKE_CHILD_DEFAULT(internalConversionCoefficients, false);
GNDSTK_MAKE_CHILD_DEFAULT(internalPairFormationCoefficient, false);
GNDSTK_MAKE_CHILD_DEFAULT(isotropic2d, false);
GNDSTK_MAKE_CHILD_DEFAULT(KalbachMann, false);
GNDSTK_MAKE_CHILD_DEFAULT(levelSpacing, false);
GNDSTK_MAKE_CHILD_DEFAULT(link, false);
GNDSTK_MAKE_CHILD_DEFAULT(listOfCovariances, false);
GNDSTK_MAKE_CHILD_DEFAULT(MadlandNix, false);
GNDSTK_MAKE_CHILD_DEFAULT(mass, false);
GNDSTK_MAKE_CHILD_DEFAULT(mixed, false);
GNDSTK_MAKE_CHILD_DEFAULT(multiplicities, false);
GNDSTK_MAKE_CHILD_DEFAULT(multiplicity, false);
GNDSTK_MAKE_CHILD_DEFAULT(NBodyPhaseSpace, false);
GNDSTK_MAKE_CHILD_DEFAULT(neutrinoEnergy, false);
GNDSTK_MAKE_CHILD_DEFAULT(nonNeutrinoEnergy, false);
GNDSTK_MAKE_CHILD_DEFAULT(nuclearAmplitudeExpansion, false);
GNDSTK_MAKE_CHILD_DEFAULT(nuclearPlusInterference, false);
GNDSTK_MAKE_CHILD_DEFAULT(nuclearTerm, false);
GNDSTK_MAKE_CHILD_DEFAULT(nucleus, false);
GNDSTK_MAKE_CHILD_DEFAULT(orphanProducts, false);
GNDSTK_MAKE_CHILD_DEFAULT(outputChannel, false);
GNDSTK_MAKE_CHILD_DEFAULT(parameterCovariance, false);
GNDSTK_MAKE_CHILD_DEFAULT(parameterCovarianceMatrix, false);
GNDSTK_MAKE_CHILD_DEFAULT(parameterCovariances, false);
GNDSTK_MAKE_CHILD_DEFAULT(parameters, false);
GNDSTK_MAKE_CHILD_DEFAULT(parity, false);
GNDSTK_MAKE_CHILD_DEFAULT(photonEmissionProbabilities, false);
GNDSTK_MAKE_CHILD_DEFAULT(pids, false);
GNDSTK_MAKE_CHILD_DEFAULT(polynomial1d, false);
GNDSTK_MAKE_CHILD_DEFAULT(positronEmissionIntensity, false);
GNDSTK_MAKE_CHILD_DEFAULT(primaryGamma, false);
GNDSTK_MAKE_CHILD_DEFAULT(probability, false);
GNDSTK_MAKE_CHILD_DEFAULT(productYield, false);
GNDSTK_MAKE_CHILD_DEFAULT(productYields, false);
GNDSTK_MAKE_CHILD_DEFAULT(projectileEnergyDomain, false);
GNDSTK_MAKE_CHILD_DEFAULT(promptGammaEnergy, false);
GNDSTK_MAKE_CHILD_DEFAULT(promptNeutronKE, false);
GNDSTK_MAKE_CHILD_DEFAULT(promptProductKE, false);
GNDSTK_MAKE_CHILD_DEFAULT(Q, false);
GNDSTK_MAKE_CHILD_DEFAULT(r, false);
GNDSTK_MAKE_CHILD_DEFAULT(realAnomalousFactor, false);
GNDSTK_MAKE_CHILD_DEFAULT(realInterferenceTerm, false);
GNDSTK_MAKE_CHILD_DEFAULT(recoil, false);
GNDSTK_MAKE_CHILD_DEFAULT(reference, false);
GNDSTK_MAKE_CHILD_DEFAULT(regions2d, false);
GNDSTK_MAKE_CHILD_DEFAULT(resolved, false);
GNDSTK_MAKE_CHILD_DEFAULT(resolvedRegion, false);
GNDSTK_MAKE_CHILD_DEFAULT(resonanceParameters, false);
GNDSTK_MAKE_CHILD_DEFAULT(resonances, false);
GNDSTK_MAKE_CHILD_DEFAULT(resonancesWithBackground, false);
GNDSTK_MAKE_CHILD_DEFAULT(RMatrix, false);
GNDSTK_MAKE_CHILD_DEFAULT(rowData, false);
GNDSTK_MAKE_CHILD_DEFAULT(RutherfordScattering, false);
GNDSTK_MAKE_CHILD_DEFAULT(S_alpha_beta, false);
GNDSTK_MAKE_CHILD_DEFAULT(scatteringFactor, false);
GNDSTK_MAKE_CHILD_DEFAULT(scatteringRadius, false);
GNDSTK_MAKE_CHILD_DEFAULT(shortRangeSelfScalingVariance, false);
GNDSTK_MAKE_CHILD_DEFAULT(simpleMaxwellianFission, false);
GNDSTK_MAKE_CHILD_DEFAULT(spin, false);
GNDSTK_MAKE_CHILD_DEFAULT(S_table, false);
GNDSTK_MAKE_CHILD_DEFAULT(standard, false);
GNDSTK_MAKE_CHILD_DEFAULT(string, false);
GNDSTK_MAKE_CHILD_DEFAULT(styles, false);
GNDSTK_MAKE_CHILD_DEFAULT(table, false);
GNDSTK_MAKE_CHILD_DEFAULT(tabulatedWidths, false);
GNDSTK_MAKE_CHILD_DEFAULT(T_effective, false);
GNDSTK_MAKE_CHILD_DEFAULT(temperature, false);
GNDSTK_MAKE_CHILD_DEFAULT(theta, false);
GNDSTK_MAKE_CHILD_DEFAULT(time, false);
GNDSTK_MAKE_CHILD_DEFAULT(T_M, false);
GNDSTK_MAKE_CHILD_DEFAULT(totalEnergy, false);
GNDSTK_MAKE_CHILD_DEFAULT(U, false);
GNDSTK_MAKE_CHILD_DEFAULT(uncertainty, false);
GNDSTK_MAKE_CHILD_DEFAULT(uncorrelated, false);
GNDSTK_MAKE_CHILD_DEFAULT(unresolved, false);
GNDSTK_MAKE_CHILD_DEFAULT(unresolvedRegion, false);
GNDSTK_MAKE_CHILD_DEFAULT(unspecified, false);
GNDSTK_MAKE_CHILD_DEFAULT(weightedFunctionals, false);
GNDSTK_MAKE_CHILD_DEFAULT(xml, false);
GNDSTK_MAKE_CHILD_DEFAULT(XYs3d, false);
GNDSTK_MAKE_CHILD_DEFAULT(yields, false);

} // namespace child



// -----------------------------------------------------------------------------
// keywords
// Special cases, not doable with our macro.
// -----------------------------------------------------------------------------

namespace child {

// Double
// Not called double, for obvious reasons.
inline const child_t<void,false> Double("double");

} // namespace child
