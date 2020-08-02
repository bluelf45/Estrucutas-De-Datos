//MaxHeap usando tcolaP
#include <stdio.h>
#include <stdlib.h>
#include "TDAheap.h"

tcolaP* initColaP(int i){
    tcolaP* cola=(tcolaP*)malloc(sizeof(tcolaP));
    cola->array = (producto*)malloc(sizeof(producto)*(i+1));
    cola->array[0].cont = -1;
    cola->len = i+1;
    cola->tot = 0;
    return cola;
}

void clearColaP(tcolaP* P){
    free(P->array);
    free(P);
}

producto encontrarMax(tcolaP* cola){
    return cola->array[0];
}

int sizeColaP(tcolaP* cola){
    return cola->len;
}

void flotar(tcolaP* cola, int i){
    producto j;
    while (i>1 && cola->array[i].cont > cola->array[i/2].cont){
        j = cola->array[i];
        cola->array[i] = cola->array[i/2];
        cola->array[i/2] = j;
        i = i/2;
    }
}

void hundir(tcolaP* cola, int i){
    int max;
    producto j;
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

void insertarColaP(tcolaP* cola, producto x)
{
    cola->array[cola->tot+1] = x ;
    if (x.cont > cola->array[(cola->tot+1)/2].cont )
    {
        flotar(cola, (cola->tot + 1));
    }
}

producto removefirstColaP(tcolaP* p){
    producto j = encontrarMax(p);
    producto fin = p->array[p->tot + 1];
    p->array[1] = fin;
    p->tot-- ;

    if (p->array[2].cont > p->array[1].cont || p->array[3].cont > p->array[1].cont){
        hundir(p, 1);
    }
    return j;
}
