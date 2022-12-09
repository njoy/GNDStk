
// -----------------------------------------------------------------------------
// basic::
// Some Meta and Child objects that use <void>, meaning that they'll retrieve
// metadata and child nodes in their original form in the GNDS tree. These are
// used in various test codes.
// -----------------------------------------------------------------------------

namespace basic {

// ------------------------
// Meta<>
// ------------------------

namespace meta {
   inline const njoy::GNDStk::Meta<void>
      ENDF_MT   ("ENDF_MT"   ),
      index     ("index"     ),
      label     ("label"     ),
      projectile("projectile"),
      symbol    ("symbol"    ),
      text      (njoy::GNDStk::special::text),
      unit      ("unit"      ),
      value     ("value"     ),
      version   ("version"   );
} // namespace meta

// ------------------------
// Child<>
// ------------------------

namespace child {

   // Some top-level nodes, per LLNL-TR-774621-DRAFT
   inline const njoy::GNDStk::Child<void,njoy::GNDStk::Allow::one>
      PoPs("PoPs"),
      reactionSuite("reactionSuite");

   // With Allow::one
   inline const njoy::GNDStk::Child<void,njoy::GNDStk::Allow::one>
      RMatrix            ("RMatrix"            ),
      angularTwoBody     ("angularTwoBody"     ),
      axes               ("axes"               ),
      cdata              (njoy::GNDStk::special::cdata),
      chemicalElements   ("chemicalElements"   ),
      crossSection       ("crossSection"       ),
      data               ("data"               ),
      distribution       ("distribution"       ),
      documentation      ("documentation"      ),
      documentations     ("documentations"     ),
      Double             ("double"             ),
      gaugeBosons        ("gaugeBosons"        ),
      mass               ("mass"               ),
      outputChannel      ("outputChannel"      ),
      pcdata             (njoy::GNDStk::special::data),
      products           ("products"           ),
      reactions          ("reactions"          ),
      regions2d          ("regions2d"          ),
      resolved           ("resolved"           ),
      resonanceParameters("resonanceParameters"),
      resonances         ("resonances"         ),
      spin               ("spin"               ),
      spinGroups         ("spinGroups"         ),
      styles             ("styles"             ),
      table              ("table"              ),
      temperature        ("temperature"        );

   // With Allow::many
   inline const njoy::GNDStk::Child<void,njoy::GNDStk::Allow::many>
      XYs1d          ("XYs1d"          ),
      axis           ("axis"           ),
      chemicalElement("chemicalElement"),
      evaluated      ("evaluated"      ),
      fraction       ("fraction"       ),
      gaugeBoson     ("gaugeBoson"     ),
      product        ("product"        ),
      reaction       ("reaction"       ),
      spinGroup      ("spinGroup"      ),
      values         ("values"         );
} // namespace child

using namespace meta;
using namespace child;

} // namespace basic



// -----------------------------------------------------------------------------
// misc::
// Some miscellaneous Meta and Child objects for use in various test codes.
// These are "miscellaneous" in the sense that some use <void>, meaning that
// they'll retrieve metadata and child nodes in their original form in the
// GNDS tree, while others stipulate specific types.
// -----------------------------------------------------------------------------

// Helper for cdata Child object below
namespace njoy {
namespace GNDStk {
namespace detail {
   // text_metadatum_to_string
   class text_metadatum_to_string {
   public:
      template<class NODE>
      void operator()(const NODE &node, std::string &to) const
      {
         to = node.meta(special::text);
      }
   };
} // namespace detail
} // namespace GNDStk
} // namespace njoy

namespace misc {

// ------------------------
// Meta<>
// ------------------------

namespace meta {
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
   inline const njoy::GNDStk::Meta<double> dvalue("value");
} // namespace meta

// ------------------------
// Child<>
// ------------------------

namespace child {
   // Some top-level nodes, per LLNL-TR-774621-DRAFT
   inline const njoy::GNDStk::Child<void,njoy::GNDStk::Allow::one>
      PoPs             ("PoPs"),
      reactionSuite    ("reactionSuite"),
      covarianceSuite  ("covarianceSuite"),
      thermalScattering("thermalScattering");

