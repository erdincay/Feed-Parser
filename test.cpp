#include <feed.h>
#include <feed.cc>
int main(){
  auto x = feed("http://www.thehindu.com/news/cities/chennai/?service=rss");
  x.fetch();
  //std::cout<<x.json;
  x.parse();
  x.fetch_data();
}
