#
# Core
#


set(SOURCES 
Source/Core/Application.h
Source/Core/Application.cpp
Source/Core/Window.h
Source/Core/Window.cpp
Source/Core/Layer.h

)


# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

add_library(Core STATIC)

target_sources(Core PRIVATE ${SOURCES})


# Link to the actual SDL3 library.
target_link_libraries(Core PRIVATE SDL3::SDL3)

target_include_directories(Core PUBLIC "Source" "vendored/SDL")
