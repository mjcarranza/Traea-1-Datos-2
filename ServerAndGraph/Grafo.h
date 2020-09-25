/* Created by mario on 19/9/20. */
 /* Libraries. */
#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H
#include <iostream>
using namespace std;

/* Arista class. */
class Arista;
/* defining Vertice class. */
class Vertice{
    /* Vertice attributes. */

    friend class Grafo;

public:
    Vertice *next;
    Arista *ady;
    string nombre;
};
/* Defining Arista class. */
class Arista{

    friend class Grafo;

public:
/* Arista attributes. */
    Arista *next;
    int peso;
    Vertice *Adyacente;
};
/* Defining Graph class. */
class Graph{
    Vertice *head; /* Graph`s head. */
/* Graph`s costructor. */
public:
    /* Graph`s functions. */
    void init();
    bool empty();
    Vertice *GetVertice(string nombre);
    void insert_arista(Vertice *origen, Vertice *destino, int peso);
    void insert_vertice(string nombre);
    int matrix();
    int floyd(int dimension);
};


#endif //GRAFO_GRAFO_H