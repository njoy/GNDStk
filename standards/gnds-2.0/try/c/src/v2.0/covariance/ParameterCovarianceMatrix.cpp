
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "try/v2_0/covariance/ParameterCovarianceMatrix.hpp"
#include "ParameterCovarianceMatrix.h"

using namespace njoy::GNDStk;
using namespace try::v2_0;

using C = ParameterCovarianceMatrixClass;
using CPP = multigroup::ParameterCovarianceMatrix;

static const std::string CLASSNAME = "ParameterCovarianceMatrix";

namespace extract {
   static auto label = [](auto &obj) { return &obj.label; };
   static auto type = [](auto &obj) { return &obj.type; };
   static auto parameters = [](auto &obj) { return &obj.parameters; };
   static auto array = [](auto &obj) { return &obj.array; };
}

using CPPParameters = covariance::Parameters;
using CPPArray = containers::Array;


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

// Create, default
Handle2ParameterCovarianceMatrix
ParameterCovarianceMatrixDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstParameterCovarianceMatrix
ParameterCovarianceMatrixCreateConst(
   const XMLName label,
   const XMLName type,
   ConstHandle2ConstParameters parameters,
   ConstHandle2ConstArray array
) {
   ConstHandle2ParameterCovarianceMatrix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      label,
      type,
      detail::tocpp<CPPParameters>(parameters),
      detail::tocpp<CPPArray>(array)
   );
   return handle;
}

// Create, general
Handle2ParameterCovarianceMatrix
ParameterCovarianceMatrixCreate(
   const XMLName label,
   const XMLName type,
   ConstHandle2ConstParameters parameters,
   ConstHandle2ConstArray array
) {
   ConstHandle2ParameterCovarianceMatrix handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      label,
      type,
      detail::tocpp<CPPParameters>(parameters),
      detail::tocpp<CPPArray>(array)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
ParameterCovarianceMatrixAssign(ConstHandle2ParameterCovarianceMatrix This, ConstHandle2ConstParameterCovarianceMatrix from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", This, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
ParameterCovarianceMatrixDelete(ConstHandle2ConstParameterCovarianceMatrix This)
{
   detail::deleteHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Delete", This);
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
ParameterCovarianceMatrixRead(ConstHandle2ParameterCovarianceMatrix This, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", This, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
ParameterCovarianceMatrixWrite(ConstHandle2ConstParameterCovarianceMatrix This, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", This, filename);
}

// Print to standard output, in our prettyprinting format
int
ParameterCovarianceMatrixPrint(ConstHandle2ConstParameterCovarianceMatrix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", This);
}

// Print to standard output, as XML
int
ParameterCovarianceMatrixPrintXML(ConstHandle2ConstParameterCovarianceMatrix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", This, "XML");
}

// Print to standard output, as JSON
int
ParameterCovarianceMatrixPrintJSON(ConstHandle2ConstParameterCovarianceMatrix This)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", This, "JSON");
}


// -----------------------------------------------------------------------------
// Metadatum: label
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceMatrixLabelHas(ConstHandle2ConstParameterCovarianceMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"LabelHas", This, extract::label);
}

// Get
// Returns by value
XMLName
ParameterCovarianceMatrixLabelGet(ConstHandle2ConstParameterCovarianceMatrix This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"LabelGet", This, extract::label);
}

// Set
void
ParameterCovarianceMatrixLabelSet(ConstHandle2ParameterCovarianceMatrix This, const XMLName label)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"LabelSet", This, extract::label, label);
}


// -----------------------------------------------------------------------------
// Metadatum: type
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceMatrixTypeHas(ConstHandle2ConstParameterCovarianceMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"TypeHas", This, extract::type);
}

// Get
// Returns by value
XMLName
ParameterCovarianceMatrixTypeGet(ConstHandle2ConstParameterCovarianceMatrix This)
{
   return detail::getField<CPP>
      (CLASSNAME, CLASSNAME+"TypeGet", This, extract::type);
}

// Set
void
ParameterCovarianceMatrixTypeSet(ConstHandle2ParameterCovarianceMatrix This, const XMLName type)
{
   detail::setField<CPP>
      (CLASSNAME, CLASSNAME+"TypeSet", This, extract::type, type);
}


// -----------------------------------------------------------------------------
// Child: parameters
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceMatrixParametersHas(ConstHandle2ConstParameterCovarianceMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ParametersHas", This, extract::parameters);
}

// Get, const
Handle2ConstParameters
ParameterCovarianceMatrixParametersGetConst(ConstHandle2ConstParameterCovarianceMatrix This)
{
   return detail::getField<CPP,Handle2ConstParameters>
      (CLASSNAME, CLASSNAME+"ParametersGetConst", This, extract::parameters);
}

// Get, non-const
Handle2Parameters
ParameterCovarianceMatrixParametersGet(ConstHandle2ParameterCovarianceMatrix This)
{
   return detail::getField<CPP,Handle2Parameters>
      (CLASSNAME, CLASSNAME+"ParametersGet", This, extract::parameters);
}

// Set
void
ParameterCovarianceMatrixParametersSet(ConstHandle2ParameterCovarianceMatrix This, ConstHandle2ConstParameters parameters)
{
   detail::setField<CPP,CPPParameters>
      (CLASSNAME, CLASSNAME+"ParametersSet", This, extract::parameters, parameters);
}


// -----------------------------------------------------------------------------
// Child: array
// -----------------------------------------------------------------------------

// Has
int
ParameterCovarianceMatrixArrayHas(ConstHandle2ConstParameterCovarianceMatrix This)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ArrayHas", This, extract::array);
}

// Get, const
Handle2ConstArray
ParameterCovarianceMatrixArrayGetConst(ConstHandle2ConstParameterCovarianceMatrix This)
{
   return detail::getField<CPP,Handle2ConstArray>
      (CLASSNAME, CLASSNAME+"ArrayGetConst", This, extract::array);
}

// Get, non-const
Handle2Array
ParameterCovarianceMatrixArrayGet(ConstHandle2ParameterCovarianceMatrix This)
{
   return detail::getField<CPP,Handle2Array>
      (CLASSNAME, CLASSNAME+"ArrayGet", This, extract::array);
}

// Set
void
ParameterCovarianceMatrixArraySet(ConstHandle2ParameterCovarianceMatrix This, ConstHandle2ConstArray array)
{
   detail::setField<CPP,CPPArray>
      (CLASSNAME, CLASSNAME+"ArraySet", This, extract::array, array);
}