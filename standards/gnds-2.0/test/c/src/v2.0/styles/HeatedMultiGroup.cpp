
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/styles/HeatedMultiGroup.hpp"
#include "HeatedMultiGroup.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = HeatedMultiGroupClass;
using CPP = multigroup::HeatedMultiGroup;

static const std::string CLASSNAME = "HeatedMultiGroup";

namespace extract {
   static auto date = [](auto &obj) { return &obj.date; };
   static auto derivedFrom = [](auto &obj) { return &obj.derivedFrom; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto transportables = [](auto &obj) { return &obj.transportables; };
   static auto flux = [](auto &obj) { return &obj.flux; };
   static auto inverseSpeed = [](auto &obj) { return &obj.inverseSpeed; };
   static auto documentation = [](auto &obj) { return &obj.documentation; };
}

using CPPTransportables = styles::Transportables;
using CPPFlux = styles::Flux;
using CPPInverseSpeed = styles::InverseSpeed;
using CPPDocumentation = documentation::Documentation;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstHeatedMultiGroup
HeatedMultiGroupDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2HeatedMultiGroup
HeatedMultiGroupDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstHeatedMultiGroup
HeatedMultiGroupCreateConst(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstTransportables transportables,
   ConstHandle2ConstFlux flux,
   ConstHandle2ConstInverseSpeed inverseSpeed,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2HeatedMultiGroup handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      date,
      derivedFrom,
      label,
      detail::tocpp<CPPTransportables>(transportables),
      detail::tocpp<CPPFlux>(flux),
      detail::tocpp<CPPInverseSpeed>(inverseSpeed),
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Create, general
Handle2HeatedMultiGroup
HeatedMultiGroupCreate(
   const char *const date,
   const XMLName derivedFrom,
   const XMLName label,
   ConstHandle2ConstTransportables transportables,
   ConstHandle2ConstFlux flux,
   ConstHandle2ConstInverseSpeed inverseSpeed,
   ConstHandle2ConstDocumentation documentation
) {
   ConstHandle2HeatedMultiGroup handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      date,
      derivedFrom,
      label,
      detail::tocpp<CPPTransportables>(transportables),
      detail::tocpp<CPPFlux>(flux),
      detail::tocpp<CPPInverseSpeed>(inverseSpeed),
      detail::tocpp<CPPDocumentation>(documentation)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
HeatedMultiGroupAssign(ConstHandle2HeatedMultiGroup self, ConstHandle2ConstHeatedMultiGroup from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
HeatedMultiGroupDelete(ConstHandle2ConstHeatedMultiGroup self)
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
HeatedMultiGroupRead(ConstHandle2HeatedMultiGroup self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
HeatedMultiGroupWrite(ConstHandle2ConstHeatedMultiGroup self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
HeatedMultiGroupPrint(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
HeatedMultiGroupPrintXML(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
HeatedMultiGroupPrintJSON(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: date
// -----------------------------------------------------------------------------

// Has
int
HeatedMultiGroupDateHas(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DateHas", self, extract::date);
}

// Get
// Returns by value
const char *
HeatedMultiGroupDateGet(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DateGet", self, extract::date);
}

// Set
void
HeatedMultiGroupDateSet(ConstHandle2HeatedMultiGroup self, const char *const date)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DateSet", self, extract::date, date);
}


// -----------------------------------------------------------------------------
// Metadatum: derivedFrom
// -----------------------------------------------------------------------------

// Has
int
HeatedMultiGroupDerivedFromHas(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromHas", self, extract::derivedFrom);
}

// Get
// Returns by value
XMLName
HeatedMultiGroupDerivedFromGet(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromGet", self, extract::derivedFrom);
}

// Set
void
HeatedMultiGroupDerivedFromSet(ConstHandle2HeatedMultiGroup self, const XMLName derivedFrom)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"DerivedFromSet", self, extract::derivedFrom, derivedFrom);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
HeatedMultiGroupLabelHas(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
XMLName
HeatedMultiGroupLabelGet(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
HeatedMultiGroupLabelSet(ConstHandle2HeatedMultiGroup self, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: transportables
// -----------------------------------------------------------------------------

// Has
int
HeatedMultiGroupTransportablesHas(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TransportablesHas", self, extract::transportables);
}

// Get, const
Handle2ConstTransportables
HeatedMultiGroupTransportablesGetConst(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::getField<CPP,Handle2ConstTransportables>
      (CLASSNAME, CLASSNAME+"TransportablesGetConst", self, extract::transportables);
}

// Get, non-const
Handle2Transportables
HeatedMultiGroupTransportablesGet(ConstHandle2HeatedMultiGroup self)
{
   return detail::getField<CPP,Handle2Transportables>
      (CLASSNAME, CLASSNAME+"TransportablesGet", self, extract::transportables);
}

// Set
void
HeatedMultiGroupTransportablesSet(ConstHandle2HeatedMultiGroup self, ConstHandle2ConstTransportables transportables)
{
   detail::setField<CPP,CPPTransportables>
      (CLASSNAME, CLASSNAME+"TransportablesSet", self, extract::transportables, transportables);
}


// -----------------------------------------------------------------------------
// Child: flux
// -----------------------------------------------------------------------------

// Has
int
HeatedMultiGroupFluxHas(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"FluxHas", self, extract::flux);
}

// Get, const
Handle2ConstFlux
HeatedMultiGroupFluxGetConst(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::getField<CPP,Handle2ConstFlux>
      (CLASSNAME, CLASSNAME+"FluxGetConst", self, extract::flux);
}

// Get, non-const
Handle2Flux
HeatedMultiGroupFluxGet(ConstHandle2HeatedMultiGroup self)
{
   return detail::getField<CPP,Handle2Flux>
      (CLASSNAME, CLASSNAME+"FluxGet", self, extract::flux);
}

// Set
void
HeatedMultiGroupFluxSet(ConstHandle2HeatedMultiGroup self, ConstHandle2ConstFlux flux)
{
   detail::setField<CPP,CPPFlux>
      (CLASSNAME, CLASSNAME+"FluxSet", self, extract::flux, flux);
}


// -----------------------------------------------------------------------------
// Child: inverseSpeed
// -----------------------------------------------------------------------------

// Has
int
HeatedMultiGroupInverseSpeedHas(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"InverseSpeedHas", self, extract::inverseSpeed);
}

// Get, const
Handle2ConstInverseSpeed
HeatedMultiGroupInverseSpeedGetConst(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::getField<CPP,Handle2ConstInverseSpeed>
      (CLASSNAME, CLASSNAME+"InverseSpeedGetConst", self, extract::inverseSpeed);
}

// Get, non-const
Handle2InverseSpeed
HeatedMultiGroupInverseSpeedGet(ConstHandle2HeatedMultiGroup self)
{
   return detail::getField<CPP,Handle2InverseSpeed>
      (CLASSNAME, CLASSNAME+"InverseSpeedGet", self, extract::inverseSpeed);
}

// Set
void
HeatedMultiGroupInverseSpeedSet(ConstHandle2HeatedMultiGroup self, ConstHandle2ConstInverseSpeed inverseSpeed)
{
   detail::setField<CPP,CPPInverseSpeed>
      (CLASSNAME, CLASSNAME+"InverseSpeedSet", self, extract::inverseSpeed, inverseSpeed);
}


// -----------------------------------------------------------------------------
// Child: documentation
// -----------------------------------------------------------------------------

// Has
int
HeatedMultiGroupDocumentationHas(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DocumentationHas", self, extract::documentation);
}

// Get, const
Handle2ConstDocumentation
HeatedMultiGroupDocumentationGetConst(ConstHandle2ConstHeatedMultiGroup self)
{
   return detail::getField<CPP,Handle2ConstDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationGetConst", self, extract::documentation);
}

// Get, non-const
Handle2Documentation
HeatedMultiGroupDocumentationGet(ConstHandle2HeatedMultiGroup self)
{
   return detail::getField<CPP,Handle2Documentation>
      (CLASSNAME, CLASSNAME+"DocumentationGet", self, extract::documentation);
}

// Set
void
HeatedMultiGroupDocumentationSet(ConstHandle2HeatedMultiGroup self, ConstHandle2ConstDocumentation documentation)
{
   detail::setField<CPP,CPPDocumentation>
      (CLASSNAME, CLASSNAME+"DocumentationSet", self, extract::documentation, documentation);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/styles/HeatedMultiGroup/src/custom.cpp"
