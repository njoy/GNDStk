
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/general/Multiplicity.hpp"
#include "Multiplicity.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = MultiplicityClass;
using CPP = multigroup::Multiplicity;

static const std::string CLASSNAME = "Multiplicity";

namespace extract {
   static auto constant1d = [](auto &obj) { return &obj.constant1d; };
   static auto XYs1d = [](auto &obj) { return &obj.XYs1d; };
   static auto regions1d = [](auto &obj) { return &obj.regions1d; };
   static auto polynomial1d = [](auto &obj) { return &obj.polynomial1d; };
   static auto reference = [](auto &obj) { return &obj.reference; };
   static auto branching1d = [](auto &obj) { return &obj.branching1d; };
   static auto branching3d = [](auto &obj) { return &obj.branching3d; };
   static auto unspecified = [](auto &obj) { return &obj.unspecified; };
}

using CPPConstant1d = general::Constant1d;
using CPPXYs1d = general::XYs1d;
using CPPRegions1d = general::Regions1d;
using CPPPolynomial1d = general::Polynomial1d;
using CPPReference = general::Reference;
using CPPBranching1d = general::Branching1d;
using CPPBranching3d = general::Branching3d;
using CPPUnspecified = general::Unspecified;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstMultiplicity
MultiplicityDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Multiplicity
MultiplicityDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstMultiplicity
MultiplicityCreateConst(
   ConstHandle2ConstConstant1d constant1d,
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d,
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstReference reference,
   ConstHandle2ConstBranching1d branching1d,
   ConstHandle2ConstBranching3d branching3d,
   ConstHandle2ConstUnspecified unspecified
) {
   ConstHandle2Multiplicity handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPConstant1d>(constant1d),
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPRegions1d>(regions1d),
      detail::tocpp<CPPPolynomial1d>(polynomial1d),
      detail::tocpp<CPPReference>(reference),
      detail::tocpp<CPPBranching1d>(branching1d),
      detail::tocpp<CPPBranching3d>(branching3d),
      detail::tocpp<CPPUnspecified>(unspecified)
   );
   return handle;
}

