
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/map/Protare.hpp"
#include "Protare.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ProtareClass;
using CPP = multigroup::Protare;

static const std::string CLASSNAME = "Protare";

namespace extract {
   static auto projectile = [](auto &obj) { return &obj.projectile; };
   static auto target = [](auto &obj) { return &obj.target; };
   static auto evaluation = [](auto &obj) { return &obj.evaluation; };
   static auto path = [](auto &obj) { return &obj.path; };
   static auto interaction = [](auto &obj) { return &obj.interaction; };
   static auto checksum = [](auto &obj) { return &obj.checksum; };
   static auto algorithm = [](auto &obj) { return &obj.algorithm; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstProtare
ProtareDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Protare
ProtareDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstProtare
ProtareCreateConst(
   const XMLName projectile,
   const XMLName target,
   const XMLName evaluation,
   const XMLName path,
   const XMLName interaction,
   const char *const checksum,
   const enums::HashAlgorithm algorithm
) {
   ConstHandle2Protare handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      projectile,
      target,
      evaluation,
      path,
      interaction,
      checksum,
      algorithm
   );
   return handle;
}

// Create, general
Handle2Protare
ProtareCreate(
   const XMLName projectile,
   const XMLName target,
   const XMLName evaluation,
   const XMLName path,
   const XMLName interaction,
   const char *const checksum,
   const enums::HashAlgorithm algorithm
) {
   ConstHandle2Protare handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      projectile,
      target,
      evaluation,
      path,
      interaction,
      checksum,
      algorithm
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ProtareAssign(ConstHandle2Protare self, ConstHandle2ConstProtare from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ProtareDelete(ConstHandle2ConstProtare self)
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
ProtareRead(ConstHandle2Protare self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ProtareWrite(ConstHandle2ConstProtare self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ProtarePrint(ConstHandle2ConstProtare self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ProtarePrintXML(ConstHandle2ConstProtare self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ProtarePrintJSON(ConstHandle2ConstProtare self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: projectile
// -----------------------------------------------------------------------------

// Has
int
ProtareProjectileHas(ConstHandle2ConstProtare self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileHas", self, extract::projectile);
}

// Get
// Returns by value
XMLName
ProtareProjectileGet(ConstHandle2ConstProtare self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileGet", self, extract::projectile);
}

// Set
void
ProtareProjectileSet(ConstHandle2Protare self, const XMLName projectile)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProjectileSet", self, extract::projectile, projectile);
}


// -----------------------------------------------------------------------------
// Metadatum: target
// -----------------------------------------------------------------------------

// Has
int
ProtareTargetHas(ConstHandle2ConstProtare self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TargetHas", self, extract::target);
}

// Get
// Returns by value
XMLName
ProtareTargetGet(ConstHandle2ConstProtare self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"TargetGet", self, extract::target);
}

// Set
void
ProtareTargetSet(ConstHandle2Protare self, const XMLName target)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"TargetSet", self, extract::target, target);
}


// -----------------------------------------------------------------------------
// Metadatum: evaluation
// -----------------------------------------------------------------------------

// Has
int
ProtareEvaluationHas(ConstHandle2ConstProtare self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationHas", self, extract::evaluation);
}

// Get
// Returns by value
XMLName
ProtareEvaluationGet(ConstHandle2ConstProtare self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationGet", self, extract::evaluation);
}

// Set
void
ProtareEvaluationSet(ConstHandle2Protare self, const XMLName evaluation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"EvaluationSet", self, extract::evaluation, evaluation);
}


// -----------------------------------------------------------------------------
// Metadatum: path
// -----------------------------------------------------------------------------

// Has
int
ProtarePathHas(ConstHandle2ConstProtare self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PathHas", self, extract::path);
}

// Get
// Returns by value
XMLName
ProtarePathGet(ConstHandle2ConstProtare self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PathGet", self, extract::path);
}

// Set
void
ProtarePathSet(ConstHandle2Protare self, const XMLName path)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PathSet", self, extract::path, path);
}


// -----------------------------------------------------------------------------
// Metadatum: interaction
// -----------------------------------------------------------------------------

// Has
int
ProtareInteractionHas(ConstHandle2ConstProtare self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionHas", self, extract::interaction);
}

// Get
// Returns by value
XMLName
ProtareInteractionGet(ConstHandle2ConstProtare self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionGet", self, extract::interaction);
}

// Set
void
ProtareInteractionSet(ConstHandle2Protare self, const XMLName interaction)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"InteractionSet", self, extract::interaction, interaction);
}


// -----------------------------------------------------------------------------
// Metadatum: checksum
// -----------------------------------------------------------------------------

// Has
int
ProtareChecksumHas(ConstHandle2ConstProtare self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ChecksumHas", self, extract::checksum);
}

// Get
// Returns by value
const char *
ProtareChecksumGet(ConstHandle2ConstProtare self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ChecksumGet", self, extract::checksum);
}

// Set
void
ProtareChecksumSet(ConstHandle2Protare self, const char *const checksum)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ChecksumSet", self, extract::checksum, checksum);
}


// -----------------------------------------------------------------------------
// Metadatum: algorithm
// -----------------------------------------------------------------------------

// Has
int
ProtareAlgorithmHas(ConstHandle2ConstProtare self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AlgorithmHas", self, extract::algorithm);
}

// Get
// Returns by value
enums::HashAlgorithm
ProtareAlgorithmGet(ConstHandle2ConstProtare self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"AlgorithmGet", self, extract::algorithm);
}

// Set
void
ProtareAlgorithmSet(ConstHandle2Protare self, const enums::HashAlgorithm algorithm)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"AlgorithmSet", self, extract::algorithm, algorithm);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/map/Protare/src/custom.cpp"
