#
# App
#

set(SOURCES
    Source/Main.cpp
    Source/AppLayer.h
    Source/AppLayer.cpp
)

add_executable(App)

target_sources(App PRIVATE ${SOURCES})

target_link_libraries(App Core)

target_include_directories(App PRIVATE Source)



