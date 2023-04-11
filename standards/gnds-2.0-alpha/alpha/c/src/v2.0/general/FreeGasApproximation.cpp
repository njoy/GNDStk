
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/FreeGasApproximation.hpp"
#include "FreeGasApproximation.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = FreeGasApproximationClass;
using CPP = multigroup::FreeGasApproximation;

static const std::string CLASSNAME = "FreeGasApproximation";


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstFreeGasApproximation
FreeGasApproximationDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2FreeGasApproximation
FreeGasApproximationDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstFreeGasApproximation
FreeGasApproximationCreateConst()
{
   ConstHandle2FreeGasApproximation handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst"
   );
   return handle;
}

// Create, general
Handle2FreeGasApproximation
FreeGasApproximationCreate()
{
   ConstHandle2FreeGasApproximation handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create"
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
FreeGasApproximationAssign(ConstHandle2FreeGasApproximation self, ConstHandle2ConstFreeGasApproximation from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
FreeGasApproximationDelete(ConstHandle2ConstFreeGasApproximation self)
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
FreeGasApproximationRead(ConstHandle2FreeGasApproximation self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
FreeGasApproximationWrite(ConstHandle2ConstFreeGasApproximation self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
FreeGasApproximationPrint(ConstHandle2ConstFreeGasApproximation self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
FreeGasApproximationPrintXML(ConstHandle2ConstFreeGasApproximation self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
FreeGasApproximationPrintJSON(ConstHandle2ConstFreeGasApproximation self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/FreeGasApproximation/src/custom.cpp"
