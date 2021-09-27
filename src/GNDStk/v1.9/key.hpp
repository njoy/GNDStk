
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

/*
This file contains Meta and Child objects for metadata and child nodes in the
current GNDS version. These may prove to be useful if you wish to use the Core
Interface in conjunction with the autogenerated classes for this GNDS version.

Within the outer njoy::GNDStk::version namespace below, the remaining namespace
arrangement was chosen to make the use of these objects smooth and logical.

Meta and Child objects are collectively called "keys." Meta keys are placed
into key::meta. Child keys correspond to autogenerated classes, each of which
is already in some namespace; we thus use theNamespace::key::child::. That way,
an autogenerated class [ns::Foo] has [ns::key::foo] as its Child object, and
a "using namespace ns" allows the class and the Child object to be [Foo] and
[key::foo], respectively. (If we reordered ns:: and key::, that wouldn't work.)

Within key::, we use meta:: and child:: around Meta and Child objects, just in
case there exist any identical GNDS metadata names and child-node names. (That
can, in fact, happen). The "using namespace meta" and "using namespace child"
directives then make the Meta<> and Child<> objects appear directly in key::,
so that "meta::" and "child::" are needed only to disambiguate identical names.
*/

#ifndef NJOY_GNDSTK_V1_9_KEY
#define NJOY_GNDSTK_V1_9_KEY

namespace njoy {
namespace GNDStk {
namespace v1_9 {


// -----------------------------------------------------------------------------
// key::meta::
// -----------------------------------------------------------------------------

namespace key {
namespace meta {

inline const Meta<>
   ENDF_MT("ENDF_MT"),
   evaluation("evaluation"),
   fissionGenre("fissionGenre"),
   format("format"),
   href("href"),
   index("index"),
   interaction("interaction"),
   interpolation("interpolation"),
   label("label"),
   length("length"),
   outerDomainValue("outerDomainValue"),
   projectile("projectile"),
   projectileFrame("projectileFrame"),
   start("start"),
   style("style"),
   target("target"),
   unit("unit"),
   valueType("valueType");

} // namespace meta
using namespace meta;
} // namespace key


// -----------------------------------------------------------------------------
// containers::key::child::
// -----------------------------------------------------------------------------

namespace containers {
namespace key {
namespace child {

inline const Child<>
   XYs1d("XYs1d"),
   axes("axes"),
   axis("axis"),
   grid("grid"),
   link("link"),
   regions1d("regions1d"),
   values("values");

} // namespace child
using namespace child;
} // namespace key
} // namespace containers


// -----------------------------------------------------------------------------
// transport::key::child::
// -----------------------------------------------------------------------------

namespace transport {
namespace key {
namespace child {

inline const Child<>
   crossSection("crossSection"),
   reaction("reaction"),
   reactionSuite("reactionSuite"),
   reactions("reactions");

} // namespace child
using namespace child;
} // namespace key
} // namespace transport


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
