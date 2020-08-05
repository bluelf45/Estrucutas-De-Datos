#include <stdio.h>
#include <stdlib.h>
#include "hashingP.h"
#include "hashingO.h"
#include "TDAheap.h"

#define VACIA -1;

int main(){
    FILE *FileProduc=fopen("productos.dat","rb");
    FILE *FileOfertasf=fopen("ofertas.dat","rb");
    if(FileOfertasf==NULL || FileProduc==NULL){
        printf("No existe un archivo\n");
        return 1;
    }
    int totalP, totalO, i;
    fread(&totalP,sizeof(int),1,FileProduc);
    fread(&totalO,sizeof(int),1,FileOfertasf);
    int TamP=(totalP/0.7)+1;
    int TamO=(totalO/0.7)+1;
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
    fclose(FileProduc);
    fclose(FileOfertasf);
    /*Empieza a hacer todo lo relacionado con compras.txt*/
    FILE *FileCompras=fopen("compras.txt","r");
    if(FileCompras==NULL){
        printf("El archivo compras.txt no existe");
        return 1;
    }
    tcolaP* heap =(tcolaP*)malloc(sizeof(tcolaP));
    initColaP(totalP+1, heap);

    int rank, clientes;

    fscanf(FileCompras, "%d", &rank);
    fscanf(FileCompras, "%d", &clientes);
    for (int j = 0; j < clientes; j++){
        int comp;
        resetCantOHeap(heap);
        fscanf(FileCompras, "%d", &comp);
        for (int j = 0; j < comp; j++){
            //crear producto2
            int leer;
            fscanf(FileCompras, "%d", &leer);
            int pos = search_P(HashProduc, leer);
            insertarColaP(heap, pos, HashOfertas, HashProduc);
        }
    }
    fclose(FileCompras);

    //Trabajo en archivo Ranking

    FILE* fp = fopen("ranking.txt", "w");
    for (int i = 0 ; i < rank; i++){
        producto2* elem;
        elem = removefirstColaP(heap);// cambiar en adelante mal uso TDA
        fprintf(fp,"%d %s %d %d\n", elem->codigo_producto, elem->nombre, elem->CantidadPrecio, elem->cont);
        free(elem);
    }
    clearColaP(heap);
    fclose(fp);
    clearHashO(HashOfertas);
    clearHashP(HashProduc);
    return 0;
}
