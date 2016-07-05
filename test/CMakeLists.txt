cmake_minimum_required (VERSION 2.8.11)

add_executable(Feedtest test.cc)

target_link_libraries (Feedtest LINK_PUBLIC Feedparser)
