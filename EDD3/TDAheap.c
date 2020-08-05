//MaxHeap usando tcolaP
#include <stdio.h>
#include <stdlib.h>
#include "TDAheap.h"


tcolaP* initColaP(int i, tcolaP* cola){
    cola->array = (producto2**)malloc(sizeof(producto2*)*(i+1));
    cola->len = i+1;
    cola->tot = 0;

    for(int j=0; j<cola->len; j++){
        cola->array[j]=(producto2*)malloc(sizeof(producto2));
        cola->array[j]->codigo_producto=-1;
        cola->array[j]->cont=-1;
        cola->array[j]->cantidadO=-1;
        cola->array[j]->CantidadPrecio=-1;
        cola->array[j]->nombre=NULL;
    }
    return cola;
}

void clearColaP(tcolaP* P){
    free(P->array[0]);
    for(int i=1; i < P->len; i++){
        free(P->array[i]);
    }
    free(P->array);
    free(P);
}

producto2* encontrarMax(tcolaP* cola){
    return cola->array[1];
}

int sizeColaP(tcolaP* cola){
    return cola->len;
}

void flotar(tcolaP* cola, int i){
    producto2* j;
    if (i==0){
        return;
    }
    if (cola->tot==0){
        return;
    }
    while (i > 1 && cola->array[i]->cont > cola->array[i/2]->cont){
        j = cola->array[i];
        cola->array[i] = cola->array[i/2];
        cola->array[i/2] = j;
        i = i/2;
    }
}

void hundir(tcolaP* cola, int i){
    int max;
    producto2* j;
    if (i==0){
        return;
    }
    if (cola->tot==0){
        return;
    }
    while (2*i + 1 <= cola->len && (cola->array[i]->cont < cola->array[2*i]->cont || cola->array[i]->cont < cola->array[2*i + 1]->cont)){
        if (cola->array[2*i]->cont > cola->array[2*i+1]->cont){
            max = 2*i;
        }
        else{
            max = 2*i + 1;
        }
        j = cola->array[i];
        cola->array[i] = cola->array[max];
        cola->array[max] = j;
        i = max;
    }
}

void insertarColaP(tcolaP* cola, int pos1, slotO *hashO, slotP *hashP){
    for (int i = 1; i < cola->tot+1; i++){
        if (cola->array[i]->codigo_producto == hashP[pos1].pro.codigo_producto){
            cola->array[i]->cantidadO ++;
            cola->array[i]->CantidadPrecio ++;
            int pos = search_P(hashP, hashP[pos1].pro.codigo_producto);
            cola->array[i]->cont = hashP[pos].pro.precio * cola->array[i]->CantidadPrecio;
            if (cola->array[i]->cont > cola->array[i/2]->cont){
                flotar(cola, i);
            }
            int posO = search_O(hashO, hashP[pos1].pro.codigo_producto);
            if (posO >=0){
                if (hashO[posO].ofer.cantidad_descuento == cola->array[i]->cantidadO){
                    cola->array[i]->cantidadO = 0;
                    cola->array[i]->cont = cola->array[i]->cont - hashO[posO].ofer.monto_descuento;
                    if (cola->array[i]->cont < cola->array[i*2]->cont || cola->array[i]->cont < cola->array[i*2+1]->cont){
                        hundir(cola, i);
                    }
                }
            }
            return; //retorna para no seguir con el codigo debajo del for
        }
    }

    cola->array[cola->tot+1]->codigo_producto = hashP[pos1].pro.codigo_producto;
    cola->array[cola->tot+1]->cont = hashP[pos1].pro.precio;
    cola->array[cola->tot+1]->nombre = hashP[pos1].pro.nombre_producto;
    cola->array[cola->tot+1]->cantidadO = 1;
    cola->array[cola->tot+1]->CantidadPrecio = 1;
    cola->tot++;
    if (hashP[pos1].pro.precio > cola->array[(cola->tot+1)/2]->cont ){
        flotar(cola, (cola->tot + 1));
    }
}

void resetCantOHeap(tcolaP* cola){
    for (int i = 0; i < cola->tot+1; i++){
        cola->array[i]->cantidadO = 0;
    }
}

producto2* removefirstColaP(tcolaP* p){
    producto2* j=(producto2*)malloc(sizeof(producto2));
    j->cantidadO = p->array[1]->cantidadO;
    j->CantidadPrecio = p->array[1]->CantidadPrecio;
    j->codigo_producto = p->array[1]->codigo_producto;
    j->cont = p->array[1]->cont;
    j->nombre = p->array[1]->nombre;
    producto2* fin = p->array[p->tot + 1];
    p->array[1]->cantidadO = fin->cantidadO;
    p->array[1]->CantidadPrecio = fin->CantidadPrecio;
    p->array[1]->codigo_producto = fin->codigo_producto;
    p->array[1]->cont = fin->cont;
    p->array[1]->nombre = fin->nombre;
    p->tot-- ;
    if (p->array[2]->cont > p->array[1]->cont || p->array[3]->cont > p->array[1]->cont){
        hundir(p, 1);
    }
    return j;
}

int buscarHeap(tcolaP* cola, int codigo){
    for(int c = 1; c < cola->len; c++){
        if (cola->array[c]->codigo_producto == codigo){
            return c;
        }
    }
    return 0;
}

producto2* creacionProduc(int pos, slotP* HT){
    producto2* producto=(producto2*)malloc(sizeof(producto2));
    producto->cantidadO = 0;
    producto->CantidadPrecio = 0;
    producto->codigo_producto = HT[pos].pro.codigo_producto;
    producto->cont = HT[pos].pro.precio;
    producto->nombre = HT[pos].pro.nombre_producto;
    return producto;
}
