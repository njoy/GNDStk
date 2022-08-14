
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "multi/v1/multigroup/Foobar.hpp"
#include "Foobar.h"

using namespace njoy::GNDStk;
using namespace multi::v1;

using C = FoobarClass;
using CPP = multigroup::Foobar;

static const std::string CLASSNAME = "Foobar";


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create: default, const
Handle2ConstFoobar
FoobarDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create: default
Handle2Foobar
FoobarDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create: general, const
Handle2ConstFoobar
FoobarCreateConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"CreateConst");
}

// Create: general
Handle2Foobar
FoobarCreate()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Create");
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
FoobarAssign(ConstHandle2Foobar This, ConstHandle2ConstFoobar from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
FoobarDelete(ConstHandle2ConstFoobar This)
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
FoobarRead(ConstHandle2Foobar This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
FoobarWrite(ConstHandle2ConstFoobar This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
FoobarPrint(ConstHandle2ConstFoobar This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
FoobarPrintXML(ConstHandle2ConstFoobar This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
FoobarPrintJSON(ConstHandle2ConstFoobar This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Re: vector
// -----------------------------------------------------------------------------

// Clear
void
FoobarDoublesClear(ConstHandle2Foobar This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"DoublesClear", This);
}

// Get size
size_t
FoobarDoublesSize(ConstHandle2ConstFoobar This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"DoublesSize", This);
}

// Get value
// By index \in [0,size)
double
FoobarDoublesGet(ConstHandle2ConstFoobar This, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGet", This, index);
}

// Set value
// By index \in [0,size)
void
FoobarDoublesSet(ConstHandle2Foobar This, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSet", This, index, value);
}

// Get pointer to existing values, const
const double *
FoobarDoublesGetArrayConst(ConstHandle2ConstFoobar This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArrayConst", This);
}

// Get pointer to existing values, non-const
double *
FoobarDoublesGetArray(ConstHandle2Foobar This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArray", This);
}

// Set completely new values and size
void
FoobarDoublesSetArray(ConstHandle2Foobar This, const double *const values, const size_t size)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSetArray", This, size, values);
}
