#ifndef TDAHEAP
#define TDAHEAP
#include "hashingO.h"
#include "hashingP.h"

typedef struct {
    int codigo_producto;
    int cont;
    int cantidadO;
    int CantidadPrecio;
    char *nombre;
} producto2;

typedef struct {
    producto2 **array;
    int len;
    int tot;
} tcolaP;

/*****
* tcolaP* initColaP
******
* Se encarga de inicializar la cola de prioridad que contiene al heap.
******
* Input:
* int i : Tamaño deseado para el heap
* tcolaP* cola : heap no inicializado
******
* Returns:
* tcolaP*, heap con la memoria alojada y valores incializados
*****/
tcolaP* initColaP(int i, tcolaP* cola);

/*****
* void clearColaP
******
* Se libera la memoria ocupada por la cola ingresada
******
* Input:
* tcolaP* P : heap la cual queremos liberar
******
* Returns:
* void, no retorna nada
*****/
void clearColaP(tcolaP* P);

/*****
* void flotar
******
* Funcion la cual se encarga de hacer "flotar" un elemento dependiendo
  de si su variable "cont" es mayor a la de su "padre" en el heap.
******
* Input:
* tcolaP* cola : heap donde se efectuaran las operaciones
* int i : posicion en el heap del elementro el cual se quiere flotar
******
* Returns:
* void, no retorna nada
*****/
void flotar(tcolaP* cola, int i);

/*****
* void hundir
******
* Funcion la cual va a "hundir" el elemento seleccionado la cantidad de
  veces necesaria.
******
* Input:
* tcolaP* cola : heap donde se efectuaran las operaciones
* int i : posicion en el heap del elementro el cual se quiere hundir
******
* Returns:
* void, no retorna nada
*****/
void hundir(tcolaP* cola, int i);

/*****
* void insertarColaP
******
* funcion encargada de insertar un elemento al heap, y ademas, en
  caso de que el elemento ya este en el heap, le agregara la cantidad necesaria
  a la cantidad de veces comprado de ese item, flotando el elemento
  en caso de ser necesario, y en caso de que se pueda efectuar un desceunto, se
  hace el descuento y se hunde el elemento de ser necesario.
******
* Input:
* tcolaP* cola : heap en donde se insertara el elemento
* int pos1 : posicion en la tabla de hashing donde 
             esta el elemento que queremos insertar
* slotO *hashO : tabla de hashing de ofertas
* slotP *hashP : tabla de hashing de productos
******
* Returns:
* void, no retorna nada
*****/
void insertarColaP(tcolaP* cola, int pos1, slotO *hashO, slotP *hashP);

/*****
* void resetCantOHeap
******
* Se encarga de devolver a 0 todas las variables cantO en el heap cuando hay
  un cambio de cliente
******
* Input:
* tcolaP* cola : heap en el cual se efectua el "reset" de las variables cantO
******
* Returns:
* void, no retorna nada
*****/
void resetCantOHeap(tcolaP* cola);

/*****
* producto2* removefirstColaP
******
* Se encarga de remover el primer elemento del max-heap para escribirlo en el
  formato pedido en el archivo de ranking
******
* Input:
* tcolaP* p : Heap donde removeremos el primer elemento
* FILE *fp : Archivo donde se escribe los datos del elemento removido
******
* Returns:
* producto2*, elemento removido.
*****/
producto2* removefirstColaP(tcolaP* p, FILE *fp);


#endif
