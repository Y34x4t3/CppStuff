/*
 * listaTemplates.cpp
 * 
 * Copyright 2020 Y34x4t3 <y34x4t3@y34x4t3-Lenovo-ideapad-330S-14IKB>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
using namespace std;
template <class T>
struct Nodo
{
	T info;
	Nodo <T> *sig;
};
template <typename T>
struct sLista
{
	Nodo <T> *cab;
	Nodo <T> *cola;
	int tam = 0;
};
template <class T>
Nodo <T>* createN ( T info )
{
	Nodo <T> *nodo = new Nodo <T>;
	nodo -> info = info;
	nodo -> sig = NULL;
	return nodo;
}
template < typename T >
bool listaVacia (sLista <T> *lista)
{
	return (lista -> cab == NULL)? 1: 0;
}
template <class T>
void addNodo ( sLista <T>*lista, T info )
{
	Nodo <T> *nodo = createN <T> (info);
	if (listaVacia(lista))
	{
		lista -> cab = nodo;
		lista -> cola = nodo;
	}
	else
	{
		Nodo <T> *nod = lista->cab;
		while (nod->sig != NULL)
		    nod = nod -> sig;
		nod -> sig = nodo;
	    lista->cola = nodo;
	}
}
template < class T >
sLista <T> * createL ()
{
	sLista <T> * nLista = new sLista <T>;
	nLista -> cab = NULL;
	nLista -> cola = NULL;
	return nLista;
}
template < typename T >
void imprimirLista ( Nodo <T> *nodo)
{
	if (nodo != NULL)
	    cout<<nodo -> info <<endl;
	if (nodo -> sig != NULL)
	    imprimirLista <T> (nodo -> sig);
	else 
	    return;
}
int main()
{
	sLista <int> *lista = createL <int> ();
	for ( int i = 0; i < 5; i++ )
	    addNodo <int> (lista, i);
	imprimirLista <int> (lista->cab);
	return 0;
}

