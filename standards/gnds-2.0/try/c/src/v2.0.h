
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// -----------------------------------------------------------------------------
// This header file is designed to work with both C and C++
// -----------------------------------------------------------------------------

#ifndef C_INTERFACE_TRY_V2_0
#define C_INTERFACE_TRY_V2_0

#include "GNDStk.h"

#ifdef __cplusplus
   // For C++
   #include "try/v2_0.hpp"
#endif

#include "v2.0/appData/ApplicationData.h"
#include "v2.0/appData/Institution.h"
#include "v2.0/appData/ENDFconversionFlags.h"
#include "v2.0/appData/Conversion.h"

#include "v2.0/atomic/CoherentPhotonScattering.h"
#include "v2.0/atomic/ImaginaryAnomalousFactor.h"
#include "v2.0/atomic/IncoherentPhotonScattering.h"
#include "v2.0/atomic/RealAnomalousFactor.h"
#include "v2.0/atomic/ScatteringFactor.h"
#include "v2.0/atomic/FormFactor.h"

#include "v2.0/common/Q.h"
#include "v2.0/common/Product.h"
#include "v2.0/common/Products.h"
#include "v2.0/common/Mass.h"
#include "v2.0/common/Energy.h"
#include "v2.0/common/Probability.h"
#include "v2.0/common/Temperature.h"
#include "v2.0/common/ExternalFiles.h"
#include "v2.0/common/ExternalFile.h"

#include "v2.0/covariance/CovarianceSuite.h"
#include "v2.0/covariance/CovarianceSections.h"
#include "v2.0/covariance/CovarianceMatrix.h"
#include "v2.0/covariance/SandwichProduct.h"
#include "v2.0/covariance/Covariance.h"
#include "v2.0/covariance/RowSensitivity.h"
#include "v2.0/covariance/ColumnSensitivity.h"
#include "v2.0/covariance/ParameterCovariances.h"
#include "v2.0/covariance/Parameters.h"
#include "v2.0/covariance/ParameterCovariance.h"
#include "v2.0/covariance/ParameterCovarianceMatrix.h"
#include "v2.0/covariance/ParameterLink.h"
#include "v2.0/covariance/ShortRangeSelfScalingVariance.h"
#include "v2.0/covariance/Mixed.h"
#include "v2.0/covariance/AverageParameterCovariance.h"
#include "v2.0/covariance/CovarianceSection.h"
#include "v2.0/covariance/RowData.h"
#include "v2.0/covariance/ColumnData.h"
#include "v2.0/covariance/Slices.h"
#include "v2.0/covariance/Slice.h"
#include "v2.0/covariance/Sum.h"
#include "v2.0/covariance/Summand.h"

#include "v2.0/cpTransport/RutherfordScattering.h"
#include "v2.0/cpTransport/CoulombPlusNuclearElastic.h"
#include "v2.0/cpTransport/NuclearPlusInterference.h"
#include "v2.0/cpTransport/NuclearAmplitudeExpansion.h"
#include "v2.0/cpTransport/NuclearTerm.h"
#include "v2.0/cpTransport/RealInterferenceTerm.h"
#include "v2.0/cpTransport/ImaginaryInterferenceTerm.h"

