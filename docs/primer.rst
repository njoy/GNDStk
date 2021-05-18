
********************************************************************************
**Tutorial**
********************************************************************************

========================================
Basics + Core Interface
========================================

Let's begin with some very minimal GNDStk-based example codes, explain our
arrangement of major C++ namespaces, and then move on to more-interesting
and useful examples.



--------------------------------
Minimal GNDStk-Aware Code
--------------------------------

Here's the most minimal GNDStk "application", albeit one that doesn't
do anything:

.. literalinclude:: tutorial/minimal.cpp
   :language: cpp

The takeaway: to use GNDStk, you should ``#include`` its one
primary header file, ``GNDStk.hpp``. In contrast to the manner in which
some C++ libraries
are designed, GNDStk provides just this one main header file for user
consumption. That header, in turn, includes all of GNDStk's other headers,
and in the correct manner with respect to namespaces and such.

Put another way, GNDStk is *not* designed, as some libraries are, so that you
selectively choose what headers to ``#include``. When we use the C++ Standard
Library, for instance, we'll pick and choose: include ``iostream``, most likely,
and perhaps ``vector``, and any number of additional specific chosen headers.

The entire C++ Standard library is very large, of course, and such selectivity
is important so that compile times are kept under control. GNDStk is much
smaller, and we've judged that compilation times aren't significantly impacted
by putting forth our simple, easily followed rule: just
``#include GNDStk.hpp`` -- nothing more, nothing less -- in whichever of your
own source files need it.



--------------------------------
Recommended Starting Point
--------------------------------

**For most users, most of the time, we suggest this starting point:**

.. literalinclude:: tutorial/minimal-recommended.cpp
   :language: cpp

This merely adds a specific ``using`` directive to the previous example.
To understand what this directive does for us, we need to understand GNDStk's
namespace hierarchy.



--------------------------------
Namespace Hierarchy
--------------------------------

GNDStk, like many C++ libraries, places its various constructs into a moderate
number of C++ namespaces. For simplicity's sake, omitting details that most
users won't care about, consider that GNDStk's namespace hierarchy looks
something like this:

.. literalinclude:: tutorial/main-namespaces.hpp
   :language: cpp

A few things are happening here, so bear with us.

For starters, everything is in ``njoy::GNDStk::``. That's easy enough to
understand. Notably, however: considering that a typical C++ library will often
begin, at global scope, with a namespace that matches the library's name, it's
laughably easy to forget the ``njoy::`` part. We've made that mistake several
times, ourselves. We have the ``njoy::`` only because GNDStk is just one element
of Los Alamos National Laboratory's broader NJOY suite of software projects.
If -- well, when -- you ever forget the ``njoy::``, a modern C++ compiler may
suggest, in its initial error message (before its flood of spurious ones), that
you probably meant the ``GNDStk::`` in ``njoy::``.

Fundamentally important in GNDStk are its "query objects". Think of these as
small modules of information that facilitate a concise notation for getting
(or setting) GNDS data. (Much more on all of this later.) For now, suffice it
to say that the query objects of most interest to users are our *basic* ones
in -- drum roll, please -- ``basic::``. Within ``basic::``, query objects are
further placed into ``meta::`` or ``child::``, depending on whether they're
designed for getting and setting *metadata*, or for getting and setting *child
nodes*. Names for our query objects equate, except in certain rare cases, to
the GNDS names of the metadata and child nodes with which they interact. For
example, a GNDS ``label`` metadatum is called ``label`` in GNDStk's query
objects, and a GNDS ``styles`` node is called ``styles``.

Strangely -- at first glance -- ``basic::`` has ``using`` directives for its
own ``meta::`` and ``child::`` sub-namespaces! Why not place the contents
of those directly into ``basic::`` to begin with, and dispense with the
sub-namespaces altogether? It turns out, in fact, that the GNDS standard has
a small amount of overlap between its names for metadata, and its names for
nodes. Two examples are ``parity`` and ``spin``. If, for example, you look
through the currently available XML-format GNDS files, you'll see XML
``spin="something"`` metadata, and also XML
``<spin>`` elements. Our arrangement for
``basic::``, ``meta::`` and ``child::`` is such that if you're
``using namespace basic``, you can dispense with a ``meta::`` or ``child::``
prefix where
names are unique (``styles``, ``label``, and most other names),
or prefix appropriately in the occasional cases where they aren't:
``meta::spin`` for spin metadata, ``child::spin`` for spin nodes, and so forth.

