/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "SecondService.h"
#ifndef SecondService_TCC
#define SecondService_TCC

#include "thrift/async/TAsyncChannel.h"

namespace thrift { namespace test {

template <class Protocol_>
uint32_t SecondService_blahBlah_args::read(Protocol_* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

template <class Protocol_>
uint32_t SecondService_blahBlah_args::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("SecondService_blahBlah_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
uint32_t SecondService_blahBlah_pargs::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("SecondService_blahBlah_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
uint32_t SecondService_blahBlah_result::read(Protocol_* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

template <class Protocol_>
uint32_t SecondService_blahBlah_result::write(Protocol_* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("SecondService_blahBlah_result");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
uint32_t SecondService_blahBlah_presult::read(Protocol_* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

template <class Protocol_>
uint32_t SecondService_blahBlah_presult::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("SecondService_blahBlah_presult");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
void SecondServiceClientT<Protocol_>::blahBlah()
{
  send_blahBlah();
  recv_blahBlah();
}

template <class Protocol_>
void SecondServiceClientT<Protocol_>::send_blahBlah()
{
  int32_t cseqid = 0;
  this->oprot_->writeMessageBegin("blahBlah", ::apache::thrift::protocol::T_CALL, cseqid);

  SecondService_blahBlah_pargs args;
  args.write(this->oprot_);

  this->oprot_->writeMessageEnd();
  this->oprot_->getTransport()->writeEnd();
  this->oprot_->getTransport()->flush();
}

template <class Protocol_>
void SecondServiceClientT<Protocol_>::recv_blahBlah()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  this->iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(this->iprot_);
    this->iprot_->readMessageEnd();
    this->iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    this->iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    this->iprot_->readMessageEnd();
    this->iprot_->getTransport()->readEnd();
  }
  if (fname.compare("blahBlah") != 0) {
    this->iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    this->iprot_->readMessageEnd();
    this->iprot_->getTransport()->readEnd();
  }
  SecondService_blahBlah_presult result;
  result.read(this->iprot_);
  this->iprot_->readMessageEnd();
  this->iprot_->getTransport()->readEnd();

  return;
}

template <class Protocol_>
bool SecondServiceProcessorT<Protocol_>::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  typename ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second.generic))(seqid, iprot, oprot, callContext);
  return true;
}

template <class Protocol_>
bool SecondServiceProcessorT<Protocol_>::dispatchCallTemplated(Protocol_* iprot, Protocol_* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  typename ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second.specialized))(seqid, iprot, oprot, callContext);
  return true;
}

template <class Protocol_>
void SecondServiceProcessorT<Protocol_>::process_blahBlah(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("SecondService.blahBlah", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "SecondService.blahBlah");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "SecondService.blahBlah");
  }

  SecondService_blahBlah_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "SecondService.blahBlah", bytes);
  }

  SecondService_blahBlah_result result;
  try {
    iface_->blahBlah();
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "SecondService.blahBlah");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("blahBlah", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "SecondService.blahBlah");
  }

  oprot->writeMessageBegin("blahBlah", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "SecondService.blahBlah", bytes);
  }
}

template <class Protocol_>
void SecondServiceProcessorT<Protocol_>::process_blahBlah(int32_t seqid, Protocol_* iprot, Protocol_* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("SecondService.blahBlah", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "SecondService.blahBlah");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "SecondService.blahBlah");
  }

  SecondService_blahBlah_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "SecondService.blahBlah", bytes);
  }

  SecondService_blahBlah_result result;
  try {
    iface_->blahBlah();
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "SecondService.blahBlah");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("blahBlah", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "SecondService.blahBlah");
  }

  oprot->writeMessageBegin("blahBlah", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "SecondService.blahBlah", bytes);
  }
}

template <class Protocol_>
::boost::shared_ptr< ::apache::thrift::TProcessor > SecondServiceProcessorFactoryT<Protocol_>::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< SecondServiceIfFactory > cleanup(handlerFactory_);
  ::boost::shared_ptr< SecondServiceIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::boost::shared_ptr< ::apache::thrift::TProcessor > processor(new SecondServiceProcessorT<Protocol_>(handler));
  return processor;
}
template <class Protocol_>
void SecondServiceCobClientT<Protocol_>::blahBlah(std::tr1::function<void(SecondServiceCobClientT<Protocol_>* client)> cob)
{
  send_blahBlah();
  this->channel_->sendAndRecvMessage(std::tr1::bind(cob, this), this->otrans_.get(), this->itrans_.get());
}

template <class Protocol_>
void SecondServiceCobClientT<Protocol_>::send_blahBlah()
{
  int32_t cseqid = 0;
  this->oprot_->writeMessageBegin("blahBlah", ::apache::thrift::protocol::T_CALL, cseqid);

  SecondService_blahBlah_pargs args;
  args.write(this->oprot_);

  this->oprot_->writeMessageEnd();
  this->oprot_->getTransport()->writeEnd();
  this->oprot_->getTransport()->flush();
}

