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


int main(int argc, char **argv){
    actualizarSaldos(argv[1], argv[2]);
    return 0;
}