// Create, general
Handle2Multiplicity
MultiplicityCreate(
   ConstHandle2ConstConstant1d constant1d,
   ConstHandle2ConstXYs1d XYs1d,
   ConstHandle2ConstRegions1d regions1d,
   ConstHandle2ConstPolynomial1d polynomial1d,
   ConstHandle2ConstReference reference,
   ConstHandle2ConstBranching1d branching1d,
   ConstHandle2ConstBranching3d branching3d,
   ConstHandle2ConstUnspecified unspecified
) {
   ConstHandle2Multiplicity handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPConstant1d>(constant1d),
      detail::tocpp<CPPXYs1d>(XYs1d),
      detail::tocpp<CPPRegions1d>(regions1d),
      detail::tocpp<CPPPolynomial1d>(polynomial1d),
      detail::tocpp<CPPReference>(reference),
      detail::tocpp<CPPBranching1d>(branching1d),
      detail::tocpp<CPPBranching3d>(branching3d),
      detail::tocpp<CPPUnspecified>(unspecified)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
MultiplicityAssign(ConstHandle2Multiplicity self, ConstHandle2ConstMultiplicity from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
MultiplicityDelete(ConstHandle2ConstMultiplicity self)
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
MultiplicityRead(ConstHandle2Multiplicity self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
MultiplicityWrite(ConstHandle2ConstMultiplicity self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
MultiplicityPrint(ConstHandle2ConstMultiplicity self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
MultiplicityPrintXML(ConstHandle2ConstMultiplicity self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
MultiplicityPrintJSON(ConstHandle2ConstMultiplicity self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: constant1d
// -----------------------------------------------------------------------------

// Has
int
MultiplicityConstant1dHas(ConstHandle2ConstMultiplicity self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Constant1dHas", self, extract::constant1d);
}

// Get, const
Handle2ConstConstant1d
MultiplicityConstant1dGetConst(ConstHandle2ConstMultiplicity self)
{
   return detail::getField<CPP,Handle2ConstConstant1d>
      (CLASSNAME, CLASSNAME+"Constant1dGetConst", self, extract::constant1d);
}

// Get, non-const
Handle2Constant1d
MultiplicityConstant1dGet(ConstHandle2Multiplicity self)
{
   return detail::getField<CPP,Handle2Constant1d>
      (CLASSNAME, CLASSNAME+"Constant1dGet", self, extract::constant1d);
}

// Set
void
MultiplicityConstant1dSet(ConstHandle2Multiplicity self, ConstHandle2ConstConstant1d constant1d)
{
   detail::setField<CPP,CPPConstant1d>
      (CLASSNAME, CLASSNAME+"Constant1dSet", self, extract::constant1d, constant1d);
}


// -----------------------------------------------------------------------------
// Child: XYs1d
// -----------------------------------------------------------------------------

// Has
int
MultiplicityXYs1dHas(ConstHandle2ConstMultiplicity self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"XYs1dHas", self, extract::XYs1d);
}

// Get, const
Handle2ConstXYs1d
MultiplicityXYs1dGetConst(ConstHandle2ConstMultiplicity self)
{
   return detail::getField<CPP,Handle2ConstXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGetConst", self, extract::XYs1d);
}

// Get, non-const
Handle2XYs1d
MultiplicityXYs1dGet(ConstHandle2Multiplicity self)
{
   return detail::getField<CPP,Handle2XYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dGet", self, extract::XYs1d);
}

// Set
void
MultiplicityXYs1dSet(ConstHandle2Multiplicity self, ConstHandle2ConstXYs1d XYs1d)
{
   detail::setField<CPP,CPPXYs1d>
      (CLASSNAME, CLASSNAME+"XYs1dSet", self, extract::XYs1d, XYs1d);
}


// -----------------------------------------------------------------------------
// Child: regions1d
// -----------------------------------------------------------------------------

// Has
int
MultiplicityRegions1dHas(ConstHandle2ConstMultiplicity self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Regions1dHas", self, extract::regions1d);
}

// Get, const
Handle2ConstRegions1d
MultiplicityRegions1dGetConst(ConstHandle2ConstMultiplicity self)
{
   return detail::getField<CPP,Handle2ConstRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGetConst", self, extract::regions1d);
}

// Get, non-const
Handle2Regions1d
MultiplicityRegions1dGet(ConstHandle2Multiplicity self)
{
   return detail::getField<CPP,Handle2Regions1d>
      (CLASSNAME, CLASSNAME+"Regions1dGet", self, extract::regions1d);
}

// Set
void
MultiplicityRegions1dSet(ConstHandle2Multiplicity self, ConstHandle2ConstRegions1d regions1d)
{
   detail::setField<CPP,CPPRegions1d>
      (CLASSNAME, CLASSNAME+"Regions1dSet", self, extract::regions1d, regions1d);
}


// -----------------------------------------------------------------------------
// Child: polynomial1d
// -----------------------------------------------------------------------------

// Has
int
MultiplicityPolynomial1dHas(ConstHandle2ConstMultiplicity self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Polynomial1dHas", self, extract::polynomial1d);
}

// Get, const
Handle2ConstPolynomial1d
MultiplicityPolynomial1dGetConst(ConstHandle2ConstMultiplicity self)
{
   return detail::getField<CPP,Handle2ConstPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGetConst", self, extract::polynomial1d);
}

// Get, non-const
Handle2Polynomial1d
MultiplicityPolynomial1dGet(ConstHandle2Multiplicity self)
{
   return detail::getField<CPP,Handle2Polynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dGet", self, extract::polynomial1d);
}

// Set
void
MultiplicityPolynomial1dSet(ConstHandle2Multiplicity self, ConstHandle2ConstPolynomial1d polynomial1d)
{
   detail::setField<CPP,CPPPolynomial1d>
      (CLASSNAME, CLASSNAME+"Polynomial1dSet", self, extract::polynomial1d, polynomial1d);
}


// -----------------------------------------------------------------------------
// Child: reference
// -----------------------------------------------------------------------------

// Has
int
MultiplicityReferenceHas(ConstHandle2ConstMultiplicity self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ReferenceHas", self, extract::reference);
}

// Get, const
Handle2ConstReference
MultiplicityReferenceGetConst(ConstHandle2ConstMultiplicity self)
{
   return detail::getField<CPP,Handle2ConstReference>
      (CLASSNAME, CLASSNAME+"ReferenceGetConst", self, extract::reference);
}

// Get, non-const
Handle2Reference
MultiplicityReferenceGet(ConstHandle2Multiplicity self)
{
   return detail::getField<CPP,Handle2Reference>
      (CLASSNAME, CLASSNAME+"ReferenceGet", self, extract::reference);
}

// Set
void
MultiplicityReferenceSet(ConstHandle2Multiplicity self, ConstHandle2ConstReference reference)
{
   detail::setField<CPP,CPPReference>
      (CLASSNAME, CLASSNAME+"ReferenceSet", self, extract::reference, reference);
}


// -----------------------------------------------------------------------------
// Child: branching1d
// -----------------------------------------------------------------------------

// Has
int
MultiplicityBranching1dHas(ConstHandle2ConstMultiplicity self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Branching1dHas", self, extract::branching1d);
}

// Get, const
Handle2ConstBranching1d
MultiplicityBranching1dGetConst(ConstHandle2ConstMultiplicity self)
{
   return detail::getField<CPP,Handle2ConstBranching1d>
      (CLASSNAME, CLASSNAME+"Branching1dGetConst", self, extract::branching1d);
}

// Get, non-const
Handle2Branching1d
MultiplicityBranching1dGet(ConstHandle2Multiplicity self)
{
   return detail::getField<CPP,Handle2Branching1d>
      (CLASSNAME, CLASSNAME+"Branching1dGet", self, extract::branching1d);
}

// Set
void
MultiplicityBranching1dSet(ConstHandle2Multiplicity self, ConstHandle2ConstBranching1d branching1d)
{
   detail::setField<CPP,CPPBranching1d>
      (CLASSNAME, CLASSNAME+"Branching1dSet", self, extract::branching1d, branching1d);
}


// -----------------------------------------------------------------------------
// Child: branching3d
// -----------------------------------------------------------------------------

// Has
int
MultiplicityBranching3dHas(ConstHandle2ConstMultiplicity self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Branching3dHas", self, extract::branching3d);
}

// Get, const
Handle2ConstBranching3d
MultiplicityBranching3dGetConst(ConstHandle2ConstMultiplicity self)
{
   return detail::getField<CPP,Handle2ConstBranching3d>
      (CLASSNAME, CLASSNAME+"Branching3dGetConst", self, extract::branching3d);
}

// Get, non-const
Handle2Branching3d
MultiplicityBranching3dGet(ConstHandle2Multiplicity self)
{
   return detail::getField<CPP,Handle2Branching3d>
      (CLASSNAME, CLASSNAME+"Branching3dGet", self, extract::branching3d);
}

// Set
void
MultiplicityBranching3dSet(ConstHandle2Multiplicity self, ConstHandle2ConstBranching3d branching3d)
{
   detail::setField<CPP,CPPBranching3d>
      (CLASSNAME, CLASSNAME+"Branching3dSet", self, extract::branching3d, branching3d);
}


// -----------------------------------------------------------------------------
// Child: unspecified
// -----------------------------------------------------------------------------

// Has
int
MultiplicityUnspecifiedHas(ConstHandle2ConstMultiplicity self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UnspecifiedHas", self, extract::unspecified);
}

// Get, const
Handle2ConstUnspecified
MultiplicityUnspecifiedGetConst(ConstHandle2ConstMultiplicity self)
{
   return detail::getField<CPP,Handle2ConstUnspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedGetConst", self, extract::unspecified);
}

// Get, non-const
Handle2Unspecified
MultiplicityUnspecifiedGet(ConstHandle2Multiplicity self)
{
   return detail::getField<CPP,Handle2Unspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedGet", self, extract::unspecified);
}

// Set
void
MultiplicityUnspecifiedSet(ConstHandle2Multiplicity self, ConstHandle2ConstUnspecified unspecified)
{
   detail::setField<CPP,CPPUnspecified>
      (CLASSNAME, CLASSNAME+"UnspecifiedSet", self, extract::unspecified, unspecified);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Multiplicity/src/custom.cpp"
