#include <stdio.h>
#include <stdlib.h>
#include "hashingO.h"

#define C1 3;

int SizeO;


/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
slotO* initArrayOfer(int Tam){
    slotO* arreglo=(slotO*)malloc(sizeof(slotO)*Tam);
    SizeO=Tam;
    for(int i=0; i<Tam; i++){
        arreglo[i].key=-1;
    }
    return arreglo;
}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int get_id_O(slotO slot){
    return slot.ofer.codigo_producto;
}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int get_cant_desc_O(slotO slot){
    return slot.ofer.cantidad_descuento;
}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int get_descuento_O(slotO slot){
    return slot.ofer.monto_descuento;
}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
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
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int h2(int k, int i){
    if (i==0){
        return 0;
    }
    int final=k*C1;
    return final*k;
}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int p(int k, int i){
    return i*h2(k,i);
}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
void insert_oferta(slotO* arreglo, oferta ofer){
    int index1=h1(ofer.codigo_producto, SizeO);
    int pos=index1;
    if(arreglo[index1].key==-1){
        arreglo[index1].key=ofer.codigo_producto;
        arreglo[index1].ofer=ofer;
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
            pos=(index1+p(ofer.codigo_producto,i))%SizeO;
        }
        arreglo[pos].key=ofer.codigo_producto;
        arreglo[pos].ofer=ofer;
    }
}

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int search_O(slotO* arreglo, int llave){
    int index1=h1(llave, SizeO);
    if (arreglo[index1].ofer.codigo_producto==llave){
        return index1;
    }
    else{
        int pos=index1;
        for(int i=1; arreglo[pos].key != -1; i++){
            if(arreglo[pos].key == llave){
                return pos;
            }
            pos=(index1+p(llave,i))%SizeO;
        }
    }
    return -1;
}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
void clearHashO(slotO* arreglo){
    free(arreglo);
}
