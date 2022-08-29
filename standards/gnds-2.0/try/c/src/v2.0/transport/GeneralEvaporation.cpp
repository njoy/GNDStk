
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/transport/GeneralEvaporation.hpp"
#include "GeneralEvaporation.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = GeneralEvaporationClass;
using CPP = multigroup::GeneralEvaporation;

static const std::string CLASSNAME = "GeneralEvaporation";

namespace extract {
   static auto U = [](auto &obj) { return &obj.U; };
   static auto g = [](auto &obj) { return &obj.g; };
   static auto theta = [](auto &obj) { return &obj.theta; };
}

using CPPU = transport::U;
using CPPG = transport::G;
using CPPTheta = transport::Theta;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstGeneralEvaporation
GeneralEvaporationDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2GeneralEvaporation
GeneralEvaporationDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstGeneralEvaporation
GeneralEvaporationCreateConst(
   ConstHandle2ConstU U,
   ConstHandle2ConstG g,
   ConstHandle2ConstTheta theta
) {
   ConstHandle2GeneralEvaporation handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPU>(U),
      detail::tocpp<CPPG>(g),
      detail::tocpp<CPPTheta>(theta)
   );
   return handle;
}

// Create, general
Handle2GeneralEvaporation
GeneralEvaporationCreate(
   ConstHandle2ConstU U,
   ConstHandle2ConstG g,
   ConstHandle2ConstTheta theta
) {
   ConstHandle2GeneralEvaporation handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPU>(U),
      detail::tocpp<CPPG>(g),
      detail::tocpp<CPPTheta>(theta)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
GeneralEvaporationAssign(ConstHandle2GeneralEvaporation This, ConstHandle2ConstGeneralEvaporation from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
GeneralEvaporationDelete(ConstHandle2ConstGeneralEvaporation This)
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
GeneralEvaporationRead(ConstHandle2GeneralEvaporation This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
GeneralEvaporationWrite(ConstHandle2ConstGeneralEvaporation This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
GeneralEvaporationPrint(ConstHandle2ConstGeneralEvaporation This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
GeneralEvaporationPrintXML(ConstHandle2ConstGeneralEvaporation This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
GeneralEvaporationPrintJSON(ConstHandle2ConstGeneralEvaporation This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: U
// -----------------------------------------------------------------------------

// Has
int
GeneralEvaporationUHas(ConstHandle2ConstGeneralEvaporation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"UHas", This, extract::U);
}

// Get, const
Handle2ConstU
GeneralEvaporationUGetConst(ConstHandle2ConstGeneralEvaporation This)
{
   return detail::getField<CPP,Handle2ConstU>
      (CLASSNAME, CLASSNAME+"UGetConst", This, extract::U);
}

// Get, non-const
Handle2U
GeneralEvaporationUGet(ConstHandle2GeneralEvaporation This)
{
   return detail::getField<CPP,Handle2U>
      (CLASSNAME, CLASSNAME+"UGet", This, extract::U);
}

// Set
void
GeneralEvaporationUSet(ConstHandle2GeneralEvaporation This, ConstHandle2ConstU U)
{
   detail::setField<CPP,CPPU>
      (CLASSNAME, CLASSNAME+"USet", This, extract::U, U);
}


// -----------------------------------------------------------------------------
// Child: g
// -----------------------------------------------------------------------------

// Has
int
GeneralEvaporationGHas(ConstHandle2ConstGeneralEvaporation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"GHas", This, extract::g);
}

// Get, const
Handle2ConstG
GeneralEvaporationGGetConst(ConstHandle2ConstGeneralEvaporation This)
{
   return detail::getField<CPP,Handle2ConstG>
      (CLASSNAME, CLASSNAME+"GGetConst", This, extract::g);
}

// Get, non-const
Handle2G
GeneralEvaporationGGet(ConstHandle2GeneralEvaporation This)
{
   return detail::getField<CPP,Handle2G>
      (CLASSNAME, CLASSNAME+"GGet", This, extract::g);
}

// Set
void
GeneralEvaporationGSet(ConstHandle2GeneralEvaporation This, ConstHandle2ConstG g)
{
   detail::setField<CPP,CPPG>
      (CLASSNAME, CLASSNAME+"GSet", This, extract::g, g);
}


// -----------------------------------------------------------------------------
// Child: theta
// -----------------------------------------------------------------------------

// Has
int
GeneralEvaporationThetaHas(ConstHandle2ConstGeneralEvaporation This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ThetaHas", This, extract::theta);
}

// Get, const
Handle2ConstTheta
GeneralEvaporationThetaGetConst(ConstHandle2ConstGeneralEvaporation This)
{
   return detail::getField<CPP,Handle2ConstTheta>
      (CLASSNAME, CLASSNAME+"ThetaGetConst", This, extract::theta);
}

// Get, non-const
Handle2Theta
GeneralEvaporationThetaGet(ConstHandle2GeneralEvaporation This)
{
   return detail::getField<CPP,Handle2Theta>
      (CLASSNAME, CLASSNAME+"ThetaGet", This, extract::theta);
}

// Set
void
GeneralEvaporationThetaSet(ConstHandle2GeneralEvaporation This, ConstHandle2ConstTheta theta)
{
   detail::setField<CPP,CPPTheta>
      (CLASSNAME, CLASSNAME+"ThetaSet", This, extract::theta, theta);
}
