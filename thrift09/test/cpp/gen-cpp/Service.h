/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Service_H
#define Service_H

#include <thrift/TDispatchProcessor.h>
#include "StressTest_types.h"

namespace test { namespace stress {

class ServiceIf {
 public:
  virtual ~ServiceIf() {}
  virtual void echoVoid() = 0;
  virtual int8_t echoByte(const int8_t arg) = 0;
  virtual int32_t echoI32(const int32_t arg) = 0;
  virtual int64_t echoI64(const int64_t arg) = 0;
  virtual void echoString(std::string& _return, const std::string& arg) = 0;
  virtual void echoList(std::vector<int8_t> & _return, const std::vector<int8_t> & arg) = 0;
  virtual void echoSet(std::set<int8_t> & _return, const std::set<int8_t> & arg) = 0;
  virtual void echoMap(std::map<int8_t, int8_t> & _return, const std::map<int8_t, int8_t> & arg) = 0;
};

class ServiceIfFactory {
 public:
  typedef ServiceIf Handler;

  virtual ~ServiceIfFactory() {}

  virtual ServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ServiceIf* /* handler */) = 0;
};

class ServiceIfSingletonFactory : virtual public ServiceIfFactory {
 public:
  ServiceIfSingletonFactory(const boost::shared_ptr<ServiceIf>& iface) : iface_(iface) {}
  virtual ~ServiceIfSingletonFactory() {}

  virtual ServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<ServiceIf> iface_;
};

class ServiceNull : virtual public ServiceIf {
 public:
  virtual ~ServiceNull() {}
  void echoVoid() {
    return;
  }
  int8_t echoByte(const int8_t /* arg */) {
    int8_t _return = 0;
    return _return;
  }
  int32_t echoI32(const int32_t /* arg */) {
    int32_t _return = 0;
    return _return;
  }
  int64_t echoI64(const int64_t /* arg */) {
    int64_t _return = 0;
    return _return;
  }
  void echoString(std::string& /* _return */, const std::string& /* arg */) {
    return;
  }
  void echoList(std::vector<int8_t> & /* _return */, const std::vector<int8_t> & /* arg */) {
    return;
  }
  void echoSet(std::set<int8_t> & /* _return */, const std::set<int8_t> & /* arg */) {
    return;
  }
  void echoMap(std::map<int8_t, int8_t> & /* _return */, const std::map<int8_t, int8_t> & /* arg */) {
    return;
  }
};


class Service_echoVoid_args {
 public:

  Service_echoVoid_args() {
  }

  virtual ~Service_echoVoid_args() throw() {}


