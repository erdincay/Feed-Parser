#include <feed.h>
#include <feed.cc>
int main(){
  auto x = feed("http://www.thehindu.com/news/cities/chennai/?service=rss");
  x.fetch();
  x.parse();
  x.fetch_data();
}
