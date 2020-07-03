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
void clear(arbolBin* arbol){

}

void Borrar(arbolBin* arbol){

}

void Sucesor(arbolBin* arbol, int item){

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
}

int main(){
    int keys[] = {10, 6, 19, 8, 11};
    arbolBin* arbol=(arbolBin*)malloc(sizeof(arbolBin));
    initArbol(arbol);
    for (int i=0; i<5; i++){
        insertar(arbol,keys[i]);
    }
    preorden(arbol);
    printf("\n");
    return 0;
}
