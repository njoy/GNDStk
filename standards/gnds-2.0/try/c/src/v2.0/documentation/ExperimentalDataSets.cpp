
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/documentation/ExperimentalDataSets.hpp"
#include "ExperimentalDataSets.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = ExperimentalDataSetsClass;
using CPP = multigroup::ExperimentalDataSets;

static const std::string CLASSNAME = "ExperimentalDataSets";

namespace extract {
   static auto exforDataSets = [](auto &obj) { return &obj.exforDataSets; };
}

using CPPExforDataSets = documentation::ExforDataSets;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstExperimentalDataSets
ExperimentalDataSetsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ExperimentalDataSets
ExperimentalDataSetsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstExperimentalDataSets
ExperimentalDataSetsCreateConst(
   ConstHandle2ConstExforDataSets exforDataSets
) {
   ConstHandle2ExperimentalDataSets handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPExforDataSets>(exforDataSets)
   );
   return handle;
}

// Create, general
Handle2ExperimentalDataSets
ExperimentalDataSetsCreate(
   ConstHandle2ConstExforDataSets exforDataSets
) {
   ConstHandle2ExperimentalDataSets handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPExforDataSets>(exforDataSets)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ExperimentalDataSetsAssign(ConstHandle2ExperimentalDataSets This, ConstHandle2ConstExperimentalDataSets from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ExperimentalDataSetsDelete(ConstHandle2ConstExperimentalDataSets This)
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
ExperimentalDataSetsRead(ConstHandle2ExperimentalDataSets This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ExperimentalDataSetsWrite(ConstHandle2ConstExperimentalDataSets This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ExperimentalDataSetsPrint(ConstHandle2ConstExperimentalDataSets This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ExperimentalDataSetsPrintXML(ConstHandle2ConstExperimentalDataSets This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ExperimentalDataSetsPrintJSON(ConstHandle2ConstExperimentalDataSets This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: exforDataSets
// -----------------------------------------------------------------------------

// Has
int
ExperimentalDataSetsExforDataSetsHas(ConstHandle2ConstExperimentalDataSets This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ExforDataSetsHas", This, extract::exforDataSets);
}

// Get, const
Handle2ConstExforDataSets
ExperimentalDataSetsExforDataSetsGetConst(ConstHandle2ConstExperimentalDataSets This)
{
   return detail::getField<CPP,Handle2ConstExforDataSets>
      (CLASSNAME, CLASSNAME+"ExforDataSetsGetConst", This, extract::exforDataSets);
}

// Get, non-const
Handle2ExforDataSets
ExperimentalDataSetsExforDataSetsGet(ConstHandle2ExperimentalDataSets This)
{
   return detail::getField<CPP,Handle2ExforDataSets>
      (CLASSNAME, CLASSNAME+"ExforDataSetsGet", This, extract::exforDataSets);
}

// Set
void
ExperimentalDataSetsExforDataSetsSet(ConstHandle2ExperimentalDataSets This, ConstHandle2ConstExforDataSets exforDataSets)
{
   detail::setField<CPP,CPPExforDataSets>
      (CLASSNAME, CLASSNAME+"ExforDataSetsSet", This, extract::exforDataSets, exforDataSets);
}
