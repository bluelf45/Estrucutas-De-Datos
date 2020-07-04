#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDArbol.h"
int main(){
    int u, numero;
    FILE*  fp;
    fp=fopen("input.txt", "r");
    char* decidor=(char*)malloc(sizeof(char)*9);
    if(fp==NULL){
        printf("Archivo no existe\n");
        return 1;
    }
    fscanf(fp,"%d", &u);
    printf("u=%d \n",u);
    arbolBin* arbol=(arbolBin*)malloc(sizeof(arbolBin));
    initArbol(arbol);
    int suce;
    while(fscanf(fp,"%s %d", decidor, &numero)!=EOF){
        if(strcmp(decidor,"SUCESOR")==0){
            suce=Sucesor(arbol, numero, u);
            if(suce!=-1){
                printf("%d\n",suce);
            }
        }
        if(strcmp(decidor,"BORRAR")==0){
            printf("borrar\n");
            Borrar(arbol, numero);
        }
        else if(strcmp(decidor,"PREORDEN")==0){
            printf("preorden: ");
            preorden(arbol);
        }
        else if(strcmp(decidor,"INSERTAR")==0){
            insertar(arbol, numero);
        }
    }
    free(decidor);
    clear(arbol);
    free(arbol);
    fclose(fp);
    return 0;
}
