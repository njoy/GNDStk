
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
// Dates is the basic handle type in this file. Example:
//    // Create a default Dates object:
//    Dates handle = DatesDefault();
// Functions involving Dates are declared throughout this file.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Preliminaries
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TEST_V2_0_DOCUMENTATION_DATES
#define C_INTERFACE_TEST_V2_0_DOCUMENTATION_DATES

#include "GNDStk.h"
#include "v2.0/documentation/Date.h"

#ifdef __cplusplus
   #define extern_c extern "C"
#else
   #define extern_c
#endif

// Proxy C struct for the handled C++ class
struct DatesClass { };


// -----------------------------------------------------------------------------
// Handle types
// -----------------------------------------------------------------------------

// +++ Dates
// +++ General handle, suitable for most users. If you're not concerned about
// +++ strict "const correctness" in your C code, you can probably use this in
// +++ place of any function parameter of a const-aware handle type.
typedef struct DatesClass *Dates;

// --- Const-aware handles.
typedef const struct DatesClass *const ConstHandle2ConstDates;
typedef       struct DatesClass *const ConstHandle2Dates;
typedef const struct DatesClass *      Handle2ConstDates;
typedef       struct DatesClass *      Handle2Dates;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// --- Create, default, const
extern_c Handle2ConstDates
DatesDefaultConst();

// +++ Create, default
extern_c Handle2Dates
DatesDefault();

// --- Create, general, const
extern_c Handle2ConstDates
DatesCreateConst(
   ConstHandle2Date *const date, const size_t dateSize
);

// +++ Create, general
extern_c Handle2Dates
DatesCreate(
   ConstHandle2Date *const date, const size_t dateSize
);

// +++ Assign
// +++ Use this to assign one handled object to another. Don't assign handles,
// +++ as with to = from. That has a meaning that you probably don't intend.
extern_c void
DatesAssign(ConstHandle2Dates This, ConstHandle2ConstDates from);

// +++ Delete
// +++ We'll attempt to remove no-longer-used objects automatically, but you
// +++ may improve performance if you delete them when you're done with them.
extern_c void
DatesDelete(ConstHandle2ConstDates This);


// -----------------------------------------------------------------------------
// I/O
// Read, Write, Print
// Each returns 0 if failure, 1 if success.
// -----------------------------------------------------------------------------

// +++ Read from file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll examine the file's contents to determine its type automatically.
extern_c int
DatesRead(ConstHandle2Dates This, const char *const filename);

// +++ Write to file
// +++ File can be XML, JSON, or HDF5.
// +++ We'll use filename's extension to determine the type you want written.
extern_c int
DatesWrite(ConstHandle2ConstDates This, const char *const filename);

// +++ Print to standard output, in our prettyprinting format
extern_c int
DatesPrint(ConstHandle2ConstDates This);

// +++ Print to standard output, as XML
extern_c int
DatesPrintXML(ConstHandle2ConstDates This);

// +++ Print to standard output, as JSON
extern_c int
DatesPrintJSON(ConstHandle2ConstDates This);


// -----------------------------------------------------------------------------
// Child: date
// -----------------------------------------------------------------------------

// +++ Has
extern_c int
DatesDateHas(ConstHandle2ConstDates This);

// +++ Clear
extern_c void
DatesDateClear(ConstHandle2Dates This);

// +++ Size
extern_c size_t
DatesDateSize(ConstHandle2ConstDates This);

// +++ Add
extern_c void
DatesDateAdd(ConstHandle2Dates This, ConstHandle2ConstDate date);

// --- Get, by index \in [0,size), const
extern_c Handle2ConstDate
DatesDateGetConst(ConstHandle2ConstDates This, const size_t index_);

// +++ Get, by index \in [0,size), non-const
extern_c Handle2Date
DatesDateGet(ConstHandle2Dates This, const size_t index_);

// +++ Set, by index \in [0,size)
extern_c void
DatesDateSet(
   ConstHandle2Dates This,
   const size_t index_,
   ConstHandle2ConstDate date
);

// +++ Has, by dateType
extern_c int
DatesDateHasByDateType(
   ConstHandle2ConstDates This,
   const enums::DateType dateType
);

// --- Get, by dateType, const
extern_c Handle2ConstDate
DatesDateGetByDateTypeConst(
   ConstHandle2ConstDates This,
   const enums::DateType dateType
);

// +++ Get, by dateType, non-const
extern_c Handle2Date
DatesDateGetByDateType(
   ConstHandle2Dates This,
   const enums::DateType dateType
);

// +++ Set, by dateType
extern_c void
DatesDateSetByDateType(
   ConstHandle2Dates This,
   const enums::DateType dateType,
   ConstHandle2ConstDate date
);

// +++ Has, by value
extern_c int
DatesDateHasByValue(
   ConstHandle2ConstDates This,
   const char *const value
);

// --- Get, by value, const
extern_c Handle2ConstDate
DatesDateGetByValueConst(
   ConstHandle2ConstDates This,
   const char *const value
);

// +++ Get, by value, non-const
extern_c Handle2Date
DatesDateGetByValue(
   ConstHandle2Dates This,
   const char *const value
);

// +++ Set, by value
extern_c void
DatesDateSetByValue(
   ConstHandle2Dates This,
   const char *const value,
   ConstHandle2ConstDate date
);


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/Dates/src/custom.h"

#undef extern_c
#endif
