
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
			link =  json.get<Object>("rss").get<Object>("channel").get<String>("link");
		    desc = json.get<Object>("rss").get<Object>("channel").get<String>("description");
			date = json.get<Object>("rss").get<Object>("channel").get<String>("pubDate");
			items = json.get<Object>("rss").get<Object>("channel").get<Array>("item");
			News.num_item = 0;
			for (;News.num_item<items.size();News.num_item++){
   				 item = new Object(items.get<Object>(News.num_item));
   				 if(item->has<String>("tile")){
   				 	News.title[News.num_item] = item->get<String>("tile");
   				 }
   				 else{
   				 	News.title[News.num_item] = item->get<String>("title");
   				 }
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
char* image;
for(i=0;i<News.num_item;i++){

	try{
		image = download(News.title[News.num_item]+".jpg",News.img_path[News.num_item],true);
      if(image!=NULL){

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
