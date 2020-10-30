
/*
Description of convert(type,node)

Brief: type ==> node ==> node.child(child_t<type>)

These are essentially the reverse of the convert(node,type) functions.
The description of those, seen in reverse, applies here.

In short, these functions are for taking various types, perhaps user-defined,
and converting them into a node that's destined to be added as a child node.

At the moment, this file is empty except for comments. We're intentionally
leaving it here, as a placeholder, in case we decide that we *should* have
some default type-to-node convert() functions.
*/



// -----------------------------------------------------------------------------
// convert(some std:: sequence containers, Node)
// -----------------------------------------------------------------------------

/*
We had these at one point, but decided to remove them. The assumption behind
them was that the containers in question - to be converted to nodes - contained
numeric data destined for nodes like this:

   <values>1.2 3.4 ...</values>

which are, in fact, common in GNDS files. Unfortunately, while there's a good
chance that someone's container of values would indeed be intended for a GNDS
node of that form, it would certainly be reasonable, given the sheer number
of different varieties of nodes in GNDS, that someone could intend a particular
container<T> to have an entirely different mapping to (and from) a GNDS node.

If we continued providing general convert()s, then, they might do the right
thing most of the time, but when they did the wrong thing, then, for general
users who would probably be far less familiar with GNDStk and C++ than we are,
overriding them might prove to be relatively awkward. (Note in particular that
if someone wrote a C++ override like, say, convert(std::vector<double>, node),
then it would indeed override a general templated version, but such an override
would then break anything that defaulted to convert(std::vector<double>, node)
with the intention of creating a <values> node as above!)

That, then, was our motivation for no longer providing these.

Built-in GNDStk constructs (in particular, certain child_t objects) that relied
previously on these now-deleted convert() functions, are instead now outfitted
with custom converters that do the same job. (We note as an FYI to readers here
that a GNDStk meta_t or child_t custom converter object is roughly analogous to
a custom comparison object or lambda that can be provided optionally as the last
argument of certain std::sort() overloads.)
*/
