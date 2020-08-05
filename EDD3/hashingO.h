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
int h1(int k, int M);

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
int h2(int k, int i);

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
