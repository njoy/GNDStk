
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "GNDS/v2.0/general/ParameterCovarianceMatrix.hpp"
#include "ParameterCovarianceMatrix.h"

using namespace njoy::GNDStk;
using namespace GNDS::v2_0;

using C = ParameterCovarianceMatrixClass;
using CPP = multigroup::ParameterCovarianceMatrix;

static const std::string CLASSNAME = "ParameterCovarianceMatrix";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto type = [](auto &obj) { return &obj.type; };
   static auto array = [](auto &obj) { return &obj.array; };
   static auto parameters = [](auto &obj) { return &obj.parameters; };
}

using CPPArray = g3d::Array;
using CPPParameters = general::Parameters;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstParameterCovarianceMatrix
ParameterCovarianceMatrixDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default, non-const
Handle2ParameterCovarianceMatrix
ParameterCovarianceMatrixDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstParameterCovarianceMatrix
ParameterCovarianceMatrixCreateConst(
   const char *const label,
   const char *const type,
   ConstHandle2ConstArray array,
   ConstHandle2ConstParameters parameters
) {
   ConstHandle2ParameterCovarianceMatrix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      type,
      detail::tocpp<CPPArray>(array),
      detail::tocpp<CPPParameters>(parameters)
   );
   return handle;
}

// Create, general, non-const
Handle2ParameterCovarianceMatrix
ParameterCovarianceMatrixCreate(
   const char *const label,
   const char *const type,
   ConstHandle2ConstArray array,
   ConstHandle2ConstParameters parameters
) {
   ConstHandle2ParameterCovarianceMatrix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      type,
      detail::tocpp<CPPArray>(array),
      detail::tocpp<CPPParameters>(parameters)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ParameterCovarianceMatrixAssign(ConstHandle2ParameterCovarianceMatrix self, ConstHandle2ConstParameterCovarianceMatrix from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ParameterCovarianceMatrixDelete(ConstHandle2ConstParameterCovarianceMatrix self)
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
ParameterCovarianceMatrixRead(ConstHandle2ParameterCovarianceMatrix self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ParameterCovarianceMatrixWrite(ConstHandle2ConstParameterCovarianceMatrix self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
ParameterCovarianceMatrixPrint(ConstHandle2ConstParameterCovarianceMatrix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
ParameterCovarianceMatrixPrintXML(ConstHandle2ConstParameterCovarianceMatrix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
ParameterCovarianceMatrixPrintJSON(ConstHandle2ConstParameterCovarianceMatrix self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceMatrixLabelHas(ConstHandle2ConstParameterCovarianceMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", self, extract::label);
}

// Get
// Returns by value
const char *
ParameterCovarianceMatrixLabelGet(ConstHandle2ConstParameterCovarianceMatrix self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", self, extract::label);
}

// Set
void
ParameterCovarianceMatrixLabelSet(ConstHandle2ParameterCovarianceMatrix self, const char *const label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", self, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: type
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceMatrixTypeHas(ConstHandle2ConstParameterCovarianceMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TypeHas", self, extract::type);
}

// Get
// Returns by value
const char *
ParameterCovarianceMatrixTypeGet(ConstHandle2ConstParameterCovarianceMatrix self)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"TypeGet", self, extract::type);
}

// Set
void
ParameterCovarianceMatrixTypeSet(ConstHandle2ParameterCovarianceMatrix self, const char *const type)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"TypeSet", self, extract::type, type);
}


// -----------------------------------------------------------------------------
// Child: array
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceMatrixArrayHas(ConstHandle2ConstParameterCovarianceMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHas", self, extract::array);
}

// Get, const
Handle2ConstArray
ParameterCovarianceMatrixArrayGetConst(ConstHandle2ConstParameterCovarianceMatrix self)
{
   return detail::getField<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetConst", self, extract::array);
}

// Get, non-const
Handle2Array
ParameterCovarianceMatrixArrayGet(ConstHandle2ParameterCovarianceMatrix self)
{
   return detail::getField<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGet", self, extract::array);
}

// Set
void
ParameterCovarianceMatrixArraySet(ConstHandle2ParameterCovarianceMatrix self, ConstHandle2ConstArray array)
{
   detail::setField<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySet", self, extract::array, array);
}


// -----------------------------------------------------------------------------
// Child: parameters
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceMatrixParametersHas(ConstHandle2ConstParameterCovarianceMatrix self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ParametersHas", self, extract::parameters);
}

// Get, const
Handle2ConstParameters
ParameterCovarianceMatrixParametersGetConst(ConstHandle2ConstParameterCovarianceMatrix self)
{
   return detail::getField<CPP,Handle2ConstParameters>
      (CLASSNAME, CLASSNAME+"ParametersGetConst", self, extract::parameters);
}

// Get, non-const
Handle2Parameters
ParameterCovarianceMatrixParametersGet(ConstHandle2ParameterCovarianceMatrix self)
{
   return detail::getField<CPP,Handle2Parameters>
      (CLASSNAME, CLASSNAME+"ParametersGet", self, extract::parameters);
}

// Set
void
ParameterCovarianceMatrixParametersSet(ConstHandle2ParameterCovarianceMatrix self, ConstHandle2ConstParameters parameters)
{
   detail::setField<CPP,CPPParameters>
      (CLASSNAME, CLASSNAME+"ParametersSet", self, extract::parameters, parameters);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/general/ParameterCovarianceMatrix/src/custom.cpp"