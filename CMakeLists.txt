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

include_directories( python/src/ )

pybind11_add_module( GNDStk.python
    EXCLUDE_FROM_ALL
    python/src/GNDStk.python.cpp
    python/src/core/Node.python.cpp
    python/src/v1.9/containers.python.cpp
    python/src/v1.9/containers/Axis.python.cpp
    python/src/v1.9/transport.python.cpp
    python/src/v1.9/GNDS.python.cpp
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
