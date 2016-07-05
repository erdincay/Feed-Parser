#include <feed.cc>

int main(){
   auto x = feed("http://www.forbes.com/feeds/popstories.xml");
   x.fetch();
   std::cout<<x.json;
   x.parse();
   x.fetch_data();
}
