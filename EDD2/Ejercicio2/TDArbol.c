#include<stdio.h>
#include<stdlib.h>
#include "TDArbol.h"
int i;
/*****
* void initArbol
******
* Inicia un arbol vacio
******
* Input:
* arbolBin* arbol : Puntero a un arbolBin para iniciar.
******
* Returns:
* Nada, es void
*****/
void initArbol(arbolBin* arbol){
    arbol->raiz=NULL;
    arbol->nElems=0;
}
/*****
* void initNodo
******
* Inicia un nodo con dato el item dado
******
* Input:
* tNodo* nodo : Puntero al nodo a inciar.
* int item : Dato a insertar en el nodo.
******
* Returns:
* Nada, es void
*****/

void initNodo(tNodo* nodo, int item){
    nodo->left=nodo->right=NULL;
    nodo->dato=item;
}
/*****
* void clearHelp
******
* Funcion usada para liberar un arbol entero, es usada para ayudar clear.
******
* Input:
* tNodo* nodo : Primero es la raiz del arbol y funciona recursivamente liberando todos los nodos.
******
* Returns:
* Nada, es void
*****/
void clearHelp(tNodo* nodo){
    if(nodo==NULL){
        return;
    }
    clearHelp(nodo->left);
    clearHelp(nodo->right);
    free(nodo);
}
/*****
* void clear
******
* Liberar un arbol dado.
******
* Input:
* arbolBin* arbol : Arbol para liberar/limpiar.
******
* Returns:
* Nada, es void.
*****/
void clear(arbolBin* arbol){
    if (arbol->raiz==NULL){
        return;
    }
    clearHelp(arbol->raiz);
    arbol->raiz=NULL;
    arbol->nElems=0;
}
/*****
* tNodo* encontrarMax
******
* Se mueve al extremo derecho del arbol para retornar el numero maximo.
******
* Input:
* tNodo* nodo: Nodo raiz del arbol.
******
* Returns:
* tNodo*: Retorna el nodo contenedor del numero maximo.
*****/
tNodo* encontrarMax(tNodo* nodo){
    while(nodo->right != NULL){
        nodo = nodo->right;
    }
    return nodo;
}
/*****
* void borrarHelp
******
* Ayuda a encontrar el nodo deseado en borrar y lo remueve del arbol.
******
* Input:
* tNodo* nodo : Primero es la raiz del arbol, luego es recursiva tomando todos los nodos hasta encontrar el nodo deseado.
* int item : Dato del nodo a eliminar.
******
* Returns:
* tNodo* :  Nodo eliminado del arbol.
*****/
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
/*****
* int Borrar
******
* Borra cierto item del ABB arbol.
******
* Input:
* arbolBin* arbol : Puntero al arbol al que le quieres borrar algo.
* int item : Dato del nodo que se desea eliminar.
******
* Returns:
* int: Retorna 0 si no se logro o 1 si se hizo correctamente.
*****/
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

/*****
* void sucesor
******
* Revisa si el item que le damos es mayor a cualquier elemento del arbol, y luego usa sucesorHelp.
******
* Input:
* arbolBin* arbol: Struct arbol sobre el cual se trabaja.
* int item: Numero entero al cual le estamos buscando el sucesor.
* int u: Cota superior del arbol y de los elementos a los que se les busca el sucesor.
******
* Returns:
* void: No retorna nada, hace print.
*****/
void Sucesor(arbolBin* arbol, int item, int u){
    i = 0;
    if(arbol->raiz!=NULL){
        if (encontrarMax(arbol->raiz)->dato < item){
            printf("%d \n", u);
        }
    }
    else{
        printf("%d \n", u);
    }
    sucesorHelp(arbol->raiz, item);
}
/*****
* void sucesorHelp
******
* Se encarga de hacer el proceso donde se busca el sucesor de cierto numero en el arbol, con un recorrido in orden.
******
* Input:
* tNodo* nodo: Nodo raiz del arbol.
* int item: Numero al cual se le busca sucesor.
******
* Returns:
* void: no retorna nada, hace return para salir de la recursividad.
*****/
void sucesorHelp(tNodo* nodo, int item){
    if (nodo == NULL){
        return;
    }
    sucesorHelp(nodo->left, item);
    if (nodo->dato > item && i == 0){
        printf ( "%d \n", nodo->dato);
        i = -1;
        return;
    }
    sucesorHelp(nodo->right, item);

}
/*****
* int insertHelp
******
* Funcion recursiva, parte desde la raiz hasta encontrar la posicion adecuda para insertar el nodo de dato item.
******
* Input:
* tNodo* nodo : Primero es la raiz del arbol, se usa para poder encontrar donde insertar el nodo
* int item : Item del nodo a insertar.
******
* Returns:
* int  : 1 si se logro y 0 si no se pudo.
*****/
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
/*****
* void insertar
******
* Funcion que usa insertHelp para poder insertar un nodo en el arbol.
******
* Input:
* arbolBin* arbol : Arbol al que se quiere insertar un nodo.
* int item : Item del nodo se quiere insertar.
******
* Returns:
* void: No retorna nada.
*****/
void insertar(arbolBin* arbol, int item){
    if(arbol->raiz==NULL){
        tNodo* NewNode=(tNodo*)malloc(sizeof(tNodo));
        initNodo(NewNode, item);
        arbol->raiz=NewNode;
        arbol->nElems++;
        return;
    }
    else if(insertHelp(arbol->raiz,item)==1){
        arbol->nElems++;
        return;
    }
}
/*****
* void printPreNodo
******
* Funcion recursiva para printear el arbon en preorden.
******
* Input:
* tNodo* nodo : Funcion recursiva, primer nodo es la raiz.
******
* Returns:
* void: No retorna nada.
*****/
void printPreNodo(tNodo* nodo){
    if(nodo==NULL){
        return;
    }
    printf("%d ",nodo->dato);
    printPreNodo(nodo->left);
    printPreNodo(nodo->right);
}
/*****
* void preorden
******
* Printear un arbol en preorden.
******
* Input:
* arbolBin* arbol : Arbol a printear.
******
* Returns:
* void: No retorna nada.
*****/
void preorden(arbolBin* arbol){
    printPreNodo(arbol->raiz);
    printf("\n");
}
