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
* char** buscar_str
****** 
* crea un arreglo dinamico de palabras y le va a unir a este arreglo todos los strings que tengan de prefijo a prefijo
usando la funcion prefijador y asignandole memoria a cada una de las palabras
****** 
* Input: 
  * tipoParámetro NombreParámetro : Descripción Parámetro 
  * char** strings : arreglo de strings que quieres saber si tiene cierto prefijo
  * int largo : cantidad de palabras de strings, o tambien la cantidad de lineas
  * char* prefijo : el string que va a ser el prefijo que quieres usar
  * int* cuenta: cuenta va a ser la cantidad de prefios que hay en el arreglo strings
****** 
* Returns: 
  * char** palabras, retorna un arreglo de palabras que tienen de prefijo a la variable prefijo
*****/ 

char ** buscar_str(char **strings, int largo,char *prefijo,int *cuenta)
{
    int contador=0;
    char **palabras = (char **)malloc(largo*sizeof(char *));
    for (int i = 0; i<largo; i++){;
        if (prefijador(strings[i],prefijo)== 0){
        palabras[contador] = (char *)malloc(201*sizeof(char));
        strcpy(palabras[contador],strings[i]);
        contador++;
        }
    }
    *cuenta=contador;
    return palabras;
  //retorna el arreglo de palabras que son prefijos de prefijo
}

/*****
* void agregar
******
* Esta funcion crea los archivos tipo ".out" y añade las palabras que tienen de prefijo
  "pre". La funcion "buscar_str" le da los string con el prefijo buscado.
******
* Input:
  * char **palabras : Un array de las palabras que tienen de prefijo "pre".
  * char *pre : El prefijo. Se usa para crear el nombre del archivo.
  * int largo : Esto nos dice cuantos prefijos vamos a añadir al archivo de mombre "pre"
    y lo usamos para recorrer el array "palabras"
***** 
* Returns:
  * No retorna nada, ya que la funcion es de tipo void.
*****/
void agregar(char **palabras, char *pre,int largo){
    strtok(pre, "\n");
    strcat(pre, ".out");
    int i = 0;

    FILE *prefijo;
    prefijo = fopen(pre, "w");
    while( i < largo){
        fprintf(prefijo, "%s", palabras[i]);
        i++;
    }
    fclose(prefijo);
}

/***** 
* int CuentaLinea
****** 
* cuenta la cantidad de \n que hay, el cual va a ser la cantidad de lineas que existan
****** 
* Input: 
  * tipoParámetro NombreParámetro : Descripción Parámetro 
  * char* archivo: nombre del archivo al que le quieres contar  las lineas
****** 
* Returns: 
  * int lineas, cantidad entera que corresponde a la cantidad de lineas del archivo
*****/ 
int CuentaLinea(char* archivo){
    FILE *fp = fopen(archivo,"r");
    if (fp == NULL){exit(1);}
    int lineas = 0;
    int c;
    while((c = fgetc(fp)) != EOF){
        if(c == '\n'){
        lineas++;
        }
    }
    fclose(fp);
    return lineas;
}

/***** 
* int main 
****** 
* funcion principal que va ausar todas las funciones  que creamos arriba de esta, va a contar lineas de los 2 archivos
  ver si estos se pueden abrir correctamente,crear arreglos de memoria dinamica para ambos archivos y los va a guardar en estos
  por ultimo va a usar buscar_str para buscar las palabras y finalmente guardarlos en archivos
  ****** 
* Returns: 
  * int 0 : retorna 0 si se cumple correctamente toda la funcion
*****/ 
int main(){

    int largo;
    int n ,i ,n2;
    n = CuentaLinea("S.txt");
    n2 = CuentaLinea("P.txt");

    FILE *string = fopen("S.txt","r");
    FILE *prefijo = fopen("P.txt","r");
    if (prefijo == NULL){
        return 1;
    }
    if (string == NULL){
        return 1;
    }
    char **strings = (char **)malloc(n*sizeof(char *));
    char **prefijos = (char **)malloc(n2*sizeof(char *));
    for (i=0;i<n;i++){
    //Guardar las palabras en arreglos
    strings[i] = (char *)malloc(201*sizeof(char));
    fgets(strings[i],201*sizeof(char),string);
    }
    for(i=0;i<n2;i++){
    //Guardar prefijos en arreglos
        prefijos[i] = (char *)malloc(201*sizeof(char));
        fgets(prefijos[i] ,201*sizeof(char) ,prefijo);
    }
    fclose(string);
    fclose(prefijo);

    for (int i = 0; i < n2; i++){
        char **pal = buscar_str(strings, n, prefijos[i],&largo);
        agregar(pal, prefijos[i], largo);
    }
    free(strings);
    free(prefijos);
    return 0;
}
