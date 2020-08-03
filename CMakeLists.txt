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

add_library( GNDStk INTERFACE )
target_include_directories( GNDStk INTERFACE src/ )
target_link_libraries( GNDStk
    INTERFACE Log
    INTERFACE catch-adapter
    INTERFACE pugi-adapter
    INTERFACE json-adapter
    )


#######################################################################
# Top-level Only
#######################################################################

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR )

    # unit testing
    if( GNDStk_unit_tests )
        include( cmake/unit_testing.cmake )
    endif()

endif()
