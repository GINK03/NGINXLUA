#include<string>
#include<iostream>
#include<db_cxx.h>
#include<memory>
#include<boost/shared_array.hpp>
extern "C"{
#include<stdint.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
};
namespace C{
class Berkley{
  using schar = boost::shared_array<char>;
  private:
    DbEnv _env;
    Db*   _db;
    const static int MAX_LEN = 65536;//16bit memory space max
    inline char* _allocHeap(){
      char* res = (char*)malloc(MAX_LEN);
      ::memset(res, '\0', MAX_LEN);
      return res;
    };
  public:
    Berkley()
    :_env(0)
    {
      _env.set_error_stream(&std::cerr);
      _env.open("./", DB_CREATE|DB_INIT_MPOOL,0);
      _db = new Db(&_env, 0);
      _db->open(nullptr, "nginx.dbm", nullptr, DB_BTREE,  DB_CREATE | DB_TRUNCATE, 0);
    };
    ~Berkley(){
      delete _db;
    };
    void set(const char* skey, const char* sval){
      Dbt key((void*)skey, strlen(skey));
      Dbt value((void*)sval, ::strlen(sval)+1);
      _db->put(nullptr, &key, &value, 0);
    };
    schar get(const char* skey){
      Dbt key((void*)skey, ::strlen(skey));
      //fetch
      char* buf = _allocHeap(); //keep as heap mem
      Dbt data;
      data.set_data(buf);
      data.set_ulen(MAX_LEN);
      data.set_flags(DB_DBT_USERMEM);
      if( _db->get(nullptr, &key, &data, 0) == DB_NOTFOUND){
        return schar(new char('F'));
      };
      std::cout << "found " << buf << std::endl;
      return schar(buf);
    };
};
};//namespace C


using namespace std;
int32_t main(){
  C::Berkley* _db = new C::Berkley();
  _db->set("hage", "hikaru");
  cout << "nemui "<< _db->get("hage").get() << endl;
  delete _db;
};
