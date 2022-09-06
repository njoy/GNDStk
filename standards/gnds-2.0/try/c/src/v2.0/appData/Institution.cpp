
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/appData/Institution.hpp"
#include "Institution.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = InstitutionClass;
using CPP = multigroup::Institution;

static const std::string CLASSNAME = "Institution";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto ENDFconversionFlags = [](auto &obj) { return &obj.ENDFconversionFlags; };
}

using CPPENDFconversionFlags = appData::ENDFconversionFlags;


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
   const XMLName label,
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
   const XMLName label,
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
InstitutionAssign(ConstHandle2Institution This, ConstHandle2ConstInstitution from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
InstitutionDelete(ConstHandle2ConstInstitution This)
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
InstitutionRead(ConstHandle2Institution This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
InstitutionWrite(ConstHandle2ConstInstitution This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
InstitutionPrint(ConstHandle2ConstInstitution This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
InstitutionPrintXML(ConstHandle2ConstInstitution This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
InstitutionPrintJSON(ConstHandle2ConstInstitution This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
InstitutionLabelHas(ConstHandle2ConstInstitution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
InstitutionLabelGet(ConstHandle2ConstInstitution This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
InstitutionLabelSet(ConstHandle2Institution This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: ENDFconversionFlags
// -----------------------------------------------------------------------------

// Has
int
InstitutionENDFconversionFlagsHas(ConstHandle2ConstInstitution This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFconversionFlagsHas", This, extract::ENDFconversionFlags);
}

// Get, const
Handle2ConstENDFconversionFlags
InstitutionENDFconversionFlagsGetConst(ConstHandle2ConstInstitution This)
{
   return detail::getField<CPP,Handle2ConstENDFconversionFlags>
      (CLASSNAME, CLASSNAME+"ENDFconversionFlagsGetConst", This, extract::ENDFconversionFlags);
}

// Get, non-const
Handle2ENDFconversionFlags
InstitutionENDFconversionFlagsGet(ConstHandle2Institution This)
{
   return detail::getField<CPP,Handle2ENDFconversionFlags>
      (CLASSNAME, CLASSNAME+"ENDFconversionFlagsGet", This, extract::ENDFconversionFlags);
}

// Set
void
InstitutionENDFconversionFlagsSet(ConstHandle2Institution This, ConstHandle2ConstENDFconversionFlags ENDFconversionFlags)
{
   detail::setField<CPP,CPPENDFconversionFlags>
      (CLASSNAME, CLASSNAME+"ENDFconversionFlagsSet", This, extract::ENDFconversionFlags, ENDFconversionFlags);
}