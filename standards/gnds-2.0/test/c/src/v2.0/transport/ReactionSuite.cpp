
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/ReactionSuite.hpp"
#include "ReactionSuite.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ReactionSuiteClass;
using CPP = multigroup::ReactionSuite;

static const std::string CLASSNAME = "ReactionSuite";

namespace extract {
   static auto evaluation = [](auto &obj) { return &obj.evaluation; };
   static auto format = [](auto &obj) { return &obj.format; };
   static auto projectile = [](auto &obj) { return &obj.projectile; };
   static auto projectileFrame = [](auto &obj) { return &obj.projectileFrame; };
   static auto target = [](auto &obj) { return &obj.target; };
   static auto interaction = [](auto &obj) { return &obj.interaction; };
   static auto externalFiles = [](auto &obj) { return &obj.externalFiles; };
   static auto styles = [](auto &obj) { return &obj.styles; };
   static auto PoPs_database = [](auto &obj) { return &obj.PoPs_database; };
   static auto resonances = [](auto &obj) { return &obj.resonances; };
   static auto reactions = [](auto &obj) { return &obj.reactions; };
   static auto orphanProducts = [](auto &obj) { return &obj.orphanProducts; };
   static auto sums = [](auto &obj) { return &obj.sums; };
   static auto fissionComponents = [](auto &obj) { return &obj.fissionComponents; };
   static auto productions = [](auto &obj) { return &obj.productions; };
   static auto incompleteReactions = [](auto &obj) { return &obj.incompleteReactions; };
   static auto applicationData = [](auto &obj) { return &obj.applicationData; };
}

using CPPExternalFiles = common::ExternalFiles;
using CPPStyles = styles::Styles;
using CPPPoPs_database = pops::PoPs_database;
using CPPResonances = resonances::Resonances;
using CPPReactions = transport::Reactions;
using CPPOrphanProducts = transport::OrphanProducts;
using CPPSums = transport::Sums;
using CPPFissionComponents = fissionTransport::FissionComponents;
using CPPProductions = transport::Productions;
using CPPIncompleteReactions = transport::IncompleteReactions;
using CPPApplicationData = appData::ApplicationData;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstReactionSuite
ReactionSuiteDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ReactionSuite
ReactionSuiteDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstReactionSuite
ReactionSuiteCreateConst(
   const XMLName evaluation,
   const XMLName format,
   const XMLName projectile,
   const enums::Frame projectileFrame,
   const XMLName target,
   const enums::Interaction interaction,
   ConstHandle2ConstExternalFiles externalFiles,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstPoPs_database PoPs_database,
   ConstHandle2ConstResonances resonances,
   ConstHandle2ConstReactions reactions,
   ConstHandle2ConstOrphanProducts orphanProducts,
   ConstHandle2ConstSums sums,
   ConstHandle2ConstFissionComponents fissionComponents,
   ConstHandle2ConstProductions productions,
   ConstHandle2ConstIncompleteReactions incompleteReactions,
   ConstHandle2ConstApplicationData applicationData
) {
   ConstHandle2ReactionSuite handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      evaluation,
      format,
      projectile,
      projectileFrame,
      target,
      interaction,
      detail::tocpp<CPPExternalFiles>(externalFiles),
      detail::tocpp<CPPStyles>(styles),
      detail::tocpp<CPPPoPs_database>(PoPs_database),
      detail::tocpp<CPPResonances>(resonances),
      detail::tocpp<CPPReactions>(reactions),
      detail::tocpp<CPPOrphanProducts>(orphanProducts),
      detail::tocpp<CPPSums>(sums),
      detail::tocpp<CPPFissionComponents>(fissionComponents),
      detail::tocpp<CPPProductions>(productions),
      detail::tocpp<CPPIncompleteReactions>(incompleteReactions),
      detail::tocpp<CPPApplicationData>(applicationData)
   );
   return handle;
}

