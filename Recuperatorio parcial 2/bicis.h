#include "LinkedList.h"

#ifndef BICIS_H_INCLUDED
#define BICIS_H_INCLUDED

typedef struct
{
    int id_bike;
    char nombre[20];
    char tipo[10];
    int tiempo;
}eBicicleta;


#endif // BICIS_H_INCLUDED

eBicicleta* nuevaBici();
eBicicleta* nuevaBiciParam(int id,char* nombre, char* tipo, int tiempo);
int setId(eBicicleta* aux, int id);
int setNombre(eBicicleta* aux, char* nombre);
int setTipo(eBicicleta* aux, char* tipo);
int setTiempo(eBicicleta* aux, int tiempo);
void tiempo(void* tiempo);
int filtrarBmx(void* bici);
int filtrarPlayera(void* bici);
int filtrarMtb(void* bici);
int filtrarPaseo(void* bici);
void guardarArchivo(LinkedList* lista, char* archivo);
int ordenarTiempo(void* a, void* b);
