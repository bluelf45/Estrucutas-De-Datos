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


int get_id_P(slotP slot);

producto get_pro(slotP slot);

char* get_name_P(slotP *slot);

int get_precio_P(slotP slot);

slotP* initArrayProduc(int Tam);

int h1P(int k, int M);

int h2P(int k, int i);

int pP(int k, int i);

void insert_producto(slotP* arreglo, producto produc);

int search_P(slotP* arreglo, int llave);

void clearHashP(slotP* arreglo);

#endif
