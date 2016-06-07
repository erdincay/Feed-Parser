#include <feed.h>

int main(){
   auto x = feed("http://www.forbes.com/feeds/popstories.xml");
   x.fetch();
   x.parse();
   x.fetch_data();
}
