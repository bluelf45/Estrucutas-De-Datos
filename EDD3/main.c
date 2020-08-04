#include <stdio.h>
#include <stdlib.h>
#include "hashingP.h"
#include "hashingO.h"
#include "TDAheap.h"
#define VACIA -1

int buscar(int codigo, int* arreglo, int tam){
    for(int i=0; i<tam; i++){
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
    int totalP, totalO, i, j;
    fread(&totalP,sizeof(int),1,FileProduc);
    fread(&totalO,sizeof(int),1,FileOfertasf);
    int TamP=totalP/0.7, TamO=totalO/0.7;
    slotP* HashProduc = initArrayProduc(TamP);
    slotO* HashOfertas = initArrayOfer(TamO);

    producto tempProduc;
    oferta tempOfertas;

    /*Leer el archivo de productos primero y los a�ade al array*/
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

    tcolaP* heap = initColaP(totalP);

    int ranking, NumClientes, NumProductos, CodProduc, codigo, pos, veces, descuento, precio,CostoUnProducto, numDes;
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
        for(int k=0; k<contador; k++){
            int ofer = search_O(HashOfertas, Codigos[k]);
            int prod = search_P(HashProduc, Codigos[k]);
            descuento = 0;
            if( ofer != -1){
                numDes = HashOfertas[ofer].ofer.cantidad_descuento;
                if(numDes<=Cantidad[k]){
                    veces = Cantidad[k]/numDes;
                    descuento = HashOfertas[pos].ofer.monto_descuento;
                }
            }
            precio = HashProduc[prod].pro.precio;
            CostoUnProducto = Cantidad[k]*precio - (veces*descuento);
            int c = buscarHeap(heap, Codigos[k]);
            if (c > 0 ){
                heap->array[c].cantidad += Cantidad[k];
                heap->array[c].cont += CostoUnProducto;
                if (heap->array[c].cont > heap->array[c/2].cont){
                    flotar(heap, c);
                }
            }
            else{
                producto2 x;
                x.codigo_producto = Codigos[k];
                x.cantidad = Cantidad[k];
                x.cont = CostoUnProducto;
                x.nombre = HashProduc[prod].pro.nombre_producto;
            }
        }
        free(Codigos);
        free(Cantidad);
    }
    
    //Trabajo en archivo Ranking

    FILE* fp = fopen("ranking.txt", 'w');

    for (int i = 0 ; i < ranking; i++){
        producto2 elem = removefirstColaP(heap);
        char *string = ("%d %s %d %d\n", elem.codigo_producto, elem.nombre, elem.cantidad, elem.cont);
        fwrite(string, 1, sizeof(string), fp);
    }

    fclose(FileProduc);
    fclose(FileOfertasf);
    fclose(FileCompras);
    fclose(fp);
    clearColaP(heap);
    return 0;
}
