//
// Created by sahar on 21/01/2020.
//

#ifndef UNTITLED_SERVER_H
#define UNTITLED_SERVER_H




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
