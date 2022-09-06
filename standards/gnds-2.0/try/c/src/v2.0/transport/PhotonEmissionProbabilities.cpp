
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/transport/PhotonEmissionProbabilities.hpp"
#include "PhotonEmissionProbabilities.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = PhotonEmissionProbabilitiesClass;
using CPP = multigroup::PhotonEmissionProbabilities;

static const std::string CLASSNAME = "PhotonEmissionProbabilities";

namespace extract {
   static auto shell = [](auto &obj) { return &obj.shell; };
}

using CPPShell = pops::Shell;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstPhotonEmissionProbabilities
PhotonEmissionProbabilitiesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2PhotonEmissionProbabilities
PhotonEmissionProbabilitiesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstPhotonEmissionProbabilities
PhotonEmissionProbabilitiesCreateConst(
   ConstHandle2ConstShell shell
) {
   ConstHandle2PhotonEmissionProbabilities handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPShell>(shell)
   );
   return handle;
}

// Create, general
Handle2PhotonEmissionProbabilities
PhotonEmissionProbabilitiesCreate(
   ConstHandle2ConstShell shell
) {
   ConstHandle2PhotonEmissionProbabilities handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPShell>(shell)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
PhotonEmissionProbabilitiesAssign(ConstHandle2PhotonEmissionProbabilities This, ConstHandle2ConstPhotonEmissionProbabilities from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
PhotonEmissionProbabilitiesDelete(ConstHandle2ConstPhotonEmissionProbabilities This)
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
PhotonEmissionProbabilitiesRead(ConstHandle2PhotonEmissionProbabilities This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
PhotonEmissionProbabilitiesWrite(ConstHandle2ConstPhotonEmissionProbabilities This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
PhotonEmissionProbabilitiesPrint(ConstHandle2ConstPhotonEmissionProbabilities This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
PhotonEmissionProbabilitiesPrintXML(ConstHandle2ConstPhotonEmissionProbabilities This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
PhotonEmissionProbabilitiesPrintJSON(ConstHandle2ConstPhotonEmissionProbabilities This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: shell
// -----------------------------------------------------------------------------

// Has
int
PhotonEmissionProbabilitiesShellHas(ConstHandle2ConstPhotonEmissionProbabilities This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ShellHas", This, extract::shell);
}

// Get, const
Handle2ConstShell
PhotonEmissionProbabilitiesShellGetConst(ConstHandle2ConstPhotonEmissionProbabilities This)
{
   return detail::getField<CPP,Handle2ConstShell>
      (CLASSNAME, CLASSNAME+"ShellGetConst", This, extract::shell);
}

// Get, non-const
Handle2Shell
PhotonEmissionProbabilitiesShellGet(ConstHandle2PhotonEmissionProbabilities This)
{
   return detail::getField<CPP,Handle2Shell>
      (CLASSNAME, CLASSNAME+"ShellGet", This, extract::shell);
}

// Set
void
PhotonEmissionProbabilitiesShellSet(ConstHandle2PhotonEmissionProbabilities This, ConstHandle2ConstShell shell)
{
   detail::setField<CPP,CPPShell>
      (CLASSNAME, CLASSNAME+"ShellSet", This, extract::shell, shell);
}