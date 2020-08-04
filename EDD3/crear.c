#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int codigo_producto;
    char nombre_producto[31];
    int precio;

} producto;

typedef struct {
    int codigo_producto;
    int cantidad_descuento;
    int monto_descuento;
} oferta;

void crear_productos() {
    FILE *fp = fopen("productos.dat", "wb");

    producto inv;
    int i = 18;
    fwrite(&i, sizeof(int), 1, fp);

    inv.codigo_producto = 2020;
    strcpy(inv.nombre_producto, "Papel Higienico");
    inv.precio = 3569;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 2637;
    strcpy(inv.nombre_producto, "Lays");
    inv.precio = 1050;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 81095;
    strcpy(inv.nombre_producto, "Submarino");
    inv.precio = 2000000;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 5032;
    strcpy(inv.nombre_producto, "Silla Gamer");
    inv.precio = 60522;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 6969;
    strcpy(inv.nombre_producto, "Belle Delphine's Bath Water");
    inv.precio = 6969;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 4444;
    strcpy(inv.nombre_producto, "Profe Torres");
    inv.precio = 4444;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 130;
    strcpy(inv.nombre_producto, "Daurte");
    inv.precio = 130130;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 120;
    strcpy(inv.nombre_producto, "La Guitarra De Daurte");
    inv.precio = 120120;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 33;
    strcpy(inv.nombre_producto, "Mineros");
    inv.precio = 4213;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 911;
    strcpy(inv.nombre_producto, "Torres Gemelas");
    inv.precio = 2000;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 9999;
    strcpy(inv.nombre_producto, "Año de graduacion");
    inv.precio = 9999;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 1;
    strcpy(inv.nombre_producto, "Se busca polola");
    inv.precio = 1;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 6470;
    strcpy(inv.nombre_producto, "Anvorguesa");
    inv.precio = 3140;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 6560;
    strcpy(inv.nombre_producto, "Dragon Lore");
    inv.precio = 1999;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 16;
    strcpy(inv.nombre_producto, "Ram Con RGB");
    inv.precio = 70000;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 2029;
    strcpy(inv.nombre_producto, "Caca con mayo");
    inv.precio = 6969;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 27;
    strcpy(inv.nombre_producto, "Black Ice Shield");
    inv.precio = 5436742;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 2021;
    strcpy(inv.nombre_producto, "Ficha del WoW en bolivares");
    inv.precio = 12700000;
    fwrite(&inv, sizeof(producto), 1, fp);

    fclose(fp);
}

void crear_ofertas(){
    FILE *fp = fopen("ofertas.dat", "wb");

    oferta inv;
    int i = 15;
    fwrite(&i, sizeof(int), 1, fp);

    inv.codigo_producto = 2020;
    inv.cantidad_descuento=0;
    inv.monto_descuento = 0;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 2637;
    inv.cantidad_descuento=4;
    inv.monto_descuento = 100;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 81095;
    inv.cantidad_descuento=2;
    inv.monto_descuento = 500;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 5032;
    inv.cantidad_descuento=2;
    inv.monto_descuento = 3000;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 6969;
    inv.cantidad_descuento=7;
    inv.monto_descuento = 3333;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 4444;
    inv.cantidad_descuento=2;
    inv.monto_descuento = 200;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 130;
    inv.cantidad_descuento=32;
    inv.monto_descuento = 50000;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 120;
    inv.cantidad_descuento=30;
    inv.monto_descuento = 100;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 911;
    inv.cantidad_descuento=5;
    inv.monto_descuento = 200;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 9999;
    inv.cantidad_descuento=69;
    inv.monto_descuento = 4000;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 6470;
    inv.cantidad_descuento=9;
    inv.monto_descuento = 1500;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 6560;
    inv.cantidad_descuento=2;
    inv.monto_descuento = 327;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 16;
    inv.cantidad_descuento=1;
    inv.monto_descuento = 100;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto=2029;
    inv.cantidad_descuento=5;
    inv.monto_descuento = 682;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 27;
    inv.cantidad_descuento=28;
    inv.monto_descuento = 60000;
    fwrite(&inv, sizeof(oferta), 1, fp);

    fclose(fp);
}

int main() {

    crear_productos();
    crear_ofertas();

    return 0;
}