#include <iostream>
#include "Grafo.h"

using namespace std;

int main()
{
    Graph G;
    G.init();
    int opc;


    //hacer funcion para que al presionar boton en Qt se ejecute esto
    G.insert_vertice("TIJ");
    G.insert_vertice("MTY");
    G.insert_vertice("MZT");
    G.insert_vertice("BJX");
    G.insert_vertice("GDL");
    G.insert_vertice("SAN");
    G.insert_vertice("TAM");
    G.insert_vertice("MEX");
    G.insert_vertice("CUN");
    G.insert_vertice("MID");

    // hacer funcion para que al presionar boton en Qt se ejecute esto
    G.insert_arista(G.GetVertice("TIJ"), G.GetVertice("MTY"), 800);
    G.insert_arista(G.GetVertice("MZT"), G.GetVertice("TIJ"), 400);
    G.insert_arista(G.GetVertice("MZT"), G.GetVertice("BJX"), 300);
    G.insert_arista(G.GetVertice("MTY"), G.GetVertice("BJX"), 700);
    G.insert_arista(G.GetVertice("BJX"), G.GetVertice("SAN"), 900);
    G.insert_arista(G.GetVertice("BJX"), G.GetVertice("TAM"), 400);
    G.insert_arista(G.GetVertice("BJX"), G.GetVertice("MEX"), 350);
    G.insert_arista(G.GetVertice("GDL"), G.GetVertice("MZT"), 500);
    G.insert_arista(G.GetVertice("GDL"), G.GetVertice("MTY"), 450);
    G.insert_arista(G.GetVertice("GDL"), G.GetVertice("BJX"), 250);
    G.insert_arista(G.GetVertice("GDL"), G.GetVertice("MEX"), 500);
    G.insert_arista(G.GetVertice("SAN"), G.GetVertice("MID"), 1200);
    G.insert_arista(G.GetVertice("TAM"), G.GetVertice("MID"), 450);
    G.insert_arista(G.GetVertice("MEX"), G.GetVertice("MID"), 450);
    G.insert_arista(G.GetVertice("MEX"), G.GetVertice("CUN"), 650);
    G.insert_arista(G.GetVertice("CUN"), G.GetVertice("GDL"), 650);

    do
    {
        //4system("cls");
        cout<<"1. Ingresar Vertice"<<endl;
        cout<<"2. Ingresar arista"<<endl;
        cout<<"3. Lista de adyacencia"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<endl<<"Elija una de las opciones anteriores: ";
        cin>>opc;
        switch(opc)
        {
            // caso para ingresar un vertice al grafo
            case 1:
            {
                string nombre;
                system("cls");
                cout<<"Ingrese el nombre del vertice: ";
                cin.ignore();
                getline(cin, nombre, '\n');
                G.insert_vertice(nombre);
                cin.get();
                cin.get();
                break;
            }
            // caso para Ingresar arista
            case 2:
            {
                string origen, destino;
                int peso;
                system("cls");
                if(G.empty())
                {
                    cout<<"El grafo esta vacio"<<endl;
                }
                else
                {
                    cout<<"Ingrese del nombre del vertice origen: ";
                    cin.ignore();
                    getline(cin, origen, '\n');
                    cout<<"Ingrese el nombre del vertice destino: ";
                    getline(cin, destino, '\n');
                    cout<<"Ingrese el peso: ";
                    cin>>peso;

                    if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                    {
                        cout<<"Uno de los vertices no es valido"<<endl;
                    }
                    else
                    {
                        G.insert_arista(G.GetVertice(origen), G.GetVertice(destino), peso);
                    }
                }
                cin.get();
                cin.get();
                break;
            }
            // caso para Lista de adyacencia
            case 3:
            {
                system("cls");
                if(G.empty())
                {
                    cout<<"El grafo esta vacio"<<endl;
                }
                else
                {
                    G.ady_list();
                }
                cin.get();
                cin.get();
                break;
            }

            // caso para salir de la aplicacion
            case 4:
            {
                break;
            }
            default:
            {
                cout<<"Elija una opcion valida"<<endl;
            }
        }
    }
    while(opc != 4);
    return 0;
}