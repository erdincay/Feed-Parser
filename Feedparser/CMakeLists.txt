cmake_minimum_required (VERSION 2.8.11)

set(HEADERS
    news.h rapidxml/rapidxml.hpp  rapidxml/rapidxml_iterators.hpp  rapidxml/rapidxml_print.hpp
    rapidxml/rapidxml_utils.hpp feed.h rapidjson/allocators.h  rapidjson/encodedstream.h
    rapidjson/error/en.h rapidjson/error/error.h rapidjson/filewritestream.h rapidjson/memorybuffer.h
    rapidjson/msinttypes/inttypes.h  rapidjson/msinttypes/stdint.h
    rapidjson/prettywriter.h rapidjson/reader.h rapidjson/writer.h
    rapidjson/document.h rapidjson/encodings.h rapidjson/filereadstream.h rapidjson/internal/biginteger.h
    rapidjson/internal/diyfp.h  rapidjson/internal/dtoa.h  rapidjson/internal/ieee754.h
    rapidjson/internal/itoa.h  rapidjson/internal/meta.h  rapidjson/internal/pow10.h
    rapidjson/internal/stack.h  rapidjson/internal/strfunc.h  rapidjson/internal/strtod.h
    rapidjson/internal/swap.h memorystream.h pointer.h rapidjson.h  stringbuffer.h jsonxx.h feed.h xml2json.hpp
)

set(SRC
    jsonxx.cc
    curler.cc
    feed.cc
)
include_directories(BEFORE ${Feedparser_BINARY_DIR})

include_directories(BEFORE ${Feedparser_SOURCE_DIR})

add_library(Feedparser ${SRC})

target_link_libraries(Feedparser pthread)
target_link_libraries(Feedparser curl)

include(GenerateExportHeader)
generate_export_header(Feedparser)
set_target_properties(Feedparser PROPERTIES COMPILE_DEFINITIONS "Feedparser_EXPORTS")

install(TARGETS Feedparser EXPORT FeedparserTargets
        ARCHIVE DESTINATION lib
        CONFIGURATIONS Debug)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION include/Feedparser
        FILES_MATCHING PATTERN "*.h" PATTERN "CMake*" EXCLUDE)
target_include_directories (Feedparser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
