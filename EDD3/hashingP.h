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

int get_id_P(producto produc);

char* get_name_P(producto* pro);

int get_precio_P(producto produc);

slotP* initArrayProduc(int Tam);

int h1P(int k, int M);

int h2P(int k, int i);

int pP(int k, int i);

void insert_producto(slotP* arreglo, producto produc);

int search_P(slotP* arreglo, int llave);


#endif