// Create, general
Handle2ReactionSuite
ReactionSuiteCreate(
   const XMLName evaluation,
   const XMLName format,
   const XMLName projectile,
   const enums::Frame projectileFrame,
   const XMLName target,
   const enums::Interaction interaction,
   ConstHandle2ConstExternalFiles externalFiles,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstPoPs_database PoPs_database,
   ConstHandle2ConstResonances resonances,
   ConstHandle2ConstReactions reactions,
   ConstHandle2ConstOrphanProducts orphanProducts,
   ConstHandle2ConstSums sums,
   ConstHandle2ConstFissionComponents fissionComponents,
   ConstHandle2ConstProductions productions,
   ConstHandle2ConstIncompleteReactions incompleteReactions,
   ConstHandle2ConstApplicationData applicationData
) {
   ConstHandle2ReactionSuite handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      evaluation,
      format,
      projectile,
      projectileFrame,
      target,
      interaction,
      detail::tocpp<CPPExternalFiles>(externalFiles),
      detail::tocpp<CPPStyles>(styles),
      detail::tocpp<CPPPoPs_database>(PoPs_database),
      detail::tocpp<CPPResonances>(resonances),
      detail::tocpp<CPPReactions>(reactions),
      detail::tocpp<CPPOrphanProducts>(orphanProducts),
      detail::tocpp<CPPSums>(sums),
      detail::tocpp<CPPFissionComponents>(fissionComponents),
      detail::tocpp<CPPProductions>(productions),
      detail::tocpp<CPPIncompleteReactions>(incompleteReactions),
      detail::tocpp<CPPApplicationData>(applicationData)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ReactionSuiteAssign(ConstHandle2ReactionSuite self, ConstHandle2ConstReactionSuite from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ReactionSuiteDelete(ConstHandle2ConstReactionSuite self)
{
   detail::deleteHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Delete", self);
}


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// Read from file
// File can be XML, JSON, or HDF5.
// We'll examine the file's contents to determine its type automatically.
int
ReactionSuiteRead(ConstHandle2ReactionSuite self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ReactionSuiteWrite(ConstHandle2ConstReactionSuite self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ReactionSuitePrint(ConstHandle2ConstReactionSuite self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ReactionSuitePrintXML(ConstHandle2ConstReactionSuite self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ReactionSuitePrintJSON(ConstHandle2ConstReactionSuite self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: evaluation
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteEvaluationHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationHas", self, extract::evaluation);
}

// Get
// Returns by value
XMLName
ReactionSuiteEvaluationGet(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationGet", self, extract::evaluation);
}

// Set
void
ReactionSuiteEvaluationSet(ConstHandle2ReactionSuite self, const XMLName evaluation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationSet", self, extract::evaluation, evaluation);
}


// -----------------------------------------------------------------------------
// Metadatum: format
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteFormatHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FormatHas", self, extract::format);
}

// Get
// Returns by value
XMLName
ReactionSuiteFormatGet(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"FormatGet", self, extract::format);
}

// Set
void
ReactionSuiteFormatSet(ConstHandle2ReactionSuite self, const XMLName format)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"FormatSet", self, extract::format, format);
}


// -----------------------------------------------------------------------------
// Metadatum: projectile
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteProjectileHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileHas", self, extract::projectile);
}

// Get
// Returns by value
XMLName
ReactionSuiteProjectileGet(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileGet", self, extract::projectile);
}

// Set
void
ReactionSuiteProjectileSet(ConstHandle2ReactionSuite self, const XMLName projectile)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileSet", self, extract::projectile, projectile);
}


// -----------------------------------------------------------------------------
// Metadatum: projectileFrame
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteProjectileFrameHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileFrameHas", self, extract::projectileFrame);
}

// Get
// Returns by value
enums::Frame
ReactionSuiteProjectileFrameGet(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileFrameGet", self, extract::projectileFrame);
}

// Set
void
ReactionSuiteProjectileFrameSet(ConstHandle2ReactionSuite self, const enums::Frame projectileFrame)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileFrameSet", self, extract::projectileFrame, projectileFrame);
}


