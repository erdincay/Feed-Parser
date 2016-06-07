#include "jsonxx.cc"
#include "jsonxx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "news.h"
#include "curler.cc"
#include <thread>
#include <stdio.h>
using namespace std;
using namespace jsonxx;

class feed{

	map <string,string> info;
	std::map<int, Object> items;
	string url;
	news News;
	Object *item;
	void strip_items();
	public:
		Object json;

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

#include<feed.cc>
