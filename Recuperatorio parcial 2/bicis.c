#include <stdio.h>
#include <stdlib.h>
#include "bicis.h"
#include "LinkedList.h"

eBicicleta* nuevaBici()
{
    eBicicleta* retorno = (eBicicleta*) malloc(sizeof(eBicicleta));

    if(retorno!=NULL)
    {
        retorno->id_bike=0;
        strcpy(retorno->nombre," ");
        strcpy(retorno->tipo," ");
        retorno->tiempo=0;
    }

    return retorno;
}

eBicicleta* nuevaBiciParam(int id,char* nombre, char* tipo, int tiempo)
{
    eBicicleta* retorno = nuevaBici();

    if(retorno!=NULL)
    {
        if(setId(retorno,id) && setNombre(retorno,nombre) && setTipo(retorno,tipo) && setTiempo(retorno,tiempo))
        {

        }
        else
        {
            free(retorno);
            retorno=NULL;
        }
    }

    return retorno;
}
int setId(eBicicleta* aux, int id)
{
    int retorno=0;

    if(aux!=NULL && id>=0)
    {
        aux->id_bike=id;
        retorno=1;
    }

    return retorno;
}

int setNombre(eBicicleta* aux, char* nombre)
{
    int retorno=0;

    if(aux!=NULL && strlen(nombre)>1 && strlen(nombre)<20)
    {
        strcpy(aux->nombre,nombre);
        retorno=1;
    }

    return retorno;
}

int setTipo(eBicicleta* aux, char* tipo)
{
    int retorno=0;

    if(aux!=NULL && strlen(tipo)>1 && strlen(tipo)<10)
    {
        strcpy(aux->tipo,tipo);
        retorno=1;
    }

    return retorno;
}

int setTiempo(eBicicleta* aux, int tiempo)
{
    int retorno=0;

    if(aux!=NULL && tiempo>=0)
    {
        aux->tiempo=tiempo;
        retorno=1;
    }

    return retorno;
}

void tiempo(void* tiempo)
{
    eBicicleta* aux;
    int aleatorio;

    aleatorio = rand()%(71) + 50;

    aux = (eBicicleta*)tiempo;
    setTiempo(aux, aleatorio);

    return aux;
}

int filtrarBmx(void* bici)
{
    int retorno=0;
    eBicicleta* aux;

    aux= (eBicicleta*) bici;


    if(strcmp(aux->tipo,"BMX")==0)
    {
        retorno=1;
    }

    return retorno;
}

int filtrarPlayera(void* bici)
{
    int retorno=0;
    eBicicleta* aux;

    aux= (eBicicleta*) bici;

    if(strcmp(aux->tipo,"PLAYERA")==0)
    {
        retorno=1;
    }

    return retorno;
}

int filtrarMtb(void* bici)
{
    int retorno=0;
    eBicicleta* aux;

    aux = (eBicicleta*) bici;

    if(strcmp(aux->tipo,"MTB")==0)
    {
        retorno=1;
    }

    return retorno;
}

int filtrarPaseo(void* bici)
{
    int retorno=0;
    eBicicleta* aux;

    aux= (eBicicleta*) bici;

    if(strcmp(aux->tipo,"PASEO")==0)
    {
        retorno=1;
    }

    return retorno;
}

void guardarArchivo(LinkedList* lista, char* archivo)
{
    FILE* f = fopen(archivo,"w");
    eBicicleta* aux;
    int tam = ll_len(lista);

    fprintf(f,"id_bike,nombre,tipo,tiempo\n\n");

    if(lista!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            aux=ll_get(lista,i);
            if(aux!=NULL)
            {
                fprintf(f,"%d,%s,%s,%d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
            }
        }

        fclose(f);
    }
}

int ordenarTiempo(void* a, void* b)
{
    int retorno=0;
    eBicicleta* p1;
    eBicicleta* p2;

    if(a!=NULL && b!=NULL)
    {
        p1=(eBicicleta*) a;
        p2=(eBicicleta*) b;

        if(p1->tiempo > p2->tiempo)
        {
            retorno=1;
        }
        else if(p1->tiempo < p2->tiempo)
        {
            retorno=-1;
        }
    }

    return retorno;
}
