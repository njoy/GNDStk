
// macro, for keyword building
#define make_child(name) \
   inline constexpr const child name(#name)



// -----------------------------------------------------------------------------
// child
// -----------------------------------------------------------------------------

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



// -----------------------------------------------------------------------------
// keywords - simple
// -----------------------------------------------------------------------------

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



// -----------------------------------------------------------------------------
// keywords - special
// -----------------------------------------------------------------------------

namespace key {

inline constexpr const child Double("double"); // gotta do something :-)

} // namespace key
