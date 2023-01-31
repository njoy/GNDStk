
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
// ExternalFiles is the basic handle type in this file. Example:
//    // Create a default ExternalFiles object:
//    ExternalFiles handle = ExternalFilesDefault();
// Functions involving ExternalFiles are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_ALPHA_V2_0_COMMON_EXTERNALFILES
#define C_INTERFACE_ALPHA_V2_0_COMMON_EXTERNALFILES

#include "GNDStk.h"
#include "v2.0/common/ExternalFile.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ExternalFilesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ExternalFiles
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ExternalFilesClass *ExternalFiles;

// --- Const-aware handles.
typedef const struct ExternalFilesClass *const ConstHandle2ConstExternalFiles;
typedef       struct ExternalFilesClass *const ConstHandle2ExternalFiles;
typedef const struct ExternalFilesClass *      Handle2ConstExternalFiles;
typedef       struct ExternalFilesClass *      Handle2ExternalFiles;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstExternalFiles
ExternalFilesDefaultConst();

// +++ Create, default
extern_c Handle2ExternalFiles
ExternalFilesDefault();

// --- Create, general, const
extern_c Handle2ConstExternalFiles
ExternalFilesCreateConst(
   ConstHandle2ExternalFile *const externalFile, const size_t externalFileSize
);

// +++ Create, general
extern_c Handle2ExternalFiles
ExternalFilesCreate(
   ConstHandle2ExternalFile *const externalFile, const size_t externalFileSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ExternalFilesAssign(ConstHandle2ExternalFiles This, ConstHandle2ConstExternalFiles from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ExternalFilesDelete(ConstHandle2ConstExternalFiles This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ExternalFilesRead(ConstHandle2ExternalFiles This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ExternalFilesWrite(ConstHandle2ConstExternalFiles This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ExternalFilesPrint(ConstHandle2ConstExternalFiles This);

// +++ Print to standard output, as XML
extern_c int
ExternalFilesPrintXML(ConstHandle2ConstExternalFiles This);

// +++ Print to standard output, as JSON
extern_c int
ExternalFilesPrintJSON(ConstHandle2ConstExternalFiles This);


// -----------------------------------------------------------------------------
// Child: externalFile
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ExternalFilesExternalFileHas(ConstHandle2ConstExternalFiles This);

// +++ Clear
extern_c void
ExternalFilesExternalFileClear(ConstHandle2ExternalFiles This);

// +++ Size
extern_c size_t
ExternalFilesExternalFileSize(ConstHandle2ConstExternalFiles This);

// +++ Add
extern_c void
ExternalFilesExternalFileAdd(ConstHandle2ExternalFiles This, ConstHandle2ConstExternalFile externalFile);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstExternalFile
ExternalFilesExternalFileGetConst(ConstHandle2ConstExternalFiles This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2ExternalFile
ExternalFilesExternalFileGet(ConstHandle2ExternalFiles This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ExternalFilesExternalFileSet(
   ConstHandle2ExternalFiles This,
   const size_t index_,
   ConstHandle2ConstExternalFile externalFile
);

// +++ Has, by label
extern_c int
ExternalFilesExternalFileHasByLabel(
   ConstHandle2ConstExternalFiles This,
   const char *const label
);

// --- Get, by label, const
extern_c Handle2ConstExternalFile
ExternalFilesExternalFileGetByLabelConst(
   ConstHandle2ConstExternalFiles This,
   const char *const label
);

// +++ Get, by label, non-const
extern_c Handle2ExternalFile
ExternalFilesExternalFileGetByLabel(
   ConstHandle2ExternalFiles This,
   const char *const label
);

// +++ Set, by label
extern_c void
ExternalFilesExternalFileSetByLabel(
   ConstHandle2ExternalFiles This,
   const char *const label,
   ConstHandle2ConstExternalFile externalFile
);

// +++ Has, by path
extern_c int
ExternalFilesExternalFileHasByPath(
   ConstHandle2ConstExternalFiles This,
   const char *const path
);

// --- Get, by path, const
extern_c Handle2ConstExternalFile
ExternalFilesExternalFileGetByPathConst(
   ConstHandle2ConstExternalFiles This,
   const char *const path
);

// +++ Get, by path, non-const
extern_c Handle2ExternalFile
ExternalFilesExternalFileGetByPath(
   ConstHandle2ExternalFiles This,
   const char *const path
);

// +++ Set, by path
extern_c void
ExternalFilesExternalFileSetByPath(
   ConstHandle2ExternalFiles This,
   const char *const path,
   ConstHandle2ConstExternalFile externalFile
);

// +++ Has, by checksum
extern_c int
ExternalFilesExternalFileHasByChecksum(
   ConstHandle2ConstExternalFiles This,
   const char *const checksum
);

// --- Get, by checksum, const
extern_c Handle2ConstExternalFile
ExternalFilesExternalFileGetByChecksumConst(
   ConstHandle2ConstExternalFiles This,
   const char *const checksum
);

// +++ Get, by checksum, non-const
extern_c Handle2ExternalFile
ExternalFilesExternalFileGetByChecksum(
   ConstHandle2ExternalFiles This,
   const char *const checksum
);

// +++ Set, by checksum
extern_c void
ExternalFilesExternalFileSetByChecksum(
   ConstHandle2ExternalFiles This,
   const char *const checksum,
   ConstHandle2ConstExternalFile externalFile
);

// +++ Has, by algorithm
extern_c int
ExternalFilesExternalFileHasByAlgorithm(
   ConstHandle2ConstExternalFiles This,
   const char *const algorithm
);

// --- Get, by algorithm, const
extern_c Handle2ConstExternalFile
ExternalFilesExternalFileGetByAlgorithmConst(
   ConstHandle2ConstExternalFiles This,
   const char *const algorithm
);

// +++ Get, by algorithm, non-const
extern_c Handle2ExternalFile
ExternalFilesExternalFileGetByAlgorithm(
   ConstHandle2ExternalFiles This,
   const char *const algorithm
);

// +++ Set, by algorithm
extern_c void
ExternalFilesExternalFileSetByAlgorithm(
   ConstHandle2ExternalFiles This,
   const char *const algorithm,
   ConstHandle2ConstExternalFile externalFile
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/common/ExternalFiles/src/custom.h"

#undef extern_c
#endif
