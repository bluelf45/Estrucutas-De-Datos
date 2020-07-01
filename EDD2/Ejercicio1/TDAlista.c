#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"
//lista1 memoria disponible
//lista2 memoria usada
tNodo* centinela;
/*****
* int move_next
******
* mueve lista->curr a la siguiente posicion, es decr, al siguiente nodo en la lista dada.
******
* Input:
* tLista* lista : Lista que queremos cambiar de posicion.
* .......
******
* Returns:
* int: Retorna 0 si no se logro, o si esta en la cabeza de la lista. Sino retorna 1 diciendo que se hizo correctamente.
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
* int contarBytes
******
* Esta funcion suma la cantidad de bytes que todavia estan asignados a la lista 2.
******
* Input:
* tLista* lista : Puntero que apunta a la lista 2, contiene todos los nodos asignados.
******
* Returns:
* int: Returna la suma de espacio asignado total.
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
* Iniciar una lista vacia sin nodos.
******
* Input:
* tLista* lista: Puntero a un espacio de memoria con tamaño = sizeof(tLista)
* .......
******
* Returns:
*  void: No retorna nada
*****/
void initList(tLista* lista){
    lista->curr = lista->head = lista->tail = (tNodo *)malloc(sizeof(tNodo));
    lista->tail->next=NULL;
    lista->listSize=0;
    lista->pos=0;
}

/*****
* void initNodo
******
* Inicia un nodo con los datos proporcionados.
******
* Input:
* tNodo* nodo = Espacio de memoria con tamaño de un nodo.
* int dato1 = Dato de inicio de memoria del nodo. (ej:byte 31)
* int dato2 = Dato final de memoria del nodo. (ej: byte 40)
******
* Returns:
* void: No retorna nada.
*****/
void initNodo(tNodo* nodo, int dato1, int dato2){
    nodo->data1=dato1;
    nodo->data2=dato2;
    nodo->next=NULL;
}

/*****
* void anterior
******
* Se mueve a la posicion anterior de la lista.
******
* Input:
* tLista* lista : Espacio de memoria de una lista.
******
* Returns:
* void: No retorna nada
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
* Inserta un nodo en la cabeza de la lista.
******
* Input:
* tLista* lista = Espacio de memoria de una lista.
* int data1=byte Inicio del nodo al que queremos insertar.
* int data2=byte Final del nodo al que queremos insertar.
******
* Returns:
* void: No retorna nada.
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
* Inserta un nodo en la posicion actual en la lista.
******
* Input:
* tLista* lista : Lista a la que le queremos insertar un nodo
* tNodo* nodo : Nodo que queremos insertar
******
* Returns:
* int: Retorna 0 ocurre un error y retorna 1 si se hizo correctamente.
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
* Remueve el nodo que tenga como byte de inicio a data1, sin quitarlo de la memoria.
******
* Input:
* tLista* lista: Puntero a la lista a la cual le queremos borrar un nodo.
* int data1 : Byte de inicio del nodo que queremos borrar.
******
* Returns:
* tNodo* temp : Retorna el nodo eliminado de la lista, sin borrar su espacio de memoria.
*****/
tNodo* remove2(tLista* lista,int data1){
   move_to_head(lista);
   tNodo* temp = lista->curr;
   if (lista->head->data1==data1){
     lista->head=temp->next;
     lista->listSize--;
     return temp;
   }
   tNodo* prev;
   while(temp!=NULL && temp->data1!=data1){
     prev=temp;
     temp=temp->next;
   }
   //queremos borrar temp->next
   prev->next=temp->next;
   lista->listSize--;
   return temp;
}

/*****
* void printlista
******
* Imprime la lista y luego te deja en la cabeza de la lista.
******
* Input:
* tLista lista : Puntero a una lista enlazada.
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
* Mueve curr a la cabeza de la lista.
******
* Input:
* tLista* lista : puntero a una lista enlazada
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
* Mueve curr a la cola de la lista.
******
* Input:
* tLista* lista : Puntero a una lista enlazada.
******
* Returns:
* void: No retorna nada
*****/
void move_to_tail(tLista* lista){
    lista->curr=lista->tail;
    lista->pos=lista->listSize-1;
}

/*****
* void clear
******
* funcion para eliminar completamente una lista
******
* Input:
* tLista* lista : lista enlazada a eliminar
******
* Returns:
* void no retorna nada
*****/
void clear(tLista* lista){
    tNodo* aux;
    lista->curr = lista->head;
    int i=0;
    while(lista->curr != NULL){
        aux = lista->curr->next;
        printf("%d",i);
        i++;
        free(lista->curr);
        lista->curr = aux;
    }
}

/*****
* int search
******
* Busca el nodo que tenga como data1 a el valor dato.
******
* Input:
* tLista* lista: Lista enlazada
* int dato : Dato que es el byte de incio
******
* Returns:
* int: Retorna 0 ocurre un error y 1 si funciono correctamente.
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
* void free2
******
* se encarga de liberar el espacio de memoria correspondiente al bloque comenzando en el byte solicitado, ademas,
  revisa si la memoria disponible se encuentra en bloques contiguos, de ser asi, los une
******
* Input:
* tLista* listaD: Lista enlazada del espacio disponible en la memoria
* tLista* listaU: Lista enlazada del espacio utilizado en la memoria
* int byte: byte donde comienza el bloque que se quiere liberar
******
* Returns:
* La funcion es void, no retorna nada
*****/
void free2(tLista* listaD, tLista* listaU, int byte){
    tNodo* aux=remove2(listaU,byte);
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
            }
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
* int bytesize: Entero que entrega el tamaño del bloque a asignar.
******
* Returns:
* int, retorna 0 si ocurre un error, y 1 funciono correctamente.
*****/
int malloc2(tLista* listaD, tLista* listaU, int bytesize){
    int aval, inicio;
    move_to_head(listaD);
    while(listaD->pos<listaD->listSize){
        aval = listaD->curr->data2 - listaD->curr->data1+1; //Calcula el espacio disponible
        if(aval >= bytesize){
            tNodo* aux2=(tNodo*)malloc(sizeof(tNodo));
            inicio = listaD->curr->data1;
            initNodo(aux2,inicio,inicio+bytesize);
            insert_nodo(listaU, aux2); //Fijarse como funcionaba el insert. || Esto lo añade a la lista 2.
            printf("Bloque de %i bytes asignado a partir del byte %i\n", bytesize, listaD->curr->data1);
            listaD->curr->data1 = inicio + bytesize; //Cambia el tamaño del nodo en la lista 1.
            if (listaD->curr->data1 >= listaD->curr->data2){ //Se Fija si el tamaño del espacio ocupado es 0 o menor que. Si es asi, quita este nodo.
                free(remove2(listaD, listaD->curr->data1)); //<-------------- Fijate en esta
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
* Retorna el tamaño de la lista.
******
* Input:
* tLista* lista : Puntero a una lista enlazada.
* .......
******
* Returns:
* int: Retorna list->listSize, el cual es el tamaño de la lista.
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
