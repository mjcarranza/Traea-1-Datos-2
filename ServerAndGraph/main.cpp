/* Created by mario on 18/9/20. */

/* Libraries */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "Grafo.h"

using namespace std;

/* Main method */
int main()
{
    /* Initializing a new graph */
    Graph G;
    G.init();

    /* Variables */
    char buffer[1024] = {0};
    int opt , Arist;
    string ONodo, DNodo;

    /* Creating server */
    struct sockaddr_in server_dir; //
    server_dir.sin_family = AF_INET;
    server_dir.sin_addr.s_addr = INADDR_ANY;
    server_dir.sin_port = htons(8080);

    /* Creating a new socket. */
    int servidor = socket(AF_INET, SOCK_STREAM, 0);
    int activado = 1;
    /* Set socket optname */
    setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado));

    /* Condition in case of a bind error */
    if (bind(servidor, (sockaddr *) &server_dir, sizeof(server_dir)) != 0) {
        perror("Bind Failed");
        return 1;
    }

    printf("Listening\n");
    listen(servidor, 100); /* Max amount of clients allowed */

    /* Accepting client`s connection */
    struct sockaddr_in client_dir;
    unsigned int sizeDir;
    int cliente = accept(servidor, (sockaddr *) &client_dir, &sizeDir);
    printf("Connection established in %d!!\n", cliente);
    send(cliente, "Hello client", 13, 0);
    send(cliente, ":)\n", 4, 0);

    /* Receiving information from client */
    int bytesRecibidos = recv(cliente, buffer, 1000, 0);
    cout<<"Info received!!";

    /* Conditional if client is disconnected */
    if (bytesRecibidos <= 0) {
        perror("Client disconnected.");
        return 1;
    }

    /* Catching information from buffer */




    opt = atoi(buffer);
    cout<<"La opcion recibida es: "<<opt<<endl;


    if (opt == 1){
        recv(cliente, buffer, 1000, 0);
        ONodo =buffer;
        cout<<"El nombre del Nodo origen es: "<<ONodo<< endl;
    }


    if (opt == 2){
        recv(cliente, buffer, 1000, 0);
        ONodo =buffer;
        cout<<"El nombre del Nodo origen es: "<<ONodo<< endl;

        recv(cliente, buffer, 1000, 0);
        DNodo =buffer;
        cout<<"El nombre del Nodo destino es: "<<DNodo<< endl;

        recv(cliente, buffer, 1000, 0);
        Arist = atoi(buffer);
        cout<<"El valor del arista es: "<<Arist<< endl;
    }



    /* Loop for managing the graph according to client`s petition */
    while (opt!=0 && opt!=4){
        if (opt == 1){
            /* Calling graph`s method */
            G.insert_vertice(ONodo);
            opt = 0;
        }
        else if (opt == 2){
            /* If graph is empty we cannot add an arista */
            if(G.empty())
            {
                cout<<"Graph is empty"<<endl;
            }
                /* If is not empty, we can insert a new arista */
            else
            {
                /* If one of the nodes does not exist we cannot insert the arista */
                if(G.GetVertice(ONodo) == nullptr || G.GetVertice(DNodo) == nullptr)
                {
                    cout<<"One of the nodes does not exist."<<endl;
                }
                    /* Inserting the arista */
                else
                {
                    /* Calling graph`s method */
                    G.insert_arista(G.GetVertice(ONodo), G.GetVertice(DNodo), Arist);
                }
            }
        }
        else if (opt == 3){
            /* Calling function to generate a matrix and then apply floyd-Warshall`s algorithm to it. */
            G.matrix();

            /* Sending matrix to client */
            send(cliente,buffer, 13, 0); // missing: pass matrix to buffer for it to be sent.

        }
    }

}