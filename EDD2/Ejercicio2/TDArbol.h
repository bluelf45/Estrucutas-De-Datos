#ifndef TDA_ARBOL_H
#define TDA_ARBOL_H
//nodo izquierdo menor al padre
//nodo derecho mayor al padre
//no pueden haber duplicados
typedef struct nodo{
    int dato;
    struct nodo *left;
    struct nodo *right;
}tNodo;

typedef struct {
    tNodo* raiz;
    int nElems;
} arbolBin;

void initArbol(arbolBin* arbol);
void initNodo(tNodo* nodo, int item);
void clearHelp(tNodo* nodo);
void clear(arbolBin* arbol);
tNodo* encontrarMax(tNodo* nodo);
tNodo* borrarHelp(tNodo* nodo, int item);
int Borrar(arbolBin* arbol, int item);
int Sucesor(arbolBin* arbol, int item, int u);
int sucesorHelp(tNodo* nodo, int item);
int insertHelp(tNodo* nodo, int item);
void insertar(arbolBin* arbol, int item);
void printPreNodo(tNodo* nodo);
void preorden(arbolBin* arbol);
#endif