   // Misc. Child Objects
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
   inline const njoy::GNDStk::Child<void,njoy::GNDStk::Allow::one>
      xml(njoy::GNDStk::special::xml);
   GNDSTK_MAKE_CHILD(void, evaluated, many);
   GNDSTK_MAKE_CHILD(void, XYs1d, many);

   // cdata
   // This is where XML <!-- ... --> (comment) material resides. It's reasonable
   // to extract such content into std::strings. We then store these in nodes
   // of name CDATA, each with one metadatum having a key of TEXT and a value
   // containing the original content.
   inline const njoy::GNDStk::Child<
      std::string,
      njoy::GNDStk::Allow::one,
      njoy::GNDStk::detail::text_metadatum_to_string
   >
   cdata(njoy::GNDStk::special::cdata);
} // namespace child

using namespace meta;
using namespace child;

} // namespace misc



// -----------------------------------------------------------------------------
// Some Child objects that are useful enough as-is that we wish to include them
// in other sets of such objects, in other namespaces.
// -----------------------------------------------------------------------------

namespace njoy {
namespace GNDStk {
namespace detail {

// ------------------------
// convert_data_text_t
// ------------------------

class convert_data_text_t {
public:

   // Node to container
   template<class CONTAINER>
   void operator()(const njoy::GNDStk::Node &node, CONTAINER &container) const
   {
      using namespace njoy::GNDStk;
      try {
         // Context:
         // We're inside of a <pcdata> node that's inside of a <values>
         // node that looked something like this (in XML):
         //    <values>0.0 1.0 2.0 3.0 4.0</values>
         // In GNDStk, the <pcdata> node has a metadatum with the key
         // special::text. The metadatum's string value is the content:
         // "0.0 1.0 ..." in our example. Goal here: extract that content
         // into the container.
         container.clear();
         for (auto &m : node.metadata)
            if (m.first == special::text) {
               convert(m.second, container);
               return;
            }
         log::error(
           "Could not find metadatum key \"#text\" "
           "in the current Node (\"{}\")",
            node.name
         );
         throw std::exception{};
      } catch (...) {
         log::function("convert_data_text_t(Node,container)");
         throw;
      }
   }

   // container to Node
   template<class CONTAINER>
   void operator()(const CONTAINER &container, njoy::GNDStk::Node &node) const
   {
      using namespace njoy::GNDStk;
      try {
         node.clear();
         node.name = special::data;
         std::string &destination = node.add(special::text,"").second;
         convert(container, destination);
      } catch (...) {
         log::function("convert_data_text_t(container,Node)");
         throw;
      }
   }
};

// ------------------------
// numeric_type
// ------------------------

// default
// create vector
template<class T>
class numeric_type {
public:
   using type = std::vector<T>;
};

// keep deque
template<class T, class Alloc>
class numeric_type<std::deque<T,Alloc>> {
public:
   using type = std::deque<T,Alloc>;
};

// keep list
template<class T, class Alloc>
class numeric_type<std::list<T,Alloc>> {
public:
   using type = std::list<T,Alloc>;
};

// keep vector
template<class T, class Alloc>
class numeric_type<std::vector<T,Alloc>> {
public:
   using type = std::vector<T,Alloc>;
};

} // namespace detail
} // namespace GNDStk
} // namespace njoy

// ------------------------
// Child<>
// ------------------------

namespace common {

// Helper: getNumeric
// Doing numeric (below) strictly as a variable template would lead
// to initialization-order issues with the specializations.
template<class T = double>
const auto &getNumeric()
{
   static const njoy::GNDStk::Child<
      // for general T, the following produces a vector<T>;
      // for T already a vector, it remains as-is
      typename njoy::GNDStk::detail::numeric_type<T>::type,
      njoy::GNDStk::Allow::one,
      njoy::GNDStk::detail::convert_data_text_t
   > ret(njoy::GNDStk::special::data);
   return ret;
}

// numeric
template<class T = double>
inline const auto numeric = getNumeric<T>();

// specializations, for float and double
inline const auto floats  = getNumeric<float >();
inline const auto doubles = getNumeric<double>();

} // namespace common

namespace basic { using namespace common; }
namespace misc  { using namespace common; }
