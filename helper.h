//
// Created by Fran on 04/09/2024.
//

#ifndef UNTITLED35_HELPER_H
#define UNTITLED35_HELPER_H
#define TAM 12
typedef struct operaciones
{
    struct operaciones*sig;
    char nombre[23];
    int id;
}Operaciones;
typedef struct pila
{
    Operaciones *tope;
}Pila;
typedef struct tablaHash
{
    Operaciones *pos[TAM];
}TablaHash;
typedef struct cola
{
    Operaciones *cab;
    Operaciones *cola;
}Cola;
Operaciones *newOperaciones(char *nombre,int id);
Pila *newPila();
TablaHash *newTablHash();
Cola *newCola();
void apilar(Pila*pila,Operaciones*operacionAI);
void almacenarOperacionEnTabla(Pila*pila,TablaHash*tabla);
void trasladarOperacionesACola(Cola*cola,TablaHash*tabla,int id);
void mostrarCola(Cola *cola);

#endif //UNTITLED35_HELPER_H
