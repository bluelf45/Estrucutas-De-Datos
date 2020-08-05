#ifndef HASHINGP
#define HASHINGP

typedef struct {
    int  codigo_producto;
    char nombre_producto[31];
    int  precio;
} producto;

typedef struct{
    int key;
    producto pro;
}slotP;

/*****
* int get_id_P
******
* devuelve el codigo de producto del producto del slot
******
* Input:
* slotP : slot del arreglo de hashing
* .......
******
* Returns:
* int, codigo producto
*****/
int get_id_P(slotP slot);

/*****
* producto get_pro
******
* devuelve el producto del slotP de la tabla de hashing
******
* Input:
* slotP slot : slotP de la tabla de hashing
* .......
******
* Returns:
* Tproducto, producto del slotP
*****/
producto get_pro(slotP slot);

/*****
* char* get_name_P
******
* devuelve el nombre del producto que esta en el slot de la tabla de hashing
******
* Input:
* slotP* slot : slotP de la tabla de hashing
* .......
******
* Returns:
* char*, nombre del producto asignado en el slot
*****/
char* get_name_P(slotP *slot);

/*****
* int get_precio_P
******
* devuelve el precio del producto asignado al slotP
******
* Input:
* slotP slot : slot del arreglo de la tabla de hashing
* .......
******
* Returns:
* int, precio del producto
*****/
int get_precio_P(slotP slot);

/*****
* initArrayProduc
******
* inicia el arreglo de slotP para la tabla de hashing;
******
* Input:
* int Tam : tamaño para la tabla de hashing
* .......
******
* Returns:
* slotP* retorna la tabla de hashing
*****/
slotP* initArrayProduc(int Tam);

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int h1P(int k, int M);

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int h2P(int k, int i);

/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int pP(int k, int i);

/*****
* void insert_producto
******
* inserta un producto en la tabla de hashing de arreglo
******
* Input:
* slotP* arreglo : tabla de hashing;
* producto produc : producto a insertar en la tabla;
* .......
******
* Returns:
* void, no retorna nada
*****/
void insert_producto(slotP* arreglo, producto produc);

/*****
* int search_P
******
* 
******
* Input:
* slotP* arreglo : tabla de hashing
* int llave : llave para buscar en la tabla de hashing
* .......
******
* Returns:
* int, devuelve la posicion en el arreglo de la tabla de hashign
*****/
int search_P(slotP* arreglo, int llave);

/*****
* void clearHashP
******
* limpia la tabla de hash, liberando la memoria de esta
******
* Input:
* slotP* arreglo : arreglo a liberar
* .......
******
* Returns:
* void, no retorna nada
*****/
void clearHashP(slotP* arreglo);

#endif