template <class Protocol_>
void SecondServiceCobClientT<Protocol_>::recv_blahBlah()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;
  bool completed = false;

  try {
    this->iprot_->readMessageBegin(fname, mtype, rseqid);
    if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
      ::apache::thrift::TApplicationException x;
      x.read(this->iprot_);
      this->iprot_->readMessageEnd();
      this->iprot_->getTransport()->readEnd();
      completed = true;
      completed__(true);
      throw x;
    }
    if (mtype != ::apache::thrift::protocol::T_REPLY) {
      this->iprot_->skip(::apache::thrift::protocol::T_STRUCT);
      this->iprot_->readMessageEnd();
      this->iprot_->getTransport()->readEnd();
      completed = true;
      completed__(false);
    }
    if (fname.compare("blahBlah") != 0) {
      this->iprot_->skip(::apache::thrift::protocol::T_STRUCT);
      this->iprot_->readMessageEnd();
      this->iprot_->getTransport()->readEnd();
      completed = true;
      completed__(false);
    }
    SecondService_blahBlah_presult result;
    result.read(this->iprot_);
    this->iprot_->readMessageEnd();
    this->iprot_->getTransport()->readEnd();

    completed = true;
    completed__(true);
    return;
  } catch (...) {
    if (!completed) {
      completed__(false);
    }
    throw;
  }
}

template <class Protocol_>
void SecondServiceAsyncProcessorT<Protocol_>::dispatchCall(std::tr1::function<void(bool ok)> cob, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid) {
  typename ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return cob(true);
  }
  (this->*(pfn->second.generic))(cob, seqid, iprot, oprot);
  return;
}

template <class Protocol_>
void SecondServiceAsyncProcessorT<Protocol_>::dispatchCallTemplated(std::tr1::function<void(bool ok)> cob, Protocol_* iprot, Protocol_* oprot, const std::string& fname, int32_t seqid) {
  typename ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return cob(true);
  }
  (this->*(pfn->second.specialized))(cob, seqid, iprot, oprot);
  return;
}

template <class Protocol_>
void SecondServiceAsyncProcessorT<Protocol_>::process_blahBlah(std::tr1::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot)
{
  Protocol_* _iprot = dynamic_cast<Protocol_*>(iprot);
  Protocol_* _oprot = dynamic_cast<Protocol_*>(oprot);
  if (_iprot && _oprot) {
    return process_blahBlah(cob, seqid, _iprot, _oprot);
  }
  T_GENERIC_PROTOCOL(this, iprot, _iprot);
  T_GENERIC_PROTOCOL(this, oprot, _oprot);

  SecondService_blahBlah_args args;
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("SecondService.blahBlah", NULL);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "SecondService.blahBlah");

  try {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->preRead(ctx, "SecondService.blahBlah");
    }
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->postRead(ctx, "SecondService.blahBlah", bytes);
    }
  }
  catch (const std::exception& exn) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "SecondService.blahBlah");
    }
    return cob(false);
  }
  freer.unregister();
  void (SecondServiceAsyncProcessorT<Protocol_>::*return_fn)(std::tr1::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx) =
    &SecondServiceAsyncProcessorT<Protocol_>::return_blahBlah;
  iface_->blahBlah(
      std::tr1::bind(return_fn, this, cob, seqid, oprot, ctx));
}

template <class Protocol_>
void SecondServiceAsyncProcessorT<Protocol_>::return_blahBlah(std::tr1::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx)
{
  Protocol_* _oprot = dynamic_cast<Protocol_*>(oprot);
  if (_oprot) {
    return return_blahBlah(cob, seqid, _oprot, ctx);
  }
  T_GENERIC_PROTOCOL(this, oprot, _oprot);

  SecondService_blahBlah_presult result;

  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("SecondService.blahBlah", NULL);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "SecondService.blahBlah");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "SecondService.blahBlah");
  }

  oprot->writeMessageBegin("blahBlah", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  uint32_t bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();
  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "SecondService.blahBlah", bytes);
  }
  return cob(true);
}

template <class Protocol_>
void SecondServiceAsyncProcessorT<Protocol_>::process_blahBlah(std::tr1::function<void(bool ok)> cob, int32_t seqid, Protocol_* iprot, Protocol_* oprot)
{
  SecondService_blahBlah_args args;
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("SecondService.blahBlah", NULL);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "SecondService.blahBlah");

  try {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->preRead(ctx, "SecondService.blahBlah");
    }
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->postRead(ctx, "SecondService.blahBlah", bytes);
    }
  }
  catch (const std::exception& exn) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "SecondService.blahBlah");
    }
    return cob(false);
  }
  freer.unregister();
  void (SecondServiceAsyncProcessorT<Protocol_>::*return_fn)(std::tr1::function<void(bool ok)> cob, int32_t seqid, Protocol_* oprot, void* ctx) =
    &SecondServiceAsyncProcessorT<Protocol_>::return_blahBlah;
  iface_->blahBlah(
      std::tr1::bind(return_fn, this, cob, seqid, oprot, ctx));
}

template <class Protocol_>
void SecondServiceAsyncProcessorT<Protocol_>::return_blahBlah(std::tr1::function<void(bool ok)> cob, int32_t seqid, Protocol_* oprot, void* ctx)
{
  SecondService_blahBlah_presult result;

  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("SecondService.blahBlah", NULL);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "SecondService.blahBlah");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "SecondService.blahBlah");
  }

  oprot->writeMessageBegin("blahBlah", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  uint32_t bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();
  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "SecondService.blahBlah", bytes);
  }
  return cob(true);
}

template <class Protocol_>
::boost::shared_ptr< ::apache::thrift::async::TAsyncProcessor > SecondServiceAsyncProcessorFactoryT<Protocol_>::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< SecondServiceCobSvIfFactory > cleanup(handlerFactory_);
  ::boost::shared_ptr< SecondServiceCobSvIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::boost::shared_ptr< ::apache::thrift::async::TAsyncProcessor > processor(new SecondServiceAsyncProcessorT<Protocol_>(handler));
  return processor;
}
}} // namespace

#endif
