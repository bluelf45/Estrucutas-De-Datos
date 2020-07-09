#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDArbol.h"
/*****
* int main
******
* lee el archivo input.txt y lee linea por linea leyendo la  frase y el numero, para saber que funcion tendria que hacer
******
* Input:
* vacio
* .......
******
* Returns:
* 0 si se logro, 1 si el archivo no existe
*****/
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
    arbolBin* arbol=(arbolBin*)malloc(sizeof(arbolBin));
    initArbol(arbol);
    while(fscanf(fp,"%s %d", decidor, &numero)!=EOF){
        if(strcmp(decidor,"SUCESOR")==0){
            Sucesor(arbol, numero, u);
        }
        if(strcmp(decidor,"BORRAR")==0){
            Borrar(arbol, numero);
        }
        else if(strcmp(decidor,"PREORDEN")==0){
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
