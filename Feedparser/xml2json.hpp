#ifndef XML2JSON_HPP_INCLUDED
#define XML2JSON_HPP_INCLUDED


#include <iostream>
#include <map>
#include <string>

#include <Feedparser/rapidxml/rapidxml.hpp>
#include <Feedparser/rapidxml/rapidxml_utils.hpp>
#include <Feedparser/rapidxml/rapidxml_print.hpp>

#include <Feedparser/rapidjson/document.h>
#include <Feedparser/rapidjson/prettywriter.h>
#include <Feedparser/rapidjson/encodedstream.h>
#include <Feedparser/rapidjson/stringbuffer.h>
#include <Feedparser/rapidjson/reader.h>
#include <Feedparser/rapidjson/writer.h>
#include <Feedparser/rapidjson/filereadstream.h>
#include <Feedparser/rapidjson/filewritestream.h>
#include <Feedparser/rapidjson/error/en.h>


void to_array_form(const char, rapidjson::Value, rapidjson::Value, rapidjson::Document::AllocatorType&);
void add_attributes(rapidxml::xml_node<>, rapidjson::Value, rapidjson::Document::AllocatorType&);
void traverse_node(rapidxml::xml_node<>, rapidjson::Value, rapidjson::Document::AllocatorType&);
std::string xml2json(const char*);


#endif
