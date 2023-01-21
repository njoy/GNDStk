
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/covariance/CovarianceSuite.hpp"
#include "CovarianceSuite.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = CovarianceSuiteClass;
using CPP = multigroup::CovarianceSuite;

static const std::string CLASSNAME = "CovarianceSuite";

namespace extract {
   static auto evaluation = [](auto &obj) { return &obj.evaluation; };
   static auto projectile = [](auto &obj) { return &obj.projectile; };
   static auto target = [](auto &obj) { return &obj.target; };
   static auto interaction = [](auto &obj) { return &obj.interaction; };
   static auto format = [](auto &obj) { return &obj.format; };
   static auto externalFiles = [](auto &obj) { return &obj.externalFiles; };
   static auto styles = [](auto &obj) { return &obj.styles; };
   static auto covarianceSections = [](auto &obj) { return &obj.covarianceSections; };
   static auto parameterCovariances = [](auto &obj) { return &obj.parameterCovariances; };
}

using CPPExternalFiles = common::ExternalFiles;
using CPPStyles = styles::Styles;
using CPPCovarianceSections = covariance::CovarianceSections;
using CPPParameterCovariances = covariance::ParameterCovariances;


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

// Create, default
Handle2CovarianceSuite
CovarianceSuiteDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCovarianceSuite
CovarianceSuiteCreateConst(
   const XMLName evaluation,
   const XMLName projectile,
   const XMLName target,
   const enums::Interaction interaction,
   const Float64 format,
   ConstHandle2ConstExternalFiles externalFiles,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstCovarianceSections covarianceSections,
   ConstHandle2ConstParameterCovariances parameterCovariances
) {
   ConstHandle2CovarianceSuite handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      evaluation,
      projectile,
      target,
      interaction,
      format,
      detail::tocpp<CPPExternalFiles>(externalFiles),
      detail::tocpp<CPPStyles>(styles),
      detail::tocpp<CPPCovarianceSections>(covarianceSections),
      detail::tocpp<CPPParameterCovariances>(parameterCovariances)
   );
   return handle;
}

// Create, general
Handle2CovarianceSuite
CovarianceSuiteCreate(
   const XMLName evaluation,
   const XMLName projectile,
   const XMLName target,
   const enums::Interaction interaction,
   const Float64 format,
   ConstHandle2ConstExternalFiles externalFiles,
   ConstHandle2ConstStyles styles,
   ConstHandle2ConstCovarianceSections covarianceSections,
   ConstHandle2ConstParameterCovariances parameterCovariances
) {
   ConstHandle2CovarianceSuite handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      evaluation,
      projectile,
      target,
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
CovarianceSuiteAssign(ConstHandle2CovarianceSuite This, ConstHandle2ConstCovarianceSuite from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CovarianceSuiteDelete(ConstHandle2ConstCovarianceSuite This)
{
   detail::deleteHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Delete", This);
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
CovarianceSuiteRead(ConstHandle2CovarianceSuite This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CovarianceSuiteWrite(ConstHandle2ConstCovarianceSuite This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
CovarianceSuitePrint(ConstHandle2ConstCovarianceSuite This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
CovarianceSuitePrintXML(ConstHandle2ConstCovarianceSuite This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
CovarianceSuitePrintJSON(ConstHandle2ConstCovarianceSuite This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: evaluation
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteEvaluationHas(ConstHandle2ConstCovarianceSuite This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationHas", This, extract::evaluation);
}

// Get
// Returns by value
XMLName
CovarianceSuiteEvaluationGet(ConstHandle2ConstCovarianceSuite This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationGet", This, extract::evaluation);
}

// Set
void
CovarianceSuiteEvaluationSet(ConstHandle2CovarianceSuite This, const XMLName evaluation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationSet", This, extract::evaluation, evaluation);
}


// -----------------------------------------------------------------------------
// Metadatum: projectile
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteProjectileHas(ConstHandle2ConstCovarianceSuite This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileHas", This, extract::projectile);
}

// Get
// Returns by value
XMLName
CovarianceSuiteProjectileGet(ConstHandle2ConstCovarianceSuite This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileGet", This, extract::projectile);
}

// Set
void
CovarianceSuiteProjectileSet(ConstHandle2CovarianceSuite This, const XMLName projectile)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileSet", This, extract::projectile, projectile);
}


// -----------------------------------------------------------------------------
// Metadatum: target
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteTargetHas(ConstHandle2ConstCovarianceSuite This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TargetHas", This, extract::target);
}

// Get
// Returns by value
XMLName
CovarianceSuiteTargetGet(ConstHandle2ConstCovarianceSuite This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"TargetGet", This, extract::target);
}

// Set
void
CovarianceSuiteTargetSet(ConstHandle2CovarianceSuite This, const XMLName target)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"TargetSet", This, extract::target, target);
}


// -----------------------------------------------------------------------------
// Metadatum: interaction
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteInteractionHas(ConstHandle2ConstCovarianceSuite This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionHas", This, extract::interaction);
}

// Get
// Returns by value
enums::Interaction
CovarianceSuiteInteractionGet(ConstHandle2ConstCovarianceSuite This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionGet", This, extract::interaction);
}

// Set
void
CovarianceSuiteInteractionSet(ConstHandle2CovarianceSuite This, const enums::Interaction interaction)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionSet", This, extract::interaction, interaction);
}


// -----------------------------------------------------------------------------
// Metadatum: format
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteFormatHas(ConstHandle2ConstCovarianceSuite This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FormatHas", This, extract::format);
}

// Get
// Returns by value
Float64
CovarianceSuiteFormatGet(ConstHandle2ConstCovarianceSuite This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"FormatGet", This, extract::format);
}

// Set
void
CovarianceSuiteFormatSet(ConstHandle2CovarianceSuite This, const Float64 format)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"FormatSet", This, extract::format, format);
}


