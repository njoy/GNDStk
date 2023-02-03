
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_KEY
#define ALPHA_V2_0_KEY

// GNDStk Core Interface
#include "GNDStk.hpp"

namespace alpha {
namespace v2_0 {

using namespace njoy;
using namespace GNDStk;


// -----------------------------------------------------------------------------
// meta::
// -----------------------------------------------------------------------------

namespace meta {

#define GNDSTK_MAKE_LOOKUP(nameField,nameGNDS) \
   inline const auto nameField = makeLookup( \
      [](const auto &obj) -> decltype(obj.nameField()) \
      { return obj.nameField(); }, \
      #nameGNDS \
   )
// nameField vs. nameGNDS: for, e.g., Double vs. double in GNDS

GNDSTK_MAKE_LOOKUP(A,A);
GNDSTK_MAKE_LOOKUP(ENDF_MFMT,ENDF_MFMT);
GNDSTK_MAKE_LOOKUP(ENDF_MT,ENDF_MT);
GNDSTK_MAKE_LOOKUP(L,L);
GNDSTK_MAKE_LOOKUP(Z,Z);
GNDSTK_MAKE_LOOKUP(algorithm,algorithm);
GNDSTK_MAKE_LOOKUP(approximation,approximation);
GNDSTK_MAKE_LOOKUP(boundaryCondition,boundaryCondition);
GNDSTK_MAKE_LOOKUP(calculateChannelRadius,calculateChannelRadius);
GNDSTK_MAKE_LOOKUP(calculatedAtThermal,calculatedAtThermal);
GNDSTK_MAKE_LOOKUP(channelSpin,channelSpin);
GNDSTK_MAKE_LOOKUP(checksum,checksum);
GNDSTK_MAKE_LOOKUP(coefficient,coefficient);
GNDSTK_MAKE_LOOKUP(columnIndex,columnIndex);
GNDSTK_MAKE_LOOKUP(columns,columns);
GNDSTK_MAKE_LOOKUP(complete,complete);
GNDSTK_MAKE_LOOKUP(compression,compression);
GNDSTK_MAKE_LOOKUP(crossTerm,crossTerm);
GNDSTK_MAKE_LOOKUP(date,date);
GNDSTK_MAKE_LOOKUP(dateType,dateType);
GNDSTK_MAKE_LOOKUP(degreesOfFreedom,degreesOfFreedom);
GNDSTK_MAKE_LOOKUP(dependenceOnProcessedGroupWidth,dependenceOnProcessedGroupWidth);
GNDSTK_MAKE_LOOKUP(derivedFrom,derivedFrom);
GNDSTK_MAKE_LOOKUP(dimension,dimension);
GNDSTK_MAKE_LOOKUP(domainMax,domainMax);
GNDSTK_MAKE_LOOKUP(domainMin,domainMin);
GNDSTK_MAKE_LOOKUP(domainUnit,domainUnit);
GNDSTK_MAKE_LOOKUP(domainValue,domainValue);
GNDSTK_MAKE_LOOKUP(ejectile,ejectile);
GNDSTK_MAKE_LOOKUP(electronNumber,electronNumber);
GNDSTK_MAKE_LOOKUP(eliminated,eliminated);
GNDSTK_MAKE_LOOKUP(evaluation,evaluation);
GNDSTK_MAKE_LOOKUP(fissionGenre,fissionGenre);
GNDSTK_MAKE_LOOKUP(flags,flags);
GNDSTK_MAKE_LOOKUP(format,format);
GNDSTK_MAKE_LOOKUP(generation,generation);
GNDSTK_MAKE_LOOKUP(genre,genre);
GNDSTK_MAKE_LOOKUP(href,href);
GNDSTK_MAKE_LOOKUP(id,id);
GNDSTK_MAKE_LOOKUP(identicalParticles,identicalParticles);
GNDSTK_MAKE_LOOKUP(index,index);
GNDSTK_MAKE_LOOKUP(interaction,interaction);
GNDSTK_MAKE_LOOKUP(interpolation,interpolation);
GNDSTK_MAKE_LOOKUP(interpolationQualifier,interpolationQualifier);
GNDSTK_MAKE_LOOKUP(label,label);
GNDSTK_MAKE_LOOKUP(library,library);
GNDSTK_MAKE_LOOKUP(matrixStartIndex,matrixStartIndex);
GNDSTK_MAKE_LOOKUP(max,max);
GNDSTK_MAKE_LOOKUP(metaStableIndex,metaStableIndex);
GNDSTK_MAKE_LOOKUP(min,min);
GNDSTK_MAKE_LOOKUP(mode,mode);
GNDSTK_MAKE_LOOKUP(muCutoff,muCutoff);
GNDSTK_MAKE_LOOKUP(nParameters,nParameters);
GNDSTK_MAKE_LOOKUP(name,name);
GNDSTK_MAKE_LOOKUP(numberOfProducts,numberOfProducts);
GNDSTK_MAKE_LOOKUP(numberPerMolecule,numberPerMolecule);
GNDSTK_MAKE_LOOKUP(outerDomainValue,outerDomainValue);
GNDSTK_MAKE_LOOKUP(parity,parity);
GNDSTK_MAKE_LOOKUP(path,path);
GNDSTK_MAKE_LOOKUP(pid,pid);
GNDSTK_MAKE_LOOKUP(primaryScatterer,primaryScatterer);
GNDSTK_MAKE_LOOKUP(process,process);
GNDSTK_MAKE_LOOKUP(productFrame,productFrame);
GNDSTK_MAKE_LOOKUP(projectile,projectile);
GNDSTK_MAKE_LOOKUP(projectileFrame,projectileFrame);
GNDSTK_MAKE_LOOKUP(resonanceReaction,resonanceReaction);
GNDSTK_MAKE_LOOKUP(rows,rows);
GNDSTK_MAKE_LOOKUP(shape,shape);
GNDSTK_MAKE_LOOKUP(spin,spin);
GNDSTK_MAKE_LOOKUP(style,style);
GNDSTK_MAKE_LOOKUP(subshell,subshell);
GNDSTK_MAKE_LOOKUP(supportsAngularReconstruction,supportsAngularReconstruction);
GNDSTK_MAKE_LOOKUP(symbol,symbol);
GNDSTK_MAKE_LOOKUP(symmetric,symmetric);
GNDSTK_MAKE_LOOKUP(symmetry,symmetry);
GNDSTK_MAKE_LOOKUP(target,target);
GNDSTK_MAKE_LOOKUP(type,type);
GNDSTK_MAKE_LOOKUP(unit,unit);
GNDSTK_MAKE_LOOKUP(useForSelfShieldingOnly,useForSelfShieldingOnly);
GNDSTK_MAKE_LOOKUP(value,value);
GNDSTK_MAKE_LOOKUP(valueType,valueType);
GNDSTK_MAKE_LOOKUP(version,version);

#undef GNDSTK_MAKE_LOOKUP

} // namespace meta


// -----------------------------------------------------------------------------
// alt::child::
// -----------------------------------------------------------------------------

namespace alt {
namespace child {

inline const Child<> distribution("distribution");

} // namespace child
using namespace child;
} // namespace alt


// -----------------------------------------------------------------------------
// g2d::child::
// -----------------------------------------------------------------------------

namespace g2d {
namespace child {

inline const Child<> array("array");

} // namespace child
using namespace child;
} // namespace g2d


// -----------------------------------------------------------------------------
// g3d::child::
// -----------------------------------------------------------------------------

namespace g3d {
namespace child {

inline const Child<> array("array");
inline const Child<> lengths("values");
inline const Child<> starts("values");

} // namespace child
using namespace child;
} // namespace g3d


// -----------------------------------------------------------------------------
// general::child::
// -----------------------------------------------------------------------------

namespace general {
namespace child {

inline const Child<> BreitWigner("BreitWigner");
inline const Child<> CoulombPlusNuclearElastic("CoulombPlusNuclearElastic");
inline const Child<> DebyeWallerIntegral("DebyeWallerIntegral");
inline const Child<> Double("double");
inline const Child<> EFH("EFH");
inline const Child<> EFL("EFL");
inline const Child<> ENDFconversionFlags("ENDFconversionFlags");
inline const Child<> J("J");
inline const Child<> Js("Js");
inline const Child<> KalbachMann("KalbachMann");
inline const Child<> L("L");
inline const Child<> Legendre("Legendre");
inline const Child<> Ls("Ls");
inline const Child<> MadlandNix("MadlandNix");
inline const Child<> NBodyPhaseSpace("NBodyPhaseSpace");
inline const Child<> PoPs("PoPs");
inline const Child<> Q("Q");
inline const Child<> RMatrix("RMatrix");
inline const Child<> RutherfordScattering("RutherfordScattering");
inline const Child<> SCTApproximation("SCTApproximation");
inline const Child<> S_table("S_table");
inline const Child<> T_M("T_M");
inline const Child<> T_effective("T_effective");
inline const Child<> U("U");
inline const Child<> XYs1d("XYs1d");
inline const Child<> XYs2d("XYs2d");
inline const Child<> XYs3d("XYs3d");
inline const Child<> add("add");
inline const Child<> alias("alias");
inline const Child<> aliases("aliases");
inline const Child<> angular("angular");
inline const Child<> angularEnergy("angularEnergy");
inline const Child<> angularTwoBody("angularTwoBody");
inline const Child<> applicationData("applicationData");
inline const Child<> array("array");
inline const Child<> atomic("atomic");
inline const Child<> author("author");
inline const Child<> authors("authors");
inline const Child<> averageEnergies("averageEnergies");
inline const Child<> averageEnergy("averageEnergy");
inline const Child<> averageParameterCovariance("averageParameterCovariance");
inline const Child<> averageProductEnergy("averageProductEnergy");
inline const Child<> axes("axes");
inline const Child<> axis("axis");
inline const Child<> background("background");
inline const Child<> baryon("baryon");
inline const Child<> baryons("baryons");
inline const Child<> bindingEnergy("bindingEnergy");
inline const Child<> body("body");
inline const Child<> boundAtomCrossSection("boundAtomCrossSection");
inline const Child<> branching1d("branching1d");
inline const Child<> branching3d("branching3d");
inline const Child<> channel("channel");
inline const Child<> channels("channels");
inline const Child<> charge("charge");
inline const Child<> chemicalElement("chemicalElement");
inline const Child<> chemicalElements("chemicalElements");
inline const Child<> coherentPhotonScattering("coherentPhotonScattering");
inline const Child<> column("column");
inline const Child<> columnData("columnData");
inline const Child<> columnHeaders("columnHeaders");
inline const Child<> configuration("configuration");
inline const Child<> configurations("configurations");
inline const Child<> constant1d("constant1d");
inline const Child<> continuum("continuum");
inline const Child<> conversion("conversion");
inline const Child<> covariance("covariance");
inline const Child<> covarianceMatrix("covarianceMatrix");
inline const Child<> covarianceSection("covarianceSection");
inline const Child<> covarianceSections("covarianceSections");
inline const Child<> crossSection("crossSection");
inline const Child<> crossSectionReconstructed("crossSectionReconstructed");
inline const Child<> crossSectionSum("crossSectionSum");
inline const Child<> crossSectionSums("crossSectionSums");
inline const Child<> data("data");
inline const Child<> date("date");
inline const Child<> dates("dates");
inline const Child<> decay("decay");
inline const Child<> decayData("decayData");
inline const Child<> decayMode("decayMode");
inline const Child<> decayModes("decayModes");
inline const Child<> decayPath("decayPath");
inline const Child<> delayedBetaEnergy("delayedBetaEnergy");
inline const Child<> delayedGammaEnergy("delayedGammaEnergy");
inline const Child<> delayedNeutron("delayedNeutron");
inline const Child<> delayedNeutronKE("delayedNeutronKE");
inline const Child<> delayedNeutrons("delayedNeutrons");
inline const Child<> discrete("discrete");
inline const Child<> discreteGamma("discreteGamma");
inline const Child<> distribution("distribution");
inline const Child<> documentation("documentation");
inline const Child<> doubleDifferentialCrossSection("doubleDifferentialCrossSection");
inline const Child<> e_critical("e_critical");
inline const Child<> e_max("e_max");
inline const Child<> elapsedTime("elapsedTime");
inline const Child<> elapsedTimes("elapsedTimes");
inline const Child<> endfCompatible("endfCompatible");
inline const Child<> energy("energy");
inline const Child<> energyAngular("energyAngular");
inline const Child<> evaluated("evaluated");
inline const Child<> evaporation("evaporation");
inline const Child<> externalFile("externalFile");
inline const Child<> externalFiles("externalFiles");
inline const Child<> f("f");
inline const Child<> fastRegion("fastRegion");
inline const Child<> fissionComponent("fissionComponent");
inline const Child<> fissionComponents("fissionComponents");
inline const Child<> fissionEnergyRelease("fissionEnergyRelease");
inline const Child<> fissionEnergyReleases("fissionEnergyReleases");
inline const Child<> formFactor("formFactor");
inline const Child<> fraction("fraction");
inline const Child<> freeGasApproximation("freeGasApproximation");
inline const Child<> function1ds("function1ds");
inline const Child<> function2ds("function2ds");
inline const Child<> g("g");
inline const Child<> gaugeBoson("gaugeBoson");
inline const Child<> gaugeBosons("gaugeBosons");
inline const Child<> generalEvaporation("generalEvaporation");
inline const Child<> grid("grid");
inline const Child<> gridded2d("gridded2d");
inline const Child<> gridded3d("gridded3d");
inline const Child<> halflife("halflife");
inline const Child<> hardSphereRadius("hardSphereRadius");
inline const Child<> imaginaryAnomalousFactor("imaginaryAnomalousFactor");
inline const Child<> imaginaryInterferenceTerm("imaginaryInterferenceTerm");
inline const Child<> incidentEnergies("incidentEnergies");
inline const Child<> incidentEnergy("incidentEnergy");
inline const Child<> incoherentPhotonScattering("incoherentPhotonScattering");
inline const Child<> incompleteReactions("incompleteReactions");
inline const Child<> institution("institution");
inline const Child<> integer("integer");
inline const Child<> intensity("intensity");
inline const Child<> internalConversionCoefficients("internalConversionCoefficients");
inline const Child<> isotope("isotope");
inline const Child<> isotopes("isotopes");
inline const Child<> isotropic2d("isotropic2d");
inline const Child<> lepton("lepton");
inline const Child<> leptons("leptons");
inline const Child<> levelSpacing("levelSpacing");
inline const Child<> link("link");
inline const Child<> listOfCovariances("listOfCovariances");
inline const Child<> mass("mass");
inline const Child<> metaStable("metaStable");
inline const Child<> mixed("mixed");
inline const Child<> multiplicity("multiplicity");
inline const Child<> multiplicitySum("multiplicitySum");
inline const Child<> multiplicitySums("multiplicitySums");
inline const Child<> neutrinoEnergy("neutrinoEnergy");
inline const Child<> nonNeutrinoEnergy("nonNeutrinoEnergy");
inline const Child<> nuclearAmplitudeExpansion("nuclearAmplitudeExpansion");
inline const Child<> nuclearPlusInterference("nuclearPlusInterference");
inline const Child<> nuclearTerm("nuclearTerm");
inline const Child<> nucleus("nucleus");
inline const Child<> nuclide("nuclide");
inline const Child<> nuclides("nuclides");
inline const Child<> orphanProduct("orphanProduct");
inline const Child<> orphanProducts("orphanProducts");
inline const Child<> outputChannel("outputChannel");
inline const Child<> parameterCovariance("parameterCovariance");
inline const Child<> parameterCovarianceMatrix("parameterCovarianceMatrix");
inline const Child<> parameterCovariances("parameterCovariances");
inline const Child<> parameterLink("parameterLink");
inline const Child<> parameters("parameters");
inline const Child<> parity("parity");
inline const Child<> photonEmissionProbabilities("photonEmissionProbabilities");
inline const Child<> polynomial1d("polynomial1d");
inline const Child<> positronEmissionIntensity("positronEmissionIntensity");
inline const Child<> primaryGamma("primaryGamma");
inline const Child<> probability("probability");
inline const Child<> product("product");
inline const Child<> productYield("productYield");
inline const Child<> productYields("productYields");
inline const Child<> production("production");
inline const Child<> productions("productions");
inline const Child<> products("products");
inline const Child<> projectileEnergyDomain("projectileEnergyDomain");
inline const Child<> promptGammaEnergy("promptGammaEnergy");
inline const Child<> promptNeutronKE("promptNeutronKE");
inline const Child<> promptProductKE("promptProductKE");
inline const Child<> r("r");
inline const Child<> rate("rate");
inline const Child<> reaction("reaction");
inline const Child<> reactions("reactions");
inline const Child<> realAnomalousFactor("realAnomalousFactor");
inline const Child<> realInterferenceTerm("realInterferenceTerm");
inline const Child<> recoil("recoil");
inline const Child<> reference("reference");
inline const Child<> regions1d("regions1d");
inline const Child<> regions2d("regions2d");
inline const Child<> resolved("resolved");
inline const Child<> resolvedRegion("resolvedRegion");
inline const Child<> resonanceParameters("resonanceParameters");
inline const Child<> resonanceReaction("resonanceReaction");
inline const Child<> resonanceReactions("resonanceReactions");
inline const Child<> resonances("resonances");
inline const Child<> resonancesWithBackground("resonancesWithBackground");
inline const Child<> rowData("rowData");
inline const Child<> scatteringAtom("scatteringAtom");
inline const Child<> scatteringAtoms("scatteringAtoms");
inline const Child<> scatteringFactor("scatteringFactor");
inline const Child<> scatteringRadius("scatteringRadius");
inline const Child<> selfScatteringKernel("selfScatteringKernel");
inline const Child<> shell("shell");
inline const Child<> shortRangeSelfScalingVariance("shortRangeSelfScalingVariance");
inline const Child<> simpleMaxwellianFission("simpleMaxwellianFission");
inline const Child<> slice("slice");
inline const Child<> slices("slices");
inline const Child<> spectra("spectra");
inline const Child<> spectrum("spectrum");
inline const Child<> spin("spin");
inline const Child<> spinGroup("spinGroup");
inline const Child<> spinGroups("spinGroups");
inline const Child<> standard("standard");
inline const Child<> string("string");
inline const Child<> styles("styles");
inline const Child<> sum("sum");
inline const Child<> summand("summand");
inline const Child<> summands("summands");
inline const Child<> sums("sums");
inline const Child<> table("table");
inline const Child<> tabulatedWidths("tabulatedWidths");
inline const Child<> temperature("temperature");
inline const Child<> thermalNeutronScatteringLaw("thermalNeutronScatteringLaw");
inline const Child<> thermalNeutronScatteringLaw1d("thermalNeutronScatteringLaw1d");
inline const Child<> thermalNeutronScatteringLaw_coherentElastic("thermalNeutronScatteringLaw_coherentElastic");
inline const Child<> thermalNeutronScatteringLaw_incoherentElastic("thermalNeutronScatteringLaw_incoherentElastic");
inline const Child<> thermalNeutronScatteringLaw_incoherentInelastic("thermalNeutronScatteringLaw_incoherentInelastic");
inline const Child<> theta("theta");
inline const Child<> time("time");
inline const Child<> title("title");
inline const Child<> totalEnergy("totalEnergy");
inline const Child<> uncertainty("uncertainty");
inline const Child<> uncorrelated("uncorrelated");
inline const Child<> unorthodox("unorthodox");
inline const Child<> unorthodoxes("unorthodoxes");
inline const Child<> unresolved("unresolved");
inline const Child<> unresolvedRegion("unresolvedRegion");
inline const Child<> unspecified("unspecified");
inline const Child<> values("values");
inline const Child<> weighted("weighted");
inline const Child<> weightedFunctionals("weightedFunctionals");
inline const Child<> width("width");
inline const Child<> widths("widths");
inline const Child<> yields("yields");

} // namespace child
using namespace child;
} // namespace general


// -----------------------------------------------------------------------------
// reduced::child::
// -----------------------------------------------------------------------------

namespace reduced {
namespace child {

inline const Child<> Double("double");
inline const Child<> crossSection("crossSection");
inline const Child<> distribution("distribution");
inline const Child<> function1ds("function1ds");
inline const Child<> nuclides("nuclides");
inline const Child<> outputChannel("outputChannel");
inline const Child<> polynomial1d("polynomial1d");
inline const Child<> product("product");
inline const Child<> products("products");

} // namespace child
using namespace child;
} // namespace reduced


// -----------------------------------------------------------------------------
// top::child::
// -----------------------------------------------------------------------------

namespace top {
namespace child {

inline const Child<> PoPs("PoPs");
inline const Child<> covarianceSuite("covarianceSuite");
inline const Child<> fissionFragmentData("fissionFragmentData");
inline const Child<> reactionSuite("reactionSuite");

} // namespace child
using namespace child;
} // namespace top


// -----------------------------------------------------------------------------
// For convenience: using directives
// -----------------------------------------------------------------------------

namespace key {
   using namespace meta;
   using namespace alt::child;
   using namespace g2d::child;
   using namespace g3d::child;
   using namespace general::child;
   using namespace reduced::child;
   using namespace top::child;
} // namespace key

using namespace key;
using namespace alt;
using namespace g2d;
using namespace g3d;
using namespace general;
using namespace reduced;
using namespace top;


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

} // namespace v2_0
} // namespace alpha

#endif
