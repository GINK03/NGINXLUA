#include<string>
#include<sstream>
#include<vector>
#include<boost/lexical_cast.hpp>
#include<iostream>
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
using sstr  = std::stringstream;
using boost::lexical_cast;
static auto funcPool = [](int32_t i){
  static int32_t k = 0;
  static std::vector<std::string> vs = {"mem1", "mem2"};
  auto regist = {'c', ':', char(k + i + 48)};
  vs.push_back(regist);
  ++k;
  return vs[k];
};

class HTML{
  private:
    HTML(){};
  public:
    static str Header(unsigned char* in){
      str input("");
      if(in != nullptr){
        input = lexical_cast<str>(in);
      };
      sstr ss;
      ss << "<html><head></head><body>Wellcome to C++11 world</br>" 
         << funcPool(1) 
         << "</br> it's too hot</br>"
         << input
         << "</body></html>";
      std::cout << "[INPUT]" << input << std::endl;
      return ss.str();
    };
};
};//namespace

const char* cxxBridge(ngx_str_t in){
  return C::HTML::Header(in.data).c_str();
};
