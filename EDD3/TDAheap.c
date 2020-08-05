//MaxHeap usando tcolaP
#include <stdio.h>
#include <stdlib.h>
#include "TDAheap.h"
#include "hashingO.h"
#include "hashingP.h"

tcolaP* initColaP(int i){
    tcolaP* cola=(tcolaP*)malloc(sizeof(tcolaP));
    cola->array = (producto2*)malloc(sizeof(producto2)*(i+1));
    cola->array[0].cont = -1;
    cola->len = i+1;
    cola->tot = 0;
    return cola;
}

void clearColaP(tcolaP* P){
    free(P->array);
    free(P);
}

producto2 encontrarMax(tcolaP* cola){
    return cola->array[0];
}

int sizeColaP(tcolaP* cola){
    return cola->len;
}

void flotar(tcolaP* cola, int i){
    producto2 j;
    while (i>1 && cola->array[i].cont > cola->array[i/2].cont){
        j = cola->array[i];
        cola->array[i] = cola->array[i/2];
        cola->array[i/2] = j;
        i = i/2;
    }
}

void hundir(tcolaP* cola, int i){
    int max;
    producto2 j;
    while (2*i <= cola->len && (cola->array[i].cont < cola->array[2*i].cont || cola->array[i].cont < cola->array[2*i + 1].cont)){
        if (cola->array[2*i].cont > cola->array[2*i+1].cont){
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

void insertarColaP(tcolaP* cola, producto2 x, slotO *hashO, slotP *hashP){
    for (int i = 1; i < cola->tot+1; i++){
        if (cola->array[i].codigo_producto == x.codigo_producto){
            cola->array[i].cantidadO ++;
            cola->array[i].CantidadPrecio ++;
            int pos = search_P(hashP, x.codigo_producto);
            cola->array[i].cont = hashP[pos].pro.precio * cola->array[i].CantidadPrecio;
            if (cola->array[i].cont > cola->array[i/2].cont){
                flotar(cola, i);
            }
            int posO = search_O(hashO, x.codigo_producto);
            if (posO >=0){
                if (hashO[posO].ofer.cantidad_descuento == cola->array[i].cantidadO){
                    cola->array[i].cantidadO = 0;
                    cola->array[i].cont = cola->array[i].cont - hashO[posO].ofer.monto_descuento;
                    if (cola->array[i].cont < cola->array[i*2].cont || cola->array[i].cont < cola->array[i*2+1].cont){
                        hundir(cola, i);
                    }
                }
            }
            return; //retorna para no seguir con el codigo debajo del for
        }
    }

    cola->array[cola->tot+1] = x ;
    cola->array[cola->tot+1].cantidadO = 1;
    cola->array[cola->tot+1].CantidadPrecio = 1;
    if (x.cont > cola->array[(cola->tot+1)/2].cont ){
        flotar(cola, (cola->tot + 1));
    }
}

void resetCantOHeap(tcolaP* cola){
    for (int i = 0; i < cola->tot+1; i++){
        cola->array[i].cantidadO = 0;
    } 
}

producto2 removefirstColaP(tcolaP* p){
    producto2 j = encontrarMax(p);
    producto2 fin = p->array[p->tot + 1];
    p->array[1] = fin;
    p->tot-- ;

    if (p->array[2].cont > p->array[1].cont || p->array[3].cont > p->array[1].cont){
        hundir(p, 1);
    }
    return j;
}

int buscarHeap(tcolaP* cola, int codigo){
    for(int c = 1; c < cola->len; c++){
        if (cola->array[c].codigo_producto == codigo){
            return c;
        }
    }
    return 0;
}
producto2 creacionProduc(int pos, slotP* HT){
    producto2 producto;
    producto.cantidadO = 0
    producto.CantidadPrecio = 0;
    producto.codigo_producto = HT[pos].pro.codigo_producto;
    producto.cont = HT[pos].pro.precio;
    producto.nombre = HT[pos].pro.nombre_producto;
    return producto;
}
void sumarElemHeap(tcolaP* heap, int c, int cant, int cont){
    heap->array[c].cantidad += cant;
    heap->array[c].cont += cont;
    if (heap->array[c].cont > heap->array[c/2].cont){
        flotar(heap, c);
    }
}
