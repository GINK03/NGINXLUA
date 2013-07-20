#include<string>
#include<sstream>
#include<vector>
#include<boost/lexical_cast.hpp>
/* TODO change prototype */
#include"Common.hpp"
#include"Level.cpp"
#include"Berkley.cpp"
extern "C"{
#include"hiredis/hiredis.h"
};
//** プロトタイプ宣言
typedef struct{
  size_t len;
  u_char *data;
} ngx_str_t;

extern "C"{
const char* cxxBridge(ngx_str_t in);
};

namespace C{
using str = std::string;
using vecstr = std::vector<std::string>;
using sstr  = std::stringstream;
using boost::lexical_cast;
constexpr auto funcCounter = [](int32_t i, char* key, Level* db){
  static int32_t k = 0;
  auto val = db->read(key);
  if(val != "F"){k = std::atoi(val.c_str());++k;};
  auto new_key = lexical_cast<str>(k);
  db->put(key, new_key);
  str regist = str("LevelDB counter: ") + new_key;
  return regist;
};
class HTML{
  private:
    Berkley* _bdb;
    Level*  _ldb;
    char* kCOUNTER(){return "___counter___";};
    HTML()
    :_ldb(new Level("/var/level.ldb")),
     _bdb(new Berkley("/var/berkley.bdb"))
    {
    };//no create instance
    ~HTML(){
      Unlock(~(*_ldb));//unlock leveldb
    };//auto dispose by kernel
    str _getKeys(){
      auto val = _ldb->read("___DATEKEY___");
      return val;
    };
  public:
    /* access only singleton-insterface */
    static HTML* getInst(){
      static HTML inst;
      return &inst;
    };
    str Header(unsigned char* in){
      str input("");
      if(in != nullptr){
        input = lexical_cast<str>(in);
      };
      sstr ss;
      ss << "<html><head></head><body>Wellcome to C++11 world</br>" 
         << funcCounter(1, kCOUNTER(), _ldb) 
         << "</br> it's too hot</br>"
         << input
         << "</br>"
         << "keys: " << _getKeys()
         << "</body></html>";
      std::cout << "[INPUT]" << input << std::endl;
      return ss.str();
    };
};
};//namespace

const char* cxxBridge(ngx_str_t in){
  return C::HTML::getInst()->Header(in.data).c_str();
};
