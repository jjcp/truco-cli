enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(truco-tests main.cpp
                           test_envido.cpp
                           test_naipe.cpp)

add_test(truco-tests truco-tests)
