
// macro, for keyword building
#define make_meta(type,name) \
   inline constexpr const meta_t<type> name(#name)



// -----------------------------------------------------------------------------
// meta_t
// -----------------------------------------------------------------------------

template<class T>
class meta_t {
public:
   const char *const name;
   explicit constexpr meta_t(const char *const n) : name(n)
   {
   }
};



// -----------------------------------------------------------------------------
// keywords
// Use our macro.
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
make_meta(std::string, decayRate); // appears to have "double 1/s" typically

} // namespace meta



// -----------------------------------------------------------------------------
// keywords
// Special cases, not doable with our macro.
// -----------------------------------------------------------------------------

// For the variant cases, we should work out a way to make the type be context
// dependent, which it *is* (I think) in GNDS. Then, additional data extraction
// syntax won't be needed.

namespace meta {

// ------------------------
// Goofy string-key cases;
// must give !goofy names
// ------------------------

// comment
inline constexpr const meta_t<std::string>
comment("<!--");

// cdata
// fixme: Cook up a shorthand to get this directly from "documentation"
inline constexpr const meta_t<std::string>
cdata("![CDATA[");

// pcdata
// fixme: This should be made more general
inline constexpr const meta_t<std::vector<double>>
pcdata("![PCDATA[");


// ------------------------
// Variant cases; comma in
// variant<,> prevents use
// of our macro
// ------------------------

// constant
inline constexpr const meta_t<std::variant<int,double>>
constant("constant");

// degreesOfFreedom
// I'd have expected an int for this, always, but some
// of the GNDS files have a non-integral double.
inline constexpr const meta_t<std::variant<int,double>>
degreesOfFreedom("degreesOfFreedom");

// value
inline constexpr const meta_t<std::variant<int,double,std::string>>
value("value");

// value
// Shorthand for specific cases.
// Prefixes {i,d,s} = {int,double,string}.
inline constexpr const meta_t<int        > ivalue("value");
inline constexpr const meta_t<double     > dvalue("value");
inline constexpr const meta_t<std::string> svalue("value");

// channelSpin
// This actually looks to me like it's always either an int,
// or some sort of fraction, so figure out something clever
// in place of variant.
inline constexpr const meta_t<std::variant<int,std::string>>
channelSpin("channelSpin");

// spin
// Same remark as for channelSpin.
inline constexpr const meta_t<std::variant<int,std::string>>
spin("spin");

} // namespace meta
