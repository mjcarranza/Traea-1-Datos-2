#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "Grafo.h"

using namespace std;

int main()
{
    // se inicializa el grafo
    Graph G;
    G.init();
    int opc, valArist;
    string buffer[1000];
    const char *opt;
    string ONodo;
    string DNodo;
    const char *Arist;

    // /////////////////////////////////////////////////////////////////////
    // se crea el servidor
    struct sockaddr_in server_dir; //
    server_dir.sin_family = AF_INET;
    server_dir.sin_addr.s_addr = INADDR_ANY;
    server_dir.sin_port = htons(8080);

    int servidor = socket(AF_INET, SOCK_STREAM, 0); // Create a new socket.

    int activado = 1;
    setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado)); // Set socket optname

    if (bind(servidor, (sockaddr *) &server_dir, sizeof(server_dir)) != 0) { // Condition in case of a Bind error
        perror("Bind Failed");
        return 1;
    }

    printf("Listening\n");
    listen(servidor, 100); // Max amount of clients allowed

    //------------------------------

    struct sockaddr_in client_dir;
    unsigned int sizeDir;
    int cliente = accept(servidor, (sockaddr *) &client_dir, &sizeDir);

    printf("Connection established in %d!!\n", cliente);
    send(cliente, "Hello client", 13, 0); // se envia un mensaje al cliente
    send(cliente, ":)\n", 4, 0);


    //------------------------------
    //string* buffer = reinterpret_cast<string *>(static_cast<char *>(malloc(1000))); // buffer size

    while (true) {
        int bytesRecibidos = recv(cliente, buffer, 1000, 0);
        cout<<"Info received!!";

        // conditional if client is disconnected
        if (bytesRecibidos <= 0) {
            perror("Client disconnected.");
            return 1;
        }


        buffer[bytesRecibidos] = '\0'; // lo recibido es almacenado en el buffer
        printf("I got %d bytes with %s\n", bytesRecibidos, buffer);

        buffer[0] = opt;
        buffer[1] = ONodo;
        buffer[2] = DNodo;
        buffer[3] = Arist;

        opc = atoi(opt); // paso el string que trae el buffer a valor numerico
        valArist = atoi(Arist); // paso el string que trae el buffer a valor numerico

        // ////////////////////////////////////////////////////
        do
        {
            switch(opc) // guardar en opc la opcion que viene en el array
            {
                // caso para ingresar un vertice al grafo
                case 1:
                {
                    cout<<"el nodo se ha insertado con exito";
                    G.insert_vertice(ONodo);
                    break;
                }
                    // caso para Ingresar arista
                case 2:
                {
                    if(G.empty())
                    {
                        cout<<"El grafo esta vacio"<<endl;
                    }
                    else
                    {
                        if(G.GetVertice(ONodo) == NULL || G.GetVertice(DNodo) == NULL)
                        {
                            cout<<"Uno de los vertices no es valido"<<endl;
                        }
                        else
                        {
                            cout<< "Arista inserted";
                            G.insert_arista(G.GetVertice(ONodo), G.GetVertice(DNodo), valArist);
                        }
                    }
                    break;
                }
                    // caso para Lista de adyacencia
                case 3:
                {
                    if(G.empty())
                    {
                        cout<<"El grafo esta vacio"<<endl;
                    }
                    else
                    {
                        G.ady_list();
                    }
                    break;
                }

                    // caso para salir de la aplicacion
                case 4:
                {
                    int dimension;
                    G.floyd(dimension);

                    // enviar el reultado del algoritmo al cliente y que este lo muestre en la Ui

                    break;
                }
                default:
                {
                    cout<<"Elija una opcion valida"<<endl;
                }
            }
        }
        while(opc > 0 && opc < 5);
    }
    free(buffer);
    return 0;
}