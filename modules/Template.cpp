#include<string>
#include<sstream>
#include<vector>
#include<boost/lexical_cast.hpp>
/* TODO change prototype */
#include"./Berkley.cpp"
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
constexpr auto funcCounter = [](int32_t i, char* key, Berkley* db){
  static int32_t k = 0; ++k;
  static std::vector<str> vs = {"start!!!:"};
  auto bval = db->get(key);
  //return str("cannnot access BerkeleyDB1!");
  if(str(bval.get()) == "F"){
    db->set(key, lexical_cast<str>(k).c_str());
    return str("cannnot access BerkeleyDB!");
  };
  str regist = str("BerkleyDB counter:") + str(bval.get());
  db->set(key, lexical_cast<str>(k).c_str());
  vs.push_back(regist);
  auto endit = vs.end();
  return *(endit - 1);
};
class HTML{
  private:
    Berkley* _db;
    char* kCOUNTER(){return "___counter___";};
    HTML(){
      _db = Berkley::getInst();
    };//no create instance
    ~HTML(){
    };//auto dispose by kernel
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
         << funcCounter(1, kCOUNTER(), _db) 
         << "</br> it's too hot</br>"
         << input
         << "</body></html>";
      std::cout << "[INPUT]" << input << std::endl;
      return ss.str();
    };
};
};//namespace

const char* cxxBridge(ngx_str_t in){
  return C::HTML::getInst()->Header(in.data).c_str();
};
