extern "C"{
#include<leveldb/c.h>
};
#include"Common.hpp"
namespace C{
class Level{
  private:
    leveldb_t* _db;
    leveldb_options_t* _options;
    leveldb_readoptions_t* _roptions;
    leveldb_writeoptions_t* _woptions;
    char*   _err;
    char*   _read;
    size_t  _read_len;
    string _dbname;
  public:
    Level(const string& dbname)
    :_options(leveldb_options_create()),
    _woptions(leveldb_writeoptions_create()),
    _roptions(leveldb_readoptions_create()),
    _dbname(dbname)
    {
      leveldb_options_set_create_if_missing(_options, 1);
      _db = leveldb_open(_options, _dbname.c_str(), &_err);
      if(_err != nullptr){/*cerr << "open fail:" << _err << endl;*/};
    };
    bool put(const string& key, const string& val){
      leveldb_put(_db, _woptions, key.c_str(), key.length(), val.c_str(), val.length(), &_err);
      if(_err != nullptr){/*cerr << "write fail:" << _err << endl;*/ return false;};
      return true;
    };
    string read(const string& key){
      _read = leveldb_get(_db, _roptions, key.c_str(), key.length(), &_read_len, &_err);
      if(_err != nullptr){/*cerr << "get fail:" << _err << endl;*/ return "";};
      return string(_read, _read + _read_len);
    };
    ~Level(){
      /**
       * if you want to close DB, use Unlock operator
       * */ 
    };
    Level& operator~(){
      std::cerr << "a little chilly 1 " << std::endl;
      return *this;
    };
    operator Unlock(){
      std::cerr << "a little chilly 2 " << std::endl;
      leveldb_close(_db);
    };
    /* 特殊機能のDBのデストロイ */
    /* DBのクローズが発生して、ハンドルポイントが失われている必要がある */
    template<class LEVEL>
    static bool Dispose(LEVEL level){
      leveldb_destroy_db(level->_options, level->_dbname.c_str(), &(level->_err));
      if(level->_err != nullptr){std::cerr << "destroy fail:" << level->_err << std::endl;};
    };
};
};//namespace C
#include<future>
int main(){
  //std::async(std::launch::async, C::Pooling);
  
  std::shared_ptr<C::Level> level(new C::Level("leveldb.ldb"));
  level->put("atsui", "nemui");
  std::string res = level->read("atsui");
  //C::Level::Dispose(level);
  //C::Unlock(~(*level));
  std::cout << "leveldbtest: " << res << std::endl;
};



