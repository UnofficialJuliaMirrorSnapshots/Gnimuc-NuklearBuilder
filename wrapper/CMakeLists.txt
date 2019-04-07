cmake_minimum_required(VERSION 3.8.0)
project(nuklear)

add_library(nuklear SHARED helper.c)

target_sources(nuklear PRIVATE helper.h)
target_sources(nuklear PRIVATE nuklear/nuklear.h)

target_include_directories(nuklear PRIVATE nuklear)

install(TARGETS nuklear
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        INCLUDES DESTINATION include)

install(FILES nuklear/nuklear.h DESTINATION include)
install(FILES helper.h DESTINATION include)
