#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

clienteBanco* leerTrans(char* transacciones, struct* finalCuentas, int totalClientes){
    FILE *fp;
    int tam,c1,c2,dinero;
    char temp,signo;

    fp = fopen(transacciones, "r+");
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

int contarlineas(char *file){
    FILE *fp;
    int cont=0;
    fp=fopen(file,"rb");
    while (fread(&cliente,sizeof(clienteBanco),1,fp)!=0){
        cont++;
  }
    fclose(fp);
    return cont;
}
clienteBanco *Cuentas(char *fname){
    int n=contarlineas(fname),i;
    FILE *fp=fopen(fname,"rb");
    clienteBanco clientes=(clienteBanco)malloc(sizeof(clienteBanco)*n);
    while (1){
        clientes[i]=cliente;
        clienteBanco cliente=(clienteBanco)malloc(sizeof(clienteBanco));
        if (fread(&cliente,sizeof(clienteBanco),1,fp)==0){
            break;
    }
        i++;
  }
  fclose(fp);
  return clientes;
}

void actualizarSaldos(char *clientes, char *transacciones){
    

}

typedef struct {
    int nroCuenta; 
    int saldo; 
    char nbre[51]; 
    char direccion[51]; 
} clienteBanco; 

int main(char* clientes, char* transacciones){

}