
add_executable( GNDStk.Node.test
                add.test.cpp
                clear.test.cpp
                child.test.cpp
                sort.test.cpp
                copy.test.cpp
                meta.test.cpp
                all.test.cpp
                empty.test.cpp
                one.test.cpp
                call.test.cpp
                ctor.test.cpp
                Node.test.cpp
                write.test.cpp )
target_compile_options( GNDStk.Node.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${GNDStk_appended_flags} )
target_link_libraries( GNDStk.Node.test PUBLIC GNDStk ) 
file( GLOB resources "resources/*" )
foreach( resource ${resources})
    file( COPY "${resource}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}" )
endforeach()
add_test( NAME GNDStk.Node COMMAND GNDStk.Node.test )