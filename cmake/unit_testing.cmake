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
add_subdirectory( src/GNDStk/meta/test )
add_subdirectory( src/GNDStk/XML/test )
add_subdirectory( src/GNDStk/JSON/test )
add_subdirectory( src/GNDStk/Node/test )
add_subdirectory( src/GNDStk/keyword/test )
add_subdirectory( src/GNDStk/child/test )
add_subdirectory( src/GNDStk/convert/test )
add_subdirectory( src/GNDStk/utility/test )
