#include<stdio.h>
#include<stdlib.h>
#include "TDAlista.h"

int main(){
    FILE *fp=fopen("input1.dat","r");
    if (fp==NULL){
        printf("se me cayo un grande\n");
        return 1;
    }
    int max,op;
    fread(&max,sizeof(int),1,fp);
    fread(&op,sizeof(int),1,fp);

    fclose(fp);
    return 0;
}
