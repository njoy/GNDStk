
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Institution.hpp"
#include "Institution.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = InstitutionClass;
using CPP = multigroup::Institution;

static const std::string CLASSNAME = "Institution";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto ENDFconversionFlags = [](auto &obj) { return &obj.ENDFconversionFlags; };
}

using CPPENDFconversionFlags = general::ENDFconversionFlags;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstInstitution
InstitutionDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Institution
InstitutionDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstInstitution
InstitutionCreateConst(
   const char *const label,
   ConstHandle2ConstENDFconversionFlags ENDFconversionFlags
) {
   ConstHandle2Institution handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      detail::tocpp<CPPENDFconversionFlags>(ENDFconversionFlags)
   );
   return handle;
}

// Create, general
Handle2Institution
InstitutionCreate(
   const char *const label,
   ConstHandle2ConstENDFconversionFlags ENDFconversionFlags
) {
   ConstHandle2Institution handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      detail::tocpp<CPPENDFconversionFlags>(ENDFconversionFlags)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
InstitutionAssign(ConstHandle2Institution self, ConstHandle2ConstInstitution from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
InstitutionDelete(ConstHandle2ConstInstitution self)
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
InstitutionRead(ConstHandle2Institution self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
InstitutionWrite(ConstHandle2ConstInstitution self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
InstitutionPrint(ConstHandle2ConstInstitution self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
InstitutionPrintXML(ConstHandle2ConstInstitution self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
InstitutionPrintJSON(ConstHandle2ConstInstitution self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
InstitutionLabelHas(ConstHandle2ConstInstitution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
InstitutionLabelGet(ConstHandle2ConstInstitution self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
InstitutionLabelSet(ConstHandle2Institution self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: ENDFconversionFlags
// -----------------------------------------------------------------------------

// Has
int
InstitutionENDFconversionFlagsHas(ConstHandle2ConstInstitution self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFconversionFlagsHas", self, extract::ENDFconversionFlags);
}

// Get, const
Handle2ConstENDFconversionFlags
InstitutionENDFconversionFlagsGetConst(ConstHandle2ConstInstitution self)
{
   return detail::getField<CPP,Handle2ConstENDFconversionFlags>
      (CLASSNAME, CLASSNAME+"ENDFconversionFlagsGetConst", self, extract::ENDFconversionFlags);
}

// Get
Handle2ENDFconversionFlags
InstitutionENDFconversionFlagsGet(ConstHandle2Institution self)
{
   return detail::getField<CPP,Handle2ENDFconversionFlags>
      (CLASSNAME, CLASSNAME+"ENDFconversionFlagsGet", self, extract::ENDFconversionFlags);
}

// Set
void
InstitutionENDFconversionFlagsSet(ConstHandle2Institution self, ConstHandle2ConstENDFconversionFlags ENDFconversionFlags)
{
   detail::setField<CPP,CPPENDFconversionFlags>
      (CLASSNAME, CLASSNAME+"ENDFconversionFlagsSet", self, extract::ENDFconversionFlags, ENDFconversionFlags);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Institution/src/custom.cpp"
