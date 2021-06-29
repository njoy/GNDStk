
add_executable( GNDStk.Component.test
                Component.test.cpp
                ctor.test.cpp
                detail.test.cpp
                finish.test.cpp
                fromNode.test.cpp
                getter.test.cpp
                toNode.test.cpp
                write.test.cpp )
target_compile_options( GNDStk.Component.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${GNDStk_appended_flags} )
target_link_libraries( GNDStk.Component.test PUBLIC GNDStk )
add_test( NAME GNDStk.Component COMMAND GNDStk.Component.test )
