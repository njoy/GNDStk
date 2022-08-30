
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/containers/Regions1d.hpp"
#include "Regions1d.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = Regions1dClass;
using CPP = multigroup::Regions1d;

static const std::string CLASSNAME = "Regions1d";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto outerDomainValue = [](auto &obj) { return &obj.outerDomainValue; };
   static auto axes = [](auto &obj) { return &obj.axes; };
   static auto function1ds = [](auto &obj) { return &obj.function1ds; };
   static auto uncertainty = [](auto &obj) { return &obj.uncertainty; };
}

using CPPAxes = containers::Axes;
using CPPFunction1ds = containers::Function1ds;
using CPPUncertainty = containers::Uncertainty;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstRegions1d
Regions1dDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Regions1d
Regions1dDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstRegions1d
Regions1dCreateConst(
   const XMLName label,
   const Float64 outerDomainValue,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstFunction1ds function1ds,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2Regions1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      outerDomainValue,
      detail::tocpp<CPPAxes>(axes),
      detail::tocpp<CPPFunction1ds>(function1ds),
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Create, general
Handle2Regions1d
Regions1dCreate(
   const XMLName label,
   const Float64 outerDomainValue,
   ConstHandle2ConstAxes axes,
   ConstHandle2ConstFunction1ds function1ds,
   ConstHandle2ConstUncertainty uncertainty
) {
   ConstHandle2Regions1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      outerDomainValue,
      detail::tocpp<CPPAxes>(axes),
      detail::tocpp<CPPFunction1ds>(function1ds),
      detail::tocpp<CPPUncertainty>(uncertainty)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
Regions1dAssign(ConstHandle2Regions1d This, ConstHandle2ConstRegions1d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Regions1dDelete(ConstHandle2ConstRegions1d This)
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
Regions1dRead(ConstHandle2Regions1d This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Regions1dWrite(ConstHandle2ConstRegions1d This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
Regions1dPrint(ConstHandle2ConstRegions1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
Regions1dPrintXML(ConstHandle2ConstRegions1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
Regions1dPrintJSON(ConstHandle2ConstRegions1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
Regions1dLabelHas(ConstHandle2ConstRegions1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
Regions1dLabelGet(ConstHandle2ConstRegions1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
Regions1dLabelSet(ConstHandle2Regions1d This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: outerDomainValue
// -----------------------------------------------------------------------------

// Has
int
Regions1dOuterDomainValueHas(ConstHandle2ConstRegions1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueHas", This, extract::outerDomainValue);
}

// Get
// Returns by value
Float64
Regions1dOuterDomainValueGet(ConstHandle2ConstRegions1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueGet", This, extract::outerDomainValue);
}

// Set
void
Regions1dOuterDomainValueSet(ConstHandle2Regions1d This, const Float64 outerDomainValue)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"OuterDomainValueSet", This, extract::outerDomainValue, outerDomainValue);
}


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// Has
int
Regions1dAxesHas(ConstHandle2ConstRegions1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxesHas", This, extract::axes);
}

// Get, const
Handle2ConstAxes
Regions1dAxesGetConst(ConstHandle2ConstRegions1d This)
{
   return detail::getField<CPP,Handle2ConstAxes>
      (CLASSNAME, CLASSNAME+"AxesGetConst", This, extract::axes);
}

// Get, non-const
Handle2Axes
Regions1dAxesGet(ConstHandle2Regions1d This)
{
   return detail::getField<CPP,Handle2Axes>
      (CLASSNAME, CLASSNAME+"AxesGet", This, extract::axes);
}

// Set
void
Regions1dAxesSet(ConstHandle2Regions1d This, ConstHandle2ConstAxes axes)
{
   detail::setField<CPP,CPPAxes>
      (CLASSNAME, CLASSNAME+"AxesSet", This, extract::axes, axes);
}


// -----------------------------------------------------------------------------
// Child: function1ds
// -----------------------------------------------------------------------------

// Has
int
Regions1dFunction1dsHas(ConstHandle2ConstRegions1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Function1dsHas", This, extract::function1ds);
}

// Get, const
Handle2ConstFunction1ds
Regions1dFunction1dsGetConst(ConstHandle2ConstRegions1d This)
{
   return detail::getField<CPP,Handle2ConstFunction1ds>
      (CLASSNAME, CLASSNAME+"Function1dsGetConst", This, extract::function1ds);
}

// Get, non-const
Handle2Function1ds
Regions1dFunction1dsGet(ConstHandle2Regions1d This)
{
   return detail::getField<CPP,Handle2Function1ds>
      (CLASSNAME, CLASSNAME+"Function1dsGet", This, extract::function1ds);
}

// Set
void
Regions1dFunction1dsSet(ConstHandle2Regions1d This, ConstHandle2ConstFunction1ds function1ds)
{
   detail::setField<CPP,CPPFunction1ds>
      (CLASSNAME, CLASSNAME+"Function1dsSet", This, extract::function1ds, function1ds);
}


// -----------------------------------------------------------------------------
// Child: uncertainty
// -----------------------------------------------------------------------------

// Has
int
Regions1dUncertaintyHas(ConstHandle2ConstRegions1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UncertaintyHas", This, extract::uncertainty);
}

// Get, const
Handle2ConstUncertainty
Regions1dUncertaintyGetConst(ConstHandle2ConstRegions1d This)
{
   return detail::getField<CPP,Handle2ConstUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGetConst", This, extract::uncertainty);
}

// Get, non-const
Handle2Uncertainty
Regions1dUncertaintyGet(ConstHandle2Regions1d This)
{
   return detail::getField<CPP,Handle2Uncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintyGet", This, extract::uncertainty);
}

// Set
void
Regions1dUncertaintySet(ConstHandle2Regions1d This, ConstHandle2ConstUncertainty uncertainty)
{
   detail::setField<CPP,CPPUncertainty>
      (CLASSNAME, CLASSNAME+"UncertaintySet", This, extract::uncertainty, uncertainty);
}
