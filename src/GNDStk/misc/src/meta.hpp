
namespace meta {

// -----------------------------------------------------------------------------
// Keywords
// Of type Meta
// -----------------------------------------------------------------------------

// bool
GNDSTK_MAKE_META(bool, calculateChannelRadius);
GNDSTK_MAKE_META(bool, calculatedAtThermal);
GNDSTK_MAKE_META(bool, calculatePenetrability);
GNDSTK_MAKE_META(bool, identicalParticles);
GNDSTK_MAKE_META(bool, supportsAngularReconstruction);
GNDSTK_MAKE_META(bool, useForSelfShieldingOnly);
GNDSTK_MAKE_META(bool, complete);

// int
GNDSTK_MAKE_META(int, A);
GNDSTK_MAKE_META(int, columnIndex);
GNDSTK_MAKE_META(int, columns);
GNDSTK_MAKE_META(int, ENDF_MT);
GNDSTK_MAKE_META(int, index);
GNDSTK_MAKE_META(int, L);
GNDSTK_MAKE_META(int, MAT);
GNDSTK_MAKE_META(int, matrixStartIndex);
GNDSTK_MAKE_META(int, metaStableIndex);
GNDSTK_MAKE_META(int, nParameters);
GNDSTK_MAKE_META(int, numberOfProducts);
GNDSTK_MAKE_META(int, numberPerMolecule);
GNDSTK_MAKE_META(int, parity);
GNDSTK_MAKE_META(int, rows);
GNDSTK_MAKE_META(int, Z);

// double
GNDSTK_MAKE_META(double, coefficient);
GNDSTK_MAKE_META(double, domainMax);
GNDSTK_MAKE_META(double, domainMin);
GNDSTK_MAKE_META(double, electronNumber);
GNDSTK_MAKE_META(double, format);
GNDSTK_MAKE_META(double, max);
GNDSTK_MAKE_META(double, min);
GNDSTK_MAKE_META(double, muCutoff);

// string
GNDSTK_MAKE_META(std::string, approximation);
GNDSTK_MAKE_META(std::string, asymmetric);
GNDSTK_MAKE_META(std::string, boundaryCondition);
GNDSTK_MAKE_META(std::string, compression);
GNDSTK_MAKE_META(std::string, crossTerm);
GNDSTK_MAKE_META(std::string, dependenceOnProcessedGroupWidth);
GNDSTK_MAKE_META(std::string, derivedFrom);
GNDSTK_MAKE_META(std::string, domainUnit);
GNDSTK_MAKE_META(std::string, ejectile);
GNDSTK_MAKE_META(std::string, eliminated);
GNDSTK_MAKE_META(std::string, emissionMode);
GNDSTK_MAKE_META(std::string, encoding);
GNDSTK_MAKE_META(std::string, ENDF_MFMT);
GNDSTK_MAKE_META(std::string, evaluation);
GNDSTK_MAKE_META(std::string, final); // is a C++ *contextual* keyword; so OK
GNDSTK_MAKE_META(std::string, fissionGenre);
GNDSTK_MAKE_META(std::string, flags);
GNDSTK_MAKE_META(std::string, functionalForm);
GNDSTK_MAKE_META(std::string, generation);
GNDSTK_MAKE_META(std::string, genre);
GNDSTK_MAKE_META(std::string, href);
GNDSTK_MAKE_META(std::string, id);
GNDSTK_MAKE_META(std::string, initial);
GNDSTK_MAKE_META(std::string, interpolation);
GNDSTK_MAKE_META(std::string, interpolationQualifier);
GNDSTK_MAKE_META(std::string, label);
GNDSTK_MAKE_META(std::string, library);
GNDSTK_MAKE_META(std::string, material);
GNDSTK_MAKE_META(std::string, mode);
GNDSTK_MAKE_META(std::string, name);
GNDSTK_MAKE_META(std::string, path);
GNDSTK_MAKE_META(std::string, pid);
GNDSTK_MAKE_META(std::string, process);
GNDSTK_MAKE_META(std::string, productFrame);
GNDSTK_MAKE_META(std::string, projectile);
GNDSTK_MAKE_META(std::string, projectileFrame);
GNDSTK_MAKE_META(std::string, resonanceReaction);
GNDSTK_MAKE_META(std::string, shape);
GNDSTK_MAKE_META(std::string, style);
GNDSTK_MAKE_META(std::string, subshell);
GNDSTK_MAKE_META(std::string, symbol);
GNDSTK_MAKE_META(std::string, symmetry);
GNDSTK_MAKE_META(std::string, target);
GNDSTK_MAKE_META(std::string, type);
GNDSTK_MAKE_META(std::string, unit);
GNDSTK_MAKE_META(std::string, version);
GNDSTK_MAKE_META(std::string, valueType);
GNDSTK_MAKE_META(std::string, date);
GNDSTK_MAKE_META(std::string, decayRate); // always has double and "1/s"?



// -----------------------------------------------------------------------------
// Keywords
// Special cases
// -----------------------------------------------------------------------------

// ------------------------
// Variant cases; comma in
// variant<,> prevents use
// of the macro
// ------------------------

// constant
inline const Meta<std::variant<int,double>>
constant("constant");

// degreesOfFreedom
// I'd have expected an int for this, always, but some of the GNDS files have
// a non-integral double. Perhaps we could arrange to always read as a double.
inline const Meta<std::variant<int,double>>
degreesOfFreedom("degreesOfFreedom");

// value
inline const Meta<std::variant<int,double,std::string>>
value("value");

// [ids]value
// Shorthands for specific cases.
// Prefixes {i,d,s} mean {int,double,string}.
inline const Meta<int        > ivalue("value");
inline const Meta<double     > dvalue("value");
inline const Meta<std::string> svalue("value");

// channelSpin
// This actually looks to me like it's always either an int, or some kind
// of fraction, so figure out something clever in place of variant. Perhaps
// a rational-number class?
inline const Meta<std::variant<int,std::string>>
channelSpin("channelSpin");

// spin
// Same remark as for channelSpin.
inline const Meta<std::variant<int,std::string>>
spin("spin");

} // namespace meta
