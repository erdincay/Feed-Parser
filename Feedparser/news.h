#ifndef NEWS_H_
#define NEWS_H_

#include <string>

struct news {
	std::string title[100];
	std::string link[100];
	int num_item;
	std::string img_path[100];
	std::string image[100];
};
#endif
