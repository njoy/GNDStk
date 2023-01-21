
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/tsl/SelfScatteringKernel.hpp"
#include "SelfScatteringKernel.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = SelfScatteringKernelClass;
using CPP = multigroup::SelfScatteringKernel;

static const std::string CLASSNAME = "SelfScatteringKernel";

namespace extract {
   static auto symmetric = [](auto &obj) { return &obj.symmetric; };
}

using CPPGridded3d = containers::Gridded3d;
using CPPGaussianApproximation = tsl::GaussianApproximation;
using CPPSCTApproximation = tsl::SCTApproximation;
using CPPFreeGasApproximation = tsl::FreeGasApproximation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSelfScatteringKernel
SelfScatteringKernelDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2SelfScatteringKernel
SelfScatteringKernelDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSelfScatteringKernel
SelfScatteringKernelCreateConst(
   const bool symmetric,
) {
   ConstHandle2SelfScatteringKernel handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      symmetric
   );
   return handle;
}

// Create, general
Handle2SelfScatteringKernel
SelfScatteringKernelCreate(
   const bool symmetric,
) {
   ConstHandle2SelfScatteringKernel handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      symmetric
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SelfScatteringKernelAssign(ConstHandle2SelfScatteringKernel This, ConstHandle2ConstSelfScatteringKernel from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SelfScatteringKernelDelete(ConstHandle2ConstSelfScatteringKernel This)
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
SelfScatteringKernelRead(ConstHandle2SelfScatteringKernel This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SelfScatteringKernelWrite(ConstHandle2ConstSelfScatteringKernel This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
SelfScatteringKernelPrint(ConstHandle2ConstSelfScatteringKernel This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
SelfScatteringKernelPrintXML(ConstHandle2ConstSelfScatteringKernel This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
SelfScatteringKernelPrintJSON(ConstHandle2ConstSelfScatteringKernel This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: symmetric
// -----------------------------------------------------------------------------

// Has
int
SelfScatteringKernelSymmetricHas(ConstHandle2ConstSelfScatteringKernel This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetricHas", This, extract::symmetric);
}

// Get
// Returns by value
bool
SelfScatteringKernelSymmetricGet(ConstHandle2ConstSelfScatteringKernel This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetricGet", This, extract::symmetric);
}

// Set
void
SelfScatteringKernelSymmetricSet(ConstHandle2SelfScatteringKernel This, const bool symmetric)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SymmetricSet", This, extract::symmetric, symmetric);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/tsl/SelfScatteringKernel/src/custom.cpp"
