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
add_subdirectory( src/GNDStk/Component/test )
add_subdirectory( src/GNDStk/BodyText/test )
add_subdirectory( src/GNDStk/precision/test )

add_subdirectory( src/GNDStk/enums/Parity/test )
add_subdirectory( src/GNDStk/enums/Frame/test )
add_subdirectory( src/GNDStk/enums/Interpolation/test )
add_subdirectory( src/GNDStk/enums/InterpolationQualifier/test )
add_subdirectory( src/GNDStk/enums/HashAlgorithm/test )

add_subdirectory( src/GNDStk/enums/Encoding/test )
add_subdirectory( src/GNDStk/enums/GridStyle/test )
add_subdirectory( src/GNDStk/enums/Interaction/test )
add_subdirectory( src/GNDStk/enums/StorageOrder/test )
add_subdirectory( src/GNDStk/enums/units/Energy/test )
add_subdirectory( src/GNDStk/enums/units/Length/test )

add_subdirectory( src/GNDStk/v1.9/containers/Values/test )
add_subdirectory( src/GNDStk/v1.9/containers/Axis/test )
add_subdirectory( src/GNDStk/v1.9/containers/Link/test )
add_subdirectory( src/GNDStk/v1.9/containers/Grid/test )
add_subdirectory( src/GNDStk/v1.9/containers/Axes/test )
add_subdirectory( src/GNDStk/v1.9/containers/XYs1d/test )
add_subdirectory( src/GNDStk/v1.9/containers/Regions1d/test )
