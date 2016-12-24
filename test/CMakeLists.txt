enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB ALL_TESTS_SRC *.cpp)
add_executable(truco-tests ${ALL_TESTS_SRC})

add_test(truco-tests truco-tests)
