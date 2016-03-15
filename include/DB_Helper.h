#include <sqlite3.h>


class DB_Helper{
  sqlite3 *db;
  std::string sql
public:
  bool Create_db(feed);
  void getfeeds();
  string getfeedtopics();
}
