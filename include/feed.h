#include "jsonxx.cc"
#include "jsonxx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "news.h"
#include "curler.cc"
#include <gtkmm.h>
#include <thread>
#include <stdio.h>
using namespace std;
using namespace jsonxx;

class feed{

	Object json;
	string url,title,link,desc,date,logo;
	Array items;
	news News;
	Object *item;

	public:

		feed(string url);

		void create(string url){
			this->url = url;
		}
		feed(){}
		string get_topic(){
			return title;
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

		Glib::RefPtr<Gdk::Pixbuf> get_item_img(int index){
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
