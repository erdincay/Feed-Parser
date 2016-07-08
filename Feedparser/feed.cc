
#include <Feedparser/feed.h>

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
			this->News.link[News.num_item] = item.get<String>("link");
			if(item.has<Object>("thumbnail"))
			this->News.img_path[News.num_item] = item.get<Object>("thumbnail").get<String>("@url");
			else if(item.has<Object>("content"))
			this->News.img_path[News.num_item] = item.get<Object>("content").get<Object>("thumbnail").get<String>("@url");

	}


}

bool feed::parse(){
		int i = 0;
		auto x = json.get<Object>("rss").get<Object>("channel").get_c();
		for (auto it:x) {
			if(it.first == "title")info["title"]=(*it.second).get<String>();
			if(it.first == "link"){

				if((*it.second).is<Array>())
				info["link"]=(*it.second).get<Array>().get<Object>(1).get<String>("@href");
				else
				info["link"]=(*it.second).get<String>();

			}
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
					this->strip_items();
					return true;

			}
		}

		return true;
}

bool feed::fetch_data(){
	int i;

	std::vector< std::future< std::pair<string,int> >> downloads;

	for(i=0;i<News.num_item;++i){
		downloads.push_back(std::async(std::launch::async,download_file,this->News.img_path[i],i));
	}

	for(auto &e : downloads) {
		std::pair<string,int> r = e.get();
  	this->News.image[r.second] = r.first;
	}

}
