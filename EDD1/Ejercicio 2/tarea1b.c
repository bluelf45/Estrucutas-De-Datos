#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int nroCuenta;
    int saldo;
    char nbre[51];
    char direccion[51];
} clienteBanco;

/***** 
* clienteBanco* leerTrans
****** 
* La funcion se encarga de leer el primer caracter de cada linea del archivo transacciones, y asi modifica los saldos en finalCuentas dependiendo en lo que diga la linea de el archivo transacciones
****** 
* Input: 
  * char* transacciones: Nombre del archivo ASCII transacciones
  * clienteBanco* finalCuentas: array de structs copiados del archivo clientes
  * int totalClientes: Cantidad total de clientes, es decir la cantidad de structs que tiene el array anteriormente mencionado
******
* Returns: 
  * clienteBanco*, Es el array de structs que se le entrega a la funcion solo que ahora con el saldo ya modificado. 
*****/ 
clienteBanco* leerTrans(char* transacciones, clienteBanco* finalCuentas, int totalClientes){
    FILE *fp;
    int tam,c1,c2,dinero;
    char temp,signo;

    fp = fopen(transacciones, "r+");
    if (fp==NULL){
        printf("Error al abrir archivo");
    }
    while (fread(&temp, sizeof(char),1,fp)!= EOF){
        if (strcmp(&temp,"+")==0){
            fscanf(fp, "%c %d %d",signo, c1, dinero);
            for (int i = 0; i < totalClientes; i++){
                if (finalCuentas[i].nroCuenta==c1){
                    finalCuentas[i].saldo= finalCuentas[i].saldo + dinero;
                }
            }
        }
        if (strcmp(&temp,"-")==0){
            fscanf(fp, "%c %d %d",signo, c1, dinero);
            for (int i = 0; i < totalClientes; i++){
                if (finalCuentas[i].nroCuenta==c1){
                    finalCuentas[i].saldo= finalCuentas[i].saldo - dinero;
                }
            }
        }
        if (strcmp(&temp,">")==0){
            fscanf(fp, "%c %d %d %d",signo, c1, c2, dinero);
            for (int i = 0; i < totalClientes; i++){
                if (finalCuentas[i].nroCuenta==c1){
                    finalCuentas[i].saldo= finalCuentas[i].saldo - dinero;
                }
                if (finalCuentas[i].nroCuenta==c2){
                    finalCuentas[i].saldo= finalCuentas[i].saldo + dinero;
                }
            }

        }
    }
    return finalCuentas;
}

/***** 
* int contarlineas 
****** 
* va a leer el archivo binario hasta que fread devuelva el valor 0, o sea, llegue al final del archivo
****** 
* Input: 
  * char * file : Nombre de un archivo binario 
****** 
* Returns: 
  * int cont, exit(1) si no se abre el archivo, o no existe. O sino devolvera la cantidad de lineas
*****/ 
int contarlineas(char *file){
    FILE *fp;
    int cont=0;
    fp=fopen(file,"rb");
    if (fp==NULL){
        printf("Error al abrir archivo");
    }
    clienteBanco cliente;
    while (fread(&cliente,sizeof(clienteBanco),1,fp)!=0){
        cont++;
  }
    fclose(fp);
    return cont;
}
/***** 
* clienteBanco Cuentas 
****** 
* crea un arreglo de memoria dinamica llamado clientes, al cual se le agregaran todos las cuentas que esten en el archivo binario
****** 
* Input: 
  * char* fname: nombre de archivo binario que tiene structs de tipo cuentaBanco
  * int n : es la cantidad de lineas del archivo binario
****** 
* Returns: 
  * TipoRetorno, Descripción retorno 
  * ClienteBanco* : Arreglo de clienteBanco que contiene el total de cuentas en el archivo binario
*****/ 
clienteBanco *Cuentas(char *fname, int n){
    int i=0;
    FILE *fp=fopen(fname,"rb");
    if (fp==NULL){
        printf("Error al abrir archivo");
    }
    clienteBanco *clientes=(clienteBanco*)malloc(sizeof(clienteBanco)*n);
    clienteBanco cliente;
    while (1){
        clientes[i]=cliente;
        if (fread(&cliente,sizeof(clienteBanco),1,fp)==0){
            break;
    }
        i++;
  }
  fclose(fp);
  return clientes;
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
    int n =contarlineas(clientes);
    clienteBanco *cuentasClientes= Cuentas(clientes,n);
    cuentasClientes=leerTrans(transacciones,cuentasClientes,n);
    FILE *fp;
    fp= fopen(clientes,"w");
    if (fp==NULL){
        printf("Error al abrir archivo");
    }
    fwrite(cuentasClientes, sizeof(clienteBanco), n, fp);
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
