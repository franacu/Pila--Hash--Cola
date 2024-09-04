//
// Created by Fran on 04/09/2024.
//

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "helper.h"
Operaciones *newOperaciones(char *nombre, int id)
{
    Operaciones *aux = malloc(sizeof(Operaciones));
    if (aux == NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    strcpy(aux->nombre, nombre);
    aux->id = id;
    aux->sig = NULL;
    return aux;
}

Pila *newPila()
{
    Pila *aux = malloc(sizeof(Pila));
    if (aux == NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    aux->tope = NULL;
    return aux;
}

TablaHash *newTablHash()
{
    TablaHash *aux = malloc(sizeof(TablaHash));
    if (aux == NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    for (int i = 0; i < TAM; i++)
    {
        aux->pos[i] = NULL;
    }
    return aux;
}

Cola *newCola()
{
    Cola *aux = malloc(sizeof(Cola));
    if (aux == NULL)
    {
        printf("Sin memoria suficiente\n");
        exit(-1);
    }
    aux->cab = NULL;
    aux->cola = NULL;
    return aux;
}
void apilar(Pila*pila,Operaciones*operacionAI)
{
    if(pila->tope==NULL)
    {
        pila->tope=operacionAI;
    }else
        {
            operacionAI->sig=pila->tope;
            pila->tope=operacionAI;
        }
}
int hash(int num)
{
    return num%TAM;
}
void almacenarOperacionEnTabla(Pila*pila,TablaHash*tabla)
{
    if(pila->tope==NULL)
    {
        printf("Pila vacia\n");
        exit(-1);
    }else
        {
            Operaciones *eliminar = pila->tope;
            pila->tope = eliminar->sig;

            int i = hash(eliminar->id);
            eliminar->sig = tabla->pos[i];
            tabla->pos[i] = eliminar;
        }
}
void trasladarOperacionesACola(Cola*cola,TablaHash*tabla,int id)
{
    int i=hash(id);
    Operaciones *act=tabla->pos[i];
    Operaciones *ant=NULL;
    while (act!=NULL)
    {
        if(act->id==id)
        {
            if(ant==NULL)
            {
                tabla->pos[i]=act->sig;
            }else
                {
                    ant->sig=act->sig;
                }
            act->sig = NULL;
            if(cola->cab==NULL)
            {
                cola->cab=act;
                cola->cola=act;
            }else
                {
                    cola->cola->sig=act;
                    cola->cola=act;
                }
            return;
        }
        ant=act;
        act=act->sig;
    }
}
void mostrarCola(Cola *cola)
{
    Operaciones *act = cola->cab;
    while (act != NULL) {
        printf("Pagina: %s \n", act->nombre);
        printf("ID: %d \n", act->id);
        act = act->sig;
    }
}