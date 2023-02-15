
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/NuclearAmplitudeExpansion.hpp"
#include "NuclearAmplitudeExpansion.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = NuclearAmplitudeExpansionClass;
using CPP = multigroup::NuclearAmplitudeExpansion;

static const std::string CLASSNAME = "NuclearAmplitudeExpansion";

namespace extract {
   static auto nuclearTerm = [](auto &obj) { return &obj.nuclearTerm; };
   static auto realInterferenceTerm = [](auto &obj) { return &obj.realInterferenceTerm; };
   static auto imaginaryInterferenceTerm = [](auto &obj) { return &obj.imaginaryInterferenceTerm; };
}

using CPPNuclearTerm = general::NuclearTerm;
using CPPRealInterferenceTerm = general::RealInterferenceTerm;
using CPPImaginaryInterferenceTerm = general::ImaginaryInterferenceTerm;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstNuclearAmplitudeExpansion
NuclearAmplitudeExpansionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2NuclearAmplitudeExpansion
NuclearAmplitudeExpansionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstNuclearAmplitudeExpansion
NuclearAmplitudeExpansionCreateConst(
   ConstHandle2ConstNuclearTerm nuclearTerm,
   ConstHandle2ConstRealInterferenceTerm realInterferenceTerm,
   ConstHandle2ConstImaginaryInterferenceTerm imaginaryInterferenceTerm
) {
   ConstHandle2NuclearAmplitudeExpansion handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPNuclearTerm>(nuclearTerm),
      detail::tocpp<CPPRealInterferenceTerm>(realInterferenceTerm),
      detail::tocpp<CPPImaginaryInterferenceTerm>(imaginaryInterferenceTerm)
   );
   return handle;
}

