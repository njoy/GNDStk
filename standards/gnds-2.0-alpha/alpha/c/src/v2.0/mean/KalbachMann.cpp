
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/mean/KalbachMann.hpp"
#include "KalbachMann.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = KalbachMannClass;
using CPP = multigroup::KalbachMann;

static const std::string CLASSNAME = "KalbachMann";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto productFrame = [](auto &obj) { return &obj.productFrame; };
   static auto f = [](auto &obj) { return &obj.f; };
   static auto r = [](auto &obj) { return &obj.r; };
}

using CPPF = mean::F;
using CPPR = mean::R;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstKalbachMann
KalbachMannDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2KalbachMann
KalbachMannDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstKalbachMann
KalbachMannCreateConst(
   const char *const label,
   const char *const productFrame,
   ConstHandle2ConstF f,
   ConstHandle2ConstR r
) {
   ConstHandle2KalbachMann handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      productFrame,
      detail::tocpp<CPPF>(f),
      detail::tocpp<CPPR>(r)
   );
   return handle;
}

// Create, general
Handle2KalbachMann
KalbachMannCreate(
   const char *const label,
   const char *const productFrame,
   ConstHandle2ConstF f,
   ConstHandle2ConstR r
) {
   ConstHandle2KalbachMann handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      productFrame,
      detail::tocpp<CPPF>(f),
      detail::tocpp<CPPR>(r)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
KalbachMannAssign(ConstHandle2KalbachMann This, ConstHandle2ConstKalbachMann from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
KalbachMannDelete(ConstHandle2ConstKalbachMann This)
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
KalbachMannRead(ConstHandle2KalbachMann This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
KalbachMannWrite(ConstHandle2ConstKalbachMann This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
KalbachMannPrint(ConstHandle2ConstKalbachMann This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
KalbachMannPrintXML(ConstHandle2ConstKalbachMann This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
KalbachMannPrintJSON(ConstHandle2ConstKalbachMann This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
KalbachMannLabelHas(ConstHandle2ConstKalbachMann This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
const char *
KalbachMannLabelGet(ConstHandle2ConstKalbachMann This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
KalbachMannLabelSet(ConstHandle2KalbachMann This, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// Has
int
KalbachMannProductFrameHas(ConstHandle2ConstKalbachMann This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameHas", This, extract::productFrame);
}

// Get
// Returns by value
const char *
KalbachMannProductFrameGet(ConstHandle2ConstKalbachMann This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameGet", This, extract::productFrame);
}

// Set
void
KalbachMannProductFrameSet(ConstHandle2KalbachMann This, const char *const productFrame)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameSet", This, extract::productFrame, productFrame);
}


// -----------------------------------------------------------------------------
// Child: f
// -----------------------------------------------------------------------------

// Has
int
KalbachMannFHas(ConstHandle2ConstKalbachMann This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FHas", This, extract::f);
}

// Get, const
Handle2ConstF
KalbachMannFGetConst(ConstHandle2ConstKalbachMann This)
{
   return detail::getField<CPP,Handle2ConstF>
      (CLASSNAME, CLASSNAME+"FGetConst", This, extract::f);
}

// Get, non-const
Handle2F
KalbachMannFGet(ConstHandle2KalbachMann This)
{
   return detail::getField<CPP,Handle2F>
      (CLASSNAME, CLASSNAME+"FGet", This, extract::f);
}

// Set
void
KalbachMannFSet(ConstHandle2KalbachMann This, ConstHandle2ConstF f)
{
   detail::setField<CPP,CPPF>
      (CLASSNAME, CLASSNAME+"FSet", This, extract::f, f);
}


// -----------------------------------------------------------------------------
// Child: r
// -----------------------------------------------------------------------------

// Has
int
KalbachMannRHas(ConstHandle2ConstKalbachMann This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RHas", This, extract::r);
}

// Get, const
Handle2ConstR
KalbachMannRGetConst(ConstHandle2ConstKalbachMann This)
{
   return detail::getField<CPP,Handle2ConstR>
      (CLASSNAME, CLASSNAME+"RGetConst", This, extract::r);
}

// Get, non-const
Handle2R
KalbachMannRGet(ConstHandle2KalbachMann This)
{
   return detail::getField<CPP,Handle2R>
      (CLASSNAME, CLASSNAME+"RGet", This, extract::r);
}

// Set
void
KalbachMannRSet(ConstHandle2KalbachMann This, ConstHandle2ConstR r)
{
   detail::setField<CPP,CPPR>
      (CLASSNAME, CLASSNAME+"RSet", This, extract::r, r);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/mean/KalbachMann/src/custom.cpp"
