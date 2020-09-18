// Code for client
// Created by mario on 14/9/20.
//

/*
 * Libraries
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
/*
 * Defining main function
 */
int main(void) {
    // Defining server features...
    struct sockaddr_in direccionServidor;
    direccionServidor.sin_family = AF_INET;
    direccionServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
    direccionServidor.sin_port = htons(8080);
    /*
     * Creating socket for client
     */
    int cliente = socket(AF_INET, SOCK_STREAM, 0);
    /*
     * Conditional in case of error
     */
    if (connect(cliente, (sockaddr*) &direccionServidor, sizeof(direccionServidor)) != 0) {
        perror("No se pudo conectar");
        return 1;
    }
    /*
     * Loop for sending message to the server
     */
    while (1) {
        char mensaje[1000];
        scanf("%s", mensaje);

        send(cliente, mensaje, strlen(mensaje), 0);
    }

    return 0;
}