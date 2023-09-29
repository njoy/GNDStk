
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/top/CovarianceSuite.hpp"
#include "CovarianceSuite.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = CovarianceSuiteClass;
using CPP = multigroup::CovarianceSuite;

static const std::string CLASSNAME = "CovarianceSuite";

namespace extract {
   static auto projectile = [](auto &obj) { return &obj.projectile; };
   static auto target = [](auto &obj) { return &obj.target; };
   static auto evaluation = [](auto &obj) { return &obj.evaluation; };
   static auto interaction = [](auto &obj) { return &obj.interaction; };
   static auto format = [](auto &obj) { return &obj.format; };
   static auto externalFiles = [](auto &obj) { return &obj.externalFiles; };
   static auto styles = [](auto &obj) { return &obj.styles; };
   static auto covarianceSections = [](auto &obj) { return &obj.covarianceSections; };
   static auto parameterCovariances = [](auto &obj) { return &obj.parameterCovariances; };
}

using CPPExternalFiles = general::ExternalFiles;
using CPPStyles = general::Styles;
using CPPCovarianceSections = general::CovarianceSections;
using CPPParameterCovariances = general::ParameterCovariances;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCovarianceSuite
CovarianceSuiteDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2CovarianceSuite
CovarianceSuiteDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCovarianceSuite
CovarianceSuiteCreateConst(
   const char *const projectile,
   const char *const target,
   const char *const evaluation,
   const char *const interaction,
   const char *const format,
   ConstHandle2ConstExternalFiles externalFiles,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstCovarianceSections covarianceSections,
   ConstHandle2ConstParameterCovariances parameterCovariances
) {
   ConstHandle2CovarianceSuite handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      projectile,
      target,
      evaluation,
      interaction,
      format,
      detail::tocpp<CPPExternalFiles>(externalFiles),
      detail::tocpp<CPPStyles>(styles),
      detail::tocpp<CPPCovarianceSections>(covarianceSections),
      detail::tocpp<CPPParameterCovariances>(parameterCovariances)
   );
   return handle;
}

// Create, general, non-const
Handle2CovarianceSuite
CovarianceSuiteCreate(
   const char *const projectile,
   const char *const target,
   const char *const evaluation,
   const char *const interaction,
   const char *const format,
   ConstHandle2ConstExternalFiles externalFiles,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstCovarianceSections covarianceSections,
   ConstHandle2ConstParameterCovariances parameterCovariances
) {
   ConstHandle2CovarianceSuite handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      projectile,
      target,
      evaluation,
      interaction,
      format,
      detail::tocpp<CPPExternalFiles>(externalFiles),
      detail::tocpp<CPPStyles>(styles),
      detail::tocpp<CPPCovarianceSections>(covarianceSections),
      detail::tocpp<CPPParameterCovariances>(parameterCovariances)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CovarianceSuiteAssign(ConstHandle2CovarianceSuite self, ConstHandle2ConstCovarianceSuite from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CovarianceSuiteDelete(ConstHandle2ConstCovarianceSuite self)
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
CovarianceSuiteRead(ConstHandle2CovarianceSuite self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CovarianceSuiteWrite(ConstHandle2ConstCovarianceSuite self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CovarianceSuitePrint(ConstHandle2ConstCovarianceSuite self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CovarianceSuitePrintXML(ConstHandle2ConstCovarianceSuite self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CovarianceSuitePrintJSON(ConstHandle2ConstCovarianceSuite self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: projectile
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteProjectileHas(ConstHandle2ConstCovarianceSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileHas", self, extract::projectile);
}

// Get
// Returns by value
const char *
CovarianceSuiteProjectileGet(ConstHandle2ConstCovarianceSuite self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileGet", self, extract::projectile);
}

// Set
void
CovarianceSuiteProjectileSet(ConstHandle2CovarianceSuite self, const char *const projectile)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileSet", self, extract::projectile, projectile);
}


// -----------------------------------------------------------------------------
// Metadatum: target
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteTargetHas(ConstHandle2ConstCovarianceSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TargetHas", self, extract::target);
}

// Get
// Returns by value
const char *
CovarianceSuiteTargetGet(ConstHandle2ConstCovarianceSuite self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"TargetGet", self, extract::target);
}

// Set
void
CovarianceSuiteTargetSet(ConstHandle2CovarianceSuite self, const char *const target)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"TargetSet", self, extract::target, target);
}


// -----------------------------------------------------------------------------
// Metadatum: evaluation
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteEvaluationHas(ConstHandle2ConstCovarianceSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationHas", self, extract::evaluation);
}

// Get
// Returns by value
const char *
CovarianceSuiteEvaluationGet(ConstHandle2ConstCovarianceSuite self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationGet", self, extract::evaluation);
}

// Set
void
CovarianceSuiteEvaluationSet(ConstHandle2CovarianceSuite self, const char *const evaluation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationSet", self, extract::evaluation, evaluation);
}


// -----------------------------------------------------------------------------
// Metadatum: interaction
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteInteractionHas(ConstHandle2ConstCovarianceSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionHas", self, extract::interaction);
}

// Get
// Returns by value
const char *
CovarianceSuiteInteractionGet(ConstHandle2ConstCovarianceSuite self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionGet", self, extract::interaction);
}

// Set
void
CovarianceSuiteInteractionSet(ConstHandle2CovarianceSuite self, const char *const interaction)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionSet", self, extract::interaction, interaction);
}


// -----------------------------------------------------------------------------
// Metadatum: format
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteFormatHas(ConstHandle2ConstCovarianceSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FormatHas", self, extract::format);
}

// Get
// Returns by value
const char *
CovarianceSuiteFormatGet(ConstHandle2ConstCovarianceSuite self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"FormatGet", self, extract::format);
}

// Set
void
CovarianceSuiteFormatSet(ConstHandle2CovarianceSuite self, const char *const format)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"FormatSet", self, extract::format, format);
}


