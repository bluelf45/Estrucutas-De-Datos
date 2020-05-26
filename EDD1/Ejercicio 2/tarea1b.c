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
void transaccion(clienteBanco cliente1, clienteBanco cliente2, int saldo){
    cliente1->saldo=cliente1->saldo-saldo;
    cliente2->saldo=cliente2->saldo+saldo;
}
void actualizar(clienteBanco cliente,int saldo, int multi){
    cliente->saldo=cliente->saldo+(saldo*multi);
}
void actualizarSaldos(char* transacciones, char* clientes){
    FILE *fp,*Aclientes;
    int tam,c1,c2,dinero,pos;
    char temp,signo;
    int cuenta;
    fp = fopen(transacciones, "r+");
    if (fp==NULL || Aclientes==NULL){
        printf("Error al abrir archivo");
    }
    clienteBanco cliente, cliente2;
    while (fread(cliente,sizeof(clienteBanco),1,Aclientes)==0)
    {
        while(1)
        {
            fread(&temp, sizeof(char),1,fp);
            if (strcmp(&temp,"+")==0)
            {
                fscanf(fp, "%c %d %d",signo, c1, dinero);
                if(c1==cuenta){
                    actualizar(cliente, dinero,1);
                }
            }
            else if(strcmp(&temp,"-")==0)
            {
                fread(&temp, sizeof(char),1,fp);
                fscanf(fp, "%c %d %d", signo, c1, dinero);
                if(c1==cuenta){
                    actualizar(cliente, dinero,-1);
                }
            }
            else if(strcmp(&temp,">")==0)
            {
                fscanf(fp, "%c %d %d %d",signo, c1, c2, dinero);
                if (c1==cuenta)
                {
                    pos=ftell(Aclientes);
                    fseek(Aclientes,0,SEEK_SET);
                    while (fread(cliente2,sizeof(clienteBanco),1,Aclientes)==0)
                    {
                        if (c2==cliente2->nroCuenta)
                        {
                            transaccion(cliente,cliente2,dinero);
                            break;
                        }
                    }
                    fseek(Aclientes,pos,SEEK_SET);
                }
            }
        }
    }
}




int main(int argc, char **argv){
    actualizarSaldos(argv[1], argv[2]);
    return 0;
}
