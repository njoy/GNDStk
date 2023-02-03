
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/RMatrix.hpp"
#include "RMatrix.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

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

using CPPPoPs = general::PoPs;
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
RMatrixAssign(ConstHandle2RMatrix This, ConstHandle2ConstRMatrix from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
RMatrixDelete(ConstHandle2ConstRMatrix This)
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
RMatrixRead(ConstHandle2RMatrix This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
RMatrixWrite(ConstHandle2ConstRMatrix This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
RMatrixPrint(ConstHandle2ConstRMatrix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
RMatrixPrintXML(ConstHandle2ConstRMatrix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
RMatrixPrintJSON(ConstHandle2ConstRMatrix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
RMatrixLabelHas(ConstHandle2ConstRMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
const char *
RMatrixLabelGet(ConstHandle2ConstRMatrix This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
RMatrixLabelSet(ConstHandle2RMatrix This, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: approximation
// -----------------------------------------------------------------------------

// Has
int
RMatrixApproximationHas(ConstHandle2ConstRMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationHas", This, extract::approximation);
}

// Get
// Returns by value
const char *
RMatrixApproximationGet(ConstHandle2ConstRMatrix This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationGet", This, extract::approximation);
}

// Set
void
RMatrixApproximationSet(ConstHandle2RMatrix This, const char *const approximation)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ApproximationSet", This, extract::approximation, approximation);
}


// -----------------------------------------------------------------------------
// Metadatum: boundaryCondition
// -----------------------------------------------------------------------------

// Has
int
RMatrixBoundaryConditionHas(ConstHandle2ConstRMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"BoundaryConditionHas", This, extract::boundaryCondition);
}

// Get
// Returns by value
const char *
RMatrixBoundaryConditionGet(ConstHandle2ConstRMatrix This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"BoundaryConditionGet", This, extract::boundaryCondition);
}

// Set
void
RMatrixBoundaryConditionSet(ConstHandle2RMatrix This, const char *const boundaryCondition)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"BoundaryConditionSet", This, extract::boundaryCondition, boundaryCondition);
}


// -----------------------------------------------------------------------------
// Metadatum: calculateChannelRadius
// -----------------------------------------------------------------------------

// Has
int
RMatrixCalculateChannelRadiusHas(ConstHandle2ConstRMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CalculateChannelRadiusHas", This, extract::calculateChannelRadius);
}

// Get
// Returns by value
bool
RMatrixCalculateChannelRadiusGet(ConstHandle2ConstRMatrix This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"CalculateChannelRadiusGet", This, extract::calculateChannelRadius);
}

// Set
void
RMatrixCalculateChannelRadiusSet(ConstHandle2RMatrix This, const bool calculateChannelRadius)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"CalculateChannelRadiusSet", This, extract::calculateChannelRadius, calculateChannelRadius);
}


// -----------------------------------------------------------------------------
// Metadatum: supportsAngularReconstruction
// -----------------------------------------------------------------------------

// Has
int
RMatrixSupportsAngularReconstructionHas(ConstHandle2ConstRMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SupportsAngularReconstructionHas", This, extract::supportsAngularReconstruction);
}

// Get
// Returns by value
bool
RMatrixSupportsAngularReconstructionGet(ConstHandle2ConstRMatrix This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SupportsAngularReconstructionGet", This, extract::supportsAngularReconstruction);
}

// Set
void
RMatrixSupportsAngularReconstructionSet(ConstHandle2RMatrix This, const bool supportsAngularReconstruction)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SupportsAngularReconstructionSet", This, extract::supportsAngularReconstruction, supportsAngularReconstruction);
}


// -----------------------------------------------------------------------------
// Child: PoPs
// -----------------------------------------------------------------------------

// Has
int
RMatrixPoPsHas(ConstHandle2ConstRMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PoPsHas", This, extract::PoPs);
}

// Get, const
Handle2ConstPoPs
RMatrixPoPsGetConst(ConstHandle2ConstRMatrix This)
{
   return detail::getField<CPP,Handle2ConstPoPs>
      (CLASSNAME, CLASSNAME+"PoPsGetConst", This, extract::PoPs);
}

// Get, non-const
Handle2PoPs
RMatrixPoPsGet(ConstHandle2RMatrix This)
{
   return detail::getField<CPP,Handle2PoPs>
      (CLASSNAME, CLASSNAME+"PoPsGet", This, extract::PoPs);
}

// Set
void
RMatrixPoPsSet(ConstHandle2RMatrix This, ConstHandle2ConstPoPs PoPs)
{
   detail::setField<CPP,CPPPoPs>
      (CLASSNAME, CLASSNAME+"PoPsSet", This, extract::PoPs, PoPs);
}


// -----------------------------------------------------------------------------
// Child: resonanceReactions
// -----------------------------------------------------------------------------

// Has
int
RMatrixResonanceReactionsHas(ConstHandle2ConstRMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsHas", This, extract::resonanceReactions);
}

// Get, const
Handle2ConstResonanceReactions
RMatrixResonanceReactionsGetConst(ConstHandle2ConstRMatrix This)
{
   return detail::getField<CPP,Handle2ConstResonanceReactions>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsGetConst", This, extract::resonanceReactions);
}

// Get, non-const
Handle2ResonanceReactions
RMatrixResonanceReactionsGet(ConstHandle2RMatrix This)
{
   return detail::getField<CPP,Handle2ResonanceReactions>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsGet", This, extract::resonanceReactions);
}

// Set
void
RMatrixResonanceReactionsSet(ConstHandle2RMatrix This, ConstHandle2ConstResonanceReactions resonanceReactions)
{
   detail::setField<CPP,CPPResonanceReactions>
      (CLASSNAME, CLASSNAME+"ResonanceReactionsSet", This, extract::resonanceReactions, resonanceReactions);
}


// -----------------------------------------------------------------------------
// Child: spinGroups
// -----------------------------------------------------------------------------

// Has
int
RMatrixSpinGroupsHas(ConstHandle2ConstRMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SpinGroupsHas", This, extract::spinGroups);
}

// Get, const
Handle2ConstSpinGroups
RMatrixSpinGroupsGetConst(ConstHandle2ConstRMatrix This)
{
   return detail::getField<CPP,Handle2ConstSpinGroups>
      (CLASSNAME, CLASSNAME+"SpinGroupsGetConst", This, extract::spinGroups);
}

// Get, non-const
Handle2SpinGroups
RMatrixSpinGroupsGet(ConstHandle2RMatrix This)
{
   return detail::getField<CPP,Handle2SpinGroups>
      (CLASSNAME, CLASSNAME+"SpinGroupsGet", This, extract::spinGroups);
}

// Set
void
RMatrixSpinGroupsSet(ConstHandle2RMatrix This, ConstHandle2ConstSpinGroups spinGroups)
{
   detail::setField<CPP,CPPSpinGroups>
      (CLASSNAME, CLASSNAME+"SpinGroupsSet", This, extract::spinGroups, spinGroups);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/RMatrix/src/custom.cpp"
