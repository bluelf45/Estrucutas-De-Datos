#include "TDAlista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    FILE* fp;
    fp = fopen("input1.dat","r");
    if (fp==NULL){
        printf("Error al abrir archivo");
        exit(1);
    }
    int M,N,cant;
    char *mf=(char*)malloc(sizeof(char)*6);
    fscanf(fp, "%d",&M);
    fscanf(fp, "%d",&N);
    tLista listaD, listaU;
    initList(&listaD);
    initList(&listaU);
    tNodo nodoX;
    initNodo(&nodoX, 1, M);
    insert_nodo(&listaD, &nodoX);
    for (int i = 0; i < N; i++){
        fscanf(fp, "%s %d", mf, &cant);
        if (strcmp(mf,"free")==0){
            free2(&listaD,&listaU,cant);
        }
        if (strcmp(mf,"malloc")==0){
            malloc2(&listaD,&listaU,cant);
        }
    }
    fclose(fp);
    free(mf);
    return 0;
}