// -----------------------------------------------------------------------------
// Metadatum: target
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteTargetHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TargetHas", self, extract::target);
}

// Get
// Returns by value
XMLName
ReactionSuiteTargetGet(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"TargetGet", self, extract::target);
}

// Set
void
ReactionSuiteTargetSet(ConstHandle2ReactionSuite self, const XMLName target)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"TargetSet", self, extract::target, target);
}


// -----------------------------------------------------------------------------
// Metadatum: interaction
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteInteractionHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionHas", self, extract::interaction);
}

// Get
// Returns by value
enums::Interaction
ReactionSuiteInteractionGet(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionGet", self, extract::interaction);
}

// Set
void
ReactionSuiteInteractionSet(ConstHandle2ReactionSuite self, const enums::Interaction interaction)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionSet", self, extract::interaction, interaction);
}


// -----------------------------------------------------------------------------
// Child: externalFiles
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteExternalFilesHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ExternalFilesHas", self, extract::externalFiles);
}

// Get, const
Handle2ConstExternalFiles
ReactionSuiteExternalFilesGetConst(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP,Handle2ConstExternalFiles>
      (CLASSNAME, CLASSNAME+"ExternalFilesGetConst", self, extract::externalFiles);
}

// Get, non-const
Handle2ExternalFiles
ReactionSuiteExternalFilesGet(ConstHandle2ReactionSuite self)
{
   return detail::getField<CPP,Handle2ExternalFiles>
      (CLASSNAME, CLASSNAME+"ExternalFilesGet", self, extract::externalFiles);
}

// Set
void
ReactionSuiteExternalFilesSet(ConstHandle2ReactionSuite self, ConstHandle2ConstExternalFiles externalFiles)
{
   detail::setField<CPP,CPPExternalFiles>
      (CLASSNAME, CLASSNAME+"ExternalFilesSet", self, extract::externalFiles, externalFiles);
}


// -----------------------------------------------------------------------------
// Child: styles
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteStylesHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StylesHas", self, extract::styles);
}

// Get, const
Handle2ConstStyles
ReactionSuiteStylesGetConst(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP,Handle2ConstStyles>
      (CLASSNAME, CLASSNAME+"StylesGetConst", self, extract::styles);
}

// Get, non-const
Handle2Styles
ReactionSuiteStylesGet(ConstHandle2ReactionSuite self)
{
   return detail::getField<CPP,Handle2Styles>
      (CLASSNAME, CLASSNAME+"StylesGet", self, extract::styles);
}

// Set
void
ReactionSuiteStylesSet(ConstHandle2ReactionSuite self, ConstHandle2ConstStyles styles)
{
   detail::setField<CPP,CPPStyles>
      (CLASSNAME, CLASSNAME+"StylesSet", self, extract::styles, styles);
}


// -----------------------------------------------------------------------------
// Child: PoPs_database
// -----------------------------------------------------------------------------

// Has
int
ReactionSuitePoPs_databaseHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PoPs_databaseHas", self, extract::PoPs_database);
}

// Get, const
Handle2ConstPoPs_database
ReactionSuitePoPs_databaseGetConst(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP,Handle2ConstPoPs_database>
      (CLASSNAME, CLASSNAME+"PoPs_databaseGetConst", self, extract::PoPs_database);
}

// Get, non-const
Handle2PoPs_database
ReactionSuitePoPs_databaseGet(ConstHandle2ReactionSuite self)
{
   return detail::getField<CPP,Handle2PoPs_database>
      (CLASSNAME, CLASSNAME+"PoPs_databaseGet", self, extract::PoPs_database);
}

// Set
void
ReactionSuitePoPs_databaseSet(ConstHandle2ReactionSuite self, ConstHandle2ConstPoPs_database PoPs_database)
{
   detail::setField<CPP,CPPPoPs_database>
      (CLASSNAME, CLASSNAME+"PoPs_databaseSet", self, extract::PoPs_database, PoPs_database);
}


