#include <stdlib.h>
#include <stdio.h>
#include "TDAlista.h"

int main(){
    FILE* fp;
    fp = fopen("input.dat","r");
    if (fp==NULL){
        printf("Error al abrir archivo");
        exit(1);
    }
    int M,N,cant;
    char op,aux;
    fscanf(fp, "%d",&M);
    fscanf(fp, "%d",&N);
    tLista listaD, listaU;
    initList(&listaD);
    initList(&listaU);
    tNodo nodoX;
    initNodo(&nodoX, 1, M);
    insert_nodo(&listaD, &nodoX);
    for (int i = 0; i < N; i++){
        op = getc(fp);
        printf(op);
        while ((aux = getc(fp)) != ' '){
            ;
        }
        fscanf(fp, "%d",&cant);
        if (op=='f'){
            free2(&listaD,&listaU,cant);
        }
        if (op=='m'){
            malloc2(&listaD,&listaU,cant);
        }
    }
    fclose(fp);

    return 0;
}
