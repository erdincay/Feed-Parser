#ifndef FEED_H_
#define FEED_H_

#include <Feedparser/news.h>
#include <Feedparser/jsonxx.h>
#include <Feedparser/curler.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <thread>
#include <stdio.h>
#include <unistd.h>
#include <map>
#include <future>

using namespace jsonxx;


class feed{

	Object json;
	Object *item;
	map <string,string> info;
	map<int, Object> items;
	string url;
	news News;

	void strip_items();

	public:
		feed(string url);

		void create(string url){
			this->url = url;
		}
		
		feed(){}

		string get_topic(){
			return info["title"];
		}

		bool fetch();
		bool fetch_data();
		bool parse();

		string get_url(){
			return url;
		}
		string get_item_title(int index){
			return News.title[index];
		}

		string get_item_img(int index){
			return News.image[index];
		}

		string get_item_link(int index){
			return News.link[index];
		}

		int get_total(){
			return News.num_item;
		}

		struct news get_news(){
			return News;
		}

};
#endif
