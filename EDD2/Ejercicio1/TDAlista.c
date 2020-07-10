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
        cont += (lista->curr->data2 - lista->curr->data1)+1;
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
            return;
        }
        move_next(lista);
    }
}

/*****
* int insert_nodo
******
* Inserta un nodo en la posicion actual en la lista.
******
* Input:
* tLista* lista : Lista a la que le queremos insertar un nodo.
* tNodo* nodo : Nodo que queremos insertar.
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
void sort(tLista* lista){
    if(lista->listSize<=1 || lista==NULL){
        return;
    }
    move_to_head(lista);
    tNodo* temp1=lista->head;
    tNodo* temp2;
    int data1,data2;
    for(int i=0; i<lista->listSize; i++){
        for(int j=0;j<lista->listSize;j++){
            temp2=temp1->next;
            if(temp2->data1<temp1->data1){
                data1=temp1->data1;
                data2=temp1->data2;
                temp1->data1=temp2->data1;
                temp1->data2=temp2->data2;
                temp2->data1=data1;
                temp2->data2=data2;
            }
        }
        lista->curr=lista->curr->next;
        lista->pos++;
    }
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
    tNodo* prev;
    if(lista==NULL){
        return NULL;
    }
    if (lista->head->data1==data1){
        lista->head=lista->curr->next;
        lista->listSize--;
        return lista->curr;
    }
    while(lista->curr!=NULL && lista->curr->data1!=data1){
        prev=lista->curr;
        lista->curr=lista->curr->next;
    }
    //queremos borrar temp->next
    prev->next=lista->curr->next;
    lista->listSize--;
    return lista->curr;
}

/*****
* void move_to_pos
******
* Mueve el curr a la posicion deseada
******
* Input:
* tLista* lista : Puntero a una lista enlazada.
* int pos : Posicion a la cual queremos mover el curr.
******
* Returns:
* void : no retorna nada
*****/
void move_to_pos(tLista* lista, int pos){
    move_to_head(lista);
    lista->pos=0;
    for(int i=0; i<=pos; i++){
        lista->curr=lista->curr->next;
        lista->pos++;
    }
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
* tLista* lista: Lista enlazada.
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
* FILE* fp: Archivo en el cual se imprime el resultado.
******
* Returns:
* La funcion es void, no retorna nada
*****/
void free2(tLista* listaD, tLista* listaU, int byte, FILE* fp){
    tNodo* aux=remove2(listaU, byte); //Remueve el nodo de la lista de usados
    tNodo* removed;
    if(aux==NULL){
        printf("nodo no existe\n"); //Comprueba si se extrajo un nodo valido
        return;
    }
    int bytes = aux->data2 - aux->data1; //cantidad de bytes liberados
    move_to_head(listaD);
    if(listaD->listSize>0){
        if (aux->data1 > listaD->curr->data2){
            while (listaD->curr->next->data1 < aux->data1){
                move_next(listaD); //se mueve hasta el nodo "anterior" al espacio donde hay que insertar el nodo nuevo en la lista disponible
            }
        }
    }
    if(aux->data1!=0 && aux->data2!=0){
        insert_nodo(listaD, aux);
    }
    sort(listaD);
    move_to_head(listaD);
    while(listaD->curr != NULL){
        if(listaD->curr->next!=NULL){
            if (listaD->curr->data2 == listaD->curr->next->data1-1){
                listaD->curr->data2 = listaD->curr->next->data2;
                removed = remove2(listaD, listaD->curr->next->data1);
                free(removed);
                move_to_head(listaD);
            }
            else{
                move_next(listaD);
            }
        }
        else if(listaD->curr->next==NULL){
            break;
        }
    }
    fprintf(fp, "Bloque de %d bytes liberado\n", bytes+1);
}
/*****
* int malloc2
******
* Esta funcion asigna nodos de memoria de tamaño "bytesize" a la lista 2, y reduce el tamaño
* de un nodo de la lista 1 si es que existen espacio disponible.
* Input:
* tLista* ListaD: Puntero a la lista de memoria disponible.
* tLista* ListaU: Puntero a la lista de memoria usada.
* int bytesize: Entero que entrega el tamaño del bloque a asignar.
******
* Returns:
* int, retorna 0 si ocurre un error, y 1 funciono correctamente.
*****/
int malloc2(tLista* listaD, tLista* listaU, int bytesize, FILE* fp){
    int aval, inicio;
    move_to_head(listaD);
    while(listaD->pos < listaD->listSize){
        aval = listaD->curr->data2 - listaD->curr->data1+1; //Calcula el espacio disponible
        if(aval >= bytesize){
            tNodo* aux2=(tNodo*)malloc(sizeof(tNodo));
            inicio = listaD->curr->data1;
            initNodo(aux2,inicio,inicio+bytesize-1);
            move_to_head(listaU);
            insert_nodo(listaU, aux2); //Fijarse como funcionaba el insert. || Esto lo añade a la lista 2.
            fprintf(fp, "Bloque de %i bytes asignado a partir del byte %i\n", bytesize, listaD->curr->data1);
            listaD->curr->data1 = inicio + bytesize; //Cambia el tamaño del nodo en la lista 1.
            if (listaD->curr->data1 >= listaD->curr->data2){ //Se Fija si el tamaño del espacio ocupado es 0 o menor que. Si es asi, quita este nodo.
                free(remove2(listaD, listaD->curr->data1)); //<-------------- Fijate en esta
            }
            return 1;
        }
        else{
            move_next(listaD);
        }
    }
    fprintf(fp, "Bloque de %d bytes NO puede ser asignado\n", bytesize);
    return 0;
}

/*****
* int tamLista
******
* Retorna el tamaño de la lista.
******
* Input:
* tLista* lista : Puntero a una lista enlazada.
******
* Returns:
* int: Retorna list->listSize, el cual es el tamaño de la lista.
*****/
int tamLista(tLista* lista){
    return lista->listSize;
}
