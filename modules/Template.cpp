#include<string>
#include<sstream>
//** プロトタイプ宣言
extern "C"{
const char* cxxBridge(char* in);
};

namespace C{
class HTML{
  private:
    HTML(){};
  public:
    static std::string Header(){
      std::stringstream ss;
      ss << "<html><head></head><body>Wellcome to C++11 world</body></html>";
      return ss.str();
    };
};
};//namespace

const char* cxxBridge(char* in){
  return C::HTML::Header().c_str();
};
