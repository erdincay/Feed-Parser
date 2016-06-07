#include <feed.h>
#include <feed.cc>
int main(){
   auto x = feed("http://www.forbes.com/feeds/popstories.xml");
   x.fetch();
   x.parse();
   x.fetch_data();
}
