/* Imports and libraries */
#include "cliente.h"
#include <cstdio>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>


/*
 * Imports
 * */
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
    /*sockaddr_in addr;
    char buffer[1000]; // envia datos en forma de string
    int cliente = socket(AF_INET, SOCK_STREAM, 0);
    */
    int Client(){
        /* Creating socket for client */
        struct sockaddr_in direccionServidor;
        char buffer[1024] = {0};
        direccionServidor.sin_family = AF_INET;
        direccionServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
        direccionServidor.sin_port = htons(8080);
        unsigned int sizeDir;
        /* Creating socket for client */
        int cliente = socket(AF_INET, SOCK_STREAM, 0);
        int servidor = accept(cliente,(sockaddr *) &direccionServidor, &sizeDir);
        /* Conditional in case of an error */
        if (connect(cliente, (sockaddr*) &direccionServidor, sizeof(direccionServidor)) != 0)
        {
            perror("Impossible to connect");
            return 1;
        }
        else{
            cout<<"Connection established successfully"<<endl;
        }
    }
    void SendString(char *message){
        cout<<"este es el mensaje a enviar: "<<message<<endl;
        /* The information is sent to the server by the message */
        send(cliente, message, sizeof(message), 0);
        cout << "Mensaje enviado!" << endl;
    }
    void Receive(){
        /* The received information is saved in the buffer */
        recv(cliente, buffer, sizeof(buffer), 0);
        cout << "El servidor dice: " << buffer << endl;
        memset(buffer, 0, sizeof(buffer));

        // agregar logica del algotitmo floyd
    }

};