#include "v2.0/documentation/Documentation.h"
#include "v2.0/documentation/Authors.h"
#include "v2.0/documentation/Author.h"
#include "v2.0/documentation/Contributors.h"
#include "v2.0/documentation/Contributor.h"
#include "v2.0/documentation/Affiliations.h"
#include "v2.0/documentation/Affiliation.h"
#include "v2.0/documentation/Collaborations.h"
#include "v2.0/documentation/Collaboration.h"
#include "v2.0/documentation/Dates.h"
#include "v2.0/documentation/Date.h"
#include "v2.0/documentation/Title.h"
#include "v2.0/documentation/Abstract.h"
#include "v2.0/documentation/Body.h"
#include "v2.0/documentation/Copyright.h"
#include "v2.0/documentation/Version.h"
#include "v2.0/documentation/Acknowledgements.h"
#include "v2.0/documentation/Acknowledgement.h"
#include "v2.0/documentation/RelatedItems.h"
#include "v2.0/documentation/RelatedItem.h"
#include "v2.0/documentation/Keywords.h"
#include "v2.0/documentation/Keyword.h"
#include "v2.0/documentation/ComputerCodes.h"
#include "v2.0/documentation/ComputerCode.h"
#include "v2.0/documentation/CodeRepo.h"
#include "v2.0/documentation/InputDecks.h"
#include "v2.0/documentation/InputDeck.h"
#include "v2.0/documentation/OutputDecks.h"
#include "v2.0/documentation/OutputDeck.h"
#include "v2.0/documentation/ExecutionArguments.h"
#include "v2.0/documentation/ExperimentalDataSets.h"
#include "v2.0/documentation/ExforDataSets.h"
#include "v2.0/documentation/ExforDataSet.h"
#include "v2.0/documentation/CovarianceScript.h"
#include "v2.0/documentation/CorrectionScript.h"
#include "v2.0/documentation/Note.h"
#include "v2.0/documentation/Bibliography.h"
#include "v2.0/documentation/Bibitem.h"
#include "v2.0/documentation/EndfCompatible.h"

#include "v2.0/fissionFragmentData/FissionFragmentData.h"
#include "v2.0/fissionFragmentData/DelayedNeutrons.h"
#include "v2.0/fissionFragmentData/DelayedNeutron.h"
#include "v2.0/fissionFragmentData/Rate.h"

#include "v2.0/fissionTransport/FissionComponents.h"
#include "v2.0/fissionTransport/FissionComponent.h"
#include "v2.0/fissionTransport/FissionEnergyReleased.h"
#include "v2.0/fissionTransport/DelayedBetaEnergy.h"
#include "v2.0/fissionTransport/TotalEnergy.h"
#include "v2.0/fissionTransport/DelayedGammaEnergy.h"
#include "v2.0/fissionTransport/NonNeutrinoEnergy.h"
#include "v2.0/fissionTransport/PromptGammaEnergy.h"
#include "v2.0/fissionTransport/NeutrinoEnergy.h"
#include "v2.0/fissionTransport/PromptProductKE.h"
#include "v2.0/fissionTransport/PromptNeutronKE.h"
#include "v2.0/fissionTransport/DelayedNeutronKE.h"
#include "v2.0/fissionTransport/Watt.h"
#include "v2.0/fissionTransport/A.h"
#include "v2.0/fissionTransport/B.h"
#include "v2.0/fissionTransport/SimpleMaxwellianFission.h"
#include "v2.0/fissionTransport/MadlandNix.h"
#include "v2.0/fissionTransport/T_M.h"
#include "v2.0/fissionTransport/EFL.h"
#include "v2.0/fissionTransport/EFH.h"

#include "v2.0/fpy/ProductYields.h"
#include "v2.0/fpy/ProductYield.h"
#include "v2.0/fpy/Nuclides.h"
#include "v2.0/fpy/ElapsedTimes.h"
#include "v2.0/fpy/ElapsedTime.h"
#include "v2.0/fpy/Time.h"
#include "v2.0/fpy/Yields.h"
#include "v2.0/fpy/IncidentEnergies.h"
#include "v2.0/fpy/IncidentEnergy.h"
#include "v2.0/fpy/Energy.h"

