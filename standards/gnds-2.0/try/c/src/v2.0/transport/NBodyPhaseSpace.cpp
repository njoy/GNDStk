
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/transport/NBodyPhaseSpace.hpp"
#include "NBodyPhaseSpace.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = NBodyPhaseSpaceClass;
using CPP = multigroup::NBodyPhaseSpace;

static const std::string CLASSNAME = "NBodyPhaseSpace";

namespace extract {
   static auto numberOfProducts = [](auto &obj) { return &obj.numberOfProducts; };
   static auto mass = [](auto &obj) { return &obj.mass; };
}

using CPPMass = ambiguousNamespace::Mass;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstNBodyPhaseSpace
NBodyPhaseSpaceDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2NBodyPhaseSpace
NBodyPhaseSpaceDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstNBodyPhaseSpace
NBodyPhaseSpaceCreateConst(
   const Integer32 numberOfProducts,
   ConstHandle2ConstMass mass
) {
   ConstHandle2NBodyPhaseSpace handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      numberOfProducts,
      detail::tocpp<CPPMass>(mass)
   );
   return handle;
}

// Create, general
Handle2NBodyPhaseSpace
NBodyPhaseSpaceCreate(
   const Integer32 numberOfProducts,
   ConstHandle2ConstMass mass
) {
   ConstHandle2NBodyPhaseSpace handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      numberOfProducts,
      detail::tocpp<CPPMass>(mass)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
NBodyPhaseSpaceAssign(ConstHandle2NBodyPhaseSpace This, ConstHandle2ConstNBodyPhaseSpace from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
NBodyPhaseSpaceDelete(ConstHandle2ConstNBodyPhaseSpace This)
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
NBodyPhaseSpaceRead(ConstHandle2NBodyPhaseSpace This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
NBodyPhaseSpaceWrite(ConstHandle2ConstNBodyPhaseSpace This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
NBodyPhaseSpacePrint(ConstHandle2ConstNBodyPhaseSpace This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
NBodyPhaseSpacePrintXML(ConstHandle2ConstNBodyPhaseSpace This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
NBodyPhaseSpacePrintJSON(ConstHandle2ConstNBodyPhaseSpace This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: numberOfProducts
// -----------------------------------------------------------------------------

// Has
int
NBodyPhaseSpaceNumberOfProductsHas(ConstHandle2ConstNBodyPhaseSpace This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NumberOfProductsHas", This, extract::numberOfProducts);
}

// Get
// Returns by value
Integer32
NBodyPhaseSpaceNumberOfProductsGet(ConstHandle2ConstNBodyPhaseSpace This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"NumberOfProductsGet", This, extract::numberOfProducts);
}

// Set
void
NBodyPhaseSpaceNumberOfProductsSet(ConstHandle2NBodyPhaseSpace This, const Integer32 numberOfProducts)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"NumberOfProductsSet", This, extract::numberOfProducts, numberOfProducts);
}


// -----------------------------------------------------------------------------
// Child: mass
// -----------------------------------------------------------------------------

// Has
int
NBodyPhaseSpaceMassHas(ConstHandle2ConstNBodyPhaseSpace This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"MassHas", This, extract::mass);
}

// Get, const
Handle2ConstMass
NBodyPhaseSpaceMassGetConst(ConstHandle2ConstNBodyPhaseSpace This)
{
   return detail::getField<CPP,Handle2ConstMass>
      (CLASSNAME, CLASSNAME+"MassGetConst", This, extract::mass);
}

// Get, non-const
Handle2Mass
NBodyPhaseSpaceMassGet(ConstHandle2NBodyPhaseSpace This)
{
   return detail::getField<CPP,Handle2Mass>
      (CLASSNAME, CLASSNAME+"MassGet", This, extract::mass);
}

// Set
void
NBodyPhaseSpaceMassSet(ConstHandle2NBodyPhaseSpace This, ConstHandle2ConstMass mass)
{
   detail::setField<CPP,CPPMass>
      (CLASSNAME, CLASSNAME+"MassSet", This, extract::mass, mass);
}
