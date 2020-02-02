

#ifndef UNTITLED_SERVER_H
#define UNTITLED_SERVER_H


#include "server_side.h"

namespace server_side {

    class Server : public ClientHandler {
    public:
        Server() = default;
        virtual ~Server()= default;

        virtual void open(int port) = 0;
        virtual bool stop() = 0;
    };

}
#endif //UNTITLED_SERVER_H
