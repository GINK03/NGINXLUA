// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Control.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::C;

class ControlHandler : virtual public ControlIf {
 public:
  ControlHandler() {
    // Your initialization goes here
  }

  int32_t ping() {
    // Your implementation goes here
    printf("ping\n");
  }

  void tSet(std::string& _return, const int32_t json) {
    // Your implementation goes here
    printf("tSet\n");
  }

  void tSetOpt(std::string& _return, const std::string& json, const std::string& opt) {
    // Your implementation goes here
    printf("tSetOpt\n");
  }

  void tGet(std::string& _return, const std::string& json) {
    // Your implementation goes here
    printf("tGet\n");
  }

  void tGetOpt(std::string& _return, const std::string& json, const std::string& opt) {
    // Your implementation goes here
    printf("tGetOpt\n");
  }

  void tTune(std::string& _return, const std::string& json) {
    // Your implementation goes here
    printf("tTune\n");
  }

  void tTuneOpt(std::string& _return, const std::string& json, const std::string& opt) {
    // Your implementation goes here
    printf("tTuneOpt\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<ControlHandler> handler(new ControlHandler());
  shared_ptr<TProcessor> processor(new ControlProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
