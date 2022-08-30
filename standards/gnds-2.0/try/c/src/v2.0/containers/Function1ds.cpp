
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/containers/Function1ds.hpp"
#include "Function1ds.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = Function1dsClass;
using CPP = multigroup::Function1ds;

static const std::string CLASSNAME = "Function1ds";

namespace extract {
}

using CPPXYs1d = containers::XYs1d;
using CPPConstant1d = containers::Constant1d;
using CPPPolynomial1d = containers::Polynomial1d;
using CPPLegendre = containers::Legendre;
using CPPGridded1d = containers::Gridded1d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstFunction1ds
Function1dsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Function1ds
Function1dsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstFunction1ds
Function1dsCreateConst(
) {
   ConstHandle2Function1ds handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst"
   );
   return handle;
}

// Create, general
Handle2Function1ds
Function1dsCreate(
) {
   ConstHandle2Function1ds handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create"
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
Function1dsAssign(ConstHandle2Function1ds This, ConstHandle2ConstFunction1ds from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Function1dsDelete(ConstHandle2ConstFunction1ds This)
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
Function1dsRead(ConstHandle2Function1ds This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Function1dsWrite(ConstHandle2ConstFunction1ds This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
Function1dsPrint(ConstHandle2ConstFunction1ds This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
Function1dsPrintXML(ConstHandle2ConstFunction1ds This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
Function1dsPrintJSON(ConstHandle2ConstFunction1ds This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}
