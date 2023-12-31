﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.10)

project (MatrixVectorMultiplication)

option(ENABLE_GTEST ON)

set(ENABLE_GTEST ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

##########################################################################################
# DO NOT MODIFY                                                                         ##
#                                                                                       ##
# Download and unpack googletest at configure time                                      ##
if(ENABLE_GTEST)                                                                        ##
                                                                                        ##
  configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)                  ##
  execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .                    ##
    RESULT_VARIABLE result                                                              ##
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )                 ##
  if(result)                                                                            ##
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")                  ##
  endif()                                                                               ##
  execute_process(COMMAND ${CMAKE_COMMAND} --build .                                    ##
    RESULT_VARIABLE result                                                              ##
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )                 ##
  if(result)                                                                            ##
    message(FATAL_ERROR "Build step for googletest failed: ${result}")                  ##
  endif()                                                                               ##
                                                                                        ##
  # Prevent GoogleTest from overriding our compiler/linker options                      ##
  # when building with Visual Studio                                                    ##
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)                                    ##
                                                                                        ##
  # Add googletest directly to our build. This adds the following targets:              ##
  # gtest, gtest_main, gmock and gmock_main                                             ##
  add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"                                 ##
                   "${CMAKE_BINARY_DIR}/googletest-build"                               ##
                   EXCLUDE_FROM_ALL)                                                    ##
  set_property(TARGET gtest PROPERTY FOLDER "libraries")                                ##
  set_property(TARGET gtest_main PROPERTY FOLDER "libraries")                           ##
                                                                                        ##
  # The gtest/gtest_main targets carry header search path                               ##
  # dependencies automatically when using CMake 2.8.11 or                               ##
  # later. Otherwise we have to add them here ourselves.                                ##
  if (CMAKE_VERSION VERSION_LESS 2.8.11)                                                ##
    include_directories("${gtest_SOURCE_DIR}/include")                                  ##
  endif()                                                                               ##
                                                                                        ##
  include(GoogleTest)                                                                   ##
  include(CTest)                                                                        ##
  enable_testing()                                                                      ##
                                                                                        ##
endif()                                                                                 ##
#                                                                                       ##
#                                                                                       ##
##########################################################################################

# set(CMAKE_CXX_COMPILER /usr/bin/g++)

message ("Using CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message ("Using CMAKE_CC_COMPILER: ${CMAKE_CC_COMPILER}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Detect clang
if(CMAKE_CXX_COMPILER MATCHES ".*clang")
  set(CMAKE_COMPILER_IS_CLANGXX 1)
endif()

# Enable / disable debug code depending upon the build configuration.
set(DEBUG_FLAGS "-DDEBUG=1")
set(RELEASE_FLAGS "-DDEBUG=0")  

if(CMAKE_BUILD_TYPE MATCHES Deb)
  message("debug mode")
  set(DEBUG_FLAGS "${DEBUG_FLAGS} -g")
  if(CMAKE_COMPILER_IS_GNUCXX)
    set(DEBUG_FLAGS "${DEBUG_FLAGS} -rdynamic")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}") 
  endif()
  if(CMAKE_COMPILER_IS_CLANGXX)
    set(DEBUG_FLAGS "${DEBUG_FLAGS} -fshow-source-location ")
    # set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-export_dynamic") 
  endif()
endif()

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/flags.cmake" "")
foreach(FLAGS_TYPE C CXX)
  # Enable debug code when CMAKE_BUILD_TYPE=Debug.
  set(FLAGS_VARIABLE CMAKE_${FLAGS_TYPE}_FLAGS_DEBUG)
  file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/flags.cmake"
       "set(${FLAGS_VARIABLE} \"\${${FLAGS_VARIABLE}} ${DEBUG_FLAGS}\")\n")
       # Disable debug code when CMAKE_BUILD_TYPE is a release config.  
  foreach(BUILD_TYPE_SUFFIX RELEASE RELWITHDEBINFO MINSIZEREL)
    set(FLAGS_VARIABLE CMAKE_${FLAGS_TYPE}_FLAGS_${BUILD_TYPE_SUFFIX})
    file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/flags.cmake"
         "set(${FLAGS_VARIABLE} \"\${${FLAGS_VARIABLE}} ${RELEASE_FLAGS}\")\n")
  endforeach(BUILD_TYPE_SUFFIX)
  # If no build configuration is specified, default to release flags to align
  # with cmake's default build configuration for makefiles.
  if(NOT CMAKE_BUILD_TYPE AND UNIX AND NOT APPLE)
    set(FLAGS_VARIABLE CMAKE_${FLAGS_TYPE}_FLAGS)
    file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/flags.cmake"
         "set(${FLAGS_VARIABLE} \"\${${FLAGS_VARIABLE}} ${RELEASE_FLAGS}\")\n")
  endif(NOT CMAKE_BUILD_TYPE AND UNIX AND NOT APPLE)
endforeach(FLAGS_TYPE)
include("${CMAKE_CURRENT_BINARY_DIR}/flags.cmake")

set(C_FLAGS_WARNINGS "")
if(MSVC)
  set(C_FLAGS_WARNINGS "/W4 /WX")
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
  # Set the maximum warning level for gcc.
  set(C_FLAGS_WARNINGS "-Wall -Werror -Wno-long-long -Wno-variadic-macros")
endif()
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_FLAGS_WARNINGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${C_FLAGS_WARNINGS}")

# Set the warning flags for all targets when using the Xcode generator.
if(CMAKE_COMPILER_IS_CLANGXX)
  foreach(target ${ALL_TARGETS})
    set_target_properties(${target} PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS
                          "${C_FLAGS_WARNINGS}")
  endforeach(target)
endif()

# set VS startup project
if(MSVC)
  set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Test)
endif(MSVC)

add_subdirectory (MockExecutable)
add_subdirectory (Matrix)
add_subdirectory (Test)

# Create a subdirectory for each build configuration when building using
# makefiles.  This makes it possible to keep multiple build artifacts
set(OUTPUT_SUBDIR "")
if(CMAKE_GENERATOR STREQUAL "Unix Makefiles")
  if(CMAKE_BUILD_TYPE STREQUAL "")
    set(OUTPUT_SUBDIR "Release/")
  else()
    set(OUTPUT_SUBDIR "${CMAKE_BUILD_TYPE}/")
  endif()
endif()

if (UNIX)
# Override / reset the output directory for all targets.
set(LIB_OUTPUT_DIR "${OUTPUT_SUBDIR}")
set(EXE_OUTPUT_DIR "${OUTPUT_SUBDIR}")
foreach(target ${ALL_TARGETS})
  set_target_properties(
    ${target} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${LIB_OUTPUT_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${LIB_OUTPUT_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${EXE_OUTPUT_DIR}")
endforeach(target)
endif (UNIX)


# add_test(AllTests ${PROJECT_BINARY_DIR}/bin/Test)