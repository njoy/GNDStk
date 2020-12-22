#######################################################################
# Setup
#######################################################################

message( STATUS "Adding GNDStk unit testing" )
enable_testing()


#######################################################################
# Unit testing directories
#######################################################################

add_subdirectory( src/GNDStk/test )
add_subdirectory( src/GNDStk/Tree/test )
add_subdirectory( src/GNDStk/type2string/test )
add_subdirectory( src/GNDStk/node2type/test )
add_subdirectory( src/GNDStk/type2node/test )
add_subdirectory( src/GNDStk/string2type/test )
add_subdirectory( src/GNDStk/meta_t/test )
add_subdirectory( src/GNDStk/XML/test )
add_subdirectory( src/GNDStk/JSON/test )
add_subdirectory( src/GNDStk/Node/test )
add_subdirectory( src/GNDStk/keyword/test )
add_subdirectory( src/GNDStk/child_t/test )
add_subdirectory( src/GNDStk/convert/test )
add_subdirectory( src/GNDStk/utility/test )

add_subdirectory( src/GNDStk/enums/units/Energy/test )
add_subdirectory( src/GNDStk/enums/units/Length/test )

add_subdirectory( src/GNDStk/v1.9/Values/test )
add_subdirectory( src/GNDStk/v1.9/Axis/test )
add_subdirectory( src/GNDStk/v1.9/Axes/test )

add_subdirectory( src/GNDStk/v1.9/Constant1D/test )

add_subdirectory( src/GNDStk/v1.9/ConstantRadius/test )
