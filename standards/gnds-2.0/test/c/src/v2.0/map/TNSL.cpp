
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/map/TNSL.hpp"
#include "TNSL.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = TNSLClass;
using CPP = multigroup::TNSL;

static const std::string CLASSNAME = "TNSL";

namespace extract {
   static auto projectile = [](auto &obj) { return &obj.projectile; };
   static auto target = [](auto &obj) { return &obj.target; };
   static auto evaluation = [](auto &obj) { return &obj.evaluation; };
   static auto path = [](auto &obj) { return &obj.path; };
   static auto interaction = [](auto &obj) { return &obj.interaction; };
   static auto checksum = [](auto &obj) { return &obj.checksum; };
   static auto algorithm = [](auto &obj) { return &obj.algorithm; };
   static auto standardTarget = [](auto &obj) { return &obj.standardTarget; };
   static auto standardEvaluation = [](auto &obj) { return &obj.standardEvaluation; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstTNSL
TNSLDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2TNSL
TNSLDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstTNSL
TNSLCreateConst(
   const XMLName projectile,
   const XMLName target,
   const XMLName evaluation,
   const XMLName path,
   const XMLName interaction,
   const char *const checksum,
   const enums::HashAlgorithm algorithm,
   const XMLName standardTarget,
   const XMLName standardEvaluation
) {
   ConstHandle2TNSL handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      projectile,
      target,
      evaluation,
      path,
      interaction,
      checksum,
      algorithm,
      standardTarget,
      standardEvaluation
   );
   return handle;
}

// Create, general
Handle2TNSL
TNSLCreate(
   const XMLName projectile,
   const XMLName target,
   const XMLName evaluation,
   const XMLName path,
   const XMLName interaction,
   const char *const checksum,
   const enums::HashAlgorithm algorithm,
   const XMLName standardTarget,
   const XMLName standardEvaluation
) {
   ConstHandle2TNSL handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      projectile,
      target,
      evaluation,
      path,
      interaction,
      checksum,
      algorithm,
      standardTarget,
      standardEvaluation
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
TNSLAssign(ConstHandle2TNSL This, ConstHandle2ConstTNSL from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
TNSLDelete(ConstHandle2ConstTNSL This)
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
TNSLRead(ConstHandle2TNSL This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
TNSLWrite(ConstHandle2ConstTNSL This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
TNSLPrint(ConstHandle2ConstTNSL This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
TNSLPrintXML(ConstHandle2ConstTNSL This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
TNSLPrintJSON(ConstHandle2ConstTNSL This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: projectile
// -----------------------------------------------------------------------------

// Has
int
TNSLProjectileHas(ConstHandle2ConstTNSL This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileHas", This, extract::projectile);
}

// Get
// Returns by value
XMLName
TNSLProjectileGet(ConstHandle2ConstTNSL This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileGet", This, extract::projectile);
}

// Set
void
TNSLProjectileSet(ConstHandle2TNSL This, const XMLName projectile)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileSet", This, extract::projectile, projectile);
}


// -----------------------------------------------------------------------------
// Metadatum: target
// -----------------------------------------------------------------------------

// Has
int
TNSLTargetHas(ConstHandle2ConstTNSL This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TargetHas", This, extract::target);
}

// Get
// Returns by value
XMLName
TNSLTargetGet(ConstHandle2ConstTNSL This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"TargetGet", This, extract::target);
}

// Set
void
TNSLTargetSet(ConstHandle2TNSL This, const XMLName target)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"TargetSet", This, extract::target, target);
}


// -----------------------------------------------------------------------------
// Metadatum: evaluation
// -----------------------------------------------------------------------------

// Has
int
TNSLEvaluationHas(ConstHandle2ConstTNSL This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationHas", This, extract::evaluation);
}

// Get
// Returns by value
XMLName
TNSLEvaluationGet(ConstHandle2ConstTNSL This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationGet", This, extract::evaluation);
}

// Set
void
TNSLEvaluationSet(ConstHandle2TNSL This, const XMLName evaluation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationSet", This, extract::evaluation, evaluation);
}


// -----------------------------------------------------------------------------
// Metadatum: path
// -----------------------------------------------------------------------------

// Has
int
TNSLPathHas(ConstHandle2ConstTNSL This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PathHas", This, extract::path);
}

// Get
// Returns by value
XMLName
TNSLPathGet(ConstHandle2ConstTNSL This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PathGet", This, extract::path);
}

// Set
void
TNSLPathSet(ConstHandle2TNSL This, const XMLName path)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PathSet", This, extract::path, path);
}


// -----------------------------------------------------------------------------
// Metadatum: interaction
// -----------------------------------------------------------------------------

// Has
int
TNSLInteractionHas(ConstHandle2ConstTNSL This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionHas", This, extract::interaction);
}

// Get
// Returns by value
XMLName
TNSLInteractionGet(ConstHandle2ConstTNSL This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionGet", This, extract::interaction);
}

// Set
void
TNSLInteractionSet(ConstHandle2TNSL This, const XMLName interaction)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionSet", This, extract::interaction, interaction);
}


// -----------------------------------------------------------------------------
// Metadatum: checksum
// -----------------------------------------------------------------------------

// Has
int
TNSLChecksumHas(ConstHandle2ConstTNSL This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChecksumHas", This, extract::checksum);
}

// Get
// Returns by value
const char *
TNSLChecksumGet(ConstHandle2ConstTNSL This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ChecksumGet", This, extract::checksum);
}

// Set
void
TNSLChecksumSet(ConstHandle2TNSL This, const char *const checksum)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ChecksumSet", This, extract::checksum, checksum);
}


// -----------------------------------------------------------------------------
// Metadatum: algorithm
// -----------------------------------------------------------------------------

// Has
int
TNSLAlgorithmHas(ConstHandle2ConstTNSL This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AlgorithmHas", This, extract::algorithm);
}

// Get
// Returns by value
enums::HashAlgorithm
TNSLAlgorithmGet(ConstHandle2ConstTNSL This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"AlgorithmGet", This, extract::algorithm);
}

// Set
void
TNSLAlgorithmSet(ConstHandle2TNSL This, const enums::HashAlgorithm algorithm)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"AlgorithmSet", This, extract::algorithm, algorithm);
}


// -----------------------------------------------------------------------------
// Metadatum: standardTarget
// -----------------------------------------------------------------------------

// Has
int
TNSLStandardTargetHas(ConstHandle2ConstTNSL This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StandardTargetHas", This, extract::standardTarget);
}

// Get
// Returns by value
XMLName
TNSLStandardTargetGet(ConstHandle2ConstTNSL This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"StandardTargetGet", This, extract::standardTarget);
}

// Set
void
TNSLStandardTargetSet(ConstHandle2TNSL This, const XMLName standardTarget)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"StandardTargetSet", This, extract::standardTarget, standardTarget);
}


// -----------------------------------------------------------------------------
// Metadatum: standardEvaluation
// -----------------------------------------------------------------------------

// Has
int
TNSLStandardEvaluationHas(ConstHandle2ConstTNSL This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StandardEvaluationHas", This, extract::standardEvaluation);
}

// Get
// Returns by value
XMLName
TNSLStandardEvaluationGet(ConstHandle2ConstTNSL This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"StandardEvaluationGet", This, extract::standardEvaluation);
}

// Set
void
TNSLStandardEvaluationSet(ConstHandle2TNSL This, const XMLName standardEvaluation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"StandardEvaluationSet", This, extract::standardEvaluation, standardEvaluation);
}
