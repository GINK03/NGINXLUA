extern "C"{
#include<leveldb/c.h>
};
#include<iostream>
#include<string>

using namespace std;
class Level{
  private:
    leveldb_t* _db;
    leveldb_options_t* _options;
    leveldb_readoptions_t* _roptions;
    leveldb_writeoptions_t* _woptions;
    char*   _err;
    char*   _read;
    size_t  _read_len;
  public:
    Level(){
      _options = leveldb_options_create();
      leveldb_options_set_create_if_missing(_options, 1);
      _db = leveldb_open(_options, "testdb.ldb", &_err);
      if(_err != nullptr){cerr << "open fail:" << _err << endl; /*return 0;*/};
      //leveldb_free((void*)err); err = nullptr;
    };
    bool put(){
      _woptions = leveldb_writeoptions_create();
      leveldb_put(_db, _woptions, "key", 3, "value", 5, &_err);
      if(_err != nullptr){cerr << "write fail:" << _err << endl; return false;};
      return true;
      //leveldb_free((void*)err); err = nullptr;
    };
    bool read(){
      _roptions = leveldb_readoptions_create();
      _read = leveldb_get(_db, _roptions, "key", 3, &_read_len, &_err);
      if(_err != nullptr){cerr << "get fail:" << _err << endl; return false;};
      cout << "read:" << string(_read, _read + _read_len) << " readlen:" << _read_len << endl;
      return true;
      //leveldb_free((void*)err); err = nullptr;
    };
    ~Level(){
      leveldb_close(_db);
      leveldb_destroy_db(_options, "testdb", &_err);
      if(_err != nullptr){cerr << "destroy fail:" << _err << endl; /*return 0;*/};
    };
};
int main(){
  Level lev();
  cout << "test " << endl;
};



