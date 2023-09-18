
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/RMatrix.hpp"
#include "RMatrix.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = RMatrixClass;
using CPP = multigroup::RMatrix;

static const std::string CLASSNAME = "RMatrix";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto approximation = [](auto &obj) { return &obj.approximation; };
   static auto boundaryCondition = [](auto &obj) { return &obj.boundaryCondition; };
   static auto calculateChannelRadius = [](auto &obj) { return &obj.calculateChannelRadius; };
   static auto supportsAngularReconstruction = [](auto &obj) { return &obj.supportsAngularReconstruction; };
   static auto PoPs = [](auto &obj) { return &obj.PoPs; };
   static auto resonanceReactions = [](auto &obj) { return &obj.resonanceReactions; };
   static auto spinGroups = [](auto &obj) { return &obj.spinGroups; };
}

using CPPPoPs = top::PoPs;
using CPPResonanceReactions = general::ResonanceReactions;
using CPPSpinGroups = general::SpinGroups;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstRMatrix
RMatrixDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2RMatrix
RMatrixDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstRMatrix
RMatrixCreateConst(
   const char *const label,
   const char *const approximation,
   const char *const boundaryCondition,
   const bool calculateChannelRadius,
   const bool supportsAngularReconstruction,
   ConstHandle2ConstPoPs PoPs,
   ConstHandle2ConstResonanceReactions resonanceReactions,
   ConstHandle2ConstSpinGroups spinGroups
) {
   ConstHandle2RMatrix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      approximation,
      boundaryCondition,
      calculateChannelRadius,
      supportsAngularReconstruction,
      detail::tocpp<CPPPoPs>(PoPs),
      detail::tocpp<CPPResonanceReactions>(resonanceReactions),
      detail::tocpp<CPPSpinGroups>(spinGroups)
   );
   return handle;
}

