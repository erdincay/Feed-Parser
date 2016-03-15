#include <string.h>
#include <gtkmm.h>
struct news {
	std::string title[100];
	std::string link[100];
	int num_item;
	Glib::RefPtr<Gdk::Pixbuf> image[100];
};
