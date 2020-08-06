#ifndef HASHINGO
#define HASHINGO

typedef struct {
    int codigo_producto;
    int cantidad_descuento;
    int monto_descuento;
} oferta;

typedef struct{
    int key;
    oferta ofer;
}slotO;

/*****
* slotO* initArrayOfer
******
* inicia la tabla de hashing dejando toads las llaves como -1
******
* Input:
* int Tam : el tamaño de la tabla de hashing
* .......
******
* Returns:
* slotO*, el arreglo de la tabla de hashing
*****/
slotO* initArrayOfer(int Tam);

/*****
* int get_id_O
******
* devuelve el codigo de producto de la oferta que esta en el slot
******
* Input:
* slotO slot : slot de la tabla de hashing
* .......
******
* Returns:
* Int, codigo de la oferta
*****/
int get_id_O(slotO slot);

/*****
* int get_cant_desc_O
******
* devuelve la cantidad de prouctos para que funcione la oferta
******
* Input:
* slotO slot : slot de la tabla de hashing
* .......
******
* Returns:
* int, cantidad de productos de la oferta
*****/
int get_cant_desc_O(slotO slot);

/*****
* int get_descuento_O
******
* devuelve el monto a reducir de la oferta
******
* Input:
* slotO slot : slot de la tabla de hashing
* .......
******
* Returns:
* int, monto a reducir por la oferta
*****/
int get_descuento_O(slotO slot);

/*****
* int h1
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
int h1(int k, int M);

/*****
* int h2
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
int h2(int k, int i);

/*****
* int p
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
int p(int k, int i);

/*****
* void insert_oferta
******
* inserta un valor en la tabla de hashing de oferta
******
* Input:
* slotO* arreglo: la tabla de hashing;
* oferta ofer : item a insertar en la tabla
* .......
******
* Returns:
* void, no retorna nada
*****/
void insert_oferta(slotO* arreglo, oferta ofer);

/*****
* int search_O
******
* busca en la tabla de hashing segun la llave dada
******
* Input:
* slotO* arreglo: tabla de hashing
* int llave : la llave del objeto a buscar
* .......
******
* Returns:
* int, devuelve la posicion en el arreglo de hashing
*****/
int search_O(slotO* arreglo, int llave);

/*****
* void clearHashO
******
* limpia la tabla de hashing y libera la memoria de esta
******
* Input:
* slotO* arreglo : tabla de hashing 
* .......
******
* Returns:
* void, no retorna nada
*****/
void clearHashO(slotO* arreglo);

#endif
