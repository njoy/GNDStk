########################################################################
# Preamble
########################################################################

cmake_minimum_required( VERSION 3.14 )
project( GNDStk LANGUAGES CXX )


########################################################################
# Project-wide setup
########################################################################

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED YES )

option( GNDStk_unit_tests
    "Compile the GNDStk unit tests and integrate with ctest" ON
    )


########################################################################
# Dependencies
########################################################################

include( cmake/GNDStk_dependencies.cmake )


########################################################################
# Project targets
########################################################################

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# GNDStk: library
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include_directories( src/ )

add_library( GNDStk INTERFACE )
target_include_directories( GNDStk INTERFACE src/ simple-json/src/ )
target_link_libraries(
    GNDStk
    INTERFACE Log
    INTERFACE catch-adapter
    INTERFACE pugixml-adapter
    INTERFACE HighFive
    )

add_executable(
    json2class.exe
    EXCLUDE_FROM_ALL
    autogen/json2class.cpp
    )
target_link_libraries(
    json2class.exe
    PRIVATE GNDStk
    )

set_target_properties( pugixml-adapter PROPERTIES POSITION_INDEPENDENT_CODE ON)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# GNDStk: python bindings
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include_directories(
    python/src/
    autogen/prototype/proto/src/
    standards/GNDS-v2.0/GNDS/src
    standards/GNDS-v2.0/GNDS/python/src
    )

