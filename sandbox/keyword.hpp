
/*
Very brief description of the overall concept of the constructs in this file.

Embed each of the various GNDS keywords (reactionSuite, projectile, evaluated,
label, whatever) into one or the other of two classes (which are defined below):

   class child
   class meta<T>

Superficially, each of these just wraps a string.
(note to self...probably make std::string, not char *)

BUT: ( <== big "but")

What we're doing here has at least three advantages over using direct strings
to drill down into the tree (as with doc["foo"]["bar"]["baz"])...

1. No typos in the string names. If a keyword is misspelled by a user, it's a
   compile time error instead of a run time error! Much better.

2. Combined with child(), meta(), and operator()() overloads in our generic
   document class, we vastly clean up the notation...

      old notation: doc["foo"]["bar"]["baz"] or similar
      new notation: doc(foo,bar,baz)

3. meta<T>'s T encodes the *type* that the wrapped string key will pulls
   from the document. (Armed, eventually, with my work on data structures,
   we'll probably put <T> onto class child as well.)

Basically, we get less chance of errors, cleaner/leaner notation, and - most
importantly in my opinion - a way of encoding TYPE into the keys that we use
to drill down into the data structure.

Note: this file is proof of principle, and only contains a small subset of all
the keywords that appear in GNDS file. I based it on what I saw in:

   a-002_He_004.xml

which is one of many GNDS files I downloaded from an online site. -MFS.
*/



// -----------------------------------------------------------------------------
// child
// Child elements
// -----------------------------------------------------------------------------

namespace gnds {

// child
// Probably have this thing take <T> after we figure out node types,
// as with the data-structure project I'm working on in parallel
class child {
public:
   const char *const name;
   explicit constexpr child(const char *const n) : name(n)
   {
   }
};



#define make_child(name) \
   inline constexpr const child name(#name)

// Maybe different namespace here, to distinguish from namespace for meta
// class (see below) if some names overlap...
// Then user could "using" both, and ::-disambiguate only if/when necessary.
namespace key {

make_child(angularTwoBody);
make_child(axes);
make_child(axis); // allow multiple
make_child(charge);
make_child(chemicalElement);
make_child(chemicalElements);
make_child(constant1d);
make_child(CoulombPlusNuclearElastic);
make_child(crossSection);
make_child(distribution);
make_child(documentation);
make_child(documentations);
inline constexpr const child Double("double"); // gotta do something :-)
make_child(doubleDifferentialCrossSection);
make_child(energy);
make_child(evaluated);
make_child(fraction);
make_child(halflife);
make_child(integer);
make_child(isotope);
make_child(isotopes);
make_child(mass);
make_child(multiplicity);
make_child(nuclearPlusInterference);
make_child(nucleus);
make_child(nuclide);
make_child(nuclides);
make_child(outputChannel);
make_child(parity);
make_child(PoPs);
make_child(product); // allow multiple
make_child(products);
make_child(projectileEnergyDomain);
make_child(Q);
make_child(reaction);
make_child(reactions);
make_child(reactionSuite);
make_child(recoil);
make_child(RutherfordScattering);
make_child(spin);
make_child(string);
make_child(styles);
make_child(temperature);
make_child(values);
make_child(xml);
make_child(XYs1d); // allow multiple
make_child(XYs2d);

} // namespace key
} // namespace gnds



// -----------------------------------------------------------------------------
// meta
// Metadata elements
// -----------------------------------------------------------------------------

namespace gnds {

// meta
template<class T>
class meta {
public:
   using type = T; // <== may not need this
   const char *const name;
   explicit constexpr meta(const char *const n) : name(n)
   {
   }
};



#define make_meta(type,name) \
   inline constexpr const meta<type> name(#name)

// Maybe different namespace here, to distinguish from namespace for child
// class (see above) if and when some names overlap...
namespace key {

make_meta(bool, identicalParticles);

make_meta(int, A);
make_meta(int, Z);
make_meta(int, index);
make_meta(int, ENDF_MT);

make_meta(double, domainMin);
make_meta(double, domainMax);
make_meta(double, min);
make_meta(double, max);
make_meta(double, muCutoff);
make_meta(double, constant);

make_meta(std::string, version);
make_meta(std::string, encoding);
make_meta(std::string, projectile);
make_meta(std::string, target);
make_meta(std::string, evaluation);
make_meta(std::string, format);
make_meta(std::string, label);
make_meta(std::string, date);
make_meta(std::string, library);
make_meta(std::string, unit);
make_meta(std::string, href);
make_meta(std::string, genre);
make_meta(std::string, id);
make_meta(std::string, name);
make_meta(std::string, pid);
make_meta(std::string, productFrame);
make_meta(std::string, projectileFrame);
make_meta(std::string, symbol);

// value
// For "value", we should work out a good way to make the type be
// context-dependent, which it *is* in GNDS files. Then, extra syntax
// regarding the variant won't be needed.
inline constexpr const meta<std::variant<int,double,std::string>>
value("value");

// text
// Let's use "text" to get the "![CDATA[;", given that the latter
// thing obviously makes no sense as a variable. We should also cook
// up a shorthand to get this from "documentation".
inline constexpr const meta<std::string>
text("![CDATA[");

// array
// We'll need to think about this one some more, and come up with
// something general.
inline constexpr const meta<std::vector<double>>
array("![PCDATA[");

} // namespace key
} // namespace gnds
