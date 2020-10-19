#include <iostream>
using namespace std;
struct sNodo
{
    int dato;
    sNodo * sig;
};
struct sLista
{
    sNodo * cab;
};
sLista * crearLista()
{
    sLista *lista = new sLista;
    lista -> cab = NULL;
    return lista;
}
bool listaVacia ( sLista *lista )
{
    return ((lista == NULL) || (lista -> cab == NULL)) ? true: false;
}
sNodo* crearNodo(int dato)
{
    sNodo* nodo = new sNodo;
    nodo -> dato = dato;
    nodo -> sig = NULL;
    return nodo;
}
void insertarNodo(sLista *lista, int dato)
{
    sNodo* nodo = new sNodo;
    nodo = crearNodo(dato);
    if(listaVacia(lista))
    {
        lista -> cab = nodo;
        nodo -> sig = nodo;
    }
    else
    {
        
        nodo -> sig = lista -> cab;
        sNodo * cab = new sNodo;
        cab = lista->cab;
        sNodo * n = cab;
        while (n -> sig != cab)
        {
            n = n -> sig;
        }
        n -> sig = nodo;
    }
}
void imprimirLista(sLista *lista)
{
    sNodo *nodo = lista->cab;
    do
    {
        cout<<"  Dato: "<<nodo->dato;
        nodo = (nodo->sig);
    } while(nodo != lista -> cab);
    cout<<endl;
}
void eliminarLista( sLista *&lista )
{
    sNodo *nodo = lista->cab;
    do
    {
        nodo = (nodo->sig);
        delete nodo;
    } while(nodo != lista -> cab);
    delete lista;
    lista = NULL;
}
int main()
{
    sLista *listaPar = crearLista();
    sLista *listaImpar = crearLista();
    for ( int i = 0; i < 16; i ++ )
    {
        (i % 2 == 0)? insertarNodo(listaPar, i):insertarNodo(listaImpar, i);
    }
    imprimirLista(listaPar);
    imprimirLista(listaImpar);
    eliminarLista(listaPar);
    eliminarLista(listaImpar);
    if (listaVacia(listaPar))
        cout<<"Hola";
}
