
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
// ListOfCovariances is the basic handle type in this file. Example:
//    // Create a default ListOfCovariances object:
//    ListOfCovariances handle = ListOfCovariancesDefault();
// Functions involving ListOfCovariances are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_CONTAINERS_LISTOFCOVARIANCES
#define C_INTERFACE_TEST_V2_0_CONTAINERS_LISTOFCOVARIANCES

#include "GNDStk.h"
#include "v2.0/containers/Covariance.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct ListOfCovariancesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ ListOfCovariances
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct ListOfCovariancesClass *ListOfCovariances;

// --- Const-aware handles.
typedef const struct ListOfCovariancesClass *const ConstHandle2ConstListOfCovariances;
typedef       struct ListOfCovariancesClass *const ConstHandle2ListOfCovariances;
typedef const struct ListOfCovariancesClass *      Handle2ConstListOfCovariances;
typedef       struct ListOfCovariancesClass *      Handle2ListOfCovariances;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstListOfCovariances
ListOfCovariancesDefaultConst();

// +++ Create, default
extern_c Handle2ListOfCovariances
ListOfCovariancesDefault();

// --- Create, general, const
extern_c Handle2ConstListOfCovariances
ListOfCovariancesCreateConst(
   ConstHandle2Covariance *const covariance, const size_t covarianceSize
);

// +++ Create, general
extern_c Handle2ListOfCovariances
ListOfCovariancesCreate(
   ConstHandle2Covariance *const covariance, const size_t covarianceSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
ListOfCovariancesAssign(ConstHandle2ListOfCovariances This, ConstHandle2ConstListOfCovariances from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
ListOfCovariancesDelete(ConstHandle2ConstListOfCovariances This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
ListOfCovariancesRead(ConstHandle2ListOfCovariances This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
ListOfCovariancesWrite(ConstHandle2ConstListOfCovariances This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
ListOfCovariancesPrint(ConstHandle2ConstListOfCovariances This);

// +++ Print to standard output, as XML
extern_c int
ListOfCovariancesPrintXML(ConstHandle2ConstListOfCovariances This);

// +++ Print to standard output, as JSON
extern_c int
ListOfCovariancesPrintJSON(ConstHandle2ConstListOfCovariances This);


// -----------------------------------------------------------------------------
// Child: covariance
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
ListOfCovariancesCovarianceHas(ConstHandle2ConstListOfCovariances This);

// +++ Clear
extern_c void
ListOfCovariancesCovarianceClear(ConstHandle2ListOfCovariances This);

// +++ Size
extern_c size_t
ListOfCovariancesCovarianceSize(ConstHandle2ConstListOfCovariances This);

// +++ Add
extern_c void
ListOfCovariancesCovarianceAdd(ConstHandle2ListOfCovariances This, ConstHandle2ConstCovariance covariance);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstCovariance
ListOfCovariancesCovarianceGetConst(ConstHandle2ConstListOfCovariances This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Covariance
ListOfCovariancesCovarianceGet(ConstHandle2ListOfCovariances This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
ListOfCovariancesCovarianceSet(
   ConstHandle2ListOfCovariances This,
   const size_t index_,
   ConstHandle2ConstCovariance covariance
);

// +++ Has, by label
extern_c int
ListOfCovariancesCovarianceHasByLabel(
   ConstHandle2ConstListOfCovariances This,
   const XMLName label
);

// --- Get, by label, const
extern_c Handle2ConstCovariance
ListOfCovariancesCovarianceGetByLabelConst(
   ConstHandle2ConstListOfCovariances This,
   const XMLName label
);

// +++ Get, by label, non-const
extern_c Handle2Covariance
ListOfCovariancesCovarianceGetByLabel(
   ConstHandle2ListOfCovariances This,
   const XMLName label
);

// +++ Set, by label
extern_c void
ListOfCovariancesCovarianceSetByLabel(
   ConstHandle2ListOfCovariances This,
   const XMLName label,
   ConstHandle2ConstCovariance covariance
);

// +++ Has, by href
extern_c int
ListOfCovariancesCovarianceHasByHref(
   ConstHandle2ConstListOfCovariances This,
   const char *const href
);

// --- Get, by href, const
extern_c Handle2ConstCovariance
ListOfCovariancesCovarianceGetByHrefConst(
   ConstHandle2ConstListOfCovariances This,
   const char *const href
);

// +++ Get, by href, non-const
extern_c Handle2Covariance
ListOfCovariancesCovarianceGetByHref(
   ConstHandle2ListOfCovariances This,
   const char *const href
);

// +++ Set, by href
extern_c void
ListOfCovariancesCovarianceSetByHref(
   ConstHandle2ListOfCovariances This,
   const char *const href,
   ConstHandle2ConstCovariance covariance
);


// -----------------------------------------------------------------------------
// Done
// -----------------------------------------------------------------------------

#undef extern_c
#endif
