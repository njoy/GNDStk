
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
// DecayPath is the basic handle type in this file. Example:
//    // Create a default DecayPath object:
//    DecayPath handle = DecayPathDefault();
// Functions involving DecayPath are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_GNDS_V2_0_GENERAL_DECAYPATH
#define C_INTERFACE_GNDS_V2_0_GENERAL_DECAYPATH

#include "GNDStk.h"
#include "v2.0/general/Decay.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DecayPathClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ DecayPath
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DecayPathClass *DecayPath;

// --- Const-aware handles.
typedef const struct DecayPathClass *const ConstHandle2ConstDecayPath;
typedef       struct DecayPathClass *const ConstHandle2DecayPath;
typedef const struct DecayPathClass *      Handle2ConstDecayPath;
typedef       struct DecayPathClass *      Handle2DecayPath;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDecayPath
DecayPathDefaultConst();

// +++ Create, default
extern_c Handle2DecayPath
DecayPathDefault();

// --- Create, general, const
extern_c Handle2ConstDecayPath
DecayPathCreateConst(
   ConstHandle2Decay *const decay, const size_t decaySize
);

// +++ Create, general
extern_c Handle2DecayPath
DecayPathCreate(
   ConstHandle2Decay *const decay, const size_t decaySize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DecayPathAssign(ConstHandle2DecayPath self, ConstHandle2ConstDecayPath from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DecayPathDelete(ConstHandle2ConstDecayPath self);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DecayPathRead(ConstHandle2DecayPath self, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DecayPathWrite(ConstHandle2ConstDecayPath self, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DecayPathPrint(ConstHandle2ConstDecayPath self);

// +++ Print to standard output, as XML
extern_c int
DecayPathPrintXML(ConstHandle2ConstDecayPath self);

// +++ Print to standard output, as JSON
extern_c int
DecayPathPrintJSON(ConstHandle2ConstDecayPath self);


// -----------------------------------------------------------------------------
// Child: decay
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DecayPathDecayHas(ConstHandle2ConstDecayPath self);

// +++ Clear
extern_c void
DecayPathDecayClear(ConstHandle2DecayPath self);

// +++ Size
extern_c size_t
DecayPathDecaySize(ConstHandle2ConstDecayPath self);

// +++ Add
extern_c void
DecayPathDecayAdd(ConstHandle2DecayPath self, ConstHandle2ConstDecay decay);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstDecay
DecayPathDecayGetConst(ConstHandle2ConstDecayPath self, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Decay
DecayPathDecayGet(ConstHandle2DecayPath self, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
DecayPathDecaySet(
   ConstHandle2DecayPath self,
   const size_t index_,
   ConstHandle2ConstDecay decay
);

// +++ Has, by index
extern_c int
DecayPathDecayHasByIndex(
   ConstHandle2ConstDecayPath self,
   const int index
);

// --- Get, by index, const
extern_c Handle2ConstDecay
DecayPathDecayGetByIndexConst(
   ConstHandle2ConstDecayPath self,
   const int index
);

// +++ Get, by index, non-const
extern_c Handle2Decay
DecayPathDecayGetByIndex(
   ConstHandle2DecayPath self,
   const int index
);

// +++ Set, by index
extern_c void
DecayPathDecaySetByIndex(
   ConstHandle2DecayPath self,
   const int index,
   ConstHandle2ConstDecay decay
);

// +++ Has, by mode
extern_c int
DecayPathDecayHasByMode(
   ConstHandle2ConstDecayPath self,
   const char *const mode
);

// --- Get, by mode, const
extern_c Handle2ConstDecay
DecayPathDecayGetByModeConst(
   ConstHandle2ConstDecayPath self,
   const char *const mode
);

// +++ Get, by mode, non-const
extern_c Handle2Decay
DecayPathDecayGetByMode(
   ConstHandle2DecayPath self,
   const char *const mode
);

// +++ Set, by mode
extern_c void
DecayPathDecaySetByMode(
   ConstHandle2DecayPath self,
   const char *const mode,
   ConstHandle2ConstDecay decay
);

// +++ Has, by complete
extern_c int
DecayPathDecayHasByComplete(
   ConstHandle2ConstDecayPath self,
   const bool complete
);

// --- Get, by complete, const
extern_c Handle2ConstDecay
DecayPathDecayGetByCompleteConst(
   ConstHandle2ConstDecayPath self,
   const bool complete
);

// +++ Get, by complete, non-const
extern_c Handle2Decay
DecayPathDecayGetByComplete(
   ConstHandle2DecayPath self,
   const bool complete
);

// +++ Set, by complete
extern_c void
DecayPathDecaySetByComplete(
   ConstHandle2DecayPath self,
   const bool complete,
   ConstHandle2ConstDecay decay
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/DecayPath/src/custom.h"

#undef extern_c
#endif
