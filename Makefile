RM = rm -f
CSTD = -std=c++14
CFLAGS = -lpthread
ROOT_DIR:=$(shell dirname $(realpath $(MAKEFILE_LIST)))
CURL_FLAGS = -lcurl

INCLUDE_H = $(ROOT_DIR)/include/
INCLUDE_CC = $(ROOT_DIR)/src/
MAIN = $(ROOT_DIR)/test.cpp


all:
	g++ -I $(INCLUDE_H) -I $(INCLUDE_CC) $(MAIN) -v -g $(CSTD) $(CURL_FLAGS) $(CFLAGS) -fpermissive -pthread

run: all
	./a.out
