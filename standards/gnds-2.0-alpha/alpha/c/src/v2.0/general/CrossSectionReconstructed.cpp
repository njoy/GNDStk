
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/CrossSectionReconstructed.hpp"
#include "CrossSectionReconstructed.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = CrossSectionReconstructedClass;
using CPP = multigroup::CrossSectionReconstructed;

static const std::string CLASSNAME = "CrossSectionReconstructed";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto derivedFrom = [](auto &obj) { return &obj.derivedFrom; };
   static auto date = [](auto &obj) { return &obj.date; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCrossSectionReconstructed
CrossSectionReconstructedDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2CrossSectionReconstructed
CrossSectionReconstructedDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCrossSectionReconstructed
CrossSectionReconstructedCreateConst(
   const char *const label,
   const char *const derivedFrom,
   const char *const date
) {
   ConstHandle2CrossSectionReconstructed handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      derivedFrom,
      date
   );
   return handle;
}

// Create, general
Handle2CrossSectionReconstructed
CrossSectionReconstructedCreate(
   const char *const label,
   const char *const derivedFrom,
   const char *const date
) {
   ConstHandle2CrossSectionReconstructed handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      derivedFrom,
      date
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CrossSectionReconstructedAssign(ConstHandle2CrossSectionReconstructed This, ConstHandle2ConstCrossSectionReconstructed from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CrossSectionReconstructedDelete(ConstHandle2ConstCrossSectionReconstructed This)
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
CrossSectionReconstructedRead(ConstHandle2CrossSectionReconstructed This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CrossSectionReconstructedWrite(ConstHandle2ConstCrossSectionReconstructed This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
CrossSectionReconstructedPrint(ConstHandle2ConstCrossSectionReconstructed This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
CrossSectionReconstructedPrintXML(ConstHandle2ConstCrossSectionReconstructed This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
CrossSectionReconstructedPrintJSON(ConstHandle2ConstCrossSectionReconstructed This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CrossSectionReconstructedLabelHas(ConstHandle2ConstCrossSectionReconstructed This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
const char *
CrossSectionReconstructedLabelGet(ConstHandle2ConstCrossSectionReconstructed This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
CrossSectionReconstructedLabelSet(ConstHandle2CrossSectionReconstructed This, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// Has
int
CrossSectionReconstructedDerivedFromHas(ConstHandle2ConstCrossSectionReconstructed This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromHas", This, extract::derivedFrom);
}

// Get
// Returns by value
const char *
CrossSectionReconstructedDerivedFromGet(ConstHandle2ConstCrossSectionReconstructed This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromGet", This, extract::derivedFrom);
}

// Set
void
CrossSectionReconstructedDerivedFromSet(ConstHandle2CrossSectionReconstructed This, const char *const derivedFrom)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromSet", This, extract::derivedFrom, derivedFrom);
}


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// Has
int
CrossSectionReconstructedDateHas(ConstHandle2ConstCrossSectionReconstructed This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DateHas", This, extract::date);
}

// Get
// Returns by value
const char *
CrossSectionReconstructedDateGet(ConstHandle2ConstCrossSectionReconstructed This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DateGet", This, extract::date);
}

// Set
void
CrossSectionReconstructedDateSet(ConstHandle2CrossSectionReconstructed This, const char *const date)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DateSet", This, extract::date, date);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/CrossSectionReconstructed/src/custom.cpp"
