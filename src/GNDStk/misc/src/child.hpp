
namespace child {

// ------------------------
// Some top-level nodes,
// per LLNL-TR-774621-DRAFT
// ------------------------

inline const Child<void,Allow::one> PoPs             ("PoPs");
inline const Child<void,Allow::one> reactionSuite    ("reactionSuite");
inline const Child<void,Allow::one> covarianceSuite  ("covarianceSuite");
inline const Child<void,Allow::one> thermalScattering("thermalScattering");

// ------------------------
// Misc. Child Objects
// ------------------------

GNDSTK_MAKE_CHILD(void, axes, one);
GNDSTK_MAKE_CHILD(void, axis, many);
GNDSTK_MAKE_CHILD(void, chemicalElements, one);
GNDSTK_MAKE_CHILD(void, chemicalElement,  many);
GNDSTK_MAKE_CHILD(void, isotopes, one);
GNDSTK_MAKE_CHILD(void, isotope,  many);
GNDSTK_MAKE_CHILD(void, nuclides, one);
GNDSTK_MAKE_CHILD(void, reactions, one);
GNDSTK_MAKE_CHILD(void, reaction,  many);
GNDSTK_MAKE_CHILD(void, crossSection, one);
GNDSTK_MAKE_CHILD(void, styles, one);
GNDSTK_MAKE_CHILD(void, temperature, one);
inline const Child<void,Allow::one> xml("#xml");
GNDSTK_MAKE_CHILD(void, evaluated, many);
GNDSTK_MAKE_CHILD(void, XYs1d, many);

// ------------------------
// cdata
// ------------------------

// This is where XML <!-- ... --> (comment) material resides. It's reasonable
// to extract such content into std::strings. We then store these in nodes of
// name #cdata, each with one metadatum having a key of "#text" and a value
// containing the original content.
inline const Child<std::string, Allow::one, detail::text_metadatum_to_string>
   cdata("#cdata");

} // namespace child