``basic::`` is one of two namespaces (at the time of this writing) into which
we've placed full sets of query objects for GNDS metadata and child nodes.
(Don't worry, for now, about the other set. We may even remove it, as other
capabilities of GNDStk have made it less worthwhile to have than it once was.)
A third namespace, ``common::``, contains a small handful (not a complete set)
of query objects that are intended for use with *both* of the two full sets.
In addition to ``using`` its own ``meta::`` and ``child::`` sub-namespaces
for the reasons we described above, ``basic::`` also brings in the contents
of ``common::``, so that no ``common::`` prefix is needed when you're
``using namespace basic``.

A namespace ``log::`` also exists in GNDStk. We'll discuss it elsewhere, but
mention it here only because (1) you may occasionally find its contents to be
useful for your own purposes; and (2) it serves, in contrast to the other
namespaces being discussed here, as an example of something that *isn't*
included automatically by our ``core::`` namespace. We don't consider it to
be useful enough, for the average user, to justify cluttering ``core::`` with
its contents. If and when you need it, ``log::`` is short, and easy to type.



--------------------------------
Core Interface
--------------------------------

That brings us, finally, to the ``core::`` namespace that we called out, in our
example code, as being precisely what we suggest that most users bring in:

.. literalinclude:: tutorial/core-using.hpp
   :language: cpp

``core::`` is little more than this:

.. literalinclude:: tutorial/core-only.hpp
   :language: cpp

So, ``core::`` brings in ``basic::``, which as we saw above brings in its own
``meta::`` and ``child::`` sub-namespaces, as well as the (modest but useful)
content in ``common::``. On top of that, ``core::`` actually brings in
``GNDStk::`` (that is, ``njoy::GNDStk::``), even though ``core::`` itself in
*inside of* ``njoy::GNDStk::``! (The language does allow that.)

All things considered, then, the single directive
``using namespace njoy::GNDStk::core`` brings in *all* content from:

.. code::

   njoy::GNDStk::
   njoy::GNDStk::basic::
   njoy::GNDStk::basic::meta::
   njoy::GNDStk::basic::child::
   njoy::GNDStk::common::

with the single caveat we spoke of already in regards to ``basic::`` -- that in
the rare but occasional cases of overlap (``meta::spin`` vs. ``child::spin``,
for instance, or ``meta::parity`` vs. ``child::parity``), you must disambiguate.
And the compiler will tell you as much, as it'll be an error until you do.

The combined content of the above-listed namespaces constitute what we consider
to be a good set of *core* GNDStk capabilities. Hence, our motivation for
creating a ``core::`` namespace that brings all of them into your code,
together, via the one convenient directive that we've recommended.

You can consider the phrases *core namespace* and *core interface* to be
essentially interchangeable. Which term we use, and where, depends on whether
we're referring to the namespace in particular, or to the functionality it
exposes.

We'll note, finally, that having (and recommending) our ``core::`` namespace
is helpful from the standpoint of software maintainability. If we decide at
some future time that GNDStk needs a refactor, and/or a rearrangement of its
functionality into a different overarching namespace scheme, we anticipate
being able to update the contents of ``core::`` in such a way that the codes
that use it -- like, we hope, yours -- will need few if any changes, even if
the GNDStk constructs that the codes employ have been moved to entirely new
or different locations.



========================================
Read and Write GNDS
========================================


--------------------------------
Read XML
--------------------------------

Here's a simple code that reads the XML format GNDS file named
``n-094_Pu_239.xml``:

.. literalinclude:: tutorial/basic-read.cpp
   :language: cpp

Obviously, but worth a reminder, this assumes that the file resides right there,
in the directory from which this code is run. If it doesn't, include a suitable
absolute or relative path in the file name string. We, and no doubt everyone
reading this, have probably made this mistake often enough over the years.

``Tree`` is GNDStk's data structure for holding an entire GNDS hierarchy, a.k.a.
GNDS tree. GNDS is, indeed, a tree-like structure, and that's reflected in the
name of our C++ class. Once loaded, you'll be able to do great things -- most
likely, in this particular example, data queries from an existing GNDS file --
with object, ``pu239`` here, into which the GNDS data in the loaded file were
placed.

A large collection of XML-format GNDS files can be downloaded from here:

   https://www.nndc.bnl.gov/endf/b8.0/gndsfiles.html

