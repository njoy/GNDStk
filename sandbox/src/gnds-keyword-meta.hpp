
// macro, for keyword building
#define make_meta(type,name) \
   inline constexpr const meta<type> name(#name)



// -----------------------------------------------------------------------------
// meta
// -----------------------------------------------------------------------------

template<class T>
class meta {
public:
   using type = T; // <== we may not need this
   const char *const name;
   explicit constexpr meta(const char *const n) : name(n)
   {
   }
};



// -----------------------------------------------------------------------------
// keywords - simple
// -----------------------------------------------------------------------------

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

} // namespace key



// -----------------------------------------------------------------------------
// keywords - special
// -----------------------------------------------------------------------------

namespace key {

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
