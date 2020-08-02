#include <stdio.h>
#include <stdlib.h>
#include "hashingO.h"

#define C1 3;

int Size=0;
int Max_size;


//llenar el arreglo de slots vacios con key=-1 y el flag=0
slotO* initArrayOfer(int Tam){
    slotO* arreglo=(slotO*)malloc(sizeof(oferta)*Tam);
    Max_size=Tam;
    for(int i=0; i<Tam; i++){
        arreglo[i].key=-1;
    }
    return arreglo;
}

int get_id_O(oferta oferta){
    return ofer.codigo_producto;
}

int get_cant_desc_O(oferta ofer){
    return ofer.cantidad_descuento;
}

int get_descuento_O(oferta ofer){
    return ofer.monto_descuento;
}

int h1(int k, int M){
    int hashVal;
    if (k == 0){
        return 0;
    }
    hashVal = (k<<3) ^ k;
    hashVal = (hashVal<<3) ^ k;
    hashVal = (hashVal<<3) ^ k;
    while (hashVal > M){
        hashVal = hashVal % M;
    }
    return hashVal;
}

int h2(int k, int i){
    if (i==0){
        return 0;
    }
    int final=k*C1;
    return final*k;
}

int p(int k, int i){
    return i*h2(k,i);
}

void insert_producto_O(slotO* arreglo, oferta ofer){
    int index1=h1(ofer.codigo_producto, Size);
    int pos=index1;
    if(arreglo[index1].key==-1){
        arreglo[index1].key=ofer.codigo_producto;
        arreglo[index1].ofer=ofer;
        Size++;
    }
    else if (arreglo[index1].ofer.codigo_producto==ofer.codigo_producto)
    {
        return;
    }
    else{
        for(int i=1; arreglo[pos].key != -1; i++){
            if(arreglo[pos].key == ofer.codigo_producto){
                return;
            }
            pos=(index1+p(ofer.codigo_producto,i));
        }
        arreglo[pos].key=ofer.codigo_producto;
        arreglo[pos].ofer=ofer;
        Size++;
    }
}


int search_O(slotO* arreglo, int llave){
    int index1=h1(llave, Size);
    if (arreglo[index1].ofer.codigo_producto==llave){
        return index1;
    }
    else{
        int pos=index1;
        for(int i=1; arreglo[pos].key != -1; i++){
            if(arreglo[pos].key == llave){
                return pos;
            }
            pos=(index1+p(llave,i));
        }
    }
    printf("no se encontro el producto\n");
    return -1;
}