  bool operator == (const Service_echoVoid_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Service_echoVoid_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoVoid_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Service_echoVoid_pargs {
 public:


  virtual ~Service_echoVoid_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Service_echoVoid_result {
 public:

  Service_echoVoid_result() {
  }

  virtual ~Service_echoVoid_result() throw() {}


  bool operator == (const Service_echoVoid_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Service_echoVoid_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoVoid_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Service_echoVoid_presult {
 public:


  virtual ~Service_echoVoid_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Service_echoByte_args__isset {
  _Service_echoByte_args__isset() : arg(false) {}
  bool arg;
} _Service_echoByte_args__isset;

class Service_echoByte_args {
 public:

  Service_echoByte_args() : arg(0) {
  }

  virtual ~Service_echoByte_args() throw() {}

  int8_t arg;

  _Service_echoByte_args__isset __isset;

  void __set_arg(const int8_t val) {
    arg = val;
  }

  bool operator == (const Service_echoByte_args & rhs) const
  {
    if (!(arg == rhs.arg))
      return false;
    return true;
  }
  bool operator != (const Service_echoByte_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoByte_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Service_echoByte_pargs {
 public:


  virtual ~Service_echoByte_pargs() throw() {}

  const int8_t* arg;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoByte_result__isset {
  _Service_echoByte_result__isset() : success(false) {}
  bool success;
} _Service_echoByte_result__isset;

class Service_echoByte_result {
 public:

  Service_echoByte_result() : success(0) {
  }

  virtual ~Service_echoByte_result() throw() {}

  int8_t success;

  _Service_echoByte_result__isset __isset;

  void __set_success(const int8_t val) {
    success = val;
  }

  bool operator == (const Service_echoByte_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Service_echoByte_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoByte_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoByte_presult__isset {
  _Service_echoByte_presult__isset() : success(false) {}
  bool success;
} _Service_echoByte_presult__isset;

class Service_echoByte_presult {
 public:


  virtual ~Service_echoByte_presult() throw() {}

  int8_t* success;

  _Service_echoByte_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Service_echoI32_args__isset {
  _Service_echoI32_args__isset() : arg(false) {}
  bool arg;
} _Service_echoI32_args__isset;

class Service_echoI32_args {
 public:

  Service_echoI32_args() : arg(0) {
  }

  virtual ~Service_echoI32_args() throw() {}

  int32_t arg;

  _Service_echoI32_args__isset __isset;

  void __set_arg(const int32_t val) {
    arg = val;
  }

  bool operator == (const Service_echoI32_args & rhs) const
  {
    if (!(arg == rhs.arg))
      return false;
    return true;
  }
  bool operator != (const Service_echoI32_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoI32_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Service_echoI32_pargs {
 public:


  virtual ~Service_echoI32_pargs() throw() {}

  const int32_t* arg;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoI32_result__isset {
  _Service_echoI32_result__isset() : success(false) {}
  bool success;
} _Service_echoI32_result__isset;

class Service_echoI32_result {
 public:

  Service_echoI32_result() : success(0) {
  }

  virtual ~Service_echoI32_result() throw() {}

  int32_t success;

  _Service_echoI32_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const Service_echoI32_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Service_echoI32_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoI32_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoI32_presult__isset {
  _Service_echoI32_presult__isset() : success(false) {}
  bool success;
} _Service_echoI32_presult__isset;

class Service_echoI32_presult {
 public:


  virtual ~Service_echoI32_presult() throw() {}

  int32_t* success;

  _Service_echoI32_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Service_echoI64_args__isset {
  _Service_echoI64_args__isset() : arg(false) {}
  bool arg;
} _Service_echoI64_args__isset;

class Service_echoI64_args {
 public:

  Service_echoI64_args() : arg(0) {
  }

  virtual ~Service_echoI64_args() throw() {}

  int64_t arg;

  _Service_echoI64_args__isset __isset;

  void __set_arg(const int64_t val) {
    arg = val;
  }

  bool operator == (const Service_echoI64_args & rhs) const
  {
    if (!(arg == rhs.arg))
      return false;
    return true;
  }
  bool operator != (const Service_echoI64_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoI64_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Service_echoI64_pargs {
 public:


  virtual ~Service_echoI64_pargs() throw() {}

  const int64_t* arg;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoI64_result__isset {
  _Service_echoI64_result__isset() : success(false) {}
  bool success;
} _Service_echoI64_result__isset;

class Service_echoI64_result {
 public:

  Service_echoI64_result() : success(0) {
  }

  virtual ~Service_echoI64_result() throw() {}

  int64_t success;

  _Service_echoI64_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const Service_echoI64_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Service_echoI64_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoI64_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoI64_presult__isset {
  _Service_echoI64_presult__isset() : success(false) {}
  bool success;
} _Service_echoI64_presult__isset;

class Service_echoI64_presult {
 public:


  virtual ~Service_echoI64_presult() throw() {}

  int64_t* success;

  _Service_echoI64_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Service_echoString_args__isset {
  _Service_echoString_args__isset() : arg(false) {}
  bool arg;
} _Service_echoString_args__isset;

class Service_echoString_args {
 public:

  Service_echoString_args() : arg() {
  }

  virtual ~Service_echoString_args() throw() {}

  std::string arg;

  _Service_echoString_args__isset __isset;

  void __set_arg(const std::string& val) {
    arg = val;
  }

  bool operator == (const Service_echoString_args & rhs) const
  {
    if (!(arg == rhs.arg))
      return false;
    return true;
  }
  bool operator != (const Service_echoString_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoString_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Service_echoString_pargs {
 public:


  virtual ~Service_echoString_pargs() throw() {}

  const std::string* arg;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoString_result__isset {
  _Service_echoString_result__isset() : success(false) {}
  bool success;
} _Service_echoString_result__isset;

class Service_echoString_result {
 public:

  Service_echoString_result() : success() {
  }

  virtual ~Service_echoString_result() throw() {}

  std::string success;

  _Service_echoString_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const Service_echoString_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Service_echoString_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoString_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoString_presult__isset {
  _Service_echoString_presult__isset() : success(false) {}
  bool success;
} _Service_echoString_presult__isset;

class Service_echoString_presult {
 public:


  virtual ~Service_echoString_presult() throw() {}

  std::string* success;

  _Service_echoString_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Service_echoList_args__isset {
  _Service_echoList_args__isset() : arg(false) {}
  bool arg;
} _Service_echoList_args__isset;

class Service_echoList_args {
 public:

  Service_echoList_args() {
  }

  virtual ~Service_echoList_args() throw() {}

  std::vector<int8_t>  arg;

  _Service_echoList_args__isset __isset;

  void __set_arg(const std::vector<int8_t> & val) {
    arg = val;
  }

  bool operator == (const Service_echoList_args & rhs) const
  {
    if (!(arg == rhs.arg))
      return false;
    return true;
  }
  bool operator != (const Service_echoList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Service_echoList_pargs {
 public:


  virtual ~Service_echoList_pargs() throw() {}

  const std::vector<int8_t> * arg;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoList_result__isset {
  _Service_echoList_result__isset() : success(false) {}
  bool success;
} _Service_echoList_result__isset;

class Service_echoList_result {
 public:

  Service_echoList_result() {
  }

  virtual ~Service_echoList_result() throw() {}

  std::vector<int8_t>  success;

  _Service_echoList_result__isset __isset;

  void __set_success(const std::vector<int8_t> & val) {
    success = val;
  }

  bool operator == (const Service_echoList_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Service_echoList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoList_presult__isset {
  _Service_echoList_presult__isset() : success(false) {}
  bool success;
} _Service_echoList_presult__isset;

class Service_echoList_presult {
 public:


  virtual ~Service_echoList_presult() throw() {}

  std::vector<int8_t> * success;

  _Service_echoList_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Service_echoSet_args__isset {
  _Service_echoSet_args__isset() : arg(false) {}
  bool arg;
} _Service_echoSet_args__isset;

class Service_echoSet_args {
 public:

  Service_echoSet_args() {
  }

  virtual ~Service_echoSet_args() throw() {}

  std::set<int8_t>  arg;

  _Service_echoSet_args__isset __isset;

  void __set_arg(const std::set<int8_t> & val) {
    arg = val;
  }

  bool operator == (const Service_echoSet_args & rhs) const
  {
    if (!(arg == rhs.arg))
      return false;
    return true;
  }
  bool operator != (const Service_echoSet_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoSet_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Service_echoSet_pargs {
 public:


  virtual ~Service_echoSet_pargs() throw() {}

  const std::set<int8_t> * arg;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoSet_result__isset {
  _Service_echoSet_result__isset() : success(false) {}
  bool success;
} _Service_echoSet_result__isset;

class Service_echoSet_result {
 public:

  Service_echoSet_result() {
  }

  virtual ~Service_echoSet_result() throw() {}

  std::set<int8_t>  success;

  _Service_echoSet_result__isset __isset;

  void __set_success(const std::set<int8_t> & val) {
    success = val;
  }

  bool operator == (const Service_echoSet_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Service_echoSet_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoSet_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoSet_presult__isset {
  _Service_echoSet_presult__isset() : success(false) {}
  bool success;
} _Service_echoSet_presult__isset;

class Service_echoSet_presult {
 public:


  virtual ~Service_echoSet_presult() throw() {}

  std::set<int8_t> * success;

  _Service_echoSet_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Service_echoMap_args__isset {
  _Service_echoMap_args__isset() : arg(false) {}
  bool arg;
} _Service_echoMap_args__isset;

class Service_echoMap_args {
 public:

  Service_echoMap_args() {
  }

  virtual ~Service_echoMap_args() throw() {}

  std::map<int8_t, int8_t>  arg;

  _Service_echoMap_args__isset __isset;

  void __set_arg(const std::map<int8_t, int8_t> & val) {
    arg = val;
  }

  bool operator == (const Service_echoMap_args & rhs) const
  {
    if (!(arg == rhs.arg))
      return false;
    return true;
  }
  bool operator != (const Service_echoMap_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoMap_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Service_echoMap_pargs {
 public:


  virtual ~Service_echoMap_pargs() throw() {}

  const std::map<int8_t, int8_t> * arg;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoMap_result__isset {
  _Service_echoMap_result__isset() : success(false) {}
  bool success;
} _Service_echoMap_result__isset;

class Service_echoMap_result {
 public:

  Service_echoMap_result() {
  }

  virtual ~Service_echoMap_result() throw() {}

  std::map<int8_t, int8_t>  success;

  _Service_echoMap_result__isset __isset;

  void __set_success(const std::map<int8_t, int8_t> & val) {
    success = val;
  }

  bool operator == (const Service_echoMap_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Service_echoMap_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service_echoMap_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Service_echoMap_presult__isset {
  _Service_echoMap_presult__isset() : success(false) {}
  bool success;
} _Service_echoMap_presult__isset;

class Service_echoMap_presult {
 public:


  virtual ~Service_echoMap_presult() throw() {}

  std::map<int8_t, int8_t> * success;

  _Service_echoMap_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ServiceClient : virtual public ServiceIf {
 public:
  ServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void echoVoid();
  void send_echoVoid();
  void recv_echoVoid();
  int8_t echoByte(const int8_t arg);
  void send_echoByte(const int8_t arg);
  int8_t recv_echoByte();
  int32_t echoI32(const int32_t arg);
  void send_echoI32(const int32_t arg);
  int32_t recv_echoI32();
  int64_t echoI64(const int64_t arg);
  void send_echoI64(const int64_t arg);
  int64_t recv_echoI64();
  void echoString(std::string& _return, const std::string& arg);
  void send_echoString(const std::string& arg);
  void recv_echoString(std::string& _return);
  void echoList(std::vector<int8_t> & _return, const std::vector<int8_t> & arg);
  void send_echoList(const std::vector<int8_t> & arg);
  void recv_echoList(std::vector<int8_t> & _return);
  void echoSet(std::set<int8_t> & _return, const std::set<int8_t> & arg);
  void send_echoSet(const std::set<int8_t> & arg);
  void recv_echoSet(std::set<int8_t> & _return);
  void echoMap(std::map<int8_t, int8_t> & _return, const std::map<int8_t, int8_t> & arg);
  void send_echoMap(const std::map<int8_t, int8_t> & arg);
  void recv_echoMap(std::map<int8_t, int8_t> & _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_echoVoid(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_echoByte(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_echoI32(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_echoI64(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_echoString(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_echoList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_echoSet(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_echoMap(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ServiceProcessor(boost::shared_ptr<ServiceIf> iface) :
    iface_(iface) {
    processMap_["echoVoid"] = &ServiceProcessor::process_echoVoid;
    processMap_["echoByte"] = &ServiceProcessor::process_echoByte;
    processMap_["echoI32"] = &ServiceProcessor::process_echoI32;
    processMap_["echoI64"] = &ServiceProcessor::process_echoI64;
    processMap_["echoString"] = &ServiceProcessor::process_echoString;
    processMap_["echoList"] = &ServiceProcessor::process_echoList;
    processMap_["echoSet"] = &ServiceProcessor::process_echoSet;
    processMap_["echoMap"] = &ServiceProcessor::process_echoMap;
  }

  virtual ~ServiceProcessor() {}
};

class ServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ServiceProcessorFactory(const ::boost::shared_ptr< ServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ServiceIfFactory > handlerFactory_;
};

class ServiceMultiface : virtual public ServiceIf {
 public:
  ServiceMultiface(std::vector<boost::shared_ptr<ServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ServiceIf> > ifaces_;
  ServiceMultiface() {}
  void add(boost::shared_ptr<ServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void echoVoid() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->echoVoid();
    }
    ifaces_[i]->echoVoid();
  }

  int8_t echoByte(const int8_t arg) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->echoByte(arg);
    }
    return ifaces_[i]->echoByte(arg);
  }

  int32_t echoI32(const int32_t arg) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->echoI32(arg);
    }
    return ifaces_[i]->echoI32(arg);
  }

  int64_t echoI64(const int64_t arg) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->echoI64(arg);
    }
    return ifaces_[i]->echoI64(arg);
  }

  void echoString(std::string& _return, const std::string& arg) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->echoString(_return, arg);
    }
    ifaces_[i]->echoString(_return, arg);
    return;
  }

  void echoList(std::vector<int8_t> & _return, const std::vector<int8_t> & arg) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->echoList(_return, arg);
    }
    ifaces_[i]->echoList(_return, arg);
    return;
  }

  void echoSet(std::set<int8_t> & _return, const std::set<int8_t> & arg) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->echoSet(_return, arg);
    }
    ifaces_[i]->echoSet(_return, arg);
    return;
  }

  void echoMap(std::map<int8_t, int8_t> & _return, const std::map<int8_t, int8_t> & arg) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->echoMap(_return, arg);
    }
    ifaces_[i]->echoMap(_return, arg);
    return;
  }

};

}} // namespace

#endif
