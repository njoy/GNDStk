
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/tsl/BraggEdges.hpp"
#include "BraggEdges.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = BraggEdgesClass;
using CPP = multigroup::BraggEdges;

static const std::string CLASSNAME = "BraggEdges";

namespace extract {
   static auto BraggEdge = [](auto &obj) { return &obj.BraggEdge; };
}

using CPPBraggEdge = tsl::BraggEdge;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstBraggEdges
BraggEdgesDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2BraggEdges
BraggEdgesDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstBraggEdges
BraggEdgesCreateConst(
   ConstHandle2BraggEdge *const BraggEdge, const size_t BraggEdgeSize
) {
   ConstHandle2BraggEdges handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPBraggEdge>{}
   );
   for (size_t BraggEdgeN = 0; BraggEdgeN < BraggEdgeSize; ++BraggEdgeN)
      BraggEdgesBraggEdgeAdd(handle, BraggEdge[BraggEdgeN]);
   return handle;
}

// Create, general
Handle2BraggEdges
BraggEdgesCreate(
   ConstHandle2BraggEdge *const BraggEdge, const size_t BraggEdgeSize
) {
   ConstHandle2BraggEdges handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPBraggEdge>{}
   );
   for (size_t BraggEdgeN = 0; BraggEdgeN < BraggEdgeSize; ++BraggEdgeN)
      BraggEdgesBraggEdgeAdd(handle, BraggEdge[BraggEdgeN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
BraggEdgesAssign(ConstHandle2BraggEdges This, ConstHandle2ConstBraggEdges from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
BraggEdgesDelete(ConstHandle2ConstBraggEdges This)
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
BraggEdgesRead(ConstHandle2BraggEdges This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
BraggEdgesWrite(ConstHandle2ConstBraggEdges This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
BraggEdgesPrint(ConstHandle2ConstBraggEdges This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
BraggEdgesPrintXML(ConstHandle2ConstBraggEdges This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
BraggEdgesPrintJSON(ConstHandle2ConstBraggEdges This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Child: BraggEdge
// -----------------------------------------------------------------------------

// Has
int
BraggEdgesBraggEdgeHas(ConstHandle2ConstBraggEdges This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"BraggEdgeHas", This, extract::BraggEdge);
}

// Clear
void
BraggEdgesBraggEdgeClear(ConstHandle2BraggEdges This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"BraggEdgeClear", This, extract::BraggEdge);
}

// Size
size_t
BraggEdgesBraggEdgeSize(ConstHandle2ConstBraggEdges This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"BraggEdgeSize", This, extract::BraggEdge);
}

// Add
void
BraggEdgesBraggEdgeAdd(ConstHandle2BraggEdges This, ConstHandle2ConstBraggEdge BraggEdge)
{
   detail::addToContainer<CPP,CPPBraggEdge>
      (CLASSNAME, CLASSNAME+"BraggEdgeAdd", This, extract::BraggEdge, BraggEdge);
}

// Get, by index \in [0,size), const
Handle2ConstBraggEdge
BraggEdgesBraggEdgeGetConst(ConstHandle2ConstBraggEdges This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstBraggEdge>
      (CLASSNAME, CLASSNAME+"BraggEdgeGetConst", This, extract::BraggEdge, index_);
}

// Get, by index \in [0,size), non-const
Handle2BraggEdge
BraggEdgesBraggEdgeGet(ConstHandle2BraggEdges This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2BraggEdge>
      (CLASSNAME, CLASSNAME+"BraggEdgeGet", This, extract::BraggEdge, index_);
}

// Set, by index \in [0,size)
void
BraggEdgesBraggEdgeSet(
   ConstHandle2BraggEdges This,
   const size_t index_,
   ConstHandle2ConstBraggEdge BraggEdge
) {
   detail::setByIndex<CPP,CPPBraggEdge>
      (CLASSNAME, CLASSNAME+"BraggEdgeSet", This, extract::BraggEdge, index_, BraggEdge);
}

// Has, by label
int
BraggEdgesBraggEdgeHasByLabel(
   ConstHandle2ConstBraggEdges This,
   const XMLName label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"BraggEdgeHasByLabel",
       This, extract::BraggEdge, meta::label, label);
}

// Get, by label, const
Handle2ConstBraggEdge
BraggEdgesBraggEdgeGetByLabelConst(
   ConstHandle2ConstBraggEdges This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2ConstBraggEdge>
      (CLASSNAME, CLASSNAME+"BraggEdgeGetByLabelConst",
       This, extract::BraggEdge, meta::label, label);
}

// Get, by label, non-const
Handle2BraggEdge
BraggEdgesBraggEdgeGetByLabel(
   ConstHandle2BraggEdges This,
   const XMLName label
) {
   return detail::getByMetadatum<CPP,Handle2BraggEdge>
      (CLASSNAME, CLASSNAME+"BraggEdgeGetByLabel",
       This, extract::BraggEdge, meta::label, label);
}

// Set, by label
void
BraggEdgesBraggEdgeSetByLabel(
   ConstHandle2BraggEdges This,
   const XMLName label,
   ConstHandle2ConstBraggEdge BraggEdge
) {
   detail::setByMetadatum<CPP,CPPBraggEdge>
      (CLASSNAME, CLASSNAME+"BraggEdgeSetByLabel",
       This, extract::BraggEdge, meta::label, label, BraggEdge);
}
