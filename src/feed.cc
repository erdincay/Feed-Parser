
bool feed::fetch(){

		json.parse(download(url));
		cout<<"@JSON";
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
   			//	 News.img_path[News.num_item] = item->get<Object>("thumbnail").get<String>("@url");
   				 News.link[News.num_item] = item->get<String>("link");
			}
		}catch(...){
			return false;
		}

return true;
}

bool feed::fetch_data(){
	cout<<"Fetching images baby";
	try{
	//	download(News.title[News.num_item]+".jpg",News.img_path[News.num_item]);
     	try{
   			 	Glib::RefPtr<Gdk::Pixbuf> temp ;
   			 	temp = Gdk::Pixbuf::create_from_file(News.title[News.num_item]+".jpg")->scale_simple(100, 100, Gdk::INTERP_BILINEAR);
   	         	News.image[News.num_item] = temp;

 	    }catch(...){
 	    	Glib::RefPtr<Gdk::Pixbuf> temp ;
   			temp = Gdk::Pixbuf::create_from_file(".backup.jpg")->scale_simple(100, 100, Gdk::INTERP_BILINEAR);
   	       	News.image[News.num_item] = temp;
 	    }
		remove(((News.title[News.num_item]+".jpg")).c_str());

		char* loc,*cwd;
		getcwd(cwd,100);
  	sprintf(loc,"%s/res/database.data",cwd);
		ofstream of(loc,ios::binary);
		cout<<this->title;
		of.write((char*)this,sizeof(*this));
  		of.close();
  	}catch(...){
  		return false;
  	}
}
