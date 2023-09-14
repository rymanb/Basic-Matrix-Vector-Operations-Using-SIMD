# Properties->C/C++->General->Additional Include Directories
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/include")


# Collect sources into the variable MATRIX_FUNCTION_SOURCES with 
# having to explicitly list each header and source file
file (GLOB MATRIX_FUNCTION_SOURCES
      "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
      "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
      "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

# Set Properties->General->Configuration Type to Dynamic Library(.dll)
# Creates math.dll with the listed sources collected in the variables
# Also adds sources to the Solution Explorer
add_library(Matrix STATIC ${MATRIX_FUNCTION_SOURCES})

# Creates a folder "libraries" and adds target project (math.vcproj) under it
set_property(TARGET Matrix PROPERTY FOLDER "libraries")

# Properties->General->Output Directory
# set_target_properties(Matrix PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# Adds logic to INSTALL.vcproj to copy math.lib to the destination directory
# install (TARGETS Matrix
#         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
#         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install)
