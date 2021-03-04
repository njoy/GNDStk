include( FetchContent )


########################################################################
# Forward declarations
########################################################################


########################################################################
# Declare project dependencies
########################################################################

FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  http://github.com/njoy/catch-adapter
    GIT_TAG         origin/master
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( Log
    GIT_REPOSITORY  http://github.com/njoy/Log
    GIT_TAG         origin/build/fetchcontent
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( pugixml-adapter
    GIT_REPOSITORY  http://github.com/njoy/pugixml-adapter
    GIT_TAG         origin/master
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.7.3
    GIT_SHALLOW true
    )

FetchContent_GetProperties(json)
set(JSON_BuildTests OFF CACHE INTERNAL "")
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_Declare( pybind11
    GIT_REPOSITORY  https://github.com/pybind/pybind11
    GIT_TAG         v2.6.1
    GIT_SHALLOW     TRUE
    )


########################################################################
# Load dependencies
########################################################################

FetchContent_MakeAvailable(
    catch-adapter
    Log
    pugixml-adapter
    json
    pybind11
    )