That's where we got our example's ``n-094_Pu_239.xml``, and many other GNDS
files. At around 24MB in size, it's one of the larger GNDS files from the above
site, but it isn't among the absolute largest. We'll often use it in our
examples; its modest size (by today's standards) should still allow for fast
reading, and we believe that its contents make for good examples. The same,
of course, could probably be said about any GNDS file, depending on what data
are of interest.

While we didn't say so directly, a C++ programmer will have realized what the
above code tells us: that ``Tree`` has a constructor from a character string
(in fact, from a ``std::string``), and for which the behavior is: "interpret
the string as the name of a GNDS file, and load the file." You could write
this instead:

.. literalinclude:: tutorial/basic-read-2.cpp
   :language: cpp

which is more explicit in its purpose, but slightly less concise. (And the
earlier, direct-constructed ``Tree`` could be ``const``, if that matters.)



--------------------------------
Files, Streams, Types
--------------------------------

In terms of what we saw above, ``Tree`` has four similar constructors. (And has
several additional completely different constructors that are outside the scope
of the present discussion).

The first argument is either a file name, or a C++ ``std::istream`` from which
to read the "file." The second argument allows you to stipulate the file format
explicitly, and can either be something from GNDStk's ``FileType`` enumerator:

.. literalinclude:: tutorial/file-types.hpp
   :language: cpp

or can be a direct string: ``"xml"``, etc. A direct string is shorter and
slightly easier to type -- but, if mistyped, would lead to a run-time error,
not a compile-time error, if that matters to you in this simple context.

**HDF5 is not supported at this time!** Just XML and JSON.

*You should seldom, if ever, need to provide the second argument*. Absent the
second argument, **GNDStk determines the file type automatically**, and we doubt
that you'll have any objections to that. If you do choose provide the second
argument, then it, not GNDStk's automatic file type determination, *will* be
used, but you'll see a warning if your directly-given value contradicts GNDStk's
automatic determination, which it still performs for diagnostic purposes. Of
course, if you try to force reading in one format, and the file's actual format
is something else, you'll soon be seeing a flood of errors, not mere warnings,
as we attempt to read the file pursuant to the (incorrect) forced format.

GNDStk uses the "file magic number," not the file name, to determine file type
automatically. The file magic number really means the first byte, or bytes,
of the file. XML files always begin with a ``<`` character. HDF files (not
supported yet) begin with ASCII 137 and a few other specific bytes. If the
first byte is neither of those values, then GNDStk assumes JSON format.

A nice thing about using the file magic number, not the file name, is that
it works for ``std::istream``, for which a "file name" isn't even available.
Moreover, it tells us what's actually in the file or the stream, independent
of what any name might imply. If you provide an XML file but call
it ``something.JSON``, then that
would be a rather strange thing to do, but GNDStk will correctly determine the
actual type -- XML -- and thus read the file correctly. In cases like that,
GNDStk will do an additional good deed: it'll warn you that the file's name
contradicts the file's type as implied by the file magic number.



--------------------------------
Read & Write XML
--------------------------------

Here's a simple example in which we read our trusty example GNDS XML file, then
write it back out to another XML file:

.. literalinclude:: tutorial/basic-rw.cpp
   :language: cpp

You probably already guessed, correctly, that if ``Tree`` has a ``read`` that
reads, then it probably has a ``write`` that writes. We've endeavored to make
GNDStk's design as intuitive and consistent as reasonably possible.

We wrote earlier that GNDStk uses the file magic number, not the file name,
to determine the file type *when reading*. When writing, there is no file magic
number -- the file to be written doesn't exist, yet, or if it does, then its
present contents are meaningless because the file is about to be replaced.

When you call ``write``, therefore, GNDStk does use the file name to determine
what format in which to write, except that you can provide that second argument
again -- a value from our ``FileType`` enumerator, or a string like ``"xml"``
or ``"json"`` -- to specify the type you want directly. As it does for ``read``,
GNDStk makes some consistency checks. If you write, for instance,

.. code::

   pu239.write("pu239.xml", "json");

then GNDStk will write file ``pu239.xml`` in JSON format, as you asked for in
the second argument, but will warn that the file extension is inconsistent with
the format you asked for.

What if the file name extension isn't given, or isn't recognized, *and* a format
isn't forced with a second argument? That is, what if we wrote, for example,
``pu239.write("pu239")``? In that case, ``write`` writes the ``Tree`` into
a simple output format that we created largely for debugging purposes. You
probably won't have much use for this format, and we don't provide the ability
to *read* from it, but you'll no doubt notice the problem quickly and be able
to fix it.

In the above code, what's ``indent`` all about? We didn't really need to clutter
the example by including it, as it isn't required at all, but we wanted to
illustrate something minor but perhaps of interest. ``indent`` is one of a small
handful of useful "global variables" (not truly global, but
in namespace ``njoy::GNDStk::``)
that GNDStk provides to you for fun and profit. Fun, at least. For XML and JSON
output files, as well as for a few other things throughout GNDStk's vast array
of features, ``indent`` tells how many spaces you'd like indentation to be.
GNDStk's default is 3 spaces, which this author happens to prefer. In the
example, we're saying (before the ``write``, of course) that we'd like 2 spaces
to be used. At present, behavior is undefined if you give a negative number, and
of course the output will look ridiculous if you give a huge number. Most people
prefer 2-5 spaces for indentation. In case you're wondering, GNDStk has no
facility for using *tabs* -- an evil creation, quite arguably  -- for this
purpose.

Finally, we note that ``write`` can write to a ``std::ostream``, not just
a file, in much the same way that ``read`` can read from a ``std::istream``,
not just a file. (Always remember: ``ostream`` for writes, ``istream`` for
reads.) Bear in mind, again, that with *output* a file magic number isn't
available, and if you use ``std::ostream``, then a file name, from which we
might guess the format, isn't available either. So, you'll specifically want
to give the second argument -- ``"xml"``, say, or ``"json"`` -- if you write
to a ``std::ostream``.



--------------------------------
More Reads & Writes
--------------------------------

We hope that GNDStk's basic facilities for reading and writing GNDS files are
clear enough at this point, but we'll provide a few more examples nonetheless.
A simple XML to JSON conversion can be done like this:

.. literalinclude:: tutorial/rw-xml-json.cpp
   :language: cpp

Here's a more compact version of the same thing:

.. literalinclude:: tutorial/rw-xml-json-2.cpp
   :language: cpp

Just as we can write JSON, we can read it, too. If we've produced the output
``.json`` file as with the above example, we can read it thus:

.. literalinclude:: tutorial/basic-read-json.cpp
   :language: cpp

Here, as you can see , we've returned to using a "read by constructor," as in
our original XML example, instead of employing a ``read`` call. It's just more
concise, in our opinion. Of course, you'll use -- and should -- whichever
variation you prefer.



--------------------------------
Read, Write, Compare
--------------------------------

We'll wrap up our set of read/write examples with a code that reads our favorite
GNDS XML file, writes it to a JSON file, independently reads the JSON back into
another ``Tree`` object, and then also *compares* the new ``Tree`` to the
original:

.. literalinclude:: tutorial/rw-compare.cpp
   :language: cpp

Several remarks are in order here.

The comparison operator for ``Tree`` compares the two GNDS trees in an
*order-agnostic* manner. GNDS fundamentally provides data in two places: nodes
(think XML "elements") in its overall tree structure, and metadata (think XML
"attributes"). The GNDS standard does not, however, consider ordering to be
important. One tree node's child nodes or metadata, anywhere or everywhere
throughout the entire tree structure, could be reordered arbitrarily, but if
each remains equivalent -- in the same respect that we consider two mathematical
*sets* to be equivalent -- then the two GNDS trees are to be considered
equivalent. So it is with our ``Tree`` comparison.

Interestingly enough, the above example's ``FromXML`` and ``FromJSON`` objects
will, in fact, have quite different orderings, across the board, of child nodes
and metadata! Why is this the case? GNDStk makes use of an external library
called **pugixml** for reading and writing XML files, and an external library
**nlohmann/json**, on Github, for reading and writing JSON files:

   | https://pugixml.org/
   | https://github.com/nlohmann/json

It turns out that pugixml preserves the existing ordering of XML elements and
attributes when it reads a file, while nlohmann/json lexicographically sorts
the JSON name/value pairs by name. The latter library's behavior could be
considered unfortunate if we'd rather see ordering preserved; while the
former library's behavior could be considered unfortunate if we wish to fully
respect GNDS' "no-ordering" rule and discourage the creation of code that might
inadvertently depend on data ordering. In any event, our ``operator==`` for
``Tree`` respects order-independent equivalence, as it should.

**What's assert about?** If you're not familiar with ``assert``, it's actually
a longstanding and quite useful macro that C++ inherited from the C language.
``assert`` simply checks that its argument is true, and causes the code to exit
immediately, with an error message that says something along the lines of
"assertion failure ...", if it isn't true.

This documentation uses ``assert`` throughout its examples. It's great for that
purpose: an expression like ``assert(foo)`` can be read, simply and concisely,
as: "we're asserting to you, the reader, that ``foo`` is true here." In the
above code, for instance, we're telling you directly that ``FromXML`` and
``FromJSON`` equal each other when we're at the ``assert`` line.

GNDStk's test suite, by the way, makes use of the CATCH library, described
online as a "test framework for unit-tests." CATCH, on the one hand, has far
more macros and other testing machinery than we get with just ``assert`` by
itself. However, a philosophy we're keeping in mind with GNDStk is that we
don't want to require potential users to learn more than they need to. A
system like CATCH, while more powerful, can obscure, to the uninitiated
user, *where* even a basic construct like a ``main()`` is located, or how
different source files are fitted together to create a group of tests.

**Therefore, for your benefit throughout this manual, we'll keep things
simple.** We'll provide complete, working, compile-able codes except where
it's obvious that something is just a code fragment; and employ the simple
but clear ``assert`` where we wish to draw attention to the fact that the
asserted expression is true.



--------------------------------
Regarding JSON Files
--------------------------------

The specifications for Version 1.9 of the GNDS standard can be found here:

   https://www.oecd-nea.org/jcms/pl_39689/specifications-for-the-generalised-nuclear-database-structure-gnds

which, at the time of this writing, is the latest available standard.
Section 2.4 of the downloadable PDF document discusses limitations of some
"meta-languages" (roughly speaking, file formats) such as JSON, in comparison
with what XML is able to represent.

**Here are three points quoted directly from the document**:

   **1.** for meta-languages that do not support attributes, either group all
   attributes together under a child node called ``attributes`` or convert
   each attribute to a child node and add a suffix like ``_attr`` to the
   node name.

   **2.** for meta-languages that do not support multiple child nodes with the
   same name, add a unique suffix to each node name. For example, if multiple
   ``reaction`` elements appear in the file, they become ``reaction0``,
   ``reaction1``, etc. To avoid parsing strings to determine the original
   node name, a ``nodeName`` attribute (or child node) should also be added
   indicating the original unmodified node name.

   **3.** for meta-languages that do not preserve the order of child elements,
   an attribute or child node with the (0-based) index should be added to
   the node. For example, in HDF5 the attribute ``nodeIndex`` could be added
   to each child in a group.

For (1), GNDStk does the first suggested action: it groups all of a node's
attributes under a child node called ``attributes``. We consider that to be
cleaner than using an ``_attr`` suffix.

For (2), GNDStk does exactly as illustrated: multiple elements of the same name
are suffixed with ``0``, ``1``, etc. And, then, a JSON name/value pair with the
name ``nodeName``, as suggested, is created in order to preserve the original
*unsuffixed* element's name.

For (3), GNDStk does nothing in particular right now. Our understanding of GNDS
is that it's designed so that elements -- nodes -- can appear in any order.
Here's a small XML fragment taken directly from the ``n-094_Pu_239.xml`` example
GNDS file that we've been using for our examples:

.. literalinclude:: tutorial/xml-axes-fragment.xml
   :language: xml

Those ``axis`` child nodes already contain a 0-based ``index`` attribute, so
perhaps the specification's admonishment #3 is something we can consider to have
been satisfied already by whomever has created an existing, valid GNDS file (so
that no further treatment is required); or something that *we* must satisfy if
we are to create our own valid GNDS files.

The GNDS document then puts forth the following example XML fragment -- slightly
reformatted here for clarity, and with a proper XML declaration node (the first
line) added for completeness:

.. literalinclude:: tutorial/employees.xml
   :language: xml

A viable JSON equivalent is then suggested.

Calling the above XML file ``employees.xml``, let's bring forth our
tried-and-true GNDStk methodology for converting from XML to JSON:

.. literalinclude:: tutorial/employees.cpp
   :language: cpp

and see what happens. Here's exactly the output JSON file that the above code,
applied to the sample XML, creates:

.. literalinclude:: tutorial/employees.json
   :language: json

This illustrates how GNDStk creates JSON files, consistent with the suggestions
in the GNDS specification.

If you try the above code, on the given input, you'll see that GNDStk prints
two *warnings*. The same warning twice, actually: once during input, and once
during output. The warning tells us that ``<employees>`` -- the top-level node
of the above XML document -- is not recognized as a valid **GNDS** top-level
node. (Valid GNDS top-level nodes, per the standard, are ``reactionSuite``,
``covarianceSuite``, ``PoPs``, ``thermalScattering``, and
``fissionFragmentData``.) It's just a warning, not an error, so don't worry
about it for now.

Naturally, GNDStk reverses the modifications when we *read* from a JSON file
into our internal format. Specifically: values in an ``attributes`` block are
transformed into metadata in the enclosing node, and values from ``nodeName``
name/value pairs replace index-suffixed names.

At this time, GNDStk provides no other options, such as the ``_attr`` suffix
that the GNDS specification suggested as a possibility, for handling JSON.
Neither can it *read* JSONs that may have been created in a different manner.
We're not aware, at the time of this writing, of the existence any official
JSON-format GNDS files. If and when such files come into existence, and if
such files use a different scheme than we do for addressing the issues
described above, then we'll provide capabilities at least for reading those
files, and perhaps for writing them in that manner as well.



========================================
Data Structure "Direct"
========================================

In this section, we'll talk about some of the basic internal constructs of some
of GNDStk's classes: more importantly, ``Tree`` and ``Node``; less importantly,
``XML`` and ``JSON``. We'll describe member *data* -- with an important message
to users first -- and also some of the member *functions* that you're likely to
find useful. For now, here, we won't cover the plethora of member functions that
support our "smart query system." Those need their own dedicated, and detailed,
discussion.



--------------------------------
About Direct Access
--------------------------------

**Right away, we strongly suggest that most users avoid direct access of member
data in these classes!** An exception is the ``name`` string in ``Tree`` and
``Node``, which you might well wish to access. It's rather inoculous. Other
member data, at this time, consists of containers for metadata and child nodes.

In most cases, we hope you'll prefer to use GNDStk's rich variety of powerful
higher-level capabilities, in our "smart query system," for pulling data from,
or pushing data to, the metadata and child-node containers. (We're talking right
now about capabilities that are still in our core interface -- not in our
"high-level" interface that provides classes tailored to specific versions
of the GNDS standard.) The basics of our "smart query system" are described
in an upcoming section of this document.

Our query system was designed precisely so that you'll have something much more
concise and powerful than you will by directly accessing the containers in
question. And, most likely, also safer to use, insofar as working directly with
the internals of data structures, especially those that were designed by other
people, invariably runs some risks. C++ containers aren't rocket science (and,
besides, some GNDStk users may well *be* rocket scientists), so we do in fact
provide public access to these structures, in the interest of supporting users
who are comfortable and capable with the C++ language.

