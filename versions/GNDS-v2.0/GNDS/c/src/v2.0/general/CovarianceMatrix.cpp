
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/CovarianceMatrix.hpp"
#include "CovarianceMatrix.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = CovarianceMatrixClass;
using CPP = multigroup::CovarianceMatrix;

static const std::string CLASSNAME = "CovarianceMatrix";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto type = [](auto &obj) { return &obj.type; };
   static auto productFrame = [](auto &obj) { return &obj.productFrame; };
   static auto gridded2d = [](auto &obj) { return &obj.gridded2d; };
}

using CPPGridded2d = general::Gridded2d;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstCovarianceMatrix
CovarianceMatrixDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2CovarianceMatrix
CovarianceMatrixDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstCovarianceMatrix
CovarianceMatrixCreateConst(
   const char *const label,
   const char *const type,
   const char *const productFrame,
   ConstHandle2ConstGridded2d gridded2d
) {
   ConstHandle2CovarianceMatrix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      type,
      productFrame,
      detail::tocpp<CPPGridded2d>(gridded2d)
   );
   return handle;
}

// Create, general, non-const
Handle2CovarianceMatrix
CovarianceMatrixCreate(
   const char *const label,
   const char *const type,
   const char *const productFrame,
   ConstHandle2ConstGridded2d gridded2d
) {
   ConstHandle2CovarianceMatrix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      type,
      productFrame,
      detail::tocpp<CPPGridded2d>(gridded2d)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
CovarianceMatrixAssign(ConstHandle2CovarianceMatrix self, ConstHandle2ConstCovarianceMatrix from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
CovarianceMatrixDelete(ConstHandle2ConstCovarianceMatrix self)
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
CovarianceMatrixRead(ConstHandle2CovarianceMatrix self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
CovarianceMatrixWrite(ConstHandle2ConstCovarianceMatrix self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
CovarianceMatrixPrint(ConstHandle2ConstCovarianceMatrix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
CovarianceMatrixPrintXML(ConstHandle2ConstCovarianceMatrix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
CovarianceMatrixPrintJSON(ConstHandle2ConstCovarianceMatrix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
CovarianceMatrixLabelHas(ConstHandle2ConstCovarianceMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
CovarianceMatrixLabelGet(ConstHandle2ConstCovarianceMatrix self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
CovarianceMatrixLabelSet(ConstHandle2CovarianceMatrix self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: type
// -----------------------------------------------------------------------------

// Has
int
CovarianceMatrixTypeHas(ConstHandle2ConstCovarianceMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TypeHas", self, extract::type);
}

// Get
// Returns by value
const char *
CovarianceMatrixTypeGet(ConstHandle2ConstCovarianceMatrix self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"TypeGet", self, extract::type);
}

// Set
void
CovarianceMatrixTypeSet(ConstHandle2CovarianceMatrix self, const char *const type)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"TypeSet", self, extract::type, type);
}


// -----------------------------------------------------------------------------
// Metadatum: productFrame
// -----------------------------------------------------------------------------

// Has
int
CovarianceMatrixProductFrameHas(ConstHandle2ConstCovarianceMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameHas", self, extract::productFrame);
}

// Get
// Returns by value
const char *
CovarianceMatrixProductFrameGet(ConstHandle2ConstCovarianceMatrix self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameGet", self, extract::productFrame);
}

// Set
void
CovarianceMatrixProductFrameSet(ConstHandle2CovarianceMatrix self, const char *const productFrame)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"ProductFrameSet", self, extract::productFrame, productFrame);
}


// -----------------------------------------------------------------------------
// Child: gridded2d
// -----------------------------------------------------------------------------

// Has
int
CovarianceMatrixGridded2dHas(ConstHandle2ConstCovarianceMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"Gridded2dHas", self, extract::gridded2d);
}

// Get, const
Handle2ConstGridded2d
CovarianceMatrixGridded2dGetConst(ConstHandle2ConstCovarianceMatrix self)
{
   return detail::getField<CPP,Handle2ConstGridded2d>
      (CLASSNAME, CLASSNAME+"Gridded2dGetConst", self, extract::gridded2d);
}

// Get, non-const
Handle2Gridded2d
CovarianceMatrixGridded2dGet(ConstHandle2CovarianceMatrix self)
{
   return detail::getField<CPP,Handle2Gridded2d>
      (CLASSNAME, CLASSNAME+"Gridded2dGet", self, extract::gridded2d);
}

// Set
void
CovarianceMatrixGridded2dSet(ConstHandle2CovarianceMatrix self, ConstHandle2ConstGridded2d gridded2d)
{
   detail::setField<CPP,CPPGridded2d>
      (CLASSNAME, CLASSNAME+"Gridded2dSet", self, extract::gridded2d, gridded2d);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/CovarianceMatrix/src/custom.cpp"
