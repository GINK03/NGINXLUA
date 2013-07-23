#ifndef INCLUDE_COMMON
#define INCLUDE_COMMON

#include<string>
#include<memory>
#include<iostream>
#include<vector>
#include<queue>
#include<thread>
namespace C{
//allowed library
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::shared_ptr;
using std::vector;
using std::queue;
using std::thread;
struct Dispose{
  Dispose(){};
};
struct Unlock{
  Unlock(){};
};
namespace L{
static string logline_;
void static Logger(){};
template<class T>
void static Logger(const T& t){
  cerr << "sample : " << logline_ << endl;
  logline_ = ""; //clear string
};
template<class T, class... Tx>
void static Logger(const T& t, const Tx&... tx){
  //if(t != nullptr){  
    logline_ += string(t);
  //};
  Logger(tx...);
};
};//end namespace L
};//end namespace C
#endif
