#ifndef TDA_LISTA_H
#define TDA_LISTA_H
typedef struct nodo {
    int data1;//inicio
    int data2;//final
    struct nodo* next;
} tNodo;
//lista1 memoria disponible
//lista2 memoria usada
typedef struct {
    tNodo* head;
    tNodo* tail;
    tNodo* curr;
    unsigned int listSize;
    unsigned int pos;
} tLista;
//retorna 1 si se hizo correctamente y 0 si no se logro

void initList(tLista* lista);
int insert(tLista* lista, int item1, int item2);//retorna posicion
void move_to_head(tLista* lista);
int clear(tLista lista);//eliminar la lista
int erase(tLista* lista, int tam);//borra cierto elemento
int espacio(tLista lista, int tam);//hay espacio en la lista?

#endif