Finally, we believe that if you understand the basic internal data format, then
you may find the behavior of the higher-level capabilities, and our motivation
for creating them, to be more clear.



--------------------------------
Tree vs. Node
--------------------------------

We've already seen ``Tree`` in some examples. It's the class to use when you
want to read or write an entire GNDS tree. ``Tree`` is derived from another
important class: ``Node``. At the time of this writing, ``Tree`` contains no
additional *data* beyond what it gets from ``Node``. It does, however, contain
some additional member functions, and it makes some slight changes to some of
the member functions that otherwise gets from its ``Node`` base.

Here's a short sketch of our arrangement:

.. literalinclude:: tutorial/tree-and-node.hpp
   :language: cpp

The GNDS standard is essentially a tree structure, and this is reflected in
our classes, with ``Tree`` being intended for the top-level (root) node, and
``Node`` for all others.

Some readers may realize, correctly, that a typical tree structure's top-level
node could be treated in exactly the same way as all of its other nodes. One
doesn't generally need different data types for a tree's root node and its other
nodes, including leaves. Roughly speaking, tree nodes all "look the same," with
similar contents as well as relationships to their child nodes.

That's all true, and it could be described as the theoretical/mathematical view
of tree structures. From a practical/engineering standpoint, some utility can
sometimes be had in treating a top-level node differently from the others.
That's the reasoning for ``Tree`` versus ``Node``.

