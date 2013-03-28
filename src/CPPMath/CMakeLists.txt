file(GLOB cppmath_HEADERS "*.h")
file(GLOB cppmath_SOURCES "*.cpp")

add_library(CPPMath ${cppmath_SOURCES} ${cppmath_HEADERS})