
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Evaporation.hpp"
#include "Evaporation.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = EvaporationClass;
using CPP = multigroup::Evaporation;

static const std::string CLASSNAME = "Evaporation";

namespace extract {
   static auto U = [](auto &obj) { return &obj.U; };
   static auto theta = [](auto &obj) { return &obj.theta; };
}

using CPPU = general::U;
using CPPTheta = general::Theta;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstEvaporation
EvaporationDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Evaporation
EvaporationDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstEvaporation
EvaporationCreateConst(
   ConstHandle2ConstU U,
   ConstHandle2ConstTheta theta
) {
   ConstHandle2Evaporation handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPU>(U),
      detail::tocpp<CPPTheta>(theta)
   );
   return handle;
}

// Create, general
Handle2Evaporation
EvaporationCreate(
   ConstHandle2ConstU U,
   ConstHandle2ConstTheta theta
) {
   ConstHandle2Evaporation handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPU>(U),
      detail::tocpp<CPPTheta>(theta)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
EvaporationAssign(ConstHandle2Evaporation self, ConstHandle2ConstEvaporation from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
EvaporationDelete(ConstHandle2ConstEvaporation self)
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
EvaporationRead(ConstHandle2Evaporation self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
EvaporationWrite(ConstHandle2ConstEvaporation self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
EvaporationPrint(ConstHandle2ConstEvaporation self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
EvaporationPrintXML(ConstHandle2ConstEvaporation self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
EvaporationPrintJSON(ConstHandle2ConstEvaporation self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: U
// -----------------------------------------------------------------------------

// Has
int
EvaporationUHas(ConstHandle2ConstEvaporation self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UHas", self, extract::U);
}

// Get, const
Handle2ConstU
EvaporationUGetConst(ConstHandle2ConstEvaporation self)
{
   return detail::getField<CPP,Handle2ConstU>
      (CLASSNAME, CLASSNAME+"UGetConst", self, extract::U);
}

// Get, non-const
Handle2U
EvaporationUGet(ConstHandle2Evaporation self)
{
   return detail::getField<CPP,Handle2U>
      (CLASSNAME, CLASSNAME+"UGet", self, extract::U);
}

// Set
void
EvaporationUSet(ConstHandle2Evaporation self, ConstHandle2ConstU U)
{
   detail::setField<CPP,CPPU>
      (CLASSNAME, CLASSNAME+"USet", self, extract::U, U);
}


// -----------------------------------------------------------------------------
// Child: theta
// -----------------------------------------------------------------------------

// Has
int
EvaporationThetaHas(ConstHandle2ConstEvaporation self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThetaHas", self, extract::theta);
}

// Get, const
Handle2ConstTheta
EvaporationThetaGetConst(ConstHandle2ConstEvaporation self)
{
   return detail::getField<CPP,Handle2ConstTheta>
      (CLASSNAME, CLASSNAME+"ThetaGetConst", self, extract::theta);
}

// Get, non-const
Handle2Theta
EvaporationThetaGet(ConstHandle2Evaporation self)
{
   return detail::getField<CPP,Handle2Theta>
      (CLASSNAME, CLASSNAME+"ThetaGet", self, extract::theta);
}

// Set
void
EvaporationThetaSet(ConstHandle2Evaporation self, ConstHandle2ConstTheta theta)
{
   detail::setField<CPP,CPPTheta>
      (CLASSNAME, CLASSNAME+"ThetaSet", self, extract::theta, theta);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Evaporation/src/custom.cpp"