As a derived class, ``Tree`` automatically inherits most of its functionality
from ``Node``, as we want it to. In a handful of respects, however, ``Tree``
will reflect the fact that it's there to represent an entire GNDS hierarchy,
not just a portion thereof. For example, it tries to ensure that the top-level
GNDS node isn't *any* valid GNDS node, but one of the few that's valid as a
*top-level* GNDS node. (GNDStk, it turns out, emits a warning, but not an error,
if you try to write a ``Tree`` that doesn't have a top-level GNDS node with a
valid name.)

One could also imagine extra functionality that a ``Tree``, but not a ``Node``,
could be equipped with. In the typical case that a GNDS tree is read from a
file, for example, we *could* have the ``Tree`` structure store the file name.
Then, perhaps, we could equip ``Tree`` with a member function like
``overwrite()`` or ``rewrite()`` that would replace the original file (say,
after a user has made changes that they wished to make to the GNDS data) without
requiring that the file name be repeated. (Analogy: a image-editing GUI that
provides, in its File menu, an item like ``Overwrite <original.jpg>``, in
addition to a ``Save As...`` and an ``Export``.) GNDStk does not, at the time
of this writing, provide this particular capability. By making ``Tree``
different from ``Node``, however, we allow for the possibility of such things
being added, painlessly, at a later time.



