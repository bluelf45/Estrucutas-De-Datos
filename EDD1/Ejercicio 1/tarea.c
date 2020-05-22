#include<stdio.h>
#include<stdlib.h>
#include <string.h>

/***** 
* int prefijador 
****** 
* La funcion toma 2 char* y comprueba si el segundo es prefijo del primero. 
****** 
* Input: 
  * char* palabra : Palabra la cual queremos comparar con el candidato a prefijo.
  * char* prefijo : Candidato a prefijo para la palabra.
  ****** 
* Returns: 
  * int, retorna 0 si es prefijo y 1 si no lo es.
*****/
int prefijador(char *palabra, char *prefijo)
{
  if (strncmp(palabra,prefijo,strlen(prefijo)-1)==0){
    return 0;
  }
  else{
    return 1;
  }

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
char ** buscar_str(char **strings, int largo,char *prefijo,int *cuenta)
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