#include "v2.0/containers/Double.h"
#include "v2.0/containers/Integer.h"
#include "v2.0/containers/Fraction.h"
#include "v2.0/containers/String.h"
#include "v2.0/containers/Link.h"
#include "v2.0/containers/Uncertainty.h"
#include "v2.0/containers/ListOfCovariances.h"
#include "v2.0/containers/Covariance.h"
#include "v2.0/containers/Standard.h"
#include "v2.0/containers/LogNormal.h"
#include "v2.0/containers/ConfidenceIntervals.h"
#include "v2.0/containers/Interval.h"
#include "v2.0/containers/Pdf.h"
#include "v2.0/containers/Axes.h"
#include "v2.0/containers/Axis.h"
#include "v2.0/containers/Grid.h"
#include "v2.0/containers/Values.h"
#include "v2.0/containers/Array.h"
#include "v2.0/containers/Table.h"
#include "v2.0/containers/ColumnHeaders.h"
#include "v2.0/containers/Column.h"
#include "v2.0/containers/Data.h"
#include "v2.0/containers/XYs1d.h"
#include "v2.0/containers/Ys1d.h"
#include "v2.0/containers/Legendre.h"
#include "v2.0/containers/Polynomial1d.h"
#include "v2.0/containers/Constant1d.h"
#include "v2.0/containers/Xs_pdf_cdf1d.h"
#include "v2.0/containers/Xs_in_xs_pdf_cdf1d.h"
#include "v2.0/containers/Pdf_in_xs_pdf_cdf1d.h"
#include "v2.0/containers/Cdf_in_xs_pdf_cdf1d.h"
#include "v2.0/containers/XYs2d.h"
#include "v2.0/containers/Function1ds.h"
#include "v2.0/containers/XYs3d.h"
#include "v2.0/containers/Function2ds.h"
#include "v2.0/containers/Regions1d.h"
#include "v2.0/containers/Regions2d.h"
#include "v2.0/containers/Regions3d.h"
#include "v2.0/containers/Function3ds.h"
#include "v2.0/containers/Gridded1d.h"
#include "v2.0/containers/Gridded2d.h"
#include "v2.0/containers/Gridded3d.h"

#include "v2.0/map/Map.h"
#include "v2.0/map/Import.h"
#include "v2.0/map/Protare.h"
#include "v2.0/map/TNSL.h"

#include "v2.0/pops/PoPs_database.h"
#include "v2.0/pops/Aliases.h"
#include "v2.0/pops/Alias.h"
#include "v2.0/pops/MetaStable.h"
#include "v2.0/pops/GaugeBosons.h"
#include "v2.0/pops/GaugeBoson.h"
#include "v2.0/pops/Leptons.h"
#include "v2.0/pops/Lepton.h"
#include "v2.0/pops/Baryons.h"
#include "v2.0/pops/Baryon.h"
#include "v2.0/pops/ChemicalElements.h"
#include "v2.0/pops/ChemicalElement.h"
#include "v2.0/pops/Atomic.h"
#include "v2.0/pops/Configurations.h"
#include "v2.0/pops/Configuration.h"
#include "v2.0/pops/BindingEnergy.h"
#include "v2.0/pops/Isotopes.h"
#include "v2.0/pops/Isotope.h"
#include "v2.0/pops/Nuclides.h"
#include "v2.0/pops/Nuclide.h"
#include "v2.0/pops/Nucleus.h"
#include "v2.0/pops/Unorthodoxes.h"
#include "v2.0/pops/Unorthodox.h"
#include "v2.0/pops/Mass.h"
#include "v2.0/pops/Spin.h"
#include "v2.0/pops/Parity.h"
#include "v2.0/pops/Charge.h"
#include "v2.0/pops/Energy.h"
#include "v2.0/pops/Halflife.h"
#include "v2.0/pops/DecayData.h"
#include "v2.0/pops/DecayModes.h"
#include "v2.0/pops/DecayMode.h"
#include "v2.0/pops/Probability.h"
#include "v2.0/pops/InternalConversionCoefficients.h"
#include "v2.0/pops/PhotonEmissionProbabilities.h"
#include "v2.0/pops/PositronEmissionIntensity.h"
#include "v2.0/pops/Shell.h"
#include "v2.0/pops/Q.h"
#include "v2.0/pops/DecayPath.h"
#include "v2.0/pops/Decay.h"
#include "v2.0/pops/Products.h"
#include "v2.0/pops/Product.h"
#include "v2.0/pops/Spectra.h"
#include "v2.0/pops/Spectrum.h"
#include "v2.0/pops/Continuum.h"
#include "v2.0/pops/Discrete.h"
#include "v2.0/pops/DiscreteEnergy.h"
#include "v2.0/pops/Intensity.h"
#include "v2.0/pops/InternalPairFormationCoefficient.h"
#include "v2.0/pops/AverageEnergies.h"
#include "v2.0/pops/AverageEnergy.h"
#include "v2.0/pops/Uncertainty.h"
#include "v2.0/pops/Standard.h"
#include "v2.0/pops/LogNormal.h"
#include "v2.0/pops/ConfidenceIntervals.h"
#include "v2.0/pops/Interval.h"
#include "v2.0/pops/Pdf.h"

