#ifndef HASHINGP
#define HASHINGP

typedef struct {
    int codigo_producto;
    int cont;
} producto;

typedef struct {
    producto *array;
    int len;
    int tot;
} tcolaP;

tcolaP* initColaP(int i);

void clearColaP(tcolaP* P);

producto encontrarMax(tcolaP* cola);

void hundir(tcolaP* cola, int i);

void insertarColaP(tcolaP* p, producto x);

producto removefirstColaP(tcolaP* p);

#endif
