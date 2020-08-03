#ifndef TDAHEAP
#define TDAHEAP

typedef struct {
    int codigo_producto;
    int cont;
} producto2;

typedef struct {
    producto2 *array;
    int len;
    int tot;
} tcolaP;

tcolaP* initColaP(int i);

void clearColaP(tcolaP* P);

producto2 encontrarMax(tcolaP* cola);

void hundir(tcolaP* cola, int i);

void insertarColaP(tcolaP* p, producto2 x);

producto2 removefirstColaP(tcolaP* p);

#endif
