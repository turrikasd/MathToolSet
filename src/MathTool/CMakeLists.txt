file(GLOB mathtool_HEADERS "*.h")
file(GLOB mathtool_SOURCES "*.cpp")

add_executable(MathTool ${mathtool_SOURCES} ${mathtool_HEADERS})
target_link_libraries (MathTool ASMMath)
target_link_libraries (MathTool CPPMath)