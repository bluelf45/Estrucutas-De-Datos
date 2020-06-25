#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"
//lista1 memoria disponible
//lista2 memoria usada
tNodo* centinela;
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
void initList(tLista* lista,int tam){
    lista->curr=(tNodo *)malloc(sizeof(tNodo));
    lista->head=lista->curr;
    lista->tail=lista->curr;
    lista->tail->next=NULL;
    lista->listSize=tam;
    lista->pos=0;
}
int remove(tLista* lista,int data1){
    search(lista,data1);
    if(lista->curr==lista->tail){
        anterior(lista);
        free(lista->curr->next);
        lista->curr->next=NULL;
        lista->tail=lista->curr;
        lista->listSize-=1;
    }
    else if(lista->curr==lista->head){
        lista->
    }
}
void insert(tLista* lista, int data1,int data2,tLista* lista2){
    while(lista->curr->dato1<data1){
        move_next(lista);
    }
    if(lista->curr->dato1==data2+1){
        lista->curr->dato1=data1;
    }
    else if(lista->curr->dato2==data1-1){
        lista->curr->dato2=data2;
    }
    remove(lista,data1);
}


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
void move_to_head(tLista* lista){
    lista->curr=lista->head;
    lista->pos=0;
}
void move_to_tail(tLista* lista){
    lista->curr=lista->tail;
    lista->pos=lista->listSize-1;
}
int limpieza(tNodo* nodo){
    tNodo* aux=nodo->next;
    free(nodo);
    if(aux==NULL){
        return 1;
    }
    limpieza(aux);
    return 0;
}
int clear(tLista* lista){
    limpieza(lista->head);
    return 0;
}
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
//lista->a la que se eliminar
//lista2->a la que se le va a agregar
//en proceso
/*int free2(tlista* lista, int inicio,tista* lista2){
    if(search(lista, inicio)==0){
        return 0;
    };
    //quitar cola
    verificar_espacio()
    if (lista->curr->next==NULL){
        free(lista->curr);
        lista->tail=centinela;
        lista->tail=NULL
    }
    //quitar cabeza
    else if(lista->pos==0){
        lista->head=lista->curr->next;
        free(lista->curr);
    }
    //quitar entremedio
    else{
        centinela->next=lista->curr->next;
        free(lista->curr);
    }
}
*/
int main(){
    return 0;
}
