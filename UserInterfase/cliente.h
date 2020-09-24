#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

class Cliente{
    friend class cliente;
public:
    sockaddr_in addr;
    string buffer[1000]; // envia datos en forma de string
    int server = socket(AF_INET, SOCK_STREAM, 0);
    int Client();
    void EnviarString(string array[]);
    void Recibir();

};

#endif // CLIENTE_H
