
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "alpha/v2_0/sfy/Spectrum.hpp"
#include "Spectrum.h"

using namespace njoy::GNDStk;
using namespace alpha::v2_0;

using C = SpectrumClass;
using CPP = multigroup::Spectrum;

static const std::string CLASSNAME = "Spectrum";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto pid = [](auto &obj) { return &obj.pid; };
   static auto discrete = [](auto &obj) { return &obj.discrete; };
   static auto continuum = [](auto &obj) { return &obj.continuum; };
}

using CPPDiscrete = sfy::Discrete;
using CPPContinuum = sfy::Continuum;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSpectrum
SpectrumDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Spectrum
SpectrumDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSpectrum
SpectrumCreateConst(
   const char *const label,
   const char *const pid,
   ConstHandle2Discrete *const discrete, const size_t discreteSize,
   ConstHandle2ConstContinuum continuum
) {
   ConstHandle2Spectrum handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      pid,
      std::vector<CPPDiscrete>{},
      detail::tocpp<CPPContinuum>(continuum)
   );
   for (size_t DiscreteN = 0; DiscreteN < discreteSize; ++DiscreteN)
      SpectrumDiscreteAdd(handle, discrete[DiscreteN]);
   return handle;
}

// Create, general
Handle2Spectrum
SpectrumCreate(
   const char *const label,
   const char *const pid,
   ConstHandle2Discrete *const discrete, const size_t discreteSize,
   ConstHandle2ConstContinuum continuum
) {
   ConstHandle2Spectrum handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      pid,
      std::vector<CPPDiscrete>{},
      detail::tocpp<CPPContinuum>(continuum)
   );
   for (size_t DiscreteN = 0; DiscreteN < discreteSize; ++DiscreteN)
      SpectrumDiscreteAdd(handle, discrete[DiscreteN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SpectrumAssign(ConstHandle2Spectrum This, ConstHandle2ConstSpectrum from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SpectrumDelete(ConstHandle2ConstSpectrum This)
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
SpectrumRead(ConstHandle2Spectrum This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SpectrumWrite(ConstHandle2ConstSpectrum This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
SpectrumPrint(ConstHandle2ConstSpectrum This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
SpectrumPrintXML(ConstHandle2ConstSpectrum This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
SpectrumPrintJSON(ConstHandle2ConstSpectrum This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
SpectrumLabelHas(ConstHandle2ConstSpectrum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
const char *
SpectrumLabelGet(ConstHandle2ConstSpectrum This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
SpectrumLabelSet(ConstHandle2Spectrum This, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// Has
int
SpectrumPidHas(ConstHandle2ConstSpectrum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PidHas", This, extract::pid);
}

// Get
// Returns by value
const char *
SpectrumPidGet(ConstHandle2ConstSpectrum This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PidGet", This, extract::pid);
}

// Set
void
SpectrumPidSet(ConstHandle2Spectrum This, const char *const pid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PidSet", This, extract::pid, pid);
}


// -----------------------------------------------------------------------------
// Child: discrete
// -----------------------------------------------------------------------------

// Has
int
SpectrumDiscreteHas(ConstHandle2ConstSpectrum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DiscreteHas", This, extract::discrete);
}

// Clear
void
SpectrumDiscreteClear(ConstHandle2Spectrum This)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"DiscreteClear", This, extract::discrete);
}

// Size
size_t
SpectrumDiscreteSize(ConstHandle2ConstSpectrum This)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"DiscreteSize", This, extract::discrete);
}

// Add
void
SpectrumDiscreteAdd(ConstHandle2Spectrum This, ConstHandle2ConstDiscrete discrete)
{
   detail::addToContainer<CPP,CPPDiscrete>
      (CLASSNAME, CLASSNAME+"DiscreteAdd", This, extract::discrete, discrete);
}

// Get, by index \in [0,size), const
Handle2ConstDiscrete
SpectrumDiscreteGetConst(ConstHandle2ConstSpectrum This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstDiscrete>
      (CLASSNAME, CLASSNAME+"DiscreteGetConst", This, extract::discrete, index_);
}

// Get, by index \in [0,size), non-const
Handle2Discrete
SpectrumDiscreteGet(ConstHandle2Spectrum This, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Discrete>
      (CLASSNAME, CLASSNAME+"DiscreteGet", This, extract::discrete, index_);
}

// Set, by index \in [0,size)
void
SpectrumDiscreteSet(
   ConstHandle2Spectrum This,
   const size_t index_,
   ConstHandle2ConstDiscrete discrete
) {
   detail::setByIndex<CPP,CPPDiscrete>
      (CLASSNAME, CLASSNAME+"DiscreteSet", This, extract::discrete, index_, discrete);
}

// Has, by type
int
SpectrumDiscreteHasByType(
   ConstHandle2ConstSpectrum This,
   const char *const type
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DiscreteHasByType",
       This, extract::discrete, meta::type, type);
}

// Get, by type, const
Handle2ConstDiscrete
SpectrumDiscreteGetByTypeConst(
   ConstHandle2ConstSpectrum This,
   const char *const type
) {
   return detail::getByMetadatum<CPP,Handle2ConstDiscrete>
      (CLASSNAME, CLASSNAME+"DiscreteGetByTypeConst",
       This, extract::discrete, meta::type, type);
}

// Get, by type, non-const
Handle2Discrete
SpectrumDiscreteGetByType(
   ConstHandle2Spectrum This,
   const char *const type
) {
   return detail::getByMetadatum<CPP,Handle2Discrete>
      (CLASSNAME, CLASSNAME+"DiscreteGetByType",
       This, extract::discrete, meta::type, type);
}

// Set, by type
void
SpectrumDiscreteSetByType(
   ConstHandle2Spectrum This,
   const char *const type,
   ConstHandle2ConstDiscrete discrete
) {
   detail::setByMetadatum<CPP,CPPDiscrete>
      (CLASSNAME, CLASSNAME+"DiscreteSetByType",
       This, extract::discrete, meta::type, type, discrete);
}


// -----------------------------------------------------------------------------
// Child: continuum
// -----------------------------------------------------------------------------

// Has
int
SpectrumContinuumHas(ConstHandle2ConstSpectrum This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ContinuumHas", This, extract::continuum);
}

// Get, const
Handle2ConstContinuum
SpectrumContinuumGetConst(ConstHandle2ConstSpectrum This)
{
   return detail::getField<CPP,Handle2ConstContinuum>
      (CLASSNAME, CLASSNAME+"ContinuumGetConst", This, extract::continuum);
}

// Get, non-const
Handle2Continuum
SpectrumContinuumGet(ConstHandle2Spectrum This)
{
   return detail::getField<CPP,Handle2Continuum>
      (CLASSNAME, CLASSNAME+"ContinuumGet", This, extract::continuum);
}

// Set
void
SpectrumContinuumSet(ConstHandle2Spectrum This, ConstHandle2ConstContinuum continuum)
{
   detail::setField<CPP,CPPContinuum>
      (CLASSNAME, CLASSNAME+"ContinuumSet", This, extract::continuum, continuum);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/sfy/Spectrum/src/custom.cpp"
