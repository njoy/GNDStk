
// -----------------------------------------------------------------------------
// Tree::zero()
// See also: Tree::top()
// -----------------------------------------------------------------------------

/*
// ------------------------
// Description
// ------------------------

GNDS is billed as being a "database structure" or a "hierarchy," and as not
being stored in, or bound to, a particular file format.

As such, a variety of different types of files, including XML, JSON, and HDF5,
can be used to store a GNDS hierarchy.

Although GNDS is not, then, tied to a particular file format, a user who reads
an existing GNDS hierarchy is reading it from a file of some particular format;
and a user who builds a brand-new GNDS hierarchy may (or may not) plan to write
it to a particular format.

GNDStk's "tree" data structure is designed to hold a GNDS hierarchy - which,
from a GNDS standpoint, begins with any one of a few available "top-level"
nodes: reactionSuite, covarianceSuite, etc.

In order to keep track of the particular type of file (XML etc.) that someone
reads from (in case such information proves to be useful), and to keep track
of what format someone may want to write in (in case such information proves
to be useful), GNDStk's tree structure places what we'll call a "zero-level
node" just above the standard GNDS top-level node.

Our terminology - "zero-level node" - can be thought of as being analogous to
C/C++ array-like containers being indexed by [0]. It's an easy term to remember,
and one that we don't believe would easily be confused to mean the top-level
GNDS node.

In respect of the above remarks, then, we provide the following functions for
accessing what could be described as top-level tree information:

   zero()
      Our zero-level node.
      Example contents:
         name: "xml"
         metadata: {{"version","1.0"},{"encoding","UTF-8"}}
         children: "reactionSuite" // as below

   top()
      The top-level GNDS node.
      Example contents:
         name: "reactionSuite"
         metadata: {{"projectile","He4"},{"target","He4"},...}
         children: "styles", "documentations", "PoPs", "reactions"

Each, of course, has a const version and a non-const version.

Importantly, our various functions for searching and drilling into GNDS trees
bypass the zero-level node - precisely because it's our own construct, not one
in GNDS. So, a user doesn't even need to know that it's there. It *is* there,
however, waiting to be used, if/when the information it holds might be useful.
*/


// non-const
nodeType &zero()
{
   assert(not empty());
   return *root;
}

// const
const nodeType &zero() const
{
   assert(not empty());
   return *root;
}
