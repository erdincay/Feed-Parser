#include<utils.cc>
#include <unistd.h>
#include <map>
#include <future>
/*#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
*/

bool feed::fetch(){

		json.parse(download(url));

		if(json.has<Object>("rss"))
			return true;
		else
			return false;
return false;

}

feed::feed(string url){
		this->url = url;
}
void feed::strip_items(){

	News.num_item = 1;
	for (;News.num_item<items.size();News.num_item++){

			Object item = items[News.num_item-1];

			this->News.title[News.num_item] = item.get<String>("title");
			this->News.img_path[News.num_item] = item.get<Object>("thumbnail").get<String>("@url");
			cout<<"\n"<<item.get<Object>("thumbnail").get<String>("@url")<<"\n";
			this->News.link[News.num_item] = item.get<String>("link");

		}

		cout<<sizeof(this->News);
		this->fetch_data();
}

bool feed::parse(){
				int i = 0;
				auto x = json.get<Object>("rss").get<Object>("channel").get_c();
				for (auto it:x) {

					if(it.first == "title")info["title"]=(*it.second).get<String>();
					if(it.first == "link")info["link"]=(*it.second).get<String>();
					if(it.first == "description")info["description"]=(*it.second).get<String>();
					if(it.first == "language")info["language"]=(*it.second).get<String>();
					if(it.first == "pubDate")info["pubDate"]=(*it.second).get<String>();
					if(it.first == "copyright")info["copyright"]=(*it.second).get<String>();
					if(it.first == "image")info["logo"]=(*it.second).get<Object>().get<String>("url");
					if(it.first == "item"){
							auto u = (*it.second).get<Array>();
							while(i<u.size()){
									items[i]=u.get<Object>(i);
									++i;
						}
					}
					}
					this->strip_items();

				std::cout<<"Done";
return true;
}

bool feed::fetch_data(){
	int i;
	cout<<sizeof(this->News);
	std::vector<std::future<string>> downloads;
	for(i=0;i<News.num_item;i++){
		downloads.push_back(std::async(std::launch::async,download_file,this->News.img_path[i]));
		//	std::cout<<this->News.img_path[i]<<endl;
		//	News.Image[i] = download_file(this->News.img_path[i]).c_str();
		}
		for(auto &e : downloads) {
   std::cout << e.get() << std::endl;
  }

 	}
