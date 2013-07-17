// This autogenerated skeleton file illustrates one way to adapt a synchronous
// interface into an asynchronous interface. You should copy it to another
// filename to avoid overwriting it and rewrite as asynchronous any functions
// that would otherwise introduce unwanted latency.

#include "ParentService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/async/TEventServer.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::async;

using boost::shared_ptr;

using namespace  ::apache::thrift::test;

class ParentServiceAsyncHandler : public ParentServiceCobSvIf {
 public:
  ParentServiceAsyncHandler() {
    syncHandler_ = std::auto_ptr<ParentServiceHandler>(new ParentServiceHandler);
    // Your initialization goes here
  }
  virtual ~ParentServiceAsyncHandler();

  void incrementGeneration(std::tr1::function<void(int32_t const& _return)> cob) {
    int32_t _return = 0;
    _return = syncHandler_->incrementGeneration();
    return cob(_return);
  }

  void getGeneration(std::tr1::function<void(int32_t const& _return)> cob) {
    int32_t _return = 0;
    _return = syncHandler_->getGeneration();
    return cob(_return);
  }

  void addString(std::tr1::function<void()> cob, const std::string& s) {
    syncHandler_->addString(s);
    return cob();
  }

  void getStrings(std::tr1::function<void(std::vector<std::string>  const& _return)> cob) {
    std::vector<std::string>  _return;
    syncHandler_->getStrings(_return);
    return cob(_return);
  }

  void getDataWait(std::tr1::function<void(std::string const& _return)> cob, const int32_t length) {
    std::string _return;
    syncHandler_->getDataWait(_return, length);
    return cob(_return);
  }

  void onewayWait(std::tr1::function<void()> cob) {
    syncHandler_->onewayWait();
    return cob();
  }

  void exceptionWait(std::tr1::function<void()> cob, std::tr1::function<void(::apache::thrift::TDelayedException* _throw)> /* exn_cob */, const std::string& message) {
    syncHandler_->exceptionWait(message);
    return cob();
  }

  void unexpectedExceptionWait(std::tr1::function<void()> cob, const std::string& message) {
    syncHandler_->unexpectedExceptionWait(message);
    return cob();
  }

 protected:
  std::auto_ptr<ParentServiceHandler> syncHandler_;
};