#include "v2.0/processed/MultiGroup3d.h"
#include "v2.0/processed/AngularEnergyMC.h"
#include "v2.0/processed/EnergyAngularMC.h"
#include "v2.0/processed/AverageProductEnergy.h"
#include "v2.0/processed/AverageProductMomentum.h"
#include "v2.0/processed/AvailableMomentum.h"
#include "v2.0/processed/AvailableEnergy.h"

#include "v2.0/resonances/Resonances.h"
#include "v2.0/resonances/ScatteringRadius.h"
#include "v2.0/resonances/HardSphereRadius.h"
#include "v2.0/resonances/ExternalRMatrix.h"
#include "v2.0/resonances/Resolved.h"
#include "v2.0/resonances/EnergyIntervals.h"
#include "v2.0/resonances/EnergyInterval.h"
#include "v2.0/resonances/RMatrix.h"
#include "v2.0/resonances/ResonanceReactions.h"
#include "v2.0/resonances/ResonanceReaction.h"
#include "v2.0/resonances/SpinGroups.h"
#include "v2.0/resonances/SpinGroup.h"
#include "v2.0/resonances/Channels.h"
#include "v2.0/resonances/Channel.h"
#include "v2.0/resonances/ResonanceParameters.h"
#include "v2.0/resonances/BreitWigner.h"
#include "v2.0/resonances/Unresolved.h"
#include "v2.0/resonances/TabulatedWidths.h"
#include "v2.0/resonances/Ls.h"
#include "v2.0/resonances/L.h"
#include "v2.0/resonances/Js.h"
#include "v2.0/resonances/J.h"
#include "v2.0/resonances/LevelSpacing.h"
#include "v2.0/resonances/Widths.h"
#include "v2.0/resonances/Width.h"

#include "v2.0/styles/Styles.h"
#include "v2.0/styles/Evaluated.h"
#include "v2.0/styles/ProjectileEnergyDomain.h"
#include "v2.0/styles/Temperature.h"
#include "v2.0/styles/CrossSectionReconstructed.h"
#include "v2.0/styles/AngularDistributionReconstructed.h"
#include "v2.0/styles/CoulombPlusNuclearElasticMuCutoff.h"
#include "v2.0/styles/Heated.h"
#include "v2.0/styles/AverageProductData.h"
#include "v2.0/styles/MonteCarlo_cdf.h"
#include "v2.0/styles/GriddedCrossSection.h"
#include "v2.0/styles/HeatedMultiGroup.h"
#include "v2.0/styles/Transportables.h"
#include "v2.0/styles/Transportable.h"
#include "v2.0/styles/MultiGroup.h"
#include "v2.0/styles/Flux.h"
#include "v2.0/styles/InverseSpeed.h"
#include "v2.0/styles/SnElasticUpScatter.h"
#include "v2.0/styles/URR_probabilityTables.h"
#include "v2.0/styles/Bondarenko.h"
#include "v2.0/styles/SigmaZeros.h"
#include "v2.0/styles/MultiBand.h"
#include "v2.0/styles/EqualProbableBins.h"
#include "v2.0/styles/Realization.h"