// -----------------------------------------------------------------------------
// Child: resonances
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteResonancesHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResonancesHas", self, extract::resonances);
}

// Get, const
Handle2ConstResonances
ReactionSuiteResonancesGetConst(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP,Handle2ConstResonances>
      (CLASSNAME, CLASSNAME+"ResonancesGetConst", self, extract::resonances);
}

// Get, non-const
Handle2Resonances
ReactionSuiteResonancesGet(ConstHandle2ReactionSuite self)
{
   return detail::getField<CPP,Handle2Resonances>
      (CLASSNAME, CLASSNAME+"ResonancesGet", self, extract::resonances);
}

// Set
void
ReactionSuiteResonancesSet(ConstHandle2ReactionSuite self, ConstHandle2ConstResonances resonances)
{
   detail::setField<CPP,CPPResonances>
      (CLASSNAME, CLASSNAME+"ResonancesSet", self, extract::resonances, resonances);
}


// -----------------------------------------------------------------------------
// Child: reactions
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteReactionsHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ReactionsHas", self, extract::reactions);
}

// Get, const
Handle2ConstReactions
ReactionSuiteReactionsGetConst(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP,Handle2ConstReactions>
      (CLASSNAME, CLASSNAME+"ReactionsGetConst", self, extract::reactions);
}

// Get, non-const
Handle2Reactions
ReactionSuiteReactionsGet(ConstHandle2ReactionSuite self)
{
   return detail::getField<CPP,Handle2Reactions>
      (CLASSNAME, CLASSNAME+"ReactionsGet", self, extract::reactions);
}

// Set
void
ReactionSuiteReactionsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstReactions reactions)
{
   detail::setField<CPP,CPPReactions>
      (CLASSNAME, CLASSNAME+"ReactionsSet", self, extract::reactions, reactions);
}


// -----------------------------------------------------------------------------
// Child: orphanProducts
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteOrphanProductsHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OrphanProductsHas", self, extract::orphanProducts);
}

// Get, const
Handle2ConstOrphanProducts
ReactionSuiteOrphanProductsGetConst(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP,Handle2ConstOrphanProducts>
      (CLASSNAME, CLASSNAME+"OrphanProductsGetConst", self, extract::orphanProducts);
}

// Get, non-const
Handle2OrphanProducts
ReactionSuiteOrphanProductsGet(ConstHandle2ReactionSuite self)
{
   return detail::getField<CPP,Handle2OrphanProducts>
      (CLASSNAME, CLASSNAME+"OrphanProductsGet", self, extract::orphanProducts);
}

// Set
void
ReactionSuiteOrphanProductsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstOrphanProducts orphanProducts)
{
   detail::setField<CPP,CPPOrphanProducts>
      (CLASSNAME, CLASSNAME+"OrphanProductsSet", self, extract::orphanProducts, orphanProducts);
}


// -----------------------------------------------------------------------------
// Child: sums
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteSumsHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SumsHas", self, extract::sums);
}

// Get, const
Handle2ConstSums
ReactionSuiteSumsGetConst(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP,Handle2ConstSums>
      (CLASSNAME, CLASSNAME+"SumsGetConst", self, extract::sums);
}

// Get, non-const
Handle2Sums
ReactionSuiteSumsGet(ConstHandle2ReactionSuite self)
{
   return detail::getField<CPP,Handle2Sums>
      (CLASSNAME, CLASSNAME+"SumsGet", self, extract::sums);
}

// Set
void
ReactionSuiteSumsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstSums sums)
{
   detail::setField<CPP,CPPSums>
      (CLASSNAME, CLASSNAME+"SumsSet", self, extract::sums, sums);
}


// -----------------------------------------------------------------------------
// Child: fissionComponents
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteFissionComponentsHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FissionComponentsHas", self, extract::fissionComponents);
}

// Get, const
Handle2ConstFissionComponents
ReactionSuiteFissionComponentsGetConst(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP,Handle2ConstFissionComponents>
      (CLASSNAME, CLASSNAME+"FissionComponentsGetConst", self, extract::fissionComponents);
}

