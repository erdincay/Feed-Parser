#ifndef CURLER_H_
#define CURLER_H_

#include <curl/curl.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Feedparser/xml2json.hpp>
#include <utility>
#include <string>

using namespace std;

//I didn't haves to create a class for this right now

CURLcode curl_read(const std::string&, std::ostream&, long);

bool download(string, string);

std::pair<string,int> download_file(string, int);

string download(string url);

#endif
