file(GLOB asmmath_HEADERS "*.h")
file(GLOB asmmath_SOURCES "*.cpp")

add_library(ASMMath ${asmmath_SOURCES} ${asmmath_HEADERS})