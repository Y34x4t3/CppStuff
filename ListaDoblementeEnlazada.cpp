#include <iostream>
using namespace std;
struct sNodo
{
    int dato;
    sNodo * sig;
    sNodo * ant;
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
    return ((lista == NULL) || (!lista -> tam)) ? true : false;
}
sNodo* crearNodo(int dato)
{
    sNodo* nodo = new sNodo;
    nodo -> dato = dato;
    nodo -> sig = NULL;
    nodo ->ant = NULL;
    return nodo;
}
void insertarNodo(sLista *lista, int dato)
{
    sNodo* nodo = new sNodo;
    nodo = crearNodo(dato);
    if(listaVacia(lista))
    {
        nodo -> ant = lista -> cab;
        lista -> cab = nodo;
        lista -> cola = nodo;
    }
    else
    {
        (lista -> cola) -> sig = nodo;
        nodo -> ant = lista -> cola;
        lista -> cola = nodo;
    }
    lista -> tam++;
}
void addOrdenado ( sLista * lista, int dato )
{
    sNodo * nodo = crearNodo(dato);
    sNodo *ant = lista -> cab;
    if (ant == NULL)
    {
        lista->cab=nodo;
        lista->cola=nodo;
    }
    else if (ant==lista->cola)
    {
        if (ant->dato<nodo->dato)
        {
            (lista->cab)->sig=nodo;
            nodo->ant = lista->cab;
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
        cout<<"El else: "<<ant->sig->dato<<endl;
        do 
        {
            cout<<"while";
            ant = ant -> sig;
        } while ((ant->sig != NULL));
        /*while ((ant -> sig != NULL)&&((ant -> sig) -> dato < nodo -> dato))
        {
            cout<<"while";
            ant = ant -> sig;
        }*/
        nodo -> sig = ant -> sig;
        (ant -> sig) -> ant = nodo;
        ant -> sig = nodo;
        nodo -> ant = ant;
        if (lista->cola == ant)
            lista->cola = nodo;
    }
    lista -> tam ++;
}
void imprimirListaA(sLista *lista)
{
    sNodo *nodo = lista->cab;
    while(nodo !=NULL)
    {
        cout<<" Dato: "<<nodo -> dato<<"\t";
        nodo = (nodo->sig);
    }
    cout<<endl;
}
void imprimirListaD(sLista *lista)
{
    sNodo *nodo = lista->cola;
    while(nodo !=NULL)
    {
        cout<<" Dato: "<<nodo -> dato<<"\t";
        nodo = (nodo -> ant);
    }
    cout<<endl;
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
    cout<<"Lista par ascendentemente"<<endl;
    imprimirListaA(listaPar);
    cout<<"Lista impar ascendentemente"<<endl;
    imprimirListaA(listaImpar);
    cout<<endl<<"Lista par descendentemente"<<endl;
    imprimirListaD(listaPar);
    cout<<"Lista impar descendentemente"<<endl;
    imprimirListaD(listaImpar);
    cout<<endl;
    //addOrdenado(listaPar, 5);
    addOrdenado(listaPar, 15);
    cout<<"Lista par ascendentemente"<<endl;
    imprimirListaA(listaPar);
    cout<<endl<<"Lista par descendentemente"<<endl;
    imprimirListaD(listaPar);
    cout<<endl;
    /*eliminarLista(listaPar, listaPar->cab);
    eliminarLista(listaImpar, listaImpar->cab);
    cout<<endl;
    if (listaVacia(listaPar))
        cout<<"...Lista par vacia..."<<endl;
    if (listaVacia(listaImpar))
        cout<<"...Lista impar vacia..."<<endl;*/
}
