
namespace child {

// -----------------------------------------------------------------------------
// child_t<void,...>
// For all elements that we see in every existing XML-format GNDS file that
// we have. The list below was auto-generated by a code we wrote to look for
// all such elements, and to guess (based on what it saw) if it should be
// given as find::one or find::all. We also tweaked the auto-generated list
// just a bit; for example, to change "double" to "Double".
// -----------------------------------------------------------------------------

// A child_t<void> will retrieve an element in its original form in the GNDS
// tree: as (a const or non-const reference to) a Node.


// -----------------------------------------------------------------------------
// Potential top-level elements. We saw the first four used as top-level nodes
// in the library of XML-format GNDS files. The last, fissionFragmentData, can
// be a top-level node according to the GNDS manual.
// -----------------------------------------------------------------------------

inline const child_t<void,find::one>
   PoPs               ("PoPs"               , true);
inline const child_t<void,find::one>
   covarianceSuite    ("covarianceSuite"    , true);
inline const child_t<void,find::one>
   reactionSuite      ("reactionSuite"      , true);
inline const child_t<void,find::one>
   thermalScattering  ("thermalScattering"  , true);
inline const child_t<void,find::one>
   fissionFragmentData("fissionFragmentData", true);


// -----------------------------------------------------------------------------
// General elements
// -----------------------------------------------------------------------------

inline const child_t<void,find::one>
   BreitWigner                     ("BreitWigner"                     );
inline const child_t<void,find::one>
   CoulombPlusNuclearElastic       ("CoulombPlusNuclearElastic"       );
inline const child_t<void,find::one>
   DebyeWaller                     ("DebyeWaller"                     );
inline const child_t<void,find::one>
   EFH                             ("EFH"                             );
inline const child_t<void,find::one>
   EFL                             ("EFL"                             );
inline const child_t<void,find::one>
   ENDFconversionFlags             ("ENDFconversionFlags"             );
inline const child_t<void,find::all>
   J                               ("J"                               );
inline const child_t<void,find::one>
   Js                              ("Js"                              );
inline const child_t<void,find::one>
   KalbachMann                     ("KalbachMann"                     );
inline const child_t<void,find::all>
   L                               ("L"                               );
inline const child_t<void,find::all>
   Legendre                        ("Legendre"                        );
inline const child_t<void,find::one>
   Ls                              ("Ls"                              );
inline const child_t<void,find::one>
   MadlandNix                      ("MadlandNix"                      );
inline const child_t<void,find::one>
   NBodyPhaseSpace                 ("NBodyPhaseSpace"                 );
inline const child_t<void,find::one>
   Q                               ("Q"                               );
inline const child_t<void,find::one>
   RMatrix                         ("RMatrix"                         );
inline const child_t<void,find::one>
   RutherfordScattering            ("RutherfordScattering"            );
inline const child_t<void,find::one>
   S_alpha_beta                    ("S_alpha_beta"                    );
inline const child_t<void,find::one>
   S_table                         ("S_table"                         );
inline const child_t<void,find::one>
   T_M                             ("T_M"                             );
inline const child_t<void,find::one>
   T_effective                     ("T_effective"                     );
inline const child_t<void,find::one>
   U                               ("U"                               );
inline const child_t<void,find::all>
   XYs1d                           ("XYs1d"                           );
inline const child_t<void,find::all>
   XYs2d                           ("XYs2d"                           );
inline const child_t<void,find::one>
   XYs3d                           ("XYs3d"                           );
inline const child_t<void,find::all>
   add                             ("add"                             );
inline const child_t<void,find::one>
   aliases                         ("aliases"                         );
inline const child_t<void,find::one>
   angular                         ("angular"                         );
inline const child_t<void,find::one>
   angularEnergy                   ("angularEnergy"                   );
inline const child_t<void,find::one>
   angularTwoBody                  ("angularTwoBody"                  );
inline const child_t<void,find::one>
   applicationData                 ("applicationData"                 );
inline const child_t<void,find::one>
   array                           ("array"                           );
inline const child_t<void,find::one>
   atomic                          ("atomic"                          );
inline const child_t<void,find::one>
   averageEnergies                 ("averageEnergies"                 );
inline const child_t<void,find::all>
   averageEnergy                   ("averageEnergy"                   );
inline const child_t<void,find::all>
   averageParameterCovariance      ("averageParameterCovariance"      );
inline const child_t<void,find::one>
   averageProductEnergy            ("averageProductEnergy"            );
inline const child_t<void,find::one>
   axes                            ("axes"                            );
inline const child_t<void,find::all>
   axis                            ("axis"                            );
inline const child_t<void,find::one>
   background                      ("background"                      );
inline const child_t<void,find::one>
   baryon                          ("baryon"                          );
inline const child_t<void,find::one>
   baryons                         ("baryons"                         );
inline const child_t<void,find::one>
   bindingEnergy                   ("bindingEnergy"                   );
inline const child_t<void,find::one>
   branching1d                     ("branching1d"                     );
inline const child_t<void,find::one>
   branching3d                     ("branching3d"                     );
inline const child_t<void,find::one>
   cdata                           ("cdata"                           );
inline const child_t<void,find::all>
   channel                         ("channel"                         );
inline const child_t<void,find::one>
   channels                        ("channels"                        );
inline const child_t<void,find::one>
   characteristicCrossSection      ("characteristicCrossSection"      );
inline const child_t<void,find::one>
   charge                          ("charge"                          );
inline const child_t<void,find::all>
   chemicalElement                 ("chemicalElement"                 );
inline const child_t<void,find::one>
   chemicalElements                ("chemicalElements"                );
inline const child_t<void,find::one>
   coherentElastic                 ("coherentElastic"                 );
inline const child_t<void,find::one>
   coherentPhotonScattering        ("coherentPhotonScattering"        );
inline const child_t<void,find::all>
   column                          ("column"                          );
inline const child_t<void,find::one>
   columnData                      ("columnData"                      );
inline const child_t<void,find::one>
   columnHeaders                   ("columnHeaders"                   );
inline const child_t<void,find::all>
   comment                         ("comment"                         );
inline const child_t<void,find::all>
   configuration                   ("configuration"                   );
inline const child_t<void,find::one>
   configurations                  ("configurations"                  );
inline const child_t<void,find::one>
   constant1d                      ("constant1d"                      );
inline const child_t<void,find::one>
   continuum                       ("continuum"                       );
inline const child_t<void,find::all>
   conversion                      ("conversion"                      );
inline const child_t<void,find::all>
   covariance                      ("covariance"                      );
inline const child_t<void,find::all>
   covarianceMatrix                ("covarianceMatrix"                );
inline const child_t<void,find::one>
   covarianceSections              ("covarianceSections"              );
inline const child_t<void,find::one>
   crossSection                    ("crossSection"                    );
inline const child_t<void,find::one>
   crossSectionReconstructed       ("crossSectionReconstructed"       );
inline const child_t<void,find::all>
   crossSectionSum                 ("crossSectionSum"                 );
inline const child_t<void,find::one>
   crossSections                   ("crossSections"                   );
inline const child_t<void,find::one>
   cutoffEnergy                    ("cutoffEnergy"                    );
inline const child_t<void,find::one>
   data                            ("data"                            );
inline const child_t<void,find::all>
   decay                           ("decay"                           );
inline const child_t<void,find::one>
   decayData                       ("decayData"                       );
inline const child_t<void,find::all>
   decayMode                       ("decayMode"                       );
inline const child_t<void,find::one>
   decayModes                      ("decayModes"                      );
inline const child_t<void,find::one>
   decayPath                       ("decayPath"                       );
inline const child_t<void,find::one>
   delayedBetaEnergy               ("delayedBetaEnergy"               );
inline const child_t<void,find::one>
   delayedGammaEnergy              ("delayedGammaEnergy"              );
inline const child_t<void,find::one>
   delayedNeutronKE                ("delayedNeutronKE"                );
inline const child_t<void,find::all>
   discrete                        ("discrete"                        );
inline const child_t<void,find::one>
   discreteGamma                   ("discreteGamma"                   );
inline const child_t<void,find::one>
   distribution                    ("distribution"                    );
inline const child_t<void,find::one>
   documentation                   ("documentation"                   );
inline const child_t<void,find::one>
   documentations                  ("documentations"                  );
inline const child_t<void,find::one>
   Double                          ("double"                          );
inline const child_t<void,find::one>
   doubleDifferentialCrossSection  ("doubleDifferentialCrossSection"  );
inline const child_t<void,find::all>
   duration                        ("duration"                        );
inline const child_t<void,find::one>
   durations                       ("durations"                       );
inline const child_t<void,find::one>
   e_critical                      ("e_critical"                      );
inline const child_t<void,find::one>
   e_max                           ("e_max"                           );
inline const child_t<void,find::one>
   energy                          ("energy"                          );
inline const child_t<void,find::one>
   energyAngular                   ("energyAngular"                   );
inline const child_t<void,find::one>
   evaluated                       ("evaluated"                       );
inline const child_t<void,find::one>
   evaporation                     ("evaporation"                     );
inline const child_t<void,find::all>
   externalFile                    ("externalFile"                    );
inline const child_t<void,find::one>
   externalFiles                   ("externalFiles"                   );
inline const child_t<void,find::one>
   f                               ("f"                               );
inline const child_t<void,find::one>
   fastRegion                      ("fastRegion"                      );
inline const child_t<void,find::all>
   fissionComponent                ("fissionComponent"                );
inline const child_t<void,find::one>
   fissionComponents               ("fissionComponents"               );
inline const child_t<void,find::one>
   fissionEnergyReleased           ("fissionEnergyReleased"           );
inline const child_t<void,find::one>
   fraction                        ("fraction"                        );
inline const child_t<void,find::one>
   freeAtomCrossSection            ("freeAtomCrossSection"            );
inline const child_t<void,find::one>
   g                               ("g"                               );
inline const child_t<void,find::one>
   gaugeBoson                      ("gaugeBoson"                      );
inline const child_t<void,find::one>
   gaugeBosons                     ("gaugeBosons"                     );
inline const child_t<void,find::one>
   generalEvaporation              ("generalEvaporation"              );
inline const child_t<void,find::all>
   grid                            ("grid"                            );
inline const child_t<void,find::one>
   gridded2d                       ("gridded2d"                       );
inline const child_t<void,find::one>
   gridded3d                       ("gridded3d"                       );
inline const child_t<void,find::one>
   halflife                        ("halflife"                        );
inline const child_t<void,find::one>
   hardSphereRadius                ("hardSphereRadius"                );
inline const child_t<void,find::one>
   imaginaryAnomalousFactor        ("imaginaryAnomalousFactor"        );
inline const child_t<void,find::one>
   imaginaryInterferenceTerm       ("imaginaryInterferenceTerm"       );
inline const child_t<void,find::one>
   incoherentElastic               ("incoherentElastic"               );
inline const child_t<void,find::one>
   incoherentInelastic             ("incoherentInelastic"             );
inline const child_t<void,find::one>
   incoherentPhotonScattering      ("incoherentPhotonScattering"      );
inline const child_t<void,find::one>
   incompleteReactions             ("incompleteReactions"             );
inline const child_t<void,find::one>
   institution                     ("institution"                     );
inline const child_t<void,find::one>
   integer                         ("integer"                         );
inline const child_t<void,find::one>
   intensity                       ("intensity"                       );
inline const child_t<void,find::one>
   internalConversionCoefficients  ("internalConversionCoefficients"  );
inline const child_t<void,find::one>
   internalPairFormationCoefficient("internalPairFormationCoefficient");
inline const child_t<void,find::all>
   isotope                         ("isotope"                         );
inline const child_t<void,find::one>
   isotopes                        ("isotopes"                        );
inline const child_t<void,find::one>
   isotropic2d                     ("isotropic2d"                     );
inline const child_t<void,find::all>
   lepton                          ("lepton"                          );
inline const child_t<void,find::one>
   leptons                         ("leptons"                         );
inline const child_t<void,find::one>
   levelSpacing                    ("levelSpacing"                    );
inline const child_t<void,find::one>
   link                            ("link"                            );
inline const child_t<void,find::one>
   listOfCovariances               ("listOfCovariances"               );
inline const child_t<void,find::one>
   mass                            ("mass"                            );
inline const child_t<void,find::all>
   metaStable                      ("metaStable"                      );
inline const child_t<void,find::one>
   mixed                           ("mixed"                           );
inline const child_t<void,find::one>
   multiplicities                  ("multiplicities"                  );
inline const child_t<void,find::one>
   multiplicity                    ("multiplicity"                    );
inline const child_t<void,find::all>
   multiplicitySum                 ("multiplicitySum"                 );
inline const child_t<void,find::one>
   neutrinoEnergy                  ("neutrinoEnergy"                  );
inline const child_t<void,find::one>
   nonNeutrinoEnergy               ("nonNeutrinoEnergy"               );
inline const child_t<void,find::one>
   nuclearAmplitudeExpansion       ("nuclearAmplitudeExpansion"       );
inline const child_t<void,find::one>
   nuclearPlusInterference         ("nuclearPlusInterference"         );
inline const child_t<void,find::one>
   nuclearTerm                     ("nuclearTerm"                     );
inline const child_t<void,find::one>
   nucleus                         ("nucleus"                         );
inline const child_t<void,find::all>
   nuclide                         ("nuclide"                         );
inline const child_t<void,find::one>
   nuclides                        ("nuclides"                        );
inline const child_t<void,find::one>
   orphanProducts                  ("orphanProducts"                  );
inline const child_t<void,find::one>
   outputChannel                   ("outputChannel"                   );
inline const child_t<void,find::one>
   parameterCovariance             ("parameterCovariance"             );
inline const child_t<void,find::one>
   parameterCovarianceMatrix       ("parameterCovarianceMatrix"       );
inline const child_t<void,find::one>
   parameterCovariances            ("parameterCovariances"            );
inline const child_t<void,find::all>
   parameterLink                   ("parameterLink"                   );
inline const child_t<void,find::one>
   parameters                      ("parameters"                      );
inline const child_t<void,find::one>
   parity                          ("parity"                          );
inline const child_t<void,find::one>
   pcdata                          ("pcdata"                          );
inline const child_t<void,find::one>
   photonEmissionProbabilities     ("photonEmissionProbabilities"     );
inline const child_t<void,find::one>
   pids                            ("pids"                            );
inline const child_t<void,find::one>
   polynomial1d                    ("polynomial1d"                    );
inline const child_t<void,find::one>
   positronEmissionIntensity       ("positronEmissionIntensity"       );
inline const child_t<void,find::one>
   primaryGamma                    ("primaryGamma"                    );
inline const child_t<void,find::one>
   probability                     ("probability"                     );
inline const child_t<void,find::all>
   product                         ("product"                         );
inline const child_t<void,find::one>
   productYield                    ("productYield"                    );
inline const child_t<void,find::one>
   productYields                   ("productYields"                   );
inline const child_t<void,find::all>
   production                      ("production"                      );
inline const child_t<void,find::one>
   productions                     ("productions"                     );
inline const child_t<void,find::one>
   products                        ("products"                        );
inline const child_t<void,find::one>
   projectileEnergyDomain          ("projectileEnergyDomain"          );
inline const child_t<void,find::one>
   promptGammaEnergy               ("promptGammaEnergy"               );
inline const child_t<void,find::one>
   promptNeutronKE                 ("promptNeutronKE"                 );
inline const child_t<void,find::one>
   promptProductKE                 ("promptProductKE"                 );
inline const child_t<void,find::one>
   r                               ("r"                               );
inline const child_t<void,find::all>
   reaction                        ("reaction"                        );
inline const child_t<void,find::one>
   reactions                       ("reactions"                       );
inline const child_t<void,find::one>
   realAnomalousFactor             ("realAnomalousFactor"             );
inline const child_t<void,find::one>
   realInterferenceTerm            ("realInterferenceTerm"            );
inline const child_t<void,find::one>
   recoil                          ("recoil"                          );
inline const child_t<void,find::one>
   reference                       ("reference"                       );
inline const child_t<void,find::all>
   regions1d                       ("regions1d"                       );
inline const child_t<void,find::one>
   regions2d                       ("regions2d"                       );
inline const child_t<void,find::one>
   resolved                        ("resolved"                        );
inline const child_t<void,find::one>
   resolvedRegion                  ("resolvedRegion"                  );
inline const child_t<void,find::one>
   resonanceParameters             ("resonanceParameters"             );
inline const child_t<void,find::all>
   resonanceReaction               ("resonanceReaction"               );
inline const child_t<void,find::one>
   resonanceReactions              ("resonanceReactions"              );
inline const child_t<void,find::one>
   resonances                      ("resonances"                      );
inline const child_t<void,find::one>
   resonancesWithBackground        ("resonancesWithBackground"        );
inline const child_t<void,find::one>
   rowData                         ("rowData"                         );
inline const child_t<void,find::all>
   scatteringAtom                  ("scatteringAtom"                  );
inline const child_t<void,find::one>
   scatteringAtoms                 ("scatteringAtoms"                 );
inline const child_t<void,find::one>
   scatteringFactor                ("scatteringFactor"                );
inline const child_t<void,find::one>
   scatteringRadius                ("scatteringRadius"                );
inline const child_t<void,find::all>
   section                         ("section"                         );
inline const child_t<void,find::all>
   shell                           ("shell"                           );
inline const child_t<void,find::one>
   shortRangeSelfScalingVariance   ("shortRangeSelfScalingVariance"   );
inline const child_t<void,find::one>
   simpleMaxwellianFission         ("simpleMaxwellianFission"         );
inline const child_t<void,find::one>
   spectra                         ("spectra"                         );
inline const child_t<void,find::all>
   spectrum                        ("spectrum"                        );
inline const child_t<void,find::one>
   spin                            ("spin"                            );
inline const child_t<void,find::all>
   spinGroup                       ("spinGroup"                       );
inline const child_t<void,find::one>
   spinGroups                      ("spinGroups"                      );
inline const child_t<void,find::one>
   standard                        ("standard"                        );
inline const child_t<void,find::one>
   string                          ("string"                          );
inline const child_t<void,find::one>
   styles                          ("styles"                          );
inline const child_t<void,find::all>
   sum                             ("sum"                             );
inline const child_t<void,find::all>
   summand                         ("summand"                         );
inline const child_t<void,find::one>
   summands                        ("summands"                        );
inline const child_t<void,find::one>
   sums                            ("sums"                            );
inline const child_t<void,find::one>
   table                           ("table"                           );
inline const child_t<void,find::one>
   tabulatedWidths                 ("tabulatedWidths"                 );
inline const child_t<void,find::one>
   temperature                     ("temperature"                     );
inline const child_t<void,find::one>
   theta                           ("theta"                           );
inline const child_t<void,find::one>
   time                            ("time"                            );
inline const child_t<void,find::one>
   totalEnergy                     ("totalEnergy"                     );
inline const child_t<void,find::one>
   uncertainty                     ("uncertainty"                     );
inline const child_t<void,find::one>
   uncorrelated                    ("uncorrelated"                    );
inline const child_t<void,find::one>
   unresolved                      ("unresolved"                      );
inline const child_t<void,find::one>
   unresolvedRegion                ("unresolvedRegion"                );
inline const child_t<void,find::one>
   unspecified                     ("unspecified"                     );

/*
// We should consider other ideas for <values>, which usually contains only
// plain character data (XML "pcdata") but *occasionally* contains metadata
// as well. And, <values> usually appears just once (so that find::one would
// be better), but *occasionally* appears more than once, in the same parent
// node; see for example some <array> parent nodes in n-094_Pu_239-covar.xml.
inline const child_t<void,find::all>
   values                          ("values"                          );
*/

inline const child_t<void,find::all>
   weighted                        ("weighted"                        );
inline const child_t<void,find::one>
   weightedFunctionals             ("weightedFunctionals"             );
inline const child_t<void,find::all>
   width                           ("width"                           );
inline const child_t<void,find::one>
   widths                          ("widths"                          );
inline const child_t<void,find::one>
   xml                             ("xml"                             );
inline const child_t<void,find::one>
   yields                          ("yields"                          );

} // namespace child
