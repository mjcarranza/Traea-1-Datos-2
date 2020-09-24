// Created by mario on 18/9/20.
//
//---------------------------------------------------------------
/*
 * Libraries
 */
#include "Grafo.h"
//----------------------------------------------------------------
/*
 * Initializing a new graph.
 */
int contador=0;
void Graph::init(){
    head=NULL;
}
// Function for defining if the graph is empty or not.
bool Graph::empty() {
    if (head == NULL){
        return true;
    }
    else{
        return false;
    }
}


// Function for getting an existing node.
// usar este para que obtenga todos lo nodos y los agregue a la matriz
Vertice *Graph::GetVertice(string nombre) {
    Vertice *aux;
    aux = head;
    while (aux != NULL){ // while aux is not pointing to null..
        if (aux->nombre == nombre){ // if aux`s name is equals to the parameter name, the searched node was found
            return aux;
        }
        aux = aux->next; // if the current node does`n match the searched node, continue with the next one
    }
    return NULL;
}
/*
 * Method for inserting a new node
 */
void Graph::insert_vertice(string nombre) {
    Vertice *nuevo = new Vertice; // Define a pointer for the new node
    nuevo->nombre = nombre; // Assign name to the new node
    nuevo->next = NULL;
    nuevo->ady = NULL;

    if (empty()){ // If the graph is empty the new node is going to be the first one on the graph
        head = nuevo;
    }
    else{ //If the graph is`n empty...
        Vertice *aux;
        aux = head;
        while (aux->next != NULL){ // Look for the last node of the graph
            aux = aux->next;
        }
        aux->next = nuevo; // Once the last node is found, its pointer changes from NULL to the new node inserted
        contador+=1;
    }
}
// inserting arista
void Graph::insert_arista(Vertice *origen, Vertice *destino, int peso) {
    Arista *nueva = new Arista;
    nueva->peso = peso;
    nueva->next = NULL;
    nueva->Adyacente = NULL;

    Arista *aux;
    aux = origen->ady;

    if (aux == NULL){
        origen->ady = nueva;
        nueva->Adyacente = destino;
    }
    else{
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = nueva;
        nueva->Adyacente = destino;
    }
}

// modificar para hacer que se obtengan las aristas de cada nodo y pasarlo a la matriz
// en lugar de imprimirlas.
void Graph::ady_list() {
    Vertice *VertAux; //puntero de tipo vertice
    Arista *ArisAux; //puntero de tipo arista
    VertAux = head; //asign valor a variable vertice
    while (VertAux != NULL){ //mientras la cabeza exista imprime la lista de adyacencia de cada nodo
        cout<<VertAux->nombre<<"->"; //imprimo el nombre del vertice cabeza actual
        ArisAux = VertAux->ady;
        while (ArisAux != NULL){// imprime la lista de adyacencia del nodo actual
            cout<<ArisAux->Adyacente->nombre<<"->";
            ArisAux = ArisAux->next;
        }
        VertAux = VertAux->next;
        cout << endl;
    }
}
/*
 * Algoritmo de floyd-warshall
 * recibe de parametro la dimension de la matriz
 */
int Graph::floyd(int dim) {
    int matriz[contador][contador];

    // Se almacenan todas las aristas en la matriz
    for (int i=0; i<contador; i++){
        for (int j=0; j<contador; j++){
            matriz[i][j];
        }
    }

    // se le aplica el algoritmo de floyd-warshall a la matriz
    for (int k=0; k<contador; k++){ // pivote
        for (int i=0; i<contador; i++){
            for (int j=0; j<contador; j++){
                if (matriz[i][k] + matriz[k][j] < matriz[i][j]){
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                }
            }
        }
    }
    // retornar matriz para pasarsela al cliente y que la muestre
}