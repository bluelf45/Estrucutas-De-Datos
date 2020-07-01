#include "TDAlista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/***** * int main
 ******
 * En el main de este problema nos encargamos de abrir el archivo y comprobar que este inicialice de forma correcta, luego tomamos los dos datos iniciales
 * que nos entrega el archivo, y creamos las listas que corresponden, ademas de que usando el numero de memoria disponible, insertamos un nodo de ese tamaño
 * en la lista de memoria disponible, luego recorremos el archivo y ejecutamos la funcion requerida.
 ******
 * Input:
 * No tiene ningun input.
 * .......
 ******
 * Returns:
 * Retorna 0 en caso de haber completado el proceso y finaliza la ejecucion.
 * *****/

int main(){
    FILE* fp;
    fp = fopen("input1.dat","r");
    if (fp==NULL){
        printf("Error al abrir archivo");
        exit(1);
    }
    int M,N,cant;
    char *mf=(char*)malloc(sizeof(char)*8);
    fscanf(fp, "%d",&M);
    fscanf(fp, "%d",&N);
    tLista* listaD=(tLista*)malloc(sizeof(tLista));
    tLista* listaU=(tLista*)malloc(sizeof(tLista));
    initList(listaD);
    initList(listaU);
    tNodo* nodoX=(tNodo*)malloc(sizeof(tNodo));
    initNodo(nodoX, 1, M);
    insert_nodo(listaD, nodoX);
    for (int i = 0; i < N; i++){
        fscanf(fp, "%s %d", mf, &cant);
        printf("%d ",tamLista(listaU));
        if (strcmp(mf,"free")==0){
            free2(listaD,listaU,cant);
        }
        if (strcmp(mf,"malloc")==0){
            malloc2(listaD,listaU,cant);
        }
    }
    //printlista(&listaU);
    printf("Quedaron %d bloques sin liberar (%d bytes)\n",tamLista(listaU),contarBytes(listaU));
    fclose(fp);
    free(mf);
    clear(listaD);
    clear(listaU);
    free(listaU);
    free(listaD);
    return 0;
}
