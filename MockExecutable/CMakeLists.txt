# Properties->C/C++->General->Additional Include Directories
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/Matrix/include")

# Collect sources into the variable MOCKEXECUTABLE_FUNCTION_SOURCES with 
# having to explicitly list each header and source file
file (GLOB MOCKEXECUTABLE_FUNCTION_SOURCES
      "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
      "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# Set Properties->General->Configuration Type to Application(.exe)
# Creates MockExecutable.exe with the listed sources (main.cxx)
# Adds sources to the Solution Explorer
add_executable (MockExecutable ${MOCKEXECUTABLE_FUNCTION_SOURCES})

# Properties->Linker->Input->Additional Dependencies
target_link_libraries (MockExecutable Matrix)

# Creates a folder "executables" and adds target 
# project (MockExecutable.vcproj) under it
set_property(TARGET MockExecutable PROPERTY FOLDER "executables")

# Properties->General->Output Directory
# set_target_properties(MockExecutable PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# Adds logic to INSTALL.vcproj to copy app.exe to destination directory
install (TARGETS MockExecutable
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install)
