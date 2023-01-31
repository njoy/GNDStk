
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/dfiles/RutherfordScattering.hpp"
#include "RutherfordScattering.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = RutherfordScatteringClass;
using CPP = multigroup::RutherfordScattering;

static const std::string CLASSNAME = "RutherfordScattering";


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstRutherfordScattering
RutherfordScatteringDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2RutherfordScattering
RutherfordScatteringDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstRutherfordScattering
RutherfordScatteringCreateConst()
{
   ConstHandle2RutherfordScattering handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst"
   );
   return handle;
}

// Create, general
Handle2RutherfordScattering
RutherfordScatteringCreate()
{
   ConstHandle2RutherfordScattering handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create"
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
RutherfordScatteringAssign(ConstHandle2RutherfordScattering This, ConstHandle2ConstRutherfordScattering from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
RutherfordScatteringDelete(ConstHandle2ConstRutherfordScattering This)
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
RutherfordScatteringRead(ConstHandle2RutherfordScattering This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
RutherfordScatteringWrite(ConstHandle2ConstRutherfordScattering This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
RutherfordScatteringPrint(ConstHandle2ConstRutherfordScattering This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
RutherfordScatteringPrintXML(ConstHandle2ConstRutherfordScattering This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
RutherfordScatteringPrintJSON(ConstHandle2ConstRutherfordScattering This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/dfiles/RutherfordScattering/src/custom.cpp"
