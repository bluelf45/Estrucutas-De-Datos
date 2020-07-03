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
void clear(arbolBin* arbol);
void Borrar(arbolBin* arbol);
void Sucesor(arbolBin* arbol, int item);
int insertHelp(tNodo* nodo, int item);
void insertar(arbolBin* arbol, int item);
void printPreNodo(tNodo* nodo);
void preorden(arbolBin* arbol);
#endif
