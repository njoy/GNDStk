
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
//    // +++ comment
// Constructs you're LESS likely to care about are preceded with:
//    // --- comment
// Anything not marked as above can be ignored by most users.
//
// ScatteringAtoms is the basic handle type in this file. Example:
//    // Create a default ScatteringAtoms object:
//    ScatteringAtoms handle = ScatteringAtomsDefault();
// Functions involving ScatteringAtoms are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_TSL_SCATTERINGATOMS
#define C_INTERFACE_TEST_V2_0_TSL_SCATTERINGATOMS

#include "GNDStk.h"
#include "v2.0/tsl/ScatteringAtom.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ScatteringAtomsClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ScatteringAtoms
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ScatteringAtomsClass *ScatteringAtoms;

// --- Const-aware handles.
typedef const struct ScatteringAtomsClass *const ConstHandle2ConstScatteringAtoms;
typedef       struct ScatteringAtomsClass *const ConstHandle2ScatteringAtoms;
typedef const struct ScatteringAtomsClass *      Handle2ConstScatteringAtoms;
typedef       struct ScatteringAtomsClass *      Handle2ScatteringAtoms;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstScatteringAtoms
ScatteringAtomsDefaultConst();

// +++ Create, default
extern_c Handle2ScatteringAtoms
ScatteringAtomsDefault();

// --- Create, general, const
extern_c Handle2ConstScatteringAtoms
ScatteringAtomsCreateConst(
   ConstHandle2ScatteringAtom *const scatteringAtom, const size_t scatteringAtomSize
);

// +++ Create, general
extern_c Handle2ScatteringAtoms
ScatteringAtomsCreate(
   ConstHandle2ScatteringAtom *const scatteringAtom, const size_t scatteringAtomSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ScatteringAtomsAssign(ConstHandle2ScatteringAtoms This, ConstHandle2ConstScatteringAtoms from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ScatteringAtomsDelete(ConstHandle2ConstScatteringAtoms This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ScatteringAtomsRead(ConstHandle2ScatteringAtoms This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ScatteringAtomsWrite(ConstHandle2ConstScatteringAtoms This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ScatteringAtomsPrint(ConstHandle2ConstScatteringAtoms This);

// +++ Print to standard output, as XML
extern_c int
ScatteringAtomsPrintXML(ConstHandle2ConstScatteringAtoms This);

// +++ Print to standard output, as JSON
extern_c int
ScatteringAtomsPrintJSON(ConstHandle2ConstScatteringAtoms This);


// -----------------------------------------------------------------------------
// Child: scatteringAtom
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ScatteringAtomsScatteringAtomHas(ConstHandle2ConstScatteringAtoms This);

// +++ Clear
extern_c void
ScatteringAtomsScatteringAtomClear(ConstHandle2ScatteringAtoms This);

// +++ Size
extern_c size_t
ScatteringAtomsScatteringAtomSize(ConstHandle2ConstScatteringAtoms This);

// +++ Add
extern_c void
ScatteringAtomsScatteringAtomAdd(ConstHandle2ScatteringAtoms This, ConstHandle2ConstScatteringAtom scatteringAtom);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstScatteringAtom
ScatteringAtomsScatteringAtomGetConst(ConstHandle2ConstScatteringAtoms This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2ScatteringAtom
ScatteringAtomsScatteringAtomGet(ConstHandle2ScatteringAtoms This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ScatteringAtomsScatteringAtomSet(
   ConstHandle2ScatteringAtoms This,
   const size_t index_,
   ConstHandle2ConstScatteringAtom scatteringAtom
);

// +++ Has, by pid
extern_c int
ScatteringAtomsScatteringAtomHasByPid(
   ConstHandle2ConstScatteringAtoms This,
   const XMLName pid
);

// --- Get, by pid, const
extern_c Handle2ConstScatteringAtom
ScatteringAtomsScatteringAtomGetByPidConst(
   ConstHandle2ConstScatteringAtoms This,
   const XMLName pid
);

// +++ Get, by pid, non-const
extern_c Handle2ScatteringAtom
ScatteringAtomsScatteringAtomGetByPid(
   ConstHandle2ScatteringAtoms This,
   const XMLName pid
);

// +++ Set, by pid
extern_c void
ScatteringAtomsScatteringAtomSetByPid(
   ConstHandle2ScatteringAtoms This,
   const XMLName pid,
   ConstHandle2ConstScatteringAtom scatteringAtom
);

// +++ Has, by primaryScatterer
extern_c int
ScatteringAtomsScatteringAtomHasByPrimaryScatterer(
   ConstHandle2ConstScatteringAtoms This,
   const bool primaryScatterer
);

// --- Get, by primaryScatterer, const
extern_c Handle2ConstScatteringAtom
ScatteringAtomsScatteringAtomGetByPrimaryScattererConst(
   ConstHandle2ConstScatteringAtoms This,
   const bool primaryScatterer
);

// +++ Get, by primaryScatterer, non-const
extern_c Handle2ScatteringAtom
ScatteringAtomsScatteringAtomGetByPrimaryScatterer(
   ConstHandle2ScatteringAtoms This,
   const bool primaryScatterer
);

// +++ Set, by primaryScatterer
extern_c void
ScatteringAtomsScatteringAtomSetByPrimaryScatterer(
   ConstHandle2ScatteringAtoms This,
   const bool primaryScatterer,
   ConstHandle2ConstScatteringAtom scatteringAtom
);

// +++ Has, by numberPerMolecule
extern_c int
ScatteringAtomsScatteringAtomHasByNumberPerMolecule(
   ConstHandle2ConstScatteringAtoms This,
   const Integer32 numberPerMolecule
);

// --- Get, by numberPerMolecule, const
extern_c Handle2ConstScatteringAtom
ScatteringAtomsScatteringAtomGetByNumberPerMoleculeConst(
   ConstHandle2ConstScatteringAtoms This,
   const Integer32 numberPerMolecule
);

// +++ Get, by numberPerMolecule, non-const
extern_c Handle2ScatteringAtom
ScatteringAtomsScatteringAtomGetByNumberPerMolecule(
   ConstHandle2ScatteringAtoms This,
   const Integer32 numberPerMolecule
);

// +++ Set, by numberPerMolecule
extern_c void
ScatteringAtomsScatteringAtomSetByNumberPerMolecule(
   ConstHandle2ScatteringAtoms This,
   const Integer32 numberPerMolecule,
   ConstHandle2ConstScatteringAtom scatteringAtom
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
