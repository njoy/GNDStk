
********************************************************************************
**Introduction**
********************************************************************************

========================================
Background
========================================

The Generalized Nuclear Database Structure, or GNDS, started at Lawrence
Livermore National Laboratory as an effort to update their ENDL format.
Realizing that they could also modernize the ENDF format for nuclear data,
and make this modernization useful and available to everyone, GNDS has
evolved to contain evaluated data, processed data, and application data,
and has become an international standard as part of the OECD/NEA.


========================================
Description
========================================

**Los Alamos National Laboratory's GNDS Toolkit**, or GNDStk, was designed first
and foremost to provide a powerful, intuitive, and flexible C++ API for
interacting with GNDS data.

Our **Core Interface** allows for version-independent access to all content in
any GNDS file, as well as capabilities to read, write, and modify GNDS content.
We support both a more-traditional C++ API design in which users can interact
with classes and functions in the usual fashion, and also a powerful and easily
extensible "query system" for retrieving (and creating) content.

Our **High-Level Interface** can be thought of as consisting of three parts:

First, it supports constructs such as a Component base class that can
add value to any GNDS data classes that one might create to represent various
GNDS elements. (We'll sometimes write *element* to mean GNDS data as it would
appear in an XML "element," but with the understanding that GNDS data need not,
of course, originate from an XML source.)
Notably, and with support from the Core Interface, native
support is available with regards to the concepts of a *required field*, an
*optional field*, and an *optional, with default* field. Here, *field* can mean
something from a node's (element's) metadata (called *attributes* in XML), or
from its own child nodes (XML nested elements).

Second, we'll design GNDS version-specific collections of high-level classes
that represent important elements in the GNDS version in question. Assuming that
GNDS specifications don't change a great deal between versions, we'll expect to
see a great deal of overlap of such classes across versions. GNDStk will,
fortunately, handle such issues efficiently, and do so in a manner that's
entirely transparent to users.

Third, we'll provide a suite of Python bindings to the C++ functionality in
our version-specific interfaces, and perhaps, where possible and useful, to
selected lower-level Core Interface constructs as well.



========================================
Acknowledgements
========================================

Special thanks to: Jeremy Conlin, Wim Haeck, Nathan Gibson, and Patrick Talou.
