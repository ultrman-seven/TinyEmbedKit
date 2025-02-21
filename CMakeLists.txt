cmake_minimum_required(VERSION 3.20)

project(tek)
add_library(tek INTERFACE)

enable_language(C)

target_compile_definitions(tek INTERFACE
)

target_include_directories(tek INTERFACE
    # ./adt
    # ./filter
    # ./controller
    )

    target_sources(tek INTERFACE
    ./adt/*.c
    ./filter/*.c
    ./controller/*.c
)

target_link_directories(tek INTERFACE
)

target_link_libraries(tek INTERFACE
)
