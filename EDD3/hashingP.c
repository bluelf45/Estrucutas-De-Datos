#include <stdio.h>
#include <stdlib.h>
#include "hashingP.h"

#define C1 3
int SizeP=0;
int Max_size;

int get_id_P(producto produc){
    return produc.codigo_producto;
}

char* get_name_P(producto* pro){
    return pro->nombre_producto;
}

int get_precio_P(producto produc){
    return produc.precio;
}

//llenar el arreglo de slots vacios con key=-1 y el flag=0
slotP* initArrayProduc(int Tam){
    slotP* arreglo=(slotP*)malloc(sizeof(producto)*Tam);
    Max_size=Tam;
    for(int i=0; i<Tam; i++){
        arreglo[i].key=-1;
    }
    return arreglo;
}

int h1P(int k, int M){
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

int h2P(int k, int i){
    if (i==0) {
        return 0;
    }
    return C1*k*k;
}

int pP(int k, int i){
    return i*h2P(k,i);
}

void insert_oferta(slotP* arreglo, producto produc){
    int index1=h1P(produc.codigo_producto, SizeP);
    int pos=index1;
    if(arreglo[index1].key==-1){
        arreglo[index1].key=produc.codigo_producto;
        arreglo[index1].pro=produc;
        SizeP++;
    }
    else if (arreglo[index1].pro.codigo_producto==produc.codigo_producto)
    {
        return;
    }
    else{
        for(int i=1; arreglo[pos].key != -1; i++){
            if(arreglo[pos].key == produc.codigo_producto){
                return;
            }
            pos=(index1+pP(produc.codigo_producto,i));
        }
        arreglo[pos].key=produc.codigo_producto;
        arreglo[pos].pro=produc;
        SizeP++;
    }
}

int search_P(slotP* arreglo, int llave){
    int index1=h1P(llave, SizeP);
    int pos=index1;
    if (get_id_P(arreglo[index1].pro)==llave){
        return pos;
    }
    else{
        for(int i=1; arreglo[pos].key != -1; i++){
            if(arreglo[pos].key == llave){
                return pos;
            }
            pos=(index1+pP(llave,i));
        }
    }
    printf("no se encontro el producto\n");
    return -1;
}
