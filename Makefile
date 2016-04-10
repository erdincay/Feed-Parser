RM = rm -f
CSTD = -std=c++14
CFLAGS = -lpthread
ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CURL_FLAGS = -lcurl
INCLUDE += -I./include/
OPTIONS  = -std=c++11 -O3 -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--strip-all
WARNINGS = -Wall -Wextra -Werror

INCLUDE_H = -I $(ROOT_DIR)/include/
INCLUDE_CC = -I $(ROOT_DIR)/src/
MAIN = $(ROOT_DIR)/src/main.cc


all:
	g++ $(INCLUDE_H) $(INCLUDE_CC) $(MAIN) -o FeedReader -g $(CSTD) $(GTKMM_FLAGS) $(WEBKIT_FLAGS) $(CURL_FLAGS) $(CFLAGS)

run:
	./FeedReader

clean:
	$(RM) FeedReader
	$(RM) -r res
	python fetch.py
