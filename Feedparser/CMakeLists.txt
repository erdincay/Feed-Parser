cmake_minimum_required (VERSION 2.8.11)

set(SRC
    xml2json.cc
    curler.cc
    jsonxx.cc
    feed.cc
)
set(CMAKE_CXX_FLAGS -fpermissive)
include_directories(BEFORE ${Feedparser_BINARY_DIR})

include_directories(BEFORE ${Feedparser_SOURCE_DIR})

add_library(Feedparser ${SRC})

target_link_libraries(Feedparser pthread)
target_link_libraries(Feedparser curl)

install(TARGETS Feedparser
        ARCHIVE DESTINATION /usr/lib )
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION include/Feedparser
        FILES_MATCHING PATTERN "*.h*" PATTERN "CMake*" EXCLUDE)
target_include_directories (Feedparser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
