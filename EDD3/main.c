#include <stdio.h>
#include <stdlib.h>
#include "hashingP.h"
#include "hashingO.h"
#include "TDAheap.h"

#define VACIA -1;

/*****
* int main
******
* El main se encarga de realizar todo lo relacionado con el programa princial. 
* Primero lee los archivos binarios struct por struct y los añade al hash 
* uno por uno. Lee el archivo compras.txt, añade los productos al heap y se fija
* cuando es nesesario aplicar los descuentos. La funcion removefirstColaP
* imprime el heap en orden en el archivo ranking.txt y lo libera.
******
* Input:
* Nada
******
* Returns:
* int, Retorna 0 si el programa se ejecuto correctamente y 1 si ocurrio un error al leer los archivos.
*****/
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
    
    i = 0;
    while(i<totalP){
        fread(&tempProduc, sizeof(producto), 1, FileProduc);
        insert_producto(HashProduc, tempProduc);
        i++;
    }
    i = 0;
    
    while(i<totalO){
        fread(&tempOfertas, sizeof(oferta),1,FileOfertasf);
        insert_oferta(HashOfertas,tempOfertas);
        i++;
    }
    fclose(FileProduc);
    fclose(FileOfertasf);

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
            int leer;
            fscanf(FileCompras, "%d", &leer);
            int pos = search_P(HashProduc, leer);
            insertarColaP(heap, pos, HashOfertas, HashProduc);
        }
    }
    fclose(FileCompras);

    FILE* fp = fopen("ranking.txt", "w");
    for (int i = 0 ; i < rank; i++){
        producto2* elem= removefirstColaP(heap, fp);
        free(elem);
    }
    clearColaP(heap);
    fclose(fp);
    clearHashO(HashOfertas);
    clearHashP(HashProduc);
    return 0;
}
