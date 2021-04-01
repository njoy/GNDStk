#######################################################################
# Setup
#######################################################################

message( STATUS "Adding GNDStk unit testing" )
enable_testing()


#######################################################################
# Unit testing directories
#######################################################################

add_subdirectory( src/GNDStk/test )
add_subdirectory( src/GNDStk/Defaulted/test )
add_subdirectory( src/GNDStk/Tree/test )
add_subdirectory( src/GNDStk/type2string/test )
add_subdirectory( src/GNDStk/node2type/test )
add_subdirectory( src/GNDStk/type2node/test )
add_subdirectory( src/GNDStk/string2type/test )
add_subdirectory( src/GNDStk/Meta/test )
add_subdirectory( src/GNDStk/XML/test )
add_subdirectory( src/GNDStk/JSON/test )
add_subdirectory( src/GNDStk/Node/test )
add_subdirectory( src/GNDStk/keyword/test )
add_subdirectory( src/GNDStk/Child/test )
add_subdirectory( src/GNDStk/convert/test )
add_subdirectory( src/GNDStk/utility/test )

add_subdirectory( src/GNDStk/enums/GridStyle/test )
add_subdirectory( src/GNDStk/enums/Interpolation/test )
add_subdirectory( src/GNDStk/enums/units/Energy/test )
add_subdirectory( src/GNDStk/enums/units/Length/test )

add_subdirectory( src/GNDStk/v1.9/gpdc/Axis/test )
add_subdirectory( src/GNDStk/v1.9/gpdc/Axes/test )
