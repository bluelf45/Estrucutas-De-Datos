#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//busca prefijos
char ** buscar_str(char **strings, int n, char *p){
  int i, j; //contadores para los ciclos for
  char palabra[201];//palabra para hacer los prefijos
  char *palabras[n];// arreglo de palabras
  for (i=0;i<n;i++){
    memset(palabra, 0, sizeof(palabra));//reiniciar palabra a un arreglo vacio
    for (j=0;j<=strlen(strings[i]);j++)
    {
      strncpy(palabra,strings[i],j);//copia el primer caracter de strings[i] a palabra
      if (strcmp(palabra,p)==0){//ver si la palabra es o no prefijo
        strcpy(palabras[i],strings[i]);
        break;//rompe el for de revisar la palabra en especifico
      }
    }
  }
  return palabras;
}

void agregar(char **palabras, char name){
  FILE prefijo = fopen("%s.dat", name, "w");
  int cant= ;
  for ( i = 0; i < cant; i++){
    fprintf(prefijo, ("%s/n",palabras[i]));
  }
  fclose(prefijo);
}

int main(){
  int n,i,n2;
  printf("Maximo cantidad de palabras: ");
  scanf("%d",&n);
  printf("Maximo cantidad de prefijos: ");
  scanf("%d",&n2);
  char archivo1[21],archivo2[21];
  char strings[n][201];
  char prefijos[n2][201];
  char palabra[201];
  printf("Nombre del archivo con palabras: ");
  scanf("%s",archivo1);
  printf("Nombre del archivo con prefijos: ");
  scanf("%s",archivo2);
  FILE *string=fopen(archivo1,"r");
  FILE *prefijo=fopen(archivo2,"r");
  if (prefijo==NULL){
    return 1;
  }
  if (string==NULL){
    return 1;
  }
  for (i=0;i<n;i++){
    //Guardar las palabras en arreglos
    fgets(palabra,201*sizeof(char),string);
    strcpy(palabras[i],palabra);
  }
  for(i=0;i<n2;i++){
    //Guardar prefijos en arreglos
    fgets(palabra,201,prefijo);
    strcpy(prefijos[i],palabra);
  }
  fclose(string);fclose(prefijo);
  for (int i = 0; i < n2; i++){
    char **pal= buscar_str(strings, n, prefijos[i]);
    cant = count(pal) 
    agregar(pal, prefijos[i]);
  }
  
  return 0;
}
