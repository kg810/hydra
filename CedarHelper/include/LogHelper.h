#ifndef LOG_HELPER_H
#define LOG_HELPER_H

#include <json/json.h>
#include "CPlusPlusCode/ProtoBufMsg.pb.h"
#include "EnumStringMap.h"

#define LOG_TAG_HEADER "<<<"
#define LOG_TAG_FOOTER ">>>"

class LogHelper {
public:
  static bool logObject(ResponseMessage &rsp) {
    Json::Value jMsg;
    jMsg["cedar_msg_type"] = EnumToString::toString(TYPE_RESPONSE_MSG);
    jMsg["id"] = rsp.id();
    jMsg["ref_id"] = rsp.ref_id();
    jMsg["type"] = EnumToString::toString(rsp.type());
    jMsg["trade_quantity"] = rsp.trade_quantity();
    jMsg["error_code"] = rsp.error_code();
    jMsg["error_msg"] = rsp.error_msg();

    toLogFile(jMsg);
    return true;
  }

  static bool logObject(OrderRequest &req) {
    return true;
  }

private:
  static inline void toLogFile(Json::Value &jMsg) {
    static Json::StreamWriterBuilder builder;
    builder.settings_["indentation"] = "";
    LOG(INFO) << LOG_TAG_HEADER
      << Json::writeString(builder, jMsg) << LOG_TAG_FOOTER;
  }

};

#endif