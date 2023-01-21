
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2_0/transport/OrphanProduct.hpp"
#include "OrphanProduct.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = OrphanProductClass;
using CPP = multigroup::OrphanProduct;

static const std::string CLASSNAME = "OrphanProduct";

namespace extract {
   static auto ENDF_MT = [](auto &obj) { return &obj.ENDF_MT; };
   static auto label = [](auto &obj) { return &obj.label; };
   static auto crossSection = [](auto &obj) { return &obj.crossSection; };
   static auto outputChannel = [](auto &obj) { return &obj.outputChannel; };
}

using CPPCrossSection = transport::CrossSection;
using CPPOutputChannel = transport::OutputChannel;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstOrphanProduct
OrphanProductDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2OrphanProduct
OrphanProductDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstOrphanProduct
OrphanProductCreateConst(
   const Integer32 ENDF_MT,
   const XMLName label,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
) {
   ConstHandle2OrphanProduct handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      ENDF_MT,
      label,
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPOutputChannel>(outputChannel)
   );
   return handle;
}

// Create, general
Handle2OrphanProduct
OrphanProductCreate(
   const Integer32 ENDF_MT,
   const XMLName label,
   ConstHandle2ConstCrossSection crossSection,
   ConstHandle2ConstOutputChannel outputChannel
) {
   ConstHandle2OrphanProduct handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      ENDF_MT,
      label,
      detail::tocpp<CPPCrossSection>(crossSection),
      detail::tocpp<CPPOutputChannel>(outputChannel)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
OrphanProductAssign(ConstHandle2OrphanProduct This, ConstHandle2ConstOrphanProduct from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
OrphanProductDelete(ConstHandle2ConstOrphanProduct This)
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
OrphanProductRead(ConstHandle2OrphanProduct This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
OrphanProductWrite(ConstHandle2ConstOrphanProduct This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
OrphanProductPrint(ConstHandle2ConstOrphanProduct This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
OrphanProductPrintXML(ConstHandle2ConstOrphanProduct This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
OrphanProductPrintJSON(ConstHandle2ConstOrphanProduct This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: ENDF_MT
// -----------------------------------------------------------------------------

// Has
int
OrphanProductENDFMTHas(ConstHandle2ConstOrphanProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTHas", This, extract::ENDF_MT);
}

// Get
// Returns by value
Integer32
OrphanProductENDFMTGet(ConstHandle2ConstOrphanProduct This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTGet", This, extract::ENDF_MT);
}

// Set
void
OrphanProductENDFMTSet(ConstHandle2OrphanProduct This, const Integer32 ENDF_MT)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ENDFMTSet", This, extract::ENDF_MT, ENDF_MT);
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
OrphanProductLabelHas(ConstHandle2ConstOrphanProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
OrphanProductLabelGet(ConstHandle2ConstOrphanProduct This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
OrphanProductLabelSet(ConstHandle2OrphanProduct This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Child: crossSection
// -----------------------------------------------------------------------------

// Has
int
OrphanProductCrossSectionHas(ConstHandle2ConstOrphanProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CrossSectionHas", This, extract::crossSection);
}

// Get, const
Handle2ConstCrossSection
OrphanProductCrossSectionGetConst(ConstHandle2ConstOrphanProduct This)
{
   return detail::getField<CPP,Handle2ConstCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGetConst", This, extract::crossSection);
}

// Get, non-const
Handle2CrossSection
OrphanProductCrossSectionGet(ConstHandle2OrphanProduct This)
{
   return detail::getField<CPP,Handle2CrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionGet", This, extract::crossSection);
}

// Set
void
OrphanProductCrossSectionSet(ConstHandle2OrphanProduct This, ConstHandle2ConstCrossSection crossSection)
{
   detail::setField<CPP,CPPCrossSection>
      (CLASSNAME, CLASSNAME+"CrossSectionSet", This, extract::crossSection, crossSection);
}


// -----------------------------------------------------------------------------
// Child: outputChannel
// -----------------------------------------------------------------------------

// Has
int
OrphanProductOutputChannelHas(ConstHandle2ConstOrphanProduct This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"OutputChannelHas", This, extract::outputChannel);
}

// Get, const
Handle2ConstOutputChannel
OrphanProductOutputChannelGetConst(ConstHandle2ConstOrphanProduct This)
{
   return detail::getField<CPP,Handle2ConstOutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelGetConst", This, extract::outputChannel);
}

// Get, non-const
Handle2OutputChannel
OrphanProductOutputChannelGet(ConstHandle2OrphanProduct This)
{
   return detail::getField<CPP,Handle2OutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelGet", This, extract::outputChannel);
}

// Set
void
OrphanProductOutputChannelSet(ConstHandle2OrphanProduct This, ConstHandle2ConstOutputChannel outputChannel)
{
   detail::setField<CPP,CPPOutputChannel>
      (CLASSNAME, CLASSNAME+"OutputChannelSet", This, extract::outputChannel, outputChannel);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/OrphanProduct/src/custom.cpp"
