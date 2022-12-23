
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/fissionTransport/SimpleMaxwellianFission.hpp"
#include "SimpleMaxwellianFission.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = SimpleMaxwellianFissionClass;
using CPP = multigroup::SimpleMaxwellianFission;

static const std::string CLASSNAME = "SimpleMaxwellianFission";

namespace extract {
   static auto U = [](auto &obj) { return &obj.U; };
   static auto theta = [](auto &obj) { return &obj.theta; };
}

using CPPU = transport::U;
using CPPTheta = transport::Theta;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSimpleMaxwellianFission
SimpleMaxwellianFissionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2SimpleMaxwellianFission
SimpleMaxwellianFissionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSimpleMaxwellianFission
SimpleMaxwellianFissionCreateConst(
   ConstHandle2ConstU U,
   ConstHandle2ConstTheta theta
) {
   ConstHandle2SimpleMaxwellianFission handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPU>(U),
      detail::tocpp<CPPTheta>(theta)
   );
   return handle;
}

// Create, general
Handle2SimpleMaxwellianFission
SimpleMaxwellianFissionCreate(
   ConstHandle2ConstU U,
   ConstHandle2ConstTheta theta
) {
   ConstHandle2SimpleMaxwellianFission handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPU>(U),
      detail::tocpp<CPPTheta>(theta)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SimpleMaxwellianFissionAssign(ConstHandle2SimpleMaxwellianFission This, ConstHandle2ConstSimpleMaxwellianFission from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SimpleMaxwellianFissionDelete(ConstHandle2ConstSimpleMaxwellianFission This)
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
SimpleMaxwellianFissionRead(ConstHandle2SimpleMaxwellianFission This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SimpleMaxwellianFissionWrite(ConstHandle2ConstSimpleMaxwellianFission This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
SimpleMaxwellianFissionPrint(ConstHandle2ConstSimpleMaxwellianFission This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
SimpleMaxwellianFissionPrintXML(ConstHandle2ConstSimpleMaxwellianFission This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
SimpleMaxwellianFissionPrintJSON(ConstHandle2ConstSimpleMaxwellianFission This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: U
// -----------------------------------------------------------------------------

// Has
int
SimpleMaxwellianFissionUHas(ConstHandle2ConstSimpleMaxwellianFission This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UHas", This, extract::U);
}

// Get, const
Handle2ConstU
SimpleMaxwellianFissionUGetConst(ConstHandle2ConstSimpleMaxwellianFission This)
{
   return detail::getField<CPP,Handle2ConstU>
      (CLASSNAME, CLASSNAME+"UGetConst", This, extract::U);
}

// Get, non-const
Handle2U
SimpleMaxwellianFissionUGet(ConstHandle2SimpleMaxwellianFission This)
{
   return detail::getField<CPP,Handle2U>
      (CLASSNAME, CLASSNAME+"UGet", This, extract::U);
}

// Set
void
SimpleMaxwellianFissionUSet(ConstHandle2SimpleMaxwellianFission This, ConstHandle2ConstU U)
{
   detail::setField<CPP,CPPU>
      (CLASSNAME, CLASSNAME+"USet", This, extract::U, U);
}


// -----------------------------------------------------------------------------
// Child: theta
// -----------------------------------------------------------------------------

// Has
int
SimpleMaxwellianFissionThetaHas(ConstHandle2ConstSimpleMaxwellianFission This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThetaHas", This, extract::theta);
}

// Get, const
Handle2ConstTheta
SimpleMaxwellianFissionThetaGetConst(ConstHandle2ConstSimpleMaxwellianFission This)
{
   return detail::getField<CPP,Handle2ConstTheta>
      (CLASSNAME, CLASSNAME+"ThetaGetConst", This, extract::theta);
}

// Get, non-const
Handle2Theta
SimpleMaxwellianFissionThetaGet(ConstHandle2SimpleMaxwellianFission This)
{
   return detail::getField<CPP,Handle2Theta>
      (CLASSNAME, CLASSNAME+"ThetaGet", This, extract::theta);
}

// Set
void
SimpleMaxwellianFissionThetaSet(ConstHandle2SimpleMaxwellianFission This, ConstHandle2ConstTheta theta)
{
   detail::setField<CPP,CPPTheta>
      (CLASSNAME, CLASSNAME+"ThetaSet", This, extract::theta, theta);
}
