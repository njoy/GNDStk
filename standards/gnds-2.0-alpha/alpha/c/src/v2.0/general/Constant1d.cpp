
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/Constant1d.hpp"
#include "Constant1d.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = Constant1dClass;
using CPP = multigroup::Constant1d;

static const std::string CLASSNAME = "Constant1d";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto value = [](auto &obj) { return &obj.value; };
   static auto domainMin = [](auto &obj) { return &obj.domainMin; };
   static auto domainMax = [](auto &obj) { return &obj.domainMax; };
   static auto axes = [](auto &obj) { return &obj.axes; };
}

using CPPAxes = general::Axes;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstConstant1d
Constant1dDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Constant1d
Constant1dDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstConstant1d
Constant1dCreateConst(
   const char *const label,
   const double value,
   const double domainMin,
   const double domainMax,
   ConstHandle2ConstAxes axes
) {
   ConstHandle2Constant1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      value,
      domainMin,
      domainMax,
      detail::tocpp<CPPAxes>(axes)
   );
   return handle;
}

// Create, general
Handle2Constant1d
Constant1dCreate(
   const char *const label,
   const double value,
   const double domainMin,
   const double domainMax,
   ConstHandle2ConstAxes axes
) {
   ConstHandle2Constant1d handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      value,
      domainMin,
      domainMax,
      detail::tocpp<CPPAxes>(axes)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
Constant1dAssign(ConstHandle2Constant1d This, ConstHandle2ConstConstant1d from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Constant1dDelete(ConstHandle2ConstConstant1d This)
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
Constant1dRead(ConstHandle2Constant1d This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Constant1dWrite(ConstHandle2ConstConstant1d This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
Constant1dPrint(ConstHandle2ConstConstant1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
Constant1dPrintXML(ConstHandle2ConstConstant1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
Constant1dPrintJSON(ConstHandle2ConstConstant1d This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
Constant1dLabelHas(ConstHandle2ConstConstant1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
const char *
Constant1dLabelGet(ConstHandle2ConstConstant1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
Constant1dLabelSet(ConstHandle2Constant1d This, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: value
// -----------------------------------------------------------------------------

// Has
int
Constant1dValueHas(ConstHandle2ConstConstant1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ValueHas", This, extract::value);
}

// Get
// Returns by value
double
Constant1dValueGet(ConstHandle2ConstConstant1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ValueGet", This, extract::value);
}

// Set
void
Constant1dValueSet(ConstHandle2Constant1d This, const double value)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ValueSet", This, extract::value, value);
}


// -----------------------------------------------------------------------------
// Metadatum: domainMin
// -----------------------------------------------------------------------------

// Has
int
Constant1dDomainMinHas(ConstHandle2ConstConstant1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinHas", This, extract::domainMin);
}

// Get
// Returns by value
double
Constant1dDomainMinGet(ConstHandle2ConstConstant1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinGet", This, extract::domainMin);
}

// Set
void
Constant1dDomainMinSet(ConstHandle2Constant1d This, const double domainMin)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMinSet", This, extract::domainMin, domainMin);
}


// -----------------------------------------------------------------------------
// Metadatum: domainMax
// -----------------------------------------------------------------------------

// Has
int
Constant1dDomainMaxHas(ConstHandle2ConstConstant1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxHas", This, extract::domainMax);
}

// Get
// Returns by value
double
Constant1dDomainMaxGet(ConstHandle2ConstConstant1d This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxGet", This, extract::domainMax);
}

// Set
void
Constant1dDomainMaxSet(ConstHandle2Constant1d This, const double domainMax)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DomainMaxSet", This, extract::domainMax, domainMax);
}


// -----------------------------------------------------------------------------
// Child: axes
// -----------------------------------------------------------------------------

// Has
int
Constant1dAxesHas(ConstHandle2ConstConstant1d This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"AxesHas", This, extract::axes);
}

// Get, const
Handle2ConstAxes
Constant1dAxesGetConst(ConstHandle2ConstConstant1d This)
{
   return detail::getField<CPP,Handle2ConstAxes>
      (CLASSNAME, CLASSNAME+"AxesGetConst", This, extract::axes);
}

// Get, non-const
Handle2Axes
Constant1dAxesGet(ConstHandle2Constant1d This)
{
   return detail::getField<CPP,Handle2Axes>
      (CLASSNAME, CLASSNAME+"AxesGet", This, extract::axes);
}

// Set
void
Constant1dAxesSet(ConstHandle2Constant1d This, ConstHandle2ConstAxes axes)
{
   detail::setField<CPP,CPPAxes>
      (CLASSNAME, CLASSNAME+"AxesSet", This, extract::axes, axes);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Constant1d/src/custom.cpp"
