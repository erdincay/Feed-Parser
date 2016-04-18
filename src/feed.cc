#include<utils.cc>
#include <unistd.h>
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

bool feed::parse(){
	try{
		int x= 0;

				title = json.get<Object>("rss").get<Object>("channel").get<String>("title");
				desc = json.get<Object>("rss").get<Object>("channel").get<String>("description");
				items = json.get<Object>("rss").get<Object>("channel").get<Array>("item");
				News.num_item = items.size();
				//	return value_map_.find(key)->second->get<T>();
				while(x<=News.num_item) {
							std::cout<<items.get<Object>(x).get_c();
							x++;
							//return value_map_.find(key)->second->get<T>();
				}
			/*	for (;News.num_item<items.size();News.num_item++){

					item = new Object(items.get<Object>(News.num_item));


						News.title[News.num_item] = item->get<Object>("title").get<String>("#text");
						if(item->has<Object>("thumbnail"))
						News.img_path[News.num_item] = item->get<Object>("thumbnail").get<String>("@url");
						else
						News.img_path[News.num_item] = "";
						if(item->has<String>("link"))
						News.link[News.num_item] = item->get<String>("link");
						if(item->has<Object>("content"))
						News.link[News.num_item] = item->get<Object>("content")->get<String>("link");
				}
*/
		}catch(...){
			return false;
		}
		std::cout<<"Done";
return true;
}

bool feed::fetch_data(){
	int i;
	char* image;
	for(i=0;i<News.num_item;i++){
			if(News.img_path[News.num_item]!=""){
			image = download(News.img_path[News.num_item],true).c_str();
			if(image != NULL){
				News.image[News.num_item] = image;
			}
		}

 	}

}
