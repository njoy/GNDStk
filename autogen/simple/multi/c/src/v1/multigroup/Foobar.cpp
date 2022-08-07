
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
      (CLASSNAME, "FoobarDefaultConst");
}

// Create: default
Handle2Foobar
FoobarDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, "FoobarDefault");
}

// Create: general, const
Handle2ConstFoobar
FoobarCreateConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, "FoobarCreateConst");
}

// Create: general
Handle2Foobar
FoobarCreate()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, "FoobarCreate");
}

// Assign
void
FoobarAssign(ConstHandle2Foobar This, ConstHandle2ConstFoobar from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, "FoobarAssign", This, from);
}

// Delete
void
FoobarDelete(ConstHandle2ConstFoobar This)
{
   detail::deleteHandle<CPP,C>
      (CLASSNAME, "FoobarDelete", This);
}


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// Read
int
FoobarRead(ConstHandle2Foobar This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, "FoobarRead", This, filename);
}

// Write
int
FoobarWrite(ConstHandle2ConstFoobar This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, "FoobarWrite", This, filename);
}

// Print to standard output
int
FoobarPrint(ConstHandle2ConstFoobar This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, "FoobarPrint", This);
}

// Print to standard output, as XML
int
FoobarPrintXML(ConstHandle2ConstFoobar This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, "FoobarPrintXML", This, "XML");
}

// Print to standard output, as JSON
int
FoobarPrintJSON(ConstHandle2ConstFoobar This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, "FoobarPrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Re: vector
// -----------------------------------------------------------------------------

// Clear
void
FoobarDoublesClear(ConstHandle2Foobar This)
{
   detail::vectorClear<CPP>
      (CLASSNAME, "FoobarDoublesClear", This);
}

// Size
size_t
FoobarDoublesSize(ConstHandle2ConstFoobar This)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, "FoobarDoublesSize", This);
}

// Get
double
FoobarDoublesGet(ConstHandle2ConstFoobar This, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, "FoobarDoublesGet", This, index);
}

// Set
void
FoobarDoublesSet(ConstHandle2Foobar This, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, "FoobarDoublesSet", This, index, value);
}

// Get pointer to values, const
const double *
FoobarDoublesGetArrayConst(ConstHandle2ConstFoobar This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, "FoobarDoublesGetArrayConst", This);
}

// Get pointer to values, non-const
double *
FoobarDoublesGetArray(ConstHandle2Foobar This)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, "FoobarDoublesGetArray", This);
}

// Set new size and values
void
FoobarDoublesSetArray(ConstHandle2Foobar This, const size_t size, const double *const values)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, "FoobarDoublesSetArray", This, size, values);
}
