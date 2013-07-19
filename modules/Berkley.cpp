#include<string>
#include<db_cxx.h>
#include<memory>
#include<boost/shared_array.hpp>
extern "C"{
#include<stdint.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
};
#include"Common.hpp"
namespace C{
class Berkley{
  private:
    DbEnv _env;
    Db*   _db;
    const static int MAX_LEN = 1024 * 10;//10kByte memory space max
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
      _env.open("/tmp/", DB_CREATE|DB_INIT_MPOOL,0);
      _db = new Db(&_env, 0);
      _db->open(nullptr, "/var/berkley.dbm", nullptr, DB_BTREE,  DB_CREATE|DB_TRUNCATE, 0);
    };
    ~Berkley(){
      delete _db;
    };
    void put(const char* skey, const char* sval){
      Dbt key((void*)skey, strlen(skey));
      Dbt value((void*)sval, ::strlen(sval)+1);
      _db->put(nullptr, &key, &value, 0);
    };
    string read(const char* skey){
      Dbt key((void*)skey, ::strlen(skey));
      //fetch
      char* buf = _allocHeap(); //keep as heap mem
      Dbt data;
      data.set_data(buf);
      data.set_ulen(MAX_LEN);
      data.set_flags(DB_DBT_USERMEM);
      if( _db->get(nullptr, &key, &data, 0) == DB_NOTFOUND){
        return string("F");
      };
      string res(buf);
      delete[] buf;
      return res;
    };
};
};//namespace C


/*using namespace std;
int32_t main(){
  C::Berkley* _db = new C::Berkley();
  _db->set("hage", "hikaru");
  cout << "nemui "<< _db->get("hage").get() << endl;
  delete _db;
};*/
