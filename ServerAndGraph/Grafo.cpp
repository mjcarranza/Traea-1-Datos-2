/* Created by mario on 18/9/20. */

/* Libraries */
#include "Grafo.h"
#define INF 99999999

/* Initializing a new graph. */
int contador=0;
int matriz[0][0];
void Graph::init(){
    head=NULL;
}
/* Method for defining if the graph is empty or not. */
bool Graph::empty() {
    if (head == NULL){
        return true;
    }
    else{
        return false;
    }
}

/* Method for inserting a new node */
void Graph::insert_vertice(string nombre) {
    Vertice *nuevo = new Vertice; /* Defining a pointer for the new node */
    nuevo->nombre = nombre; /* Assigning name to the new node */
    nuevo->next = NULL;
    nuevo->ady = NULL;

    if (empty()){ /* If the graph is empty the new node is going to be the first one on the graph */
        head = nuevo;
    }
    else{ /* If the graph is`n empty... */
        Vertice *aux;
        aux = head;
        contador+=1;
        while (aux->next != NULL){ /* Look for the last node of the graph */
            aux = aux->next;
        }
        aux->next = nuevo; /* Once the last node is found, its pointer changes from NULL to the new node inserted */
        contador+=1; /* Counter for knowing how many nodes are inserted */

    }
    cout<<"Node inserted successfully."<<endl;
}
/* inserting "aristas" */
void Graph::insert_arista(Vertice *origen, Vertice *destino, int peso) {
    /* Variables and assignations*/
    Arista *nueva = new Arista;
    nueva->peso = peso;
    nueva->next = NULL;
    nueva->Adyacente = NULL;
    Arista *aux;
    aux = origen->ady;
    /* If origin node does not have any arista */
    if (aux == NULL){
        origen->ady = nueva;
        nueva->Adyacente = destino;
    }
    /* If origin node does have arista */
    else{
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = nueva;
        nueva->Adyacente = destino;
    }
}

/* Method for getting an existing node. */
Vertice *Graph::GetVertice(string nombre) {
    Vertice *aux;
    aux = head;
    while (aux != NULL){ /* while aux is not pointing to null.. */
        if (aux->nombre == nombre){ /* If aux`s name is equals to the parameter name, the searched node was found */
            return aux;
        }
        aux = aux->next; /* If the current node does`n match the searched node, continue with the next one */
    }
    return NULL;
}

/* Method for getting graph`s weight. */
int Graph::matrix() {
    int cont = 0;
    Vertice *auxiliar; /* This is going to travel the hole graph */
    auxiliar = head;

    /* Counting the amount of nodes in the graph */
    while (auxiliar != NULL){ /* If auxiliar is not pointing to NULL, counter increases +1. */
        cont++;
        auxiliar = auxiliar->next;
    }

    /* Reestablishing auxiliar variable */
    auxiliar=head;
    /* Filling out the matrix with "arista" values */
    for (int i=0; i<cont; i++){
        for (int j=0; j<cont; j++){
            if (auxiliar == head || auxiliar == auxiliar->next){
                matriz[i][j] = 0;
                auxiliar = auxiliar->next;
            }
            else if (auxiliar->next == NULL){
                matriz[i][j] = INF;
                auxiliar = auxiliar->next;
            }
            else if (auxiliar->next != NULL){
                matriz[i][j] = auxiliar->ady->peso;
                auxiliar = auxiliar->next;
                cout<<"El valor insertado en la matriz es: "<<matriz[i][j];
            }
        }
    }
    /* Callling method for applying Floyd-Warshall`s algorithm */
    this->floyd(cont);
}


/* Floyd-Warshall algorithm (Param matrix size) */
int Graph::floyd(int dim) {

    /* Adding arist values to a matrix */
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
            matriz[i][j];
        }
    }

    /* Applying floyd-warshall`s algorithm to the matrix */
    for (int k=0; k<dim; k++){ /* k is the pivot */
        for (int i=0; i<dim; i++){
            for (int j=0; j<dim; j++){
                /* Floyd-Warshall algorithm */
                if (matriz[i][k] + matriz[k][j] < matriz[i][j]){
                    /* Updating matrix position */
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                } // End if
            } // End for
        } // End for
    } // End for
    return matrix();
}