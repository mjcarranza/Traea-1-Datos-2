/*
 * Imports
 * */
#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;
/*
 * Client class
 * */
class Cliente{
    /*
     * Defining Client`s friend class
     * */
    friend class cliente;
    /*
     * Public constructor
     * */
public:
    //sockaddr_in addr;
    char buffer[1000];
    int server = socket(AF_INET, SOCK_STREAM, 0);
    int Client();
    void SendString(char *message);
    void Receive();

};

#endif // CLIENTE_H
