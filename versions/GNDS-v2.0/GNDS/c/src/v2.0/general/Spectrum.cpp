
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Spectrum.hpp"
#include "Spectrum.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = SpectrumClass;
using CPP = multigroup::Spectrum;

static const std::string CLASSNAME = "Spectrum";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto pid = [](auto &obj) { return &obj.pid; };
   static auto discrete = [](auto &obj) { return &obj.discrete; };
   static auto continuum = [](auto &obj) { return &obj.continuum; };
}

using CPPDiscrete = general::Discrete;
using CPPContinuum = general::Continuum;


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
SpectrumAssign(ConstHandle2Spectrum self, ConstHandle2ConstSpectrum from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SpectrumDelete(ConstHandle2ConstSpectrum self)
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
SpectrumRead(ConstHandle2Spectrum self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SpectrumWrite(ConstHandle2ConstSpectrum self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
SpectrumPrint(ConstHandle2ConstSpectrum self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
SpectrumPrintXML(ConstHandle2ConstSpectrum self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
SpectrumPrintJSON(ConstHandle2ConstSpectrum self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
SpectrumLabelHas(ConstHandle2ConstSpectrum self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
SpectrumLabelGet(ConstHandle2ConstSpectrum self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
SpectrumLabelSet(ConstHandle2Spectrum self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: pid
// -----------------------------------------------------------------------------

// Has
int
SpectrumPidHas(ConstHandle2ConstSpectrum self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"PidHas", self, extract::pid);
}

// Get
// Returns by value
const char *
SpectrumPidGet(ConstHandle2ConstSpectrum self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"PidGet", self, extract::pid);
}

// Set
void
SpectrumPidSet(ConstHandle2Spectrum self, const char *const pid)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"PidSet", self, extract::pid, pid);
}


// -----------------------------------------------------------------------------
// Child: discrete
// -----------------------------------------------------------------------------

// Has
int
SpectrumDiscreteHas(ConstHandle2ConstSpectrum self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"DiscreteHas", self, extract::discrete);
}

// Clear
void
SpectrumDiscreteClear(ConstHandle2Spectrum self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"DiscreteClear", self, extract::discrete);
}

// Size
size_t
SpectrumDiscreteSize(ConstHandle2ConstSpectrum self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"DiscreteSize", self, extract::discrete);
}

// Add
void
SpectrumDiscreteAdd(ConstHandle2Spectrum self, ConstHandle2ConstDiscrete discrete)
{
   detail::addToContainer<CPP,CPPDiscrete>
      (CLASSNAME, CLASSNAME+"DiscreteAdd", self, extract::discrete, discrete);
}

// Get, by index \in [0,size), const
Handle2ConstDiscrete
SpectrumDiscreteGetConst(ConstHandle2ConstSpectrum self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstDiscrete>
      (CLASSNAME, CLASSNAME+"DiscreteGetConst", self, extract::discrete, index_);
}

// Get, by index \in [0,size)
Handle2Discrete
SpectrumDiscreteGet(ConstHandle2Spectrum self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Discrete>
      (CLASSNAME, CLASSNAME+"DiscreteGet", self, extract::discrete, index_);
}

// Set, by index \in [0,size)
void
SpectrumDiscreteSet(
   ConstHandle2Spectrum self,
   const size_t index_,
   ConstHandle2ConstDiscrete discrete
) {
   detail::setByIndex<CPP,CPPDiscrete>
      (CLASSNAME, CLASSNAME+"DiscreteSet", self, extract::discrete, index_, discrete);
}

// Has, by type
int
SpectrumDiscreteHasByType(
   ConstHandle2ConstSpectrum self,
   const char *const type
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"DiscreteHasByType",
       self, extract::discrete, meta::type, type);
}

// Get, by type, const
Handle2ConstDiscrete
SpectrumDiscreteGetByTypeConst(
   ConstHandle2ConstSpectrum self,
   const char *const type
) {
   return detail::getByMetadatum<CPP,Handle2ConstDiscrete>
      (CLASSNAME, CLASSNAME+"DiscreteGetByTypeConst",
       self, extract::discrete, meta::type, type);
}

// Get, by type
Handle2Discrete
SpectrumDiscreteGetByType(
   ConstHandle2Spectrum self,
   const char *const type
) {
   return detail::getByMetadatum<CPP,Handle2Discrete>
      (CLASSNAME, CLASSNAME+"DiscreteGetByType",
       self, extract::discrete, meta::type, type);
}

// Set, by type
void
SpectrumDiscreteSetByType(
   ConstHandle2Spectrum self,
   const char *const type,
   ConstHandle2ConstDiscrete discrete
) {
   detail::setByMetadatum<CPP,CPPDiscrete>
      (CLASSNAME, CLASSNAME+"DiscreteSetByType",
       self, extract::discrete, meta::type, type, discrete);
}


// -----------------------------------------------------------------------------
// Child: continuum
// -----------------------------------------------------------------------------

// Has
int
SpectrumContinuumHas(ConstHandle2ConstSpectrum self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ContinuumHas", self, extract::continuum);
}

// Get, const
Handle2ConstContinuum
SpectrumContinuumGetConst(ConstHandle2ConstSpectrum self)
{
   return detail::getField<CPP,Handle2ConstContinuum>
      (CLASSNAME, CLASSNAME+"ContinuumGetConst", self, extract::continuum);
}

// Get
Handle2Continuum
SpectrumContinuumGet(ConstHandle2Spectrum self)
{
   return detail::getField<CPP,Handle2Continuum>
      (CLASSNAME, CLASSNAME+"ContinuumGet", self, extract::continuum);
}

// Set
void
SpectrumContinuumSet(ConstHandle2Spectrum self, ConstHandle2ConstContinuum continuum)
{
   detail::setField<CPP,CPPContinuum>
      (CLASSNAME, CLASSNAME+"ContinuumSet", self, extract::continuum, continuum);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Spectrum/src/custom.cpp"