#include "v2.0/transport/ReactionSuite.h"
#include "v2.0/transport/Reactions.h"
#include "v2.0/transport/Reaction.h"
#include "v2.0/transport/Sums.h"
#include "v2.0/transport/OutputChannel.h"
#include "v2.0/transport/CrossSectionSums.h"
#include "v2.0/transport/CrossSection.h"
#include "v2.0/transport/ResonancesWithBackground.h"
#include "v2.0/transport/ResonancesLink.h"
#include "v2.0/transport/Background.h"
#include "v2.0/transport/ResolvedRegion.h"
#include "v2.0/transport/UnresolvedRegion.h"
#include "v2.0/transport/FastRegion.h"
#include "v2.0/transport/URR_probabilityTables1d.h"
#include "v2.0/transport/CrossSectionSum.h"
#include "v2.0/transport/DoubleDifferentialCrossSection.h"
#include "v2.0/transport/CoherentPhoton.h"
#include "v2.0/transport/IncoherentPhoton.h"
#include "v2.0/transport/MultiplicitySums.h"
#include "v2.0/transport/Multiplicity.h"
#include "v2.0/transport/Branching1d.h"
#include "v2.0/transport/OrphanProducts.h"
#include "v2.0/transport/OrphanProduct.h"
#include "v2.0/transport/MultiplicitySum.h"
#include "v2.0/transport/Distribution.h"
#include "v2.0/transport/Branching3d.h"
#include "v2.0/transport/MultiGroup3d.h"
#include "v2.0/transport/NBodyPhaseSpace.h"
#include "v2.0/transport/Angular_uncorrelated.h"
#include "v2.0/transport/Energy_uncorrelated.h"
#include "v2.0/transport/AngularEnergy.h"
#include "v2.0/transport/EnergyAngular.h"
#include "v2.0/transport/AngularTwoBody.h"
#include "v2.0/transport/Uncorrelated.h"
#include "v2.0/transport/Recoil.h"
#include "v2.0/transport/KalbachMann.h"
#include "v2.0/transport/GeneralEvaporation.h"
#include "v2.0/transport/WeightedFunctionals.h"
#include "v2.0/transport/Evaporation.h"
#include "v2.0/transport/Unspecified.h"
#include "v2.0/transport/DiscreteGamma.h"
#include "v2.0/transport/PhotonEmissionProbabilities.h"
#include "v2.0/transport/PrimaryGamma.h"
#include "v2.0/transport/Production.h"
#include "v2.0/transport/Productions.h"
#include "v2.0/transport/IncompleteReactions.h"
#include "v2.0/transport/Summands.h"
#include "v2.0/transport/Add.h"
#include "v2.0/transport/F.h"
#include "v2.0/transport/G.h"
#include "v2.0/transport/R.h"
#include "v2.0/transport/A.h"
#include "v2.0/transport/Theta.h"
#include "v2.0/transport/U.h"
#include "v2.0/transport/Forward.h"
#include "v2.0/transport/Isotropic2d.h"
#include "v2.0/transport/Weighted.h"
#include "v2.0/transport/Reference.h"

#include "v2.0/tsl/ThermalNeutronScatteringLaw1d.h"
#include "v2.0/tsl/ThermalNeutronScatteringLaw.h"
#include "v2.0/tsl/ThermalNeutronScatteringLaw_coherentElastic.h"
#include "v2.0/tsl/S_table.h"
#include "v2.0/tsl/BraggEdges.h"
#include "v2.0/tsl/BraggEdge.h"
#include "v2.0/tsl/BraggEnergy.h"
#include "v2.0/tsl/StructureFactor.h"
#include "v2.0/tsl/ThermalNeutronScatteringLaw_incoherentElastic.h"
#include "v2.0/tsl/DebyeWallerIntegral.h"
#include "v2.0/tsl/ThermalNeutronScatteringLaw_incoherentInelastic.h"
#include "v2.0/tsl/Mass.h"
#include "v2.0/tsl/ScatteringAtom.h"
#include "v2.0/tsl/ScatteringAtoms.h"
#include "v2.0/tsl/E_critical.h"
#include "v2.0/tsl/E_max.h"
#include "v2.0/tsl/BoundAtomCrossSection.h"
#include "v2.0/tsl/CoherentAtomCrossSection.h"
#include "v2.0/tsl/SelfScatteringKernel.h"
#include "v2.0/tsl/DistinctScatteringKernel.h"
#include "v2.0/tsl/T_effective.h"
#include "v2.0/tsl/GaussianApproximation.h"
#include "v2.0/tsl/PhononSpectrum.h"
#include "v2.0/tsl/SCTApproximation.h"
#include "v2.0/tsl/FreeGasApproximation.h"

#endif