
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include "test/v2.0/transport/IncompleteReactions.hpp"
#include "IncompleteReactions.h"

using namespace njoy::GNDStk;
using namespace test::v2_0;

using C = IncompleteReactionsClass;
using CPP = multigroup::IncompleteReactions;

static const std::string CLASSNAME = "IncompleteReactions";

namespace extract {
   static auto reaction = [](auto &obj) { return &obj.reaction; };
}

using CPPReaction = transport::Reaction;


// -----------------------------------------------------------------------------
// Basics
// Create, Assign, Delete
// -----------------------------------------------------------------------------

// Create, default, const
Handle2ConstIncompleteReactions
IncompleteReactionsDefaultConst()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"DefaultConst");
}

// Create, default
Handle2IncompleteReactions
IncompleteReactionsDefault()
{
   return detail::createHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Default");
}

// Create, general, const
Handle2ConstIncompleteReactions
IncompleteReactionsCreateConst(
   ConstHandle2ConstReaction reaction
) {
   ConstHandle2IncompleteReactions handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"CreateConst",
      detail::tocpp<CPPReaction>(reaction)
   );
   return handle;
}

// Create, general
Handle2IncompleteReactions
IncompleteReactionsCreate(
   ConstHandle2ConstReaction reaction
) {
   ConstHandle2IncompleteReactions handle = detail::createHandle<CPP,C>(
      CLASSNAME, CLASSNAME+"Create",
      detail::tocpp<CPPReaction>(reaction)
   );
   return handle;
}

// Assign
// Use this to assign one handled object to another. Don't assign handles,
// as with to = from. That has a meaning that you probably don't intend.
void
IncompleteReactionsAssign(ConstHandle2IncompleteReactions self, ConstHandle2ConstIncompleteReactions from)
{
   detail::assignHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Assign", self, from);
}

// Delete
// We'll attempt to remove no-longer-used objects automatically, but you
// may improve performance if you delete them when you're done with them.
void
IncompleteReactionsDelete(ConstHandle2ConstIncompleteReactions self)
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
IncompleteReactionsRead(ConstHandle2IncompleteReactions self, const char *const filename)
{
   return detail::readHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Read", self, filename);
}

// Write to file
// File can be XML, JSON, or HDF5.
// We'll use filename's extension to determine the type you want written.
int
IncompleteReactionsWrite(ConstHandle2ConstIncompleteReactions self, const char *const filename)
{
   return detail::writeHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Write", self, filename);
}

// Print to standard output, in our prettyprinting format
int
IncompleteReactionsPrint(ConstHandle2ConstIncompleteReactions self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"Print", self);
}

// Print to standard output, as XML
int
IncompleteReactionsPrintXML(ConstHandle2ConstIncompleteReactions self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintXML", self, "XML");
}

// Print to standard output, as JSON
int
IncompleteReactionsPrintJSON(ConstHandle2ConstIncompleteReactions self)
{
   return detail::printHandle<CPP,C>
      (CLASSNAME, CLASSNAME+"PrintJSON", self, "JSON");
}


// -----------------------------------------------------------------------------
// Child: reaction
// -----------------------------------------------------------------------------

// Has
int
IncompleteReactionsReactionHas(ConstHandle2ConstIncompleteReactions self)
{
   return detail::hasField<CPP>
      (CLASSNAME, CLASSNAME+"ReactionHas", self, extract::reaction);
}

// Get, const
Handle2ConstReaction
IncompleteReactionsReactionGetConst(ConstHandle2ConstIncompleteReactions self)
{
   return detail::getField<CPP,Handle2ConstReaction>
      (CLASSNAME, CLASSNAME+"ReactionGetConst", self, extract::reaction);
}

// Get, non-const
Handle2Reaction
IncompleteReactionsReactionGet(ConstHandle2IncompleteReactions self)
{
   return detail::getField<CPP,Handle2Reaction>
      (CLASSNAME, CLASSNAME+"ReactionGet", self, extract::reaction);
}

// Set
void
IncompleteReactionsReactionSet(ConstHandle2IncompleteReactions self, ConstHandle2ConstReaction reaction)
{
   detail::setField<CPP,CPPReaction>
      (CLASSNAME, CLASSNAME+"ReactionSet", self, extract::reaction, reaction);
}


// -----------------------------------------------------------------------------
// Custom functionality
// -----------------------------------------------------------------------------

#include "v2.0/transport/IncompleteReactions/src/custom.cpp"
