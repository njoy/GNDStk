
********************************************************************************
**Introduction**
********************************************************************************


========================================
Description
========================================

**Los Alamos National Laboratory's GNDS Toolkit**, or GNDStk, has been designed
first and foremost to provide a powerful, intuitive, and flexible C++ language
API for interacting with Generalized Nuclear Database Structure data.

We begin by providing basic and cleanly-designed classes in which GNDS data are
stored. Next, we support a robust and flexible I/O system for reading from, and
writing to, both the XML and JSON file formats. Support for more file formats
is anticipated in the future, as GNDS becomes more widely used.

While GNDStk is *one* library, from which you can use any functionality you
wish to at any time, we consider it conceptually to consist of roughly three
major parts: basic constructs and I/O; a "core" interface, and a higher-level
interface that will also be equipped with Python bindings for users who wish
to take advantage of them. Let's say a bit more about all of these elements.


**BASICS**

Here we have the basic requisite data structures and functions, as well as
flexible and easy-to-use GNDS file I/O capabilities. Along with these also come,
of course, the numerous and sundry utilities needed for their implementation.
Some of the utilities, e.g. those for generating diagnostic messages such as
warnings and errors, may be of value in their own right to our users. We'll
therefore provide some documentation of how selected utility constructs work,
without distracting us from our focus on GNDStk's major, most interesting
capabilities.


**CORE INTERFACE**

The heart of GNDStk lies in its Core Interface. Consider this interface to
*include* the basics as described above, while adding to them a powerful,
flexible, and highly user-programmable suite of *data query* and *creation*
capabilities that can be used to great effect by themselves if you wish -- given
some knowledge of the GNDS hierarchy's internal structure -- and also for
creating higher-level interfaces like our own.

Our Core Interface allows for version-independent access to all data in any
GNDS file, including functionality for reading, writing, and modification.

We support both a more-traditional C++ API design, in which users can interact
with classes and functions in the usual fashion (largely through the Basics as
described above), as well as a
powerful and easily extensible "query system" for retrieving or creating GNDS
content. The query system is, in particular, quite intentionally designed to
enable you to integrate GNDStk's capabilities easily into virtually any other
code in which you might wish to use it -- code that utilizes entirely your own
data structures, perhaps, or those of any other library or libraries
with which you may be working.


**HIGH-LEVEL INTERFACE**

While still a work-in-progress at the time of this writing, GNDStk's High-Level
Interface will be comprised of several elements.

First, we'll provide one or more C++ base classes that are designed to provide
value to high-level derived classes that one might wish to create, individually
or *en masse*, to represent GNDS data structures. Note that, here, our use of
the word *derived* refers to *derived classes* in C++ -- not, say, to nuclear
data that were *derived* in some sense from other nuclear data.

Notably, and with support from the Core Interface, proper handling will be made
available for capturing the concepts of a *required field*, an *optional field*,
and an *optional, with default* field in a GNDS data structure. Here, and
thinking in the language of XML, *field* may mean something from an XML
element's attributes (we'll prefer the non-XML-specific term *metadata* in
GNDStk), or from its nested XML elements -- *child nodes*, in our preferred
terminology.

An additional note regarding terminology: We may occasionally write *element*
to mean GNDS data as it would appear in an XML element, if and when the term
works well in the narrative, but do so with the understanding that GNDS data
need not, of course, originate from an XML source, or be intended for an XML
destination.

We'll also design GNDS version-specific collections of high-level classes that
represent important data structures for the GNDS version in question. Assuming
that the GNDS specifications don't change a great deal between releases, we'll
expect to see substantial overlap, across our version-specific collections, of
these classes. GNDStk will, naturally, handle such issues efficiently, and will
do so in a manner that's entirely transparent to users. We'll focus on making
our capabilities work well, so that you can focus similarly on yours.

Finally, but no less significantly for many of GNDStk's intended beneficiaries,
we'll provide a suite of Python bindings to much of our C++ functionality. That
will include, certainly, the major classes in our version-specific interfaces,
and perhaps also -- where reasonable and possible, given differences between
Python and C++ as well as their respective limitations - to selected fabulous
and action-packed lower-level Core Interface constructs as well.


========================================
Background
========================================

The Generalized Nuclear Database Structure, or GNDS, started at Lawrence
Livermore National Laboratory as an effort to update their ENDL format.
Realizing that they could also modernize the ENDF format for nuclear data,
and make this modernization useful and available to everyone, they evolved
GNDS to contain evaluated data, processed data, and application data. GNDS
has become an international standard as part of the OECD/NEA.


========================================
Acknowledgements
========================================

The author wishes to thank several individuals for the support and ideas that
they provided throughout this endeavor. An introduction to GNDS, to the broader
NJOY21 project, and to the need for quality software for working with the GNDS
format, was provided by Nuclear Data team leader Jeremy Conlin. Materials and
Physical Data (XCP-5) group leader Patrick Talou tirelessly ensured financial
support for the project, and positive encouragement for its personnel. Nathan
Gibson constructed the build system currently in use not only for GNDStk but
for many other elements of NJOY21. Finally, Wim Haeck was a source of copious
and invaluable comments, ideas, and discussions, without which GNDStk wouldn't
be what it is today.

**Martin Staley, Los Alamos National Laboratory, February 2021**
