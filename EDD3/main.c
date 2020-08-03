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
    int totalP, totalO, i, j, codigo;
    fread(&totalP,sizeof(int),1,FileProduc);
    fread(&totalO,sizeof(int),1,FileOfertasf);
    int TamP=totalP/0.7;
    int TamO=totalO/0.7;
    slotP* HashProduc = initArrayProduc(TamP);
    slotO* HashOfertas = initArrayOfer(TamO);

    producto tempProduc;
    oferta tempOfertas;

    /*Leer el archivo de productos primero y los añade al array*/
    i = 0;
    while(i<totalP){
        fread(&tempProduc, sizeof(producto),1,FileProduc);
        insert_producto(HashProduc,tempProduc);
        i++;
    }
    i = 0;
    /*Lo mismo pero al de ofertas*/
    while(i<totalO){
        fread(&tempProduc, sizeof(oferta),1,FileOfertasf);
        insert_oferta(HashOfertas,tempOfertas);
        i++;
    }
    /*Empieza a hacer todo lo relacionado con compras.txt*/
    FILE *FileCompras=fopen("compras.txt","rb");
    if(FileCompras==NULL){
        printf("El archivo compras.txt no existe");
        return 1;
    }

    tcolaP* heap = initColaP(totalP);/*wat*/

    char ranking, NumClientes, NumProductos, CodProduc;
    fscanf(FileCompras,"%d" , &ranking);
    fscanf(FileCompras, "%d", &NumClientes);
    i = 0;
    while(i<=NumClientes){
        fscanf(FileCompras, "%d", &NumProductos);
        j = 0;
        while(j<=NumProductos){
            fscanf(FileCompras, "%d", &CodProduc);
            codigo = search_P(HashProduc, CodProduc);
            j++;
        }
        i++;
    }

    /*Aqui añadir las cosas para crear el archivo final*/



    fclose(FileProduc);
    fclose(FileOfertasf);
    fclose(FileCompras);

    return 0;
}
