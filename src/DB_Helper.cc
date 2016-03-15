#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

bool DB_Helper::Create_db(feed f){
    sqlite3 *db;
    char *zErrMsg = 0;
    int  rc;


    /* Open database */
    rc = sqlite3_open("News.db", &db);
    if( rc ){
       fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
       exit(0);
    }else{
       fprintf(stdout, "Opened database successfully\n");
    }

    sql = "CREATE TABLE FEED("  \
       "ID NUMBER PRIMARY KEY     NOT NULL," \
       "TITLE           CHAR(50)    NOT NULL," \
       "LINK           CHAR(50)     NOT NULL," \
       "FEEDNAME    CHAR(50)");

     rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
     if( rc != SQLITE_OK ){
       sqlite3_close(db);
       sqlite3_free(zErrMsg);
       return false;
     }else{
        sqlite3_close(db);
        return true;
     }
return true;
}

static news pushintofeed(void *NotUsed, int argc, char **argv, char **azColName){

     char *cwd;
     getcwd(cwd,100);
     int i;
     news.num_item = atoi(argv[0]);
     news.title[news.num_item] = string(argv[1]);
     news.link[news.num_item] = string(argv[2]);
     Glib::RefPtr<Gdk::Pixbuf> temp = Gdk::Pixbuf::create_from_file(string(cwd)+news.num_item+".jpg")->scale_simple(100, 100, Gdk::INTERP_BILINEAR);
     ofstream f("d.d",ios::app);
     f.write((char*)&temp,sizeof(temp));
     f.close();
     printf("\n");
     return 0;
}

feed DB_Helper::getfeeds(){
  sql = "SELECT * FROM FEED";
  int rc = sqlite3_exec(db, sql.c_str(), pushintofeed, 0, &zErrMsg);

}

string DB_Helper::getfeedtopics(){
  sql = "SELECT * FROM FEED"
}
