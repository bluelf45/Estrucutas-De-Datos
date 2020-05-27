#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cont = 0;

typedef struct {
    int nroCuenta;
    int saldo;
    char nbre[51];
    char direccion[51];
} clienteBanco;

/*****
* clienteBanco* leerTrans
******
* La funcion se encarga de leer el primer caracter de cada linea del archivo transacciones,y asi modifica
  los saldos en finalCuentas dependiendo en lo que diga la linea de el archivo transacciones. Ademas modifica la variable universal cont, tal que tengamos la cantidad de clientes totales.
******
* Input:
  * char* transacciones: Nombre del archivo ASCII transacciones
  * clienteBanco* finalCuentas: array de structs copiados del archivo clientes
******
* Returns:
  * clienteBanco*, Es el array de structs que se le entrega a la funcion solo que ahora con el saldo ya modificado.
*****/
clienteBanco* leerTrans(char* transacciones, char* clientes){
    FILE *fp, *Aclientes;
    int c1,c2,dinero;
    char temp, signo;
    fp = fopen(transacciones, "r+");
    Aclientes = fopen(clientes, "r+");
    if (fp==NULL || Aclientes==NULL){
        printf("Error al abrir archivo");
    }
    clienteBanco cliente;
    clienteBanco* finalCuentas=(clienteBanco*)malloc(sizeof(clienteBanco));

    while (fread(&cliente,sizeof(clienteBanco),1,Aclientes)!=0){
        finalCuentas[cont]=cliente;
        cont++;
    }
    fseek(Aclientes,0,SEEK_SET);
    fseek(fp,0,SEEK_SET);
    while (fread(&temp, sizeof(char),1,fp)!=0){
        if (temp=='+'){
            fseek(fp, -1*sizeof(char), SEEK_CUR);
            fscanf(fp, "%c %d %d",&signo, &c1, &dinero);
            printf("%c %d %d\n",signo,c1,dinero);
            for (int i = 0; i < cont; i++){
                if (finalCuentas[i].nroCuenta==c1){
                    finalCuentas[i].saldo= finalCuentas[i].saldo + dinero;
                }
            }
        }
        else if (temp=='-'){
            fseek(fp, -1*sizeof(char), SEEK_CUR);
            fscanf(fp, "%c %d %d",&signo, &c1, &dinero);
            for (int i = 0; i < cont; i++){
                if (finalCuentas[i].nroCuenta==c1){
                    finalCuentas[i].saldo= finalCuentas[i].saldo - dinero;
                }
            }
        }
        else if (temp=='>'){
            fseek(fp, -1*sizeof(char), SEEK_CUR);
            fscanf(fp, "%c %d %d %d",&signo, &c1, &c2, &dinero);
            for (int i = 0; i < cont; i++){
                if (finalCuentas[i].nroCuenta==c1){
                    finalCuentas[i].saldo= finalCuentas[i].saldo - dinero;
                }
                if (finalCuentas[i].nroCuenta==c2){
                    finalCuentas[i].saldo= finalCuentas[i].saldo + dinero;
                }
            }

        }
    }
    fclose(fp);
    fclose(Aclientes);
    return finalCuentas;
}

/*****
* void actualizarSaldos
******
* Usa las funciones anteriormente definidas y luego escribe el archivo clientes con los nuevos datos
******
* Input:
  * char *clientes: Nombre del archivo binario con la informacion de los clientes
  * char *transacciones: Nombre del archivo ASCII con la informacion sobre las transacciones
******
* Returns:
  * void, no retorna nada ya que modifica los archivos dados.
*****/
void actualizarSaldos(char *clientes, char *transacciones){
    clienteBanco *cuentasClientes;
    cuentasClientes=leerTrans(transacciones,clientes);
    FILE *fp;
    clienteBanco temp;
    fp= fopen(clientes,"r+");
    if (fp==NULL){
        printf("Error al abrir archivo");
    }
    for (int i = 0; i < cont; i++){
        fread(&temp, sizeof(clienteBanco),1,fp);
        printf("%d %d\n",temp.saldo,cuentasClientes[i].saldo);
        fseek(fp, -1*sizeof(clienteBanco), SEEK_CUR);
        fwrite(&cuentasClientes[i],sizeof(clienteBanco),1,fp);
    }
    fclose(fp);
}

/*****
* int main
******
* Toma los datos de la linea de comandos y usa la funcion actualizarSaldos
******
* Input:
  * int argc: Cantidad de datos en la linea de comandos
  * char **argv: Datos entregados en la linea de comandos
******
* Returns:
  * int, retorna 0 para que el sistema sepa que se ejecuto correctamente el programa.
*****/
int main(int argc, char **argv){
    actualizarSaldos(argv[1], argv[2]);
    return 0;
}
