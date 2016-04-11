#include<utils.cc>
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
				std::cout<<items;
				for (;News.num_item<items.size();News.num_item++){

					item = new Object(items.get<Object>(News.num_item));

						std::cout<<item->get<Object>("title").get<String>("#text");
						std::cout<<News.title[News.num_item];

					 	News.img_path[News.num_item] = item->get<Object>("thumbnail").get<String>("@url");
   				 	News.link[News.num_item] = item->get<String>("link");
				}

		}catch(...){
			return false;
		}

return true;
}

bool feed::fetch_data(){
int i;
string image;
std::cout<<News.num_item;
for(i=0;i<News.num_item;i++){

	try{
		image = download(News.img_path[News.num_item],true);
		std::cout<<image.size();
      if(!image.empty()){
			  std::cout<<image;
				News.image[News.num_item] = image;

 	    }else{
				image = copy_file(".backup.jpg");
				News.image[News.num_item] = image;
 	    }

  	}catch(...){
  		return false;
  	}
}

}
