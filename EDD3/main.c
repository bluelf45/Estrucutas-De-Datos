#include <stdio.h>
#include <stdlib.h>
#include "hashingO.h"
#include "hashingP.h"
#include "TDAheap.h"

#define VACIA -1

typedef struct {
    int  codigo_producto;
    char nombre_producto[31];
    int  precio;
} producto;

typedef struct {
    int codigo_producto;
    int cantidad_descuento;
    int monto_descuento;
} oferta;

int esPrimo(int n){
    if(n<=1){
        return 0;
    }
    else if(n<=3){
        return 1;
    }
    if(n%2==0 || n%3==0){
        return 0;
    }
    for(int i=5; i*i <=n; i+=6){
        if(n%i==0 || n%(i+2) ==0){
            return 0;
        }
    }
    return 1;
}

int SigPrimo(int n){
    if(n<=1){
        return 2;
    }
    int primo=n;
    int flag=0;
    while(found!=0){
        primo++;
        if(esPrimo(primo)==1){
            flag=1;
        }
    }
    return primo
}

int main(){
    FILE *FileProduc=fopen("productos.dat","rb");
    FILE *FileOfertasf=fopen("ofertas.dat","rb");
    if(FileOfertas==NULL || FileProduc==NULL){
        printf("No existe un archivo\n");
        return 1;
    }
    int totalP, totalO, i, j, codigo;
    fread(&totalP,sizeof(int),1,FileProduc);
    fread(&totalO,sizeof(int),1,FileOfertas);
    int TamP=totalP/0.7;
    int TamO=totalO/0.7;
    struct slotP* HashProduc = initArray(TamP);
    struct slotO* HashOfertas = initArray(TamO);

    struct producto tempProduc;
    struct oferta tempOfertas;

    /*Leer el archivo de productos primero y los añade al array*/
    i = 0;
    while(i<totalP;i++){
        fread(&tempProduc, sizeof(producto),1,FileProduc);
        insert_producto(hashProduc,tempProduct);
    }
    i = 0;
    /*Lo mismo pero al de ofertas*/
    while(i<totalP;i++){
        fread(&tempProduc, sizeof(oferta),1,FileOferta);
        insert_oferta(hashOfertas,tempOfertas);
    }
    /*Empieza a hacer todo lo relacionado con compras.txt*/
    FILE *FileCompras=fopen("compras.txt","rb");
    if(FileCompras==NULL){
        printf("El archivo compras.txt no existe");
        return 1;
    }

    struct tcolaP heap = initColaP(); /*wat*/

    char ranking, NumClientes, NumProductos, CodProduc;
    fscanf(FileCompras, %d, &ranking);
    fscanf(FileCompras, %d, &NumClientes);
    i = 0;
    while(i<=NumClientes; i++){
        fscanf(FileCompras, %d, &NumProductos);
        j = 0;
        while(j<=NumProductos;j++){
            fscanf(FileCompras, %d, &CodProduc);
            codigo = search(HashProduc, CodProduc);
        }
    }



    /*Aqui añadir las cosas para crear el archivo final*/



    fclose(FileProduc);
    fclose(FileOfertas);
    fclose(FileCompras);

    return 0;
}
