#include "cliente.h"
#include <cstdio>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>

int Cliente::Client(){
    /*
     * Creating socket for client
     */
    struct sockaddr_in direccionServidor;

    direccionServidor.sin_family = AF_INET;
    direccionServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
    direccionServidor.sin_port = htons(8080);
    unsigned int sizeDir;
    /*
     * Creating socket for client
     */
    int cliente = socket(AF_INET, SOCK_STREAM, 0);
    int servidor = accept(cliente,(sockaddr *) &direccionServidor, &sizeDir);
    /*
     * Conditional in case of error
     */
    if (connect(cliente, (sockaddr*) &direccionServidor, sizeof(direccionServidor)) != 0)
    {
        perror("No se pudo conectar");
        return 1;
    }
    else{
        printf("conexion establecida");
    }
}


void Cliente::EnviarString(string array[])
{
    array = this->buffer; // se le pasa la cadena de texto al buffer para que este lo envie al servidor
    send(server, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    cout << "Mensaje enviado!" << endl;
}
void Cliente::Recibir()
{
    recv(server, buffer, sizeof(buffer), 0);
    cout << "El servidor dice: " << buffer << endl;
    memset(buffer, 0, sizeof(buffer));

    // agregar logica del algotitmo floyd
}
