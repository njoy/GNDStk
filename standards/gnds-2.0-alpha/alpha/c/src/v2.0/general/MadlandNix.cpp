
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/MadlandNix.hpp"
#include "MadlandNix.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = MadlandNixClass;
using CPP = multigroup::MadlandNix;

static const std::string CLASSNAME = "MadlandNix";

namespace extract {
   static auto EFL = [](auto &obj) { return &obj.EFL; };
   static auto EFH = [](auto &obj) { return &obj.EFH; };
   static auto T_M = [](auto &obj) { return &obj.T_M; };
}

using CPPEFL = general::EFL;
using CPPEFH = general::EFH;
using CPPT_M = general::T_M;


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
   ConstHandle2ConstEFL EFL,
   ConstHandle2ConstEFH EFH,
   ConstHandle2ConstT_M T_M
) {
   ConstHandle2MadlandNix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPEFL>(EFL),
      detail::tocpp<CPPEFH>(EFH),
      detail::tocpp<CPPT_M>(T_M)
   );
   return handle;
}

// Create, general
Handle2MadlandNix
MadlandNixCreate(
   ConstHandle2ConstEFL EFL,
   ConstHandle2ConstEFH EFH,
   ConstHandle2ConstT_M T_M
) {
   ConstHandle2MadlandNix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPEFL>(EFL),
      detail::tocpp<CPPEFH>(EFH),
      detail::tocpp<CPPT_M>(T_M)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
MadlandNixAssign(ConstHandle2MadlandNix This, ConstHandle2ConstMadlandNix from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
MadlandNixDelete(ConstHandle2ConstMadlandNix This)
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
MadlandNixRead(ConstHandle2MadlandNix This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
MadlandNixWrite(ConstHandle2ConstMadlandNix This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
MadlandNixPrint(ConstHandle2ConstMadlandNix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
MadlandNixPrintXML(ConstHandle2ConstMadlandNix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
MadlandNixPrintJSON(ConstHandle2ConstMadlandNix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: EFL
// -----------------------------------------------------------------------------

// Has
int
MadlandNixEFLHas(ConstHandle2ConstMadlandNix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EFLHas", This, extract::EFL);
}

// Get, const
Handle2ConstEFL
MadlandNixEFLGetConst(ConstHandle2ConstMadlandNix This)
{
   return detail::getField<CPP,Handle2ConstEFL>
      (CLASSNAME, CLASSNAME+"EFLGetConst", This, extract::EFL);
}

// Get, non-const
Handle2EFL
MadlandNixEFLGet(ConstHandle2MadlandNix This)
{
   return detail::getField<CPP,Handle2EFL>
      (CLASSNAME, CLASSNAME+"EFLGet", This, extract::EFL);
}

// Set
void
MadlandNixEFLSet(ConstHandle2MadlandNix This, ConstHandle2ConstEFL EFL)
{
   detail::setField<CPP,CPPEFL>
      (CLASSNAME, CLASSNAME+"EFLSet", This, extract::EFL, EFL);
}


// -----------------------------------------------------------------------------
// Child: EFH
// -----------------------------------------------------------------------------

// Has
int
MadlandNixEFHHas(ConstHandle2ConstMadlandNix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"EFHHas", This, extract::EFH);
}

// Get, const
Handle2ConstEFH
MadlandNixEFHGetConst(ConstHandle2ConstMadlandNix This)
{
   return detail::getField<CPP,Handle2ConstEFH>
      (CLASSNAME, CLASSNAME+"EFHGetConst", This, extract::EFH);
}

// Get, non-const
Handle2EFH
MadlandNixEFHGet(ConstHandle2MadlandNix This)
{
   return detail::getField<CPP,Handle2EFH>
      (CLASSNAME, CLASSNAME+"EFHGet", This, extract::EFH);
}

// Set
void
MadlandNixEFHSet(ConstHandle2MadlandNix This, ConstHandle2ConstEFH EFH)
{
   detail::setField<CPP,CPPEFH>
      (CLASSNAME, CLASSNAME+"EFHSet", This, extract::EFH, EFH);
}


// -----------------------------------------------------------------------------
// Child: T_M
// -----------------------------------------------------------------------------

// Has
int
MadlandNixT_MHas(ConstHandle2ConstMadlandNix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"T_MHas", This, extract::T_M);
}

// Get, const
Handle2ConstT_M
MadlandNixT_MGetConst(ConstHandle2ConstMadlandNix This)
{
   return detail::getField<CPP,Handle2ConstT_M>
      (CLASSNAME, CLASSNAME+"T_MGetConst", This, extract::T_M);
}

// Get, non-const
Handle2T_M
MadlandNixT_MGet(ConstHandle2MadlandNix This)
{
   return detail::getField<CPP,Handle2T_M>
      (CLASSNAME, CLASSNAME+"T_MGet", This, extract::T_M);
}

// Set
void
MadlandNixT_MSet(ConstHandle2MadlandNix This, ConstHandle2ConstT_M T_M)
{
   detail::setField<CPP,CPPT_M>
      (CLASSNAME, CLASSNAME+"T_MSet", This, extract::T_M, T_M);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/MadlandNix/src/custom.cpp"
