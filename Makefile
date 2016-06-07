RM = rm -f
CSTD = -std=c++14
CFLAGS = -lpthread
ROOT_DIR:=$(shell dirname $(realpath $(MAKEFILE_LIST)))
CURL_FLAGS = -lcurl
INCLUDE += -I./include/
OPTIONS  = -std=c++11 -O3 -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--strip-all -fpermissive
WARNINGS = -Wall -Wextra -Werror

INCLUDE_H = $(ROOT_DIR)/include/
INCLUDE_CC = $(ROOT_DIR)/src/
MAIN = $(ROOT_DIR)/test.cpp


all:
	g++ -I $(INCLUDE_H) -I $(INCLUDE_CC) $(MAIN) -g $(CSTD) $(CURL_FLAGS) $(CFLAGS) -fpermissive


json.o:
	g++ $(INCLUDE_H) -c $(INCLUDE_CC)jsonxx.cc -o $(INCLUDE_CC)json.o

curler.o:
	g++ -c -I $(INCLUDE_H) $(INCLUDE_CC)curler.cc -o $(INCLUDE_CC)curler.o

xml2json.o:
		g++ -c $(INCLUDE_H)xml2json.hpp -o $(INCLUDE_CC)xml2json.o
run: all
	./a.out

clean:
	$(RM) FeedReader
	$(RM) -r res
	python fetch.py
