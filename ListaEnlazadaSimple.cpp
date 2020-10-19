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
    sNodo * cola;
    int tam;
};
sLista * crearLista()
{
    sLista *lista = new sLista;
    lista->cab = NULL;
    lista->cola = NULL;
    lista->tam = 0;
    return lista;
}
bool listaVacia ( sLista *lista )
{
    return ((lista == NULL) || (!lista -> tam)) ? true: false;
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
        lista->cab = nodo;
        lista->cola=nodo;
    }
    else
    {
        (lista->cola)->sig = nodo;
        lista->cola = nodo;
    }
    lista->tam++;
}
void imprimirLista(sLista *lista)
{
    sNodo *nodo = new sNodo;
    nodo = lista->cab;
    while(nodo !=NULL)
    {
        cout<<"\tDato: "<<nodo->dato;
        nodo = (nodo->sig);
    }
    cout<<endl;
}
void addOrdenado ( sLista * lista, int dato )
{
    sNodo * nodo = crearNodo(dato);
    sNodo *ant = lista -> cab;
    if (lista -> cab == NULL)
    {
        lista->cab=nodo;
        lista->cola=nodo;
    }
    else if (lista->cab==lista->cola)
    {
        if ((lista->cab)->dato<nodo->dato)
        {
            (lista->cab)->sig=nodo;
            lista->cola=nodo;
        }
        else
        {
            nodo->sig = lista->cab;
            lista->cab=nodo;
        }
    }
    else
    {
        while ((ant -> sig != NULL)&&((ant -> sig) -> dato < nodo -> dato))
        {
            ant = ant -> sig;
        }
        nodo -> sig = ant -> sig;
        ant -> sig = nodo;
        if (ant == lista->cola)
            lista->cola=nodo;
    }
    lista -> tam ++;
}
void eliminarLista( sLista *&lista, sNodo* nodo )
{
    if (nodo == NULL)
        return;
    else
    {
        eliminarLista(lista, nodo->sig);
        delete nodo;
        lista->tam--;
    }
    if (!lista->tam)
    {
        delete lista;
        lista = NULL;
    }
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
    addOrdenado(listaPar, 10);
    addOrdenado(listaPar, 19);
    imprimirLista(listaPar);
    eliminarLista(listaPar, listaPar->cab);
    eliminarLista(listaImpar, listaImpar->cab);
    if ((listaVacia(listaPar))&&(listaVacia(listaImpar)))
        cout<<"\tListas vacias...";
    
}
