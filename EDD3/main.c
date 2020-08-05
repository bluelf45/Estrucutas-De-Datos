#include <stdio.h>
#include <stdlib.h>
#include "hashingP.h"
#include "hashingO.h"
#include "TDAheap.h"

#define VACIA -1;

int buscar(int codigo, int *arreglo, int tam){
    int i;
    for(i=0; i<tam; i++){
        if(arreglo[i]==codigo){
            return i;
        }
    }
    return -1;
}

int main(){
    FILE *FileProduc=fopen("productos.dat","rb");
    FILE *FileOfertasf=fopen("ofertas.dat","rb");
    if(FileOfertasf==NULL || FileProduc==NULL){
        printf("No existe un archivo\n");
        return 1;
    }
    int totalP, totalO, i, k;
    fread(&totalP,sizeof(int),1,FileProduc);
    fread(&totalO,sizeof(int),1,FileOfertasf);
    int TamP=(totalP/0.7)+1, TamO=(totalO/0.7)+1;
    slotP* HashProduc = initArrayProduc(TamP);
    slotO* HashOfertas = initArrayOfer(TamO);

    producto tempProduc;
    oferta tempOfertas;

    /*Leer el archivo de productos primero y los a�ade al array*/
    i = 0;
    while(i<totalP){
        fread(&tempProduc, sizeof(producto), 1, FileProduc);
        insert_producto(HashProduc, tempProduc);
        i++;
    }
    i = 0;
    /*Lo mismo pero al de ofertas*/
    while(i<totalO){
        fread(&tempOfertas, sizeof(oferta),1,FileOfertasf);
        insert_oferta(HashOfertas,tempOfertas);
        i++;
    }
    /*Empieza a hacer todo lo relacionado con compras.txt*/
    FILE *FileCompras=fopen("compras.txt","r");
    if(FileCompras==NULL){
        printf("El archivo compras.txt no existe");
        return 1;
    }
    tcolaP* heap = initColaP(totalP);

    int rank, clientes;

    fscanf(FileCompras, "%d", &rank);
    fscanf(FileCompras, "%d", &clientes);
    for (int i = 0; i < clientes; i++){
        int comp;
        resetCantOHeap(heap);
        fscanf(FileCompras, "%d", &comp);
        for (int i = 0; i < comp; i++){
            //crear producto2
            int leer;
            fscanf(FileCompras, "%d", &leer);
            int pos = search_P(HashProduc, leer);
            producto2 x = creacionProduc(HashProduc, pos);
            insertarColaP(heap, x, HashOfertas, HashProduc);
        }
    }


    
    //Trabajo en archivo Ranking

    FILE* fp = fopen("ranking.txt", "w");

    for (int i = 0 ; i < ranking; i++){
        producto2 elem = removefirstColaP(heap);// cambiar en adelante mal uso TDA
        fprintf(fp,"%d %s %d %d\n", elem.codigo_producto, elem.nombre, elem.cantidad, elem.cont);
    }

    fclose(FileProduc);
    fclose(FileOfertasf);
    fclose(FileCompras);
    fclose(fp);
    clearColaP(heap);
    clearHashO(HashOfertas);
    clearHashP(HashProduc);
    return 0;
}
