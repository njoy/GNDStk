
add_executable( GNDStk.tree.test
                assign.test.cpp
                root.test.cpp
                ctor.test.cpp
                child.test.cpp
                tree.test.cpp
                read.test.cpp
                meta.test.cpp
                write.test.cpp
                parens.test.cpp
                normalize.test.cpp
                clear.test.cpp
                empty.test.cpp )
target_compile_options( GNDStk.tree.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${GNDStk_appended_flags} )
target_link_libraries( GNDStk.tree.test PUBLIC GNDStk ) 
file( GLOB resources "resources/*" )
foreach( resource ${resources})
    file( COPY "${resource}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}" )
endforeach()
add_test( NAME GNDStk.tree COMMAND GNDStk.tree.test )