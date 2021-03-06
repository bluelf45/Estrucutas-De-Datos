#include <stdio.h>
#include <stdlib.h>
#include "hashingP.h"

#define C1 1
int SizeP;

int get_id_P(slotP slot){
    return slot.pro.codigo_producto;
}
producto get_pro(slotP slot){
    return slot.pro;
}
char* get_name_P(slotP* slot){
    return slot->pro.nombre_producto;
}

int get_precio_P(slotP slot){
    return slot.pro.precio;
}

//llenar el arreglo de slots vacios con key=-1 y el flag=0
slotP* initArrayProduc(int Tam){
    slotP* arreglo;
    arreglo=(slotP*) malloc(sizeof(slotP)*Tam);
    SizeP=Tam;
    for(int i=0; i<Tam; i++){
        arreglo[i].key=-1;
    }
    return arreglo;
}

int h1P(int k, int m){
    int hashVal;
    if (k == 0){
        return 0;
    }
    hashVal = (k<<3) ^ k;
    hashVal = (hashVal<<3) ^ k;
    hashVal = (hashVal<<3) ^ k;
    while (hashVal > m){
        hashVal = hashVal % m;
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
    return i+h2P(k,i);
}

void insert_producto(slotP* arreglo, producto produc){
    int index1=h1P(produc.codigo_producto, SizeP);
    int pos=index1;
    if(arreglo[index1].key==-1){
        arreglo[index1].key=produc.codigo_producto;
        arreglo[index1].pro=produc;
    }
    else{
        for(int i=1; arreglo[pos].key != -1 && pos<SizeP; i++){
            pos=(index1+pP(produc.codigo_producto,i))%SizeP;
        }
        arreglo[pos].key=produc.codigo_producto;
        arreglo[pos].pro=produc;
    }
}

int search_P(slotP* arreglo, int llave){
    int index1=h1P(llave, SizeP);
    int pos=index1;
    if (get_id_P(arreglo[index1])==llave){
        return pos;
    }
    else{
        for(int i=1; i<SizeP; i++){
            if(arreglo[pos].key == llave){
                return pos;
            }
            pos=(index1+pP(llave,i))%SizeP;
        }
    }
    return -1;
}
void clearHashP(slotP* arreglo){
    free(arreglo);
}