// Get, non-const
Handle2FissionComponents
ReactionSuiteFissionComponentsGet(ConstHandle2ReactionSuite self)
{
   return detail::getField<CPP,Handle2FissionComponents>
      (CLASSNAME, CLASSNAME+"FissionComponentsGet", self, extract::fissionComponents);
}

// Set
void
ReactionSuiteFissionComponentsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstFissionComponents fissionComponents)
{
   detail::setField<CPP,CPPFissionComponents>
      (CLASSNAME, CLASSNAME+"FissionComponentsSet", self, extract::fissionComponents, fissionComponents);
}


// -----------------------------------------------------------------------------
// Child: productions
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteProductionsHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductionsHas", self, extract::productions);
}

// Get, const
Handle2ConstProductions
ReactionSuiteProductionsGetConst(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP,Handle2ConstProductions>
      (CLASSNAME, CLASSNAME+"ProductionsGetConst", self, extract::productions);
}

// Get, non-const
Handle2Productions
ReactionSuiteProductionsGet(ConstHandle2ReactionSuite self)
{
   return detail::getField<CPP,Handle2Productions>
      (CLASSNAME, CLASSNAME+"ProductionsGet", self, extract::productions);
}

// Set
void
ReactionSuiteProductionsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstProductions productions)
{
   detail::setField<CPP,CPPProductions>
      (CLASSNAME, CLASSNAME+"ProductionsSet", self, extract::productions, productions);
}


// -----------------------------------------------------------------------------
// Child: incompleteReactions
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteIncompleteReactionsHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IncompleteReactionsHas", self, extract::incompleteReactions);
}

// Get, const
Handle2ConstIncompleteReactions
ReactionSuiteIncompleteReactionsGetConst(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP,Handle2ConstIncompleteReactions>
      (CLASSNAME, CLASSNAME+"IncompleteReactionsGetConst", self, extract::incompleteReactions);
}

// Get, non-const
Handle2IncompleteReactions
ReactionSuiteIncompleteReactionsGet(ConstHandle2ReactionSuite self)
{
   return detail::getField<CPP,Handle2IncompleteReactions>
      (CLASSNAME, CLASSNAME+"IncompleteReactionsGet", self, extract::incompleteReactions);
}

// Set
void
ReactionSuiteIncompleteReactionsSet(ConstHandle2ReactionSuite self, ConstHandle2ConstIncompleteReactions incompleteReactions)
{
   detail::setField<CPP,CPPIncompleteReactions>
      (CLASSNAME, CLASSNAME+"IncompleteReactionsSet", self, extract::incompleteReactions, incompleteReactions);
}


// -----------------------------------------------------------------------------
// Child: applicationData
// -----------------------------------------------------------------------------

// Has
int
ReactionSuiteApplicationDataHas(ConstHandle2ConstReactionSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ApplicationDataHas", self, extract::applicationData);
}

// Get, const
Handle2ConstApplicationData
ReactionSuiteApplicationDataGetConst(ConstHandle2ConstReactionSuite self)
{
   return detail::getField<CPP,Handle2ConstApplicationData>
      (CLASSNAME, CLASSNAME+"ApplicationDataGetConst", self, extract::applicationData);
}

// Get, non-const
Handle2ApplicationData
ReactionSuiteApplicationDataGet(ConstHandle2ReactionSuite self)
{
   return detail::getField<CPP,Handle2ApplicationData>
      (CLASSNAME, CLASSNAME+"ApplicationDataGet", self, extract::applicationData);
}

// Set
void
ReactionSuiteApplicationDataSet(ConstHandle2ReactionSuite self, ConstHandle2ConstApplicationData applicationData)
{
   detail::setField<CPP,CPPApplicationData>
      (CLASSNAME, CLASSNAME+"ApplicationDataSet", self, extract::applicationData, applicationData);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/ReactionSuite/src/custom.cpp"
