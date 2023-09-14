# Properties->C/C++->General->Additional Include Directories
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/Matrix/include")

# Collect sources into the variable TEST_FUNCTION_SOURCES with 
# having to explicitly list each header and source file
file (GLOB TEST_FUNCTION_SOURCES
      "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
      "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

# Set Properties->General->Configuration Type to Application(.exe)
# Creates Test.exe with the listed sources (main.cxx)
# Adds sources to the Solution Explorer
add_executable (Test ${TEST_FUNCTION_SOURCES})

# Properties->Linker->Input->Additional Dependencies
target_link_libraries(Test Matrix)

if (ENABLE_GTEST)
      find_package(gtest_FOUND QUIET)
      find_package(gtest_main_FOUND QUIET)
      target_link_libraries(Test gtest gtest_main)
endif()

target_include_directories(Test PRIVATE "${PROJECT_SOURCE_DIR}/Matrix/include")

gtest_discover_tests(Test)

# Creates a folder "executables" and adds target 
# project (Test.vcproj) under it
set_property(TARGET Test PROPERTY FOLDER "executables")

# Properties->General->Output Directory
# set_target_properties(Test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# Adds logic to INSTALL.vcproj to copy app.exe to destination directory
install (TARGETS Test
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install)
