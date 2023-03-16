
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/fissionTransport/MadlandNix.hpp"
#include "MadlandNix.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = MadlandNixClass;
using CPP = multigroup::MadlandNix;

static const std::string CLASSNAME = "MadlandNix";

namespace extract {
   static auto EFH = [](auto &obj) { return &obj.EFH; };
   static auto EFL = [](auto &obj) { return &obj.EFL; };
   static auto T_M = [](auto &obj) { return &obj.T_M; };
}

using CPPEFH = fissionTransport::EFH;
using CPPEFL = fissionTransport::EFL;
using CPPT_M = fissionTransport::T_M;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstMadlandNix
MadlandNixDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2MadlandNix
MadlandNixDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstMadlandNix
MadlandNixCreateConst(
   ConstHandle2ConstEFH EFH,
   ConstHandle2ConstEFL EFL,
   ConstHandle2ConstT_M T_M
) {
   ConstHandle2MadlandNix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPEFH>(EFH),
      detail::tocpp<CPPEFL>(EFL),
      detail::tocpp<CPPT_M>(T_M)
   );
   return handle;
}

// Create, general
Handle2MadlandNix
MadlandNixCreate(
   ConstHandle2ConstEFH EFH,
   ConstHandle2ConstEFL EFL,
   ConstHandle2ConstT_M T_M
) {
   ConstHandle2MadlandNix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPEFH>(EFH),
      detail::tocpp<CPPEFL>(EFL),
      detail::tocpp<CPPT_M>(T_M)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
MadlandNixAssign(ConstHandle2MadlandNix self, ConstHandle2ConstMadlandNix from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
MadlandNixDelete(ConstHandle2ConstMadlandNix self)
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
MadlandNixRead(ConstHandle2MadlandNix self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
MadlandNixWrite(ConstHandle2ConstMadlandNix self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
MadlandNixPrint(ConstHandle2ConstMadlandNix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
MadlandNixPrintXML(ConstHandle2ConstMadlandNix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
MadlandNixPrintJSON(ConstHandle2ConstMadlandNix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: EFH
// -----------------------------------------------------------------------------

// Has
int
MadlandNixEFHHas(ConstHandle2ConstMadlandNix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EFHHas", self, extract::EFH);
}

// Get, const
Handle2ConstEFH
MadlandNixEFHGetConst(ConstHandle2ConstMadlandNix self)
{
   return detail::getField<CPP,Handle2ConstEFH>
      (CLASSNAME, CLASSNAME+"EFHGetConst", self, extract::EFH);
}

// Get, non-const
Handle2EFH
MadlandNixEFHGet(ConstHandle2MadlandNix self)
{
   return detail::getField<CPP,Handle2EFH>
      (CLASSNAME, CLASSNAME+"EFHGet", self, extract::EFH);
}

// Set
void
MadlandNixEFHSet(ConstHandle2MadlandNix self, ConstHandle2ConstEFH EFH)
{
   detail::setField<CPP,CPPEFH>
      (CLASSNAME, CLASSNAME+"EFHSet", self, extract::EFH, EFH);
}


// -----------------------------------------------------------------------------
// Child: EFL
// -----------------------------------------------------------------------------

// Has
int
MadlandNixEFLHas(ConstHandle2ConstMadlandNix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EFLHas", self, extract::EFL);
}

// Get, const
Handle2ConstEFL
MadlandNixEFLGetConst(ConstHandle2ConstMadlandNix self)
{
   return detail::getField<CPP,Handle2ConstEFL>
      (CLASSNAME, CLASSNAME+"EFLGetConst", self, extract::EFL);
}

// Get, non-const
Handle2EFL
MadlandNixEFLGet(ConstHandle2MadlandNix self)
{
   return detail::getField<CPP,Handle2EFL>
      (CLASSNAME, CLASSNAME+"EFLGet", self, extract::EFL);
}

// Set
void
MadlandNixEFLSet(ConstHandle2MadlandNix self, ConstHandle2ConstEFL EFL)
{
   detail::setField<CPP,CPPEFL>
      (CLASSNAME, CLASSNAME+"EFLSet", self, extract::EFL, EFL);
}


// -----------------------------------------------------------------------------
// Child: T_M
// -----------------------------------------------------------------------------

// Has
int
MadlandNixT_MHas(ConstHandle2ConstMadlandNix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"T_MHas", self, extract::T_M);
}

// Get, const
Handle2ConstT_M
MadlandNixT_MGetConst(ConstHandle2ConstMadlandNix self)
{
   return detail::getField<CPP,Handle2ConstT_M>
      (CLASSNAME, CLASSNAME+"T_MGetConst", self, extract::T_M);
}

// Get, non-const
Handle2T_M
MadlandNixT_MGet(ConstHandle2MadlandNix self)
{
   return detail::getField<CPP,Handle2T_M>
      (CLASSNAME, CLASSNAME+"T_MGet", self, extract::T_M);
}

// Set
void
MadlandNixT_MSet(ConstHandle2MadlandNix self, ConstHandle2ConstT_M T_M)
{
   detail::setField<CPP,CPPT_M>
      (CLASSNAME, CLASSNAME+"T_MSet", self, extract::T_M, T_M);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/fissionTransport/MadlandNix/src/custom.cpp"
