/*
 * Application`s Server
 */


/*
 * Libraries
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
 /*
  * Main method
  */
int main(void) {
    struct sockaddr_in server_dir; //
     server_dir.sin_family = AF_INET;
     server_dir.sin_addr.s_addr = INADDR_ANY;
     server_dir.sin_port = htons(8080);

    int servidor = socket(AF_INET, SOCK_STREAM, 0); // Create a new socket.

    int activado = 1;
    setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado)); // Set socket optname

    if (bind(servidor, (sockaddr *) &server_dir, sizeof(server_dir)) != 0) { // Condition in case of a Bind error
        perror("Falló el bind");
        return 1;
    }

    printf("Estoy escuchando\n");
    listen(servidor, 100); // Max amount of clients allowed

    //------------------------------

    struct sockaddr_in client_dir;
    unsigned int sizeDir;
    int cliente = accept(servidor, (sockaddr *) &client_dir, &sizeDir);

    printf("Recibí una conexión en %d!!\n", cliente);
    send(cliente, "Hola NetCat!", 13, 0);
    send(cliente, ":)\n", 4, 0);

    //------------------------------

    char* buffer = static_cast<char *>(malloc(1000));

    while (1) {
        int bytesRecibidos = recv(cliente, buffer, 1000, 0);
        if (bytesRecibidos <= 0) {
            perror("El cliente se ha desconectado.");
            return 1;
        }

        buffer[bytesRecibidos] = '\0';
        printf("Me llegaron %d bytes con %s\n", bytesRecibidos, buffer);
    }

    free(buffer);

    return 0;
}