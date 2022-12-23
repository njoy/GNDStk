
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/Isotropic2d.hpp"
#include "Isotropic2d.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = Isotropic2dClass;
using CPP = multigroup::Isotropic2d;

static const std::string CLASSNAME = "Isotropic2d";


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstIsotropic2d
Isotropic2dDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Isotropic2d
Isotropic2dDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstIsotropic2d
Isotropic2dCreateConst()
{
   ConstHandle2Isotropic2d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst"
   );
   return handle;
}

// Create, general
Handle2Isotropic2d
Isotropic2dCreate()
{
   ConstHandle2Isotropic2d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create"
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
Isotropic2dAssign(ConstHandle2Isotropic2d This, ConstHandle2ConstIsotropic2d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Isotropic2dDelete(ConstHandle2ConstIsotropic2d This)
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
Isotropic2dRead(ConstHandle2Isotropic2d This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Isotropic2dWrite(ConstHandle2ConstIsotropic2d This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
Isotropic2dPrint(ConstHandle2ConstIsotropic2d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
Isotropic2dPrintXML(ConstHandle2ConstIsotropic2d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
Isotropic2dPrintJSON(ConstHandle2ConstIsotropic2d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}
