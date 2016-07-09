#include <Feedparser/feed.h>

int main(){
   auto x = feed("http://www.forbes.com/feeds/popstories.xml");
   x.fetch();
   std::cout<<x.json;
}
