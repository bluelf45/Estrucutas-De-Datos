#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"
//lista1 memoria disponible
//lista2 memoria usada

void initList(tLista* lista){
    lista->curr=(tNodo *)malloc(sizeof(tNodo));
    lista->head=lista->curr;
    lista->tail=lista->curr;
    lista->listSize=0;
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

void limpieza(tNodo* head){
    tNodo aux=lista->head->next;
    free(lista->head);
    limpieza(aux);
}

void clear(tLista* lista){
    limpieza(lista->head);
}

int erase(tLista* lista, int tam){
    
}

int espacio(tLista* lista, int tam){
    return 1;
}

int main(){
    return 0;
}
