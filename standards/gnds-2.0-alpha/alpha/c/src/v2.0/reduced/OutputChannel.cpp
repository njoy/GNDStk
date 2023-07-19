
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2.0/reduced/OutputChannel.hpp"
#include "OutputChannel.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = OutputChannelClass;
using CPP = multigroup::OutputChannel;

static const std::string CLASSNAME = "OutputChannel";

namespace extract {
   static auto genre = [](auto &obj) { return &obj.genre; };
   static auto process = [](auto &obj) { return &obj.process; };
   static auto Q = [](auto &obj) { return &obj.Q; };
   static auto products = [](auto &obj) { return &obj.products; };
}

using CPPQ = general::Q;
using CPPProducts = reduced::Products;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstOutputChannel
OutputChannelDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2OutputChannel
OutputChannelDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstOutputChannel
OutputChannelCreateConst(
   const char *const genre,
   const char *const process,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstProducts products
) {
   ConstHandle2OutputChannel handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      genre,
      process,
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPProducts>(products)
   );
   return handle;
}

// Create, general
Handle2OutputChannel
OutputChannelCreate(
   const char *const genre,
   const char *const process,
   ConstHandle2ConstQ Q,
   ConstHandle2ConstProducts products
) {
   ConstHandle2OutputChannel handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      genre,
      process,
      detail::tocpp<CPPQ>(Q),
      detail::tocpp<CPPProducts>(products)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
OutputChannelAssign(ConstHandle2OutputChannel self, ConstHandle2ConstOutputChannel from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
OutputChannelDelete(ConstHandle2ConstOutputChannel self)
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
OutputChannelRead(ConstHandle2OutputChannel self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
OutputChannelWrite(ConstHandle2ConstOutputChannel self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
OutputChannelPrint(ConstHandle2ConstOutputChannel self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
OutputChannelPrintXML(ConstHandle2ConstOutputChannel self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
OutputChannelPrintJSON(ConstHandle2ConstOutputChannel self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: genre
// -----------------------------------------------------------------------------

// Has
int
OutputChannelGenreHas(ConstHandle2ConstOutputChannel self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"GenreHas", self, extract::genre);
}

// Get
// Returns by value
const char *
OutputChannelGenreGet(ConstHandle2ConstOutputChannel self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"GenreGet", self, extract::genre);
}

// Set
void
OutputChannelGenreSet(ConstHandle2OutputChannel self, const char *const genre)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"GenreSet", self, extract::genre, genre);
}


// -----------------------------------------------------------------------------
// Metadatum: process
// -----------------------------------------------------------------------------

// Has
int
OutputChannelProcessHas(ConstHandle2ConstOutputChannel self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProcessHas", self, extract::process);
}

// Get
// Returns by value
const char *
OutputChannelProcessGet(ConstHandle2ConstOutputChannel self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProcessGet", self, extract::process);
}

// Set
void
OutputChannelProcessSet(ConstHandle2OutputChannel self, const char *const process)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProcessSet", self, extract::process, process);
}


// -----------------------------------------------------------------------------
// Child: Q
// -----------------------------------------------------------------------------

// Has
int
OutputChannelQHas(ConstHandle2ConstOutputChannel self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"QHas", self, extract::Q);
}

// Get, const
Handle2ConstQ
OutputChannelQGetConst(ConstHandle2ConstOutputChannel self)
{
   return detail::getField<CPP,Handle2ConstQ>
      (CLASSNAME, CLASSNAME+"QGetConst", self, extract::Q);
}

// Get, non-const
Handle2Q
OutputChannelQGet(ConstHandle2OutputChannel self)
{
   return detail::getField<CPP,Handle2Q>
      (CLASSNAME, CLASSNAME+"QGet", self, extract::Q);
}

// Set
void
OutputChannelQSet(ConstHandle2OutputChannel self, ConstHandle2ConstQ Q)
{
   detail::setField<CPP,CPPQ>
      (CLASSNAME, CLASSNAME+"QSet", self, extract::Q, Q);
}


// -----------------------------------------------------------------------------
// Child: products
// -----------------------------------------------------------------------------

// Has
int
OutputChannelProductsHas(ConstHandle2ConstOutputChannel self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductsHas", self, extract::products);
}

// Get, const
Handle2ConstProducts
OutputChannelProductsGetConst(ConstHandle2ConstOutputChannel self)
{
   return detail::getField<CPP,Handle2ConstProducts>
      (CLASSNAME, CLASSNAME+"ProductsGetConst", self, extract::products);
}

// Get, non-const
Handle2Products
OutputChannelProductsGet(ConstHandle2OutputChannel self)
{
   return detail::getField<CPP,Handle2Products>
      (CLASSNAME, CLASSNAME+"ProductsGet", self, extract::products);
}

// Set
void
OutputChannelProductsSet(ConstHandle2OutputChannel self, ConstHandle2ConstProducts products)
{
   detail::setField<CPP,CPPProducts>
      (CLASSNAME, CLASSNAME+"ProductsSet", self, extract::products, products);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/reduced/OutputChannel/src/custom.cpp"
