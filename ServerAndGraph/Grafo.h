//
// Created by mario on 19/9/20.
//

#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H

#include <iostream>
using namespace std;

//
class Arista;
// defining Vertice class.
class Vertice{
    //Vertice attributes.

    friend class Grafo;

public:
    Vertice *next;
    Arista *ady;
    string nombre;
};
// Defining Arista class.
class Arista{

    friend class Grafo;

public:
// Arista attributes.
    Arista *next;
    int peso;
    Vertice *Adyacente;
};
// Defining Graph class.
class Graph{
    Vertice *head; //Graph`s head.
// Graph`s functions.
public:
    void init();
    bool empty();
    Vertice *GetVertice(string nombre);
    void insert_arista(Vertice *origen, Vertice *destino, int peso);
    void insert_vertice(string nombre);
    void ady_list();
    int contNodo();
    int floyd(int numero);
};


#endif //GRAFO_GRAFO_H