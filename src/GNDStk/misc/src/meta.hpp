
namespace meta {

// ------------------------
// Misc. Meta Objects
// ------------------------

// int
GNDSTK_MAKE_META(int, A);
GNDSTK_MAKE_META(int, ENDF_MT);

// double
GNDSTK_MAKE_META(double, format);

// string
GNDSTK_MAKE_META(std::string, encoding);
GNDSTK_MAKE_META(std::string, evaluation);
GNDSTK_MAKE_META(std::string, id);
GNDSTK_MAKE_META(std::string, label);
GNDSTK_MAKE_META(std::string, projectile);
GNDSTK_MAKE_META(std::string, projectileFrame);
GNDSTK_MAKE_META(std::string, symbol);
GNDSTK_MAKE_META(std::string, target);
GNDSTK_MAKE_META(std::string, unit);
GNDSTK_MAKE_META(std::string, version);

// value, as double
inline const Meta<double> dvalue("value");

} // namespace meta
