
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/containers/Interval.hpp"
#include "Interval.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = IntervalClass;
using CPP = multigroup::Interval;

static const std::string CLASSNAME = "Interval";

namespace extract {
   static auto confidence = [](auto &obj) { return &obj.confidence; };
   static auto lower = [](auto &obj) { return &obj.lower; };
   static auto upper = [](auto &obj) { return &obj.upper; };
}


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstInterval
IntervalDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Interval
IntervalDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstInterval
IntervalCreateConst(
   const Float64 confidence,
   const Float64 lower,
   const Float64 upper
) {
   ConstHandle2Interval handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      confidence,
      lower,
      upper
   );
   return handle;
}

// Create, general
Handle2Interval
IntervalCreate(
   const Float64 confidence,
   const Float64 lower,
   const Float64 upper
) {
   ConstHandle2Interval handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      confidence,
      lower,
      upper
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
IntervalAssign(ConstHandle2Interval This, ConstHandle2ConstInterval from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
IntervalDelete(ConstHandle2ConstInterval This)
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
IntervalRead(ConstHandle2Interval This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
IntervalWrite(ConstHandle2ConstInterval This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
IntervalPrint(ConstHandle2ConstInterval This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
IntervalPrintXML(ConstHandle2ConstInterval This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
IntervalPrintJSON(ConstHandle2ConstInterval This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: confidence
// -----------------------------------------------------------------------------

// Has
int
IntervalConfidenceHas(ConstHandle2ConstInterval This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ConfidenceHas", This, extract::confidence);
}

// Get
// Returns by value
Float64
IntervalConfidenceGet(ConstHandle2ConstInterval This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ConfidenceGet", This, extract::confidence);
}

// Set
void
IntervalConfidenceSet(ConstHandle2Interval This, const Float64 confidence)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ConfidenceSet", This, extract::confidence, confidence);
}


// -----------------------------------------------------------------------------
// Metadatum: lower
// -----------------------------------------------------------------------------

// Has
int
IntervalLowerHas(ConstHandle2ConstInterval This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LowerHas", This, extract::lower);
}

// Get
// Returns by value
Float64
IntervalLowerGet(ConstHandle2ConstInterval This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LowerGet", This, extract::lower);
}

// Set
void
IntervalLowerSet(ConstHandle2Interval This, const Float64 lower)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LowerSet", This, extract::lower, lower);
}


// -----------------------------------------------------------------------------
// Metadatum: upper
// -----------------------------------------------------------------------------

// Has
int
IntervalUpperHas(ConstHandle2ConstInterval This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UpperHas", This, extract::upper);
}

// Get
// Returns by value
Float64
IntervalUpperGet(ConstHandle2ConstInterval This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"UpperGet", This, extract::upper);
}

// Set
void
IntervalUpperSet(ConstHandle2Interval This, const Float64 upper)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"UpperSet", This, extract::upper, upper);
}
