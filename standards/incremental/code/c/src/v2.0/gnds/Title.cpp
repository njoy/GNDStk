
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "code/v2.0/gnds/Title.hpp"
#include "Title.h"

using namespace njoy::GNDStk;
using namespace code::v2_0;

using C = TitleClass;
using CPP = multigroup::Title;

static const std::string CLASSNAME = "Title";


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstTitle
TitleDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Title
TitleDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstTitle
TitleCreateConst()
{
   ConstHandle2Title handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst"
   );
   return handle;
}

// Create, general
Handle2Title
TitleCreate()
{
   ConstHandle2Title handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create"
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
TitleAssign(ConstHandle2Title self, ConstHandle2ConstTitle from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
TitleDelete(ConstHandle2ConstTitle self)
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
TitleRead(ConstHandle2Title self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
TitleWrite(ConstHandle2ConstTitle self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
TitlePrint(ConstHandle2ConstTitle self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
TitlePrintXML(ConstHandle2ConstTitle self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
TitlePrintJSON(ConstHandle2ConstTitle self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Data vector
// -----------------------------------------------------------------------------

// ------------------------
// int
// ------------------------

// Clear
void
TitleIntsClear(ConstHandle2Title self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"IntsClear", self);
}

// Get size
size_t
TitleIntsSize(ConstHandle2ConstTitle self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"IntsSize", self);
}

// Get value
// By index \in [0,size)
int
TitleIntsGet(ConstHandle2ConstTitle self, const size_t index)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGet", self, index);
}

// Set value
// By index \in [0,size)
void
TitleIntsSet(ConstHandle2Title self, const size_t index, const int value)
{
   detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSet", self, index, value);
}

// Get pointer to existing values, const
const int *
TitleIntsGetArrayConst(ConstHandle2ConstTitle self)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArrayConst", self);
}

// Get pointer to existing values, non-const
int *
TitleIntsGetArray(ConstHandle2Title self)
{
   return detail::vectorGet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsGetArray", self);
}

// Set completely new values and size
void
TitleIntsSetArray(ConstHandle2Title self, const int *const values, const size_t size)
{
   return detail::vectorSet<CPP,int>
      (CLASSNAME, CLASSNAME+"IntsSetArray", self, size, values);
}

// ------------------------
// unsigned
// ------------------------

// Clear
void
TitleUnsignedsClear(ConstHandle2Title self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsClear", self);
}

// Get size
size_t
TitleUnsignedsSize(ConstHandle2ConstTitle self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"UnsignedsSize", self);
}

// Get value
// By index \in [0,size)
unsigned
TitleUnsignedsGet(ConstHandle2ConstTitle self, const size_t index)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGet", self, index);
}

// Set value
// By index \in [0,size)
void
TitleUnsignedsSet(ConstHandle2Title self, const size_t index, const unsigned value)
{
   detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSet", self, index, value);
}

// Get pointer to existing values, const
const unsigned *
TitleUnsignedsGetArrayConst(ConstHandle2ConstTitle self)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArrayConst", self);
}

// Get pointer to existing values, non-const
unsigned *
TitleUnsignedsGetArray(ConstHandle2Title self)
{
   return detail::vectorGet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsGetArray", self);
}

// Set completely new values and size
void
TitleUnsignedsSetArray(ConstHandle2Title self, const unsigned *const values, const size_t size)
{
   return detail::vectorSet<CPP,unsigned>
      (CLASSNAME, CLASSNAME+"UnsignedsSetArray", self, size, values);
}

// ------------------------
// float
// ------------------------

// Clear
void
TitleFloatsClear(ConstHandle2Title self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"FloatsClear", self);
}

// Get size
size_t
TitleFloatsSize(ConstHandle2ConstTitle self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"FloatsSize", self);
}

// Get value
// By index \in [0,size)
float
TitleFloatsGet(ConstHandle2ConstTitle self, const size_t index)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGet", self, index);
}

// Set value
// By index \in [0,size)
void
TitleFloatsSet(ConstHandle2Title self, const size_t index, const float value)
{
   detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSet", self, index, value);
}

// Get pointer to existing values, const
const float *
TitleFloatsGetArrayConst(ConstHandle2ConstTitle self)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArrayConst", self);
}

// Get pointer to existing values, non-const
float *
TitleFloatsGetArray(ConstHandle2Title self)
{
   return detail::vectorGet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsGetArray", self);
}

// Set completely new values and size
void
TitleFloatsSetArray(ConstHandle2Title self, const float *const values, const size_t size)
{
   return detail::vectorSet<CPP,float>
      (CLASSNAME, CLASSNAME+"FloatsSetArray", self, size, values);
}

// ------------------------
// double
// ------------------------

// Clear
void
TitleDoublesClear(ConstHandle2Title self)
{
   detail::vectorClear<CPP>
      (CLASSNAME, CLASSNAME+"DoublesClear", self);
}

// Get size
size_t
TitleDoublesSize(ConstHandle2ConstTitle self)
{
   return detail::vectorSize<CPP>
      (CLASSNAME, CLASSNAME+"DoublesSize", self);
}

// Get value
// By index \in [0,size)
double
TitleDoublesGet(ConstHandle2ConstTitle self, const size_t index)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGet", self, index);
}

// Set value
// By index \in [0,size)
void
TitleDoublesSet(ConstHandle2Title self, const size_t index, const double value)
{
   detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSet", self, index, value);
}

// Get pointer to existing values, const
const double *
TitleDoublesGetArrayConst(ConstHandle2ConstTitle self)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArrayConst", self);
}

// Get pointer to existing values, non-const
double *
TitleDoublesGetArray(ConstHandle2Title self)
{
   return detail::vectorGet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesGetArray", self);
}

// Set completely new values and size
void
TitleDoublesSetArray(ConstHandle2Title self, const double *const values, const size_t size)
{
   return detail::vectorSet<CPP,double>
      (CLASSNAME, CLASSNAME+"DoublesSetArray", self, size, values);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/gnds/Title/src/custom.cpp"
