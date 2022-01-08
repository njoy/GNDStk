
namespace child {

// -----------------------------------------------------------------------------
// Child<void,...>
// -----------------------------------------------------------------------------

// Note: a Child<void> will retrieve an element in its original form
// in the GNDS tree: as (a const or non-const reference to) a Node.

// ------------------------
// Some top-level nodes,
// per LLNL-TR-774621-DRAFT
// ------------------------

inline const Child<void,Allow::one> PoPs("PoPs");
inline const Child<void,Allow::one> reactionSuite("reactionSuite");

// ------------------------
// With Allow::one
// ------------------------

inline const Child<void,Allow::one>
   RMatrix            ("RMatrix"            ),
   angularTwoBody     ("angularTwoBody"     ),
   axes               ("axes"               ),
   cdata              ("#cdata"             ),
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
   pcdata             ("#pcdata"            ),
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

// ------------------------
// With Allow::many
// ------------------------

inline const Child<void,Allow::many>
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
