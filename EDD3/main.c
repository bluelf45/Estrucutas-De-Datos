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
    FILE *FileCompras=fopen("compras.txt","rb");
    if(FileCompras==NULL){
        printf("El archivo compras.txt no existe");
        return 1;
    }

    tcolaP* heap = initColaP(totalP);

    int ranking, NumClientes, NumProductos, CodProduc, pos, veces, descuento, precio,CostoUnProducto, numDes;
    int* Codigos, *Cantidad, contador;
    fscanf(FileCompras,"%d" , &ranking);
    fscanf(FileCompras, "%d", &NumClientes);
    for(int i=0; i <= NumClientes; i++){
        fscanf(FileCompras, "%d", &NumProductos);
        Codigos=(int*)malloc(sizeof(int)*NumProductos);
        Cantidad=(int*)malloc(sizeof(int)*NumProductos);
        contador=0;
        for(int j=0; j <= NumProductos; j++){
            fscanf(FileCompras, "%d", &CodProduc);
            pos=buscar(CodProduc, Codigos, NumProductos);
            if(pos >= 0){
                Cantidad[pos]++;
            }
            else{
                Codigos[contador]=CodProduc;
                Cantidad[contador]=1;
                contador++;
            }
        }
        for(k=0; k<contador; k++){
            int ofer = search_O(HashOfertas, Codigos[k]);
            int prod = search_P(HashProduc, Codigos[k]);
            descuento = 0;
            if(ofer != -1){
                numDes = get_cant_desc_O(HashOfertas[ofer]);
                if(numDes<=Cantidad[k]){
                    veces = Cantidad[k]/numDes;
                    descuento = get_descuento_O(HashOfertas[pos]);
                }
            }
            precio = get_precio_P(HashProduc[prod]);
            CostoUnProducto = Cantidad[k]*precio - (veces*descuento);
            int c = buscarHeap(heap, Codigos[k]);
            if (c > 0 ){
                sumarElemHeap(heap,  c, Cantidad[k], CostoUnProducto);
            }
            else{
                producto2 x=creacionProduc(Codigos[k], Cantidad[k], CostoUnProducto, get_name_P(&HashProduc[prod]));
                insertarColaP(heap,x);
            }
        }
        free(Codigos);
        free(Cantidad);
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
