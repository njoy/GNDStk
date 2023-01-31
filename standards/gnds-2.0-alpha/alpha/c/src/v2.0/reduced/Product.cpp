
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/reduced/Product.hpp"
#include "Product.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = ProductClass;
using CPP = multigroup::Product;

static const std::string CLASSNAME = "Product";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto pid = [](auto &obj) { return &obj.pid; };
   static auto multiplicity = [](auto &obj) { return &obj.multiplicity; };
   static auto distribution = [](auto &obj) { return &obj.distribution; };
}

using CPPMultiplicity = common::Multiplicity;
using CPPDistribution = reduced::Distribution;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstProduct
ProductDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Product
ProductDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstProduct
ProductCreateConst(
   const char *const label,
   const char *const pid,
   ConstHandle2ConstMultiplicity multiplicity,
   ConstHandle2ConstDistribution distribution
) {
   ConstHandle2Product handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      pid,
      detail::tocpp<CPPMultiplicity>(multiplicity),
      detail::tocpp<CPPDistribution>(distribution)
   );
   return handle;
}

// Create, general
Handle2Product
ProductCreate(
   const char *const label,
   const char *const pid,
   ConstHandle2ConstMultiplicity multiplicity,
   ConstHandle2ConstDistribution distribution
) {
   ConstHandle2Product handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      pid,
      detail::tocpp<CPPMultiplicity>(multiplicity),
      detail::tocpp<CPPDistribution>(distribution)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ProductAssign(ConstHandle2Product This, ConstHandle2ConstProduct from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ProductDelete(ConstHandle2ConstProduct This)
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
ProductRead(ConstHandle2Product This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ProductWrite(ConstHandle2ConstProduct This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ProductPrint(ConstHandle2ConstProduct This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ProductPrintXML(ConstHandle2ConstProduct This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ProductPrintJSON(ConstHandle2ConstProduct This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ProductLabelHas(ConstHandle2ConstProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
const char *
ProductLabelGet(ConstHandle2ConstProduct This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
ProductLabelSet(ConstHandle2Product This, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// Has
int
ProductPidHas(ConstHandle2ConstProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PidHas", This, extract::pid);
}

// Get
// Returns by value
const char *
ProductPidGet(ConstHandle2ConstProduct This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PidGet", This, extract::pid);
}

// Set
void
ProductPidSet(ConstHandle2Product This, const char *const pid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PidSet", This, extract::pid, pid);
}


// -----------------------------------------------------------------------------
// Child: multiplicity
// -----------------------------------------------------------------------------

// Has
int
ProductMultiplicityHas(ConstHandle2ConstProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MultiplicityHas", This, extract::multiplicity);
}

// Get, const
Handle2ConstMultiplicity
ProductMultiplicityGetConst(ConstHandle2ConstProduct This)
{
   return detail::getField<CPP,Handle2ConstMultiplicity>
      (CLASSNAME, CLASSNAME+"MultiplicityGetConst", This, extract::multiplicity);
}

// Get, non-const
Handle2Multiplicity
ProductMultiplicityGet(ConstHandle2Product This)
{
   return detail::getField<CPP,Handle2Multiplicity>
      (CLASSNAME, CLASSNAME+"MultiplicityGet", This, extract::multiplicity);
}

// Set
void
ProductMultiplicitySet(ConstHandle2Product This, ConstHandle2ConstMultiplicity multiplicity)
{
   detail::setField<CPP,CPPMultiplicity>
      (CLASSNAME, CLASSNAME+"MultiplicitySet", This, extract::multiplicity, multiplicity);
}


// -----------------------------------------------------------------------------
// Child: distribution
// -----------------------------------------------------------------------------

// Has
int
ProductDistributionHas(ConstHandle2ConstProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DistributionHas", This, extract::distribution);
}

// Get, const
Handle2ConstDistribution
ProductDistributionGetConst(ConstHandle2ConstProduct This)
{
   return detail::getField<CPP,Handle2ConstDistribution>
      (CLASSNAME, CLASSNAME+"DistributionGetConst", This, extract::distribution);
}

// Get, non-const
Handle2Distribution
ProductDistributionGet(ConstHandle2Product This)
{
   return detail::getField<CPP,Handle2Distribution>
      (CLASSNAME, CLASSNAME+"DistributionGet", This, extract::distribution);
}

// Set
void
ProductDistributionSet(ConstHandle2Product This, ConstHandle2ConstDistribution distribution)
{
   detail::setField<CPP,CPPDistribution>
      (CLASSNAME, CLASSNAME+"DistributionSet", This, extract::distribution, distribution);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/reduced/Product/src/custom.cpp"
