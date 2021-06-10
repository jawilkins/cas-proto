cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

function(add_example NAME)
    project(${LIBRARY}-${NAME}
        DESCRIPTION "Example Program for a Computer Algebra System Prototype in C++ (${NAME})"
        VERSION ${CAS_PROTO_VERSION}
        LANGUAGES CXX
        HOMEPAGE_URL "https://github.com/jawilkins/cas-proto/tree/master/examples"
    )

    add_executable         (        ${PROJECT_NAME} ${NAME}.cpp)
    target_link_libraries  (        ${PROJECT_NAME} ${LIBRARY})
    install                (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${LIBRARY_TYPE}/\${BUILD_TYPE}/bin)
endfunction()

list(APPEND EXAMPLES
    quadratic-formula
    cubic-formula
)

foreach(EX ${EXAMPLES})
    add_example(${EX})
endforeach()
