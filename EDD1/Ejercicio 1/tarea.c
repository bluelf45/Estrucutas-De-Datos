#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//busca prefijos
int prefijador(char *palabra, char *prefijo)
//Compara 2 strings hasta el largo del 2do
//Los inputs de la funcion son 2 strings
{
  if (strncmp(palabra,prefijo,strlen(prefijo)-1)==0){
    return 0;
  }
  else{
    return 1;
  }
  //retorna 0 si es prefijo, 1 si no es prefijo
}
char ** buscar_str(char **strings, int largo,char *prefijo,int *cuenta)
//funcion busca todos los strings que sean prefijos del string prefijo
//inputs son :arreglo de strings, el largo del arreglo strings, el prefijo que quieres usar,
{
  int contador=0;
  char **palabras=(char **)malloc(largo*sizeof(char *));
  for (int i=0; i<largo; i++){;
    if (prefijador(strings[i],prefijo)==0){
      palabras[contador]=(char *)malloc(201*sizeof(char));
      strcpy(palabras[contador],strings[i]);
      contador++;
    }
  }
  *cuenta=contador;
  return palabras;
  //retorna el arreglo de palabras que son prefijos de prefijo
}
//basti comenta esta
void agregar(char **palabras, char *name,int largo){
  int i=0;
  strtok(name, "\n");
  strcat(name,".out");
  printf("Archivo\n");
  for(int j=0;j<largo;j++){
    printf("%s",palabras[j]);
  }
  printf("\n");
  FILE *prefijo;
  prefijo=fopen(name, "w");
  while(i<largo){
    fprintf(prefijo, "%s", palabras[i]);
    i++;
  }
  fclose(prefijo);
}
int CuentaLinea(char* archivo){
  FILE *fp=fopen(archivo,"r");
  if (fp==NULL){exit(1);}
  int lineas=0;
  int c;
  while((c=fgetc(fp))!=EOF){
    if(c=='\n'){
      lineas++;
    }
  }
  fclose(fp);
  return lineas;
}

int main()
{
  int largo;
  int n,i,n2;
  n=CuentaLinea("S.txt");
  n2=CuentaLinea("P.txt");
  printf("%d %d\n",n,n2);
  FILE *string=fopen("S.txt","r");
  FILE *prefijo=fopen("P.txt","r");
  if (prefijo==NULL){
    return 1;
  }
  if (string==NULL){
    return 1;
  }
  char **strings=(char **)malloc(n*sizeof(char *));
  char **prefijos=(char **)malloc(n2*sizeof(char *));
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
  fclose(string);
  fclose(prefijo);
  for (int i = 0; i < n2; i++){
    char **pal= buscar_str(strings, n, prefijos[i],&largo);
    agregar(pal, prefijos[i], largo);
  }
  free(strings);
  free(prefijos);
  return 0;
}

