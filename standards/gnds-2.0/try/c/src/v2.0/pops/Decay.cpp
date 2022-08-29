
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/pops/Decay.hpp"
#include "Decay.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = DecayClass;
using CPP = multigroup::Decay;

static const std::string CLASSNAME = "Decay";

namespace extract {
   static auto index = [](auto &obj) { return &obj.index; };
   static auto mode = [](auto &obj) { return &obj.mode; };
   static auto complete = [](auto &obj) { return &obj.complete; };
   static auto products = [](auto &obj) { return &obj.products; };
}

using CPPProducts = pops::Products;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstDecay
DecayDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Decay
DecayDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstDecay
DecayCreateConst(
   const Integer32 index,
   const enums::DecayType mode,
   const bool complete,
   ConstHandle2ConstProducts products
) {
   ConstHandle2Decay handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      index,
      mode,
      complete,
      detail::tocpp<CPPProducts>(products)
   );
   return handle;
}

// Create, general
Handle2Decay
DecayCreate(
   const Integer32 index,
   const enums::DecayType mode,
   const bool complete,
   ConstHandle2ConstProducts products
) {
   ConstHandle2Decay handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      index,
      mode,
      complete,
      detail::tocpp<CPPProducts>(products)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
DecayAssign(ConstHandle2Decay This, ConstHandle2ConstDecay from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
DecayDelete(ConstHandle2ConstDecay This)
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
DecayRead(ConstHandle2Decay This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
DecayWrite(ConstHandle2ConstDecay This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
DecayPrint(ConstHandle2ConstDecay This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
DecayPrintXML(ConstHandle2ConstDecay This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
DecayPrintJSON(ConstHandle2ConstDecay This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: index
// -----------------------------------------------------------------------------

// Has
int
DecayIndexHas(ConstHandle2ConstDecay This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"IndexHas", This, extract::index);
}

// Get
// Returns by value
Integer32
DecayIndexGet(ConstHandle2ConstDecay This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"IndexGet", This, extract::index);
}

// Set
void
DecayIndexSet(ConstHandle2Decay This, const Integer32 index)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"IndexSet", This, extract::index, index);
}


// -----------------------------------------------------------------------------
// Metadatum: mode
// -----------------------------------------------------------------------------

// Has
int
DecayModeHas(ConstHandle2ConstDecay This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ModeHas", This, extract::mode);
}

// Get
// Returns by value
enums::DecayType
DecayModeGet(ConstHandle2ConstDecay This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ModeGet", This, extract::mode);
}

// Set
void
DecayModeSet(ConstHandle2Decay This, const enums::DecayType mode)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ModeSet", This, extract::mode, mode);
}


// -----------------------------------------------------------------------------
// Metadatum: complete
// -----------------------------------------------------------------------------

// Has
int
DecayCompleteHas(ConstHandle2ConstDecay This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CompleteHas", This, extract::complete);
}

// Get
// Returns by value
bool
DecayCompleteGet(ConstHandle2ConstDecay This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"CompleteGet", This, extract::complete);
}

// Set
void
DecayCompleteSet(ConstHandle2Decay This, const bool complete)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"CompleteSet", This, extract::complete, complete);
}


// -----------------------------------------------------------------------------
// Child: products
// -----------------------------------------------------------------------------

// Has
int
DecayProductsHas(ConstHandle2ConstDecay This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductsHas", This, extract::products);
}

// Get, const
Handle2ConstProducts
DecayProductsGetConst(ConstHandle2ConstDecay This)
{
   return detail::getField<CPP,Handle2ConstProducts>
      (CLASSNAME, CLASSNAME+"ProductsGetConst", This, extract::products);
}

// Get, non-const
Handle2Products
DecayProductsGet(ConstHandle2Decay This)
{
   return detail::getField<CPP,Handle2Products>
      (CLASSNAME, CLASSNAME+"ProductsGet", This, extract::products);
}

// Set
void
DecayProductsSet(ConstHandle2Decay This, ConstHandle2ConstProducts products)
{
   detail::setField<CPP,CPPProducts>
      (CLASSNAME, CLASSNAME+"ProductsSet", This, extract::products, products);
}
