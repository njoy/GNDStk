
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/Spectra.hpp"
#include "Spectra.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = SpectraClass;
using CPP = multigroup::Spectra;

static const std::string CLASSNAME = "Spectra";

namespace extract {
   static auto spectrum = [](auto &obj) { return &obj.spectrum; };
}

using CPPSpectrum = general::Spectrum;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstSpectra
SpectraDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2Spectra
SpectraDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstSpectra
SpectraCreateConst(
   ConstHandle2Spectrum *const spectrum, const size_t spectrumSize
) {
   ConstHandle2Spectra handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      std::vector<CPPSpectrum>{}
   );
   for (size_t SpectrumN = 0; SpectrumN < spectrumSize; ++SpectrumN)
      SpectraSpectrumAdd(handle, spectrum[SpectrumN]);
   return handle;
}

// Create, general
Handle2Spectra
SpectraCreate(
   ConstHandle2Spectrum *const spectrum, const size_t spectrumSize
) {
   ConstHandle2Spectra handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      std::vector<CPPSpectrum>{}
   );
   for (size_t SpectrumN = 0; SpectrumN < spectrumSize; ++SpectrumN)
      SpectraSpectrumAdd(handle, spectrum[SpectrumN]);
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
SpectraAssign(ConstHandle2Spectra self, ConstHandle2ConstSpectra from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
SpectraDelete(ConstHandle2ConstSpectra self)
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
SpectraRead(ConstHandle2Spectra self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
SpectraWrite(ConstHandle2ConstSpectra self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
SpectraPrint(ConstHandle2ConstSpectra self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
SpectraPrintXML(ConstHandle2ConstSpectra self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
SpectraPrintJSON(ConstHandle2ConstSpectra self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: spectrum
// -----------------------------------------------------------------------------

// Has
int
SpectraSpectrumHas(ConstHandle2ConstSpectra self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SpectrumHas", self, extract::spectrum);
}

// Clear
void
SpectraSpectrumClear(ConstHandle2Spectra self)
{
   detail::clearContainer<CPP>
      (CLASSNAME, CLASSNAME+"SpectrumClear", self, extract::spectrum);
}

// Size
size_t
SpectraSpectrumSize(ConstHandle2ConstSpectra self)
{
   return detail::sizeOfContainer<CPP>
      (CLASSNAME, CLASSNAME+"SpectrumSize", self, extract::spectrum);
}

// Add
void
SpectraSpectrumAdd(ConstHandle2Spectra self, ConstHandle2ConstSpectrum spectrum)
{
   detail::addToContainer<CPP,CPPSpectrum>
      (CLASSNAME, CLASSNAME+"SpectrumAdd", self, extract::spectrum, spectrum);
}

// Get, by index \in [0,size), const
Handle2ConstSpectrum
SpectraSpectrumGetConst(ConstHandle2ConstSpectra self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2ConstSpectrum>
      (CLASSNAME, CLASSNAME+"SpectrumGetConst", self, extract::spectrum, index_);
}

// Get, by index \in [0,size)
Handle2Spectrum
SpectraSpectrumGet(ConstHandle2Spectra self, const size_t index_)
{
   return detail::getByIndex<CPP,Handle2Spectrum>
      (CLASSNAME, CLASSNAME+"SpectrumGet", self, extract::spectrum, index_);
}

// Set, by index \in [0,size)
void
SpectraSpectrumSet(
   ConstHandle2Spectra self,
   const size_t index_,
   ConstHandle2ConstSpectrum spectrum
) {
   detail::setByIndex<CPP,CPPSpectrum>
      (CLASSNAME, CLASSNAME+"SpectrumSet", self, extract::spectrum, index_, spectrum);
}

// Has, by label
int
SpectraSpectrumHasByLabel(
   ConstHandle2ConstSpectra self,
   const char *const label
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SpectrumHasByLabel",
       self, extract::spectrum, meta::label, label);
}

// Get, by label, const
Handle2ConstSpectrum
SpectraSpectrumGetByLabelConst(
   ConstHandle2ConstSpectra self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2ConstSpectrum>
      (CLASSNAME, CLASSNAME+"SpectrumGetByLabelConst",
       self, extract::spectrum, meta::label, label);
}

// Get, by label
Handle2Spectrum
SpectraSpectrumGetByLabel(
   ConstHandle2Spectra self,
   const char *const label
) {
   return detail::getByMetadatum<CPP,Handle2Spectrum>
      (CLASSNAME, CLASSNAME+"SpectrumGetByLabel",
       self, extract::spectrum, meta::label, label);
}

// Set, by label
void
SpectraSpectrumSetByLabel(
   ConstHandle2Spectra self,
   const char *const label,
   ConstHandle2ConstSpectrum spectrum
) {
   detail::setByMetadatum<CPP,CPPSpectrum>
      (CLASSNAME, CLASSNAME+"SpectrumSetByLabel",
       self, extract::spectrum, meta::label, label, spectrum);
}

// Has, by pid
int
SpectraSpectrumHasByPid(
   ConstHandle2ConstSpectra self,
   const char *const pid
) {
   return detail::hasByMetadatum<CPP>
      (CLASSNAME, CLASSNAME+"SpectrumHasByPid",
       self, extract::spectrum, meta::pid, pid);
}

// Get, by pid, const
Handle2ConstSpectrum
SpectraSpectrumGetByPidConst(
   ConstHandle2ConstSpectra self,
   const char *const pid
) {
   return detail::getByMetadatum<CPP,Handle2ConstSpectrum>
      (CLASSNAME, CLASSNAME+"SpectrumGetByPidConst",
       self, extract::spectrum, meta::pid, pid);
}

// Get, by pid
Handle2Spectrum
SpectraSpectrumGetByPid(
   ConstHandle2Spectra self,
   const char *const pid
) {
   return detail::getByMetadatum<CPP,Handle2Spectrum>
      (CLASSNAME, CLASSNAME+"SpectrumGetByPid",
       self, extract::spectrum, meta::pid, pid);
}

// Set, by pid
void
SpectraSpectrumSetByPid(
   ConstHandle2Spectra self,
   const char *const pid,
   ConstHandle2ConstSpectrum spectrum
) {
   detail::setByMetadatum<CPP,CPPSpectrum>
      (CLASSNAME, CLASSNAME+"SpectrumSetByPid",
       self, extract::spectrum, meta::pid, pid, spectrum);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/Spectra/src/custom.cpp"
