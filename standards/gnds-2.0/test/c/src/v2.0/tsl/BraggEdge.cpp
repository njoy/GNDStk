
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/tsl/BraggEdge.hpp"
#include "BraggEdge.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = BraggEdgeClass;
using CPP = multigroup::BraggEdge;

static const std::string CLASSNAME = "BraggEdge";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto BraggEnergy = [](auto &obj) { return &obj.BraggEnergy; };
   static auto structureFactor = [](auto &obj) { return &obj.structureFactor; };
}

using CPPBraggEnergy = tsl::BraggEnergy;
using CPPStructureFactor = tsl::StructureFactor;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstBraggEdge
BraggEdgeDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2BraggEdge
BraggEdgeDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstBraggEdge
BraggEdgeCreateConst(
   const XMLName label,
   ConstHandle2ConstBraggEnergy BraggEnergy,
   ConstHandle2ConstStructureFactor structureFactor
) {
   ConstHandle2BraggEdge handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPBraggEnergy>(BraggEnergy),
      detail::tocpp<CPPStructureFactor>(structureFactor)
   );
   return handle;
}

// Create, general
Handle2BraggEdge
BraggEdgeCreate(
   const XMLName label,
   ConstHandle2ConstBraggEnergy BraggEnergy,
   ConstHandle2ConstStructureFactor structureFactor
) {
   ConstHandle2BraggEdge handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPBraggEnergy>(BraggEnergy),
      detail::tocpp<CPPStructureFactor>(structureFactor)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
BraggEdgeAssign(ConstHandle2BraggEdge This, ConstHandle2ConstBraggEdge from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
BraggEdgeDelete(ConstHandle2ConstBraggEdge This)
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
BraggEdgeRead(ConstHandle2BraggEdge This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
BraggEdgeWrite(ConstHandle2ConstBraggEdge This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
BraggEdgePrint(ConstHandle2ConstBraggEdge This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
BraggEdgePrintXML(ConstHandle2ConstBraggEdge This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
BraggEdgePrintJSON(ConstHandle2ConstBraggEdge This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
BraggEdgeLabelHas(ConstHandle2ConstBraggEdge This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
BraggEdgeLabelGet(ConstHandle2ConstBraggEdge This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
BraggEdgeLabelSet(ConstHandle2BraggEdge This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: BraggEnergy
// -----------------------------------------------------------------------------

// Has
int
BraggEdgeBraggEnergyHas(ConstHandle2ConstBraggEdge This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"BraggEnergyHas", This, extract::BraggEnergy);
}

// Get, const
Handle2ConstBraggEnergy
BraggEdgeBraggEnergyGetConst(ConstHandle2ConstBraggEdge This)
{
   return detail::getField<CPP,Handle2ConstBraggEnergy>
      (CLASSNAME, CLASSNAME+"BraggEnergyGetConst", This, extract::BraggEnergy);
}

// Get, non-const
Handle2BraggEnergy
BraggEdgeBraggEnergyGet(ConstHandle2BraggEdge This)
{
   return detail::getField<CPP,Handle2BraggEnergy>
      (CLASSNAME, CLASSNAME+"BraggEnergyGet", This, extract::BraggEnergy);
}

// Set
void
BraggEdgeBraggEnergySet(ConstHandle2BraggEdge This, ConstHandle2ConstBraggEnergy BraggEnergy)
{
   detail::setField<CPP,CPPBraggEnergy>
      (CLASSNAME, CLASSNAME+"BraggEnergySet", This, extract::BraggEnergy, BraggEnergy);
}


// -----------------------------------------------------------------------------
// Child: structureFactor
// -----------------------------------------------------------------------------

// Has
int
BraggEdgeStructureFactorHas(ConstHandle2ConstBraggEdge This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"StructureFactorHas", This, extract::structureFactor);
}

// Get, const
Handle2ConstStructureFactor
BraggEdgeStructureFactorGetConst(ConstHandle2ConstBraggEdge This)
{
   return detail::getField<CPP,Handle2ConstStructureFactor>
      (CLASSNAME, CLASSNAME+"StructureFactorGetConst", This, extract::structureFactor);
}

// Get, non-const
Handle2StructureFactor
BraggEdgeStructureFactorGet(ConstHandle2BraggEdge This)
{
   return detail::getField<CPP,Handle2StructureFactor>
      (CLASSNAME, CLASSNAME+"StructureFactorGet", This, extract::structureFactor);
}

// Set
void
BraggEdgeStructureFactorSet(ConstHandle2BraggEdge This, ConstHandle2ConstStructureFactor structureFactor)
{
   detail::setField<CPP,CPPStructureFactor>
      (CLASSNAME, CLASSNAME+"StructureFactorSet", This, extract::structureFactor, structureFactor);
}
