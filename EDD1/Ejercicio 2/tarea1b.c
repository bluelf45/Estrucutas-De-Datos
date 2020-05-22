#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/***** 
* TipoFunción NombreFunción 
****** 
* Resumen Función 
****** 
* Input: 
  * tipoParámetro NombreParámetro : Descripción Parámetro 
  * ....... ****** 
* Returns: 
  * TipoRetorno, Descripción retorno 
*****/ 
clienteBanco* leerTrans(char* transacciones, clienteBanco* finalCuentas, int totalClientes){
    FILE *fp;
    int tam,c1,c2,dinero;
    char temp,signo;

    fp = fopen(transacciones, "r+");
    if (fp==NULL){
        printf("Error al abrir archivo")
    }
    while (fread(&temp, sizeof(char),1,fp)!= EOF){
        if (temp=="+"){
            fscanf(fp, "%c %d %d",signo, c1, dinero);
            for (int i = 0; i < totalClientes; i++){
                if (finalCuentas[i].nrocuenta==c1){
                    finalCuentas[i].saldo= finalCuentas[i].saldo + dinero;
                }
            }     
        }
        if (temp=="-"){
            fscanf(fp, "%c %d %d",signo, c1, dinero);
            for (int i = 0; i < totalClientes; i++){
                if (finalCuentas[i].nrocuenta==c1){
                    finalCuentas[i].saldo= finalCuentas[i].saldo - dinero;
                }
            }
        }
        if (temp==">"){
            fscanf(fp, "%c %d %d %d",signo, c1, c2, dinero);
            for (int i = 0; i < totalClientes; i++){
                if (finalCuentas[i].nrocuenta==c1){
                    finalCuentas[i].saldo= finalCuentas[i].saldo - dinero;
                }
                if (finalCuentas[i].nrocuenta==c2){
                    finalCuentas[i].saldo= finalCuentas[i].saldo + dinero;
                }
            }
            
        }
    }
    return finalCuentas;
}

/***** 
* TipoFunción NombreFunción 
****** 
* Resumen Función 
****** 
* Input: 
  * tipoParámetro NombreParámetro : Descripción Parámetro 
  * ....... ****** 
* Returns: 
  * TipoRetorno, Descripción retorno 
*****/ 
int contarlineas(char *file){
    FILE *fp;
    int cont=0;
    fp=fopen(file,"rb");
    if (fp==NULL){
        printf("Error al abrir archivo")
    }
    while (fread(&cliente,sizeof(clienteBanco),1,fp)!=0){
        cont++;
  }
    fclose(fp);
    return cont;
}

/***** 
* TipoFunción NombreFunción 
****** 
* Resumen Función 
****** 
* Input: 
  * tipoParámetro NombreParámetro : Descripción Parámetro 
  * ....... ****** 
* Returns: 
  * TipoRetorno, Descripción retorno 
*****/ 
clienteBanco *Cuentas(char *fname, int n){
    int i=0;
    FILE *fp=fopen(fname,"rb");
    if (fp==NULL){
        printf("Error al abrir archivo")
    }
    clienteBanco clientes=(clienteBanco)malloc(sizeof(clienteBanco)*n);
    while (1){
        clientes[i]=cliente;
        clienteBanco* cliente=(clienteBanco*)malloc(sizeof(clienteBanco));
        if (fread(&cliente,sizeof(clienteBanco),1,fp)==0){
            break;
    }
        i++;
  }
  fclose(fp);
  return clientes;
}

/***** 
* TipoFunción NombreFunción 
****** 
* Resumen Función 
****** 
* Input: 
  * tipoParámetro NombreParámetro : Descripción Parámetro 
  * ....... ****** 
* Returns: 
  * TipoRetorno, Descripción retorno 
*****/ 
void actualizarSaldos(char *clientes, char *transacciones){
    int n =contarlineas(clientes);
    clienteBanco *cuentasClientes= Cuentas(clientes);
    cuentasClientes=leerTrans(transacciones,cuentasClientes,n);
    FILE *fp;
    fp= fopen(clientes,"w");
    if (fp==NULL){
        printf("Error al abrir archivo")
    }
    fwrite(cuentasClientes, clienteBanco,n, fp);
}

typedef struct {
    int nroCuenta; 
    int saldo; 
    char nbre[51]; 
    char direccion[51]; 
} clienteBanco; 

int main(char* clientes, char* transacciones){
    if (clientes == NULL || transacciones== NULL){
        printf("Inserte los nombres correctos para los archivos");
    }
    actualizarSaldos(char* clientes, char* transacciones);
    return 0;
}