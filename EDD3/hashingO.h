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

slotO* initArrayOfer(int Tam);

int get_id_O(oferta oferta);

int get_cant_desc_O(oferta ofer);

int get_descuento_O(oferta oferta);

int h1(int k, int M);

int h2(int k, int i);

int p(int k, int i);

void insert_oferta(slotO* arreglo, oferta ofer);

int search_O(slotO* arreglo, int llave);

#endif
