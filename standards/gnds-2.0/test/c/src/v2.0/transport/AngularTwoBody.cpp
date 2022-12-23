
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/AngularTwoBody.hpp"
#include "AngularTwoBody.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = AngularTwoBodyClass;
using CPP = multigroup::AngularTwoBody;

static const std::string CLASSNAME = "AngularTwoBody";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto productFrame = [](auto &obj) { return &obj.productFrame; };
   static auto XYs2d = [](auto &obj) { return &obj.XYs2d; };
   static auto regions2d = [](auto &obj) { return &obj.regions2d; };
   static auto isotropic2d = [](auto &obj) { return &obj.isotropic2d; };
   static auto recoil = [](auto &obj) { return &obj.recoil; };
}

using CPPXYs2d = containers::XYs2d;
using CPPRegions2d = containers::Regions2d;
using CPPIsotropic2d = transport::Isotropic2d;
using CPPRecoil = transport::Recoil;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstAngularTwoBody
AngularTwoBodyDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2AngularTwoBody
AngularTwoBodyDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstAngularTwoBody
AngularTwoBodyCreateConst(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstIsotropic2d isotropic2d,
   ConstHandle2ConstRecoil recoil
) {
   ConstHandle2AngularTwoBody handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      productFrame,
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPRegions2d>(regions2d),
      detail::tocpp<CPPIsotropic2d>(isotropic2d),
      detail::tocpp<CPPRecoil>(recoil)
   );
   return handle;
}

// Create, general
Handle2AngularTwoBody
AngularTwoBodyCreate(
   const XMLName label,
   const XMLName productFrame,
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstIsotropic2d isotropic2d,
   ConstHandle2ConstRecoil recoil
) {
   ConstHandle2AngularTwoBody handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      productFrame,
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPRegions2d>(regions2d),
      detail::tocpp<CPPIsotropic2d>(isotropic2d),
      detail::tocpp<CPPRecoil>(recoil)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AngularTwoBodyAssign(ConstHandle2AngularTwoBody This, ConstHandle2ConstAngularTwoBody from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AngularTwoBodyDelete(ConstHandle2ConstAngularTwoBody This)
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
AngularTwoBodyRead(ConstHandle2AngularTwoBody This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AngularTwoBodyWrite(ConstHandle2ConstAngularTwoBody This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
AngularTwoBodyPrint(ConstHandle2ConstAngularTwoBody This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
AngularTwoBodyPrintXML(ConstHandle2ConstAngularTwoBody This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
AngularTwoBodyPrintJSON(ConstHandle2ConstAngularTwoBody This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyLabelHas(ConstHandle2ConstAngularTwoBody This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
AngularTwoBodyLabelGet(ConstHandle2ConstAngularTwoBody This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
AngularTwoBodyLabelSet(ConstHandle2AngularTwoBody This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyProductFrameHas(ConstHandle2ConstAngularTwoBody This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameHas", This, extract::productFrame);
}

// Get
// Returns by value
XMLName
AngularTwoBodyProductFrameGet(ConstHandle2ConstAngularTwoBody This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameGet", This, extract::productFrame);
}

// Set
void
AngularTwoBodyProductFrameSet(ConstHandle2AngularTwoBody This, const XMLName productFrame)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameSet", This, extract::productFrame, productFrame);
}


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyXYs2dHas(ConstHandle2ConstAngularTwoBody This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs2dHas", This, extract::XYs2d);
}

// Get, const
Handle2ConstXYs2d
AngularTwoBodyXYs2dGetConst(ConstHandle2ConstAngularTwoBody This)
{
   return detail::getField<CPP,Handle2ConstXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGetConst", This, extract::XYs2d);
}

// Get, non-const
Handle2XYs2d
AngularTwoBodyXYs2dGet(ConstHandle2AngularTwoBody This)
{
   return detail::getField<CPP,Handle2XYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGet", This, extract::XYs2d);
}

// Set
void
AngularTwoBodyXYs2dSet(ConstHandle2AngularTwoBody This, ConstHandle2ConstXYs2d XYs2d)
{
   detail::setField<CPP,CPPXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dSet", This, extract::XYs2d, XYs2d);
}


// -----------------------------------------------------------------------------
// Child: regions2d
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyRegions2dHas(ConstHandle2ConstAngularTwoBody This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Regions2dHas", This, extract::regions2d);
}

// Get, const
Handle2ConstRegions2d
AngularTwoBodyRegions2dGetConst(ConstHandle2ConstAngularTwoBody This)
{
   return detail::getField<CPP,Handle2ConstRegions2d>
      (CLASSNAME, CLASSNAME+"Regions2dGetConst", This, extract::regions2d);
}

// Get, non-const
Handle2Regions2d
AngularTwoBodyRegions2dGet(ConstHandle2AngularTwoBody This)
{
   return detail::getField<CPP,Handle2Regions2d>
      (CLASSNAME, CLASSNAME+"Regions2dGet", This, extract::regions2d);
}

// Set
void
AngularTwoBodyRegions2dSet(ConstHandle2AngularTwoBody This, ConstHandle2ConstRegions2d regions2d)
{
   detail::setField<CPP,CPPRegions2d>
      (CLASSNAME, CLASSNAME+"Regions2dSet", This, extract::regions2d, regions2d);
}


// -----------------------------------------------------------------------------
// Child: isotropic2d
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyIsotropic2dHas(ConstHandle2ConstAngularTwoBody This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Isotropic2dHas", This, extract::isotropic2d);
}

// Get, const
Handle2ConstIsotropic2d
AngularTwoBodyIsotropic2dGetConst(ConstHandle2ConstAngularTwoBody This)
{
   return detail::getField<CPP,Handle2ConstIsotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dGetConst", This, extract::isotropic2d);
}

// Get, non-const
Handle2Isotropic2d
AngularTwoBodyIsotropic2dGet(ConstHandle2AngularTwoBody This)
{
   return detail::getField<CPP,Handle2Isotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dGet", This, extract::isotropic2d);
}

// Set
void
AngularTwoBodyIsotropic2dSet(ConstHandle2AngularTwoBody This, ConstHandle2ConstIsotropic2d isotropic2d)
{
   detail::setField<CPP,CPPIsotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dSet", This, extract::isotropic2d, isotropic2d);
}


// -----------------------------------------------------------------------------
// Child: recoil
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyRecoilHas(ConstHandle2ConstAngularTwoBody This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RecoilHas", This, extract::recoil);
}

// Get, const
Handle2ConstRecoil
AngularTwoBodyRecoilGetConst(ConstHandle2ConstAngularTwoBody This)
{
   return detail::getField<CPP,Handle2ConstRecoil>
      (CLASSNAME, CLASSNAME+"RecoilGetConst", This, extract::recoil);
}

// Get, non-const
Handle2Recoil
AngularTwoBodyRecoilGet(ConstHandle2AngularTwoBody This)
{
   return detail::getField<CPP,Handle2Recoil>
      (CLASSNAME, CLASSNAME+"RecoilGet", This, extract::recoil);
}

// Set
void
AngularTwoBodyRecoilSet(ConstHandle2AngularTwoBody This, ConstHandle2ConstRecoil recoil)
{
   detail::setField<CPP,CPPRecoil>
      (CLASSNAME, CLASSNAME+"RecoilSet", This, extract::recoil, recoil);
}