--------------------------------
Content Preservation
--------------------------------

An important initial design decision that we made for our ``Tree`` and ``Node``
classes is that they faithfully represent precisely the content from any GNDS
file we may read into them. The fundamental motivation here is simple: data
evaluators work hard to create good data, and we don't want to take any
actions that might, in any way, change or lose anything.

Consider, as a simple example, this small fragment of content from near the
beginning of our favorite ``n-094_Pu_239.xml`` example GNDS file:

.. literalinclude:: tutorial/mass-double-fragment.xml
   :language: xml

We could probably all agree that the label ``"eval"`` and unit ``"amu"`` should
be stored as strings. But what about the value ``"1.00866491574"``? We *could*
store it as a ``double``, if we're presumptuous enough to assume that a user
intends to use it as a ``double`` -- not a ``float``, say, or
a ``long double``. We'd also be assuming, there, that a user doesn't mind the
expensive of presumptively "floating-point" content from GNDS files being
converted *en masse* from the original XML character strings to floating-points,
regardless of which GNDS content the user might actually access. On top of
that, we'd be glossing over the various complexities that can (and do) arise
when decimal representations of floating-point numbers are converted to internal
binary floating-points, and back again. (The "back again" part is especially
relevant if someone plans, say, to read a GNDS file, add new data and/or fix
old data in selected areas, and then write the entire GNDS file back out again.)

