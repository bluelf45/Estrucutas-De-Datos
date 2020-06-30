#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"
//lista1 memoria disponible
//lista2 memoria usada

tNodo* centinela;//nodo para guardar posiciones globalmente, solo es usado en una funcion

/*****
* int move_next
******
* mueve lista->curr a la siguiente posicion, es decr, al siguiente nodo
******
* Input:
* tLista* lista : lista que queremos cambiar de posicion
* .......
******
* Returns:
* int, retorna 0 si no se logro, o si esta en la cabeza de la lista. Sino retorna 1 diciendo que se hizo correctamente
*****/
int move_next(tLista* lista){
    if(lista->curr->next!=NULL){
        lista->curr=lista->curr->next;
        lista->pos++;
        return 1;
    }
    else{
        return 0;
    }
}

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int  contarBytes (tLista* lista){
    move_to_head(lista);
    int cont = 0;
    for (int i = 0; i < lista->listSize; i++){
        cont += lista->curr->data2 - lista->curr->data1;
        move_next(lista);
    }
    return cont;
}

/*****
* void initList
******
* iniciar una lista vacia sin nodos 
******
* Input:
* tLista* lista: puntero a un espacio de memoria con tamaño = sizeof(tLista)
* .......
******
* Returns:
* void, no retorna nada
*****/
void initList(tLista* lista){
    lista->curr= malloc(sizeof(tNodo));
    lista->head=lista->curr;
    lista->tail=lista->curr;
    lista->tail->next=NULL;
    lista->listSize=0;
    lista->pos=0;
}

/*****
* void initNodo
******
* inicia un nodo con los datos proporcionados
******
* Input:
* tNodo* nodo = espacio de memoria con tamaño de un nodo
* int dato1 = dato de inicio de memoria del nodo (ej:byte 31)
* int dato2 = dato final de memoria del nodo (ej: byte 40)
******
* Returns:
* void no retorna nada
*****/
void initNodo(tNodo* nodo, int dato1, int dato2){
    nodo->data1=dato1;
    nodo->data2=dato2;
    nodo->next=NULL;
}

/*****
* void anterior
******
* se mueve a la posicion anterior de la lista
******
* Input:
* tLista* lista : espacio de memoria de una lista
* .......
******
* Returns:
* void no retorna nada
*****/
void anterior(tLista* lista){
    tNodo* aux=lista->curr;
    move_to_head(lista);
    while(1){
        if(lista->curr->next==aux){
            break;
        }
        move_next(lista);
    }
}

/*****
* void push
******
* inserta un nodo en la cabeza de la lista
******
* Input:
* tLista* lista = espacio de memoria de una lista
* int data1=byte inicio del nodo al que queremos insertar
* int data2=byte final del nodo al que queremos insertar
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* void no retorna nada
*****/
void push(tLista* lista,int data1,int data2){
  move_to_head(lista);
  tNodo* nodo=(tNodo*)malloc(sizeof(tNodo));
  nodo->data1=data1;
  nodo->data2=data2;
  nodo->next=lista->head;
  lista->head=nodo;
  lista->listSize++;
}

/*****
* int insert_nodo
******
* inserta un nodo en la posicion actual en la lista
******
* Input:
* tLista* lista : lista a la que le queremos insertar un nodo
* tNodo* nodo : nodo que queremos insertar
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* int retorna 0 si hubo algun error y retorna 1 si se hizo correctamente
*****/
int insert_nodo(tLista*lista,tNodo* nodo){
    if (nodo==NULL || lista==NULL){
        return 0;
    }
    //insert cabeza
    if(lista->head==lista->curr){
        nodo->next=lista->curr;
        lista->head=nodo;
    }
    //insert cola
    else if(lista->pos==lista->listSize){
        nodo->next=NULL;
        lista->tail->next=nodo;
        lista->tail=nodo;
    }
    //insert mitad
    else{
        nodo->next=lista->curr;
        anterior(lista);
        lista->curr->next=nodo;
        move_next(lista);
        move_next(lista);
    }
    lista->listSize++;
    return 1;
}

/*****
* tNodo* remove2
******
* remueve el nodo que tenga como byte de inicio a data1, sin quitarlo de la memoria
******
* Input:
* tLista* lista: puntero a la lista a la cual le queremos borrar un nodo
* int data1 : byte de inicio del nodo que queremos borrar
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* tNodo* temp : retorna el nodo eliminado de la lista, sin borrar su espacio de memoria
*****/
tNodo* remove2(tLista* lista,int data1){
   move_to_head(lista);
   tNodo* temp = lista->curr, *prev;
   if (lista->head->data1==data1){
     lista->head=temp->next;
     lista->listSize--;
     return temp;
   }
   while(temp->next!=NULL && temp->data1!=data1){
     prev=temp;
     temp=temp->next;
   }
   prev->next=temp->next;
   lista->listSize--;
   return temp;
}

/*****
* void print lista
******
* imprime la lista  y luego te deja en la cabeza de la lista
******
* Input:
* tLista lista : puntero a una lista enlazada
* .......
******
* Returns:
* void : no retorna nada
*****/
void printlista(tLista* lista){
  move_to_head(lista);
  int i=0;
  while(i<lista->listSize){
    printf("%d %d %d\n", i, lista->curr->data1, lista->curr->data2);
    lista->curr=lista->curr->next;
    i++;
  }
  move_to_head(lista);
}

