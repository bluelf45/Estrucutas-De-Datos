#ifndef TDAHEAP
#define TDAHEAP

typedef struct {
    int codigo_producto;
    int cont;
    int cantidadO;
    int CantidadPrecio;
    char* nombre;
} producto2;

typedef struct {
    producto2 *array;
    int len;
    int tot;
} tcolaP;

tcolaP* initColaP(int i);

void clearColaP(tcolaP* P);

producto2 encontrarMax(tcolaP* cola);

void flotar(tcolaP* cola, int i);

void hundir(tcolaP* cola, int i);

void insertarColaP(tcolaP* cola, producto2 x, slotO *hashO, slotP *hashP);

void resetCantOHeap(tcolaP* cola);

producto2 removefirstColaP(tcolaP* p);

int buscarHeap(tcolaP* cola, int codigo);

producto2 creacionProduc(int cod, int cont, int cant, char* name);

void sumarElemHeap(tcolaP* heap, int c, int cant, int cont);

#endif
