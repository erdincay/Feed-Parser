#include<utils.cc>
#include <unistd.h>
#include <map>
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
void feed::stripmaps(std::map<string, string> map,std::map<int, Object> maps);
bool feed::parse(){
				map <string,string> is;
				std::map<int, Object> itemss;
				title = json.get<Object>("rss").get<Object>("channel").get<String>("title");
				desc = json.get<Object>("rss").get<Object>("channel").get<String>("description");
				items = json.get<Object>("rss").get<Object>("channel").get<Array>("item");
				auto x = json.get<Object>("rss").get<Object>("channel").get_c();
				for (auto it:x) {

					cout << it.first << " " << *it.second<<"\n\n\n";
					switch (it.first) {
						case "title":
								is["title"]=(*it.second).get<String>();
								break;
						case "link":
								is["link"]=(*it.second).get<String>();
								break;
						case "description":
								is["description"]=(*it.second).get<String>();
								break;
						case "language":
								is["language"]=(*it.second).get<String>();
								break;
						case "pubDate":
								is["pubDate"]=(*it.second).get<String>();
								break;
						case "copyright":
								is["copyright"]=(*it.second).get<String>();
								break;
						case "image":
								is["logo"]=(*it.second).get<Object>().get<String>("url");
								break;
					}

					}
					if(it.first == "title")is["title"]=(*it.second).get<String>();
					if(it.first == "link")is["link"]=(*it.second).get<String>();

					//if(it.first == "item")itemss[0]=(*it.second).get<Array>().get<Object>(1);
				}
				cout<<itemss[0];
				for (;News.num_item<items.size();News.num_item++){

					item = new Object(items.get<Object>(News.num_item));


						this->News.title[News.num_item] = item->get<String>("title");
						if(item->has<Object>("thumbnail"))
						this->News.img_path[News.num_item] = item->get<Object>("thumbnail").get<String>("@url");
						this->News.link[News.num_item] = item->get<String>("link");

					}
		std::cout<<"Done";
return true;
}

bool feed::fetch_data(){
	int i;

	for(i=0;i<News.num_item;i++){
			std::cout<<this->News.img_path[News.num_item]<<endl;
			if(News.img_path[News.num_item]!="."){
			auto image = download(News.img_path[News.num_item],true);
			News.image[News.num_item] = image;
			std::cout<<image;
		}

 	}

}
