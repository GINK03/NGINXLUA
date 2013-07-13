#!/usr/local/bin/thrift --gen cpp
# c++'s namespace
namespace cpp C

service Control {
  i32 ping();
  string tSet(1:i32 json);
  string tSetOpt(1:string json, 2:string opt);
  string tGet(1:string json);
  string tGetOpt(1:string json, 2:string opt);
  string tTune(1:string json);
  string tTuneOpt(1:string json, 2:string opt);
}
