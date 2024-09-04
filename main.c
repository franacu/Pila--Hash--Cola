#include "helper.h"
int main()
{
    Pila *pila = newPila();
    Cola *cola = newCola();
    TablaHash *tabla = newTablHash();

    apilar(pila, newOperaciones("Youtube", 41242));
    apilar(pila, newOperaciones("Instagram", 74575));
    apilar(pila, newOperaciones("Wsp", 978732));
    apilar(pila, newOperaciones("Github", 124211));

    almacenarOperacionEnTabla(pila, tabla);
    almacenarOperacionEnTabla(pila, tabla);
    almacenarOperacionEnTabla(pila, tabla);
    almacenarOperacionEnTabla(pila, tabla);


    trasladarOperacionesACola(cola, tabla, 978732);  // Usamos solo el ID
    trasladarOperacionesACola(cola, tabla, 74575);  // Usamos solo el ID

    mostrarCola(cola);

    return 0;
}
