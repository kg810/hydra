#ifndef STRAT_BASE_H
#define STRAT_BASE_H

#include "CedarJsonConfig.h"
#include "CPlusPlusCode/ProtoBufMsg.pb.h"
#include "ProtoBufMsgHub.h" 

class StratBase {
public:
  virtual int onMsg(MessageBase) = 0;

  template<typename T>
  int sendRequest(MsgType type, T &obj);
  int run();

private:
  std::string mode;
  ProtoBufMsgHub msgHub
  Backtester backtester;
};

#endif
