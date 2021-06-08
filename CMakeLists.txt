cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(CAS_PROTO_VERSION 0.1)

project(cas-proto
    DESCRIPTION "Computer Algebra System Prototype in C++"
    VERSION ${CAS_PROTO_VERSION}
    LANGUAGES CXX
    HOMEPAGE_URL "https://github.com/jawilkins/cas-proto"
)

set(LIBRARY ${LIBRARY_PREFIX}${PROJECT_NAME})

list(APPEND HEADERS
    include/${PROJECT_NAME}/api.h
    include/${PROJECT_NAME}/BinaryOperator.h
    include/${PROJECT_NAME}/Blank.h
    include/${PROJECT_NAME}/Constant.h
    include/${PROJECT_NAME}/ConstantDefinition.h
    include/${PROJECT_NAME}/ConstantExpression.h
    include/${PROJECT_NAME}/ConstantSymbol.h
    include/${PROJECT_NAME}/Definition.h
    include/${PROJECT_NAME}/Difference.h
    include/${PROJECT_NAME}/DifferenceDefinition.h
    include/${PROJECT_NAME}/Equation.h
    include/${PROJECT_NAME}/Exponent.h
    include/${PROJECT_NAME}/ExponentDefinition.h
    include/${PROJECT_NAME}/Expression.h
    include/${PROJECT_NAME}/ExpressionBase.h
    include/${PROJECT_NAME}/ExpressionVisitor.h
    include/${PROJECT_NAME}/Formula.h
    include/${PROJECT_NAME}/Function.h
    include/${PROJECT_NAME}/FunctionDefinition.h
    include/${PROJECT_NAME}/FunctionSymbol.h
    include/${PROJECT_NAME}/ImaginaryDefinition.h
    include/${PROJECT_NAME}/Natural.h
    include/${PROJECT_NAME}/NcBinaryOperator.h
    include/${PROJECT_NAME}/Negate.h
    include/${PROJECT_NAME}/NegateDefinition.h
    include/${PROJECT_NAME}/Object.h
    include/${PROJECT_NAME}/OneDefinition.h
    include/${PROJECT_NAME}/Pi.h
    include/${PROJECT_NAME}/Product.h
    include/${PROJECT_NAME}/ProductDefinition.h
    include/${PROJECT_NAME}/Quotient.h
    include/${PROJECT_NAME}/QuotientDefinition.h
    include/${PROJECT_NAME}/Rational.h
    include/${PROJECT_NAME}/Ref.h
    include/${PROJECT_NAME}/SquareRoot.h
    include/${PROJECT_NAME}/SquareRootDefinition.h
    include/${PROJECT_NAME}/Stat.h
    include/${PROJECT_NAME}/Sum.h
    include/${PROJECT_NAME}/SumDefinition.h
    include/${PROJECT_NAME}/Symbol.h
    include/${PROJECT_NAME}/SymbolBase.h
    include/${PROJECT_NAME}/TwoDefinition.h
    include/${PROJECT_NAME}/UnaryOperator.h
    include/${PROJECT_NAME}/Variable.h
    include/${PROJECT_NAME}/VariableDefinition.h
    include/${PROJECT_NAME}/VariableSymbol.h
    include/${PROJECT_NAME}/ZeroDefinition.h
    include/${PROJECT_NAME}/precedence.h

    include/${PROJECT_NAME}/Expression.hpp
    include/${PROJECT_NAME}/Symbol.hpp
)

list(APPEND SOURCES
    src/BinaryOperator.cpp
    src/Blank.cpp
    src/Constant.cpp
    src/ConstantDefinition.cpp
    src/ConstantSymbol.cpp
    src/Definition.cpp
    src/Difference.cpp
    src/DifferenceDefinition.cpp
    src/Exponent.cpp
    src/ExponentDefinition.cpp
    src/ExpressionBase.cpp
    src/Function.cpp
    src/FunctionDefinition.cpp
    src/FunctionSymbol.cpp
    src/ImaginaryDefinition.cpp
    src/Natural.cpp
    src/NcBinaryOperator.cpp
    src/Negate.cpp
    src/NegateDefinition.cpp
    src/Object.cpp
    src/OneDefinition.cpp
    src/Product.cpp
    src/ProductDefinition.cpp
    src/QuadraticEquation.cpp
    src/QubicFormula.cpp
    src/Quotient.cpp
    src/QuotientDefinition.cpp
    src/Rational.cpp
    src/SquareRoot.cpp
    src/SquareRootDefinition.cpp
    src/Stat.cpp
    src/Sum.cpp
    src/SumDefinition.cpp
    src/SymbolBase.cpp
    src/TwoDefinition.cpp
    src/UnaryOperator.cpp
    src/Variable.cpp
    src/VariableDefinition.cpp
    src/VariableSymbol.cpp
    src/ZeroDefinition.cpp
)

add_library(${LIBRARY} ${HEADERS} ${SOURCES})

set_target_properties(${LIBRARY} PROPERTIES PUBLIC_HEADER "${HEADERS}")
set_target_properties(${LIBRARY} PROPERTIES DEBUG_POSTFIX d)

target_include_directories(${LIBRARY} PUBLIC
    $<INSTALL_INTERFACE:\${BUILD_TYPE}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_definitions(${LIBRARY} PUBLIC -DWITH_CAS_PROTO)

if (BUILD_SHARED_LIBS)
    set(LIBRARY_TYPE Shared)
    target_compile_definitions(${LIBRARY} PRIVATE -DCAS_PROTO_BUILD_DLL)
else()
    set(LIBRARY_TYPE Static)
endif()

install(TARGETS ${LIBRARY}
    ARCHIVE       DESTINATION ${LIBRARY_TYPE}/\${BUILD_TYPE}/lib
    RUNTIME       DESTINATION ${LIBRARY_TYPE}/\${BUILD_TYPE}/bin
    LIBRARY       DESTINATION ${LIBRARY_TYPE}/\${BUILD_TYPE}/lib
    PUBLIC_HEADER DESTINATION ${LIBRARY_TYPE}/\${BUILD_TYPE}/include/${PROJECT_NAME}
)




list(APPEND DEPENDENCIES ${LIBRARY})

add_subdirectory(examples)
