#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "bicis.h"
#include "utn.h"

int cargarArchivo(LinkedList* lista)
{
    int retorno=0;
    char archivo[30];
    FILE* f;
    char buffer[4][20];
    eBicicleta* aux;

    printf("ingrese el nombre del archivo:");
    scanf("%s",archivo);

    strcat(archivo,".csv");

    f=fopen(archivo,"r");

    if(f!=NULL && lista!=NULL)
    {
        fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        while(!feof(f))
        {
            fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            aux = nuevaBiciParam(atoi(buffer[0]),buffer[1],buffer[2], atoi(buffer[3]));

            if(aux!=NULL)
            {
                ll_add(lista,aux);
                retorno=1;
            }
            else
            {
                retorno=0;
                break;
            }

        }
    }

    return retorno;
}

void imprimirLista(LinkedList* lista)
{
    eBicicleta* aux;
    int tam = ll_len(lista);

    if(lista!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            aux = (eBicicleta*) ll_get(lista,i);

            if(aux!=NULL)
            {
                printf("%d %s %s %d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
            }
        }
    }
    else
    {
        printf("No hay lista que mostrar\n\n");
    }
}

int asignarTiempo(LinkedList* lista)
{
    int retorno;

    if(lista!=NULL)
    {
        ll_map(lista,tiempo);
        retorno=1;
    }

    return retorno;
}

int filtrarTipo(LinkedList* lista)
{
    int retorno=0;
    LinkedList* listaFiltrada = ll_newLinkedList();
    int tipo;

    if(lista!=NULL)
    {
        printf("1. Bmx\n");
        printf("2. Playera\n");
        printf("3. Mtb\n");
        printf("4. Paseo\n\n");

        utn_getEntero(&tipo,20,"Que tipo de bicicleta desea filtrar: ","Error. Ese tipo no existe: ",1,4);

        switch(tipo)
        {
        case 1:
            listaFiltrada=ll_filter(lista,filtrarBmx);
            if(listaFiltrada!=NULL)
            {
                guardarArchivo(listaFiltrada,"Bicicletas BMX.csv");
                retorno=1;
            }
            break;
        case 2:
            listaFiltrada=ll_filter(lista,filtrarPlayera);
            if(listaFiltrada!=NULL)
            {
                guardarArchivo(listaFiltrada,"Bicicletas Playera.csv");
                retorno=1;
            }
            break;
        case 3:
            listaFiltrada=ll_filter(lista,filtrarMtb);
            if(listaFiltrada!=NULL)
            {
                guardarArchivo(listaFiltrada,"Bicicletas MTB.csv");
                retorno=1;
            }
            break;
        case 4:
            listaFiltrada=ll_filter(lista,filtrarPaseo);
            if(listaFiltrada!=NULL)
            {
                guardarArchivo(listaFiltrada,"Bicicletas Paseo.csv");
                retorno=1;
            }
            break;
        }
    }

    return retorno;
}

int mostrarPocisiones ( LinkedList* lista)
{
    int retorno=0;
    int tam = ll_len(lista);
    eBicicleta* aux;

    if(lista!=NULL)
    {
        ll_sort(lista,ordenarTiempo,1);

        for(int i=0; i<4; i++)
        {
            if(i==0)
            {
                printf("BMX:\n\n");
            }
            else if(i==1)
            {
                printf("\nPLAYERA:\n\n");
            }
            else if(i==2)
            {
                printf("\nMTB:\n\n");
            }
            else
            {
                printf("\nPASEO:\n\n");
            }

            for(int j=i+1; j<tam; j++)
            {
                aux = ll_get(lista,j);
                if(aux!=NULL)
                {
                    if(i==0 && strcmp(aux->tipo,"BMX")==0)
                    {
                        printf("%d %s %s %d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
                    }
                    else if(i==1 && strcmp(aux->tipo,"PLAYERA")==0)
                    {
                        printf("%d %s %s %d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
                    }
                    else if(i==2 && strcmp(aux->tipo,"MTB")==0)
                    {
                        printf("%d %s %s %d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
                    }
                    else if(i==3 && strcmp(aux->tipo,"PASEO")==0)
                    {
                        printf("%d %s %s %d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
                    }
                }
            }
        }
        retorno=1;
    }

    return retorno;
}

int guardarPocisiones ( LinkedList* lista)
{
    FILE* f = fopen("Bicicletas pocisiones.csv","w");
    int retorno=0;
    int tam = ll_len(lista);
    eBicicleta* aux;

    fprintf(f,"id_bike,nombre,tipo,tiempo\n\n");

    if(lista!=NULL)
    {
        ll_sort(lista,ordenarTiempo,1);

        for(int i=0; i<4; i++)
        {
            if(i==0)
            {
                fprintf(f,"BMX:\n\n");
            }
            else if(i==1)
            {
                fprintf(f,"\nPLAYERA:\n\n");
            }
            else if(i==2)
            {
                fprintf(f,"\nMTB:\n\n");
            }
            else
            {
                fprintf(f,"\nPASEO:\n\n");
            }

            for(int j=i+1; j<tam; j++)
            {
                aux = ll_get(lista,j);
                if(aux!=NULL)
                {
                    if(i==0 && strcmp(aux->tipo,"BMX")==0)
                    {
                        fprintf(f,"%d %s %s %d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
                    }
                    else if(i==1 && strcmp(aux->tipo,"PLAYERA")==0)
                    {
                        fprintf(f,"%d %s %s %d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
                    }
                    else if(i==2 && strcmp(aux->tipo,"MTB")==0)
                    {
                        fprintf(f,"%d %s %s %d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
                    }
                    else if(i==3 && strcmp(aux->tipo,"PASEO")==0)
                    {
                        fprintf(f,"%d %s %s %d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
                    }
                }
            }
        }
        retorno=1;
        fclose(f);
    }

    return retorno;
}


