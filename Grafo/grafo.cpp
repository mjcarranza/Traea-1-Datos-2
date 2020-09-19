//
// Created by mario on 18/9/20.
//
//---------------------------------------------------------------
/*
 * Libraries
 */
#include "grafo.h"
//----------------------------------------------------------------
/*
 * Initializing a new graph.
 */
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

void Graph::ady_list() {
    Vertice *VertAux;
    Arista *ArisAux;
    VertAux = head;
    while (VertAux != NULL){
        cout<<VertAux->nombre<<"->";
        ArisAux = VertAux->ady;
        while (ArisAux != NULL){
            cout<<ArisAux->Adyacente->nombre<<"->";
            ArisAux = ArisAux->next;
        }
        VertAux = VertAux->next;
        cout << endl;
    }
}

void Graph::anular() {
    Vertice *aux;
    while (head != NULL){
        aux = head;
        head = head->next;
        delete (aux);
    }
}
void Graph::eliminar_arista(Vertice *origen, Vertice *destino) {
    int band = 0;
    Arista *actual, *anterior;
    actual = origen->ady;
    if (actual == NULL){
        cout << "el vertice origen no tiene aristas"<<endl;
    }
    else if (actual->Adyacente == destino){
        origen->ady == actual->next;
        delete (actual);
    }
    else{
        while (actual != NULL){
            if (actual->Adyacente == destino){
                band =1;
                anterior->next = actual->next;
                delete (actual);
                break;
            }
            anterior = actual;
            actual = actual->next;
        }
        if (band == 0){
            cout<<"esos dos vertices no estan conectados"<<endl;
        }
    }
}
void Graph::delete_vert(Vertice *vert) {
    Vertice *actual, *anterior;
    Arista *aux;

    actual = head;
    while (actual != NULL){
        aux = actual->ady;
        while (aux != NULL){
            if (aux->Adyacente == vert){
                eliminar_arista(actual, aux->Adyacente);
                break;
            }
            aux = aux->next;
        }
        actual = actual->next;
    }
    actual = head;
    if (head == vert){
        head = head->next;
        delete (actual);
    }
    else{
        while (actual != vert){
            anterior = actual;
            actual = actual->next;
        }
        anterior->next = actual->next;
        delete (actual);
    }
}