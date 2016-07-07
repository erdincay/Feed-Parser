cmake_minimum_required (VERSION 2.8.11)

add_library (Feedparser news.h xml2json.hpp jsonxx.h jsonxx.cc curler.cc feed.h feed.cc )

target_link_libraries(Feedparser pthread)
target_link_libraries(Feedparser curl)

#install(TARGETS Feedparser
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION /usr/lib)
#install(FILES "feed.h" DESTINATION /usr/include  )
target_include_directories (Feedparser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
