cmake_minimum_required (VERSION 2.6)
project (MathToolSet)

# Set the current version number to be defined in the config header
set (MathToolSet_VERSION_MAJOR 1)
set (MathToolSet_VERSION_MINOR 0)

# Configured Header File
configure_file ("${PROJECT_SOURCE_DIR}/Config.h.in"
				"${PROJECT_BINARY_DIR}/Config.h")

# Add the binary tree to the search path for include files
include_directories("${PROJECT_BINARY_DIR}")

# Add the projects' include directories to search path for includes
include_directories("${PROJECT_SOURCE_DIR}/src/MathTool")
include_directories("${PROJECT_SOURCE_DIR}/src/ASMMath")
include_directories("${PROJECT_SOURCE_DIR}/src/CPPMath")

# Add the source directories and their CMakeLists.txt
add_subdirectory (src/MathTool)
add_subdirectory (src/ASMMath)
add_subdirectory (src/CPPMath)