pybind11_add_module(
    GNDStk.python.old
    EXCLUDE_FROM_ALL
    python/src/GNDStk.python.cpp
    python/src/core/Node.python.cpp
    python/src/enums/BoundaryCondition.python.cpp
    python/src/enums/ContributorType.python.cpp
    python/src/enums/DateType.python.cpp
    python/src/enums/DecayType.python.cpp
    python/src/enums/Frame.python.cpp
    python/src/enums/GridStyle.python.cpp
    python/src/enums/HashAlgorithm.python.cpp
    python/src/enums/Interaction.python.cpp
    python/src/enums/Interpolation.python.cpp
    python/src/enums/InterpolationQualifier.python.cpp
    python/src/enums/Parity.python.cpp
    python/src/enums/RelationType.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/g3d/Starts.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/g3d/Lengths.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/g3d/Array.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/SelfScatteringKernel.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Sums.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Values.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/NuclearTerm.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ImaginaryAnomalousFactor.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/BoundAtomCrossSection.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Isotopes.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Standard.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Unresolved.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ThermalNeutronScatteringLaw_incoherentInelastic.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DecayMode.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/InternalConversionCoefficients.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Temperature.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Polynomial1d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Product.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/NuclearPlusInterference.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Branching1d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/FreeGasApproximation.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Isotope.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/MultiplicitySums.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ScatteringAtom.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Nuclide.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/AverageEnergy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/PrimaryGamma.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Spectrum.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/OrphanProduct.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DelayedNeutronKE.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Time.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/IncidentEnergies.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Distribution.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Gridded3d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ThermalNeutronScatteringLaw1d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/AverageProductEnergy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Q.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/AngularTwoBody.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/R.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DecayPath.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Summand.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Title.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Continuum.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ResonanceReactions.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/G.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/EnergyAngular.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Institution.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/String.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Width.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/CrossSectionSum.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ScatteringRadius.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Table.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Nuclides.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/NuclearAmplitudeExpansion.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/GaugeBoson.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Spectra.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ProductYields.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Theta.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/LevelSpacing.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/J.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/PromptProductKE.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Widths.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/MultiplicitySum.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Parameters.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Grid.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Add.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Slice.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ProductYield.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/MadlandNix.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/BindingEnergy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DebyeWallerIntegral.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/CovarianceSections.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Link.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/AverageParameterCovariance.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Energy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Body.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Alias.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Uncertainty.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Reactions.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/XYs1d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Configurations.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Weighted.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Resolved.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/FissionEnergyReleases.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Baryon.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/IncoherentPhotonScattering.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ENDFconversionFlags.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/FissionComponent.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ScatteringAtoms.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Configuration.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/PromptGammaEnergy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/E_max.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/IncompleteReactions.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/CrossSectionReconstructed.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Productions.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Charge.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/PhotonEmissionProbabilities.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Probability.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/FissionComponents.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/XYs3d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/SpinGroups.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/T_M.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/SpinGroup.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DiscreteGamma.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Production.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/CoulombPlusNuclearElastic.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ChemicalElements.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Unorthodox.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/FormFactor.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/S_table.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/SimpleMaxwellianFission.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/AverageEnergies.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Shell.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/RealAnomalousFactor.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/CoherentPhotonScattering.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Background.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DecayData.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/KalbachMann.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DelayedBetaEnergy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Lepton.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Dates.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DoubleDifferentialCrossSection.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Authors.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ElapsedTimes.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ScatteringFactor.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Ls.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/RutherfordScattering.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Fraction.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/NBodyPhaseSpace.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ExternalFiles.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Conversion.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ParameterCovarianceMatrix.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/RMatrix.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/EFH.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ParameterLink.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ChemicalElement.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Constant1d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Baryons.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ParameterCovariance.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/IncidentEnergy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/NonNeutrinoEnergy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/FastRegion.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Halflife.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Angular.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ProjectileEnergyDomain.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ExternalFile.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ResonanceReaction.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Data.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ApplicationData.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/PromptNeutronKE.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/HardSphereRadius.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Reference.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Nucleus.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Function2ds.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Unspecified.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ShortRangeSelfScalingVariance.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Spin.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Leptons.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Author.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/CovarianceSection.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/FissionEnergyRelease.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Channels.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Unorthodoxes.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Gridded2d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/OrphanProducts.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DelayedNeutron.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Slices.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ListOfCovariances.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Decay.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Axes.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Covariance.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Mass.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ThermalNeutronScatteringLaw_incoherentElastic.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/AngularEnergy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/SCTApproximation.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DelayedNeutrons.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Multiplicity.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/WeightedFunctionals.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/EFL.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Column.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Integer.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DecayModes.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/XYs2d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Branching3d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ResonanceParameters.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ResolvedRegion.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/UnresolvedRegion.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/RealInterferenceTerm.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Intensity.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Discrete.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/TotalEnergy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ParameterCovariances.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Regions1d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/DelayedGammaEnergy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/NeutrinoEnergy.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ColumnData.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ElapsedTime.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ColumnHeaders.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/PositronEmissionIntensity.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Recoil.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Evaluated.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Atomic.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/CrossSectionSums.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Resonances.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/CrossSection.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/BreitWigner.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Date.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Uncorrelated.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ThermalNeutronScatteringLaw_coherentElastic.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Isotropic2d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/L.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Products.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/F.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Legendre.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/U.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Mixed.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/E_critical.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/T_effective.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Channel.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Parity.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Sum.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Double.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Summands.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/GeneralEvaporation.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/TabulatedWidths.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Evaporation.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Yields.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Regions2d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ImaginaryInterferenceTerm.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/OutputChannel.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Js.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/EndfCompatible.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Reaction.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Documentation.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/MetaStable.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Rate.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/CovarianceMatrix.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Styles.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Array.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ThermalNeutronScatteringLaw.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Axis.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Aliases.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/RowData.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/Function1ds.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/GaugeBosons.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general/ResonancesWithBackground.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/reduced/Polynomial1d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/reduced/Product.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/reduced/Distribution.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/reduced/Nuclides.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/reduced/CrossSection.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/reduced/Products.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/reduced/Double.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/reduced/OutputChannel.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/reduced/Function1ds.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/g2d/Array.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/top/FissionFragmentData.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/top/ReactionSuite.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/top/PoPs.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/top/CovarianceSuite.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/g3d.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/general.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/top.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/reduced.python.cpp
    standards/GNDS-v2.0/GNDS/python/src/v2.0/g2d.python.cpp
    )

target_link_libraries( GNDStk.python.old PRIVATE GNDStk )
target_compile_options(GNDStk.python.old PRIVATE "-fvisibility=hidden" )
set_target_properties( GNDStk.python.old PROPERTIES OUTPUT_NAME GNDStk )
set_target_properties( GNDStk.python.old PROPERTIES COMPILE_DEFINITIONS "PYBIND11" )
set_target_properties( GNDStk.python.old PROPERTIES POSITION_INDEPENDENT_CODE ON)

pybind11_add_module(
    GNDStk.python
    EXCLUDE_FROM_ALL
    python/src/all.python.cpp
    )

target_link_libraries( GNDStk.python PRIVATE GNDStk )
target_compile_options(GNDStk.python PRIVATE "-fvisibility=hidden" )
set_target_properties( GNDStk.python PROPERTIES OUTPUT_NAME GNDStk )
set_target_properties( GNDStk.python PROPERTIES COMPILE_DEFINITIONS "PYBIND11" )
set_target_properties( GNDStk.python PROPERTIES POSITION_INDEPENDENT_CODE ON)

#######################################################################
# Top-level Only
#######################################################################

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR )
    # unit testing
    if( GNDStk_unit_tests )
        include( cmake/unit_testing.cmake )
    endif()
endif()