// -----------------------------------------------------------------------------
// Child: externalFiles
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteExternalFilesHas(ConstHandle2ConstCovarianceSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ExternalFilesHas", self, extract::externalFiles);
}

// Get, const
Handle2ConstExternalFiles
CovarianceSuiteExternalFilesGetConst(ConstHandle2ConstCovarianceSuite self)
{
   return detail::getField<CPP,Handle2ConstExternalFiles>
      (CLASSNAME, CLASSNAME+"ExternalFilesGetConst", self, extract::externalFiles);
}

// Get, non-const
Handle2ExternalFiles
CovarianceSuiteExternalFilesGet(ConstHandle2CovarianceSuite self)
{
   return detail::getField<CPP,Handle2ExternalFiles>
      (CLASSNAME, CLASSNAME+"ExternalFilesGet", self, extract::externalFiles);
}

// Set
void
CovarianceSuiteExternalFilesSet(ConstHandle2CovarianceSuite self, ConstHandle2ConstExternalFiles externalFiles)
{
   detail::setField<CPP,CPPExternalFiles>
      (CLASSNAME, CLASSNAME+"ExternalFilesSet", self, extract::externalFiles, externalFiles);
}


// -----------------------------------------------------------------------------
// Child: styles
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteStylesHas(ConstHandle2ConstCovarianceSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StylesHas", self, extract::styles);
}

// Get, const
Handle2ConstStyles
CovarianceSuiteStylesGetConst(ConstHandle2ConstCovarianceSuite self)
{
   return detail::getField<CPP,Handle2ConstStyles>
      (CLASSNAME, CLASSNAME+"StylesGetConst", self, extract::styles);
}

// Get, non-const
Handle2Styles
CovarianceSuiteStylesGet(ConstHandle2CovarianceSuite self)
{
   return detail::getField<CPP,Handle2Styles>
      (CLASSNAME, CLASSNAME+"StylesGet", self, extract::styles);
}

// Set
void
CovarianceSuiteStylesSet(ConstHandle2CovarianceSuite self, ConstHandle2ConstStyles styles)
{
   detail::setField<CPP,CPPStyles>
      (CLASSNAME, CLASSNAME+"StylesSet", self, extract::styles, styles);
}


// -----------------------------------------------------------------------------
// Child: covarianceSections
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteCovarianceSectionsHas(ConstHandle2ConstCovarianceSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceSectionsHas", self, extract::covarianceSections);
}

// Get, const
Handle2ConstCovarianceSections
CovarianceSuiteCovarianceSectionsGetConst(ConstHandle2ConstCovarianceSuite self)
{
   return detail::getField<CPP,Handle2ConstCovarianceSections>
      (CLASSNAME, CLASSNAME+"CovarianceSectionsGetConst", self, extract::covarianceSections);
}

// Get, non-const
Handle2CovarianceSections
CovarianceSuiteCovarianceSectionsGet(ConstHandle2CovarianceSuite self)
{
   return detail::getField<CPP,Handle2CovarianceSections>
      (CLASSNAME, CLASSNAME+"CovarianceSectionsGet", self, extract::covarianceSections);
}

// Set
void
CovarianceSuiteCovarianceSectionsSet(ConstHandle2CovarianceSuite self, ConstHandle2ConstCovarianceSections covarianceSections)
{
   detail::setField<CPP,CPPCovarianceSections>
      (CLASSNAME, CLASSNAME+"CovarianceSectionsSet", self, extract::covarianceSections, covarianceSections);
}


// -----------------------------------------------------------------------------
// Child: parameterCovariances
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteParameterCovariancesHas(ConstHandle2ConstCovarianceSuite self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ParameterCovariancesHas", self, extract::parameterCovariances);
}

// Get, const
Handle2ConstParameterCovariances
CovarianceSuiteParameterCovariancesGetConst(ConstHandle2ConstCovarianceSuite self)
{
   return detail::getField<CPP,Handle2ConstParameterCovariances>
      (CLASSNAME, CLASSNAME+"ParameterCovariancesGetConst", self, extract::parameterCovariances);
}

// Get, non-const
Handle2ParameterCovariances
CovarianceSuiteParameterCovariancesGet(ConstHandle2CovarianceSuite self)
{
   return detail::getField<CPP,Handle2ParameterCovariances>
      (CLASSNAME, CLASSNAME+"ParameterCovariancesGet", self, extract::parameterCovariances);
}

// Set
void
CovarianceSuiteParameterCovariancesSet(ConstHandle2CovarianceSuite self, ConstHandle2ConstParameterCovariances parameterCovariances)
{
   detail::setField<CPP,CPPParameterCovariances>
      (CLASSNAME, CLASSNAME+"ParameterCovariancesSet", self, extract::parameterCovariances, parameterCovariances);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/top/CovarianceSuite/src/custom.cpp"
