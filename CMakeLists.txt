cmake_minimum_required(VERSION 3.0)

project(zmij-json VERSION 0.1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)
add_compile_options("-Wall" "-Wextra" "-Wpedantic" "-Werror")

option(USE_CCACHE "Use ccache for build" ON)
if (USE_CCACHE)
    find_program(CCACHE ccache)
    if (CCACHE)
        message(STATUS "ccache found and enabled")
        set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE})
        set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})
    else()
        message(WARNING "ccache enabled, but not found")
    endif()
else()
    message(STATUS "ccache disabled")
endif()

# pretty file name for logging
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFILENAME='\"$(subst ${CMAKE_SOURCE_DIR}/,,$(abspath $<))\"'")

option(JSON_BUILD_TESTS ON)
option(JSON_BUILD_BENCHMARK ON)

set(
    BOOST_COMPONENTS
    system
)

find_package(Boost 1.66 COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
#find_package(ExternalProjectGTest)
#find_package(ExternalProjectGBench)
find_package(ExternalProjectZmijModules)
find_package(ExternalProjectMetapushkin)
find_package(ExternalProjectAFSM)
message(STATUS "AFSM include dirs ${AFSM_INCLUDE_DIRS}")
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
include_directories(${AFSM_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src/zmij/json)

if(JSON_BUILD_TESTS)
    message(STATUS "Building JSON tests")
    enable_testing()
    add_subdirectory(test)
else()
    message(STATUS "Not building JSON tests")
endif()
