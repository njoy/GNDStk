
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/styles/InverseSpeed.hpp"
#include "InverseSpeed.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = InverseSpeedClass;
using CPP = multigroup::InverseSpeed;

static const std::string CLASSNAME = "InverseSpeed";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto gridded1d = [](auto &obj) { return &obj.gridded1d; };
}

using CPPGridded1d = containers::Gridded1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstInverseSpeed
InverseSpeedDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2InverseSpeed
InverseSpeedDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstInverseSpeed
InverseSpeedCreateConst(
   const XMLName label,
   ConstHandle2ConstGridded1d gridded1d
) {
   ConstHandle2InverseSpeed handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPGridded1d>(gridded1d)
   );
   return handle;
}

// Create, general
Handle2InverseSpeed
InverseSpeedCreate(
   const XMLName label,
   ConstHandle2ConstGridded1d gridded1d
) {
   ConstHandle2InverseSpeed handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPGridded1d>(gridded1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
InverseSpeedAssign(ConstHandle2InverseSpeed self, ConstHandle2ConstInverseSpeed from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
InverseSpeedDelete(ConstHandle2ConstInverseSpeed self)
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
InverseSpeedRead(ConstHandle2InverseSpeed self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
InverseSpeedWrite(ConstHandle2ConstInverseSpeed self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
InverseSpeedPrint(ConstHandle2ConstInverseSpeed self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
InverseSpeedPrintXML(ConstHandle2ConstInverseSpeed self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
InverseSpeedPrintJSON(ConstHandle2ConstInverseSpeed self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
InverseSpeedLabelHas(ConstHandle2ConstInverseSpeed self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
InverseSpeedLabelGet(ConstHandle2ConstInverseSpeed self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
InverseSpeedLabelSet(ConstHandle2InverseSpeed self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: gridded1d
// -----------------------------------------------------------------------------

// Has
int
InverseSpeedGridded1dHas(ConstHandle2ConstInverseSpeed self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Gridded1dHas", self, extract::gridded1d);
}

// Get, const
Handle2ConstGridded1d
InverseSpeedGridded1dGetConst(ConstHandle2ConstInverseSpeed self)
{
   return detail::getField<CPP,Handle2ConstGridded1d>
      (CLASSNAME, CLASSNAME+"Gridded1dGetConst", self, extract::gridded1d);
}

// Get, non-const
Handle2Gridded1d
InverseSpeedGridded1dGet(ConstHandle2InverseSpeed self)
{
   return detail::getField<CPP,Handle2Gridded1d>
      (CLASSNAME, CLASSNAME+"Gridded1dGet", self, extract::gridded1d);
}

// Set
void
InverseSpeedGridded1dSet(ConstHandle2InverseSpeed self, ConstHandle2ConstGridded1d gridded1d)
{
   detail::setField<CPP,CPPGridded1d>
      (CLASSNAME, CLASSNAME+"Gridded1dSet", self, extract::gridded1d, gridded1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/InverseSpeed/src/custom.cpp"
