
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/S_table.hpp"
#include "S_table.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = S_tableClass;
using CPP = multigroup::S_table;

static const std::string CLASSNAME = "S_table";

namespace extract {
   static auto gridded2d = [](auto &obj) { return &obj.gridded2d; };
}

using CPPGridded2d = general::Gridded2d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstS_table
S_tableDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2S_table
S_tableDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstS_table
S_tableCreateConst(
   ConstHandle2ConstGridded2d gridded2d
) {
   ConstHandle2S_table handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPGridded2d>(gridded2d)
   );
   return handle;
}

// Create, general
Handle2S_table
S_tableCreate(
   ConstHandle2ConstGridded2d gridded2d
) {
   ConstHandle2S_table handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPGridded2d>(gridded2d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
S_tableAssign(ConstHandle2S_table self, ConstHandle2ConstS_table from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
S_tableDelete(ConstHandle2ConstS_table self)
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
S_tableRead(ConstHandle2S_table self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
S_tableWrite(ConstHandle2ConstS_table self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
S_tablePrint(ConstHandle2ConstS_table self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
S_tablePrintXML(ConstHandle2ConstS_table self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
S_tablePrintJSON(ConstHandle2ConstS_table self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: gridded2d
// -----------------------------------------------------------------------------

// Has
int
S_tableGridded2dHas(ConstHandle2ConstS_table self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Gridded2dHas", self, extract::gridded2d);
}

// Get, const
Handle2ConstGridded2d
S_tableGridded2dGetConst(ConstHandle2ConstS_table self)
{
   return detail::getField<CPP,Handle2ConstGridded2d>
      (CLASSNAME, CLASSNAME+"Gridded2dGetConst", self, extract::gridded2d);
}

// Get, non-const
Handle2Gridded2d
S_tableGridded2dGet(ConstHandle2S_table self)
{
   return detail::getField<CPP,Handle2Gridded2d>
      (CLASSNAME, CLASSNAME+"Gridded2dGet", self, extract::gridded2d);
}

// Set
void
S_tableGridded2dSet(ConstHandle2S_table self, ConstHandle2ConstGridded2d gridded2d)
{
   detail::setField<CPP,CPPGridded2d>
      (CLASSNAME, CLASSNAME+"Gridded2dSet", self, extract::gridded2d, gridded2d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/S_table/src/custom.cpp"
