
// Used by child_t
// metadata
// children
template<class... Ms> class metadata { };
template<class... Cs> class children { };



// -----------------------------------------------------------------------------
// child_t
// -----------------------------------------------------------------------------

/*
// ------------------------
// Description
// ------------------------

RESULT

   The type to which GNDStk should convert a Node<> that's extracted from
   a Tree<> with the child_t object. If RESULT is void, then GNDStk uses
   Node<*> (the child node, in its original form in the tree), where *
   is whatever template parameters are in play with the particular Tree<>
   being queried.

FIND

   A value, of enum class find, that indicates whether or not the kind of
   node in question is expected to appear one time, or any number of times.
   Consider, for example, that an XML-format GNDS might have:

      <axes>
         <axis> ... </axis>
         <axis> ... </axis>
         <axis> ... </axis>
         ...
      </axes>

   In other words: there are (or can be) any number of <axis> nodes within
   an enclosing context (here, <axes>). FIND is a template parameter because
   it affects the *type* that's pulled from the Tree when the child_t object
   is used for a query. For example,

      tree(...,axes,axis)

   gives back a container of axis objects, not a single axis object, because
   our child_t axis keyword has FIND == find::any. Note that axes, not to be
   confused with axis, has FIND == find::one because it's expected just once.

CONVERTER

   Custom conversion between RESULT and Node, if we wish to override the
   default of calling the overloaded function convert() to do the conversion.

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

// ------------------------
// default
// ------------------------

template<
   class RESULT    = void,       // default means current Node type
   find  FIND      = find::one,  // one, or any number allowed?
   class CONVERTER = typename detail::default_converter<RESULT>::type,
   class METADATA  = metadata<>, // allowable metadata for this child-node type
   class CHILDREN  = children<>  // allowable children ...
>
class child_t {
public:
   // name, converter, can be top level?
   const std::string name;
   const CONVERTER converter; // optional custom converter; needs operator()
   const bool canBeTopLevel;

   // ctor(name)
   // ctor(name,top)
   // ctor(name,top,converter)
   explicit child_t(
      const std::string &n,
      const bool top = false,
      const CONVERTER &c = CONVERTER{}
   ) :
      name(n), converter(c), canBeTopLevel(top)
   { }

   // ctor(name,converter)
   // ctor(name,converter,top)
   child_t(
      const std::string &n,
      const CONVERTER &c,
      const bool top = false
   ) :
      name(n), converter(c), canBeTopLevel(top)
   { }
};



// ------------------------
// void (valid)
// ------------------------

template<find FIND, class METADATA, class CHILDREN>
class child_t<void,FIND,detail::failure_t,METADATA,CHILDREN> {
public:
   // name, can be top level?
   const std::string name;
   const bool canBeTopLevel;

   // ctor(name)
   // ctor(name,top)
   explicit child_t(
      const std::string &n,
      const bool top = false
   ) :
      name(n), canBeTopLevel(top)
   { }
};



// ------------------------
// void (invalid)
// ------------------------

template<find FIND, class CONVERTER, class METADATA, class CHILDREN>
class child_t<void,FIND,CONVERTER,METADATA,CHILDREN> {
   static_assert(
      !std::is_same<CONVERTER,detail::failure_t>::value,
      "Can't instantiate child_t<void,FIND,CONVERTER> "
      "with non-default CONVERTER"
   );
};



// -----------------------------------------------------------------------------
// voidify
// one/all --/++
// -----------------------------------------------------------------------------

// operator-
template<class TYPE, find FIND, class CONVERTER, class METADATA, class CHILDREN>
inline auto operator-(
   const child_t<TYPE,FIND,CONVERTER,METADATA,CHILDREN> &kwd
) {
   return child_t<void,FIND,detail::failure_t,METADATA,CHILDREN>(
      kwd.name, kwd.canBeTopLevel
   );
}

// child_t<void>--
template<find FIND, class METADATA, class CHILDREN>
inline auto operator--(
   const child_t<void,FIND,detail::failure_t,METADATA,CHILDREN> &kwd, const int
) {
   return child_t<void,find::one,detail::failure_t,METADATA,CHILDREN>(
      kwd.name, kwd.canBeTopLevel
   );
}

// child_t<void>++
template<find FIND, class METADATA, class CHILDREN>
inline auto operator++(
   const child_t<void,FIND,detail::failure_t,METADATA,CHILDREN> &kwd, const int
) {
   return child_t<void,find::all,detail::failure_t,METADATA,CHILDREN>(
      kwd.name, kwd.canBeTopLevel
   );
}

// child_t<TYPE>--
template<class TYPE, find FIND, class CONVERTER, class METADATA, class CHILDREN>
inline auto operator--(
   const child_t<TYPE,FIND,CONVERTER,METADATA,CHILDREN> &kwd, const int
) {
   return child_t<TYPE,find::one,CONVERTER,METADATA,CHILDREN>(
      kwd.name, kwd.converter, kwd.canBeTopLevel
   );
}

// child_t<TYPE>++
template<class TYPE, find FIND, class CONVERTER, class METADATA, class CHILDREN>
inline auto operator++(
   const child_t<TYPE,FIND,CONVERTER,METADATA,CHILDREN> &kwd, const int
) {
   return child_t<TYPE,find::all,CONVERTER,METADATA,CHILDREN>(
      kwd.name, kwd.converter, kwd.canBeTopLevel
   );
}



// -----------------------------------------------------------------------------
// Macros
// For child_t building. The macros don't handle the optional converter;
// for that, just construct such an object directly.
// -----------------------------------------------------------------------------

// void (unspecified) result type (so, Node<>)
#define GNDSTK_MAKE_CHILD_DEFAULT(name,FIND) \
   inline const child_t<void,FIND> name(#name)

// user-defined result type
#define GNDSTK_MAKE_CHILD(result,name,FIND) \
   inline const child_t<result,FIND> name(#name)

// Note: we won't #undef these eventually, as we normally would,
// because they're perfectly viable macros for users to invoke.



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
//
// fixme Eventually, many (or most (or all)) deserve a solid type,
// not child_t's default.
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
// Special cases, not doable with our macro.
// -----------------------------------------------------------------------------

namespace child {

// Double
// Not called double, for obvious reasons.
inline const child_t<void,find::one> Double("double");

} // namespace child
