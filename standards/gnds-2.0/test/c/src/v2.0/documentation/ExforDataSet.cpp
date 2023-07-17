
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/documentation/ExforDataSet.hpp"
#include "ExforDataSet.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = ExforDataSetClass;
using CPP = multigroup::ExforDataSet;

static const std::string CLASSNAME = "ExforDataSet";

namespace extract {
   static auto subentry = [](auto &obj) { return &obj.subentry; };
   static auto retrievalDate = [](auto &obj) { return &obj.retrievalDate; };
   static auto covarianceScript = [](auto &obj) { return &obj.covarianceScript; };
   static auto correctionScript = [](auto &obj) { return &obj.correctionScript; };
   static auto note = [](auto &obj) { return &obj.note; };
}

using CPPCovarianceScript = documentation::CovarianceScript;
using CPPCorrectionScript = documentation::CorrectionScript;
using CPPNote = documentation::Note;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstExforDataSet
ExforDataSetDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2ExforDataSet
ExforDataSetDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstExforDataSet
ExforDataSetCreateConst(
   const XMLName subentry,
   const char *const retrievalDate,
   ConstHandle2ConstCovarianceScript covarianceScript,
   ConstHandle2ConstCorrectionScript correctionScript,
   ConstHandle2ConstNote note
) {
   ConstHandle2ExforDataSet handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      subentry,
      retrievalDate,
      detail::tocpp<CPPCovarianceScript>(covarianceScript),
      detail::tocpp<CPPCorrectionScript>(correctionScript),
      detail::tocpp<CPPNote>(note)
   );
   return handle;
}

// Create, general
Handle2ExforDataSet
ExforDataSetCreate(
   const XMLName subentry,
   const char *const retrievalDate,
   ConstHandle2ConstCovarianceScript covarianceScript,
   ConstHandle2ConstCorrectionScript correctionScript,
   ConstHandle2ConstNote note
) {
   ConstHandle2ExforDataSet handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      subentry,
      retrievalDate,
      detail::tocpp<CPPCovarianceScript>(covarianceScript),
      detail::tocpp<CPPCorrectionScript>(correctionScript),
      detail::tocpp<CPPNote>(note)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ExforDataSetAssign(ConstHandle2ExforDataSet self, ConstHandle2ConstExforDataSet from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ExforDataSetDelete(ConstHandle2ConstExforDataSet self)
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
ExforDataSetRead(ConstHandle2ExforDataSet self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ExforDataSetWrite(ConstHandle2ConstExforDataSet self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ExforDataSetPrint(ConstHandle2ConstExforDataSet self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ExforDataSetPrintXML(ConstHandle2ConstExforDataSet self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ExforDataSetPrintJSON(ConstHandle2ConstExforDataSet self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: subentry
// -----------------------------------------------------------------------------

// Has
int
ExforDataSetSubentryHas(ConstHandle2ConstExforDataSet self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"SubentryHas", self, extract::subentry);
}

// Get
// Returns by value
XMLName
ExforDataSetSubentryGet(ConstHandle2ConstExforDataSet self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"SubentryGet", self, extract::subentry);
}

// Set
void
ExforDataSetSubentrySet(ConstHandle2ExforDataSet self, const XMLName subentry)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"SubentrySet", self, extract::subentry, subentry);
}


// -----------------------------------------------------------------------------
// Metadatum: retrievalDate
// -----------------------------------------------------------------------------

// Has
int
ExforDataSetRetrievalDateHas(ConstHandle2ConstExforDataSet self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"RetrievalDateHas", self, extract::retrievalDate);
}

// Get
// Returns by value
const char *
ExforDataSetRetrievalDateGet(ConstHandle2ConstExforDataSet self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"RetrievalDateGet", self, extract::retrievalDate);
}

// Set
void
ExforDataSetRetrievalDateSet(ConstHandle2ExforDataSet self, const char *const retrievalDate)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"RetrievalDateSet", self, extract::retrievalDate, retrievalDate);
}


// -----------------------------------------------------------------------------
// Child: covarianceScript
// -----------------------------------------------------------------------------

// Has
int
ExforDataSetCovarianceScriptHas(ConstHandle2ConstExforDataSet self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CovarianceScriptHas", self, extract::covarianceScript);
}

// Get, const
Handle2ConstCovarianceScript
ExforDataSetCovarianceScriptGetConst(ConstHandle2ConstExforDataSet self)
{
   return detail::getField<CPP,Handle2ConstCovarianceScript>
      (CLASSNAME, CLASSNAME+"CovarianceScriptGetConst", self, extract::covarianceScript);
}

// Get, non-const
Handle2CovarianceScript
ExforDataSetCovarianceScriptGet(ConstHandle2ExforDataSet self)
{
   return detail::getField<CPP,Handle2CovarianceScript>
      (CLASSNAME, CLASSNAME+"CovarianceScriptGet", self, extract::covarianceScript);
}

// Set
void
ExforDataSetCovarianceScriptSet(ConstHandle2ExforDataSet self, ConstHandle2ConstCovarianceScript covarianceScript)
{
   detail::setField<CPP,CPPCovarianceScript>
      (CLASSNAME, CLASSNAME+"CovarianceScriptSet", self, extract::covarianceScript, covarianceScript);
}


// -----------------------------------------------------------------------------
// Child: correctionScript
// -----------------------------------------------------------------------------

// Has
int
ExforDataSetCorrectionScriptHas(ConstHandle2ConstExforDataSet self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"CorrectionScriptHas", self, extract::correctionScript);
}

// Get, const
Handle2ConstCorrectionScript
ExforDataSetCorrectionScriptGetConst(ConstHandle2ConstExforDataSet self)
{
   return detail::getField<CPP,Handle2ConstCorrectionScript>
      (CLASSNAME, CLASSNAME+"CorrectionScriptGetConst", self, extract::correctionScript);
}

// Get, non-const
Handle2CorrectionScript
ExforDataSetCorrectionScriptGet(ConstHandle2ExforDataSet self)
{
   return detail::getField<CPP,Handle2CorrectionScript>
      (CLASSNAME, CLASSNAME+"CorrectionScriptGet", self, extract::correctionScript);
}

// Set
void
ExforDataSetCorrectionScriptSet(ConstHandle2ExforDataSet self, ConstHandle2ConstCorrectionScript correctionScript)
{
   detail::setField<CPP,CPPCorrectionScript>
      (CLASSNAME, CLASSNAME+"CorrectionScriptSet", self, extract::correctionScript, correctionScript);
}


// -----------------------------------------------------------------------------
// Child: note
// -----------------------------------------------------------------------------

// Has
int
ExforDataSetNoteHas(ConstHandle2ConstExforDataSet self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"NoteHas", self, extract::note);
}

// Get, const
Handle2ConstNote
ExforDataSetNoteGetConst(ConstHandle2ConstExforDataSet self)
{
   return detail::getField<CPP,Handle2ConstNote>
      (CLASSNAME, CLASSNAME+"NoteGetConst", self, extract::note);
}

// Get, non-const
Handle2Note
ExforDataSetNoteGet(ConstHandle2ExforDataSet self)
{
   return detail::getField<CPP,Handle2Note>
      (CLASSNAME, CLASSNAME+"NoteGet", self, extract::note);
}

// Set
void
ExforDataSetNoteSet(ConstHandle2ExforDataSet self, ConstHandle2ConstNote note)
{
   detail::setField<CPP,CPPNote>
      (CLASSNAME, CLASSNAME+"NoteSet", self, extract::note, note);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/documentation/ExforDataSet/src/custom.cpp"
