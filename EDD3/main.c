#include <stdio.h>
#include <stdlib.h>

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
    int totalP, totalO;
    FILE *produc=fopen("productos.dat","rb");
    FILE *ofertas=fopen("ofertas.dat","rb");
    if(ofertas==NULL || produc==NULL){
        printf("No existe un archivo\n");
        return 1;
    }
    fread(&totalP,sizeof(int),1,produc);
    fread(&totalO,sizeof(int),1,ofertas);

    return 0;
}
