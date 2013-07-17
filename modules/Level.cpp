extern "C"{
#include<leveldb/c.h>
};
#include<iostream>
#include<string>

using namespace std;

int main(){
  leveldb_t* db;
  leveldb_options_t* options;
  leveldb_readoptions_t* roptions;
  leveldb_writeoptions_t* woptions;
  char* err = nullptr;
  char* read;
  size_t read_len;

  options = leveldb_options_create();
  leveldb_options_set_create_if_missing(options, 1);
  db = leveldb_open(options, "testdb.ldb", &err);
  if(err != nullptr){cerr << "open fail:" << err << endl; return 0;};
  //leveldb_free((void*)err); err = nullptr;

  woptions = leveldb_writeoptions_create();
  leveldb_put(db, woptions, "key", 3, "value", 5, &err);
  if(err != nullptr){cerr << "write fail:" << err << endl; return 0;};
  //leveldb_free((void*)err); err = nullptr;
  
  roptions = leveldb_readoptions_create();
  read = leveldb_get(db, roptions, "key", 3, &read_len, &err);
  if(err != nullptr){cerr << "get fail:" << err << endl; return 0;};
  cout << "read:" << std::string(read, read + read_len) << " readlen:" << read_len << endl;
  //leveldb_free((void*)err); err = nullptr;

  leveldb_close(db);
  leveldb_destroy_db(options, "testdb", &err);
  if(err != nullptr){cerr << "destroy fail:" << err << endl; return 0;};
  cout << "test " << endl;
};



