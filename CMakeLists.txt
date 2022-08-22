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
# GNDStk : library
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include_directories( src/ )

add_library( GNDStk INTERFACE )
target_include_directories( GNDStk INTERFACE src/ )
target_link_libraries( GNDStk
    INTERFACE Log
    INTERFACE catch-adapter
    INTERFACE pugixml-adapter
    INTERFACE nlohmann_json::nlohmann_json
    INTERFACE HighFive
    )

add_executable( json2class.exe
    EXCLUDE_FROM_ALL
    autogen/json2class.cpp
    )
target_link_libraries( json2class.exe
    PRIVATE GNDStk
    PRIVATE nlohmann_json::nlohmann_json
    )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# GNDStk : python bindings
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include_directories( python/src/ autogen/prototype/proto/src/ )

pybind11_add_module( GNDStk.python
    EXCLUDE_FROM_ALL
    python/src/GNDStk.python.cpp
    python/src/core/Node.python.cpp
    python/src/BoundaryCondition.python.cpp
    python/src/ContributorType.python.cpp
    python/src/DateType.python.cpp
    python/src/DecayType.python.cpp
    python/src/Frame.python.cpp
    python/src/GridStyle.python.cpp
    python/src/HashAlgorithm.python.cpp
    python/src/Interaction.python.cpp
    python/src/Interpolation.python.cpp
    python/src/InterpolationQualifier.python.cpp
    python/src/Parity.python.cpp
    python/src/RelationType.python.cpp
    autogen/prototype/proto/python/src/v1.9/containers.python.cpp
    autogen/prototype/proto/python/src/v1.9/containers/Axis.python.cpp
    autogen/prototype/proto/python/src/v1.9/containers/Values.python.cpp
    autogen/prototype/proto/python/src/v1.9/containers/Link.python.cpp
    autogen/prototype/proto/python/src/v1.9/containers/Grid.python.cpp
    autogen/prototype/proto/python/src/v1.9/containers/Axes.python.cpp
    autogen/prototype/proto/python/src/v1.9/containers/XYs1d.python.cpp
    autogen/prototype/proto/python/src/v1.9/containers/Regions1d.python.cpp
    autogen/prototype/proto/python/src/v1.9/transport/CrossSection.python.cpp
    autogen/prototype/proto/python/src/v1.9/transport/Reaction.python.cpp
    autogen/prototype/proto/python/src/v1.9/transport/Reactions.python.cpp
    autogen/prototype/proto/python/src/v1.9/transport/ReactionSuite.python.cpp
    autogen/prototype/proto/python/src/v1.9/transport.python.cpp
    autogen/prototype/proto/python/src/v1.9/proto.python.cpp
    python/src/v2.0/GNDS.python.cpp
    python/src/v2.0/containers.python.cpp
    python/src/v2.0/containers/Array.python.cpp
    python/src/v2.0/containers/Axes.python.cpp
    python/src/v2.0/containers/Axis.python.cpp
    python/src/v2.0/containers/Column.python.cpp
    python/src/v2.0/containers/ColumnHeaders.python.cpp
    python/src/v2.0/containers/Constant1d.python.cpp
    python/src/v2.0/containers/Data.python.cpp
    python/src/v2.0/containers/Double.python.cpp
    python/src/v2.0/containers/Fraction.python.cpp
    python/src/v2.0/containers/Function1ds.python.cpp
    python/src/v2.0/containers/Function2ds.python.cpp
    python/src/v2.0/containers/Function3ds.python.cpp
    python/src/v2.0/containers/Grid.python.cpp
    python/src/v2.0/containers/Gridded1d.python.cpp
    python/src/v2.0/containers/Gridded2d.python.cpp
    python/src/v2.0/containers/Gridded3d.python.cpp
    python/src/v2.0/containers/Integer.python.cpp
    python/src/v2.0/containers/Legendre.python.cpp
    python/src/v2.0/containers/Link.python.cpp
    python/src/v2.0/containers/Polynomial1d.python.cpp
    python/src/v2.0/containers/Regions1d.python.cpp
    python/src/v2.0/containers/Regions2d.python.cpp
    python/src/v2.0/containers/Regions3d.python.cpp
    python/src/v2.0/containers/String.python.cpp
    python/src/v2.0/containers/Table.python.cpp
    python/src/v2.0/containers/Values.python.cpp
    python/src/v2.0/containers/XYs1d.python.cpp
    python/src/v2.0/containers/XYs2d.python.cpp
    python/src/v2.0/containers/XYs3d.python.cpp
    python/src/v2.0/containers/Ys1d.python.cpp
    python/src/v2.0/fissionFragmentData.python.cpp
    python/src/v2.0/fissionFragmentData/DelayedNeutron.python.cpp
    python/src/v2.0/fissionFragmentData/DelayedNeutrons.python.cpp
    python/src/v2.0/fissionFragmentData/FissionFragmentData.python.cpp
    python/src/v2.0/fpy.python.cpp
    python/src/v2.0/fpy/ElapsedTime.python.cpp
    python/src/v2.0/fpy/ElapsedTimes.python.cpp
    python/src/v2.0/fpy/Energy.python.cpp
    python/src/v2.0/fpy/IncidentEnergies.python.cpp
    python/src/v2.0/fpy/IncidentEnergy.python.cpp
    python/src/v2.0/fpy/Nuclides.python.cpp
    python/src/v2.0/fpy/ProductYield.python.cpp
    python/src/v2.0/fpy/ProductYields.python.cpp
    python/src/v2.0/fpy/Time.python.cpp
    python/src/v2.0/fpy/Yields.python.cpp
    python/src/v2.0/fissionFragmentData/Rate.python.cpp
    python/src/v2.0/pops.python.cpp
    python/src/v2.0/pops/Alias.python.cpp
    python/src/v2.0/pops/Aliases.python.cpp
    python/src/v2.0/pops/Atomic.python.cpp
    python/src/v2.0/pops/AverageEnergies.python.cpp
    python/src/v2.0/pops/AverageEnergy.python.cpp
    python/src/v2.0/pops/Baryon.python.cpp
    python/src/v2.0/pops/Baryons.python.cpp
    python/src/v2.0/pops/BindingEnergy.python.cpp
    python/src/v2.0/pops/Charge.python.cpp
    python/src/v2.0/pops/ChemicalElement.python.cpp
    python/src/v2.0/pops/ChemicalElements.python.cpp
    python/src/v2.0/pops/Configuration.python.cpp
    python/src/v2.0/pops/Configurations.python.cpp
    python/src/v2.0/pops/Continuum.python.cpp
    python/src/v2.0/pops/Decay.python.cpp
    python/src/v2.0/pops/DecayData.python.cpp
    python/src/v2.0/pops/DecayMode.python.cpp
    python/src/v2.0/pops/DecayModes.python.cpp
    python/src/v2.0/pops/DecayPath.python.cpp
    python/src/v2.0/pops/Discrete.python.cpp
    python/src/v2.0/pops/Energy.python.cpp
    python/src/v2.0/pops/GaugeBoson.python.cpp
    python/src/v2.0/pops/GaugeBosons.python.cpp
    python/src/v2.0/pops/Halflife.python.cpp
    python/src/v2.0/pops/Intensity.python.cpp
    python/src/v2.0/pops/InternalConversionCoefficients.python.cpp
    python/src/v2.0/pops/InternalPairFormationCoefficient.python.cpp
    python/src/v2.0/pops/Isotope.python.cpp
    python/src/v2.0/pops/Isotopes.python.cpp
    python/src/v2.0/pops/Lepton.python.cpp
    python/src/v2.0/pops/Leptons.python.cpp
    python/src/v2.0/pops/Mass.python.cpp
    python/src/v2.0/pops/MetaStable.python.cpp
    python/src/v2.0/pops/Nucleus.python.cpp
    python/src/v2.0/pops/Nuclide.python.cpp
    python/src/v2.0/pops/Nuclides.python.cpp
    python/src/v2.0/pops/Parity.python.cpp
    python/src/v2.0/pops/PhotonEmissionProbabilities.python.cpp
    python/src/v2.0/pops/PoPs.python.cpp
    python/src/v2.0/pops/Probability.python.cpp
    python/src/v2.0/pops/Product.python.cpp
    python/src/v2.0/pops/Products.python.cpp
    python/src/v2.0/pops/Q.python.cpp
    python/src/v2.0/pops/Shell.python.cpp
    python/src/v2.0/pops/Spectra.python.cpp
    python/src/v2.0/pops/Spectrum.python.cpp
    python/src/v2.0/pops/Spin.python.cpp
    python/src/v2.0/pops/Unorthodox.python.cpp
    python/src/v2.0/pops/Unorthodoxes.python.cpp
    python/src/v2.0/resonances.python.cpp
    python/src/v2.0/resonances/BreitWigner.python.cpp
    python/src/v2.0/resonances/Channel.python.cpp
    python/src/v2.0/resonances/Channels.python.cpp
    python/src/v2.0/resonances/EnergyInterval.python.cpp
    python/src/v2.0/resonances/EnergyIntervals.python.cpp
    python/src/v2.0/resonances/ExternalRMatrix.python.cpp
    python/src/v2.0/resonances/HardSphereRadius.python.cpp
    python/src/v2.0/resonances/J.python.cpp
    python/src/v2.0/resonances/Js.python.cpp
    python/src/v2.0/resonances/L.python.cpp
    python/src/v2.0/resonances/LevelSpacing.python.cpp
    python/src/v2.0/resonances/Ls.python.cpp
    python/src/v2.0/resonances/RMatrix.python.cpp
    python/src/v2.0/resonances/Resolved.python.cpp
    python/src/v2.0/resonances/ResonanceParameters.python.cpp
    python/src/v2.0/resonances/ResonanceReaction.python.cpp
    python/src/v2.0/resonances/ResonanceReactions.python.cpp
    python/src/v2.0/resonances/Resonances.python.cpp
    python/src/v2.0/resonances/ScatteringRadius.python.cpp
    python/src/v2.0/resonances/SpinGroup.python.cpp
    python/src/v2.0/resonances/SpinGroups.python.cpp
    python/src/v2.0/resonances/TabulatedWidths.python.cpp
    python/src/v2.0/resonances/Unresolved.python.cpp
    python/src/v2.0/resonances/Width.python.cpp
    python/src/v2.0/resonances/Widths.python.cpp
    )
target_link_libraries( GNDStk.python PRIVATE GNDStk )
target_compile_options( GNDStk.python PRIVATE "-fvisibility=hidden" )
set_target_properties( GNDStk.python PROPERTIES OUTPUT_NAME GNDStk )
set_target_properties( GNDStk.python PROPERTIES COMPILE_DEFINITIONS "PYBIND11" )
set_target_properties( pugixml-adapter PROPERTIES POSITION_INDEPENDENT_CODE ON)
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
