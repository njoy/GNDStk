
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/general/ApplicationData.hpp"
#include "ApplicationData.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = ApplicationDataClass;
using CPP = multigroup::ApplicationData;

static const std::string CLASSNAME = "ApplicationData";

namespace extract {
   static auto institution = [](auto &obj) { return &obj.institution; };
}

using CPPInstitution = general::Institution;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstApplicationData
ApplicationDataDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ApplicationData
ApplicationDataDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstApplicationData
ApplicationDataCreateConst(
   ConstHandle2ConstInstitution institution
) {
   ConstHandle2ApplicationData handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPInstitution>(institution)
   );
   return handle;
}

// Create, general
Handle2ApplicationData
ApplicationDataCreate(
   ConstHandle2ConstInstitution institution
) {
   ConstHandle2ApplicationData handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPInstitution>(institution)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ApplicationDataAssign(ConstHandle2ApplicationData This, ConstHandle2ConstApplicationData from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ApplicationDataDelete(ConstHandle2ConstApplicationData This)
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
ApplicationDataRead(ConstHandle2ApplicationData This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ApplicationDataWrite(ConstHandle2ConstApplicationData This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ApplicationDataPrint(ConstHandle2ConstApplicationData This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ApplicationDataPrintXML(ConstHandle2ConstApplicationData This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ApplicationDataPrintJSON(ConstHandle2ConstApplicationData This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: institution
// -----------------------------------------------------------------------------

// Has
int
ApplicationDataInstitutionHas(ConstHandle2ConstApplicationData This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"InstitutionHas", This, extract::institution);
}

// Get, const
Handle2ConstInstitution
ApplicationDataInstitutionGetConst(ConstHandle2ConstApplicationData This)
{
   return detail::getField<CPP,Handle2ConstInstitution>
      (CLASSNAME, CLASSNAME+"InstitutionGetConst", This, extract::institution);
}

// Get, non-const
Handle2Institution
ApplicationDataInstitutionGet(ConstHandle2ApplicationData This)
{
   return detail::getField<CPP,Handle2Institution>
      (CLASSNAME, CLASSNAME+"InstitutionGet", This, extract::institution);
}

// Set
void
ApplicationDataInstitutionSet(ConstHandle2ApplicationData This, ConstHandle2ConstInstitution institution)
{
   detail::setField<CPP,CPPInstitution>
      (CLASSNAME, CLASSNAME+"InstitutionSet", This, extract::institution, institution);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ApplicationData/src/custom.cpp"