Instead of making wild assumptions, we'll opt instead to preserve original
content -- that is, to respect precisely what exists in a GNDS file to begin
with.

To this end, all individual data, regardless of what they may appear to be
(string, floating-point, integer, single character, etc.), are stored as
strings. More precisely, as C++ ``std::strings``. Node names (``"mass"``) are
stored as strings. Metadata key/value pairs are stored as C++ ``std::pairs``
of strings; think ``{"label","eval"}``. Even the content in GNDS ``values``
nodes, like this one (the first in ``n-094_Pu_239.xml``):

.. literalinclude:: tutorial/xml-values-fragment.xml
   :language: xml

are stored, in a ``Node``, as long strings. (We could reasonably split out such
thing into ``std::vector<std::string>s``, too, but decided to not even do that.
To perform such a split everywhere, automatically, would take time, and a user
might not even intend to access any specific portion of GNDS data.)

No worries, though: our core interface, and especially the smart query system
that we've spoken of, has plenty of functionality for serving its internal
strings to you as floating-points, for instance; or for re-forming long strings,
like the ones just described, into vectors of strings, or vectors of
floating-points, or vectors of just about anything you may wish to create. When
we speak of content preservation, then, we're saying that an input text
file -- XML or JSON, for now -- is factored into its underlying tree structure,
but with its individual meaningful parts (neglecting, as usual, whitespace)
still stored as text, with no modifications.

A given user's application code will almost certainly have its own internal
classes that contain GNDS data, or data computed from GNDS data, in ways that
work well for the user's application. Someone may also have classes specifically
intended to mirror the content in various GNDS nodes, just in a different way.
(GNDStk's own "high-level interface" will provide precisely such classes.) Such
classes can certainly make assumptions we didn't want GNDStk to make -- like,
for example, that we do want ``double`` for that numerical value above. Or, for
that matter, that perhaps the ``unit``, ``"amu"`` above should be an entry in
some C++ enumerator for allowable units -- no longer a string at all. We're
happy to report that our core interface, and in particular our smart query
system, is designed to help you interact well, and easily, with GNDStk's
internal string storage.

We'll write more about the above considerations elsewhere. For now, let's return
to the main point of this chapter, and describe GNDStk's two major classes that
store GNDS data.



--------------------------------
Node
--------------------------------

We'll write first about ``Node`` (for general nodes), because ``Tree`` (for the
root node only) derives from ``Node``. Recall that the member data in ``Node``
looks like this:

.. literalinclude:: tutorial/node-data.hpp
   :language: cpp

In short, inlining the ``metaPair`` and ``childPtr`` types and omitting the
``std::`` prefix for brevity:

.. literalinclude:: tutorial/node-data-brief.hpp
   :language: cpp

