
// macro, for keyword building
#define make_meta(type,name) \
   inline const meta_t<type> name(#name)



// -----------------------------------------------------------------------------
// meta_t
// -----------------------------------------------------------------------------

template<class T>
class meta_t {
public:
   const std::string name;
   explicit meta_t(const std::string &n) :
      name(n)
   { }
};



// -----------------------------------------------------------------------------
// keywords
// -----------------------------------------------------------------------------

namespace meta {

// bool
make_meta(bool, calculateChannelRadius);
make_meta(bool, calculatedAtThermal);
make_meta(bool, calculatePenetrability);
make_meta(bool, identicalParticles);
make_meta(bool, supportsAngularReconstruction);
make_meta(bool, useForSelfShieldingOnly);

// int
make_meta(int, A);
make_meta(int, columnIndex);
make_meta(int, columns);
make_meta(int, ENDF_MT);
make_meta(int, index);
make_meta(int, L);
make_meta(int, MAT);
make_meta(int, matrixStartIndex);
make_meta(int, metaStableIndex);
make_meta(int, nParameters);
make_meta(int, numberOfProducts);
make_meta(int, numberPerMolecule);
make_meta(int, parity);
make_meta(int, rows);
make_meta(int, Z);

// double
make_meta(double, coefficient);
make_meta(double, domainMax);
make_meta(double, domainMin);
make_meta(double, electronNumber);
make_meta(double, format);
make_meta(double, max);
make_meta(double, min);
make_meta(double, muCutoff);

// string
make_meta(std::string, approximation);
make_meta(std::string, asymmetric);
make_meta(std::string, boundaryCondition);
make_meta(std::string, complete);
make_meta(std::string, compression);
make_meta(std::string, crossTerm);
make_meta(std::string, dependenceOnProcessedGroupWidth);
make_meta(std::string, derivedFrom);
make_meta(std::string, domainUnit);
make_meta(std::string, ejectile);
make_meta(std::string, eliminated);
make_meta(std::string, emissionMode);
make_meta(std::string, encoding);
make_meta(std::string, ENDF_MFMT);
make_meta(std::string, evaluation);
make_meta(std::string, final);
make_meta(std::string, fissionGenre);
make_meta(std::string, flags);
make_meta(std::string, functionalForm);
make_meta(std::string, generation);
make_meta(std::string, genre);
make_meta(std::string, href);
make_meta(std::string, id);
make_meta(std::string, initial);
make_meta(std::string, interpolation);
make_meta(std::string, interpolationQualifier);
make_meta(std::string, label);
make_meta(std::string, library);
make_meta(std::string, material);
make_meta(std::string, mode);
make_meta(std::string, name);
make_meta(std::string, path);
make_meta(std::string, pid);
make_meta(std::string, process);
make_meta(std::string, productFrame);
make_meta(std::string, projectile);
make_meta(std::string, projectileFrame);
make_meta(std::string, resonanceReaction);
make_meta(std::string, shape);
make_meta(std::string, style);
make_meta(std::string, subshell);
make_meta(std::string, symbol);
make_meta(std::string, symmetry);
make_meta(std::string, target);
make_meta(std::string, type);
make_meta(std::string, unit);
make_meta(std::string, version);
make_meta(std::string, valueType);
make_meta(std::string, date);
make_meta(std::string, decayRate); // seems to always have double and "1/s"

} // namespace meta



// -----------------------------------------------------------------------------
// keywords
// Special cases, not doable with our macro.
// -----------------------------------------------------------------------------

// fixme
// For the variant cases, we should work out a way to make the type be context-
// dependent, which it *is* (I think) in GNDS. Then, additional data extraction
// syntax won't be needed.

namespace meta {

// ------------------------
// Goofy string-key cases
// must have !goofy names
// ------------------------

// fixme These may actually arrive with different keys if we've read from a
// Json (not XML) file - at least an original one, not created from an XML.
// Think about how we'll handle that. (Maybe allow for multiple keys?)

// comment
inline const meta_t<std::string>
comment("<!--");

// text
inline const meta_t<std::string>
text("![CDATA[");

// body
// fixme: This should be made more general, not just vector<double>
inline const meta_t<std::vector<double>>
body("![PCDATA[");


// ------------------------
// Variant cases; comma in
// variant<,> prevents use
// of the macro
// ------------------------

// constant
inline const meta_t<std::variant<int,double>>
constant("constant");

// degreesOfFreedom
// I'd have expected an int for this, always, but some of the GNDS files have
// a non-integral double. Perhaps we could arrange to always read as a double.
inline const meta_t<std::variant<int,double>>
degreesOfFreedom("degreesOfFreedom");

// value
inline const meta_t<std::variant<int,double,std::string>>
value("value");

// [ids]value
// Shorthands for specific cases.
// Prefixes {i,d,s} mean {int,double,string}.
inline const meta_t<int        > ivalue("value");
inline const meta_t<double     > dvalue("value");
inline const meta_t<std::string> svalue("value");

// channelSpin
// This actually looks to me like it's always either an int, or some sort
// of fraction, so figure out something clever in place of variant. Perhaps
// our own handmade (or Boost's) rational-number class?
inline const meta_t<std::variant<int,std::string>>
channelSpin("channelSpin");

// spin
// Same remark as for channelSpin.
inline const meta_t<std::variant<int,std::string>>
spin("spin");

} // namespace meta
