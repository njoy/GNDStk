
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/ImaginaryAnomalousFactor.hpp"
#include "ImaginaryAnomalousFactor.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ImaginaryAnomalousFactorClass;
using CPP = multigroup::ImaginaryAnomalousFactor;

static const std::string CLASSNAME = "ImaginaryAnomalousFactor";

namespace extract {
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
}

using CPPXYs1d = general::XYs1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstImaginaryAnomalousFactor
ImaginaryAnomalousFactorDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ImaginaryAnomalousFactor
ImaginaryAnomalousFactorDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstImaginaryAnomalousFactor
ImaginaryAnomalousFactorCreateConst(
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2ImaginaryAnomalousFactor handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Create, general
Handle2ImaginaryAnomalousFactor
ImaginaryAnomalousFactorCreate(
   ConstHandle2ConstXYs1d XYs1d
) {
   ConstHandle2ImaginaryAnomalousFactor handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs1d>(XYs1d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ImaginaryAnomalousFactorAssign(ConstHandle2ImaginaryAnomalousFactor self, ConstHandle2ConstImaginaryAnomalousFactor from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ImaginaryAnomalousFactorDelete(ConstHandle2ConstImaginaryAnomalousFactor self)
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
ImaginaryAnomalousFactorRead(ConstHandle2ImaginaryAnomalousFactor self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ImaginaryAnomalousFactorWrite(ConstHandle2ConstImaginaryAnomalousFactor self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ImaginaryAnomalousFactorPrint(ConstHandle2ConstImaginaryAnomalousFactor self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ImaginaryAnomalousFactorPrintXML(ConstHandle2ConstImaginaryAnomalousFactor self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ImaginaryAnomalousFactorPrintJSON(ConstHandle2ConstImaginaryAnomalousFactor self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
ImaginaryAnomalousFactorXYs1dHas(ConstHandle2ConstImaginaryAnomalousFactor self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", self, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
ImaginaryAnomalousFactorXYs1dGetConst(ConstHandle2ConstImaginaryAnomalousFactor self)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", self, extract::XYs1d);
}

// Get
Handle2XYs1d
ImaginaryAnomalousFactorXYs1dGet(ConstHandle2ImaginaryAnomalousFactor self)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", self, extract::XYs1d);
}

// Set
void
ImaginaryAnomalousFactorXYs1dSet(ConstHandle2ImaginaryAnomalousFactor self, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", self, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ImaginaryAnomalousFactor/src/custom.cpp"
