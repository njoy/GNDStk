
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/AngularTwoBody.hpp"
#include "AngularTwoBody.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = AngularTwoBodyClass;
using CPP = multigroup::AngularTwoBody;

static const std::string CLASSNAME = "AngularTwoBody";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto productFrame = [](auto &obj) { return &obj.productFrame; };
   static auto XYs2d = [](auto &obj) { return &obj.XYs2d; };
   static auto regions2d = [](auto &obj) { return &obj.regions2d; };
   static auto recoil = [](auto &obj) { return &obj.recoil; };
   static auto isotropic2d = [](auto &obj) { return &obj.isotropic2d; };
}

using CPPXYs2d = general::XYs2d;
using CPPRegions2d = general::Regions2d;
using CPPRecoil = general::Recoil;
using CPPIsotropic2d = general::Isotropic2d;


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
   const char *const label,
   const char *const productFrame,
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstRecoil recoil,
   ConstHandle2ConstIsotropic2d isotropic2d
) {
   ConstHandle2AngularTwoBody handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      productFrame,
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPRegions2d>(regions2d),
      detail::tocpp<CPPRecoil>(recoil),
      detail::tocpp<CPPIsotropic2d>(isotropic2d)
   );
   return handle;
}

// Create, general
Handle2AngularTwoBody
AngularTwoBodyCreate(
   const char *const label,
   const char *const productFrame,
   ConstHandle2ConstXYs2d XYs2d,
   ConstHandle2ConstRegions2d regions2d,
   ConstHandle2ConstRecoil recoil,
   ConstHandle2ConstIsotropic2d isotropic2d
) {
   ConstHandle2AngularTwoBody handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      productFrame,
      detail::tocpp<CPPXYs2d>(XYs2d),
      detail::tocpp<CPPRegions2d>(regions2d),
      detail::tocpp<CPPRecoil>(recoil),
      detail::tocpp<CPPIsotropic2d>(isotropic2d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
AngularTwoBodyAssign(ConstHandle2AngularTwoBody self, ConstHandle2ConstAngularTwoBody from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
AngularTwoBodyDelete(ConstHandle2ConstAngularTwoBody self)
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
AngularTwoBodyRead(ConstHandle2AngularTwoBody self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
AngularTwoBodyWrite(ConstHandle2ConstAngularTwoBody self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
AngularTwoBodyPrint(ConstHandle2ConstAngularTwoBody self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
AngularTwoBodyPrintXML(ConstHandle2ConstAngularTwoBody self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
AngularTwoBodyPrintJSON(ConstHandle2ConstAngularTwoBody self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyLabelHas(ConstHandle2ConstAngularTwoBody self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
AngularTwoBodyLabelGet(ConstHandle2ConstAngularTwoBody self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
AngularTwoBodyLabelSet(ConstHandle2AngularTwoBody self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyProductFrameHas(ConstHandle2ConstAngularTwoBody self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameHas", self, extract::productFrame);
}

// Get
// Returns by value
const char *
AngularTwoBodyProductFrameGet(ConstHandle2ConstAngularTwoBody self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameGet", self, extract::productFrame);
}

// Set
void
AngularTwoBodyProductFrameSet(ConstHandle2AngularTwoBody self, const char *const productFrame)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameSet", self, extract::productFrame, productFrame);
}


// -----------------------------------------------------------------------------
// Child: XYs2d
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyXYs2dHas(ConstHandle2ConstAngularTwoBody self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs2dHas", self, extract::XYs2d);
}

// Get, const
Handle2ConstXYs2d
AngularTwoBodyXYs2dGetConst(ConstHandle2ConstAngularTwoBody self)
{
   return detail::getField<CPP,Handle2ConstXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGetConst", self, extract::XYs2d);
}

// Get
Handle2XYs2d
AngularTwoBodyXYs2dGet(ConstHandle2AngularTwoBody self)
{
   return detail::getField<CPP,Handle2XYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dGet", self, extract::XYs2d);
}

// Set
void
AngularTwoBodyXYs2dSet(ConstHandle2AngularTwoBody self, ConstHandle2ConstXYs2d XYs2d)
{
   detail::setField<CPP,CPPXYs2d>
      (CLASSNAME, CLASSNAME+"XYs2dSet", self, extract::XYs2d, XYs2d);
}


// -----------------------------------------------------------------------------
// Child: regions2d
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyRegions2dHas(ConstHandle2ConstAngularTwoBody self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Regions2dHas", self, extract::regions2d);
}

// Get, const
Handle2ConstRegions2d
AngularTwoBodyRegions2dGetConst(ConstHandle2ConstAngularTwoBody self)
{
   return detail::getField<CPP,Handle2ConstRegions2d>
      (CLASSNAME, CLASSNAME+"Regions2dGetConst", self, extract::regions2d);
}

// Get
Handle2Regions2d
AngularTwoBodyRegions2dGet(ConstHandle2AngularTwoBody self)
{
   return detail::getField<CPP,Handle2Regions2d>
      (CLASSNAME, CLASSNAME+"Regions2dGet", self, extract::regions2d);
}

// Set
void
AngularTwoBodyRegions2dSet(ConstHandle2AngularTwoBody self, ConstHandle2ConstRegions2d regions2d)
{
   detail::setField<CPP,CPPRegions2d>
      (CLASSNAME, CLASSNAME+"Regions2dSet", self, extract::regions2d, regions2d);
}


// -----------------------------------------------------------------------------
// Child: recoil
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyRecoilHas(ConstHandle2ConstAngularTwoBody self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RecoilHas", self, extract::recoil);
}

// Get, const
Handle2ConstRecoil
AngularTwoBodyRecoilGetConst(ConstHandle2ConstAngularTwoBody self)
{
   return detail::getField<CPP,Handle2ConstRecoil>
      (CLASSNAME, CLASSNAME+"RecoilGetConst", self, extract::recoil);
}

// Get
Handle2Recoil
AngularTwoBodyRecoilGet(ConstHandle2AngularTwoBody self)
{
   return detail::getField<CPP,Handle2Recoil>
      (CLASSNAME, CLASSNAME+"RecoilGet", self, extract::recoil);
}

// Set
void
AngularTwoBodyRecoilSet(ConstHandle2AngularTwoBody self, ConstHandle2ConstRecoil recoil)
{
   detail::setField<CPP,CPPRecoil>
      (CLASSNAME, CLASSNAME+"RecoilSet", self, extract::recoil, recoil);
}


// -----------------------------------------------------------------------------
// Child: isotropic2d
// -----------------------------------------------------------------------------

// Has
int
AngularTwoBodyIsotropic2dHas(ConstHandle2ConstAngularTwoBody self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Isotropic2dHas", self, extract::isotropic2d);
}

// Get, const
Handle2ConstIsotropic2d
AngularTwoBodyIsotropic2dGetConst(ConstHandle2ConstAngularTwoBody self)
{
   return detail::getField<CPP,Handle2ConstIsotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dGetConst", self, extract::isotropic2d);
}

// Get
Handle2Isotropic2d
AngularTwoBodyIsotropic2dGet(ConstHandle2AngularTwoBody self)
{
   return detail::getField<CPP,Handle2Isotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dGet", self, extract::isotropic2d);
}

// Set
void
AngularTwoBodyIsotropic2dSet(ConstHandle2AngularTwoBody self, ConstHandle2ConstIsotropic2d isotropic2d)
{
   detail::setField<CPP,CPPIsotropic2d>
      (CLASSNAME, CLASSNAME+"Isotropic2dSet", self, extract::isotropic2d, isotropic2d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/AngularTwoBody/src/custom.cpp"
