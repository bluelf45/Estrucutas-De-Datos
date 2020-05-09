#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//busca prefijos
int prefijador(char *palabra, char *prefijo)
//Compara 2 strings hasta el largo del 2do
{
  if (strncmp(palabra,prefijo,strlen(prefijo))==0){
    return 0;
  }
  else{
    return 1;
  }
  //retorna 0 si es prefijo, 1 si no lo es
}
char ** buscar_str(char **strings, int largo,char *prefijo)
{
  int contador=0;
  printf("xd\n");
  char **palabras=(char **)malloc(largo*sizeof(char *));
  for (int i=0; i<6; i++){
    if (prefijador(strings[i],prefijo)==0){
      palabras[contador]=(char *)malloc(201*sizeof(char));
      strcpy(palabras[contador],strings[i]);
      printf("%s\n",palabras[contador]);
      contador++;
    }
  }
  return palabras;
}

void agregar(char **palabras, char *name){
  int i=0;
  strcat(name,".dat");
  FILE *prefijo = fopen(name, "w");
  while(palabras[i] != NULL){
    strcat(palabras[i],"\n");
    fprintf(prefijo, palabras[i]);
    i++;
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
  char **strings=(char **)malloc(n*sizeof(char *));
  char **prefijos=(char **)malloc(n2*sizeof(char *));
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
    strings[i]=(char *)malloc(201*sizeof(char));
    fgets(strings[i],201*sizeof(char),string);
  }
  for(i=0;i<n2;i++){
    //Guardar prefijos en arreglos
    prefijos[i]=(char *)malloc(201*sizeof(char));
    fgets(prefijos[i],201*sizeof(char),prefijo);
  }
  fclose(string);fclose(prefijo);
  for (int i = 0; i < n2; i++){
    char **pal= buscar_str(strings, n, prefijos[i]);
    agregar(pal, prefijos[i]);
  }

  return 0;
}
