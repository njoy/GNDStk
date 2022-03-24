
add_executable( GNDStk.BlockData.test
                BlockData.test.cpp
                assign.test.cpp
                convert.test.cpp
                detail.test.cpp
                fromNode.test.cpp
                get.test.cpp
                params.test.cpp
                string.test.cpp
                sync.test.cpp
                toNode.test.cpp
                types.test.cpp
                write.test.cpp )
target_compile_options( GNDStk.BlockData.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${GNDStk_appended_flags} )
target_link_libraries( GNDStk.BlockData.test PUBLIC GNDStk )
add_test( NAME GNDStk.BlockData COMMAND GNDStk.BlockData.test )
