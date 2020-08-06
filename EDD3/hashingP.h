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
* int h1P
******
* Primera funcion de hashing, usa operadores de bits (<< y ^) para modificar el valor 
  del numero ingresado.  
******
* Input:
* int k : numero al cual se le hara el hash 
* int M : numero total de "slots" en la tabla de hash, numero por el cual se hace modulo.
******
* Returns:
* int, indice de donde se insertara el valor (HashVal).
*****/
int h1P(int k, int M);

/*****
* int h2P
******
* Segunda funcion de hashing, utilizada en caso de que el indice retornado por h1 ya este
  siendo ocupado por otro elemento.
******
* Input:
* int k : numero al cual se le aplica la funcion de hash
* int i : veces que se ha realizado la funcion con tal de encontrar un slot vacio.
******
* Returns:
* int, retorna el indice donde insertar el valor.
*****/
int h2P(int k, int i);

/*****
* int pP
******
* funcion que se encarga de utilizar a h2 las veces necesarias para hacer el hashing 
  en casos donde h1 no encuentra un slot vacio
******
* Input:
* int k : valor al cual se le hace el hash
* int i : veces que se ha llamado a la funcion p
******
* Returns:
* int, devuelve el valor obtenido para el hash.
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
