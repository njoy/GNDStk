
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// Interface for C
// This header file is designed to work with both C and C++
// Function definitions are in this file's .cpp source

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Instructions for Users
//
// Constructs you're MORE likely to care about are preceded with:
//    // +++ remark
// Constructs you're LESS likely to care about are preceded with:
//    // --- remark
// Anything not marked as above can be ignored by most users.
//
// Spectra is the basic handle type in this file. Example:
//    // Create a default Spectra object:
//    Spectra handle = SpectraDefault();
// Functions involving Spectra are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_POPS_SPECTRA
#define C_INTERFACE_TEST_V2_0_POPS_SPECTRA

#include "GNDStk.h"
#include "v2.0/pops/Spectrum.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct SpectraClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Spectra
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct SpectraClass *Spectra;

// --- Const-aware handles.
typedef const struct SpectraClass *const ConstHandle2ConstSpectra;
typedef       struct SpectraClass *const ConstHandle2Spectra;
typedef const struct SpectraClass *      Handle2ConstSpectra;
typedef       struct SpectraClass *      Handle2Spectra;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstSpectra
SpectraDefaultConst();

// +++ Create, default
extern_c Handle2Spectra
SpectraDefault();

// --- Create, general, const
extern_c Handle2ConstSpectra
SpectraCreateConst(
   ConstHandle2Spectrum *const spectrum, const size_t spectrumSize
);

// +++ Create, general
extern_c Handle2Spectra
SpectraCreate(
   ConstHandle2Spectrum *const spectrum, const size_t spectrumSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
SpectraAssign(ConstHandle2Spectra self, ConstHandle2ConstSpectra from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
SpectraDelete(ConstHandle2ConstSpectra self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
SpectraRead(ConstHandle2Spectra self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
SpectraWrite(ConstHandle2ConstSpectra self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
SpectraPrint(ConstHandle2ConstSpectra self);

// +++ Print to standard output, as XML
extern_c int
SpectraPrintXML(ConstHandle2ConstSpectra self);

// +++ Print to standard output, as JSON
extern_c int
SpectraPrintJSON(ConstHandle2ConstSpectra self);


// -----------------------------------------------------------------------------
// Child: spectrum
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
SpectraSpectrumHas(ConstHandle2ConstSpectra self);

// +++ Clear
extern_c void
SpectraSpectrumClear(ConstHandle2Spectra self);

// +++ Size
extern_c size_t
SpectraSpectrumSize(ConstHandle2ConstSpectra self);

// +++ Add
extern_c void
SpectraSpectrumAdd(ConstHandle2Spectra self, ConstHandle2ConstSpectrum spectrum);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstSpectrum
SpectraSpectrumGetConst(ConstHandle2ConstSpectra self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Spectrum
SpectraSpectrumGet(ConstHandle2Spectra self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
SpectraSpectrumSet(
   ConstHandle2Spectra self,
   const size_t index_,
   ConstHandle2ConstSpectrum spectrum
);

// +++ Has, by label
extern_c int
SpectraSpectrumHasByLabel(
   ConstHandle2ConstSpectra self,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstSpectrum
SpectraSpectrumGetByLabelConst(
   ConstHandle2ConstSpectra self,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2Spectrum
SpectraSpectrumGetByLabel(
   ConstHandle2Spectra self,
   const XMLName label
);

// +++ Set, by label
extern_c void
SpectraSpectrumSetByLabel(
   ConstHandle2Spectra self,
   const XMLName label,
   ConstHandle2ConstSpectrum spectrum
);

// +++ Has, by pid
extern_c int
SpectraSpectrumHasByPid(
   ConstHandle2ConstSpectra self,
   const XMLName pid
);

// --- Get, by pid, const
extern_c Handle2ConstSpectrum
SpectraSpectrumGetByPidConst(
   ConstHandle2ConstSpectra self,
   const XMLName pid
);

// +++ Get, by pid, non-const
extern_c Handle2Spectrum
SpectraSpectrumGetByPid(
   ConstHandle2Spectra self,
   const XMLName pid
);

// +++ Set, by pid
extern_c void
SpectraSpectrumSetByPid(
   ConstHandle2Spectra self,
   const XMLName pid,
   ConstHandle2ConstSpectrum spectrum
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/pops/Spectra/src/custom.h"

#undef extern_c
#endif
