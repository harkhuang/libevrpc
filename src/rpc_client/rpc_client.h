/***************************************************************************
 *
 * Copyright (c) 2015 aishuyu, Inc. All Rights Reserved
 *
 **************************************************************************/



/**
 * @file rpc_client.h
 * @author aishuyu(asy5178@163.com)
 * @date 2015/09/10 17:43:49
 * @brief
 *
 **/




#ifndef __RPC_CLIENT_H
#define __RPC_CLIENT_H

#include "rpc_channel.h"

#include <string>

#include "rpc_heartbeat_client.h"
#include "config_parser/config_parser.h"

namespace libevrpc {

class RpcClient {
    public:
        RpcClient(const std::string& config_file = "../conf/libevrpc.ini");
        virtual ~RpcClient();

        bool OpenRpcAsyncMode();
        bool GetAsyncResponse(const std::string& method_name, google::protobuf::Message* response);
        bool SetRpcConnectionInfo(int32_t rpc_timeout, int32_t try_time = 1);
        google::protobuf::RpcController* Status();

        bool IsCallOk();
        std::string GetErrorInfo() const;

    protected:
        bool InitClient();

        Channel* GetRpcChannel();

    private:
        /*
         * rpc channel: communication with server
         */
        Channel* rpc_channel_ptr_;
        /*
         *controll the rpc client action
         */
        google::protobuf::RpcController* rpc_controller_ptr_;
        /*
         *
         */
        RpcHeartbeatClient* rpc_heartbeat_ptr_;;
        /*
         * when init, read config from config file
         */
        ConfigParser& config_parser_instance_;



};

}  // end of namespace libevrpc



#endif // __RPC_CLIENT_H



/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
