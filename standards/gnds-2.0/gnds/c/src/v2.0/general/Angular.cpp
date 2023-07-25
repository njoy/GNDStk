
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "gnds/v2.0/general/Angular.hpp"
#include "Angular.h"

using namespace njoy::GNDStk;
using namespace gnds::v2_0;

using C = AngularClass;
using CPP = multigroup::Angular;

static const std::string CLASSNAME = "Angular";

namespace extract {
   static auto isotropic2d = [](auto &obj) { return &obj.isotropic2d; };
   static auto XYs2d = [](auto &obj) { return &obj.XYs2d; };
}

using CPPIsotropic2d = general::Isotropic2d;
using CPPXYs2d = general::XYs2d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAngular
AngularDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Angular
AngularDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAngular
AngularCreateConst(
   ConstHandle2ConstIsotropic2d isotropic2d,
   ConstHandle2ConstXYs2d XYs2d
) {
   ConstHandle2Angular handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPIsotropic2d>(isotropic2d),
      detail::tocpp<CPPXYs2d>(XYs2d)
   );
   return handle;
}

// Create, general
Handle2Angular
AngularCreate(
   ConstHandle2ConstIsotropic2d isotropic2d,
   ConstHandle2ConstXYs2d XYs2d
) {
   ConstHandle2Angular handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPIsotropic2d>(isotropic2d),
      detail::tocpp<CPPXYs2d>(XYs2d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AngularAssign(ConstHandle2Angular self, ConstHandle2ConstAngular from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AngularDelete(ConstHandle2ConstAngular self)
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
AngularRead(ConstHandle2Angular self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AngularWrite(ConstHandle2ConstAngular self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
AngularPrint(ConstHandle2ConstAngular self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
AngularPrintXML(ConstHandle2ConstAngular self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
AngularPrintJSON(ConstHandle2ConstAngular self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: isotropic2d
// -----------------------------------------------------------------------------

// Has
int
AngularIsotropic2dHas(ConstHandle2ConstAngular self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Isotropic2dHas", self, extract::isotropic2d);
}

// Get, const
Handle2ConstIsotropic2d
AngularIsotropic2dGetConst(ConstHandle2ConstAngular self)
{
   return detail::getField<CPP,Handle2ConstIsotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dGetConst", self, extract::isotropic2d);
}

// Get, non-const
Handle2Isotropic2d
AngularIsotropic2dGet(ConstHandle2Angular self)
{
   return detail::getField<CPP,Handle2Isotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dGet", self, extract::isotropic2d);
}

// Set
void
AngularIsotropic2dSet(ConstHandle2Angular self, ConstHandle2ConstIsotropic2d isotropic2d)
{
   detail::setField<CPP,CPPIsotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dSet", self, extract::isotropic2d, isotropic2d);
}


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// Has
int
AngularXYs2dHas(ConstHandle2ConstAngular self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs2dHas", self, extract::XYs2d);
}

// Get, const
Handle2ConstXYs2d
AngularXYs2dGetConst(ConstHandle2ConstAngular self)
{
   return detail::getField<CPP,Handle2ConstXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGetConst", self, extract::XYs2d);
}

// Get, non-const
Handle2XYs2d
AngularXYs2dGet(ConstHandle2Angular self)
{
   return detail::getField<CPP,Handle2XYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGet", self, extract::XYs2d);
}

// Set
void
AngularXYs2dSet(ConstHandle2Angular self, ConstHandle2ConstXYs2d XYs2d)
{
   detail::setField<CPP,CPPXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dSet", self, extract::XYs2d, XYs2d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Angular/src/custom.cpp"
