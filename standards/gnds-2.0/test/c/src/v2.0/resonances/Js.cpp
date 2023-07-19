
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/resonances/Js.hpp"
#include "Js.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = JsClass;
using CPP = multigroup::Js;

static const std::string CLASSNAME = "Js";

namespace extract {
   static auto J = [](auto &obj) { return &obj.J; };
}

using CPPJ = resonances::J;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstJs
JsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Js
JsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstJs
JsCreateConst(
   ConstHandle2J *const J, const size_t JSize
) {
   ConstHandle2Js handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPJ>{}
   );
   for (size_t JN = 0; JN < JSize; ++JN)
      JsJAdd(handle, J[JN]);
   return handle;
}

// Create, general
Handle2Js
JsCreate(
   ConstHandle2J *const J, const size_t JSize
) {
   ConstHandle2Js handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPJ>{}
   );
   for (size_t JN = 0; JN < JSize; ++JN)
      JsJAdd(handle, J[JN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
JsAssign(ConstHandle2Js self, ConstHandle2ConstJs from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
JsDelete(ConstHandle2ConstJs self)
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
JsRead(ConstHandle2Js self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
JsWrite(ConstHandle2ConstJs self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
JsPrint(ConstHandle2ConstJs self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
JsPrintXML(ConstHandle2ConstJs self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
JsPrintJSON(ConstHandle2ConstJs self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: J
// -----------------------------------------------------------------------------

// Has
int
JsJHas(ConstHandle2ConstJs self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"JHas", self, extract::J);
}

// Clear
void
JsJClear(ConstHandle2Js self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"JClear", self, extract::J);
}

// Size
size_t
JsJSize(ConstHandle2ConstJs self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"JSize", self, extract::J);
}

// Add
void
JsJAdd(ConstHandle2Js self, ConstHandle2ConstJ J)
{
   detail::addToContainer<CPP,CPPJ>
      (CLASSNAME, CLASSNAME+"JAdd", self, extract::J, J);
}

// Get, by index \in [0,size), const
Handle2ConstJ
JsJGetConst(ConstHandle2ConstJs self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstJ>
      (CLASSNAME, CLASSNAME+"JGetConst", self, extract::J, index_);
}

// Get, by index \in [0,size), non-const
Handle2J
JsJGet(ConstHandle2Js self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2J>
      (CLASSNAME, CLASSNAME+"JGet", self, extract::J, index_);
}

// Set, by index \in [0,size)
void
JsJSet(
   ConstHandle2Js self,
   const size_t index_,
   ConstHandle2ConstJ J
) {
   detail::setByIndex<CPP,CPPJ>
      (CLASSNAME, CLASSNAME+"JSet", self, extract::J, index_, J);
}

// Has, by label
int
JsJHasByLabel(
   ConstHandle2ConstJs self,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"JHasByLabel",
       self, extract::J, meta::label, label);
}

// Get, by label, const
Handle2ConstJ
JsJGetByLabelConst(
   ConstHandle2ConstJs self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstJ>
      (CLASSNAME, CLASSNAME+"JGetByLabelConst",
       self, extract::J, meta::label, label);
}

// Get, by label, non-const
Handle2J
JsJGetByLabel(
   ConstHandle2Js self,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2J>
      (CLASSNAME, CLASSNAME+"JGetByLabel",
       self, extract::J, meta::label, label);
}

// Set, by label
void
JsJSetByLabel(
   ConstHandle2Js self,
   const XMLName label,
   ConstHandle2ConstJ J
) {
   detail::setByMetadatum<CPP,CPPJ>
      (CLASSNAME, CLASSNAME+"JSetByLabel",
       self, extract::J, meta::label, label, J);
}

// Has, by value
int
JsJHasByValue(
   ConstHandle2ConstJs self,
   const Fraction32 value
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"JHasByValue",
       self, extract::J, meta::value, value);
}

// Get, by value, const
Handle2ConstJ
JsJGetByValueConst(
   ConstHandle2ConstJs self,
   const Fraction32 value
) {
   return detail::getByMetadatum<CPP,Handle2ConstJ>
      (CLASSNAME, CLASSNAME+"JGetByValueConst",
       self, extract::J, meta::value, value);
}

// Get, by value, non-const
Handle2J
JsJGetByValue(
   ConstHandle2Js self,
   const Fraction32 value
) {
   return detail::getByMetadatum<CPP,Handle2J>
      (CLASSNAME, CLASSNAME+"JGetByValue",
       self, extract::J, meta::value, value);
}

// Set, by value
void
JsJSetByValue(
   ConstHandle2Js self,
   const Fraction32 value,
   ConstHandle2ConstJ J
) {
   detail::setByMetadatum<CPP,CPPJ>
      (CLASSNAME, CLASSNAME+"JSetByValue",
       self, extract::J, meta::value, value, J);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/resonances/Js/src/custom.cpp"