The above evinces a simple tree structure that's entirely sufficient for
representing the contents of any GNDS node.

Let's provide a short but concrete example. Here's some XML content from near
the top of the ``n-094_Pu_239.xml`` GNDS file:

.. literalinclude:: tutorial/evaluated-node.xml
   :language: xml

Here, an outer ``evaluated`` node (XML "element") contains four metadata
key/value pairs (XML "attributes") and two child elements. The first child
element, ``temperature``, contains two metadata pairs but no further child
nodes. The second child element, ``projectileEnergyDomain``, contains three
metadata pairs but no further child nodes.

At the risk of continuing a narrative of statements that are no doubt obvious,
here's precisely how the above ``evaluated`` node is represented in a ``Node``:

.. code::

   name: "evaluated"

   metadata[0]: {"label", "eval"}
   metadata[1]: {"date", "2017-12-01"}
   metadata[2]: {"library", "ENDF/B"}
   metadata[3]: {"version", "8.0.5"}

   children[0]: pointer to another Node, with:

      name: "temperature"

      metadata[0]: {"value", "0.0"}
      metadata[1]: {"unit", "K"}

   children[1]: pointer to another Node, with:

      name: "projectileEnergyDomain"

      metadata[0]: {"min", "1e-05"}
      metadata[1]: {"max", "20000000.0"}
      metadata[2]: {"unit", "eV"}

Here, ``{"foo", "bar"}`` is a C++ ``std::pair<std::string,std::string>``,
and is thus accessible in the customary manner: ``.first`` for the ``"foo"``
and ``.second`` for the ``"bar"``.

We use C++ ``std::unique_ptr<Node>s`` for the pointers to child nodes.



--------------------------------
Pointers about Pointers
--------------------------------

A couple of early users asked us about the motivation for using pointers,
so we'll briefly address, here, the concerns that they raised, in case other
users wonder the same things.

One person wondered why ``children`` is a vector of pointers -- not a vector
of Nodes, which would *appear* at least to be simpler. Of course, a ``Node``
can't directly contain another ``Node`` -- C++ wouldn't allow it -- but
could indeed contain a ``vector`` of ``Nodes``. (C++ ``vectors`` themselves
involve pointers, so pointers are still involved, they're just not explicit.)

Without delving into a discussion that's well beyond the scope of this
document, we'll say only that implementing a Node's ``children`` as a vector
of ``Nodes`` would likely wreak havoc on efficiency, both in space (memory)
and in time, when objects like ``Tree`` and ``Node`` are being read from a
file or otherwise created or modified. Considerable memory fragmentation
could also come about.

Another user wanted to write code that copied some of ``children's`` pointers.
The attempt to do so was stymied due to ``std::unique_ptr's`` intentional
lack of a copy constructor, as ``unique_ptr`` is designed to be the exclusive
"owner" of the object to which it points. GNDStk uses ``unique_ptr`` quite
intentionally, precisely to deal with the ownership issue cleanly and clearly
while also benefitting from ``unique_ptr's`` automatic handling of an object's
memory footprint.

A code shouldn't attempt to take any actions that would break the ownership
rules ``unique_ptr`` manifests, and a C++ compiler will say so loudly if one
tries. Anyone who really wishes to make their own pointer -- say, a raw
pointer -- to an object to which one of our ``unique_ptrs`` already refers,
can always dereference the ``unique_ptr`` (giving a reference to a ``const``
or non-``const`` Node, and effectively losing the ``unique_ptr`` aspect), then
take the address to get a pointer again: basically ``&(*uptr)``, where ``uptr``
is a ``unique_ptr`` in one of our ``children`` vectors. (Do not, of course,
``delete`` the Node through such a pointer; leave its management to the original
``unique_ptr``!) We recommend that anyone who does this, or anything similar,
be sufficiently familiar with the C++ language, as well as justifiably confident
that there isn't a better way to accomplish the goal at hand.



--------------------------------
Tree
--------------------------------

``Tree`` derives from ``Node``, so what we've already spoken about, in terms
of member data, still applies. Some additional points are in order, however,
owing to ``Tree's`` status as the root node in our internal representation
of a GNDS hierarchy.



--------------------------------
Direct-Access Examples
--------------------------------



--------------------------------
XML and JSON
--------------------------------



========================================
Smart Query System
========================================



========================================
GNDS Creation
========================================

node ctors
tree ctors
add()s



========================================
Advanced Examples
========================================

Largely continue query system discussion.
Not sure about "advanced examples" characterization.