// Create, general
Handle2NuclearAmplitudeExpansion
NuclearAmplitudeExpansionCreate(
   ConstHandle2ConstNuclearTerm nuclearTerm,
   ConstHandle2ConstRealInterferenceTerm realInterferenceTerm,
   ConstHandle2ConstImaginaryInterferenceTerm imaginaryInterferenceTerm
) {
   ConstHandle2NuclearAmplitudeExpansion handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPNuclearTerm>(nuclearTerm),
      detail::tocpp<CPPRealInterferenceTerm>(realInterferenceTerm),
      detail::tocpp<CPPImaginaryInterferenceTerm>(imaginaryInterferenceTerm)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
NuclearAmplitudeExpansionAssign(ConstHandle2NuclearAmplitudeExpansion self, ConstHandle2ConstNuclearAmplitudeExpansion from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
NuclearAmplitudeExpansionDelete(ConstHandle2ConstNuclearAmplitudeExpansion self)
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
NuclearAmplitudeExpansionRead(ConstHandle2NuclearAmplitudeExpansion self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
NuclearAmplitudeExpansionWrite(ConstHandle2ConstNuclearAmplitudeExpansion self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
NuclearAmplitudeExpansionPrint(ConstHandle2ConstNuclearAmplitudeExpansion self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
NuclearAmplitudeExpansionPrintXML(ConstHandle2ConstNuclearAmplitudeExpansion self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
NuclearAmplitudeExpansionPrintJSON(ConstHandle2ConstNuclearAmplitudeExpansion self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: nuclearTerm
// -----------------------------------------------------------------------------

// Has
int
NuclearAmplitudeExpansionNuclearTermHas(ConstHandle2ConstNuclearAmplitudeExpansion self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NuclearTermHas", self, extract::nuclearTerm);
}

// Get, const
Handle2ConstNuclearTerm
NuclearAmplitudeExpansionNuclearTermGetConst(ConstHandle2ConstNuclearAmplitudeExpansion self)
{
   return detail::getField<CPP,Handle2ConstNuclearTerm>
      (CLASSNAME, CLASSNAME+"NuclearTermGetConst", self, extract::nuclearTerm);
}

// Get, non-const
Handle2NuclearTerm
NuclearAmplitudeExpansionNuclearTermGet(ConstHandle2NuclearAmplitudeExpansion self)
{
   return detail::getField<CPP,Handle2NuclearTerm>
      (CLASSNAME, CLASSNAME+"NuclearTermGet", self, extract::nuclearTerm);
}

// Set
void
NuclearAmplitudeExpansionNuclearTermSet(ConstHandle2NuclearAmplitudeExpansion self, ConstHandle2ConstNuclearTerm nuclearTerm)
{
   detail::setField<CPP,CPPNuclearTerm>
      (CLASSNAME, CLASSNAME+"NuclearTermSet", self, extract::nuclearTerm, nuclearTerm);
}


// -----------------------------------------------------------------------------
// Child: realInterferenceTerm
// -----------------------------------------------------------------------------

// Has
int
NuclearAmplitudeExpansionRealInterferenceTermHas(ConstHandle2ConstNuclearAmplitudeExpansion self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RealInterferenceTermHas", self, extract::realInterferenceTerm);
}

// Get, const
Handle2ConstRealInterferenceTerm
NuclearAmplitudeExpansionRealInterferenceTermGetConst(ConstHandle2ConstNuclearAmplitudeExpansion self)
{
   return detail::getField<CPP,Handle2ConstRealInterferenceTerm>
      (CLASSNAME, CLASSNAME+"RealInterferenceTermGetConst", self, extract::realInterferenceTerm);
}

// Get, non-const
Handle2RealInterferenceTerm
NuclearAmplitudeExpansionRealInterferenceTermGet(ConstHandle2NuclearAmplitudeExpansion self)
{
   return detail::getField<CPP,Handle2RealInterferenceTerm>
      (CLASSNAME, CLASSNAME+"RealInterferenceTermGet", self, extract::realInterferenceTerm);
}

// Set
void
NuclearAmplitudeExpansionRealInterferenceTermSet(ConstHandle2NuclearAmplitudeExpansion self, ConstHandle2ConstRealInterferenceTerm realInterferenceTerm)
{
   detail::setField<CPP,CPPRealInterferenceTerm>
      (CLASSNAME, CLASSNAME+"RealInterferenceTermSet", self, extract::realInterferenceTerm, realInterferenceTerm);
}


// -----------------------------------------------------------------------------
// Child: imaginaryInterferenceTerm
// -----------------------------------------------------------------------------

// Has
int
NuclearAmplitudeExpansionImaginaryInterferenceTermHas(ConstHandle2ConstNuclearAmplitudeExpansion self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ImaginaryInterferenceTermHas", self, extract::imaginaryInterferenceTerm);
}

// Get, const
Handle2ConstImaginaryInterferenceTerm
NuclearAmplitudeExpansionImaginaryInterferenceTermGetConst(ConstHandle2ConstNuclearAmplitudeExpansion self)
{
   return detail::getField<CPP,Handle2ConstImaginaryInterferenceTerm>
      (CLASSNAME, CLASSNAME+"ImaginaryInterferenceTermGetConst", self, extract::imaginaryInterferenceTerm);
}

// Get, non-const
Handle2ImaginaryInterferenceTerm
NuclearAmplitudeExpansionImaginaryInterferenceTermGet(ConstHandle2NuclearAmplitudeExpansion self)
{
   return detail::getField<CPP,Handle2ImaginaryInterferenceTerm>
      (CLASSNAME, CLASSNAME+"ImaginaryInterferenceTermGet", self, extract::imaginaryInterferenceTerm);
}

// Set
void
NuclearAmplitudeExpansionImaginaryInterferenceTermSet(ConstHandle2NuclearAmplitudeExpansion self, ConstHandle2ConstImaginaryInterferenceTerm imaginaryInterferenceTerm)
{
   detail::setField<CPP,CPPImaginaryInterferenceTerm>
      (CLASSNAME, CLASSNAME+"ImaginaryInterferenceTermSet", self, extract::imaginaryInterferenceTerm, imaginaryInterferenceTerm);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/NuclearAmplitudeExpansion/src/custom.cpp"