// Create, general
Handle2RMatrix
RMatrixCreate(
   const char *const label,
   const char *const approximation,
   const char *const boundaryCondition,
   const bool calculateChannelRadius,
   const bool supportsAngularReconstruction,
   ConstHandle2ConstPoPs PoPs,
   ConstHandle2ConstResonanceReactions resonanceReactions,
   ConstHandle2ConstSpinGroups spinGroups
) {
   ConstHandle2RMatrix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      approximation,
      boundaryCondition,
      calculateChannelRadius,
      supportsAngularReconstruction,
      detail::tocpp<CPPPoPs>(PoPs),
      detail::tocpp<CPPResonanceReactions>(resonanceReactions),
      detail::tocpp<CPPSpinGroups>(spinGroups)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
RMatrixAssign(ConstHandle2RMatrix self, ConstHandle2ConstRMatrix from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
RMatrixDelete(ConstHandle2ConstRMatrix self)
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
RMatrixRead(ConstHandle2RMatrix self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
RMatrixWrite(ConstHandle2ConstRMatrix self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
RMatrixPrint(ConstHandle2ConstRMatrix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
RMatrixPrintXML(ConstHandle2ConstRMatrix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
RMatrixPrintJSON(ConstHandle2ConstRMatrix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
RMatrixLabelHas(ConstHandle2ConstRMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
RMatrixLabelGet(ConstHandle2ConstRMatrix self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
RMatrixLabelSet(ConstHandle2RMatrix self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: approximation
// -----------------------------------------------------------------------------

// Has
int
RMatrixApproximationHas(ConstHandle2ConstRMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationHas", self, extract::approximation);
}

// Get
// Returns by value
const char *
RMatrixApproximationGet(ConstHandle2ConstRMatrix self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationGet", self, extract::approximation);
}

// Set
void
RMatrixApproximationSet(ConstHandle2RMatrix self, const char *const approximation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationSet", self, extract::approximation, approximation);
}


// -----------------------------------------------------------------------------
// Metadatum: boundaryCondition
// -----------------------------------------------------------------------------

// Has
int
RMatrixBoundaryConditionHas(ConstHandle2ConstRMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"BoundaryConditionHas", self, extract::boundaryCondition);
}

// Get
// Returns by value
const char *
RMatrixBoundaryConditionGet(ConstHandle2ConstRMatrix self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"BoundaryConditionGet", self, extract::boundaryCondition);
}

// Set
void
RMatrixBoundaryConditionSet(ConstHandle2RMatrix self, const char *const boundaryCondition)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"BoundaryConditionSet", self, extract::boundaryCondition, boundaryCondition);
}


// -----------------------------------------------------------------------------
// Metadatum: calculateChannelRadius
// -----------------------------------------------------------------------------

// Has
int
RMatrixCalculateChannelRadiusHas(ConstHandle2ConstRMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CalculateChannelRadiusHas", self, extract::calculateChannelRadius);
}

// Get
// Returns by value
bool
RMatrixCalculateChannelRadiusGet(ConstHandle2ConstRMatrix self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"CalculateChannelRadiusGet", self, extract::calculateChannelRadius);
}

// Set
void
RMatrixCalculateChannelRadiusSet(ConstHandle2RMatrix self, const bool calculateChannelRadius)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"CalculateChannelRadiusSet", self, extract::calculateChannelRadius, calculateChannelRadius);
}


// -----------------------------------------------------------------------------
// Metadatum: supportsAngularReconstruction
// -----------------------------------------------------------------------------

// Has
int
RMatrixSupportsAngularReconstructionHas(ConstHandle2ConstRMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SupportsAngularReconstructionHas", self, extract::supportsAngularReconstruction);
}

// Get
// Returns by value
bool
RMatrixSupportsAngularReconstructionGet(ConstHandle2ConstRMatrix self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SupportsAngularReconstructionGet", self, extract::supportsAngularReconstruction);
}

// Set
void
RMatrixSupportsAngularReconstructionSet(ConstHandle2RMatrix self, const bool supportsAngularReconstruction)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SupportsAngularReconstructionSet", self, extract::supportsAngularReconstruction, supportsAngularReconstruction);
}


// -----------------------------------------------------------------------------
// Child: PoPs
// -----------------------------------------------------------------------------

// Has
int
RMatrixPoPsHas(ConstHandle2ConstRMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PoPsHas", self, extract::PoPs);
}

// Get, const
Handle2ConstPoPs
RMatrixPoPsGetConst(ConstHandle2ConstRMatrix self)
{
   return detail::getField<CPP,Handle2ConstPoPs>
      (CLASSNAME, CLASSNAME+"PoPsGetConst", self, extract::PoPs);
}

// Get
Handle2PoPs
RMatrixPoPsGet(ConstHandle2RMatrix self)
{
   return detail::getField<CPP,Handle2PoPs>
      (CLASSNAME, CLASSNAME+"PoPsGet", self, extract::PoPs);
}

// Set
void
RMatrixPoPsSet(ConstHandle2RMatrix self, ConstHandle2ConstPoPs PoPs)
{
   detail::setField<CPP,CPPPoPs>
      (CLASSNAME, CLASSNAME+"PoPsSet", self, extract::PoPs, PoPs);
}


// -----------------------------------------------------------------------------
// Child: resonanceReactions
// -----------------------------------------------------------------------------

// Has
int
RMatrixResonanceReactionsHas(ConstHandle2ConstRMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsHas", self, extract::resonanceReactions);
}

// Get, const
Handle2ConstResonanceReactions
RMatrixResonanceReactionsGetConst(ConstHandle2ConstRMatrix self)
{
   return detail::getField<CPP,Handle2ConstResonanceReactions>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsGetConst", self, extract::resonanceReactions);
}

// Get
Handle2ResonanceReactions
RMatrixResonanceReactionsGet(ConstHandle2RMatrix self)
{
   return detail::getField<CPP,Handle2ResonanceReactions>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsGet", self, extract::resonanceReactions);
}

// Set
void
RMatrixResonanceReactionsSet(ConstHandle2RMatrix self, ConstHandle2ConstResonanceReactions resonanceReactions)
{
   detail::setField<CPP,CPPResonanceReactions>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsSet", self, extract::resonanceReactions, resonanceReactions);
}


// -----------------------------------------------------------------------------
// Child: spinGroups
// -----------------------------------------------------------------------------

// Has
int
RMatrixSpinGroupsHas(ConstHandle2ConstRMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SpinGroupsHas", self, extract::spinGroups);
}

// Get, const
Handle2ConstSpinGroups
RMatrixSpinGroupsGetConst(ConstHandle2ConstRMatrix self)
{
   return detail::getField<CPP,Handle2ConstSpinGroups>
      (CLASSNAME, CLASSNAME+"SpinGroupsGetConst", self, extract::spinGroups);
}

// Get
Handle2SpinGroups
RMatrixSpinGroupsGet(ConstHandle2RMatrix self)
{
   return detail::getField<CPP,Handle2SpinGroups>
      (CLASSNAME, CLASSNAME+"SpinGroupsGet", self, extract::spinGroups);
}

// Set
void
RMatrixSpinGroupsSet(ConstHandle2RMatrix self, ConstHandle2ConstSpinGroups spinGroups)
{
   detail::setField<CPP,CPPSpinGroups>
      (CLASSNAME, CLASSNAME+"SpinGroupsSet", self, extract::spinGroups, spinGroups);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/RMatrix/src/custom.cpp"
