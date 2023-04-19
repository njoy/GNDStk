
add_executable(
   GNDStk.Defaulted.test
   assign.test.cpp
   ctor.test.cpp
   Defaulted.test.cpp
   get.test.cpp
   has.test.cpp
   reset.test.cpp
   value.test.cpp
)

target_compile_options( GNDStk.Defaulted.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${GNDStk_appended_flags} )
target_link_libraries( GNDStk.Defaulted.test PUBLIC GNDStk )
add_test( NAME GNDStk.Defaulted COMMAND GNDStk.Defaulted.test )