/*****
* void move_to_head
******
* te mueve a la cabeza de la lista
******
* Input:
* tLista* lista : puntero a una lista enlazada
* .......
******
* Returns:
* void : no retorna nada
*****/
void move_to_head(tLista* lista){
    lista->curr=lista->head;
    lista->pos=0;
}

/*****
* void move_to_tail
******
* te mueve a la cola de la lista
******
* Input:
* tLista* lista : puntero a una lista enlazada
* .......
******
* Returns:
* void : no retorna nada
*****/
void move_to_tail(tLista* lista){
    lista->curr=lista->tail;
    lista->pos=lista->listSize-1;
}

/*****
* int limpieza
******
* borrar una lista recursivamente
******
* Input:
* tNodo* nodo : inicialmente la cabeza de la lista
* .......
******
* Returns:
* int 1 si se hizo correctamente y 0 de lo contrario
*****/
int limpieza(tNodo* nodo){
    tNodo* aux=nodo->next;
    free(nodo);
    if(aux==NULL){
        return 1;
    }
    limpieza(aux);
    return 0;
}

/*****
* int clear
******
* usa limpieza, esto debido a que no queriamos pasar un nodo para una funcion de limpieza, debido a que esto arruinaria e TDA
******
* Input:
* tLista* lista : lista enlazada a eliminar
* .......
******
* Returns:
* int, retorna 1 si se logro
*****/
int clear(tLista* lista){
    limpieza(lista->head);
    return 1;
}

/*****
* int search
******
* busca el nodo que tenga como data1 a el valor dato
******
* Input:
* tLista* lista: lista enlazada
* int dato : dato que es el byte de incio
* .......
******
* Returns:
* int, retorna 0 si no se hizo correctamente y 1 si funciono de maravilla
*****/
int search(tLista* lista, int dato){
    move_to_head(lista);
    while(lista->curr!=NULL){
        if(lista->curr->data1==dato){
            return 1;
        }
        else{
            centinela=lista->curr;
            lista->pos++;
            lista->curr=lista->curr->next;
        }
    }
    move_to_head(lista);
    return 0;
}

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
void free2(tLista* listaD, tLista* listaU, int byte){
    tNodo* aux = remove2(listaU,byte);
    int bytes = aux->data2 - aux->data1;
    move_to_head(listaD);
    while (listaD->curr->data2 < aux->data1){
        move_next(listaD);
    }
    if (listaD->pos==0){
        if (aux->data2 == listaD->curr->data1-1){
            listaD->curr->data1 = aux->data1;
        }
        else{
            move_to_head(listaD);
            insert_nodo(listaD, aux);
        }
    }
    else if (listaD->pos==listaD->listSize){
        if (aux->data1==listaD->curr->data2+1){
            listaD->curr->data2=aux->data2;
        }
        else{
            insert_nodo(listaD,aux);
        }
    }
    else{
        if (aux->data1==listaD->curr->data2+1){
            listaD->curr->data2=aux->data2;
            if (listaD->curr->data2==listaD->curr->next->data1-1){
                listaD->curr->data2 = listaD->curr->next->data1;
                tNodo* aux1 = remove2(listaD, listaD->curr->next->data1);
                free(aux1);

            }
            free(aux);
        }
        else if (aux->data2==listaD->curr->next->data1-1){
            listaD->curr->next->data1=aux->data1;
        }
        else{
            move_next(listaD);
            insert_nodo(listaD,aux);
        }
    }
    printf("Bloque de %d bytes liberado\n", bytes);
}

/*****
* int malloc2
******
* Esta funcion asigna nodos de memoria de tamaño "bytesize" a la lista 2, y reduce el tamaño
* de un nodo de la lista 1 si es que existen espacio disponible. 
* Input:
* tLista* ListaD: Puntero a la lista de disponible. 
* tLista* ListaU: Puntero a la lista de memoria usada.
* int bytesize: Entero que dice el tamaño del bloque a asignar.
******
* Returns:
* int, retorna 0 si se hizo corrrectamente la signacion, y 1 si lo hizo correcto.
*****/
int malloc2(tLista* listaD, tLista* listaU, int bytesize){
    int aval, inicio;
    tNodo* aux = (tNodo*)malloc(sizeof(tNodo));
    move_to_head(listaD);
    while(listaD->pos<listaD->listSize){
        aval = listaD->curr->data2 - listaD->curr->data1+1;
        if(aval >= bytesize){
            tNodo* aux2 = (tNodo*)malloc(sizeof(tNodo*));
            inicio = listaD->curr->data1;
            aux2->data1 = inicio;
            aux2->data2 = inicio + bytesize;
            insert_nodo(listaU, aux2); 
            printf("Bloque de %i bytes asignado a partir del byte %i\n", bytesize, listaD->curr->data1);
            listaD->curr->data1 = inicio + bytesize;
            if (listaD->curr->data1 >= listaD->curr->data2){
                aux = remove2(listaD, listaD->curr->data1); 
                free(aux);
            }
            return 1;
        }
        move_next(listaD);
    }
    printf("Bloque de %d bytes NO puede ser asignado\n",bytesize);
    return 0;
}

/*****
* int tamLista
******
* retorna el tamaño de la lista
******
* Input:
* tLista* lista : puntero a una lista enlazada
* .......
******
* Returns:
* int retorna list->listSize, el cual es el tamaño de la lista
*****/
int tamLista(tLista* lista){
    return lista->listSize;
}

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int bytesLib(tLista* lista){
    int count = 0;
    for (int i = 0; i < tamLista(lista); i++){
        count += lista->curr->data2 - lista->curr->data1;
        move_next(lista);
    }
    return count;
}
