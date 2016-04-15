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

				title = json.get<Object>("rss").get<Object>("channel").get<String>("title");
				desc = json.get<Object>("rss").get<Object>("channel").get<String>("description");
				items = json.get<Object>("rss").get<Object>("channel").get<Array>("item");
				News.num_item = 0;
				for (;News.num_item<items.size();News.num_item++){

					item = new Object(items.get<Object>(News.num_item));


						News.title[News.num_item] = item->get<Object>("title").get<String>("#text");
						if(item->has<Object>("thumbnail"))
						News.img_path[News.num_item] = item->get<Object>("thumbnail").get<String>("@url");
						else
						News.img_path[News.num_item] = "";
						News.link[News.num_item] = item->get<String>("link");
				}

		}catch(...){
			return false;
		}
		std::cout<<"Done";
return true;
}

bool feed::fetch_data(){
char* cwd;
int i;
getcwd(cwd,100);
string image;
for(i=0;i<News.num_item;i++){


			if(News.img_path[News.num_item]!="")
			image = download(News.img_path[News.num_item],true);
			if(!image.empty()){
				News.image[News.num_item] = image;

 	    }else{
				image = copy_file(string(string(cwd)+".backup.jpg").c_str());
				std::cout<<image;
				News.image[News.num_item] = image;
			}

		std::cout<<News.image[News.num_item];

}

}
