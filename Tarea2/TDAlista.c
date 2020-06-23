#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"
//lista1 memoria disponible
//lista2 memoria usada

void initList(tLista* lista,int tam){
    lista->curr=(tNodo *)malloc(sizeof(tNodo));
    lista->head=lista->curr;
    lista->tail=lista->curr;
    lista->tail->next=NULL;
    lista->listSize=tam;
    lista->pos=0;
}
int insert(tLista* lista, int item1, int item2){
    tNodo* aux=lista->curr->next;
    lista->curr->next=malloc(sizeof(tNodo));
    lista->curr->next->data1=item1;
    lista->curr->next->data2=item2;
    lista->curr->next->next=aux;
    if(lista->curr==lista->tail){
        lista->tail=lista->curr->next;
    }
    lista->listSize++;
    return lista->pos;
}
void move_to_head(tLista* lista){
    lista->curr=lista->head;
    lista->pos=0;
}
void move_to_tail(tLista* lista){
    lista->curr=lista->tail;
    lista->pos=lista->listSize-1;
}
int limpieza(tNodo* head){
    tNodo aux=lista->head->next;
    free(lista->head);
    if(aux==NULL){
        return 1;
    }
    limpieza(aux);
    return 0;
}
void clear(tLista* lista){
    return limpieza(lista->head);
}
int espacio(tLista* lista, int tam){
    return 1;
}
int search(tNodo* nodo, int dato){
    if(lista->head->dato1==dato){
        lista->curr=lista->head;
        return 1;
    }
    tNodo* aux=lista->head->next;
    else if(aux->dato1==dato){
        lista->curr->aux;
        return 1;
    }
    search(aux,dato);
    return 0;
}

int liberar(tLista* lista, int inicio){
    if(search(lista->head, inicio)==0){
        printf("no se encontro la Memoria\n");
        return 0;
    }
    if (lista->curr->next==NULL){

    }
}

int main(){
    return 0;
}
