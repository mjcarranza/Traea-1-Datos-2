/* Imports and libraries */
#include "cliente.h"
#include <cstdio>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>

int Cliente::Client(){
    /* Creating socket for client */
    struct sockaddr_in direccionServidor;
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
        printf("Connection established succesfully");
    }
}

/* Client method for sending information to the server */
void Cliente::SendString(string array[])
{
    /* The information is sent to the server by the buffer */
    array = this->buffer;
    send(server, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    cout << "Mensaje enviado!" << endl;
}

/* Client method for receiving information from server */
void Cliente::Receive()
{
    /* The received information is saved in the buffer */
    recv(server, buffer, sizeof(buffer), 0);
    cout << "El servidor dice: " << buffer << endl;
    memset(buffer, 0, sizeof(buffer));

    // agregar logica del algotitmo floyd
}























