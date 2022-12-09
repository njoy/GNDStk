
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/EnergyAngular.hpp"
#include "EnergyAngular.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = EnergyAngularClass;
using CPP = multigroup::EnergyAngular;

static const std::string CLASSNAME = "EnergyAngular";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto productFrame = [](auto &obj) { return &obj.productFrame; };
   static auto XYs3d = [](auto &obj) { return &obj.XYs3d; };
}

using CPPXYs3d = containers::XYs3d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstEnergyAngular
EnergyAngularDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2EnergyAngular
EnergyAngularDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstEnergyAngular
EnergyAngularCreateConst(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstXYs3d XYs3d
) {
   ConstHandle2EnergyAngular handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      productFrame,
      detail::tocpp<CPPXYs3d>(XYs3d)
   );
   return handle;
}

// Create, general
Handle2EnergyAngular
EnergyAngularCreate(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstXYs3d XYs3d
) {
   ConstHandle2EnergyAngular handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      productFrame,
      detail::tocpp<CPPXYs3d>(XYs3d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
EnergyAngularAssign(ConstHandle2EnergyAngular This, ConstHandle2ConstEnergyAngular from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
EnergyAngularDelete(ConstHandle2ConstEnergyAngular This)
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
EnergyAngularRead(ConstHandle2EnergyAngular This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
EnergyAngularWrite(ConstHandle2ConstEnergyAngular This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
EnergyAngularPrint(ConstHandle2ConstEnergyAngular This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
EnergyAngularPrintXML(ConstHandle2ConstEnergyAngular This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
EnergyAngularPrintJSON(ConstHandle2ConstEnergyAngular This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
EnergyAngularLabelHas(ConstHandle2ConstEnergyAngular This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
EnergyAngularLabelGet(ConstHandle2ConstEnergyAngular This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
EnergyAngularLabelSet(ConstHandle2EnergyAngular This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// Has
int
EnergyAngularProductFrameHas(ConstHandle2ConstEnergyAngular This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameHas", This, extract::productFrame);
}

// Get
// Returns by value
XMLName
EnergyAngularProductFrameGet(ConstHandle2ConstEnergyAngular This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameGet", This, extract::productFrame);
}

// Set
void
EnergyAngularProductFrameSet(ConstHandle2EnergyAngular This, const XMLName productFrame)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameSet", This, extract::productFrame, productFrame);
}


// -----------------------------------------------------------------------------
// Child: XYs3d
// -----------------------------------------------------------------------------

// Has
int
EnergyAngularXYs3dHas(ConstHandle2ConstEnergyAngular This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs3dHas", This, extract::XYs3d);
}

// Get, const
Handle2ConstXYs3d
EnergyAngularXYs3dGetConst(ConstHandle2ConstEnergyAngular This)
{
   return detail::getField<CPP,Handle2ConstXYs3d>
      (CLASSNAME, CLASSNAME+"XYs3dGetConst", This, extract::XYs3d);
}

// Get, non-const
Handle2XYs3d
EnergyAngularXYs3dGet(ConstHandle2EnergyAngular This)
{
   return detail::getField<CPP,Handle2XYs3d>
      (CLASSNAME, CLASSNAME+"XYs3dGet", This, extract::XYs3d);
}

// Set
void
EnergyAngularXYs3dSet(ConstHandle2EnergyAngular This, ConstHandle2ConstXYs3d XYs3d)
{
   detail::setField<CPP,CPPXYs3d>
      (CLASSNAME, CLASSNAME+"XYs3dSet", This, extract::XYs3d, XYs3d);
}