// -----------------------------------------------------------------------------
// Child: externalFiles
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteExternalFilesHas(ConstHandle2ConstCovarianceSuite This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ExternalFilesHas", This, extract::externalFiles);
}

// Get, const
Handle2ConstExternalFiles
CovarianceSuiteExternalFilesGetConst(ConstHandle2ConstCovarianceSuite This)
{
   return detail::getField<CPP,Handle2ConstExternalFiles>
      (CLASSNAME, CLASSNAME+"ExternalFilesGetConst", This, extract::externalFiles);
}

// Get, non-const
Handle2ExternalFiles
CovarianceSuiteExternalFilesGet(ConstHandle2CovarianceSuite This)
{
   return detail::getField<CPP,Handle2ExternalFiles>
      (CLASSNAME, CLASSNAME+"ExternalFilesGet", This, extract::externalFiles);
}

// Set
void
CovarianceSuiteExternalFilesSet(ConstHandle2CovarianceSuite This, ConstHandle2ConstExternalFiles externalFiles)
{
   detail::setField<CPP,CPPExternalFiles>
      (CLASSNAME, CLASSNAME+"ExternalFilesSet", This, extract::externalFiles, externalFiles);
}


// -----------------------------------------------------------------------------
// Child: styles
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteStylesHas(ConstHandle2ConstCovarianceSuite This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StylesHas", This, extract::styles);
}

// Get, const
Handle2ConstStyles
CovarianceSuiteStylesGetConst(ConstHandle2ConstCovarianceSuite This)
{
   return detail::getField<CPP,Handle2ConstStyles>
      (CLASSNAME, CLASSNAME+"StylesGetConst", This, extract::styles);
}

// Get, non-const
Handle2Styles
CovarianceSuiteStylesGet(ConstHandle2CovarianceSuite This)
{
   return detail::getField<CPP,Handle2Styles>
      (CLASSNAME, CLASSNAME+"StylesGet", This, extract::styles);
}

// Set
void
CovarianceSuiteStylesSet(ConstHandle2CovarianceSuite This, ConstHandle2ConstStyles styles)
{
   detail::setField<CPP,CPPStyles>
      (CLASSNAME, CLASSNAME+"StylesSet", This, extract::styles, styles);
}


// -----------------------------------------------------------------------------
// Child: covarianceSections
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteCovarianceSectionsHas(ConstHandle2ConstCovarianceSuite This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceSectionsHas", This, extract::covarianceSections);
}

// Get, const
Handle2ConstCovarianceSections
CovarianceSuiteCovarianceSectionsGetConst(ConstHandle2ConstCovarianceSuite This)
{
   return detail::getField<CPP,Handle2ConstCovarianceSections>
      (CLASSNAME, CLASSNAME+"CovarianceSectionsGetConst", This, extract::covarianceSections);
}

// Get, non-const
Handle2CovarianceSections
CovarianceSuiteCovarianceSectionsGet(ConstHandle2CovarianceSuite This)
{
   return detail::getField<CPP,Handle2CovarianceSections>
      (CLASSNAME, CLASSNAME+"CovarianceSectionsGet", This, extract::covarianceSections);
}

// Set
void
CovarianceSuiteCovarianceSectionsSet(ConstHandle2CovarianceSuite This, ConstHandle2ConstCovarianceSections covarianceSections)
{
   detail::setField<CPP,CPPCovarianceSections>
      (CLASSNAME, CLASSNAME+"CovarianceSectionsSet", This, extract::covarianceSections, covarianceSections);
}


// -----------------------------------------------------------------------------
// Child: parameterCovariances
// -----------------------------------------------------------------------------

// Has
int
CovarianceSuiteParameterCovariancesHas(ConstHandle2ConstCovarianceSuite This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ParameterCovariancesHas", This, extract::parameterCovariances);
}

// Get, const
Handle2ConstParameterCovariances
CovarianceSuiteParameterCovariancesGetConst(ConstHandle2ConstCovarianceSuite This)
{
   return detail::getField<CPP,Handle2ConstParameterCovariances>
      (CLASSNAME, CLASSNAME+"ParameterCovariancesGetConst", This, extract::parameterCovariances);
}

// Get, non-const
Handle2ParameterCovariances
CovarianceSuiteParameterCovariancesGet(ConstHandle2CovarianceSuite This)
{
   return detail::getField<CPP,Handle2ParameterCovariances>
      (CLASSNAME, CLASSNAME+"ParameterCovariancesGet", This, extract::parameterCovariances);
}

// Set
void
CovarianceSuiteParameterCovariancesSet(ConstHandle2CovarianceSuite This, ConstHandle2ConstParameterCovariances parameterCovariances)
{
   detail::setField<CPP,CPPParameterCovariances>
      (CLASSNAME, CLASSNAME+"ParameterCovariancesSet", This, extract::parameterCovariances, parameterCovariances);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/covariance/CovarianceSuite/src/custom.cpp"
