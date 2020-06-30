#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"
//lista1 memoria disponible
//lista2 memoria usada
tNodo* centinela;

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
void initList(tLista* lista){
    lista->curr= malloc(sizeof(tNodo));
    lista->head=lista->curr;
    lista->tail=lista->curr;
    lista->tail->next=NULL;
    lista->listSize=0;
    lista->pos=0;
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
void initNodo(tNodo* nodo, int dato1, int dato2){
    nodo->data1=dato1;
    nodo->data2=dato2;
    nodo->next=NULL;
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
   //queremos borrar temp->next
   prev->next=temp->next;
   lista->listSize--;
   return temp;
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
void move_to_head(tLista* lista){
    lista->curr=lista->head;
    lista->pos=0;
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
void move_to_tail(tLista* lista){
    lista->curr=lista->tail;
    lista->pos=lista->listSize-1;
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
int clear(tLista* lista){
    limpieza(lista->head);
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
