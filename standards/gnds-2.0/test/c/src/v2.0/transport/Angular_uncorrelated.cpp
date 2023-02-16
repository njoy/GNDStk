
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/Angular_uncorrelated.hpp"
#include "Angular_uncorrelated.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = Angular_uncorrelatedClass;
using CPP = multigroup::Angular_uncorrelated;

static const std::string CLASSNAME = "Angular_uncorrelated";

namespace extract {
   static auto XYs2d = [](auto &obj) { return &obj.XYs2d; };
   static auto isotropic2d = [](auto &obj) { return &obj.isotropic2d; };
   static auto forward = [](auto &obj) { return &obj.forward; };
}

using CPPXYs2d = containers::XYs2d;
using CPPIsotropic2d = transport::Isotropic2d;
using CPPForward = transport::Forward;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAngular_uncorrelated
Angular_uncorrelatedDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Angular_uncorrelated
Angular_uncorrelatedDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAngular_uncorrelated
Angular_uncorrelatedCreateConst(
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstIsotropic2d isotropic2d,
   ConstHandle2ConstForward forward
) {
   ConstHandle2Angular_uncorrelated handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPIsotropic2d>(isotropic2d),
      detail::tocpp<CPPForward>(forward)
   );
   return handle;
}

// Create, general
Handle2Angular_uncorrelated
Angular_uncorrelatedCreate(
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstIsotropic2d isotropic2d,
   ConstHandle2ConstForward forward
) {
   ConstHandle2Angular_uncorrelated handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPIsotropic2d>(isotropic2d),
      detail::tocpp<CPPForward>(forward)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
Angular_uncorrelatedAssign(ConstHandle2Angular_uncorrelated self, ConstHandle2ConstAngular_uncorrelated from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
Angular_uncorrelatedDelete(ConstHandle2ConstAngular_uncorrelated self)
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
Angular_uncorrelatedRead(ConstHandle2Angular_uncorrelated self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
Angular_uncorrelatedWrite(ConstHandle2ConstAngular_uncorrelated self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
Angular_uncorrelatedPrint(ConstHandle2ConstAngular_uncorrelated self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
Angular_uncorrelatedPrintXML(ConstHandle2ConstAngular_uncorrelated self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
Angular_uncorrelatedPrintJSON(ConstHandle2ConstAngular_uncorrelated self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// Has
int
Angular_uncorrelatedXYs2dHas(ConstHandle2ConstAngular_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs2dHas", self, extract::XYs2d);
}

// Get, const
Handle2ConstXYs2d
Angular_uncorrelatedXYs2dGetConst(ConstHandle2ConstAngular_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGetConst", self, extract::XYs2d);
}

// Get, non-const
Handle2XYs2d
Angular_uncorrelatedXYs2dGet(ConstHandle2Angular_uncorrelated self)
{
   return detail::getField<CPP,Handle2XYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGet", self, extract::XYs2d);
}

// Set
void
Angular_uncorrelatedXYs2dSet(ConstHandle2Angular_uncorrelated self, ConstHandle2ConstXYs2d XYs2d)
{
   detail::setField<CPP,CPPXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dSet", self, extract::XYs2d, XYs2d);
}


// -----------------------------------------------------------------------------
// Child: isotropic2d
// -----------------------------------------------------------------------------

// Has
int
Angular_uncorrelatedIsotropic2dHas(ConstHandle2ConstAngular_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Isotropic2dHas", self, extract::isotropic2d);
}

// Get, const
Handle2ConstIsotropic2d
Angular_uncorrelatedIsotropic2dGetConst(ConstHandle2ConstAngular_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstIsotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dGetConst", self, extract::isotropic2d);
}

// Get, non-const
Handle2Isotropic2d
Angular_uncorrelatedIsotropic2dGet(ConstHandle2Angular_uncorrelated self)
{
   return detail::getField<CPP,Handle2Isotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dGet", self, extract::isotropic2d);
}

// Set
void
Angular_uncorrelatedIsotropic2dSet(ConstHandle2Angular_uncorrelated self, ConstHandle2ConstIsotropic2d isotropic2d)
{
   detail::setField<CPP,CPPIsotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dSet", self, extract::isotropic2d, isotropic2d);
}


// -----------------------------------------------------------------------------
// Child: forward
// -----------------------------------------------------------------------------

// Has
int
Angular_uncorrelatedForwardHas(ConstHandle2ConstAngular_uncorrelated self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ForwardHas", self, extract::forward);
}

// Get, const
Handle2ConstForward
Angular_uncorrelatedForwardGetConst(ConstHandle2ConstAngular_uncorrelated self)
{
   return detail::getField<CPP,Handle2ConstForward>
      (CLASSNAME, CLASSNAME+"ForwardGetConst", self, extract::forward);
}

// Get, non-const
Handle2Forward
Angular_uncorrelatedForwardGet(ConstHandle2Angular_uncorrelated self)
{
   return detail::getField<CPP,Handle2Forward>
      (CLASSNAME, CLASSNAME+"ForwardGet", self, extract::forward);
}

// Set
void
Angular_uncorrelatedForwardSet(ConstHandle2Angular_uncorrelated self, ConstHandle2ConstForward forward)
{
   detail::setField<CPP,CPPForward>
      (CLASSNAME, CLASSNAME+"ForwardSet", self, extract::forward, forward);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/Angular_uncorrelated/src/custom.cpp"
