#include <feed.h>
#include <feed.cc>
int main(){
  auto x = feed("http://rss.cnn.com/rss/edition.rss");
  x.fetch();
  x.parse();
//  x.fetch_data();
}
