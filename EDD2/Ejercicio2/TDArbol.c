#include<stdio.h>
#include<stdlib.h>
#include "TDArbol.h"

void initArbol(arbolBin* arbol){
    arbol->raiz=NULL;
    arbol->nElems=0;
}

void initNodo(tNodo* nodo, int item){
    nodo->left=nodo->right=NULL;
    nodo->dato=item;
}

void clearHelp(tNodo* nodo){
    if(nodo==NULL){
        return;
    }
    clearHelp(nodo->left);
    clearHelp(nodo->right);
    free(nodo);
}

void clear(arbolBin* arbol){
    if (arbol->raiz==NULL){
        return;
    }
    clearHelp(arbol->raiz);
    arbol->raiz=NULL;
    arbol->nElems=0;
}

tNodo* encontrarMax(tNodo* nodo){
    while(nodo->right != NULL){
        nodo = nodo->right;
    }
    return nodo;
}

tNodo* borrarHelp(tNodo* nodo, int item){
    if(nodo == NULL){
        return NULL;
    }
    if(item < nodo->dato){
        nodo->left = borrarHelp(nodo->left, item);
    }
    else if(item > nodo->dato){
        nodo->right = borrarHelp(nodo->right, item);
    }
    else{
        // 0 Hijos
        if(nodo->left == NULL && nodo->right == NULL){
            free(nodo);
            return NULL;
            }

        // 1 Hijo
        else if(nodo->right == NULL || nodo->left == NULL){
            tNodo* aux;
            if(nodo->left == NULL){
                aux = nodo->right;
            }
            else {
                aux = nodo->left;
            }
            free(nodo);
            return aux;
        // 2 hijos
        } else{
            tNodo* aux = encontrarMax(nodo->left);
            nodo->dato = aux->dato;
            nodo->left = borrarHelp(nodo->left, aux->dato);
        }
    }
    return nodo;
}

int Borrar(arbolBin* arbol, int item){

    if(arbol->raiz == NULL){
        return 0;
    }
    else{
        borrarHelp(arbol->raiz, item);
        arbol->nElems--;
        return 1;
    }
}

int Sucesor(arbolBin* arbol, int item, int u){
    int aux;
    printf("item = %d\n", item);
    if(arbol->raiz==NULL){
        if (item<u){
            return u;
        }
        else {
            return -1;
        }
    }
    aux = sucesorHelp(arbol->raiz,item);
    if (aux == -1){
        return u;
    }
    else{
        return aux;
    }
}

int sucesorHelp(tNodo* nodo, int item){
    printf("nodo dato = %d\n", nodo->dato);
    if(nodo==NULL){
        return -1;
    }
    if (nodo->dato==item){
        if (nodo->right!=NULL){
            sucesorHelp(nodo->right, item);
        }
        else{
            return -1;
        }
    }
    else if (nodo->dato > item){
        if ( nodo->left == NULL || nodo->left->dato < item){
            return nodo->dato;
        }
        else if(nodo->left->dato > item || nodo->left->dato==item){
            sucesorHelp(nodo->left, item);
        }
    }
    else if (nodo->dato < item){
        if (nodo->right->dato > item){
            sucesorHelp(nodo->right, item);
        }
        else if(nodo->right == NULL || nodo->right->dato < item){
            return nodo->dato;
        }
        else if (nodo->dato < item && nodo->right == NULL){
            return -1;
        }
    }
    return nodo->dato;
}

int insertHelp(tNodo* nodo, int item){
    if(nodo->dato==item){
        return 0;
    }
    else if(nodo->dato < item){
        if(nodo->right==NULL){
            tNodo* NewNode=(tNodo*)malloc(sizeof(tNodo));
            initNodo(NewNode, item);
            nodo->right=NewNode;
            return 1;
        }
        else{
            insertHelp(nodo->right, item);
        }
    }
    else if(nodo->dato > item){
        if(nodo->left==NULL){
            tNodo* NewNode=(tNodo*)malloc(sizeof(tNodo));
            initNodo(NewNode, item);
            nodo->left=NewNode;
            return 1;
        }
        else{
            insertHelp(nodo->left, item);
        }
    }
    return 0;
}

void insertar(arbolBin* arbol, int item){
    if(arbol->raiz==NULL){
        tNodo* NewNode=(tNodo*)malloc(sizeof(tNodo));
        initNodo(NewNode, item);
        arbol->raiz=NewNode;
    }
    else if(insertHelp(arbol->raiz,item)==1){
        arbol->nElems++;
    }
}

void printPreNodo(tNodo* nodo){
    if(nodo==NULL){
        return;
    }
    printf("%d ",nodo->dato);
    printPreNodo(nodo->left);
    printPreNodo(nodo->right);
}

void preorden(arbolBin* arbol){
    printPreNodo(arbol->raiz);
    printf("\n");
}
