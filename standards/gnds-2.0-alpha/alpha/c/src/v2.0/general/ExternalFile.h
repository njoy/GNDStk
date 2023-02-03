
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
// ExternalFile is the basic handle type in this file. Example:
//    // Create a default ExternalFile object:
//    ExternalFile handle = ExternalFileDefault();
// Functions involving ExternalFile are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_GENERAL_EXTERNALFILE
#define C_INTERFACE_ALPHA_V2_0_GENERAL_EXTERNALFILE

#include "GNDStk.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ExternalFileClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ExternalFile
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ExternalFileClass *ExternalFile;

// --- Const-aware handles.
typedef const struct ExternalFileClass *const ConstHandle2ConstExternalFile;
typedef       struct ExternalFileClass *const ConstHandle2ExternalFile;
typedef const struct ExternalFileClass *      Handle2ConstExternalFile;
typedef       struct ExternalFileClass *      Handle2ExternalFile;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstExternalFile
ExternalFileDefaultConst();

// +++ Create, default
extern_c Handle2ExternalFile
ExternalFileDefault();

// --- Create, general, const
extern_c Handle2ConstExternalFile
ExternalFileCreateConst(
   const char *const label,
   const char *const path,
   const char *const checksum,
   const char *const algorithm
);

// +++ Create, general
extern_c Handle2ExternalFile
ExternalFileCreate(
   const char *const label,
   const char *const path,
   const char *const checksum,
   const char *const algorithm
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ExternalFileAssign(ConstHandle2ExternalFile This, ConstHandle2ConstExternalFile from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ExternalFileDelete(ConstHandle2ConstExternalFile This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ExternalFileRead(ConstHandle2ExternalFile This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ExternalFileWrite(ConstHandle2ConstExternalFile This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ExternalFilePrint(ConstHandle2ConstExternalFile This);

// +++ Print to standard output, as XML
extern_c int
ExternalFilePrintXML(ConstHandle2ConstExternalFile This);

// +++ Print to standard output, as JSON
extern_c int
ExternalFilePrintJSON(ConstHandle2ConstExternalFile This);


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExternalFileLabelHas(ConstHandle2ConstExternalFile This);

// +++ Get
// +++ Returns by value
extern_c const char *
ExternalFileLabelGet(ConstHandle2ConstExternalFile This);

// +++ Set
extern_c void
ExternalFileLabelSet(ConstHandle2ExternalFile This, const char *const label);


// -----------------------------------------------------------------------------
// Metadatum: path
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExternalFilePathHas(ConstHandle2ConstExternalFile This);

// +++ Get
// +++ Returns by value
extern_c const char *
ExternalFilePathGet(ConstHandle2ConstExternalFile This);

// +++ Set
extern_c void
ExternalFilePathSet(ConstHandle2ExternalFile This, const char *const path);


// -----------------------------------------------------------------------------
// Metadatum: checksum
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExternalFileChecksumHas(ConstHandle2ConstExternalFile This);

// +++ Get
// +++ Returns by value
extern_c const char *
ExternalFileChecksumGet(ConstHandle2ConstExternalFile This);

// +++ Set
extern_c void
ExternalFileChecksumSet(ConstHandle2ExternalFile This, const char *const checksum);


// -----------------------------------------------------------------------------
// Metadatum: algorithm
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExternalFileAlgorithmHas(ConstHandle2ConstExternalFile This);

// +++ Get
// +++ Returns by value
extern_c const char *
ExternalFileAlgorithmGet(ConstHandle2ConstExternalFile This);

// +++ Set
extern_c void
ExternalFileAlgorithmSet(ConstHandle2ExternalFile This, const char *const algorithm);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ExternalFile/src/custom.h"

#undef extern_c
#endif
